#include <iostream>
using namespace std;
class date
{
    private:
    int day, month, year;
    
    public:
    date();
    date(int year);
    date(int day, int month, int year);

    int GetDay();
    int GetMonth();
    int GetYear();
    void SetDay(int day);
    void SetMonth(int month);
    void SetYear(int year);

    friend bool operator<(date a, date b);
    friend bool operator>(date a, date b);
    friend bool operator<=(date a, date b);
    friend bool operator>=(date a, date b);
    friend bool operator==(date a, date b);
    friend bool operator!=(date a, date b);
    
    int operator- (date b);

    friend ostream &operator<<(ostream &o, date a);
};
