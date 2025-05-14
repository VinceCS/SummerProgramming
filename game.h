class Player
{
    public:
        virtual void display();
};

class Duck:public Player
{
    public:
        virtual void display();
};

class Goose:public Player
{
    public:
        virtual void display();
};
