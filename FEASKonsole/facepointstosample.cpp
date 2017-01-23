#include "facepointstosample.h"
#include <dlib/opencv.h>
#include <QTime>
#include <dlib/gui_widgets.h>
#include <opencv2/highgui/highgui.hpp>
#include <dlib/image_processing.h>
#include "sendoscmsg.h"
#include "soundmodus.h"
using namespace std;


facepointstosample::facepointstosample():
    sendoscmsg(new Sendoscmsg)

{
}
int audioClip=0;
int prevClip=0;

void facepointstosample::playSound(){

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
    double headdistance;





    //Berechnung der Parameter!!!!!
    mouthOpen=(double)((shapes[0].part(62)-shapes[0].part(66)).length())*100/((shapes[0].part(0)-shapes[0].part(16)).length()*ratioMouth);
    browL=(double)((shapes[0].part(20)-shapes[0].part(40)).length()-(shapes[0].part(0)-shapes[0].part(16)).length()*ratioBrowLow)*100/(((shapes[0].part(0)-shapes[0].part(16)).length()*ratioBrowHigh)-((shapes[0].part(0)-shapes[0].part(16)).length()*ratioBrowLow));
    browR=(double)((shapes[0].part(23)-shapes[0].part(47)).length()-(shapes[0].part(0)-shapes[0].part(16)).length()*ratioBrowLow)*100/(((shapes[0].part(0)-shapes[0].part(16)).length()*ratioBrowHigh)-((shapes[0].part(0)-shapes[0].part(16)).length()*ratioBrowLow));
    headpositionY=abs((double)shapes[0].part(30).y()-(cap.get(CV_CAP_PROP_FRAME_HEIGHT)/2));
    headpositionX=((double)shapes[0].part(30).x()-(cap.get(CV_CAP_PROP_FRAME_WIDTH)/2));
    rotationHead=((double)shapes[0].part(36).y()-shapes[0].part(45).y())*100/((shapes[0].part(0)-shapes[0].part(16)).length()*ratioHeadRotation);
    headdistance=(double)(shapes[0].part(0)-shapes[0].part(16)).length()*100/cap.get(CV_CAP_PROP_FRAME_WIDTH);


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
   switch (audioClip)
         {
case 1:
    cout<<"mouthOpen"<<endl;
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
         }
}


    //Ausgabe
    /*
    cout <<" X: "<<clampParam(headpositionX);
    cout <<" Y: "<<clampParam(headpositionY);//
    cout <<" Kopfneigung: "<<clampParam(rotationHead);//
    cout <<" BraueLinks: "<<clampParam(browL);//
    cout <<" BraueRechts: "<<clampParam(browR);//
    cout <<" Mund: "<<clampParam(mouthOpen);//
    cout <<endl;

    */







}


//clamp Funktion
double facepointstosample::clampParam(double percent){
   if(percent>100)
       percent=100;
   if(percent<0)
         percent=0;
    return percent;

}
