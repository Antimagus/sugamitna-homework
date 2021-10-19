#include <iostream>
#include "Classes.h"

using namespace std;

double CalcCylinderVolume(double h, Figure* F)
{
	return h * F->Area();
}

int main()
{
	int a, b, c;
	cout << "Enter the sides of the triangle:\n";
	cout << "a = "; cin >> a; cout << "b = "; cin >> b; cout << "c = "; cin >> c;
	Triangle T(a, b, c);
	cout << "S(triangle) = " << T.Area() << ".\n";
	cout << "P(triangle) = " << T.Perimeter() << ".\n\n";

	int r;
	cout << "Enter the radius of the circle:\n";
	cout << "r = "; cin >> r;
	Circle C(r);
	cout << "S(circle) = " << C.Area() << ".\n";
	cout << "P(circle) = " << C.Perimeter() << ".\n\n";

	int h;
	cout << "Enter the height of the figures:\n";
	cout << "h = ";  cin >> h;
	cout << "The volume of a cylindrical triangle: " << CalcCylinderVolume(h, &T) << ".\n";
	cout << "The volume of a cylindrical circle: " << CalcCylinderVolume(h, &C) << ".\n";
}