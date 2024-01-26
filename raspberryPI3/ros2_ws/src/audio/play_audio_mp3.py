import os

def play_audio_mp3(file_path, file_name):
    
    #os.system(" pacmd set-default-sink \"alsa_output.usb-Jieli_Technology_UACDemoV1.0_4150333236393504-00.analog-stereo\"")
    #os.system(" pacmd set-sink-volume \"alsa_output.usb-Jieli_Technology_UACDemoV1.0_4150333236393504-00.analog-stereo\" 60000")
    os.system(f"ffplay -v 0 -nodisp -autoexit {file_path}{file_name}") 

if __name__ == "__main__":
    # chemin absolue : ~/arthur/Xcar_chidi/raspberryPI3/ros2_ws/src/audio
    mp3_file = "~/arthur/Xcar_chidi/raspberryPI3/ros2_ws/src/audio/"
    mp3_name = "obst_10db.mp3"
    play_audio_mp3(mp3_file,mp3_name)