#include <QApplication>
#include <QDebug>
#include "widget.h"
//#include "win.h"

/*void openWindow(){
    qDebug() <<">>> openWindow";
    Win win;
}*/

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget window;
    window.show();


    //FaceDetAndFPL f;
    //f.findFacesAndPoints();
    return a.exec();
}



