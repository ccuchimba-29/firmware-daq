#include <wifi_manager.h>
#include <WiFi.h>


const char* ssid = "CCUCHIMBA 29";
const char* password = "set@06072001";

void connectWiFi(){
    WiFi.begin(ssid, password);

    Serial.print("Conectando");

    while (WiFi.status() != WL_CONNECTED)
    {
        delay(500);
        Serial.print(".");
    }

    Serial.println();
    Serial.println("WiFi conectado");
    Serial.print("IP: ");
    Serial.println(WiFi.localIP());
}