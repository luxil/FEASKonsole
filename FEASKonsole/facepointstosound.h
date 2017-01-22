#ifndef FACEPOINTSTOSOUND_H
#define FACEPOINTSTOSOUND_H

#include <dlib/opencv.h>
#include <dlib/gui_widgets.h>
#include <opencv2/highgui/highgui.hpp>
#include <dlib/image_processing.h>


class FacePointsToSound
{
public:
    FacePointsToSound();
    ~FacePointsToSound();
    std::vector<dlib::full_object_detection> shapes;
    void playSound();
    double clampParam(double percent);
    cv::VideoCapture cap;
};

#endif // FACEPOINTSTOSOUND_H
