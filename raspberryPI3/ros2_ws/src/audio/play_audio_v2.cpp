#include <iostream>
#include <cstdlib>

void playWav(const char* filename) {
    // Utilisez cvlc pour jouer le fichier audio avec le moteur de sortie ALSA
    system("sox obst_10db.wav -r 44100 -c 2 -b 16 -t wav - | aplay -D hw:UACDemoV10,0 -r 44100");
    //system("sox obst_10db.wav -r 44100 -c 2 -b 16 -t wav - | aplay -D hw:UACDemoV10,0");
    //system("aplay -D hw:UACDemoV10,0 -r 44100 -c 2 -f S24_LE obst_10db.wav");
    //system("cvlc --no-xlib --aout alsa --alsa-audio-device hw:UACDemoV10,0 obst_10db.wav");
    //system("vlc --no-xlib --no-x11-display --aout alsa --alsa-audio-device hw:UACDemoV10,0 --intf dummy obst_10db.wav vlc://quit");
    //system("vlc --no-xlib --aout alsa --alsa-audio-device hw:UACDemoV10,0 --intf dummy obst_10db.wav vlc://quit");
    //system("cvlc --aout alsa --alsa-audio-device hw:UACDemoV10,0 obst_10db.wav");
}

int main() {
    const char* wavFile = "obst_10db.wav";

    // Appeler la fonction pour lire le fichier audio
    playWav(wavFile);

    return 0;
}
