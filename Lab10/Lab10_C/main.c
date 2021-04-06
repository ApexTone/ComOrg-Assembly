#include <stdio.h>
#include <stdlib.h>
#include <wiringPi.h>

int main()
{
   	int pin=7;
   	printf("LED blinking by wiringPi\n");
	if(wiringPiSetup() == -1){
		printf("Setting up problem... Abort!\n");
		exit(1);
	}

	pinMode(pin, OUTPUT);
	for(int i=0;i<10;i++){
		digitalWrite(pin,1);
		delay(500);
		digitalWrite(pin,0);
		delay(500);
	}
    return 0;
}
