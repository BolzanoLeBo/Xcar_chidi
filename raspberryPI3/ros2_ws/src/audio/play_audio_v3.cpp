#include <iostream>
#include <cstdlib>

void adjustVolume() {
    // Ajuster le volume à 50%
    system("pactl set-sink-volume 0 50%");
}

void playWav(const char* filename) {
    // Appeler la fonction pour ajuster le volume
    adjustVolume();

    // Jouer le fichier audio avec aplay
    
    //system("aplay -D hw:UACDemoV10,0 obst_10db.wav");
    //system("paplay -d hw:UACDemoV10,0 --format=s16le --rate=44100 obst_10db.wav");
    //system("paplay -d hw:UACDemoV10,0 obst_10db.wav");
    //system("aplay -r 44100 -c 2 -f S24_3LE -D hw:UACDemoV10,0 obst_10db.wav");
    //system("aplay -r 44100 -c 2 -f S16_LE -D hw:UACDemoV10,0 obst_10db.wav");
}

int main() {
    const char* wavFile = "obst_10db.wav";

    // Appeler la fonction pour lire le fichier audio
    playWav(wavFile);

    return 0;
}
