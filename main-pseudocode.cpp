#include <vector>
#include <utility>

#include "CVProcessor.h";
#include "FaceData.h";
#include "PassengerMap.h";
#include "ProfileManager.h";
#include "SysConfig.h";
#include "VehicleInterface.h";

using namespace fd;
using namespace pm;
using namespace prf;
using namespace std;
using namespace vi;

int main(void)
{

	// Initialization
	// ==============

	sc::load();  // Load the configuration constants, used by all other utilities.

	CVProcessor::initialize();  // Initialize the video capture and anything computer vision related.

	VehicleInterface::activate();  // Activate the VehicleInterface. This sets the necessary pins to their
								   // required mode (input/output).

	PassengerMap::initialize();  // Initialize the PassengerMap based on the loaded Passenger objects.
	// NOTE: This assumes the "initialize" method is refactored to take no parameters.

	ProfileManager profileManager();  // Instantiate "global" profile manager instance.
	profileManager.initialize();  // Initialize the profile manager (currently does nothing).

	profileManager.load(); // Deserialize the profile data.
	profileManager.writeDeserialized();  // Write the previously deserialized profile data to the vehicle.

	// Feedback Loop
	// =============
	// |
	// | Initialization
	// -----------------
	bool running = true;
	vector<FaceData> detected_faces;

	// | Loop
	// ------
	while (running) 
	{
		VehicleInterface::update();

		CVProcessor::update();
		detected_faces = CVProcessor::detectFaces();

		PassengerMap::update(detected_faces);
		// Assumes the existence of such a method. Specified in task 17.

		for (auto it = PassengerMap::begin(); it != PassengerMap::end(); it++) 
		{
			it->getProfileData()->update(); // Reads new profile data from the vehicle.
			// Assumes the existence of such a method.

			bool new_face = it->compareLatestFace(); // Use CVProcessor
			// Assumes the existence of such a method.

			if (new_face)
			{
				Pair<ProfileData, bool> profile = profileManager.getProfile(it->latestFace());

				if (profile.second) // The bool is true if a profile was found.
				{
					it->setProfileData(profile.first);
					profile.first.writeToVehicle();
					// Assumes the existence of such a method.
				}
				else
				{
					ProfileData new_profile = profileManager.createProfile(it->latestFace());
					// Assumes the existence of such a method.
					it->setProfileData(new_profile);
					new_profile.writeToVehicle();
				}
			}
		}

		// Exit conditions?
	}


	// Exit Loop

	// What has to be implemented?
	// - void PassengerMap::initialize() (with no parameters)
	// - void ProfileManager::writeDeserialized()
	// - void PassengerMap::update(vector<FaceData>)
	// - void ProfileData::update()
	// - bool Passenger::compareLatestFace()
	// - Pair<ProfileData, bool> ProfileManager::getProfile(FaceData)
	// - void ProfileData::writeToVehicle()
	// - ProfileData ProfileManager::createProfile(FaceData)
	// - Add a "null face" and "neutral profile" to the ProfileManager in initialize.

	return 0;
}
