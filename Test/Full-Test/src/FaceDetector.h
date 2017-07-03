#ifndef FACE_DETECTOR_H
#define FACE_DETECTOR_H

#include "opencv2/highgui.hpp"
#include "opencv2/objdetect.hpp"
#include "opencv2/imgproc.hpp"
#include <iostream>
#include <sstream>
#include <cstdio>
#include <cmath>
#include <vector>

// Screen resolution constants
#define R_WIDTH 640
#define R_HEIGHT 480

class FaceDetector {
private:
        static cv::Mat frame;
        static cv::VideoCapture capture;
        static std::vector<cv::Rect> faces;
        static cv::Rect main_face;
        static cv::Scalar main_face_col;
        static int main_id;

        static std::string face_cascade_name;
        static cv::CascadeClassifier face_cascade;
        static int low_canny_thresh;
        static int canny_ratio;  

public:
        static void initialize();
        static void detectFace();
        static void makeMesh(cv::Rect loc);
        static void terminate();
        static void idUser();
        static void showUserId();
	static void printUserId();
        static cv::Rect getMainFace();
        static int getMainID();
};

#endif
