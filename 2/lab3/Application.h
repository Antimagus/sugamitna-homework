#ifndef Application_h
#define Application_h
#include "Datetime.h"
#include <string>

using namespace std;

class Application
{
    public:
        void Run(string fileName);
    
    private:
        Datetime* ReadFileDate(string fileName, int& n);
};

#endif