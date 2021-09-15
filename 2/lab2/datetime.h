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

class datetime
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
        void System_time(datetime& system);
        void Get_next_date(datetime& next);
        void Get_prev_date(datetime& prev);

        void Set(int data, int type_of_date);

        int Get(int type_of_date);

};
time_t Get_unix_time(datetime A);
void Get_normal_time(time_t unix_time, datetime& A);
#endif