#include "facepointstosample.h"
#include <dlib/opencv.h>

#include <dlib/gui_widgets.h>
#include <opencv2/highgui/highgui.hpp>
#include <dlib/image_processing.h>
#include "sendoscmsg.h"
#include "soundmodus.h"

using namespace std;

facepointstosample::facepointstosample():
    sendoscmsg(new Sendoscmsg)
    ,soundModus(new SoundModus)
    ,audioClip(0)
    ,prevClip(0)
    ,ratioBrowLow(0.14)
    ,ratioBrowHigh(0.26)
    ,ratioMouth(0.18)
    ,ratioHeadRotation(0.15)

{

}



void facepointstosample::playSound(){

    Parameterberechnung();

    if(clampParam(browL)>85||clampParam(browR)>85){
        //cout<<"browclip"<<endl;
        audioClip=2;
    }
     if(clampParam(mouthOpen)>85){
        //cout<<"MouthOpen"<<endl;
        audioClip=1;

    }
    // if(clampParam(mouthOpen)<10)
     //   cout<<"MouthClosed"<<endl;

     if(headpositionX<-60){
        //cout<<"HeadLeft"<<endl;
        audioClip=5;
     }
     if(headpositionX>60){
        //cout<<"HeadRight"<<endl;
        audioClip=6;
     }
    if(rotationHead>90){
        //cout<<"HeadTilted"<<endl;
        audioClip=7;
   }

   if(rotationHead<-90){
        //cout<<"HeadTilted"<<endl;
        audioClip=8;
   }

    if(audioClip!=prevClip){
       switch (audioClip){
            case 1:
                cout<<"mouthOpen"<<endl;
                soundModus->mundauf();
                prevClip=1;
                break;
            case 2:
                cout<<"browHigh"<<endl;
                prevClip=2;
                break;
            case 3:
                cout<<"headNear"<<endl;
                prevClip=3;
                break;
            case 4:
                cout<<"headFar"<<endl;
                prevClip=4;
                break;
            case 5:
                cout<<"headRight"<<endl;
                prevClip=5;
                break;
            case 6:
                cout<<"headleft"<<endl;
                prevClip=6;
                break;
            case 7:
                cout<<"tiltRight"<<endl;
                prevClip=7;
                break;
            case 8:
                cout<<"tiltLeft"<<endl;
                prevClip=8;
                break;
            default:
                cout<<"";
                break;
       }
    }
}

void facepointstosample::Parameterberechnung(){
    //Berechnung der Parameter!!!!!
    mouthOpen=(double)((shapes[0].part(62)-shapes[0].part(66)).length())*100/((shapes[0].part(0)-shapes[0].part(16)).length()*ratioMouth);
    browL=(double)((shapes[0].part(20)-shapes[0].part(40)).length()-(shapes[0].part(0)-shapes[0].part(16)).length()*ratioBrowLow)*100/(((shapes[0].part(0)-shapes[0].part(16)).length()*ratioBrowHigh)-((shapes[0].part(0)-shapes[0].part(16)).length()*ratioBrowLow));
    browR=(double)((shapes[0].part(23)-shapes[0].part(47)).length()-(shapes[0].part(0)-shapes[0].part(16)).length()*ratioBrowLow)*100/(((shapes[0].part(0)-shapes[0].part(16)).length()*ratioBrowHigh)-((shapes[0].part(0)-shapes[0].part(16)).length()*ratioBrowLow));
    headpositionY=abs((double)shapes[0].part(30).y()-(cap.get(CV_CAP_PROP_FRAME_HEIGHT)/2));
    headpositionX=((double)shapes[0].part(30).x()-(cap.get(CV_CAP_PROP_FRAME_WIDTH)/2));
    rotationHead=((double)shapes[0].part(36).y()-shapes[0].part(45).y())*100/((shapes[0].part(0)-shapes[0].part(16)).length()*ratioHeadRotation);
    headdistance=(double)(shapes[0].part(0)-shapes[0].part(16)).length()*100/cap.get(CV_CAP_PROP_FRAME_WIDTH);
}

//clamp Funktion
double facepointstosample::clampParam(double percent){
   if(percent>100)
       percent=100;
   if(percent<0)
         percent=0;
    return percent;

}

double facepointstosample::getMouthOpen(){
    return mouthOpen;
}

double facepointstosample::getBrowR(){
    return browR;
}

double facepointstosample::getBrowL(){
    return browL;
}

double facepointstosample::getHeadPosY(){
    return headpositionY;
}

double facepointstosample::getHeadPosX(){
    return headpositionX;
}

double facepointstosample::getRotationHead(){
    return rotationHead;
}

