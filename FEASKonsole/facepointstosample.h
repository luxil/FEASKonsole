#ifndef FACEPOINTSTOSAMPLE_H
#define FACEPOINTSTOSAMPLE_H
#include "mymediaplayer.h"
#include <dlib/opencv.h>
#include <dlib/gui_widgets.h>
#include <opencv2/highgui/highgui.hpp>
#include <dlib/image_processing.h>
#include "sendoscmsg.h"

#include "soundmodus.h"

class facepointstosample
{
public:
    facepointstosample();
    ~facepointstosample();

    std::vector<dlib::full_object_detection> shapes;
    void playSound();
    double clampParam(double percent);
    cv::VideoCapture cap;
    Sendoscmsg *sendoscmsg;
    SoundModus *soundModus;

    void Parameterberechnung();
    double getMouthOpen();
    double getBrowR();
    double getBrowL();
    double getHeadPosY();
    double getHeadPosX();
    double getRotationHead();


private:
    double mouthOpen;
    double browR;
    double browL;
    double headpositionY;
    double headpositionX;
    double rotationHead;
    double ratioBrowLow;
    double ratioBrowHigh;
    double ratioMouth;
    double ratioHeadRotation;
    double headdistance;

    int audioClip;
    int prevClip;


};

#endif // FACEPOINTSTOSAMPLE_H
