/*
 * Title:	FaceData.h
 * Author:	Dilpreet S. Chana
 * Created:	December 15, 2016
 * Last Edit:	May 5, 2017
 * Description:	The FaceData class contains the various
 *		metrics and features that the facial
 *		recognition looks for to identify a
 *		new face.
**/

#ifndef FACE_DATA_H
#define FACE_DATA_H

#include "opencv2/core.hpp"

namespace fd {
	class FaceData {
		private:
			cv::Scalar colour;  // The average colour of detected face in BGR colour space
			cv::Point centre;   // The location of the detected face
			int section;	    // The region id the face is located in

		public:
			FaceData();
			FaceData(cv::Scalar n_colour, cv::Point n_centre, int n_id);
			~FaceData();

			cv::Scalar getColour();
			cv::Point getCentre();
			int getSection();

			void setCentre(cv::Point n_centre);
			void setSection(int n_id);
	};
} 

#endif
