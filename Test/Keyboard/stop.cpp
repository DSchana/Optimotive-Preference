#include <wiringPi.h>
#include <cstdio>

using namespace std;

// Power pins
#define F_PWR 11
#define M_PWR 12
#define B_PWR 13

// Direction control pins
#define F_DIR 15
#define M_DIR 16
#define B_DIR 18

int main() {
	wiringPiSetupPhys();
	int m, d;

	pinMode(F_PWR, OUTPUT);
	pinMode(M_PWR, OUTPUT);
	pinMode(B_PWR, OUTPUT);

	pinMode(F_DIR, OUTPUT);
	pinMode(M_DIR, OUTPUT);
	pinMode(B_DIR, OUTPUT);

	// Stop everything
	digitalWrite(F_PWR, 0);
	digitalWrite(F_DIR, 0);

	digitalWrite(M_PWR, 0);
	digitalWrite(M_DIR, 0);

	digitalWrite(B_PWR, 0);
	digitalWrite(B_DIR, 0);

	/*
	while (true) {
		scanf("%d %d", &m, &d);

		if (m == 3 || d == 3) {
			printf("All Halt\n");
			digitalWrite(F_PWR, 0);
			digitalWrite(F_DIR, 0);

			digitalWrite(M_PWR, 0);
			digitalWrite(M_DIR, 0);

			digitalWrite(B_PWR, 0);
			digitalWrite(B_DIR, 0);
		}

		if (m == 0) {
                        switch (d) {
                        case 0:  // Stop
                                printf("Stop\n");
                                digitalWrite(F_PWR, 0);
                                digitalWrite(F_DIR, 0);
                                break;
                        case -1:
                                printf("Down\n");
                                digitalWrite(F_PWR, 1);
                                digitalWrite(F_DIR, 0);
                                break;
                        case 1:
                                printf("Up\n");
                                digitalWrite(F_PWR, 1);
                                digitalWrite(F_DIR, 1);
                                break;
                        default:
                                break;
                        }
                }

		if (m == 1) {
			switch (d) {
			case 0:  // Stop
				printf("Stop\n");
				digitalWrite(M_PWR, 0);
				digitalWrite(M_DIR, 0);
				break;
			case -1:  // Forwards
				printf("Forward\n");
				digitalWrite(M_PWR, 1);
				digitalWrite(M_DIR, 0);
				break;
			case 1:  // Backwards
				printf("Backward\n");
				digitalWrite(M_PWR, 1);
				digitalWrite(M_DIR, 1);
				break;
			default:
				break;
			}
		}

		if (m == 2) {
                        switch (d) {
                        case 0:  // Stop
                                printf("Stop\n");
                                digitalWrite(B_PWR, 0);
                                digitalWrite(B_DIR, 0);
                                break;
                        case -1:
                                printf("Up\n");
                                digitalWrite(B_PWR, 1);
                                digitalWrite(B_DIR, 0);
                                break;
                        case 1:
                                printf("Down\n");
                                digitalWrite(B_PWR, 1);
                                digitalWrite(B_DIR, 1);
                                break;
                        default:
                                break;
                        }
                }
	}
	*/

	return 0;
}
