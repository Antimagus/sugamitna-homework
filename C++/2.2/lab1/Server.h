#include "IServer.h"

class Server : public IServer{   
private:
    int a;
    int b;
    int c;
    
public:
    void Func();
    Server();
    ~Server();
};