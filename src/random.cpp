#include "random.h"

float randomData[12];

//float temperatures[12];

void generateRandomNumbers(void){
    
    for (int i = 0; i < 12; i++)
    {
        randomData[i] = random(250, 301) / 10.0;
    }

}