// Chaos_Game.cpp : This file contains the 'main' function. Program execution begins and ends there.
//Eduardo and Jordan
//Need text to user, user inut, (4), vector/array to hold point, vm,while,draw,

#include <iostream>
#include <sstream>
#include <cstdlib>
#include <SFML/Graphics.hpp>


using namespace sf;
using namespace std;

int main()
{


    //Make window
    VideoMode vm(1920, 1080);
    RenderWindow window(vm, "Chaos Game!!!", Style::Fullscreen);

    //CREATE TEXT;
    Text text,dotText;

    Font font;
    font.loadFromFile("fonts/KOMIKAP_.ttf");
    text.setFont(font);
    text.setCharacterSize(25);
    text.setPosition(10,10);
    text.setFillColor(Color::White);
    dotText = text;
    dotText.setPosition(10, 100);

    int inputCounter = 0; //see how many clicks;
    int dotCounter = 0;

    //dots
    RectangleShape dot1,dot2,dot3,dot4;
    dot1.setSize( Vector2f (1,1));
    dot1.setFillColor(Color::White);
    dot2 = dot1;
    dot3 = dot1;
    dot4 = dot1;
    vector<RectangleShape>;


    //control input;
    bool acceptInput = true;



    while (window.isOpen())

    {
        
        int x;
        int y;
        //HANDLE PLAYER INPUT--------ESC
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

        /***************************************************************************
        * First three inputs
        ***************************************************************************/

        if (acceptInput && dotCounter==0)//For the first click, now need 2 more + 1;
        {
            if (event.type == Event::MouseButtonPressed)
            {
                    x = event.mouseButton.x;
                    y = event.mouseButton.y;
                    dot1.setPosition(x, y);
                    inputCounter++;
                    dotCounter++;
                    acceptInput = false;              
            }
        }
        if (acceptInput && dotCounter == 1)
        {
            if (event.type == Event::MouseButtonPressed)
            {
                x = event.mouseButton.x;
                y = event.mouseButton.y;
                dot2.setPosition(x, y);
                inputCounter++;
                dotCounter++;
                acceptInput = false;
            }
        }
        if (acceptInput && dotCounter == 2)
        {
            if (event.type == Event::MouseButtonPressed)
            {
                x = event.mouseButton.x;
                y = event.mouseButton.y;
                dot3.setPosition(x, y);
                inputCounter++;
                dotCounter++;
                acceptInput = false;
            }
        }

        /***************************************************************************
         last input
         ***************************************************************************/
        if (acceptInput && dotCounter == 3)
        {
            if (event.type == Event::MouseButtonPressed)
            {
                x = event.mouseButton.x;
                y = event.mouseButton.y;
                dot4.setPosition(x, y);
                inputCounter++;
                dotCounter++;
                acceptInput = false;
            }
        }









        if (event.type == Event::MouseButtonReleased)//makes it so theres no 100 clicks per second
        {
            acceptInput = true;
        }

        //Output text;
        if(inputCounter <4)
        { 
            text.setString("Welcome to Chaos Game!!! \n   Choose 3 points for triangle");
        }
        if (inputCounter == 3)
        {
            text.setString("Select 4th point to start!");
        }

        stringstream ss;
        ss << "Dot counter: " << dotCounter;
        dotText.setString(ss.str());

       
        
        

        //draw
        window.clear();
        window.draw(text);
        window.draw(dotText);
        window.draw(dot1);
        window.draw(dot2);
        window.draw(dot3);
        window.display();


    }
}







































// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
