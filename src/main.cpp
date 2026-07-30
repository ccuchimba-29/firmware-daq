#include <Arduino.h>
#include "wifi_manager.h"
#include "websocket_server.h"
#include "timer_manager.h"
#include "temp_manager.h"
#include "json_manager.h"

float temps[12];

String messageJson;

void setup() {
  
  timerInit();
  Serial.begin(115200);
  Serial.println("ESP32 iniciado");
  connectWiFi();
  websocketInit();

  for (int i = 0; i < 12; i++)
  {
    temps[i]=i*2;
    /* code */
  }
  
}

void loop() {
  
  websocketLoop();
  if(timerFlags.sendFlag){
    timerFlags.sendFlag = false;
    
    setJsonMessage(temps);

    messageJson = getJsonMessage();
    Serial.println(messageJson);
    websocketSend(messageJson);
  }
  
}

