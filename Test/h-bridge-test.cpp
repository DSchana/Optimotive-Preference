#include <wiringPi.h>
#include <cstdio>

#define H_PIN_1 12
#define H_PIN_2 11

using namespace std;

int main() {
	wiringPiSetup();

	pinMode(H_PIN_1, OUTPUT);
	pinMode(H_PIN_2, OUTPUT);

	digitalWrite(H_PIN_1, 1);
	digitalWrite(H_PIN_2, 0);
	delay(2000);

	digitalWrite(H_PIN_1, 0);
	digitalWrite(H_PIN_2, 1);
	delay(2000);

	digitalWrite(H_PIN_1, 0);
	digitalWrite(H_PIN_2, 0);

	return 0;
}
