#include <iostream>
#include <time.h>
#include "Datetime.h"

void DatetimeRandom::GetUnixTime()
{
    timeinfo.tm_year = date.Get(_year_) - 1900;
    timeinfo.tm_mon = date.Get(_month_) - 1;
    timeinfo.tm_mday = date.Get(_day_);
    timeinfo.tm_hour = date.Get(_hour_);
    timeinfo.tm_min = date.Get(_minute_);
    timeinfo.tm_sec = date.Get(_second_);
    unixTime = mktime(&timeinfo);
}

void DatetimeRandom::GetNormalTime()
{
    localtime_s(&timeinfo, &unixTime);
    newDate.Set(timeinfo.tm_hour, _hour_);
    newDate.Set(timeinfo.tm_min, _minute_);
    newDate.Set(timeinfo.tm_sec, _second_);
    newDate.Set(timeinfo.tm_mday, _day_);
    newDate.Set(timeinfo.tm_mon + 1, _month_);
    newDate.Set(timeinfo.tm_year + 1900, _year_);
}

Datetime DatetimeRandom::NextDate()
{
    GetUnixTime();
    unixTime += min + rand() % (max - min + 1);
    GetNormalTime();
    return newDate;
}

Datetime DatetimeRandom::PrevDate()
{
    GetUnixTime();
    unixTime -= min + rand() % (max - min + 1);
    GetNormalTime();
    return newDate;
}

void Datetime::Set(int data, int type_of_date)
{
    switch (type_of_date)
    {
    case 0:
        hour = data;
        break;
    case 1:
        minute = data;
    case 2:
        second = data;
    case 3:
        day = data;
    case 4:
        month = data;
    case 5:
        year = data;
    default:
        break;
    }
}

int Datetime::Get(int type_of_date)
{
    switch (type_of_date)
    {
    case 0:
        return hour;
    case 1:
        return minute;
    case 2:
        return second;
    case 3:
        return day;
    case 4:
        return month;
    case 5:
        return year;
    default:
        return 0;
    }
}

void Datetime::SystemTime(Datetime& system)
{
    time_t rawtime;
    tm timeinfo;
    time(&rawtime);
    localtime_s(&timeinfo, &rawtime);
    system.hour = timeinfo.tm_hour;
    system.minute = timeinfo.tm_min;
    system.second = timeinfo.tm_sec;
    system.day = timeinfo.tm_mday;
    system.month = timeinfo.tm_mon + 1;
    system.year = timeinfo.tm_year + 1900;
}