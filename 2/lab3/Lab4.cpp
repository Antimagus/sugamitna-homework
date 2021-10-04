#include <iostream>
#include "Application.h"
int main()
{
	setlocale(LC_ALL, "");
	srand(time(0));
	Application A;
	A.ReadDate("data.txt");
	A.SystemDate();
	A.Main();
}