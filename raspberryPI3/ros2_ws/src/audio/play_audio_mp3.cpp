#include <iostream>
#include <cstdlib>

int main() {
    const char* mp3File = "obst_10db.mp3";

    // Utilisez mpg123 pour décompresser le fichier MP3 et le lire avec aplay
    system("mpg123 -q -w - obst_10db.mp3 | aplay -D hw:UACDemoV10,0 -r 44100");

    return 0;
}

