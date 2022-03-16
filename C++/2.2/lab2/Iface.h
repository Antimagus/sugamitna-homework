#include "I_Unknown.h"

class IServer : public I_Unknown
{
public:
    virtual void Func() = 0;
};

class IServer2 : public I_Unknown
{
public:
    virtual void Func2() = 0;
};

class IServerFactory : public I_ClassFactory 
{
    public:
        IServerFactory() {};
        H_RESULT QueryInterface(I_ID iid, void** ppv);
        H_RESULT CreateInstance(I_ID iid, void** ppv);
};

H_RESULT GetClassObject(CLS_ID clsid, I_ID iid, void** ppv);
