#include <stdio.h>
#include <errno.h>
#include <wiringPi.h>
#define BUTTON_PIN 0

volatile int eventCount = 0;
void myInterrupt(void){
    eventCount++;
}

int main()
{
    if(wiringPiSetup() < 0){
        printf("Can't setup wiringPi: %s\n",strerror(errno));
        return 1;
    }

    if(wiringPiISR(BUTTON_PIN, INT_EDGE_FALLING, &myInterrupt) < 0){
        printf("Can't setup ISR: %s\n", strerror(errno));
        return 2;
    }

    while(1){
        printf("%d\n",eventCount);
        eventCount = 0;
        delay(1000);
    }

    return 0;
}
