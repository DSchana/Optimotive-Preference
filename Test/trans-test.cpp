#include <wiringPi.h>
#include <cstdio>

#define T_PIN 12

using namespace std;

int main() {
        wiringPiSetup();

        pinMode(T_PIN, OUTPUT);

        while (true) {
                digitalWrite(T_PIN, 1);  // Open gate

                delay(1000);  // Delay in ms

                digitalWrite(T_PIN, 0);  // Close gate

                delay(1000);
        }

        digitalWrite(T_PIN, 0);

        return 0;
}
