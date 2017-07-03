/*
 * Title: 		ProfileManager.h
 * Authors: 	Michael F. Ala, Roman Seviaryn
 * Created:		April 2nd, 2017
 * Last Edit:   April 30th, 2017
 * Description: This is the header for ProfileManager, a class which serializes and
 *				deserializes ProfileData, compares the detected face data against
 *				the known face data, and sends associated data to the VehicleInterface.
**/

#ifndef PROFILE_MANAGER_H
#define PROFILE_MANAGER_H

#define PROFILE_DATA_FNAME "profiles.bin"

#include <map>
#include "CVManipulator.h"
#include "FaceData.h"
#include "ProfileData.h"

namespace prf
{
	/*
	 * Description: The ProfileManager class hosts all loaded ProfileData objects, for access by
	 *				associated FaceData objects. It also handles serialization and deserialization.
	**/
	class ProfileManager
	{
	private:
		ProfileManager();

		std::map<fd::FaceData, prf::ProfileData> _profiles;
		// The _profiles dictionary is updated throughout the lifetime of the program.
		//
		// When load() is called, _profiles is populated with the previously known FaceData and ProfileData
		// objects. When a user 

	public:
		void initialize(); // Initialize the ProfileManager.
		void load();	   // Load the previously known ProfileData objects.
		void exit();	   // Write the known ProfileData objects.

		pd::ProfileData getProfile(fd::FaceData);
	};
}

#endif
