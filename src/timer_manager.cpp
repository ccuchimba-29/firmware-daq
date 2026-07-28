#include "timer_manager.h"

static hw_timer_t *timer = nullptr;

static volatile uint32_t seconds = 0;
static volatile boolean messageSendFlag = false;

TimerFlags_t timerFlags;

void IRAM_ATTR onTimer(){
    timerFlags.tickCounter++;

    if(timerFlags.tickCounter >= 1000){
        timerFlags.sendFlag = true;
        timerFlags.tickCounter=0;
    }
}


void timerInit(void){
    // Timer 0, Prescaler = 80, Frecuencia = 80 MHz / 80 = 1 MHz
    timer = timerBegin(0, 80, true);
    // Asocia la ISR
    timerAttachInterrupt(timer, &onTimer, false);
    // Interrupción cada 1 000 000 ticks = 1 segundo
    timerAlarmWrite(timer, 1000, true);
    // Habilita la alarma
    timerAlarmEnable(timer);
}

