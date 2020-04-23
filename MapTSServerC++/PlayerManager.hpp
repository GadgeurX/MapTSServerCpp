#pragma once
#include <evpp\tcp_conn.h>
#include <mutex>
#include <string>
#include "Player.hpp"


class PlayerManager {
public:
	uint32_t getPlayerIdFromConnection(const evpp::TCPConnPtr& conn);
	bool registerPlayer(std::string& login, std::string& email, std::string& password);
	bool loginPlayer(const evpp::TCPConnPtr& conn, std::string& login, std::string& password);
private:
	std::vector<Player> players;
};