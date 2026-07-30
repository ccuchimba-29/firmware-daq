#include "json_manager.h"

JsonDocument json;

void jsonCreateMessage()
{
    json.clear();
    json["type"] = "temperature";
}

void setJsonMessage(const float temps[12]){
    json.clear();
    json["type"] = "temperature";
    JsonArray tempArray = json["temperatures"].to<JsonArray>();
    for (uint8_t i = 0; i < 12; i++)
    {
        tempArray.add(temps[i]);
    }


}

String getJsonMessage(){
    String message;
    serializeJson(json,message);
    return message;
}