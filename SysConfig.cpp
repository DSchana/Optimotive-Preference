/*
 * Title: 		SysConfig.cpp
 * Authors: 	Michael F. Ala
 * Created:		March 12th, 2017
 * Last Edit: 	April 30th, 2017
 * Description: This contains implementations of SysConfig functions, 
 *			    which loads the system configurations from a file and
 *			    provides access for other utilities.
**/
#include <set>
#include "opencv2/core.hpp"
#include "SysConfig.h"

#define DEVICES_DECL "DEVICES"
#define V_OUTPUT_TYPE_MOTOR "MOTOR"
#define PASSENGER_DECL "PASSENGERS"
#define CONTROLLABLES_DECL_START "CONTROLLABLES"

using namespace ctrl;
using namespace cv;
using namespace pm;
using namespace std;
using namespace sc;

/*
 * Description: Determines if a given string is entirely whitespace.
 * Parameters:  String - text: The input to test.
 * Returns:     Boolean: True if the string is composed of only spaces, tabs, and 
 *				newlines, and false otherwise.
**/
bool _isws(string text) {
	return text.find_first_not_of("\t\n ") == npos;
}

/*
 * Description: Reads the lines of the system configuration file, as per specifications
 *				defined in the "System Configuration File Format" document. This will
 *				automatically ignore any lines without significant data.
 * Parameters:  ifstream & - config_file: A reference to the input file stream reading the system
 *				configuration file.
 * Returns:     List of Strings: The resulting list of (significant) lines.
**/
vector<string> _getSysConfigLines(ifstream & config_file) {
	vector<string> lines;
	string next_line;

	while (getline(config_file, next_line)) {
		if (next_line.empty() || 
			next_line[0] == '#' ||
			_isws(next_line)
			) {
			// Lines that start with a '#' character are completely ignored.
			// See "Optimotive\Technology\System Configuration File Format" for
			// more details.
			continue;
		}
		lines.push_back(next_line);
	}
	return lines;
}

/*
 * Description: Takes a line of input and tokenizes it by whitespace characters (i.e.
 *				breaks it up into a list of strings that are partitioned by whitespace).
 * Parameters:  String - line: The line of input to tokenize.
 * Returns:     List of Strings: The resulting list of tokens.
**/
vector<string> _tokenize(string line) {
	vector<string> output;
	tok = strtok(line, " \t");
	string next_token(tok);

	while (next_token != nullptr) {
		output.push_back(next_token);
		char* tok = strtok(NULL, " \t");
		next_token = string(tok);
	}
	return output;
}

/*
 * Description: Converts a token into a base 10 integer, checking first if the conversion
 *				can take place, and throwing an error if not.
 * Parameters:  String - token: The string to convert.
 * Returns:     Integer: The integer interpretation of the given string.
**/
int _tokenToInt(string token) {
	int b = token.begin(), e = token.end();
	if (token.empty() || find_if(b, e, [](char c) { return !isdigit(c); }) != e) {
		// Throw an appropriate error.
		return -1;
	}
	return stoi(token);
}

/*
 * Description: Converts a list of tokens into a Device object, or else throwing
 *				an error if the conversion can't take place.
 * Parameters:  List of Strings - tokens: The list of tokens to convert.
 * Returns:     Device: The Device interpretation of the given tokens.
**/
Device _tokensToDevice(vector<string> tokens) {
	// See "Optimotive\Technology\System Configuration File Format" for format details.
	Device result;

	result.readable_name = tokens[1];
	result.id            = tokens[2];
	int num_pins         = tokens[3];

	for (int i = 0; i < num_pins; i++) {
		// Should catch an error here.
		result.output_pins.push_back(tokens[4+i]);
	}
	return result;
}

/*
 * Description: Converts a list of tokens into a Controllable object, or else
 *				throwing an error if the conversion isn't possible.
 * Parameters:  List of Strings - tokens: The list of tokens to convert.
 * Returns:		Controllable: The Controllable interpretation of the given tokens.
**/
Controllable _tokensToControllable(vector<string> tokens) {
	if (tokens.size() < 3) {
		// Throw an appropriate error. The minimum number of tokens needed to specify a
		// Controllable object is 3.
	}

	Controllable result;
	result.setName(tokens[0]);
	result.setID(tokens[1]);
	int num_pins = _tokenToInt(tokens[2]);

	for (int i = 0; i < num_pins; i++) {
		// Should catch an error here.
		result.pushBackDeviceID(_tokenToInt(tokens[3+i]));
	}

	return result;
}

/*
 * Description: Converts a list of tokens into a Passenger object, or else throwing
 *				an error if the conversion can't take place.
 * Parameters:  List of Strings - tokens: The list of tokens to convert.
 * Returns:		Passenger: The Passenger interpretation of the given tokens.
**/
Passenger _tokensToPassenger(vector<string> tokens) {
	if (tokens.size() < 8) {
		// Throw an appropriate error. The minimum number of tokens needed to specify a Passegner
		// is 8.
	}

	Passenger result;
	result.setName(tokens[1]);
	int id = _tokenToInt(tokens[2]),
		x  = _tokenToInt(tokens[3]),
		y  = _tokenToInt(tokens[4]),
		w  = _tokenToInt(tokens[5]),
		h  = _tokenToInt(tokens[6]),
		num_outputs = _tokenToInt(tokens[7]);

	// result.id = id; See Task 36
	result.setRegion(Rect(x, y, w, h));

	for (int i = 0; i < num_pins; i++) {
		// Should catch an error here.
		// result.controllables.push_back(tokens[8+i]); See Task 37
	}

	return result;
}

/*
 * Description: Parses the Devices section of the System Configuration file in
 *				its entirety.
 * Parameters:  ifstream &	  		     - config_file:	A reference to the input file stream 
 *				reading the system configuration file.
 *				integer         		 - tokens:		The number of lines to parse.
 *				List of Strings Iterator - c_it:		An iterator representing the current
 *				line from the list of lines.
 * Returns:     void
**/
void _parseDevices(ifstream & config_file, int num_lines, vector<string>::const_iterator & c_it) {
	for (int i = 0; i < num_lines; i++) {
		c_it++;

		vector<string> tokenized_line = _tokenize(*c_it);
		if (tokenized_line.empty()) continue;  // see above

		string output_type = tokenized_line[0];
		if (output_type == VH_OUTPUT_TYPE_MOTOR) {
			Device output = _tokensToDevice(tokenized_line);

			_vehicleOutputs.push_back(output);
		}
		else {
			// Throw an appropriate exception.
			continue; // for now
		}
	}
}

/*
 * Description: Parse the Controllables section of the System Configuration file in its entirety.
 * Parameters:	ifstream &	  		     - config_file:	A reference to the input file stream 
 *				reading the system configuration file.
 *				integer         		 - tokens:		The number of lines to parse.
 *				List of Strings Iterator - c_it:		An iterator representing the current
 *				line from the list of lines.
 * Returns:     void
**/
void _parseControllables(ifstream & config_file, int num_lines, vector<string>::const_iterator & c_it) {
	for (int i = 0; i < num_lines; i++) {
		c_it++;

		vector<string> tokenized_lien = _tokenize(*c_it);
		if (tokenized_line.empty()) continue;

		Controllable output = _tokensToControllable(tokenized_line);
		_controllables.push_back(output);
	}
}

/*
 * Description: Parses the Passengers section of the System Configuration file in
 *				its entirety.
 * Parameters:  ifstream &	  		     - config_file:	A reference to the input file stream 
 *				reading the system configuration file.
 *				integer         		 - tokens:		The number of lines to parse.
 *				List of Strings Iterator - c_it:		An iterator representing the current
 *				line from the list of lines.
 * Returns:		void
**/
void _parsePassengers(ifstream & config_file, int num_lines, vector<string>::const_iterator & c_it) {
	for (int i = 0; i < num_lines; i++) {
		c_it++;

		vector<string> tokenized_line = _tokenize(*c_it);
		if (tokenized_line.empty()) continue;

		Passenger output = _tokensToPassenger(tokenized_line);
		_passengers.push_back(output);
	}
}

/*
 * Description: Load the System Configuration file. 
 * Parameters:  None
 * Returns:     void
**/
void load() {

	ifstream config_file (SYSCONFIG_FNAME);

	if (config_file.is_open()) {

		vector<string> lines = _getSysConfigLines(config_file);

		for (vector<string>::const_iterator c_it = lines.cbegin() ; c_it != lines.end(); c_it++) {
			vector<string> tokenized_line = _tokenize(*c_it);
			if (tokenized_line.empty()) {
				// This shouldn't occur since an empty token list would imply that the string
				// was completely whitespace, which, assuming _isws works, would get skipped
				// in _getLines.
				//
				// That said, you can never be too safe.
				continue;
			}
			string first_token = tokenized_line[0];

			if (first_token == DEVICES_DECL) {
				if (tokenized_line.size() != 2) {
					// Throw an appropriate error. For now ignore.
				}
				int num_output_lines = _tokenToInt(tokenized_line[1]);
				_parseVehicleOutputs(config_file, num_output_lines, c_it);
			} else if (first_token == PASSENGERS_DECL) {
				if (tokenized_line.size() != 2) {
					// Throw an appropriate error. For now ignore.
				}
				int num_passenger_lines = _tokenToInt(tokenized_line[1]);
				_parsePassengers(config_file, num_passenger_lines, c_it);
			} else if (first_token == CONTROLLABLES_DECL) { 
				if (tokenized_line.size() != 2) {
					// Throw an appropriate error. For now ignore.
				}
				int num_controllable_lines = _tokenToInt(tokenized_line[1]);
				_parseControllables(config_file, num_controllable_lines, c_it);
			} else {
				// Throw an appropriate error.
			}
		}
		config_file.close();
		_isLoaded = true;
	}
	else {
		// Throw an appropriate error.
	}
}

// Check that the loaded data is consistent. 
void _postParseCheck() { } // Stub for now.

/*
 * Description: Returns the list of Device objects read from the
 *				System Configuration file. This will throw an error if
 *				the System Configuration file hasn't been loaded yet.
 * Parameters:  None
 * Returns:     List of Devices: The list of parsed Devices.
**/
vector<Device> getDevices() {
	if (!_isLoaded) {
		// Throw an appropriate error.
	}
	return _vehicleOutputs;
}

/*
 * Description: Returns the list of Passenger objects read from the
 *				System Configuration file. This will throw an error if
 *				the System Configuration file hasn't been loaded yet.
 * Parameters:  None
 * Returns:		List of Passengers: The list of parsed Passengers.
**/
vector<Passenger> getPassengers() {
	if (!_isLoaded) {
		// Throw an appropriate error.
	}
	return _passegners;
}

/*
 * Description: Returns the list of Controllable objects read from the
 *				System Configuration file. This will throw an error if
 *				the System Configuration file hasn't been loaded yet.
 * Parameters:	None
 * Returns:		List of Controllables: The list of parsed Controllables.
**/
vector<Controllable> getControllables() {
	if (!_isLoaded) {
		// Throw an appropriate error.
	}
	return _controllables;
}