// Chapter06vs.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "Ball.h"
#include "Bat.h"
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <SFML/Graphics.hpp>

using namespace std;

int main()
{
    VideoMode vm(1920, 1080);
    RenderWindow window(vm, "Pong", Style::Fullscreen);
    int score = 0;
    int lives = 3;

    Bat bat(1920 / 2, 1080 - 20);
    Ball ball(1920 / 2, 0);

    Text hud;
    Font font;
    font.loadFromFile("fonts/DS-DIGIT.TTF");
    hud.setFont(font);
    hud.setCharacterSize(75);
    hud.setPosition(20, 20);
    hud.setFillColor(Color::White);

    Clock clock;

    while (window.isOpen())
    {
        //HANDLE PLAYER INPUT
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
            {
                window.close();
            }
        }
        if (Keyboard::isKeyPressed(Keyboard::Escape))
        {
            window.close();
        }
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

        //Update objects

        Time dt = clock.restart();
        bat.update(dt);

        ball.update(dt);

        stringstream ss;
        ss << "Score:" << score << "     Lives: " << lives;
        hud.setString(ss.str());

        //handle ball hitting the bottom

        if (ball.getPosition().top > window.getSize().y)
        {
            ball.reboundBottom();
            lives--;

            if (lives < 1)
            {
                score = 0;
                lives = 3;
            }
        }

        //Handle ball hitting top

        if (ball.getPosition().top < 0)
        {
            ball.reboundBatOrTop();
        }

        //Handle sides

        if (ball.getPosition().left<0 || (ball.getPosition().left + ball.getPosition().width) > window.getSize().x)
        {
            ball.reboundSides();
        }

        //has the ball hit the bat?

        if (ball.getPosition().intersects(bat.getPosition()))
        {
            ball.reboundBatOrTop();
            score++;
        }

        ///Draw

        window.clear();
        window.draw(hud);
        window.draw(bat.getShape());
        window.draw(ball.getShape());
        window.display();


    }


}
