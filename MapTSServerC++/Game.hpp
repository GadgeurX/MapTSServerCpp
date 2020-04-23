#pragma once

#include <chrono>
#include <thread>
#include <mutex>
#include "EntityManager.hpp"
#include "PlayerManager.hpp"
#include "server/Server.hpp"

class Game {
public:
	static Game* Instance();
	Server* server;
	PlayerManager* playerManager;
	EntityManager* entityManager;
	void run();
private:
	Game();
	static Game* instance;
};