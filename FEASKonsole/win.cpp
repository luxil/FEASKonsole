#include "win.h"
#include <dlib/gui_widgets.h>
#include <dlib/image_processing/render_face_detections.h>

using namespace std;

Win::Win()
    :imageWin(new dlib::image_window)
{
    //imageWin->show();

}

Win::~Win(){
    //nicht ausführen, sonst schließt sich das Fenster
    //delete imageWin;
}

boolean Win::is_closed(){
    return imageWin->is_closed();
}


void Win::drawImage(dlib::cv_image<dlib::bgr_pixel> cimg){

    imageWin->clear_overlay();
    imageWin->set_image(cimg);
}

void Win::drawFacePoints(){
    imageWin->add_overlay(dlib::render_face_detections(shapes));
    //cout << "shapes" << shapes[0].part(0) <<endl;
}

