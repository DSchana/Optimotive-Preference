/*
 * Title:	    ProfileData.h
 * Author:	    Michael Ala, Roman Seviaryn
 * Created:	    April 2nd, 2017
 * Last Edit:	April 30th, 2017
 * Description:	The ProfileData class represents a database of preferences
 *				associated with a user. 
**/

#include <algorithm>
#include "ProfileData.h"

using namespace ctrl;
using namespace fd;
using namespace pd;
using namespace std;

ProfileData::ProfileData(FaceData fd)
{
	face = fd;
}

/*
 * Description: Returns the FaceData associated with this ProfileData.
 * Parameters:  None
 * Returns:		FaceData: The associated FaceData.
**/
FaceData ProfileData::getFaceData()
{
	return face;
}

/*
 * Description: Serializes this ProfileData object.
 * Parameters:  ofstream & - profile_bin: The binary file to write to.
 * Returns:		void
**/
void ProfileData::serialize(ofstream & profile_bin)
{
	// This is dependent on the Profile Data Serialization method.
	/*
	for (auto & controllable : controllables) {
		controllable.serialize(ofstream);
	}
	*/
}

/*
 * Description:     Return a piece of data from this ProfileData object. The data is  
 *				    usually a preference data associated to a controllable.
 * Template Params: class - T: The type of data to retrieve.
 * Parameters:	    string - controllable_name: The name of the controllable from which
 *				    to retrieve the data.
 *				    string - data_name: The name of the data to retrieve.
 * Returns:		    T*: A pointer to the data. If no data is found, the nullptr is returned.
**/
template <class T>
T * ProfileData::getData(string controllable_name, string data_name)
{
	auto it = find_if(controllables.begin(), controllables.end(), 
		[controllable_name] (Controllable const & c) { return c.getName() == controllable_name; } );
	if (!it)
		return nullptr;
	return it->getData<T>(data_name);
}
