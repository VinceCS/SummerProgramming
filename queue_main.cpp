#include <iostream>
#include "queue.h"

using namespace std;

int main()
{
    QuickQueue <int> list1;
    for(int i = 0; i<8; i++)
        list1.Enqueue(i*3);
    cout<<"\nEntire list is: \n";
    list1.Print();
    cout<<"\n";

    QuickQueue<double>list2;
    for (int i = 0; i<9; i++)
        list2.Enqueue((i*1.1));
    
    cout<<"Entire list of doubles"<<endl;
    list2.Print();

    list2.Dequeue(3);
    cout<<"\nEntire list of doubles (after dequeuing the third index): "<<endl;
    list2.Print();
    
    list2.Enqueue(9*3);
    cout<<"\nList after enqueuing 27"<<endl;
    list2.Print();
    return 0;
}
