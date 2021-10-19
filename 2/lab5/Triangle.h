#pragma once
#include "Figure.h"
class Triangle : public Figure
{
private:
	double a;
	double b;
	double c;
public:
	double Perimeter();
	double Area();

	Triangle(int A, int B, int C);
};

