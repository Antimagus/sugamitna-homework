#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <time.h>
#include "datetime.h"

using namespace std;

datetime* Read_file_date(string file_name, int& n)
{
    int hour, minute, second, day, month, year;
    ifstream file(file_name);
    string line;
    n = 0;
    while (getline(file, line))
    {
        n++;
    }
    datetime* Date = new datetime[n];
    int i = 0;
    file.clear();
    file.seekg(0, ios::beg);
    while (getline(file, line))
    {
        istringstream line_(line);
        line_ >> hour >> minute >> second >> day >> month >> year;
        Date[i].Set(hour, _hour_);
        Date[i].Set(minute, _minute_);
        Date[i].Set(second, _second_);
        Date[i].Set(day, _day_);
        Date[i].Set(month, _month_);
        Date[i].Set(year, _year_);
        i++;
    }
    file.close();
    return Date;
}

int main()
{
    srand(time(0));
    datetime date, next, prev;
    int n;
    datetime* Date = Read_file_date("data.txt", n);
    datetime* Prev = new datetime[n];
    date.System_time(date); printf("\n\nSystem time: "); date.Output();
    printf("\n\n\tData read from file:\n\n");
    for (int i = 0; i < n; i++)
    {
        Date[i].Get_next_date(next);
        Date[i].Get_prev_date(prev);
        printf("%i)\t", i + 1);
        Date[i].Output(); 
        printf("\t");
        next.Output();
        printf("\t");
        prev.Output();
        printf("\n");
        Prev[i] = prev;
    }
    printf("\n\tVariant 8:\n\n");
    for (int i = 0; i < n; i++)
    {
        if (Date[i].Get(_year_) == Prev[i].Get(_year_))
        {
            printf("%i)\t", i + 1);
            Date[i].Output(); 
            printf("\t");
            prev.Output();
            printf("\n");
        }
    }
    delete[] Date;
    delete[] Prev;
    return 0;
}
