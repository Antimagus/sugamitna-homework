#define _USE_MATH_DEFINES
#include "Circle.h"
#include <cmath>

Circle::Circle(int R)
{
	if (R > 0) r = R;
	else r = 1;
}

double Circle::Area()
{
	return M_PI * r * r;
}

double Circle::Perimeter()
{
	return 2 * M_PI * r;
}