#include "facepointstosound.h"
#include <dlib/opencv.h>
#include <QTime>
#include <dlib/gui_widgets.h>
#include <opencv2/highgui/highgui.hpp>
#include <dlib/image_processing.h>
#include "sendoscmsg.h"
using namespace std;


FacePointsToSound::FacePointsToSound():
    sendoscmsg(new Sendoscmsg)
{
    //Neue Variablen;
    double mouthOpen=0;
    double browR=0;
    double browL=0;
    double headpositionY=0;
    double headpositionX=0;
    double rotationHead=0;

    double ratioBrowLow=0.14;
    double ratioBrowHigh=0.26;
    double ratioMouth=0.18;
    double ratioHeadRotation=0.15;
}


void FacePointsToSound::playSound(){

    bool active=true;
    QTime delay;

    //Berechnung der Parameter!!!!!
    Parameterberechnung();

/*
if(active){
    delay=QTime::currentTime().addMSecs(500);
    cout<<"Trigger"<<endl;
    active=false;
}
if(QTime::currentTime()>delay){
    cout<<"activate!!!"<<endl;
    active=true;
    cout<<"activate!!!"<<endl;
}*/

    //Ausgabe
    cout <<" X: "<<clampParam(headpositionX);
    cout <<" Y: "<<clampParam(headpositionY);//
    cout <<" Kopfneigung: "<<clampParam(rotationHead);//
    cout <<" BraueLinks: "<<clampParam(browL);//
    cout <<" BraueRechts: "<<clampParam(browR);//
    cout <<" Mund: "<<clampParam(mouthOpen);//
    cout <<endl;


    sendoscmsg->send("/MundH", clampParam(mouthOpen));
    //sendoscmsg->send("/MundB", value);
    sendoscmsg->send("/AugenbraueL", clampParam(browL));
    sendoscmsg->send("/AugenbraueR", clampParam(browR));
    sendoscmsg->send("/Kopfdrehung", clampParam(rotationHead));
    //sendoscmsg->send("/Kopfskalierung", value);
    sendoscmsg->send("/AugeL", clampParam(headpositionX));
    sendoscmsg->send("/AugeR", clampParam(headpositionY));
}


//clamp Funktion
double FacePointsToSound::clampParam(double percent){
   if(percent>100)
       percent=100;
   if(percent<0)
         percent=0;
    return percent;

}

void FacePointsToSound::Parameterberechnung(){
    //Berechnung der Parameter!!!!!
    mouthOpen=(double)((shapes[0].part(62)-shapes[0].part(66)).length())*100/((shapes[0].part(0)-shapes[0].part(16)).length()*ratioMouth);
    browL=(double)((shapes[0].part(20)-shapes[0].part(40)).length()-(shapes[0].part(0)-shapes[0].part(16)).length()*ratioBrowLow)*100/(((shapes[0].part(0)-shapes[0].part(16)).length()*ratioBrowHigh)-((shapes[0].part(0)-shapes[0].part(16)).length()*ratioBrowLow));
    browR=(double)((shapes[0].part(23)-shapes[0].part(47)).length()-(shapes[0].part(0)-shapes[0].part(16)).length()*ratioBrowLow)*100/(((shapes[0].part(0)-shapes[0].part(16)).length()*ratioBrowHigh)-((shapes[0].part(0)-shapes[0].part(16)).length()*ratioBrowLow));
    headpositionY=abs((double)shapes[0].part(30).y()-(cap.get(CV_CAP_PROP_FRAME_HEIGHT)/2));
    headpositionX=abs((double)shapes[0].part(30).x()-(cap.get(CV_CAP_PROP_FRAME_WIDTH)/2));
    rotationHead=abs((double)shapes[0].part(36).y()-shapes[0].part(45).y())*100/((shapes[0].part(0)-shapes[0].part(16)).length()*ratioHeadRotation);
}

double FacePointsToSound::getMouthOpen(){
    return mouthOpen;
}

double FacePointsToSound::getBrowR(){
    return browR;
}

double FacePointsToSound::getBrowL(){
    return browL;
}

double FacePointsToSound::getHeadPosY(){
    return headpositionY;
}

double FacePointsToSound::getHeadPosX(){
    return headpositionX;
}

double FacePointsToSound::getRotationHead(){
    return rotationHead;
}

