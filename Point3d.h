#pragma once
class Point3d
{
	int x;
	int y;
	int z;
public:
	Point3d(int xCoord, int yCoord, int zCoord);
	Point3d() = default;
	void printCoord();
	int getX();
	int getY();
	int getZ();
	void setX(int aX);
	void setY(int aY);
	void setZ(int aZ);
	bool isSamePoint(Point3d& aPoint);
};
