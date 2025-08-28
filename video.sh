#!/bin/sh

# $1
if [ -n "$1" ]; then
	DURATION=$1
else
	DURATION=5
fi
	
BASE_PATH="/usr/sample/venc/"
NFS_PATH="/nfsroot/"
PROGRAM_NAME="sample_venc"
PROGRAM="${BASE_PATH}${PROGRAM_NAME} 1"
VIDEO_FILENAME_EXTENSION=".h265"
VIDEO_OUTPUT_FILENAME="stream_chn0"
VIDEO_SOURCE="${VIDEO_OUTPUT_FILENAME}${VIDEO_FILENAME_EXTENSION}"
VIDEO_BASE_FILENAME="video"
VIDEO_INDEX=0

if [ "$(hostname)" = "(none)" ]; then
	echo "Start video."
	cd "$BASE_PATH"
	while true; do
		(
			echo "c"
			sleep 1
			echo "2"
			sleep $DURATION
			echo ""
			echo ""	
		) | $PROGRAM > /dev/null &
		#) | $PROGRAM > /dev/null 2>&1 &

		PID=$!
		wait $PID 2 > /dev/null
		
        if [ -f "$VIDEO_SOURCE" ]; then
			VIDEO_DESTINATION="${NFS_PATH}${VIDEO_BASE_FILENAME}${VIDEO_INDEX}${VIDEO_FILENAME_EXTENSION}"
			mv "${VIDEO_SOURCE}" "${VIDEO_DESTINATION}"
            VIDEO_INDEX=$(expr $VIDEO_INDEX + 1) 
			echo "${VIDEO_DESTINATION} has been created successfully!"
		else
			echo "Failed to create ${VIDEO_DESTINATION}" 
		fi
	done	
else
	echo "Not the target machine."
fi

