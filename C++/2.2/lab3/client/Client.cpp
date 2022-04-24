#include "../component/Component.h"
#include <iostream>
#include <windows.h>

using namespace std;

typedef H__RESULT (*GetClass) (CLS__ID clsid, I__ID iid, void** ppv);

int main(int argc, char const *argv[])
{
    GetClass f;
    HINSTANCE h = LoadLibrary("build/Component.dll");
    if (h == NULL)
    {
        cout << "No dll!!!" << endl;
        return 0;
    }
    f = (GetClass) GetProcAddress(h, "Get__ClassObject");
    if (!f)
    {
        cout << "No dll function" << endl;
        return 0;
    } 
    ColorFactory* ppv;
    IPrint* iP;
    f(CLSIDColor, IID__IClassFactory, (void**)&ppv);
    ppv->CreateInstance(IID__IPrint, (void**)&iP, 120, 230, 34);
    iP->print();
    return 0;
}