#include <iostream>
#include "page.h"
using namespace std;

void printMenu();
void createPage(page* &book, const int &size);
void readBook(page* &book, int const &size);
void updatePage(page* &book, const int &userNumber, const string &Contents);
void deletePage(page* &book, const int &userNumber, int const &size);

int main()
{
    int size = 3, choice, userNumber;
    string contents;
    page* book = new page[size];
    for (int i = 0; i<size; i++)
        book[i] = page(i+1);
    while (true)
    {
        printMenu();
        cin>>choice;
        switch (choice)
        {
            case 1:
                createPage(book, size);
                size++;
                break;
            case 2:
                readBook(book, size);
                break;
            case 3:
                cout<<"What page would you like to change?: ";
                cin>>userNumber;
                cout<<"Add the contents for that page: ";
                cin.ignore();
                getline(cin, contents); 
                updatePage(book, userNumber, contents);
                break;
            case 4:
                cout<<"What page would you like to delete?: ";
                cin>>userNumber;
                deletePage(book, userNumber, size);
                size--;
                break;
            case 5:
                delete[] book;
                return 0;
            default:
                cout<<"Invalid choice"<<endl;
        }

    }
    return 0;
}

void printMenu()
{
    cout<<"What do you want to do? \n1.Create a new page \n2.Print all contents of the book \n3.Update the contents of a page \n4.Delete a page \n5.Exit"<<endl;
}

void createPage(page* &book, const int &size)
{
    page *temp = new page [size + 1];
    for (int i = 0; i<size; i++)
        temp[i]=book[i];
    temp[size] = page(size+1);
    delete[] book;
    book = temp;
}

void readBook(page* &book, const int &size)
{
    for(int i = 0; i<size; i++)
        cout<<book[i]<<endl;
}

void updatePage(page* &book, const int &userNumber, const string &Contents)
{
    book[userNumber-1].setContents(Contents);
}

void deletePage(page* &book, const int &userNumber, int const &size)
{

    page *temp =  new page [size - 1];
    for (int i = 0, j=0; i<size; i++)
    {
        if (i != (userNumber - 1))
        {
            temp[j]=page(j+1);
            temp[j].setContents(book[i].getContents());
            j++;
        }
    }
    delete[] book;
    book=temp;
}
