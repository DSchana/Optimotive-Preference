/*
 * Title:	FaceData.cpp
 * Author:	Dilpreet S. Chana
 * Created:	December 15, 2017
 * Last Edit:	May 5, 2017
 * Description:	Implementation of FaceData class
**/

#include "FaceData.h"

using namespace fd;

FaceData::FaceData() {
	colour = Scalar(0, 0, 0);
	centre = Point(0, 0);
	region_id = -1;
}

FaceData::FaceData(Scalar n_colour, Point n_centre, int n_id) {
	colour = n_colour;
	centre = n_centre;
	region_id = n_id;
}

FaceData::~FaceData() {
}

Scalar FaceData::getColour() {
	return colour;
}

Point FaceData::getCentre() {
	return centre;
}

int FaceData::getRegionID() {
	return region_id;
}

void FaceData::setCentre(Point n_centre) {
	centre = n_centre;
}

void FaceData::setRegionID(int n_id) {
	region_id = id;
}
