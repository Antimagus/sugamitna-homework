#include "Component.h"
#include <iostream>
#include <windows.h>

extern "C" H__RESULT Get__ClassObject(CLS__ID clsid, I__ID iid, void** ppv);

BOOL APIENTRY DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpvReserved)
{
    return true;
}

class Color : public IMix, IPrint
{
    private:
        int countReference = 0;
        int r, g, b;
        bool check(int r, int g, int b);
    public:
        H__RESULT QueryInterface(I__ID iid, void** ppv);
        U__LONG AddRef();
        U__LONG Release();
        void mix(int r, int g, int b);
        void print();
        Color(int r, int g, int b);
};

bool Color::check(int r, int g, int b) 
{
    if (r >= 0 && r <= 255 && g >= 0 && g <= 255 && b >= 0 && b <= 255) return true;
    else return false;
}

Color::Color(int r, int g, int b)
{
    if (check(r, g, b))
    {
        this->r = r;
        this->g = g;
        this->b = b;
    } else throw 0;
}
void Color::mix(int r, int g, int b) 
{
    if (check(r, g, b))
    {
        this->r = (this->r + r) / 2;
        this->g = (this->g + g) / 2;
        this->g = (this->g + g) / 2;
    } else throw 0;

}

void Color::print() 
{
    std::cout << "Color: " << r << " " << g << " " << b << std::endl;
}

U__LONG Color::AddRef() 
{
    countReference++;
    return countReference;
}

U__LONG Color::Release() 
{
    countReference--;
    if(countReference == 0)
    {
        delete this;
    }
    return countReference;
}

H__RESULT Color::QueryInterface(I__ID iid, void** ppv)
{
    switch (iid)
    {
        case IID__IUnknown:
        {
            *ppv = (I__Unknown*) (IMix*) this;
            break;
        }
        case IID__IMix:
        {
            *ppv = (IMix*) this;
            break;
        }
        case IID__IPrint:
        {
            *ppv = (IPrint*) this;
            break;
        }
        default:
        {
            *ppv = 0;
            return E_NOINTERFACE;
        }
    }
    AddRef();
    return S_OK;
}

ColorFactory::ColorFactory()
{

}

U__LONG ColorFactory::AddRef() 
{
    countReference++;
    return countReference;
}

U__LONG ColorFactory::Release() 
{
    countReference--;
    if(countReference == 0)
    {
        delete this;
    }
    return countReference;
}
extern "C" H__RESULT __declspec(dllexport) ColorFactory::CreateInstance(I__ID iid, void** ppv, int r, int g, int b)
{
    Color* color = new Color(r, g, b);
    if (color == 0)
    {
        return E_OUTOFMEMORY;
    }
    H__RESULT res = color->QueryInterface(iid, ppv);
    return res;
}

H__RESULT ColorFactory::QueryInterface(I__ID iid, void** ppv)
{
    if (iid == IID__IUnknown || iid == IID__IClassFactory)
    {
        *ppv = (I__ClassFactory*) this;
    }
    else
    {
        *ppv = 0;
        return E_NOINTERFACE;
    }
    AddRef();
    return S_OK;
}

extern "C" H__RESULT __declspec(dllexport) Get__ClassObject(CLS__ID clsid, I__ID iid, void** ppv)
{
    if(clsid != CLSIDColor)
    {
        return E_CLASSNOTAVAILABLE;
    }
    ColorFactory* factory = new ColorFactory();
    if(factory == 0) 
    {
        return E_OUTOFMEMORY;
    }
    H__RESULT res = factory->QueryInterface(iid, ppv);
    return res;
}

ColorWrapper::ColorWrapper(int r, int g, int b)
{
    Get__ClassObject(CLSIDColor, IID__IClassFactory, (void**)&factory);
    factory->CreateInstance(IID__IMix, (void**)&iMix, r, g, b);
    factory->Release();
    iMix->QueryInterface(IID__IPrint, (void**)&iPrint);
}

ColorWrapper::~ColorWrapper() 
{
    iMix->Release();
    iPrint->Release();
}

void ColorWrapper::print() 
{
    iPrint->print();
}

void ColorWrapper::mix(int r, int g, int b)
{
    iMix->mix(r, g, b);
}