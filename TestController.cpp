#include "TestController.h"

using namespace cv;

// Define variables
/*
vio::TransistorTuple HORIZONTAL_MOTOR;
vio::TransistorTuple FRONT_MOTOR;
vio::TransistorTuple BACK_MOTOR;
*/

void test::moveChair()
{
	// Define variables
        vio::TransistorTuple HORIZONTAL_MOTOR;
        vio::TransistorTuple FRONT_MOTOR;
        vio::TransistorTuple BACK_MOTOR;

	int key_pressed = waitKey(5);
	switch (key_pressed)
	{
		case 97:
			outputToTransistors(vio::HORIZONTAL_MOTOR, vio::POS);
			break;
		case 100:
			outputToTransistors(vio::HORIZONTAL_MOTOR, vio::NEG);
			break;
		case 119:
			outputToTransistors(vio::FRONT_MOTOR, vio::POS);
			break;
		case 115:
			outputToTransistors(vio::FRONT_MOTOR, vio::NEG);
			break;
		case 32:
			outputToTransistors(vio::HORIZONTAL_MOTOR, vio::NEUT);
			outputToTransistors(vio::FRONT_MOTOR, vio::NEUT);
	}
}
