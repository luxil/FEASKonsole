#include "punkteverarbeitungsk.h"

PunkteVerarbeitungsK::PunkteVerarbeitungsK()
{

}

PunkteVerarbeitungsK::~PunkteVerarbeitungsK(){
    //nicht ausführen, sonst schließt sich das Fenster
    //delete imageWin;
}

/*
void PunkteVerarbeitungsK::playSound(){
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


    //Berechnung der Parameter!!!!!


    mouthOpen=(double)((shapes.part(62)-shapes.part(66)).length())*100/((shapes.part(0)-shapes.part(16)).length()*ratioMouth);
    browL=(double)((shapes.part(20)-shapes.part(40)).length()-(shapes.part(0)-shapes.part(16)).length()*ratioBrowLow)*100/(((shape.part(0)-shapes.part(16)).length()*ratioBrowHigh)-((shapes.part(0)-shapes.part(16)).length()*ratioBrowLow));

    browR=(double)((shapes.part(23)-shapes.part(47)).length()-(shapes.part(0)-shapes.part(16)).length()*ratioBrowLow)*100/(((shapes.part(0)-shapes.part(16)).length()*ratioBrowHigh)-((shapes.part(0)-shapes.part(16)).length()*ratioBrowLow));

    headpositionY=abs((double)shapes.part(30).y()-(cap.get(CV_CAP_PROP_FRAME_HEIGHT)/2));
    headpositionX=abs((double)shapes.part(30).x()-(cap.get(CV_CAP_PROP_FRAME_WIDTH)/2));

    rotationHead=abs((double)shapes.part(36).y()-shapes.part(45).y())*100/((shapes.part(0)-shapes.part(16)).length()*ratioHeadRotation);

    //Ausgabe

    cout <<" X: "<<clampParam(headpositionX);
    cout <<" Y: "<<clampParam(headpositionY);
    cout <<" Kopfneigung: "<<clampParam(rotationHead);
    cout <<" BraueLinks: "<<clampParam(browL);
    cout <<" BraueRechts: "<<clampParam(browR);
    cout <<" Mund: "<<clampParam(mouthOpen);
    cout <<endl;



}


//clamp Funktion
double PunkteVerarbeitungsK::clampParam(double percent)
{
   if(percent>100)
       percent=100;
   if(percent<0)
         percent=0;
    return percent;

}*/
