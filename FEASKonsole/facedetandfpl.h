#ifndef FACEDETANDFPL_H
#define FACEDETANDFPL_H

#include "win.h"
#include "punkteverarbeitungsk.h"
#include "sendoscmsg.h"
#include "facepointstosample.h"
#include "soundmodus.h"
#include "facepointstosound.h"


class FaceDetAndFPL
{
public:
    Win winClass;

    FaceDetAndFPL();
    ~FaceDetAndFPL();
    void findFacesAndPoints();
    void sendFacePoints(std::vector<dlib::full_object_detection> shapes);
    Sendoscmsg *sendoscmsg;
    FacePointsToSound *fpts;
    facepointstosample *fptSam;
    SoundModus *soundModus;
    int programmModus;
};

#endif // FACEDETANDFPL_H
