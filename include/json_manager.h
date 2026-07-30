#ifndef JSON_MANAGER_H
#define JSON_MANAGER_H

#include <Arduino.h>
#include <ArduinoJson.h>

//StaticJsonDocument<256> json;

void jsonCreateMessage();
void setJsonMessage(const float temps[12]);
String getJsonMessage();
#endif