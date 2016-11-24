#ifndef WINDOW_H
#define WINDOW_H
#include <dlib/gui_widgets.h>

#include <dlib/opencv.h>
#include <opencv2/highgui/highgui.hpp>
#include <dlib/image_processing/frontal_face_detector.h>
#include <dlib/image_processing/render_face_detections.h>
#include <dlib/image_processing.h>
#include <dlib/gui_widgets.h>
#include <dlib/image_io.h>


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
