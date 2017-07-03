/*
 * Title:	CVProcessor.h
 * Author:	Dilpreet S. Chana
 * Last Edit:	March 12, 2017
 * Description:	Static class to handle any request
 *		for vision processing.
**/

#ifndef CV_PROCESSOR_H_
#define CV_PROCESSOR_H_

#include <cmath>
#include <vector>
#include "FaceData.h"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/objdetect.hpp"
#include "PassengerMap.h"

#define FACE_CASCADE_NAME "Data/haarcascade_frontalface_alt.xml"

class CVProcessor {
public:
	static void initialize();  // Setup all components for image capture
	static void update();  // Update all components of image capture process
	static std::vector<fd::FaceData> detectFaces();  // Find faces in CVProcessor::frame
	static std::vector<fd::FaceData> detectFaces(cv::Mat src);  // Find faces in src
	static bool compareFaces(fd::FaceData face1, fd::FaceData face2, int radius = -1);  // Determine similarty between two faces
	static cv::Mat *CVProcessor::getFrame();  // Return address to CVProcessor::frame

private:
	static cv::CascadeClassifier face_cascade;
	static cv::VideoCapture capture;
	static cv::Mat frame;
};

#endif  // CV_PROCESSOR_H_
