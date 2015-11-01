#include "Game.h"
#include <SFML/Window/Event.hpp>
#include "Constants.h"
#include "InGameState.h"

namespace Fury
{
    Game::Game() : window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Fury"), state(new InGameState(this))
    {
        window.setFramerateLimit(60);
        if (!state->Init())
        {
            delete state;
            state = nullptr;
            window.close();
        }
    }

    Game::~Game()
    {
        if (state != nullptr)
            delete state;
    }

    void Game::Quit()
    {
        window.close();
    }

    int Game::Run()
    {
        while (window.isOpen())
        {
            ManageInput();
            Update();
            Draw();
        }
        return EXIT_SUCCESS;
    }

    void Game::ManageInput()
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        state->ManageInput(window);
    }

    void Game::Update()
    {
        state->Update();
    }

    void Game::Draw()
    {
        window.clear(sf::Color::Green);

        window.draw(*state);

        window.display();
    }
}
