#ifndef TIMER_MANAGER_H
#define TIMER_MANAGER_H

#include <Arduino.h>
typedef struct 
{
    volatile uint32_t tickCounter;
    volatile bool sendFlag; 
}TimerFlags_t;
extern TimerFlags_t timerFlags;

void timerInit(void);

//uint32_t timerGetSeconds(void);

#endif