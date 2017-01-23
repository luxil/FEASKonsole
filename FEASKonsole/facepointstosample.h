#ifndef FACEPOINTSTOSAMPLE_H
#define FACEPOINTSTOSAMPLE_H

#include <dlib/opencv.h>
#include <dlib/gui_widgets.h>
#include <opencv2/highgui/highgui.hpp>
#include <dlib/image_processing.h>
#include "sendoscmsg.h"
#include <QTime>
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


};

#endif // FACEPOINTSTOSAMPLE_H
