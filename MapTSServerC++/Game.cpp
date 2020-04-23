#include "Game.hpp"

Game* Game::instance = nullptr;

Game::Game() {
	this->entityManager = new EntityManager();
	this->playerManager = new PlayerManager();
	this->server = new Server();
}

Game* Game::Instance()
{
	if (!Game::instance)
		Game::instance = new Game();
	return Game::instance;
}

void Game::run()
{
	std::thread serverThread(&Server::run, this->server);
	while (true) {
		this->entityManager->update();
		std::this_thread::sleep_for(std::chrono::milliseconds(16));
	}
	serverThread.join();
}
