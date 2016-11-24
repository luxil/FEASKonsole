#ifndef FACEDETANDFPL_H
#define FACEDETANDFPL_H

#include <dlib/opencv.h>
#include <opencv2/highgui/highgui.hpp>
#include <dlib/image_processing/frontal_face_detector.h>
#include <dlib/image_processing/render_face_detections.h>
#include <dlib/image_processing.h>
#include <dlib/gui_widgets.h>
#include <dlib/image_io.h>
#include "win.h"


using namespace std;
using namespace dlib;


class FaceDetAndFPL
{
public:
    Win winClass;
    FaceDetAndFPL();
    ~FaceDetAndFPL();
    void findFacesAndPoints();
    void sendFacePoints(std::vector<full_object_detection> shapes);
};

#endif // FACEDETANDFPL_H
