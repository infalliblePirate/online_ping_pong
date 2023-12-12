#ifndef CLIENT_NETWORK_H
#define CLIENT_NETWORK_H

#include <enet/enet.h>
#include <string>
#include <functional>

namespace network {

    enum class packetType {
        assignId,
        updatePosition,
    };

    struct packet {
        packetType type;
        uint16_t id;
        float x;
    };

    class client {
    public:
        client(const std::string &ip, uint16_t port);

        ~client();

        bool connect();

        void handle(const std::function<void(uint16_t, const packet &packet)>& callback, bool *isSetId);

        void send(const packet &packet) const;

        uint16_t getId() const;

    private:
        ENetAddress address;
        ENetHost *host;
        ENetPeer *peer;
        ENetEvent event;
        uint16_t id;
    };
}

#endif //CLIENT_NETWORK_H
