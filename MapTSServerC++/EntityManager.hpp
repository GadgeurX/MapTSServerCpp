#pragma once
#include <vector>
#include "entity/Entity.hpp"

class EntityManager {
public:
	void update();
private:
	std::vector<Entity> entities;
};