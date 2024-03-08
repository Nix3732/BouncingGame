#include "Ball.hpp"
#include "Game.hpp"
#include "Block.hpp"
#include <iostream>

int main()
{   
    ez::Game Game(1000, 1000, "Bouncing Game");
    Game.set();
    Game.life();

}