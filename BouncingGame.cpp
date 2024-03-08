#include "Ball.hpp"
#include "Game.hpp"

int main()
{   
    int a = 2;
    ez::Game Game(1600, 900, "Bouncing Game");
    Game.set(a);
    Game.life();

}