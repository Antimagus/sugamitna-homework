#pragma once
#include <string>
class Exception
{
public:
	int code;
	std::string message;
	
	Exception(int code, std::string message);
	~Exception();
	void Show();
};

