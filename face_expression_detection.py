import cv2
import mediapipe as mp
import numpy as np
import math
import os
import time

class FaceExpressionDetector:
    def __init__(self):
        self.mp_face_mesh = mp.solutions.face_mesh
        self.mp_drawing = mp.solutions.drawing_utils
        self.mp_drawing_styles = mp.solutions.drawing_styles
        
        # Initialize face mesh
        self.face_mesh = self.mp_face_mesh.FaceMesh(
            max_num_faces=1,
            refine_landmarks=True,
            min_detection_confidence=0.5,
            min_tracking_confidence=0.5
        )
        
        # Key facial landmarks for expression detection
        self.FACE_LANDMARKS = {
            'left_eye': [33, 7, 163, 144, 145, 153, 154, 155, 133, 173, 157, 158, 159, 160, 161, 246],
            'right_eye': [362, 382, 381, 380, 374, 373, 390, 249, 263, 466, 388, 387, 386, 385, 384, 398],
            'mouth': [61, 84, 17, 314, 405, 320, 307, 375, 321, 308, 324, 318],
            'eyebrows': [70, 63, 105, 66, 107, 55, 65, 52, 53, 46],
            'nose': [1, 2, 5, 4, 6, 168, 8, 9, 10, 151]
        }
        
    def calculate_distance(self, point1, point2):
        """Calculate Euclidean distance between two points"""
        return math.sqrt((point1.x - point2.x)**2 + (point1.y - point2.y)**2)
    
    def calculate_eye_aspect_ratio(self, landmarks, eye_points):
        """Calculate eye aspect ratio (EAR) for blink detection"""
        # Get eye landmarks
        eye_landmarks = [landmarks[i] for i in eye_points]
        
        # Calculate vertical distances
        vertical_1 = self.calculate_distance(eye_landmarks[1], eye_landmarks[5])
        vertical_2 = self.calculate_distance(eye_landmarks[2], eye_landmarks[4])
        
        # Calculate horizontal distance
        horizontal = self.calculate_distance(eye_landmarks[0], eye_landmarks[3])
        
        # Calculate EAR
        ear = (vertical_1 + vertical_2) / (2.0 * horizontal)
        return ear
    
    def calculate_mouth_aspect_ratio(self, landmarks, mouth_points):
        """Calculate mouth aspect ratio (MAR) for smile detection"""
        mouth_landmarks = [landmarks[i] for i in mouth_points]
        
        # Ensure we have enough points for calculation
        if len(mouth_landmarks) < 6:
            return 0
        
        # Calculate vertical distance (mouth height) - using available indices
        vertical = self.calculate_distance(mouth_landmarks[2], mouth_landmarks[5])
        
        # Calculate horizontal distance (mouth width)
        horizontal = self.calculate_distance(mouth_landmarks[0], mouth_landmarks[3])
        
        # Calculate MAR
        mar = vertical / horizontal if horizontal > 0 else 0
        return mar
    
    def detect_expression(self, landmarks):
        """Detect facial expression based on landmark analysis"""
        expressions = []
        
        # Calculate eye aspect ratios using more accurate eye landmarks
        # Left eye: inner corner, top, outer corner, bottom points
        left_eye_points = [33, 159, 133, 145]  # Simplified but more reliable
        right_eye_points = [362, 386, 263, 374]  # Simplified but more reliable
        
        left_ear = self.calculate_eye_aspect_ratio_simple(landmarks, left_eye_points)
        right_ear = self.calculate_eye_aspect_ratio_simple(landmarks, right_eye_points)
        
        # Mouth landmarks for better expression detection
        # Using key mouth points: left corner, right corner, top center, bottom center
        mouth_left = landmarks[61]      # Left mouth corner
        mouth_right = landmarks[291]    # Right mouth corner  
        mouth_top = landmarks[13]       # Top lip center
        mouth_bottom = landmarks[14]    # Bottom lip center
        
        # Calculate mouth width and height
        mouth_width = self.calculate_distance(mouth_left, mouth_right)
        mouth_height = self.calculate_distance(mouth_top, mouth_bottom)
        mouth_ratio = mouth_height / mouth_width if mouth_width > 0 else 0
        
        # Smile detection: check if mouth corners are elevated
        mouth_center_y = (mouth_top.y + mouth_bottom.y) / 2
        left_elevated = mouth_left.y < mouth_center_y - 0.01
        right_elevated = mouth_right.y < mouth_center_y - 0.01
        
        # Expression classification with improved thresholds
        if left_ear < 0.15 and right_ear < 0.15:
            expressions.append("close eyes")
        elif left_ear < 0.15:
            expressions.append("left eye blink")
        elif right_ear < 0.15:
            expressions.append("right eye blink")

        # Mouth expressions
        if left_elevated and right_elevated and mouth_ratio > 0.02:
            expressions.append("smile")
        elif mouth_ratio > 0.06:
            expressions.append("open mouth/surprise")
        elif mouth_ratio < 0.015:
            expressions.append("pursed lips")

        # Additional expressions based on mouth shape
        if mouth_width > 0.05:  # Wide mouth
            if not (left_elevated and right_elevated):
                expressions.append("open mouth")

        # Default expression
        if not expressions:
            expressions.append("neutral")

        return expressions
    
    def calculate_eye_aspect_ratio_simple(self, landmarks, eye_points):
        """Simplified EAR calculation with 4 points"""
        if len(eye_points) < 4:
            return 0.3  # Default value
            
        eye_landmarks = [landmarks[i] for i in eye_points]
        
        # Calculate vertical distance (height)
        vertical = self.calculate_distance(eye_landmarks[1], eye_landmarks[3])
        
        # Calculate horizontal distance (width)  
        horizontal = self.calculate_distance(eye_landmarks[0], eye_landmarks[2])
        
        # Calculate EAR
        ear = vertical / horizontal if horizontal > 0 else 0.3
        return ear


class PoseDetector:
    def __init__(self):
        self.mp_pose = mp.solutions.pose
        self.mp_drawing = mp.solutions.drawing_utils
        self.mp_drawing_styles = mp.solutions.drawing_styles
        
        # Initialize pose detection
        self.pose = self.mp_pose.Pose(
            min_detection_confidence=0.5,
            min_tracking_confidence=0.5
        )
        
    def calculate_angle(self, a, b, c):
        """Calculate angle between three points"""
        a = np.array(a)
        b = np.array(b)
        c = np.array(c)
        
        radians = np.arctan2(c[1] - b[1], c[0] - b[0]) - np.arctan2(a[1] - b[1], a[0] - b[0])
        angle = np.abs(radians * 180.0 / np.pi)
        
        if angle > 180.0:
            angle = 360 - angle
            
        return angle
    
    def analyze_pose(self, landmarks, hand_landmarks=None):
        """Analyze reading posture with finger detection for higher accuracy"""
        poses = []

        # 获取关键点
        nose = [landmarks[self.mp_pose.PoseLandmark.NOSE.value].x,
                landmarks[self.mp_pose.PoseLandmark.NOSE.value].y]
        left_wrist = [landmarks[self.mp_pose.PoseLandmark.LEFT_WRIST.value].x,
                      landmarks[self.mp_pose.PoseLandmark.LEFT_WRIST.value].y]
        right_wrist = [landmarks[self.mp_pose.PoseLandmark.RIGHT_WRIST.value].x,
                       landmarks[self.mp_pose.PoseLandmark.RIGHT_WRIST.value].y]
        mouth_center = [(landmarks[13].x + landmarks[14].x) / 2, (landmarks[13].y + landmarks[14].y) / 2]
        face_top = [landmarks[10].x, landmarks[10].y]  # 头顶

        # 基于手指的姿势检测
        def is_finger_near_point(hand_landmarks, point, threshold=0.07):
            if hand_landmarks is None:
                return False
            for tip_id in [4, 8, 12, 16, 20]:
                tip = hand_landmarks.landmark[tip_id]
                dist = np.linalg.norm(np.array([tip.x, tip.y]) - np.array(point))
                if dist < threshold:
                    return True
            return False

        if hand_landmarks is not None:
            # 手指在脸颊上检测：手指靠近鼻子
            if is_finger_near_point(hand_landmarks, nose, threshold=0.065):
                poses.append("Hand/Finger on Cheek")

            # 揪头发检测：手的最高点在面部最高点之上，且水平距离在阈值内
            hand_points = hand_landmarks.landmark
            max_hand_y = min([pt.y for pt in hand_points])
            max_hand_x = hand_points[[pt.y for pt in hand_points].index(max_hand_y)].x
            face_top_y = face_top[1]
            face_top_x = face_top[0]
            horizontal_dist = abs(max_hand_x - face_top_x)
            if max_hand_y < face_top_y and horizontal_dist < 0.2:
                poses.append("Pulling Hair")

            # 啃手/笔检测：手指靠近嘴部中心
            if is_finger_near_point(hand_landmarks, mouth_center, threshold=0.055):
                poses.append("Biting Finger/Pen")

        else:
            if np.linalg.norm(np.array(left_wrist) - np.array(nose)) < 0.075:
                poses.append("Left Hand on Cheek")
            if np.linalg.norm(np.array(right_wrist) - np.array(nose)) < 0.075:
                poses.append("Right Hand on Cheek")
            if left_wrist[1] < nose[1] - 0.045:
                poses.append("Left Hand Scratching Head")
            if right_wrist[1] < nose[1] - 0.045:
                poses.append("Right Hand Scratching Head")
            if np.linalg.norm(np.array(left_wrist) - np.array(mouth_center)) < 0.045:
                poses.append("Biting Left Hand/Pen")
            if np.linalg.norm(np.array(right_wrist) - np.array(mouth_center)) < 0.045:
                poses.append("Biting Right Hand/Pen")

        # 趴桌检测：鼻子y坐标接近下边界
        if nose[1] > 0.8:
            poses.append("Lying on Desk")

        # 头到桌子的距离 (assume y=1 is desk, smaller y is farther)
        if nose[1] < 0.5:
            poses.append("Head-to-Desk Distance OK")
        else:
            poses.append("Head-to-Desk Distance Too Close")

        if not poses:
            poses.append("Reading Posture Normal")

        return poses


class MultiModalDetector:
    def __init__(self):
        self.face_detector = FaceExpressionDetector()
        self.pose_detector = PoseDetector()
        self.mp_hands = mp.solutions.hands
        self.hands = self.mp_hands.Hands(
            static_image_mode=False,
            max_num_hands=2,
            min_detection_confidence=0.5,
            min_tracking_confidence=0.5
        )

    def process_frame(self, frame):
        """Process frame for face, pose, and hand/finger detection"""
        results = {}
        rgb_frame = cv2.cvtColor(frame, cv2.COLOR_BGR2RGB)

        # # Face expression detection
        # face_results = self.face_detector.face_mesh.process(rgb_frame)
        # if face_results.multi_face_landmarks:
        #     for face_landmarks in face_results.multi_face_landmarks:
        #         self.face_detector.mp_drawing.draw_landmarks(
        #             frame, face_landmarks,
        #             self.face_detector.mp_face_mesh.FACEMESH_CONTOURS,
        #             landmark_drawing_spec=None,
        #             connection_drawing_spec=self.face_detector.mp_drawing_styles
        #             .get_default_face_mesh_contours_style())
        #         expressions = self.face_detector.detect_expression(face_landmarks.landmark)
        #         results['expressions'] = expressions

        # Hand/finger detection
        hand_results = self.hands.process(rgb_frame)
        hand_landmarks = None
        if hand_results.multi_hand_landmarks:
            # Use the first detected hand for posture analysis
            hand_landmarks = hand_results.multi_hand_landmarks[0]
            for hand_landmark in hand_results.multi_hand_landmarks:
                self.mp_hands.HAND_CONNECTIONS
                self.pose_detector.mp_drawing.draw_landmarks(
                    frame, hand_landmark,
                    self.mp_hands.HAND_CONNECTIONS)

        # Pose detection
        pose_results = self.pose_detector.pose.process(rgb_frame)
        if pose_results.pose_landmarks:
            self.pose_detector.mp_drawing.draw_landmarks(
                frame, pose_results.pose_landmarks,
                self.pose_detector.mp_pose.POSE_CONNECTIONS,
                landmark_drawing_spec=self.pose_detector.mp_drawing_styles
                .get_default_pose_landmarks_style())
            # Pass hand landmarks to pose analysis for finger-based detection
            poses = self.pose_detector.analyze_pose(pose_results.pose_landmarks.landmark, hand_landmarks)
            results['poses'] = poses

        return frame, results


video_path = "/home/ubuntu/Desktop/rp/nfsroot/"
video_index = 0

"""Main function to run the detection system"""
# Initialize detector
detector = MultiModalDetector()

while True:
    # Check if video file exists
    if not os.path.exists(f"{video_path}video{video_index + 1}.h265"):
        print(f"Waiting for video file {video_path}video{video_index + 1}.h265")
        time.sleep(1)
        continue
    else:
        print(f"Opening video file: {video_path}video{video_index + 1}.h265")

    # Open camera
    cap = cv2.VideoCapture(f"{video_path}video{video_index + 1}.h265")

    # 姿势收集列表
    pose_words = set()

    # Process video frames
    while True:
        ret, frame = cap.read()
        if not ret:
            print(f"video file {video_path}video{video_index + 1}.h265 finished")
            video_index += 1
            break

        # Flip frame horizontally for mirror effect
        frame = cv2.flip(frame, 1)
        
        # Process frame
        processed_frame, results = detector.process_frame(frame)
        
        # Display results on frame
        y_offset = 30
        
        # # Display face expressions
        # if 'expressions' in results:
        #     cv2.putText(processed_frame, f"face expression: {', '.join(results['expressions'])}", 
        #                (10, y_offset), cv2.FONT_HERSHEY_SIMPLEX, 0.7, (0, 255, 0), 2)
        #     y_offset += 30
        
        # Display poses
        if 'poses' in results:
            cv2.putText(processed_frame, f"pose: {', '.join(results['poses'])}", 
                       (10, y_offset), cv2.FONT_HERSHEY_SIMPLEX, 0.7, (255, 0, 0), 2)
            # 收集所有姿势单词
            for pose in results['poses']:
                # 只取第一个单词，全部小写
                pose_word = pose.split()[0].lower()
                pose_words.add(pose_word)
        
        # # 灯光强度检测
        # gray = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)
        # brightness = np.mean(gray)
        # cv2.putText(processed_frame, f"Brightness: {brightness:.1f}", 
        #            (10, y_offset + 30), cv2.FONT_HERSHEY_SIMPLEX, 0.7, (0, 255, 255), 2)
        # if brightness < 60:
        #     cv2.putText(processed_frame, "Lighting is too dark, please turn on the light.", (10, y_offset + 60),
        #                 cv2.FONT_HERSHEY_SIMPLEX, 0.7, (0, 0, 255), 2)
        # elif brightness > 200:
        #     cv2.putText(processed_frame, "Lighting is too bright, please adjust the light.", (10, y_offset + 60),
        #                 cv2.FONT_HERSHEY_SIMPLEX, 0.7, (0, 0, 255), 2)
        # else:
        #     cv2.putText(processed_frame, "Lighting is good.", (10, y_offset + 60),
        #                 cv2.FONT_HERSHEY_SIMPLEX, 0.7, (0, 255, 0), 2)

        # 显示分辨率和帧率
        width = int(cap.get(cv2.CAP_PROP_FRAME_WIDTH))
        height = int(cap.get(cv2.CAP_PROP_FRAME_HEIGHT))
        fps = cap.get(cv2.CAP_PROP_FPS)
        cv2.putText(processed_frame, f"Resolution: {width}x{height}", (10, y_offset + 90), cv2.FONT_HERSHEY_SIMPLEX, 0.7, (255, 255, 0), 2)
        cv2.putText(processed_frame, f"FPS: {fps:.2f}", (10, y_offset + 120), cv2.FONT_HERSHEY_SIMPLEX, 0.7, (255, 255, 0), 2)

        # Display FPS (quit info)
        cv2.putText(processed_frame, f"Press 'q' to quit", 
                   (10, processed_frame.shape[0] - 20), 
                   cv2.FONT_HERSHEY_SIMPLEX, 0.5, (255, 255, 255), 1)

        # Show frame
        cv2.imshow('face expression and pose detection', processed_frame)

        key = cv2.waitKey(1)
        if key == ord('q') or key == 27:  # 按q或ESC退出
            break
    # 每个视频结束时写入姿势单词到文件（覆写）
    output_file = f"/home/ubuntu/Desktop/rp/nfsroot/video_state"
    with open(output_file, "w") as f:
        for word in pose_words:
            f.write(word + "\n")
    # Cleanup
    cap.release()
    cv2.destroyAllWindows()


# if __name__ == "__main__":
#     main()
