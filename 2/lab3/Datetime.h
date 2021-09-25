#ifndef Datetime_h
#define Datetime_h

enum {
    _hour_,
    _minute_,
    _second_,
    _day_,
    _month_,
    _year_
};

class Datetime
{
    private:
        int hour;
        int minute;
        int second;

        int day;
        int month;
        int year;

    public:
        void SystemTime(Datetime& system);

        void Set(int data, int type_of_date);

        int Get(int type_of_date);

    Datetime(int _hour, int _minute, int _second, int _day, int _month, int _year)
    {
        if(_hour >= 0 && _hour < 24)
        {
            hour = _hour;
        }
        else hour = 0;
        
        if(_minute >= 0 && _minute < 60)
        {
            minute = _minute;
        }
        else minute = 0;

        if(_second >= 0 && _second < 60)
        {
            second = _second;
        }
        else second = 0;

        if(_day > 0 && _day < 32)
        {
            day = _day;
        }
        else day = 1;

        if(_month > 0 && _month < 13)
        {
            month = _month;
        }
        else month = 1;

        if(_year >= 1970)
        {
            year = _year;
        }
        else year = 1970;
    }
    Datetime() {}
    ~Datetime() {}
};

class DatetimeRandom
{
    public:
        Datetime date;
        Datetime NextDate();
        Datetime PrevDate();

    private:
        tm timeinfo;
        time_t unixTime;
        Datetime newDate;
        int min = 2419200 * 2;
        int max = 31536000;

        void GetUnixTime();
        void GetNormalTime();
};

#endif