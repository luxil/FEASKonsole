#include "mymediaplayer.h"
#include <QDebug>       //für debug Konsolenausagbe

const QString path = "../Sounds/";
//const QString path = "C:/Users/Muffinman/Desktop/GitSpace/FEASKonsole/Sounds/";
MyMediaPlayer::MyMediaPlayer():
    mMediaPlayer(new QMediaPlayer)
{
    //mMediaPlayer = new QMediaPlayer(mMediaPlayer);
}

MyMediaPlayer::~MyMediaPlayer(){

}

void MyMediaPlayer::openMusicFile(const char* filename){
    QString url = path + filename;
    //qDebug() << url;
    mMediaPlayer->setMedia(QUrl::fromLocalFile(url));
}

void MyMediaPlayer::play(){
    mMediaPlayer->play();
}

void MyMediaPlayer::pause(){
    mMediaPlayer->pause();
}

void MyMediaPlayer::stop(){
    mMediaPlayer->stop();
}

void MyMediaPlayer::volume(int volume){
    mMediaPlayer->setVolume(volume);
}

void MyMediaPlayer::mute(bool mute){
    mMediaPlayer->setMuted(mute);
}
