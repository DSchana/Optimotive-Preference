#include "MotorManager.h"

using namespace std;

vector<Motor> MotorManager::motors;
vector<int> MotorManager::times;
int MotorManager::end_time;
int MotorManager::curr_time;

void MotorManager::initialize() {
        wiringPiSetupPhys();
	end_time = 0;
	curr_time = 0;
	for (int i = 0; i < 3; i++) {
		times.push_back(0);
	}
}

int sign(int x, int y) {
	if (x == y) {
		return 0;
	}

	return (x - y) / abs(x - y);
}

void MotorManager::update() {
	int dir = sign(end_time, curr_time);

	// curr_time += dir;

	if (curr_time < 0) {
		curr_time = 0;
		end_time = 0;
	}

	for (int i = 0; i < 3; i++) {
		motors[i].changeDirection(0);
	}

	if (times[0] != end_time) {
		// printf("Updateing 0\n");
		motors[0].changeDirection(dir);
		times[0] += dir;
		// motors[0].update();
	}
	else if (times[1] != end_time) {
		// printf("Updateing 1\n");
		motors[1].changeDirection(dir);
		times[1] += dir;
		// motors[1].update();
	}
	else if (times[2] != end_time) {
		// printf("Updateing 2\n");
		motors[2].changeDirection(dir);
		times[2] += dir;
		// motors[2].update();
	}

	if (times[0] == end_time &&
	    times[1] == end_time &&
	    times[2] == end_time) {
		curr_time = end_time;
	}

	for (int i = 0; i < motors.size(); i++) {
                motors[i].update();
        }

	for (int i = 0; i < 3; i++) {
		printf("%d, ", times[i]);
	}

	printf("   Dir: %d; Curr: %d; End: %d\n", dir, curr_time, end_time);
}

void MotorManager::loadUser(int id) {
	if (id == -1) {
		return;
	}
	else if (id == 0) {
		end_time = 0;
	}
	else if (id == 1) {
		end_time = 2;
	}
	else if (id == 2) {
		end_time = 4;
	}
}

void MotorManager::addMotor(Motor m) {
	motors.push_back(m);
}

Motor MotorManager::getMotor(int id) {
	return motors[id];
}

bool MotorManager::isLoading() {
	return end_time != curr_time;
}
