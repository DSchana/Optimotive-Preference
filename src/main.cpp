#include <cstdio>
#include "FaceDetector.h"
#include "Motor.h"
#include "MotorManager.h"
#include "opencv2/highgui.hpp"

#define DEBUG false

using namespace std;

int main() {
        MotorManager::initialize();
        FaceDetector::initialize();

        MotorManager::addMotor(Motor(11, 15));
        MotorManager::addMotor(Motor(12, 16));
        MotorManager::addMotor(Motor(13, 18));

        while (true) {
                MotorManager::update();

                FaceDetector::detectFace();
                FaceDetector::makeMesh(FaceDetector::getMainFace());

		if (!DEBUG) {
			FaceDetector::printUserId();
			MotorManager::loadUser(FaceDetector::getMainID());
		}
		else if(DEBUG) {
			int to_load = -1;

			if (!MotorManager::isLoading()) {
				MotorManager::update();
				printf("Who dis: ");
				scanf("%d", &to_load);
			}

			MotorManager::loadUser(to_load);
		}
        }   

        FaceDetector::terminate();

        return 0;
}
