#ifndef FACEDETANDFPL_H
#define FACEDETANDFPL_H

#include "win.h"


class FaceDetAndFPL
{
public:
    Win winClass;
    FaceDetAndFPL();
    ~FaceDetAndFPL();
    void findFacesAndPoints();
    void sendFacePoints(std::vector<dlib::full_object_detection> shapes);
};

#endif // FACEDETANDFPL_H
