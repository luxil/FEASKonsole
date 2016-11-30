#include <QCoreApplication>
#include "facedetandfpl.h"
#include "soundmodus.h"
#include "win.h"
#include <QDebug>

void openWindow(){
    qDebug() <<">>> openWindow";
    Win win;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    //Test ob das Soundabspielen funktioniert
    //SoundModus soundModus;
    //soundModus.augenauf();


    FaceDetAndFPL f;
    f.findFacesAndPoints();
    return a.exec();
}



