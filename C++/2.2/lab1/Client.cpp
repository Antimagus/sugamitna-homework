#include "IServer.h"

int main()
{
    IServer *server = CreateInstance();
    server->Func();
    delete server;
}