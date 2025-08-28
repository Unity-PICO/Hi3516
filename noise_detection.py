import os
import time
import librosa
# import librosa.display
# import matplotlib.pyplot as plt
import numpy as np

audio_path = "/home/ubuntu/Desktop/rp/nfsroot/"
audio_index = 0
threshold = 0.001

"""Main function to run the detection system"""
# Initialize detector

if __name__ == "__main__":
    output_file = "audio_state"
    while True:
        # Check if audio file exists
        if not os.path.exists(f"{audio_path}audio{audio_index + 1}.aac"):
            print("Waiting for audio file...")
            time.sleep(1)
            continue
        else:
            print(f"Opening audio file: {audio_path}audio{audio_index + 1}.aac")

        # 读入音频
        y, sr = librosa.load(f"{audio_path}audio{audio_index + 1}.aac", sr=None)

        # 计算短时能量 (frame-level RMS)
        rms = librosa.feature.rms(y=y)[0]

        # 判断平均能量是否超过阈值
        avg_energy = np.mean(rms)
        print(f"平均能量: {avg_energy:.6f}")

        with open(output_file, "a") as f:
            if avg_energy > threshold:
                f.write("yes\n")
            else:
                f.write("no\n")

        # # 绘制波形
        # plt.figure(figsize=(12, 4))
        # librosa.display.waveshow(y, sr=sr)
        # plt.title("Waveform")
        # plt.show()

        # # 计算频谱
        # D = np.abs(librosa.stft(y))
        # plt.figure(figsize=(12, 6))
        # librosa.display.specshow(librosa.amplitude_to_db(D, ref=np.max),
        #                         sr=sr, x_axis="time", y_axis="log")
        # plt.colorbar(format="%+2.0f dB")
        # plt.title("Spectrogram (dB)")
        # plt.show()
