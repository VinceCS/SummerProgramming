#include <iostream>
#include "date.h"
using namespace std;

void menu();

int main()
{
    int choice, day, month, year;
    date a, b;

    while(true)
    {
        menu();
        cin>>choice;
        switch (choice)
        {
            case 1:
                a = date();
                cout<<"Default Date is set";
                break;
            case 2:
                cout<<"Enter year: ";
                cin>>year;
                a = date(year);
                cout<<"Year is set"<<endl;
                break;
            case 3:
                cout<<"Enter day, month, and year";
                cin>>day>>month>>year;
                a = date(day, month, year);
                cout<<"Date is set"<<endl;
                break;
            case 4:
                cout<<"Enter a date to be compared: ";
                cin>>day>>month>>year;
                b = date(day,month,year);
                cout<<"Date 1 is greater than Date 2: "<<(a>b)<<endl;
                cout<<"Date 1 is less than Date 2: "<<(a<b)<<endl;
                cout<<"Date 1 is greater than or equal to Date 2: "<<(a>=b)<<endl;
                cout<<"Date 1 is less than or equal to Date 2: "<<(a<=b)<<endl;
                cout<<"Date 1 is equal to Date 2: "<<(a==b)<<endl;
                cout<<"Date 1 is not equal to Date 2: "<<(a!=b)<<endl;
                break;
            case 5:
                cout<<"Enter a date to be subtracted from original (must be greater): ";
                cin>>day>>month>>year;
                b = date(day,month,year);
                cout<<"There are "<<(b-a)<<" days in between"<<endl;
                break;
            case 6:
                cout<<a<<endl;
                break;
            case 7:
                return 0;
            default:
                cout<<"Invalid choice"<<endl;
        }
    }

    return 0;
}

void menu()
{
    cout<<"Welcome to the date program what do you want to do?";
    cout<<"\n1.Create a default date (1/1/1900)";
    cout<<"\n2.Create a date with a specific year";
    cout<<"\n3.Create a date (Day, Month, Year)";
    cout<<"\n4.Show all the comparisons between 2 dates (Make sure you have created a date)";
    cout<<"\n5.Calculate difference between 2 dates";
    cout<<"\n6.Display Date";
    cout<<"\n7.Exit"<<endl;

}
