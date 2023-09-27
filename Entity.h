#pragma once
#include "Point3d.h"
#include <vector>
class Entity
{
	int entityDamage{};
	char id{'o'};
	int entityRange{};
	Point3d entityCoord{ 0,0,0 };
public:
	Entity();
	Entity(int aRange, int aDamage);
	void setRandomCoords();
	bool inRange(Entity& aEntity);
	void printEntityStats();
	void printInRange();
	bool checkCollisions(std::vector<Entity> entities);
	void deleteEntity();

	static std::vector<Entity> generateEntities(int aNumber)
	{
		std::vector<Entity> entities{};
		entities.resize(aNumber);
		for (std::size_t index{0}; index < aNumber; ++index)
		{
			entities[index] = Entity();
		}
		return entities;
	}

};
