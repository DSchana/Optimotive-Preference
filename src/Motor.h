#ifndef MOTOR_H
#define MOTOR_H

#include <cstdio>
#include <wiringPi.h>

class Motor {
private:
        int pwr_pin, dir_pin;
        int pwr, dir;
        int curr_dir;

public:
        Motor(int n_pwr_pin, int n_dir_pin);
        void update();
        void changeDirection(int n_dir);
};

#endif
