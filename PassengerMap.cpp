/*
 * Title:	PassengerMap.cpp
 * Author:	Dilpreet S. Chana
 * Created:	March 12, 2017
 * Last Edit:	March 30, 2017
 * Description: Implementation of PassengerMap class
**/

#include "PassengerMap.h"

using namespace std;
using namespace pm;
using namespace fd;

// Define static variables
vector<Passenger> PassengerMap::passengers;
int PassengerMap::id;

void PassengerMap::initialize() {
	passengers = sc::getPassengers();
}

/*
 * Description:	Update the passengers with the newly
 *		received list of faces
 * Parameters:	vector of FaceData - detected_faces:
 *		the list of newly detected faces
 * Returns:	void
**/
void PassengerMap::update(vector<FaceData> detected_faces) {
	// ASSUME: The faces are filtered from CVProcessor such
	//	   that at most one face per region is returned

	for (int i = 0; i < detected_faces.size(); i++) {
		for (int j = 0; j < passengers.size(); j++) {
			if (detected_faces[i].getSection() == passengers[j].getID()) {
				passengers[j].remember(detected_faces[i]);
				break;
			}
		}
	}
}

/*
 * Description: Get address of specified passenger
 * Parameters:	Integer - id: id of passenger to get
 * Returns:	Address of passenger at id if it
 *		exists. NULL pointer if id DNE
**/
Passenger *PassengerMap::getPassenger(int id) {
	for (int i = 0; i < passengers.size(); i++) {
		if (passengers[i].id == id) {
			return &passengers[i];
		}
	}

	return NULL;
}

/*
 * Description:	Get passenger within a region
 * Parameters:	Rect - region: region to search
 *		for passenger in
 * Returns:	Passenger in region if found
 *		NullPtr if not
**/
Passenger *PassengerMap::getPassenger(Rect region) {
	for (int i = 0; i < passengers.size(); i++) {
		if (passenger[i].region == region) {
			return &passenger[i];
		}
	}

	return NULL;
}

/*
 * Description:	Get iterator to the beginning of
 *		the list of passengers
 * Parameters:	void
 * Returns:	Iterator to the beginning of the
 *		list of passengers
**/
vector<Passenger>::iterator PassengerMap::begin() {
	return passengers.begin();
}

/*
 * Description: Get iterator to the end
 *              the list of passengers
 * Parameters:  void
 * Returns:     Iterator to the end of the
 *              list of passengers
**/
vector<Passenger>::iterator PassengerMap::end() {
	return passengers.end();
}
