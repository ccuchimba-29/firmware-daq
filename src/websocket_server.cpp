#include "websocket_server.h"

#include <WebSocketsServer.h>

//==================================================
// Variables privadas
//==================================================

static WebSocketsServer webSocket(81);

static bool clientConnected = false;
static uint8_t clientID = 0;

//==================================================
// Función privada
//==================================================

static void websocketEvent(
    uint8_t client,
    WStype_t type,
    uint8_t *payload,
    size_t length)
{
    switch (type)
    {
        case WStype_CONNECTED:
        {
            clientConnected = true;
            clientID = client;

            Serial.printf("Cliente %u conectado\n", client);

            webSocket.sendTXT(client, "CONNECTED");

            break;
        }

        case WStype_DISCONNECTED:
        {
            clientConnected = false;

            Serial.printf("Cliente %u desconectado\n", client);

            break;
        }

        case WStype_TEXT:
        {
            String message = String((char *)payload);

            Serial.print("Mensaje recibido: ");
            Serial.println(message);

            break;
        }

        default:
            break;
    }
}

//==================================================
// Funciones públicas
//==================================================

void websocketInit()
{
    webSocket.begin();

    webSocket.onEvent(websocketEvent);

    Serial.println("Servidor WebSocket iniciado");
}

void websocketLoop()
{
    webSocket.loop();
}

bool websocketIsClientConnected()
{
    return clientConnected;
}

void websocketSend(String message)
{
    if (!clientConnected)
        return;

    webSocket.sendTXT(clientID, message);
}

void websocketBroadcast(String &message)
{
    webSocket.broadcastTXT(message);
}