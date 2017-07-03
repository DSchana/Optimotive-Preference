/*
 * Title: 		SysConfig.h
 * Authors: 	Michael F. Ala
 * Created:		March 12th, 2017
 * Last Edit:   April 30th, 2017
 * Description: This is the header for SysConfig, a namespace which provides
 *			    functionality for dealing with system-wide constants, which
 *			    the entire codebase requires access to.
**/
#ifndef SYSCONFIG_H_
#define SYSCONFIG_H_

#define SYSCONFIG_FNAME "config.txt"

#include <cstring>
#include <fstream>
#include <string>
#include <vector>
#include "Controllable.h"
#include "Passenger.h"

namespace sc {

	/* 
 	 * Description: Represents an arbitrary vehicle device as a list of its pins.
 	 * Fields:      int id:                  The ID which refers to this output.
 	 *				string readable_name:    A human-readable identifier for this output (for debugging).
 	 *				vector<int> output_pins: A list of the output pins this output is connected to.
	**/
	struct Device {
		int id;
		std::string readable_name;
		vector<int> output_pins;
		/* Pretty much all devices are binary devices, which have the corresponding pins:
		 *
		 * 0 - Increment positive (away from neutral).
		 * 1 - Increment negative (towards neutral).
		 * 2, 3 - Neutral position limit switch.
		 * 4, 5, ... - Encoder.
		 *
		 * As for more complicated devices, such as radios and heating units, we need to ask
		 * Faurecia for more details, and may have to implement different Device objects or
		 * presets.
		**/

		/*
		 * Description: A list of pin values corresponding to the above assumptions.
		 * WARNING: These pin values are only a SUGGESTED PRACTICE, there is no way of enforcing,
		 *			for example, the 5th through 8th pins to be dedicated to the encoder. It is up
		 *			to the discretion of the engineer to determine if the pins correspond to their
		 *			associated purposes listed here.
		**/
		enum MotorPinPresets {
			INCREMENT_POSITIVE = 0,
			INCREMENT_NEGATIVE = 1,
			NEUTRAL_POSITION_LIMIT_SWITCH_LO = 2,
			NEUTRAL_POSITION_LIMIT_SWITCH_HI = 3,
			ENCODER_0 = 4,
			ENCODER_1 = 5,
			ENCODER_2 = 6,
			ENCODER_3 = 7
		};
	 };

	// "Private" Namespace Members
	// ===========================

	std::vector<Device> _vehicleOutputs;
	std::vector<pm::Passenger> _passengers;
	std::vector<ctrl::Controllable> _controllables;
	bool _isLoaded = false;

	// General Parsing Utilities
	std::vector<std::string> _getSysConfigLines(std::ifstream & config_file); // Turn the system configuration stream into a list of relevant lines.

	// General Tokenization Functions
	std::vector<std::string> _tokenize(std::string line); // Tokenize a string of input.
	int _tokenToInt(std::string token); // Convert a token to an integer.

	// "Important" Tokenization Functions
	Device             _tokensToDevice      (std::vector<std::string> tokens); // Convert a list of tokens into a Device object.
	pm::Passenger      _tokensToPassenger   (std::vector<std::string> tokens); // Convert a list of tokens into a Passenger object.
	ctrl::Controllable _tokensToControllable(std::vector<std::string> tokens); // Convert a list of tokens into a Controllable object.

	// Section Parsers

	// Parse the Devices from the configuration file.
	void _parseDevices      (std::ifstream & config_file, int num_lines, std::vector<std::string>::const_iterator & c_it);
	// Parse the Passengers from the configuration file.
	void _parsePassengers   (std::ifstream & config_file, int num_lines, std::vector<std::string>::const_iterator & c_it);
	// Parse the Controllables from the configuration file.
	void _parseControllables(std::ifstream & config_file, int num_lines, std::vector<std::string>::const_iterator & c_it);

	void _postParseCheck(); // Check that the data retreived post-parse is consistent and error-free.

	// "Public" Namespace Members
	// ==========================

	// Function Declarations

	void load(); // The main function to load configuration constants.

	std::vector<Device> getDevices(); // Return the parsed Devices.

	std::vector<pm::Passenger> getPassengers(); // Return the parsed Passengers.

	std::vector<ctrl::Controllable> getControllables(); // Return the parsed Controllables.

	// Class Declarations
}

#endif