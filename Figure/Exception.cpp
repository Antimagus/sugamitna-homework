#include "Exception.h"

Exception::Exception(int code, std::string message)
{
	this->code = code;
	this->message = message;
}

Exception::~Exception() {}

void Exception::Show()
{
	std::cout << "Error " << code << ": " << message << std::endl;
}
