#include <Arduino.h>
#include "wifi_manager.h"
#include "websocket_server.h"

void setup() {

  Serial.begin(115200);
  Serial.println("ESP32 iniciado");
  connectWiFi();

  websocketInit();
}

void loop() {
  // put your main code here, to run repeatedly:
  websocketLoop();
  //delay(1000);
  websocketSend("Hola desde el esp");
}

