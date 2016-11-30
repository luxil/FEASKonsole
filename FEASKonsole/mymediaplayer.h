#ifndef MEDIAPLAYER_H
#define MEDIAPLAYER_H

#include <QMediaPlayer>

class MyMediaPlayer{

public:
    MyMediaPlayer();
    ~MyMediaPlayer();
    void openMusicFile(const char *filename);
    void play();
    void pause();
    void stop();
    void volume(int volume);
    void mute(bool mute);

private:
    QMediaPlayer *mMediaPlayer;
};

#endif // MEDIAPLAYER_H
