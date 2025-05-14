#include "treasure.h"
#include <iostream>
#include <cmath>
using namespace std;

void Player::Move(char direction)
{
    switch (direction)
    {
        case 'N':
            if(yCoord>0)
                yCoord--;
            break;
        case 'S':
            if(yCoord<9)
                yCoord++;
            break;
        case 'E':
            if (xCoord<9)
                xCoord++;
            break;
        case 'W':
            if (xCoord>0)
                xCoord--;
            break;
        default:
            cout<<"Invalid case, please enter again: ";
            break;
    }
}

double Player::calcDist(int x, int y, int xPrize, int yPrize)
{
    double dist;
    dist = sqrt(pow((xCoord-xPrize),2)+(pow((yCoord-yPrize),2)));
    return dist;
}
