/*
 * Title:	PassengerMap.h
 * Author:	Dilpreet S. Chana, Michael Ala
 * Created:	March 12, 2017
 * Last Edit:	March 30, 2017
 * Description: A static class mapping people to
 *		a place in the vehicle. This allows
 *		the program to know what settings
 *		to change for each user.
**/

#ifndef PASSENGER_MAP_H_
#define PASSENGER_MAP_H_

#include <stack>
#include <vector>
#include "opencv2/core.hpp"
#include "Passenger.h"
#include "FaceData.h"
#include "CVProcessor.h"

namespace pm {
	class PassengerMap {
	public:
		static void initialize(int num_passengers);
		static void update(std::vector<fd::FaceData> detected_faces);
		static Passenger *getPassenger(int id);
		static Passenger *getPassenger(cv::Rect region);
		static std::vector<Passenger>::iterator begin();
		static std::vector<Passenger>::iterator end();

	private:
		static std::vector<Passenger> passengers;
	};
}

#endif  // PASSENGER_MAP_H_
