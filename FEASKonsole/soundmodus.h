#ifndef SOUNDMODUS_H
#define SOUNDMODUS_H

#include "mymediaplayer.h"
#include <windows.h>

class SoundModus
{
public:
    SoundModus();
    void braueLinks();
    void braueRechts();
    void mundauf();
    void kopfrotation();
    void kopfoben();
    void kopfunten();
    void kopflinks();
    void kopfrechts();

public:
    bool on;

private:
    MyMediaPlayer *mediaPlayer;
};

#endif // SOUNDMODUS_H
