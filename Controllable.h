/*
 * Title: 		Controllable.h
 * Authors: 	Michael F. Ala
 * Created:		April 29th, 2017
 * Last Edit: 	April 30th, 2017
 * Description: This is the header for the abstract Controllable class.
**/
#ifndef CONTROLLABLE_H_
#define CONTROLLABLE_H_

#include <fstream>
#include <set>
#include <utility>

namespace ctrl {

	class Controllable {
	public:

		// Note: The following method declarations are grouped and listed in the order
		// they're called in. For example, when we need to store ProfileData, we call
		// "readFromVehicle" and then "serialize", whereas if we need to load ProfileData,
		// we call "deserialize" and then "writeToVehicle".

		// Read this Controllable's information from the vehicle.
		virtual void readFromVehicle() = 0;
		// Serialize this Controllable to a binary file.
		virtual void serialize(std::ofstream & profile_bin) = 0;

		// Deserialize this Controllable from a binary file.
		virtual void deserialize(std::ifstream & profile_bin) = 0;
		// Write this Controllable's information to the vehicle.
		virtual void writeToVehicle()  = 0;

		// Perform arbitrary processing on this Controllable. The implementation of this method
		// is specific to the given Controllable.
		virtual void update(int process_type, ... );

		// Return a pointer to a piece of data this Controllable manages (most likely a preference setting).
		template <class T>
		virtual T * getData(std::string data_name);

		// Getter and setter for the name property.
		string getName();
		void   setName(std::string name);

		// Getter and setter for the ID property.
		int  getID();
		void setID(int id);

		// Getter and setter for the device ID property.
		std::set<int> getDeviceIDs();
		std::pair<std::set<int>::iterator, bool> pushBackDeviceID(int deviceID);

		// Check if this Controllable has a given DeviceID.
		bool hasDeviceID(int id);

	private:
		std::string name;		// "Human-Readable" name for this Controllable (for debugging).
		int id;					// ControllableID (referenced by Passenger).
		std::set<int> devices;	// The list of devices (DeviceIDs) this Controllable contains.
	};
}

#endif