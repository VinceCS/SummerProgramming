#include <iostream>
using namespace std;

const int MAX = 10;

template <class T>
class QuickQueue
{
    public:
        QuickQueue();
        ~QuickQueue();
        bool Enqueue (T item);
        T* Dequeue(unsigned int n);
        void Print();
        QuickQueue(const QuickQueue<T> &a);
        QuickQueue<T> &operator= (const QuickQueue<T> &a);

    private:
        T** array;
        int current;
        int size;
};
