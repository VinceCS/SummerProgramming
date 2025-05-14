#include "page.h"
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
