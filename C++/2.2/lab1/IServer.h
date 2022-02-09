class IServer{
public:
    virtual void Func() = 0;
};

IServer* CreateInstance();