#include "Triangle.h"
#include <cmath>
double Triangle::Perimeter()
{
	return a + b + c;
}

double Triangle::Area()
{
	double p = Perimeter() / 2;
	return sqrt(p * (p - a) * (p - b) * (p - c));
}

Triangle::Triangle(int A, int B, int C)
{
	if (A > 0 &&  B > 0 && C > 0 && (A + B) > C && (A + C) > B && (B + C) > A)
	{
		a = A;
		b = B;
		c = C;
	}
	else
	{
		a = 3;
		b = 4;
		c = 5;
	}
}