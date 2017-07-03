/*
 * Title:       VehicleInterface.h
 * Authors:     Roman Seviaryn, Michael Ala
 * Last Edit:   March 12th, 2017
 * Description: This file is a wrapper between the Optimotive 
 *              System and the car's hardware.
**/

#ifndef VEHICLEINTERFACE_H
#define VEHICLEINTERFACE_H

#include <wiringPi.h>
#include <vector>

#include "SysConfig.h"

namespace vi {

	// enum for the direction of the motors
	enum OutputType {
		POS,
		NEG,
		NEUT
	};

	struct HBridgeOutput {
		int motor_id;			// ID of the motor used
		int pwr_pin, dir_pin;		// pins to output to: power to the motor and direction of the motor
		int current_pos;		// current_position of the motor, assumes starting point is spot 0
	};

	struct MotorQueuePacket {
		int time_remaining;		// remaining number of loops the packet has to run
		HBridgeOutputs pin_set;		// the set of pins being controled
		OutputType direction;		// direction of movement
	};

	class VehicleInterface {
	private:
		std::vector <MotorQueuePacket> active_outputs;
		std::vector <HBridgeOutput> output_map;
		std::vector <sc::Device> devices;

		static void moveMotor(HBridgeOutput, OutputType, int length);	// Internal motor driver
		
	public:
		static void activate();					// initialize method
		static void setMotorPos(int motor_id, int position);	// sets the motor to the given position. Warning! this is not immediate
		static int  getMotorPos(int motor_id);			// returns the current position of the motor
		static void update();					// updates the motors packets, stops motors when they have arrived to their destinations
	};
}

#endif
