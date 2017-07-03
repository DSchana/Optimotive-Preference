#ifndef MOTOR_MANAGER_H
#define MOTOR_MANAGER_H

#include "Motor.h"
#include "opencv2/highgui.hpp"
#include <cmath>
#include <cstdio>
#include <vector>
#include <wiringPi.h>

class MotorManager {
private:
        static std::vector<Motor> motors;
	static int end_time;
	static int curr_time;
	static std::vector<int> times;

public:
	static void initialize();
	static void update();
	static void loadUser(int id);
	static void addMotor(Motor m); 
	static Motor getMotor(int id);
	static bool isLoading();
};

#endif
