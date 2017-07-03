/*
 * Title:	Passenger.cpp
 * Author:	Dilpreet S. Chana
 * Created:	March 12, 2017
 * Last Edit:	March 30, 2017
 * Description: Implementation of Passenger class
**/

#include "Passenger.h"

using namespace std;
using namespace pm;

/*
 * Description:	Constructor for Passenger
 * Parameters:	void
 * Returns:	void
**/
Passenger::Passenger() {
	face_memory = deque<FaceData>();
	controllables = sc::getControllables();
	profile_data = NULL;
}

/*
 * Description:	Add new instance of passenger's
 *		face to the list of faces	
 * Parameters:	FaceData - n_face_data: data of
 *		new face instance
 * Returns:	void
**/
void remember(FaceData n_face_data) {
	face_memory.push_front(n_face_data);

	if (face_memory.size() > MAX_MEMORY) {
		face_memory.pop_back();
	}
}

/*
 * Description: Assign new Profile to this passenger
 * Parameters:	Pointer to new ProfileData
 * Returns:	void
**/
void setProfileData(ProfileData *n_profile_data) {
	profile_data = n_profile_data;
}

/*
 * Description: Assign a readable name to this passanger
 * Parameters:  string - n_name: new name of this passanger
 * Returns:     void
**/
void setName(string n_name) {
	readable_name = n_name;
}

/*
 * Description:	Set the region of this passenger
 * Parameters:	New region of passenger
 * Returns:	void
**/
void setRegion(Rect n_region) {
	region = n_region;
}

/*
 * Description:	Get the most recent remembered face
 *		of this passenger
 * Parameters:	void
 * Returns:	Pointer to most recent remembered face
**/
FaceData *getRecent() {
	return face_memory.size() > 0 ? &face_memory[0] : NULL;
}

/*
 * Description:	Get the profile assigned to this passenger
 * Parameters:	void
 * Returns:	Pointer to this passenger's ProfileData
**/
ProfileData *getProfileData() {
	return profile_data;
}

/*
 * Description:	Get the readable name of this passanger
 * Parameters:	void
 * Returns:	Readable name of this passanger
**/
string getName() {
	return readable_name;
}

/*
 * Description:	Get the current region this passanger
 *		is found in.
 * Parameters:	void
 * Returns:	Current region this passanger is in
**/
Rect getRegion() {
	return region;
}

int getID() {
	return id;
}

/*
 * Description:	Get the list of controllable items for
 *		this passenger location.
 * Parameters:	void
 * Returns:	Address of the lost of controllable
 *		items for this passenger location.
**/
vector<ctrl::Controllable> *getControllables() {
	return &controllables;
}
