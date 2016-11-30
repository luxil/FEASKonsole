#ifndef SOUNDMODUS_H
#define SOUNDMODUS_H

#include "mymediaplayer.h"

class SoundModus
{
public:
    SoundModus();
    void augenauf();
    void augenzu();
    void mundauf();
    void mundzu();
    void kopfnah();
    void kopffern();
    void kopflinks();
    void kopfrechts();

private:
    MyMediaPlayer mediaPlayer;
};

#endif // SOUNDMODUS_H
