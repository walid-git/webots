#include "WbTransportClientWebsocket.hpp"

#include <QtWebSockets/QWebSocket>

void WbTransportClientWebsocket::setWebSocketClient(QWebSocket *client) {
  mClient = client;
  connect(mClient, &QWebSocket::disconnected, this, &WbTransportClientWebsocket::propagateDisconnected);
  connect(mClient, &QWebSocket::textMessageReceived, this, &WbTransportClientWebsocket::propagateTextMessageReceived);
}

qint64 WbTransportClientWebsocket::sendTextMessage(const QString &message) {
  return mClient->sendTextMessage(message);
}
