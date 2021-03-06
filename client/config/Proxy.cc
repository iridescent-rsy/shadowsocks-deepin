#include "Proxy.h"

namespace config {

Proxy::Proxy() : QSX::Proxy() {}

Proxy::Proxy(const QSX::Proxy &p) {
  use = p.use;
  type = p.type;
  server = p.server;
  port = p.port;
  timeout = p.timeout;
}

Proxy::Proxy(const QJsonObject &json) {
  fromJson(json);
}

void Proxy::fromJson(const QJsonObject &json) {
  if (!json.isEmpty()) {
    use = json["useProxy"].toBool();
    type = json["proxyType"].toInt();
    server = json["proxyServer"].toString();
    port = static_cast<uint16_t>(json["proxyPort"].toInt());
    timeout = static_cast<uint16_t>(json["proxyTimeout"].toInt());
  } else {
    *this = Proxy();
  }
}

QJsonObject Proxy::toJson() {
  QJsonObject json;
  json.insert("useProxy", use);
  json.insert("proxyType", type);
  json.insert("proxyServer", server);
  json.insert("proxyPort", port);
  json.insert("proxyTimeout", timeout);
  return json;
}

}
