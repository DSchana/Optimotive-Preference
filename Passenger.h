/*
 * Title:	Passenger.h
 * Author:	Dilpreet S. Chana, Michael Ala
 * Created:	March 12, 2017
 * Last Edit:	March 30, 2017
 * Description:	The Passenger class represents a template
 *		for each possible passenger in the vehicle.
 *		The data for each passenger is loaded from
 *		SysConfig
**/

#ifndef PASSENGER_H_
#define PASSENGER_H_

#include <deque>
#include <string>
#include "FaceData.h"
#include "opencv2/core.hpp"
#include "ProfileData.h"

#define MAX_MEMORY 4  // TODO: fix number by testing

namespace pm {
	class Passenger {
	public:
		Passenger();

		void remember(fd::FaceData n_face_data);
		void setProfileData(prf::ProfileData *n_profile_data);
		void setName(std::string n_name);
		void setRegion(cv::Rect n_region);

		fd::FaceData *getRecent();
		prf::ProfileData *getProfileData();
		std::string getName();
		cv::Rect getRegion();
		std::vector<ctrl::Controllable> *getControllables();
		int getID();

	private:
		std::deque<fd::FaceData> face_memory;
		prf::ProfileData *profile_data;
		std::string readable_name;
		cv::Rect region;
		std::vector<ctrl::Controllable> controllables;
		int id;
	};
}

#endif  // PASSENGER_H_
