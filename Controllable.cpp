/*
 * Title: 		Controllable.cpp
 * Authors: 	Michael F. Ala
 * Created:		April 30th, 2017
 * Last Edit: 	April 30th, 2017
 * Description: This is the header for the abstract Controllable class.
**/
#include "Controllable.h"

using namespace ctrl;
using namespace std;

/*
 * Description: Return the "human-readable" name of this Controllable.
 * Parameters:  None
 * Returns:		string: This Controllable's name.
**/
string Controllable::getName() { return name; }
/*
 * Description: Set the "human-readable" name of this Controllable.
 * Parameters:	string - new_name: The given name.
 * Returns:		void
**/
void Controllable::setName(string new_name) { name = new_name; }

/*
 * Description:	Return the ControllableID.
 * Parameters:	None
 * Returns:		int: This Controllable's ID.
**/
int Controllable::getID() { return id; }
/*
 * Description:	Set the ID of this Controllable. This will throw an exception if the ID has
 *				already been set.
 * Parameters:  int - new_id: The given id.
 * Returns:		void
**/
void Controllable::setID(int new_id) 
{ 
	if (_id_set)
	{
		// throw an appropriate exception. For now ignore.
	}
	id = new_id; 
}

/*
 * Description: Get the list of DeviceIDs this Controllable manages.
 * Parameters:	None
 * Returns:		List of ints: the list of DeviceIDs.
**/
set<int> Controllable::getDeviceIDs() { return devices; }
/*
 * Description: Add a new DeviceID for this Controllable to manage.
 * Parameters:	int - device: The DeviceID to add.
 * Returns:		Pair of set<int> iterator and bool: the result of set<int>::insert.
**/
pair<set<int>::iterator, bool> Controllable::pushBackDeviceID(int device) { devices.insert(device); }

/*
 * Description: Check if this Controllable is managing a given ID.
 * Parameters:	int - id: The DeviceID to check.
 * Returns:		bool: True if this Controllable is managing a device with the given ID, and
 *					  false if not.
**/
bool Controllable::hasDeviceID(int id) 
{
	return devices.count(id) > 0;
}

/*
 * Description: Perform arbitrary processing on this Controllable object. This method is
 *				empty in the base Controllable class, and is meant to be overridden with
 *				subclass-specific implementations.
 * Parameters:  int - process_type: An arbitrary id indicating what this call to "update" is meant to do.
 				What exactly each integer value does is subclass implementation specific.
 *				var args: Variable, arbitrary type arguments, for arbitrary use by the method.
 * Returns:		void
**/
virtual void Controllable::update(int process_type, ... ) { }

/*
 * Description:     Return a pointer to a piece of data this Controllable has access to, such as
 *				    a preference setting.
 * Template Params: class - T: The type of data to retrieve.
 * Parameters:		string - data_name: The name of the data to retreive. This does not refer to anything
 *					generally; what a given data_name returns is implementation specific.
 * Returns:			T*: pointer to the data. We return a pointer so that, in the case that we can't retreive
 *					data of the given type or can't find data with the given name, we simply return nullptr.
**/
template <class T>
virtual T * getData(string data_name) 
{
	return nullptr;
}