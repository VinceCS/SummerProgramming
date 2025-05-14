#include "date.h"
#include <iostream>
#include <cmath>
using namespace std;

date::date()
{
    month = 1;
    day = 1;
    year = 1900;
}

date::date(int year)
{
    month = 1;
    day = 1;
    if (year<1900)
    {
        cout<<"Invalid year";
        this-> year = 1900;
    }
    else
        this -> year = year;
}

date::date(int day, int month, int year)
{
    int calender[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (year%4==0)
        if (year%100!=0 || year%400==0)
            calender[1] = 29;
    
    if (year<1900 || month<1 || month>12 || day<1 || day>(calender[month-1]))
    {
        cout<<"Invalid date";
        this->day=1;
        this->month=1;
        this->year=1900;
    }
    else
    {
        this -> day = day;
        this -> month = month;
        this -> year = year;
    }
}

int date::GetDay()
{
    return day;
}

int date::GetMonth()
{
    return month;
}

int date::GetYear()
{
    return year;
}

void date::SetDay(int day)
{
    int calender[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (year%4==0)
        if (year%100!=0 || year%400==0)
            calender[1] = 29;
    if (day>=1 && day<=(calender[month-1]))
        this ->day=day;
    else
        cout<<"Invalid day";
}

void date::SetMonth(int month)
{
    if(month>=1 && month<=12)
        this ->month=month;
    else
        cout<<"Invalid Month";
}

void date::SetYear(int year)
{
    if (year>=1900)
        this ->year=year;
    else
        cout<<"Invalid Year";
}

bool operator<(date a, date b)
{
    if (a.GetYear() < b.GetYear())
        return true;
    if (a.GetYear() > b.GetYear())
        return false;
    if (a.GetYear() == b.GetYear())
    {
        if (a.GetMonth() < b.GetMonth())
            return true;
        if (a.GetMonth() > b.GetMonth())
            return false;
        if (a.GetMonth() == b.GetMonth())
        {
            if (a.GetDay() < b.GetDay())
                return true;
            if (a.GetDay() > b.GetDay())
                return false;
            if (a.GetDay() == b.GetDay())
                return false;
        }
    }
    return false;
}

bool operator>(date a, date b)
{
    if (a.GetYear() > b.GetYear())
        return true;
    if (a.GetYear() < b.GetYear())
        return false;
    if (a.GetYear() == b.GetYear())
    {
        if (a.GetMonth() > b.GetMonth())
            return true;
        if (a.GetMonth() < b.GetMonth())
            return false;
        if (a.GetMonth() == b.GetMonth())
        {
            if (a.GetDay() > b.GetDay())
                return true;
            if (a.GetDay() < b.GetDay())
                return false;
            if (a.GetDay() == b.GetDay())
                return false;
        }
    }
    return false;
}

bool operator<=(date a, date b)
{
    if (a.GetYear() < b.GetYear())
        return true;
    if (a.GetYear() > b.GetYear())
        return false;
    if (a.GetYear() == b.GetYear())
    {
        if (a.GetMonth() < b.GetMonth())
            return true;
        if (a.GetMonth() > b.GetMonth())
            return false;
        if (a.GetMonth() == b.GetMonth())
        {
            if (a.GetDay() < b.GetDay())
                return true;
            if (a.GetDay() > b.GetDay())
                return false;
            if (a.GetDay() == b.GetDay())
                return true;
        }
    }
    return false;
}

bool operator>=(date a, date b)
{
    if (a.GetYear() > b.GetYear())
        return true;
    if (a.GetYear() < b.GetYear())
        return false;
    if (a.GetYear() == b.GetYear())
    {
        if (a.GetMonth() > b.GetMonth())
            return true;
        if (a.GetMonth() < b.GetMonth())
            return false;
        if (a.GetMonth() == b.GetMonth())
        {   
            if (a.GetDay() > b.GetDay())
                return true;
            if (a.GetDay() < b.GetDay())
                return false;
            if (a.GetDay() == b.GetDay())
                return true;
        }   
    }   
    return false;
}

bool operator==(date a, date b)
{
    if (a.year==b.year)
        if (a.month==b.month)
            if (a.day==b.day)
                return true;
    return false;
}

bool operator!=(date a, date b)
{
    if (a.GetYear() != b.GetYear())
        return true;
    else if (a.GetMonth() != b.GetMonth())
        return true;
    else if (a.GetDay() !=  b.GetDay())
        return true;
    return false;
}

int date::operator- (date b)
{
    date a = *this;
    int sum = 0;
    int calender[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    
    if (a.GetMonth() == 2)
        if (a.GetDay() == 29)
        {
            a.SetDay(28);
        }

    if (b.GetMonth() == 2)
        if (b.GetDay() == 29)
        {
            b.SetDay(28);
            sum +=1;
        }

    if (a.GetMonth() < b.GetMonth())
    {
        for(int i = a.GetMonth(); i<=b.GetMonth(); i++)
        {
            if(i == a.GetMonth())
                sum += (calender[i-1]-a.GetDay());
            else if (i == b.GetMonth())
                sum += b.GetDay();
            else
                sum +=calender[i-1];
        }
    }

    if (a.GetMonth() > b.GetMonth())
    {
        for (int i = a.GetMonth(); i>=b.GetMonth(); i--)
        {
            if (i == a.GetMonth())
                sum += a.GetDay();
            else if (i== b.GetMonth())
                sum += (calender[i-1]-b.GetDay());
            else
                sum += calender[i-1];
        }
    }

    if (a.GetMonth() == b.GetMonth())
        if (a.GetDay() > b.GetDay())
            sum += (a.GetDay()-b.GetDay());
        else if (a.GetDay() == b.GetDay())
            sum += 0;
        else if (b.GetDay() > a.GetDay()) 
            sum -= (b.GetDay()-a.GetDay());

    int c, count = 0;
    c = b.GetYear()-a.GetYear();
    for (int i = a.GetYear(); i<b.GetYear(); i++)
    {
        if (i%4==0)
            if (i%100!= 0 || i%400==0)
                count++;
    }
    
    if (b.GetYear() % 4 ==0)
        if (b.GetYear() % 100 != 0 || b.GetYear() % 400 == 0)
            if (b.GetMonth() > 2)
                    sum+=1;
    
    sum += (c*365);
    sum += count;
    return abs(sum);
}

ostream &operator<<(ostream &o, date a)
{
    int choice = a.GetMonth();
    switch (choice)
    {
        case 1:
            o<<"January "<<a.GetDay()<<", "<<a.GetYear();
            break;
        case 2:
             o<<"February "<<a.GetDay()<<", "<<a.GetYear();
             break;
        case 3:
            o<<"March "<<a.GetDay()<<", "<<a.GetYear();
            break;
        case 4:
            o<<"April "<<a.GetDay()<<", "<<a.GetYear();
            break;
        case 5:
            o<<"May "<<a.GetDay()<<", "<<a.GetYear();
            break;
        case 6:
            o<<"June "<<a.GetDay()<<", "<<a.GetYear();
            break;
        case 7:
            o<<"July "<<a.GetDay()<<", "<<a.GetYear();
            break;
        case 8:
            o<<"August "<<a.GetDay()<<", "<<a.GetYear();
            break;
        case 9:
            o<<"September "<<a.GetDay()<<", "<<a.GetYear();
            break;
        case 10:
            o<<"October"<<a.GetDay()<<", "<<a.GetYear();
            break;
        case 11:
            o<<"November "<<a.GetDay()<<", "<<a.GetYear();
            break;
        case 12:
            o<<"December "<<a.GetDay()<<", "<<a.GetYear();
            break;
        default:
            o<<"Invalid Month";
            break;
    }
    return o;
}
