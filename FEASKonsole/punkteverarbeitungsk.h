#ifndef PUNKTEVERARBEITUNGSK_H
#define PUNKTEVERARBEITUNGSK_H

#include <dlib/opencv.h>
#include <dlib/gui_widgets.h>

class PunkteVerarbeitungsK
{
public:
    PunkteVerarbeitungsK();
    ~PunkteVerarbeitungsK();
    std::vector<dlib::full_object_detection> shapes;
    void playSound();
    double clampParam(double percent);
};

#endif // PUNKTEVERARBEITUNGSK_H
