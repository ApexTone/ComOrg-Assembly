#include <stdio.h>
#include <errno.h>
#include <wiringPi.h>

#define BUTTON_PIN 0

int delayTime = 1000, state=0;
void myInterrupt(void){
    if(state==0){
        delayTime = 500;
        state++;
    }
    else if(state==1){
        delayTime = 250;
        state++;
    }
    else{
        delayTime = 1000;
        state = 0;
    }
    //printf("state: %d\n",state);
}

int main(void) {
    int pin[3] = {1, 2, 3};
    int bi[8][3] = {
                        {0,0,0},{0,0,1},{0,1,0},
                        {0,1,1},{1,0,0},{1,0,1},
                        {1,1,0},{1,1,1}
                    };

    if (wiringPiSetup() < -1) {
        printf("Setting up problem ... Abort!\n");
        return 1;
    }

    if(wiringPiISR(BUTTON_PIN, INT_EDGE_FALLING, &myInterrupt) < 0){
        printf("Can't setup ISR\n");
        return 2;
    }

    int i= 0;
    for (i = 0; i < 3; ++i)
        pinMode(pin[i], OUTPUT);

    while(1) {
        for (i = 0; i <=7 ; i++) {
            int k;
            for (k = 0; k < 3; k++)
                digitalWrite(pin[k], bi[i][k]);
            delay(delayTime);
            //printf("i=%d\n",i);
        }
        for (i = 6; i > 0 ; i--) {
            int k;
            for (k = 0; k < 3; k++)
                digitalWrite(pin[k], bi[i][k]);
            delay(delayTime);
            //printf("i=%d\n",i);
        }
    }
}
