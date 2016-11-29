#ifndef WINDOW_H
#define WINDOW_H

#include <dlib/opencv.h>
#include <dlib/gui_widgets.h>

class Win
{
public:
    dlib::image_window *imageWin;
    Win();
    ~Win();
    boolean is_closed();
    std::vector<dlib::full_object_detection> shapes;
    void drawImage(dlib::cv_image<dlib::bgr_pixel> cimg);
    void drawFacePoints();
};

#endif // WINDOW_H
