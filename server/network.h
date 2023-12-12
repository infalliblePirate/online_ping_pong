#ifndef PING_PONG_NETWORK_H
#define PING_PONG_NETWORK_H

#include <string>
#include <enet/enet.h>

namespace network {
    enum class packetType {
        assignId,
        updatePosition,
        gameState
    };

    struct packet {
        packetType type;
        uint16_t id;
        float x;
    };

    class server {
    public:
        server (uint16_t port = 8192);
        ~server();

        void handle();
    private:
        void send(const packet& packet, ENetPeer* peer) const;
        void broadcast(const packet& packet) const;

        ENetAddress address;
        ENetHost* host;
        ENetEvent event;
        uint16_t freeId;
    };


}


#endif //PING_PONG_NETWORK_H
