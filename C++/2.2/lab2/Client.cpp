#include <iostream>
#include "Iface.h"

class Server
{
    private:
        I_ClassFactory* factory;
        IServer* iServer;
        IServer2* iServer2;

    public:
        void Func();
        void Func2();
        Server();
        ~Server();
        Server& operator=(Server& newServer);
};

Server::Server()
{
    GetClassObject(CLSIDServer, IID_IClassFactory, (void**)&factory);
    factory->CreateInstance(IID_IServer, (void**)&iServer);
    factory->Release();
    iServer->QueryInterface(IID_IServer2, (void**)&iServer2);
}

Server::~Server() 
{
    iServer->Release();
    iServer2->Release();
}

void Server::Func()
{
    iServer->Func();
}

void Server::Func2()
{
    iServer2->Func2();
}

Server& Server::operator=(Server& newServer) 
{
    return newServer;
}

int main()
{
    Server server;
    Server server2;
    server = server2;
    server.Func();
    server.Func2();
}