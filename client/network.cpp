#include "network.h"
#include <iostream>


network::client::client(const std::string &ip, uint16_t port) {
  enet_initialize();
  atexit(enet_deinitialize);

  enet_address_set_host(&address, "127.0.0.1");
  address.port = port;

  host = enet_host_create(nullptr, 1, 1, 0, 0);

}

network::client::~client() {
  enet_peer_disconnect(peer, 0);
  while (enet_host_service(host, &event, 1000)) {
    switch (event.type) {
      case ENET_EVENT_TYPE_RECEIVE:
        enet_packet_destroy(event.packet);
        break;
      case ENET_EVENT_TYPE_DISCONNECT:
        std::cout << "disconnected\n";
        break;
    }
  }
  enet_host_destroy(host);
}

bool network::client::connect() {
  peer = enet_host_connect(host, &address, 1, 0);
  if (enet_host_service(host, &event, 5000)) {
    if (event.type == ENET_EVENT_TYPE_CONNECT) {
      std::cout << "connected\n";
    }
  } else {
    enet_peer_reset(peer);
    std::cout << "failed to connect\n";
    return false;
  }

  return true;
}

void network::client::handle(const std::function<void(uint16_t, const packet &)>& callback, bool *isSetId) {
  while (enet_host_service(host, &event, 0)) {
    if (event.type == ENET_EVENT_TYPE_RECEIVE) {
      auto p = *reinterpret_cast<packet *>(event.packet->data);
      if (p.type == packetType::assignId ) {
        id = p.id;
        std::cout << "assigned to new id (" << p.id << ")\n";
        *isSetId = true;
      }
      callback(id, p);
    }
  }
}

void network::client::send(const network::packet &packet) const {
  auto p= enet_packet_create(&packet, sizeof(packet), ENET_PACKET_FLAG_RELIABLE);
  enet_peer_send(peer, 0, p);
}

uint16_t network::client::getId() const {
  return id;
}