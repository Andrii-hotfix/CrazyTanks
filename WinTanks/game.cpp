#include "game.h"
#include <iostream>

using namespace std;

Game::Game()
{
    walls = nullptr;
}

void Game::exec()
{
  Map b(60, 25);
  Wall a(1, 1, 20);
  cin.ignore();
//  a.destroy();
}
