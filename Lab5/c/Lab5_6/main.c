/*
This program explore the negative overflowing of int
*/

#include <stdio.h>

int main()
{
    int i=-1;
    while(i<0)
    {
        i--;
        if(i>=0)
        {
            printf("i was %10d before\n",i+1);
            printf("i  is %10d now\n",i);
        }
    }
    return 0;
}
