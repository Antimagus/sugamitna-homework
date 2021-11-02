#include "Figure3D.h"
#include <iostream>

//______________________Cylinder______________________________

double Cylinder::CalcVolume()
{
	return h * f->CalcArea();
}

Cylinder::Cylinder(Figure* f, double h)
{
	this->h = h;
	this->f = f;
}

Cylinder::~Cylinder()
{
	delete f;
}

//______________________CircleCylinder______________________________

CircleCylinder* CircleCylinder::CreateInstance(double r, double h)
{
	Circle* C = new Circle(r);
	CircleCylinder* CC = new CircleCylinder(C, h);
	//delete C;
	return CC;
}

double CircleCylinder::GetRadius()
{
	Circle* C = (Circle*)f;
	return C->GetRadius();
}

CircleCylinder::CircleCylinder(Circle* f, double h) : Cylinder(f, h) {}

//______________________TriangleCylinder______________________________

TriangleCylinder* TriangleCylinder::CreateInstance(double a, double b, double c, double h)
{
	Triangle* T = new Triangle(a, b, c);
	TriangleCylinder* TC = new TriangleCylinder(T, h);
	return TC;
}

double TriangleCylinder::GetSide(int number)
{
	Triangle* T = (Triangle*)f;
	return T->GetSide(number);
}

TriangleCylinder::TriangleCylinder(Triangle* f, double h) : Cylinder(f, h) {}

//______________________RingCylinder______________________________

RingCylinder* RingCylinder::CreateInstance(double r, double R, double h)
{
	Ring* R_ = new Ring(r, R);
	RingCylinder* RC = new RingCylinder(R_, h);
	return RC;
}

double RingCylinder::GetSmallRadius()
{
	Ring* T = (Ring*)f;
	return T->GetSmallRadius();
}

double RingCylinder::GetBigRadius()
{
	Ring* T = (Ring*)f;
	return T->GetBigRadius();
}

RingCylinder::RingCylinder(Ring* f, double h) : Cylinder(f, h) {}