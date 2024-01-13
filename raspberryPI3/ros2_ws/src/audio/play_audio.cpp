#include <iostream>
#include <cstdlib>
#include <vector>
#include <sndfile.h>

// Fonction pour lire des fichiers WAV
void playWav(const char* filename) {
    SF_INFO sfinfo;
    SNDFILE* file = sf_open(filename, SFM_READ, &sfinfo);

    if (file) {
        std::vector<short> buffer(sfinfo.frames * sfinfo.channels);
        sf_read_short(file, buffer.data(), buffer.size());

        system("amixer cset numid=3 1");  // Assurez-vous que le son est dirigé vers la sortie audio de la Raspberry Pi

        std::cout << "Lecture du fichier WAV : " << filename << std::endl;
        system("aplay -r 44100 -c 2 -f S16_LE -D hw:UACDemoV10,0");
        //system("aplay -r 44100 -c 2 -f S16_LE -D hw:5,0");  // Joue le son
        sf_close(file);
    } else {
        std::cerr << "Erreur lors de la lecture du fichier WAV : " << filename << std::endl;
    }
}

int main() {
    const char* wavFile = "obst_10db.wav";

    playWav(wavFile);

    return 0;
}
