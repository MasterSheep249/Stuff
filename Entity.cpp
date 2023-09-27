#include "Point3d.h"
#include "Entity.h"
#include "Random.h"
#include <iostream>
#include <cmath>
void Entity::setRandomCoords()
{
	entityCoord.setX(Random::get(1, 10));
	entityCoord.setY(Random::get(1, 10));
	entityCoord.setZ(Random::get(1, 10));
}
Entity::Entity(int aRange, int aDamage)
{
	setRandomCoords();
	id = 'p';
	entityDamage = aDamage;
	entityRange = aRange;
}
Entity::Entity()
{
	setRandomCoords();
	entityDamage  = Random::get(1,2);
	entityRange = Random::get(1, 1);
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
	bool isInXRange{ std::abs((aEntity.entityCoord.getX() - this->entityCoord.getX())) <= std::abs(this->entityRange) };
	if (isInXRange) { return true; }

	bool isInYRange{ std::abs((aEntity.entityCoord.getY() - this->entityCoord.getY())) <= std::abs(this->entityRange) };
	if (isInYRange) { return true; }

	bool isInZRange{ std::abs((aEntity.entityCoord.getZ() - this->entityCoord.getZ())) <= std::abs(this->entityRange) };
	if (isInZRange) { return true; }

	return false;
}
void Entity::printInRange()
{
	
}
bool Entity::checkCollisions(std::vector<Entity> entities)
{
	for (std::size_t index{0}; index < entities.size(); ++index)
	{
		if (this->inRange(entities[index]))
		{
			return true;
		}
	}
	return false;
}
void Entity::deleteEntity()
{
	std::cout << "Entity with id " << this->id << " has been deleted";
	entityCoord.setX(-1);
	entityCoord.setY(-1);
	entityCoord.setZ(-1);
}
