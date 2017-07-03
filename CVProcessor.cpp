/*
 * Title:	CVProcessor.cpp
 * Author:	Dilpreet S. Chana
 * Last Edit:	March 12, 2017
 * Description:	Implemtation of CVProccesor class
**/

#include "CVProcessor.h"

using namespace fd;
using namespace std;

// Define static variables
CascadeClassifier CVProcessor::face_cascade;
VideoCapture CVProcessor::capture;
Mat CVProcessor::frame;

/*
 * Description:	Setup all components for image capture
 *		and load the haar cascade files
 * Parameters:	void
 * Returns:	void
**/
void CVProcessor::initialize() {
	capture.open(0);
	if (!capture.isOpened())
	{
		printf("Error opening camera\n");
		// throw error
	}

	// Set resolution
	capture.set(CV_CAP_PROP_FRAME_WIDTH, 640);
	capture.set(CV_CAP_PROP_FRAME_HEIGHT, 480);

	face_cascade.load(FACE_CASCADE_NAME);
}

/*
 * Description:	Retreive next frame from camera
 * Parameters:	void
 * Returns:	void
**/
void CVProcessor::update() {
	if (!capture.isOpened()) {
		printf("Camera lost...\n");
		// Throw error maybe. Or perhaps try to find again

		break;
	}
	capture >> frame;
}

/*
 * Description:	Find all faces inside frame
 * Parameters:	void
 * Returns:	list of faces found in frame
**/
vector<FaceData> CVProcessor::detectFaces() {
	return detectFaces(frame);
}

/*
 * Description:	Find all faces inside src
 * Parameters:	Matrix - src: Matrix in which to search for faces
 * Returns:	list of faces found in src
**/
vector<FaceData> CVProcessor::detectFaces(Mat src) {
	vector<Rect> faces;
	vector<FaceData> faces_data;
	Mat frame_gray;

	cvtColor(src, frame_gray, CV_BGR2GRAY);
	equalizeHist(frame_gray, frame_gray);

	// Detect faces using the cascade
	face_cascade.detectMultiScale(frame_gray, faces, 1.1, 2, 0 | CV_HAAR_SCALE_IMAGE, Size(80, 80));

	for (size_t i = 0; i < faces.size(); i++) {
		Point centre(faces[i].x + faces[i].width / 2, faces[i].y + faces[i].height / 2);
		faces_data.push_back(FaceData(mean(src(faces[i])), centre, -1));  // section -1 by default. Must be set by Quad Dic
	}

	// TODO: Filter faces such that at most one face (the biggest face) is detected per region

	return faces_data;
}

/*
 * Description:	Determine whether two faces match one another as one face
 * Parameters:	FaceData - face1:  first face
 *		FaceData - face2:  second face
 *		Integer  - radius: minimum distance face1 and face2 can be
 *			   from each other
 * Returns:	Boolean: true if faces match
 *			 false if not
**/
bool CVProcessor::compareFaces(FaceData face1, FaceData face2, int radius) {
	// TODO: This algorithm is only theoretical and will only be usful after testing
	// True if the face properties are deemed equal enough
	bool colour 	 = false,
	     location    = false,
	     dic_section = false;

	// Check location
	if (radius == -1) {
		location = true;
	}
	else {
		if (sqrt(
			pow(face1.getCentre().x - face2.getCentre().y, 2) + 
			pow(face1.getCentre().y - face2.getCentre().y, 2)) < radius) {  // radius px margin of error
			location = true;
		}
	}

	// Check section
	if (face1.getSection() == face2.getSection()) {
		dic_section = true;
	}

	// Check colour
	// Algorithm reference: https://en.wikipedia.org/wiki/Color_difference
	Scalar hsv_colour_1, hsv_colour_2, lab_colour_1, lab_colour_2;

	// Convert RGB to HSV and LAB colour space
	cvtColor(face1.getColour(), hsv_colour_1, CV_BGR2HSV);
	cvtColor(face2.getColour(), hsv_colour_2, CV_BGR2HSV);
	cvtColor(face1.getColour(), lab_colour_1, CV_BGR2Lab);
	cvtColor(face2.getColour(), lab_colour_2, CV_BGR2Lab);

	// TODO: consider updating to CIEDE2000 colour diff algorithm
	// Declare delta LAB and LCH colour space values
	double delta_E;  // Colour difference
	double c1, c2;   // LCH colour space C value for face 1 and 2
	double delta_L;  // LAB/LCH colour space delta L value
	double delta_C;  // LCH colour space delta C value
	double delta_H;  // LCH colour space delta H value

	// Manual calculations and conversions for previously declared variables
	c1 = sqrt(pow(lab_colour_1[1], 2) + pow(lab_colour_1[2], 2));
	c2 = sqrt(pow(lab_colour_2[1], 2) + pow(lab_colour_2[2], 2));
	delta_C = c1 - c2;

	delta_L = lab_colour_1[0] - lab_colour_2[0];

	delta_H = sqrt(
		pow(lab_colour_1[1] - lab_colour_2[1], 2) + 
		pow(lab_colour_1[2] - lab_colour_2[2], 2) - 
		pow(delta_C, 2));

	delta_E = sqrt(
		pow(delta_L, 2) + 
		pow(delta_C / (1 + 0.045 * c1), 2) + 
		pow(delta_H / (1 + 0.015 * c1), 2));

	if (delta_E < 50) {  // TODO: This value needs testing
		colour = true;
	}

	if (colour && location && dic_section) {
		return true;
	}

	return false;
}

/*
 * Description:	Give access to address of frame
 * Parameters:	void
 * Returns:	Address to matrix - frame
**/
Mat *CVProcessor::getFrame() {
	return &frame;
}
