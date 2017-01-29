/**
  * Quellen für den Code aus: http://dlib.net/face_landmark_detection_ex.cpp.html
  * und http://dlib.net/webcam_face_pose_ex.cpp.html
  *
  * */

#include "facedetandfpl.h"
#include "win.h"
#include "facepointstosample.h"
#include "soundmodus.h"
#include "facepointstosound.h"

#include <dlib/image_processing/frontal_face_detector.h>
#include <opencv2/highgui/highgui.hpp>
#include <dlib/image_processing.h>

#include "opencv2/imgproc/imgproc.hpp" //für resize cv
#include "opencv2/opencv.hpp"           //für resize cv
#include <dlib/image_transforms.h>

using namespace std;
using namespace dlib;

FaceDetAndFPL::FaceDetAndFPL():
    sendoscmsg(new Sendoscmsg)
    ,fpts(new FacePointsToSound)
    ,soundModus(new SoundModus)
    ,fptSam(new facepointstosample)
    ,winClass(new Win)
  //Vorschlag: Man könnte überlegen, dass fpts oder ftpSam jeweils nur initialisiert werden sollen,
  //wenn der entsprechende Modus dazu ausgewählt wurde. Dies könnte man zum Beispiel mithilfe
  //von Polymorphismus lösen. Dies umzusetzen hat jedoch
  //keine Prio und kann man vielleicht mal umsetzen, wenn die Zeit dafür da ist.
{    
}



void FaceDetAndFPL::findFacesAndPoints(){
    try
    {
        string pathToSPDat = "../shape_predictor_68_face_landmarks.dat";
        //string pathToSPDat = "C:/Users/Muffinman/Desktop/FEASKonsole/shape_predictor_68_face_landmarks.dat";
        cv::VideoCapture cap(0);
        if (!cap.isOpened()){
            cerr << "Unable to connect to camera" << endl;
            //return 1;
        }

        // Load face detection and pose estimation models.
        frontal_face_detector detector = get_frontal_face_detector();
        shape_predictor pose_model;
        deserialize(pathToSPDat) >> pose_model;
        // Grab and process frames until the main window is closed by the user.
        cv::Size sizeForCam = getSizeForCameraWin();
        while(!winClass->is_closed()){
            // Grab a frame
            cv::Mat temp;
            cap >> temp;
            // Turn OpenCV's Mat into something dlib can deal with.  Note that this just
            // wraps the Mat object, it doesn't copy anything.  So cimg is only valid as
            // long as temp is valid.  Also don't do anything to temp that would cause it
            // to reallocate the memory which stores the image as that will make cimg
            // contain dangling pointers.  This basically means you shouldn't modify temp
            // while using cimg.


            // Resize the image
            //cout<<"height: "<<temp.cols*5/4 << " " <<temp.rows*5/4<<endl;
            cv::Size size(sizeForCam);//the dst image size,e.g.100x100
            cv::Mat dstImg;//dst image
            cv::resize(temp,dstImg,size);//resize image
            cv::flip(dstImg, temp, 1);
            cv_image<bgr_pixel> cimg(temp);

            // Detect faces
            std::vector<rectangle> faces = detector(cimg);
            // Find the pose of each face.
            std::vector<full_object_detection> shapes;
            for (unsigned long i = 0; i < faces.size(); ++i){
                dlib::full_object_detection shape = pose_model(cimg, faces[i]);

                //cout << "pixel position of first part:  " << shape.part(0) << endl;
                shapes.push_back(shape);
                //cout << "shapes" << shapes[0].part(0)(0) <<endl;
                //cout << "faces.size()" << faces.size() <<endl;

            }


            // Display it all on the screen
            if(faces.size() >0){
                sendFacePoints(shapes);
                winClass->drawImage(cimg);
                winClass->drawFacePoints();

                if(programmModus==1){
                    fpts->cap = cap;
                    fpts->playSound();


                } else if(programmModus==0){
                    fptSam->cap =cap;
                    fptSam->playSound();
                }
            }
        }
    }
    catch(serialization_error& e) {cout << endl << e.what() << endl;}
    catch(exception& e){cout << e.what() << endl;}
}


FaceDetAndFPL::~FaceDetAndFPL()
{
}


void FaceDetAndFPL::sendFacePoints(std::vector<full_object_detection> shapes){
    winClass->shapes = shapes;
    fpts->shapes = shapes;
    fptSam->shapes = shapes;
}


cv::Size FaceDetAndFPL::getSizeForCameraWin(){
    int tbheight = 0;
    RECT rectWork = { 0 };
    if (SystemParametersInfo(SPI_GETWORKAREA, 0, &rectWork, 0))
    {
            int scrheight = GetSystemMetrics(SM_CYSCREEN);
            tbheight = scrheight - (rectWork.bottom - rectWork.top);
    }

    int height = GetSystemMetrics(SM_CYSCREEN)/8*5;
    int width = height*4/3;
    cv::Size size(width, height);
    cout<<"height: "<<width<< " " << height <<endl;
    return size;
}
