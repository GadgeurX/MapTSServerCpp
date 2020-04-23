// MapTSServerC++.cpp : définit le point d'entrée de l'application.
//

#include "MapTSServerC++.hpp"
#include "Game.hpp"
#include <boost/log/trivial.hpp>
#include "Logger.hpp"

using namespace std;

int main()
{
	LOG_INFO << "MapTS Startup";
	Game::Instance()->run();
	return 0;
}
