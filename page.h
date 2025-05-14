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
};
