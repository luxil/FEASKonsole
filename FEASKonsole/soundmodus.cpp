#include "soundmodus.h"

SoundModus::SoundModus()
{

}


void SoundModus::augenauf()
{
    mediaPlayer.openMusicFile("adler.mp3");
    mediaPlayer.play();
}

void SoundModus::augenzu()
{
    mediaPlayer.openMusicFile("auto_hupe.mp3");
    mediaPlayer.play();
}

void SoundModus::mundauf()
{
    mediaPlayer.openMusicFile("elefant.mp3");
    mediaPlayer.play();
}

void SoundModus::mundzu()
{
    mediaPlayer.openMusicFile("ente.mp3");
    mediaPlayer.play();
}

void SoundModus::kopfnah()
{
    mediaPlayer.openMusicFile("blubbern.mp3");
    mediaPlayer.play();
}

void SoundModus::kopffern()
{
    mediaPlayer.openMusicFile("ozean3.mp3");
    mediaPlayer.play();
}

void SoundModus::kopflinks()
{
    mediaPlayer.openMusicFile("muecke.mp3");
    mediaPlayer.play();
}

void SoundModus::kopfrechts()
{
    mediaPlayer.openMusicFile("geschuetz.mp3");
    mediaPlayer.play();
}

