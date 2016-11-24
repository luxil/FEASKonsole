#include <QCoreApplication>
#include "facedetandfpl.h"
#include "win.h"
#include <QDebug>

void openWindow(){
    qDebug() <<">>> openWindow";
    Win win;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    FaceDetAndFPL f;
    f.findFacesAndPoints();
    return a.exec();
}



