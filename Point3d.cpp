#include "Point3d.h"
#include <iostream>
Point3d::Point3d(int xCoord, int yCoord, int zCoord) : x{ xCoord }, y{ yCoord }, z{ zCoord }
{

}

int Point3d::getX() { return x; }
int Point3d::getY() { return y; }
int Point3d::getZ() { return z; }

void Point3d::setX(int aX) { x = aX; }
void Point3d::setY(int aY) { y = aY; }
void Point3d::setZ(int aZ) { z = aZ; }

void Point3d::printCoord()
{
	std::cout << "(X: " << getX() << ", Y: " << getY() << ", Z: " << getZ() << ")" << '\n';
}
bool Point3d::isSamePoint(Point3d& aPoint)
{
	if (aPoint.x != this->x)
	{
		return false;
	}
	if (aPoint.y != this->y)
	{
		return false;
	}
	if (aPoint.z != this->z)
	{
		return false;
	}
	return true;
}
