#include "unknown.h"

const I__ID IID__IUnknown = 0;
const I__ID IID__IClassFactory = 10;

const I__ID IID__IMix = 1;
const I__ID IID__IPrint = 2;
const CLS__ID CLSIDColor = 101;

class IMix: public I__Unknown
{
public:
    virtual void mix(int r, int g, int b) = 0;
};

class IPrint: public I__Unknown
{
public:
    virtual void print() = 0;
};

class ColorFactory : public I__Unknown
{
    private:
        int countReference = 0;
    public:
        H__RESULT CreateInstance(I__ID iid, void** ppv, int r, int g, int b);
        H__RESULT QueryInterface(I__ID iid, void** ppv);
        U__LONG AddRef();
        U__LONG Release();
        ColorFactory();
};

extern "C" H__RESULT Get__ClassObject(CLS__ID clsid, I__ID iid, void** ppv);

class ColorWrapper
{
    private:
        ColorFactory* factory;
        IMix* iMix;
        IPrint* iPrint;

    public:
        void print();
        void mix(int r, int g, int b);
        ColorWrapper(int r, int g, int b);
        ~ColorWrapper();
};