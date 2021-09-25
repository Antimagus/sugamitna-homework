#include <iostream>
#include "UI.h"

void UI::Output(Datetime date)
{
    printf("%i:%i:%i %i/%i/%i", date.Get(_hour_), date.Get(_minute_), date.Get(_second_),date.Get(_day_), date.Get(_month_), date.Get(_year_));
}

void UI::PrintDateNextPrev(Datetime date, Datetime next, Datetime prev, int i)
{
    printf("%i)\t", i + 1);
    Output(date);
    printf("\t");
    Output(next);
    printf("\t");
    Output(prev);
    printf("\n");
}

void UI::PrintDateNextPrev(Datetime date, Datetime prev, int i)
{
    printf("%i)\t", i + 1);
    Output(date);
    printf("\t");
    Output(prev);
    printf("\n");
}

void UI::PrintSystemDate(Datetime date)
{
    printf("\n\nSystem time: "); 
    Output(date);
};