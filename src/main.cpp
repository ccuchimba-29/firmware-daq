#include <Arduino.h>
#include "wifi_manager.h"
#include "websocket_server.h"
#include "timer_manager.h"

void setup() {
  timerInit();
  Serial.begin(115200);
  Serial.println("ESP32 iniciado");
  connectWiFi();
  websocketInit();
}

void loop() {
  // put your main code here, to run repeatedly:
  websocketLoop();
  if(timerFlags.sendFlag){
    timerFlags.sendFlag = false;
    websocketSend("Hola desde el esp");
  }
  //delay(1000);
  //websocketSend("Hola desde el esp");
}

