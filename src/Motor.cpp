#include "Motor.h"

using namespace std;

Motor::Motor(int n_pwr_pin, int n_dir_pin) {
        pwr_pin = n_pwr_pin;
        dir_pin = n_dir_pin;
        dir = 0;
	pwr = 0;

        pinMode(pwr_pin, OUTPUT);
	pinMode(dir_pin, OUTPUT);

	update();
}

void Motor::update() {
        digitalWrite(pwr_pin, pwr);
        digitalWrite(dir_pin, dir);
}

void Motor::changeDirection(int n_dir) {
        curr_dir = n_dir;

        if (curr_dir == 1) {
                pwr = 1;
                dir = 1;
        }   
        else if (curr_dir == -1) {
                pwr = 1;
                dir = 0;
        }   
        else {
                pwr = 0;
                dir = 0;
        }
}
