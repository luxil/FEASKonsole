#include <QCoreApplication>
#include "facedetandfpl.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    FaceDetAndFPL f;
    f.funcFaceDetAndFPL();
    return a.exec();
}



