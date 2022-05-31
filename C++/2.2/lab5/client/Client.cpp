#include <windows.h>
#include <iostream>
#include <sstream>
#include "../server/color/ColorAPI.h"

const CLSID CLSIDColor = {0x91A42CAA,0x2577,0x4E80,{0x93,0x4E,0x07,0xDE,0x64,0x50,0x2F,0xD6}};

int main() 
{
    CoInitialize(NULL);
    IPrint* iPrint;
    IClassFactory* factory = NULL;
    HRESULT result = CoCreateInstance(CLSIDColor, NULL, CLSCTX_INPROC_SERVER, IID_IPrint, (void**)&iPrint);
    if (!(SUCCEEDED(result))) {
        std::cout << "error" << std::endl;
        return 0;
    }
    iPrint->print();
    CoUninitialize();
}