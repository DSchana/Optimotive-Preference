/*
 * Title:       VehicleInterface.cpp
 * Authors:     Roman Seviaryn
 * Last Edit:   March 12th, 2017
 * Description: This file is a wrapper between the Optimotive 
 *              System and the car's hardware.
**/

#include "VehicleInterface.h"

using namespace vi;

/*
 * Description:	Moves the motors based on the input
 * Parameters:	HBridgeOutput - motor_set:	set of motors to control
 *				OutputType - direction:		direction to move the the motors in
 *				Integer - length:			duration of time to drive the motors
 * Returns:		Void
**/
void VehicleInterface::moveMotor(HBridgeOutput motor_set, OutputType direction, int length) {
	switch (output) {
		case POS:
			digitalWrite(motor_set.pwr_pin, 1);
			digitalWrite(motor_set.dir_pin, 0);
			break;
		case NEG:
			digitalWrite(motor_set.pwr_pin, 1);
			digitalWrite(motor_set.dir_pin, 1);
			break;
		case NEUT:

			digitalWrite(motor_set.pwr_pin, 0);
			digitalWrite(motor_set.dir_pin, 0);
			break;
	}

	MotorQueuePacket to_heap = {length, motor_set, direction};
	active_outputs.push_back(to_heap);
}

/*
 * Description:	Initializes the Vehicle interface
 * Parameters:	Nothing
 * Returns:		Void
 **/
void VehicleInterface::initialize() {

	wiringPiSetup(); // to use the pi

	using namespace sc;

	devices = getDevices();

	std::vector<Device>::iterator element;

	for (element = devices.begin(); devices.end(); element++) {
		HBridgeOutput temp_package;

		pinMode(element->output_pins[0], OUTPUT);
		pinMode(element->output_pins[1], OUTPUT);

		temp_package.id = element->id
		temp_package.pwr_pin = element->output_pins[0];
		temp_package.dir_pin = element->output_pins[1];
		temp_package.current_pos = 0;

		output_map.push_back(temp_package);
	}
}

/*
 * Description:	Public function to control motors
 * Parameters:	Integer - motor_id:	Id of motor to move
 *				Integer - position:	position to move the motor to
 * Returns:		Void
**/
void VehicleInterface::setMotorPos(int motor_id, int position) {
	HBridgeOutput motor_set = output_map[motor_id];
	int difference = position - motor_set.current_pos;
	if (difference < 0) {
		difference *= -1;
		MoveMotor(motor_set, NEG, difference);
	}
	else {
		MoveMotor(motor_set, POS, difference);
	}
}

/*
 * Description:	Gets the current motor position
 * Parameters:	Integer:	motor_id
 * Returns:		Integer:	returns the current position of the motor
**/
int VehicleInterface::getMotorPos(int motor_id) { return motor_map[motor_id].current_pos; }

/*
 * Description:	Updates the motors every tick, stops the motors
 *				when they have reached their destinations
 * Parameters:	N/A
 * Returns:		Void
**/
void VehicleInterface::update() {

	std::vector<MotorQueuePacket>::iterator element;

	for (element = active_outputs.begin(); active_outputs.end(); element++) {

		if (element->time_remaining == 0){
			MoveMotor(element->pin_set.motor_id, NEUT)
			active_outputs.erase(active_outputs.begin() + i);
		}
		element->time_remaining -= 1;
		
		// may have to switch these if wired incorrectly
		if (element->direction == POS) {
			element->motor_set.position += 1;
		}
		else if (element->direction == NEG) {
			element->motor_set.position -= 1;
		}
	}
}
