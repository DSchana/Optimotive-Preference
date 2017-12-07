#include "FaceDetector.h"

using namespace std;
using namespace cv;

Mat FaceDetector::frame;
VideoCapture FaceDetector::capture;
vector<cv::Rect> FaceDetector::faces;
Rect FaceDetector::main_face;
Scalar FaceDetector::main_face_col;
int FaceDetector::main_id;

string FaceDetector::face_cascade_name;
CascadeClassifier FaceDetector::face_cascade;
int FaceDetector::low_canny_thresh;
int FaceDetector::canny_ratio;

void FaceDetector::initialize() {
	main_id = 0;
	low_canny_thresh = 45;
        canny_ratio = 3;
	face_cascade_name = "Data/haarcascade_frontalface_alt.xml";

        capture = VideoCapture(0);

        if (!capture.isOpened()) {
                printf("Error when opening camera\n");
                terminate();
        }

        // Set resolution
        capture.set(CV_CAP_PROP_FRAME_WIDTH, R_WIDTH);
        capture.set(CV_CAP_PROP_FRAME_HEIGHT, R_HEIGHT);

        // Load the cascades
        if (!face_cascade.load(face_cascade_name)) {
                printf("Error loading face cascade\n");
                terminate();
        }
}

void FaceDetector::detectFace() {
        capture >> frame;

	Mat frame_gray;

        cvtColor(frame, frame_gray, CV_BGR2GRAY);
        equalizeHist(frame_gray, frame_gray);

        main_face = Rect(0, 0, 0, 0);  // hold the main face to be recognized

        // Detect faces using the cascade
        face_cascade.detectMultiScale(frame_gray, faces, 1.1, 2, 0 | CV_HAAR_SCALE_IMAGE, Size(80, 80));

        for (size_t i = 0; i < faces.size(); i++) {
                if (faces[i].width * faces[i].height > main_face.width * main_face.height) {
                        main_face.x = faces[i].x;
                        main_face.y = faces[i].y;
                        main_face.width = faces[i].width;
                        main_face.height = faces[i].height;
                }

                rectangle(frame, Point(faces[i].x, faces[i].y), Point(faces[i].x + faces[i].width, faces[i].y + faces[i].height), Scalar(229, 181, 51), 4);
        }

        main_face_col = mean(frame(main_face));

        circle(frame, Point(main_face.x + main_face.width / 2, main_face.y + main_face.height / 2), 4, main_face_col, 4);
        rectangle(frame, main_face, main_face_col, 5);  // Indicate main face

        idUser();
}

void FaceDetector::makeMesh(cv::Rect loc) {

}

void FaceDetector::terminate() {
        printf("Cleaning up CV stuff\n");
        destroyAllWindows();
        capture.release();
        exit(EXIT_SUCCESS);
}

void FaceDetector::idUser() {
        int face_count = faces.size();

        if (face_count == 0) {
                main_id = 0;
		return;
        }

	Scalar diff_black = main_face_col - Scalar(33, 48, 94);
        Scalar diff_white = Scalar(196, 229, 240) - main_face_col;
        //cout << diff_black << "\t" << diff_white << endl;

        double v_b = sqrt(pow(diff_black[0], 2) + pow(diff_black[1], 2) + pow(diff_black[2], 2));
        double v_w = sqrt(pow(diff_white[0], 2) + pow(diff_white[1], 2) + pow(diff_white[2], 2));

        if (v_w > v_b) {
                // id 1, me. or any other brown fella
                main_id = 1;
        }
        else {
                // id 2, roman. or another privileged fella
                main_id = 2;
        }
}

void FaceDetector::showUserId() {
        if (main_id == 0) {
                putText(frame, "No User Detected", Point(10, 50), 5, 3, Scalar(255, 255, 255), 2);
        }
        else {
                stringstream ss;
                ss << "User " << main_id << " Detected";
                putText(frame, ss.str(), Point(10, 50), 5, 3, Scalar(255, 255, 255), 2);
        }
}

void FaceDetector::printUserId() {
	if (main_id == 0) {
		printf("No user found\n");
	}
	else {
		printf("User %d detected\n", main_id);
	}
}

Rect FaceDetector::getMainFace() {
        return main_face;
}

int FaceDetector::getMainID() {
        return main_id;
}
