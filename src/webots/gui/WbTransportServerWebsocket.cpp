#include "WbTransportServerWebsocket.hpp"

#include <QtWebSockets/QWebSocket>
#include <QtWebSockets/QWebSocketServer>

WbTransportClientWebsocket *WbTransportServerWebsocket::nextPendingConnection() {
  QWebSocket *client = mServer->nextPendingConnection();
  WbTransportClientWebsocket *transportClient = new WbTransportClientWebsocket(client);
  return transportClient;
};

WbTransportServerWebsocket::WbTransportServerWebsocket(bool ssl) {
  QWebSocketServer::SslMode sslMode = ssl ? QWebSocketServer::SecureMode : QWebSocketServer::NonSecureMode;
  mServer = new QWebSocketServer("Webots Streaming Server", sslMode, this);
};

void WbTransportServerWebsocket::setSslConfiguration(QSslConfiguration sslConfiguration) {
  mServer->setSslConfiguration(sslConfiguration);
};
