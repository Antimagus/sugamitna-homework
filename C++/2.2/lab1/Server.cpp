#include "Server.h"
#include <iostream>

void Server::Func()
{
    std::cout << a + b;
}

Server::Server()
{
    a = 10;
    b = 10;
}

Server::~Server()
{
}