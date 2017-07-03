/*
 * Title: 		ProfileManager.h
 * Authors: 	Michael F. Ala, Roman Seviaryn
 * Created:		April 30th, 2017
 * Last Edit:   April 30th, 2017
 * Description: The ProfileManager stores, serializes, and deserializes ProfileData objects. It is
 *				accessed in main.cpp; for each Passenger in the PassengerMap, if the Passenger has
 *				new FaceData, then we check the ProfileManager for the ProfileData associated to
 *				said FaceData. From here there are two paths
 *
 *				Case 1: The ProfileManager has a ProfileData associated to the given FaceData.
 *					In this case, the ProfileManager returns the ProfileData, and the ProfileData's info 
 *					is written to the vehicle.
 *
 *				Case 2: The ProfileManager doesn't have a ProfileData associated to the given FaceData.
 *					In this case, a new ProfileData object is created, added to the ProfileManager, and
 *					returned.
**/
#include <fstream>
#include "FaceData.h"
#include "ProfileData.h"
#include "ProfileManager.h"

using namespace fd;
using namespace pd;
using namespace prf;
using namespace std;

/* Description: Initialize the ProfileManager.
 * Parameters:  None
 * Returns:		void
**/
void ProfileManager::initialize() {

}

/* Description: Load the ProfileData from the binary file.
 * Parameters: 	None
 * Returns:		void
**/
void ProfileManager::load() {
	// Implementation depends on Profile Data Serialization method.
}

/* Description: Deserialize the ProfileData objects upon exit of the program.
 * Parameters:  None
 * Returns:		void
**/
void ProfileManager::exit() {
	ofstream profile_bin (PROFILE_DATA_FNAME);
	for (auto & pair : _profiles) {
		pair.second.serialize(profile_bin);
	}
	profile_bin.close();
}

/*
 * Description: Returns the ProfileData associated to a given FaceData.
 * Parameters:	FaceData - f: The FaceData to index the profiles dictionary with.
 * Returns:		ProfileData: The ProfileData associated with this FaceData (if it exists).
 *				If no such ProfileData exists, an error is thrown.
**/
ProfileData ProfileManager::getProfile(FaceData f) {
	return _profiles.at(f);
}