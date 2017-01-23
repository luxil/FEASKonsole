#include "soundmodus.h"
#include "mymediaplayer.h"

SoundModus::SoundModus():
    mediaPlayer(new MyMediaPlayer)
{

}

void SoundModus::braueLinks()
{
    mediaPlayer->openMusicFile("adler.mp3");
    mediaPlayer->play();
    //Sleep(3000);
}

void SoundModus::braueRechts()
{
    mediaPlayer->openMusicFile("auto_hupe.mp3");
    mediaPlayer->play();
    //Sleep(1000);
}

void SoundModus::mundauf()
{
    mediaPlayer->openMusicFile("elefant.mp3");
    mediaPlayer->play();
    //Sleep(2000);
}

void SoundModus::kopfrotation()
{
    mediaPlayer->openMusicFile("ente.mp3");
    mediaPlayer->play();
    //Sleep(5000);
}

void SoundModus::kopfoben()
{
    mediaPlayer->openMusicFile("blubbern.mp3");
    mediaPlayer->play();
    //Sleep(3000);
}

void SoundModus::kopfunten()
{
    mediaPlayer->openMusicFile("ozean3.mp3");
    mediaPlayer->play();
    //Sleep(9000);
}

void SoundModus::kopflinks()
{
    mediaPlayer->openMusicFile("muecke.mp3");
    mediaPlayer->play();
    //Sleep(4000);
}

void SoundModus::kopfrechts()
{
    mediaPlayer->openMusicFile("geschuetz.mp3");
    mediaPlayer->play();
    //Sleep(4000);
}

