#pragma once
#include <evpp/tcp_server.h>
#include <evpp/buffer.h>
#include <evpp/tcp_conn.h>
#include "../Game.hpp"
#include "../../schema_generated.h"


typedef void (*processorFunc)(const evpp::TCPConnPtr&, const void*);

class PacketProcessor {
public:
	static PacketProcessor* Instance();
	void execute(const evpp::TCPConnPtr& conn, const packet::Packet* msg);
private:
	static PacketProcessor* instance;
	static std::map<packet::PacketType, processorFunc> packets;
};