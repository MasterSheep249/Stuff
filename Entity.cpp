#include "Point3d.h"
#include "Entity.h"
#include "Random.h"
#include <iostream>
#include <cmath>
Entity::Entity()
{
	entityCoord.setX(Random::get(1, 10));
	entityCoord.setY(Random::get(1, 10));
	entityCoord.setZ(Random::get(1, 10));

	entityDamage  = Random::get(1,2);
	entityRange = Random::get(1, 3);
}
void Entity::printEntityStats()
{
	std::cout << "Entity damage: " << entityDamage << '\n';
	std::cout << "Entity range: " << entityRange << '\n';
	entityCoord.printCoord();
}
bool Entity::inRange(Entity& aEntity)
{
	//std::cout << aEntity.entityCoord.getX() - this->entityCoord.getX() << '\n';
	bool isInXRange{ std::abs((aEntity.entityCoord.getX() - this->entityCoord.getX())) < std::abs(this->entityRange) };
	if (isInXRange) { return true; }

	bool isInYRange{ std::abs((aEntity.entityCoord.getY() - this->entityCoord.getY())) < std::abs(this->entityRange) };
	if (isInYRange) { return true; }

	bool isInZRange{ std::abs((aEntity.entityCoord.getZ() - this->entityCoord.getZ())) < std::abs(this->entityRange) };
	if (isInZRange) { return true; }

	return false;
}
void Entity::printInRange()
{
	
}
