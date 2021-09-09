#include <iostream>
#include <ctime>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

struct datetime
{
    int hour;
    int minute;
    int second;
    
    int day;
    int month;
    int year;

    void Get_next_date(datetime& next);
    void Get_prev_date(datetime& prev);
    void System_time(datetime& system);

    void Output();
};

void Get_normal_time(time_t unix_time, datetime& A);
time_t Get_unix_time(datetime A);

void datetime::Get_next_date(datetime& next)
{
    Get_normal_time(Get_unix_time(*this) + 86400, next);
}

void datetime::Get_prev_date(datetime& prev)
{
    Get_normal_time(Get_unix_time(*this) - 86400, prev);
}

void datetime::Output()
{
    printf("%i:%i:%i %i/%i/%i", hour, minute, second, day, month, year);
}

void datetime::System_time(datetime& system)
{
    time_t now = time(0);
    tm *ltm = localtime(&now);
    system.hour = ltm->tm_hour;
    system.minute = ltm->tm_min;
    system.second = ltm->tm_sec;
    
    system.day = ltm->tm_mday;
    system.month = ltm->tm_mon + 1;
    system.year = ltm->tm_year + 1900;
}

time_t Get_unix_time(datetime A)
{
    time_t now = time(0);
    tm *ltm;
    time(&now);
    ltm = localtime(&now);
    ltm->tm_year = A.year - 1900;
    ltm->tm_mon = A.month - 1;    
    ltm->tm_mday = A.day;          
    ltm->tm_hour = A.hour;         
    ltm->tm_min = A.minute;          
    ltm->tm_sec = A.second;  
    time_t unix_time = mktime (ltm);
    return unix_time;
}

void Get_normal_time(time_t unix_time, datetime& A)
{
    tm *ltm = localtime(&unix_time);
    A.hour = ltm->tm_hour;
    A.minute = ltm->tm_min;
    A.second = ltm->tm_sec;
    
    A.day = ltm->tm_mday;
    A.month = ltm->tm_mon + 1;
    A.year = ltm->tm_year + 1900;
}

datetime* Read_file_date(string file_name, int& n)
{
    ifstream file(file_name);
    string line;
    n = 0;
    while(getline(file, line))
    {
        n++;
    }
    datetime* Date = new datetime[n];
    int i = 0;
    file.close();
    ifstream file2(file_name);
    while(getline(file2, line))
    {
        istringstream line_(line);
        line_ >> Date[i].hour >> Date[i].minute >> Date[i].second >> Date[i].day >> Date[i].month >> Date[i].year;
        i++;
    }
    file2.close();
    return Date;
}

int main()
{
    datetime date;
    int n;
    datetime* Date = Read_file_date("data.txt", n);
    for(int i = 0; i < n; i++)
    {
        cout << i + 1 << ")\t"; Date[i].Output(); cout << "\t"; Date[i].Get_next_date(date); date.Output(); 
        cout << "\t"; Date[i].Get_prev_date(date); date.Output(); cout << endl;
    }
    delete[] Date;
    return 0;
}
