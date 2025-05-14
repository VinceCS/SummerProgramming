using namespace std;
class Player
{
    public:
        //state
        int xCoord = 0;
        int yCoord = 0;
        double dist;

        //behavior
        void Move(char direction);
        double calcDist(int x, int y, int prizeX, int prizeY);

    private:

};
