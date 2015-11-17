#include "Game.h"
#include "TextureManager.hpp"

int main()
{
    Fury::Game game;
    Fury::TextureManager::GetInstance();
    return game.Run();
}
