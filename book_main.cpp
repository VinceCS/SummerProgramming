#include "book.h"
#include <iostream>
using namespace std;
void printMenu();
int main()
{
    book a;
    book b;
    int choice;
    int userNumber;
    string contents;
    while (true)
    {
        printMenu();
        cin>>choice;
        switch(choice)
        {
            case 1:
                a.createPage();
                break;
            case 2:
                a.readBook();
                break;
            case 3:
                cout<<"What page number do you want to update?: ";
                cin>>userNumber;
                cout<<"Enter the new contents: ";
                cin.ignore();
                getline(cin,contents);
                a.updatePage(userNumber, contents);
                break;
            case 4:
                cout<<"What page number do you want to delete?: ";
                cin>>userNumber;
                a.deletePage(userNumber);
                break;
            case 5:
                return 0;
            case 6:
                b=a;
                b.readBook();
                return 0;
            case 7:
            {
                book c(a);
                c.readBook();
            }
                return 0;
            default:
                cout<<"Invalid choice"<<endl;
        }
    }
}
void printMenu()
{
    cout<<"What do you want to do? \n1.Create a new page \n2.Print all contents of the book \n3.Update the contents of a page \n4.Delete a page \n5.Exit \n6.Paste it into book 2 and Exit (Assignment Operator) \n7.Paste it into book 2 and Exit (Deep Copy Constructor)"<<endl;
}
