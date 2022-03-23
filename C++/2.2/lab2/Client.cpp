#include <iostream>
#include "Iface.h"

using namespace std;
int main()
{
    I_ClassFactory* serverFactory;
    IServer2* iServer2;
    H_RESULT res = GetClassObject(CLSIDServer, IID_IClassFactory, (void**)&serverFactory);
    if(res != S_OK) return res;
    res = serverFactory->CreateInstance(IID_IServer2, (void**)&iServer2);
    serverFactory->Release();
    if(res != S_OK) return res;
    iServer2->Func2();
    IServer* iServer;
    iServer2->QueryInterface(IID_IServer, (void**)&iServer);
    iServer->Func();
    iServer2->Release();
    iServer->Release();
}