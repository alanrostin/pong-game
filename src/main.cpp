#include "Bat.h"
#include <sstream>
#include <cstdlib>
#include <SFML/Graphics.hpp>

int main()
{
    // Create a video mode object
    VideoMode vm(1600, 900);

    // Create and open a window for the game
    RenderWindow window(vm, "Pong", Style::Fullscreen);

    int score = 0;
    int lives = 3;

    // Create a bat at the bottom center of the screen
    Bat bat(1600 / 2, 900 - 20);

    // Create a Text object called HUD
    Text hud;

    // A cool retro-style font
    Font font;
    font.loadFromFile("/home/alanrostin/learn/gamedev/code/game-prog/pong-game/fonts/DS-DIGI.TTF");

    // Set the font to our retro-style
    hud.setFont(font);

    // Make it nice and big
    hud.setCharacterSize(64);

    // Choose a color
    hud.setFillColor(Color::White);

    hud.setPosition(20, 20);

    // Clock for timing everything
    Clock clock;

    while (window.isOpen())
    {
        /*
        ***********************
        Handle the player input
        ***********************
        */
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
            {
                // Quit the game when the window is closed
                window.close();
            }
        }

        // Handle the player quitting
        if (Keyboard::isKeyPressed(Keyboard::Escape))
        {
            window.close();
        }

        // Handle the pressing and releasing of the arrow keys
        if (Keyboard::isKeyPressed(Keyboard::Left))
        {
            bat.moveLeft();
        }
        else
        {
            bat.stopLeft();
        }

        if (Keyboard::isKeyPressed(Keyboard::Right))
        {
            bat.moveRight();
        }
        else
        {
            bat.stopRight();
        }

        /*
        ************************************
        Update the bat, the ball and the HUD
        ************************************
        */

        // Update the delta time
        Time dt = clock.restart();
        bat.update(dt);

        // Update the HUD text
        std::stringstream ss;
        ss << "Score:" << score << "   Lives:" << lives;
        hud.setString(ss.str());

        /*
        **********************************
        Draw the bat, the ball and the HUD
        **********************************
        */
        window.clear();
        window.draw(hud);
        window.draw(bat.getShape());
        window.display();
    }

    return 0;
}