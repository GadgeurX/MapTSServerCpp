#include "PlayerManager.hpp"

std::mutex g_players_mutex;

uint32_t PlayerManager::getPlayerIdFromConnection(const evpp::TCPConnPtr& conn)
{
	std::lock_guard<std::mutex> guard(g_players_mutex);
	for (auto player :this->players)
	{
		if (player.getConnection()->id() == conn->id())
			return player.id;
	}
	return -1;
}

bool PlayerManager::registerPlayer(std::string& login, std::string& email, std::string& password)
{
	std::lock_guard<std::mutex> guard(g_players_mutex);
	for (auto player : this->players)
	{
		if (player.login == login || player.email == email)
			return false;
	}
	this->players.push_back(Player(login, email, password));
	return true;
}

bool PlayerManager::loginPlayer(const evpp::TCPConnPtr& conn, std::string& login, std::string& password)
{
	std::lock_guard<std::mutex> guard(g_players_mutex);
	for (auto player : this->players)
	{
		if (player.login == login && player.password == password) {
			player.setConnection(conn);
			return true;
		}
	}
	return false;
}
