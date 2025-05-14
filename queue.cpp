#include <iostream>
#include "queue.h"
using namespace std;

template<class T>
QuickQueue<T>::QuickQueue()
{
    current = 0;
    size = MAX;
    array = new T*[MAX];
}

template <class T>
QuickQueue<T>::~QuickQueue()
{
    for(int i=0; i<current; i++)
        delete array[i];
    delete [] array;
}

template <class T>
bool QuickQueue<T>::Enqueue(T item)
{
    if (current < size)
    {
        array[current] = new T;
        *array[current] = item;
        current++;
        return true;
    }
    else
        return false;
}

template <class T>
T* QuickQueue<T>::Dequeue(unsigned int n)
{
    if(n>=current)
        return nullptr;

    T* value =  array[n];
    for(int i = n; i<current; i++)
        array[i]= array[i+1];
    current--;
    return value;
}

template<class T>
void QuickQueue<T>::Print()
{
    if(current==0)
    {
        cout<<"Empty List"<<endl;
        return;
    }
    for (int i = 0; i<current; i++)
    {    
        cout<<*array[i]<<' ';
    }
    cout<<endl;
}

template <class T>
QuickQueue<T>::QuickQueue(const QuickQueue<T> &a)
{
    size=a.size;
    current = a.current;
    array = new T*[size];
    for(int i = 0; i<current; i++)
        array[i]= new T (*a.array[i]);
}


template <class T>
QuickQueue<T>& QuickQueue<T>::operator=(const QuickQueue<T> &a)
{
    if(this != &a)
    {
        size = a.size;
        current = a.current;
        for(int i=0; i<current; i++)
            delete array[i];
        delete [] array;

        array = new T*[size];
        for(int i = 0; i<size; i++)
            array[i]= new T(*a.array[i]);
    }
    return *this;
}

template class QuickQueue<int>;
template class QuickQueue<double>;
