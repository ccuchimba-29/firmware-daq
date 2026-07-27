#ifndef WEBSOCKET_SERVER_H
#define WEBSOCKET_SERVER_H

#include <Arduino.h>

void websocketInit();
void websocketLoop();

bool websocketIsClientConnected();

void websocketSend(String message);
void websocketBroadcast(String message);

#endif