#pragma once

#include <iostream>
#include <vector>
#include <evpp/tcp_server.h>
#include <evpp/buffer.h>
#include <evpp/tcp_conn.h>
#include "Client.hpp"
#include "PacketProcessor.hpp"
#include "../../schema_generated.h"

class Server {
public:
	Server();
	void run();
private:
	std::vector<Client> clients;
};