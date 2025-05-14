#include <iostream>
#include <cstdlib>
#include <ctime>
#include "treasure.h"

using namespace std;

int main()
{
    int xPrize, yPrize;
    srand(time(NULL));

    xPrize = rand();
    yPrize = rand();

    if (xPrize < 0)
        xPrize=xPrize*-1;
    if(yPrize < 0)
        yPrize=yPrize*-1;

    while(xPrize>9)
        xPrize=xPrize%10;

    if (xPrize == 0)
        while(yPrize>9 || yPrize<1)
        {
            yPrize=yPrize%10;
            if (yPrize==0)
            {
                yPrize=rand();
                if(yPrize<0)
                    yPrize=yPrize*-1;
            }
        }
    else
        while(yPrize>9 || yPrize<0)
            yPrize=yPrize%10;
    Player one;
    char direction;
    double preDis;
    cout<<"You are in a 10x10 grid with the position ("<<one.xCoord<<","<<one.yCoord<<")"<<endl;
    preDis = one.calcDist(one.xCoord, one.yCoord, xPrize, yPrize);
    do
    {
        cout<<"Choose a direction to move one space towards (Enter N, S, E, or W): ";
        cin>>direction;
        one.Move(direction);
        one.dist = one.calcDist(one.xCoord, one.yCoord, xPrize, yPrize);
        if (one.dist>preDis)
            cout<<"You are colder"<<endl;
        else if (preDis>one.dist)
            cout<<"You are warmer"<<endl;
        cout<<"Your coordinates are now: ("<<one.xCoord<<","<<one.yCoord<<")"<<endl;
        preDis=one.dist;
    } while (one.xCoord != xPrize || one.yCoord != yPrize);
    cout<<"You win!"<<" The treasure was in ("<<xPrize<<","<<yPrize<<")"<<endl;
    return 0;
}
