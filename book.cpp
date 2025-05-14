#include "book.h"
#include <iostream>
using namespace std;

ostream &operator<<(ostream &o, const page &a)
{
    o<<a.PageNumber<<"."<<a.Contents;
    return o;
}

page::page(int number)
{
    PageNumber = number;
    Contents = "Nothing";
}

void page::setContents(const string &Contents)
{
    this->Contents=Contents;
}

string page::getContents() const
{
    return Contents;
}

int page::getPageNumber() const
{
    return PageNumber;
}

book::book()
{
    pages = nullptr;
    size = 0;
}

book::~book()
{
    cout<<"\nDestructor Executed";
    delete[] pages;
}

book::book(const book &a)
{
    size = a.size;
    pages = new page[size];
    for(int i = 0; i<size; i++)
        pages[i] = a.pages[i];
}

book & book::operator=(const book &a)
{
    if (this != &a)
    {
        size = a.size;
        pages = new page[size];
        for(int i = 0; i<size; i++)
            pages[i] = a.pages[i];
    }
    return *this;
}

void book::createPage()
{
    page *temp = new page [size + 1];
    for (int i = 0; i<size; i++)
        temp[i]=pages[i];
    temp[size] = page(size+1);
    delete[] pages;
    pages = temp;
    size++;
}

void book::readBook()
{
    for(int i = 0; i<size; i++)
        cout<<pages[i]<<endl;

}

void book::updatePage(const int &userNumber, const string &Contents)
{
    pages[userNumber-1].setContents(Contents);
}

void book::deletePage(const int &userNumber)
{
    page *temp =  new page [size - 1];
    for (int i = 0, j=0; i<size; i++)
    {
        if (i != (userNumber - 1))
        {
            temp[j]=page(j+1);
            temp[j].setContents(pages[i].getContents());
            j++;
        }
    }
    delete[] pages;
    pages=temp;
    size--;
}
