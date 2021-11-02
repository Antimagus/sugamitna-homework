#pragma once
#include "Figure.h"
class Figure3D
{
public:
	virtual double CalcVolume() = 0;
};

class Cylinder : public Figure3D
{
protected:
	Figure* f;
private:
	double h;
public:
	double CalcVolume();

	Cylinder(Figure* f, double h);
	~Cylinder();
};

class CircleCylinder : public Cylinder
{	
public:
	static CircleCylinder* CreateInstance(double r, double h);
	double GetRadius();

	CircleCylinder(Circle* f, double h);
};

class TriangleCylinder : public Cylinder
{
public:
	static TriangleCylinder* CreateInstance(double a, double b, double c, double h);
	double GetSide(int number);

	TriangleCylinder(Triangle* f, double h);
};

class RingCylinder : public Cylinder
{
public:
	static RingCylinder* CreateInstance(double r, double R, double h);
	double GetSmallRadius();
	double GetBigRadius();

	RingCylinder(Ring* f, double h);
};