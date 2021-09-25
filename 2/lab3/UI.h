#ifndef UI_h
#define UI_h
#include "Datetime.h"

class UI
{
    public:
        void PrintSystemDate(Datetime date);
        void PrintDateNextPrev(Datetime date, Datetime next, Datetime prev, int i);
        void PrintDateNextPrev(Datetime date, Datetime prev, int i);
    
    private:
        void Output(Datetime date);
};

#endif