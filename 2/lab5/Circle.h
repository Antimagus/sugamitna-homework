#pragma once
#include "Figure.h"
class Circle : public Figure
{
private:
	double r;
public:
	double Area();
	double Perimeter();

	Circle(int R);
};

