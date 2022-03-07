#include <iostream>
#include "Servers.h"

using namespace std;
int main()
{
    int serverID;
    int interfaceID;
    cout << "Select server: "; cin >> serverID;
    cout << "Select interface: "; cin >> interfaceID;
    I_Unknown* iU = CreateInstance(serverID);
    if(iU == NULL) return 0;
    switch (interfaceID)
    {
    case 1:
    {
        IServer* iserver;
        if(iU->QueryInterface(1, (void**)&iserver) != -1)
        {
            iserver->Func();
        }
        else return 0;
        break;
    }
    case 2:
    {
        IServer2* iserver2;
        if(iU->QueryInterface(2, (void**)&iserver2) != -1)
        {
            iserver2->Func2();
        }
        else return 0;
        break;
    }
    
    default:
        return 0;
    }
}