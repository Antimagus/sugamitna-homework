#ifndef A_h
#define A_h

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
        void Output();
        void System_time(Datetime& system);
        void Get_next_date(Datetime& next);
        void Get_prev_date(Datetime& prev);

        void Set(int data, int type_of_date);

        int Get(int type_of_date);

};
time_t Get_unix_time(Datetime A);
void Get_normal_time(time_t unix_time, Datetime& A);
#endif