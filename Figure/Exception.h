#pragma once
#include <string>
#include <string>
#include <iostream>
class Exception
{
private:
	int code;
	std::string message;
public:
	Exception(int code, std::string message);
	~Exception();
	void Show();
};

