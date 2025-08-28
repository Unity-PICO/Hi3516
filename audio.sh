#!/bin/sh

# $1
if [ -n "$1" ]; then
	DURATION=$1
else
	DURATION=5
fi
	
BASE_PATH="/usr/sample/audio/"
NFS_PATH="/nfsroot/"
PROGRAM_NAME="sample_audio"
#PROGRAM_INPUT="${BASE_PATH}${PROGRAM_NAME} 1"
PROGRAM_INPUT='echo "Begin input"'
#PROGRAM_OUTPUT="${BASE_PATH}${PROGRAM_NAME} 2"
PROGRAM_OUTPUT='echo "Begin output."'
AUDIO_FILENAME_EXTENSION=".aac"
AUDIO_OUTPUT_FILENAME="audio_chn0"
AUDIO_INPUT_FILENAME="audio_chn0"
AUDIO_SOURCE="${AUDIO_OUTPUT_FILENAME}${AUDIO_FILENAME_EXTENSION}"
AUDIO_BASE_FILENAME="audio"
AUDIO_INDEX=0

AUDIO_NOISY="noisy"

VIDEO_STATE_FILE="video_state"
AUDIO_STATE_FILE="audio_state"

if [ "$(hostname)" = "(none)" ]; then
	echo "Start audio."
	cd "$BASE_PATH"
	while true; do
		$PROGRAM_INPUT > /dev/null &
		# $PROGRAM_INPUT > /dev/null 2>&1 &
		PID=$!
	    sleep $DURATION
        if ps -p $PID ? /dev/null; then
            kill $PID 2>/dev/null
            wait $PID 2>/dev/null
		
        if [ -f "$AUDIO_SOURCE" ]; then
			AUDIO_DESTINATION="${NFS_PATH}${AUDIO_BASE_FILENAME}${AUDIO_INDEX}${AUDIO_FILENAME_EXTENSION}"
			mv "${AUDIO_SOURCE}" "${AUDIO_DESTINATION}"
            AUDIO_INDEX=$(expr $AUDIO_INDEX + 1) 
			echo "${AUDIO_DESTINATION} has been created successfully!"
		else
			echo "Failed to create ${AUDIO_DESTINATION}" 
		fi

        if [ -f "$VIDEO_STATE_FILE" ]; then
           while IFS= read -r word; do
               case "$word" in
                   start)
                       echo "start"
                       ;;
                   stop)
                       echo "stop"
                       ;;
                   restart)
                       echo "restart"
                       ;;
                   *)
                       echo "default"
                       ;;
                esac
            done < "$file"
        else 
            echo "File ${AUDIO_STATE_FILE} not found!"
        fi

        if [ -f "$AUDIO_STATE_FILE" ]; then
            lines=$(wc -l < "$AUDIO_STATE_FILE")   
            if [[ $lines -eq 1 ]] ; then
                read -r line < "$AUDIO_STATE_FILE"
                if [[ "$line" == "yes" ]]; then
                    if [ -f "${AUDIO_NOISY}${AUDIO_FILENAME_EXtENSION}" ]; then
                        cp "${AUDIO_NOISY}${AUDIO_FILENAME_EXTENSION}" "${AUDIO_INPUT_FILENAME}${AUDIO_FILENAME_EXTENSION}"
                        $PROGRAM_OUTPUT > /dev/null &
                        PID=$!
                        sleep 2
                        if ps -p $PID ? /dev/null; then
                            kill $PID 2>/dev/null
                            wait $PID 2>/dev/null

                    fi
                fi
            else
                echo "File ${AUDIO_STATE_FILE} is illegal!"
            fi
        else
            echo "File ${AUDIO_STATE_FILE} not found!"
        fi
	done	
else
	echo "Not the target machine."
fi

