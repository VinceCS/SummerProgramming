#include "game.h"
#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;
int main()
{
    srand(time(NULL));
    int picked = rand();

    int num;
    cout<<"How many players are playing duck duck goose?: ";
    cin>>num;

    Player **players =  new Player*[num];
    
    if (picked < 0)
        picked = picked*-1;
    picked = rand()%num;

    Player *p = new Player;
    Player *d = new Duck;
    Player *g = new Goose;

    for (int i = 0; i<num; i++)
    {
        if(i!=picked)
            players[i] = d;
        else
            players[i] = g;
    }

    for (int i = 0; i<num; i++)
        players[i]->display();

    delete p;
    delete d;
    delete g;
    delete [] players;

    return 0;

}

