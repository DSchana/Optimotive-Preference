/*
 * Title:	    ProfileData.h
 * Author:	    Michael Ala, Roman Seviaryn
 * Created:	    April 14th, 2017
 * Last Edit:	April 30th, 2017
 * Description:	The ProfileData class represents a database of preferences
 *				associated with a user. 
**/

#ifndef PROFILES_H
#define PROFILES_H

#include <fstream>
#include <set>
#include <utility>
#include "Controllable.h"
#include "FaceData.h"

namespace pd
{
	/*
	 * Description: ProfileData objects represents the Profile associated with a vehicle user, and records
	 *				all preferences for this user.
	**/
	class ProfileData
	{
	private:
		fd::FaceData face;						 	// The face associated with this profile.
		std::set<ctrl::Controllable> controllables; // The list of controllables this ProfileData is recording.

	public:
		ProfileData(fd::FaceData fd);

		// Return this ProfileData's associated FaceData.
		FaceData getFaceData();

		// Serialize this ProfileData in a binary file.
		void serialize(std::ofstream & profile_bin);

		// Push a Controllable object to be recorded in this ProfileData.
		std::pair<std::set<ctrl::Controllable>::int, bool> pushControllable(ctrl::Controllable);

		// Get a piece of data from thsi profile.
		template <class T>
		T * getData(std::string controllable_name, std::string data_name);
	};
}

#endif
