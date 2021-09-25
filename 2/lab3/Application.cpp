#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <time.h>
#include "Application.h"
#include "UI.h"

using namespace std;

void Application::Run(string fileName)
{
    srand(time(0));
    Datetime date, next, prev;
    DatetimeRandom randomDate;
    UI ui;
    int n;
    Datetime* Date = ReadFileDate(fileName, n);
    Datetime* Prev = new Datetime[n];
    date.SystemTime(date);
    ui.PrintSystemDate(date);
    printf("\n\n\tData read from file:\n\n");
    for (int i = 0; i < n; i++)
    {
        randomDate.date = Date[i];
        next = randomDate.NextDate();
        prev = randomDate.PrevDate();
        Prev[i] = prev;
        ui.PrintDateNextPrev(Date[i], next, prev, i);
    }
    printf("\n\tVariant 8:\n\n");
    for (int i = 0; i < n; i++)
    {
        if (Date[i].Get(_year_) == Prev[i].Get(_year_))
        {
            ui.PrintDateNextPrev(Date[i], Prev[i], i);
        }
    }
    delete[] Date;
    delete[] Prev;
}

Datetime* Application::ReadFileDate(string fileName, int& n)
{
    int hour, minute, second, day, month, year;
    ifstream file(fileName);
    string line;
    n = 0;
    while (getline(file, line))
    {
        n++;
    }
    Datetime* Date = new Datetime[n];
    int i = 0;
    file.clear();
    file.seekg(0, ios::beg);
    while (getline(file, line))
    {
        istringstream line_(line);
        line_ >> hour >> minute >> second >> day >> month >> year;
        Date[i] = Datetime(hour, minute, second, day, month, year);
        i++;
    }
    file.close();
    return Date;
}