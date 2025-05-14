#include <iostream>
using namespace std;
class page
{
    private:
    int PageNumber;
    string Contents;

    public:
    friend ostream &operator<<(ostream &o, const page &a);
    page(int number = 1);
    void setContents(const string &Contents);
    string getContents() const;
    int getPageNumber() const;
};

class book
{
    private:
    page* pages;
    int size;

    public:
    book();
    ~book();
    book(const book &a);
    book &operator=(const book &a);

    void createPage();
    void readBook();
    void updatePage(const int &userNumber, const string &Contents);
    void deletePage(const int &userNumber);
};
