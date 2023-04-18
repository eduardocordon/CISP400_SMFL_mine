
// Chaos_Game.cpp : This file contains the 'main' function. Program execution begins and ends there.
//Eduardo and Jordan
//Need text to user, user inut, (4), vector/array to hold point, vm,while,draw,

#include <iostream>
#include <sstream>
#include <cstdlib>
#include <SFML/Graphics.hpp>


using namespace sf;
using namespace std;

float lerp(float a, float b, float f)
{
    return a + f * (b - a);
}

int main()
{
    VideoMode vm(1920, 1080);                        //Make window
    RenderWindow window(vm, "Chaos Game!!!", Style::Fullscreen);

    Text text,dotText;                               //CREATE TEXT; ,,INSTRUCTION AND COUNTER 
    Font font;
    font.loadFromFile("fonts/KOMIKAP_.ttf");        
    text.setFont(font);
    text.setCharacterSize(25);
    text.setPosition(10,10);
    text.setFillColor(Color::White);
    dotText = text;
    dotText.setPosition(10, 100);

    int dotCounter = 0;                             //see how many clicks;

    //dots
    RectangleShape dot1;                            //Object to create dots
    dot1.setSize( Vector2f (1,1));                  //dots1 used as base for first 4 clicks
    dot1.setFillColor(Color::White);
    vector<RectangleShape> dotList;
    
    int rng;                                        //rng number

    bool acceptInputMouse = true;                       //control input;
   
    Vector2f temp,temp2;    

    Color red(255, 0, 0);
    Color blue(0, 0, 255);
    Color green(0, 255, 0);
    Color yellow(255, 255, 0);
    Color pink(255, 0, 255);
    Color orange(255, 128, 0);

    bool isTriangle = false;                        //List for input;
    bool isPent = false;
    bool isHex = false;



    while (window.isOpen())                                         //Frame loop starts
    {
        float x,y;                                                    //Coordinates for points
      
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)                        //Close for red X 
            {
                window.close();
            }
        }
        //ESC TO CLOSE
        if (Keyboard::isKeyPressed(Keyboard::Escape))               //ESC TO CLOSE
        {
            window.close();
        }
        if (Keyboard::isKeyPressed(Keyboard::Q))
        {
            isTriangle = true;

        }
        if (Keyboard::isKeyPressed(Keyboard::W))
        {
            isPent = true;

        }
        if (Keyboard::isKeyPressed(Keyboard::E))
        {
            isHex = true;

        }

        /***************************************************************************
         First 3 inputs + 1 to start
        ***************************************************************************/

        if (acceptInputMouse && dotCounter<5 && isTriangle == true && isPent == false && isHex == false)                            //Loops to get click input 4 times
        {
            if (event.type == Event::MouseButtonPressed)
            {
                RectangleShape* ndot = new RectangleShape;          //new dot
                x = event.mouseButton.x;                            //GET X THEN Y
                y = event.mouseButton.y;                           
                *ndot = dot1;
                ndot->setPosition(x, y);                            //SET DOT X,Y                              
                dotCounter++;                                       //INCREMENT
                acceptInputMouse = false;                                //AVOID 100 MPH
                dotList.push_back(*ndot);                           //Push in vector
            }
        }

        if (acceptInputMouse && dotCounter < 7 && isTriangle == false && isPent == true && isHex == false)                            //FOR pent
        {
            if (event.type == Event::MouseButtonPressed)
            {
                RectangleShape* ndot = new RectangleShape;          //new dot
                x = event.mouseButton.x;                            //GET X THEN Y
                y = event.mouseButton.y;
                *ndot = dot1;
                ndot->setPosition(x, y);                            //SET DOT X,Y                              
                dotCounter++;                                       //INCREMENT
                acceptInputMouse = false;                                //AVOID 100 MPH
                dotList.push_back(*ndot);                           //Push in vector
            }
        }
        if (acceptInputMouse && dotCounter < 8 && isTriangle == false && isPent == false && isHex == true)                            //FOR HEX
        {
            if (event.type == Event::MouseButtonPressed)
            {
                RectangleShape* ndot = new RectangleShape;          //new dot
                x = event.mouseButton.x;                            //GET X THEN Y
                y = event.mouseButton.y;
                *ndot = dot1;
                ndot->setPosition(x, y);                            //SET DOT X,Y                              
                dotCounter++;                                       //INCREMENT
                acceptInputMouse = false;                                //AVOID 100 MPH
                dotList.push_back(*ndot);                           //Push in vector
            }
        }
        if (acceptInputMouse && dotCounter > 3000)                       //RESET PART
        {                                                           //RESET if COUNTER>3000
            if (event.type == Event::MouseButtonPressed)
            {
                dotList.clear();                                   
                dotCounter = 0;
                isTriangle = false;                       
                isPent = false;
                isHex = false;
              
            }
        }
        /***************************************************************************
                 Chaos part
         ***************************************************************************/
        if (dotCounter >= 4 && isTriangle == true && isPent == false && isHex == false)
        {
            RectangleShape* ndot = new RectangleShape;                  //MAKES NEW EA FRAME
            ndot->setSize(Vector2f(1, 1));
            //ndot->setFillColor(Color::White);
            rng = rand() % (3);                                         //RANDOM 0,1,2
            if (rng == 0)
            {
                ndot->setFillColor(red);
                temp = dotList.at(0).getPosition();                     //GET FIRST DOT X AND Y
                temp2 = dotList.at(dotList.size() - 1).getPosition();   //GET LAST DOT X AND Y
                temp.x = temp.x + temp2.x;                              ///////////////////////////
                temp.x = temp.x / 2;
                temp.y = temp.y + temp2.y;
                temp.y = temp.y / 2;
                ndot->setPosition(temp);                                //GET MIDPOINT^^/////////////
                dotList.push_back(*ndot);                               //MIDPOINT IS NEW DOT, BACK AT THE LINE
                dotCounter++;
            }
            else if (rng == 1)                                          //same for next 2 block, but index = rng
            {
                ndot->setFillColor(blue);
                temp = dotList.at(1).getPosition();
                temp2 = dotList.at(dotList.size() - 1).getPosition();
                temp.x = temp.x + temp2.x;
                temp.x = temp.x / 2;
                temp.y = temp.y + temp2.y;
                temp.y = temp.y / 2;
                ndot->setPosition(temp);
                dotList.push_back(*ndot);
                dotCounter++;
            }
            else
            {
                ndot->setFillColor(green);
                temp = dotList.at(2).getPosition();
                temp2 = dotList.at(dotList.size() - 1).getPosition();
                temp.x = temp.x + temp2.x;
                temp.x = temp.x / 2;
                temp.y = temp.y + temp2.y;
                temp.y = temp.y / 2;
                ndot->setPosition(temp);
                dotList.push_back(*ndot);
                dotCounter++;
            }
        
        }
        if (dotCounter >= 6 && isTriangle == false && isPent == true && isHex == false)
        {
                RectangleShape* ndot = new RectangleShape;          //MAKES NEW EA FRAME
                ndot->setSize(Vector2f(1, 1));
                //ndot->setFillColor(Color::White);
                rng = rand() % (5);                                 //RANDOM 0,1,2
                if (rng == 0)
                {
                    ndot->setFillColor(pink);
                    temp = dotList.at(0).getPosition();;                      //GET FIRST DOT X AND Y
                    temp2 = dotList.at(dotList.size() - 1).getPosition();//GET LAST DOT X AND Y
                    temp.x = lerp(temp.x, temp2.x, 0.33);                           ///////////////////////////
                    temp.y = lerp(temp.y, temp2.y, 0.33);                                   //GET MIDPOINT^^/////////////
                    ndot->setPosition(temp);                            //MIDPOINT IS NEW DOT, BACK AT THE LINE
                    dotList.push_back(*ndot);
                    dotCounter++;


                }
                else if (rng == 1)
                {
                    ndot->setFillColor(blue);
                    temp = dotList.at(1).getPosition();
                    temp2 = dotList.at(dotList.size() - 1).getPosition();
                    temp.x = lerp(temp.x, temp2.x, 0.33);                           ///////////////////////////
                    temp.y = lerp(temp.y, temp2.y, 0.33);
                    ndot->setPosition(temp);
                    dotList.push_back(*ndot);
                    dotCounter++;

                }
                else if (rng == 2)
                {
                    ndot->setFillColor(red);
                    temp = dotList.at(2).getPosition();
                    temp2 = dotList.at(dotList.size() - 1).getPosition();
                    temp.x = lerp(temp.x, temp2.x, 0.33);                           ///////////////////////////
                    temp.y = lerp(temp.y, temp2.y, 0.33);
                    ndot->setPosition(temp);
                    dotList.push_back(*ndot);
                    dotCounter++;

                }
                else if (rng == 3)
                {
                    ndot->setFillColor(yellow);
                    temp = dotList.at(3).getPosition();
                    temp2 = dotList.at(dotList.size() - 1).getPosition();
                    temp.x = lerp(temp.x, temp2.x, 0.33);                           ///////////////////////////
                    temp.y = lerp(temp.y, temp2.y, 0.33);
                    ndot->setPosition(temp);
                    dotList.push_back(*ndot);
                    dotCounter++;

                }
                else if (rng == 4)
                {
                    ndot->setFillColor(green);
                    temp = dotList.at(4).getPosition();
                    temp2 = dotList.at(dotList.size() - 1).getPosition();
                    temp.x = lerp(temp.x, temp2.x, 0.33);                           ///////////////////////////
                    temp.y = lerp(temp.y, temp2.y, 0.33);
                    ndot->setPosition(temp);
                    dotList.push_back(*ndot);
                    dotCounter++;

                }
                else
                {
                    ndot->setFillColor(orange);
                    temp = dotList.at(5).getPosition();
                    temp2 = dotList.at(dotList.size() - 1).getPosition();
                    temp.x = lerp(temp.x, temp2.x, 0.33);                           ///////////////////////////
                    temp.y = lerp(temp.y, temp2.y, 0.33);
                    ndot->setPosition(temp);
                    dotList.push_back(*ndot);
                    dotCounter++;

                }
            }
        if (dotCounter >= 7 && isTriangle == false && isPent == false && isHex == true)
        {
            RectangleShape* ndot = new RectangleShape;          //MAKES NEW EA FRAME
            ndot->setSize(Vector2f(1, 1));
            //ndot->setFillColor(Color::White);
            rng = rand() % (6);                                 //RANDOM 0,1,2
            if (rng == 0)
            {
                ndot->setFillColor(pink);
                temp = dotList.at(0).getPosition();;                      //GET FIRST DOT X AND Y
                temp2 = dotList.at(dotList.size() - 1).getPosition();//GET LAST DOT X AND Y
                temp.x = lerp(temp.x, temp2.x, 0.33);                           ///////////////////////////
                temp.y = lerp(temp.y, temp2.y, 0.33);                                   //GET MIDPOINT^^/////////////
                ndot->setPosition(temp);                            //MIDPOINT IS NEW DOT, BACK AT THE LINE
                dotList.push_back(*ndot);
                dotCounter++;


            }
            else if (rng == 1)
            {
                ndot->setFillColor(blue);
                temp = dotList.at(1).getPosition();
                temp2 = dotList.at(dotList.size() - 1).getPosition();
                temp.x = lerp(temp.x, temp2.x, 0.33);                           ///////////////////////////
                temp.y = lerp(temp.y, temp2.y, 0.33);
                ndot->setPosition(temp);
                dotList.push_back(*ndot);
                dotCounter++;

            }
            else if (rng == 2)
            {
                ndot->setFillColor(red);
                temp = dotList.at(2).getPosition();
                temp2 = dotList.at(dotList.size() - 1).getPosition();
                temp.x = lerp(temp.x, temp2.x, 0.33);                           ///////////////////////////
                temp.y = lerp(temp.y, temp2.y, 0.33);
                ndot->setPosition(temp);
                dotList.push_back(*ndot);
                dotCounter++;

            }
            else if (rng == 3)
            {
                ndot->setFillColor(yellow);
                temp = dotList.at(3).getPosition();
                temp2 = dotList.at(dotList.size() - 1).getPosition();
                temp.x = lerp(temp.x, temp2.x, 0.33);                           ///////////////////////////
                temp.y = lerp(temp.y, temp2.y, 0.33);
                ndot->setPosition(temp);
                dotList.push_back(*ndot);
                dotCounter++;

            }
            else if (rng == 4)
            {
                ndot->setFillColor(green);
                temp = dotList.at(4).getPosition();
                temp2 = dotList.at(dotList.size() - 1).getPosition();
                temp.x = lerp(temp.x, temp2.x, 0.33);                           ///////////////////////////
                temp.y = lerp(temp.y, temp2.y, 0.33);
                ndot->setPosition(temp);
                dotList.push_back(*ndot);
                dotCounter++;

            }
            else if (rng == 5)
            {
                ndot->setFillColor(orange);
                temp = dotList.at(5).getPosition();
                temp2 = dotList.at(dotList.size() - 1).getPosition();
                temp.x = lerp(temp.x, temp2.x, 0.33);                           ///////////////////////////
                temp.y = lerp(temp.y, temp2.y, 0.33);
                ndot->setPosition(temp);
                dotList.push_back(*ndot);
                dotCounter++;

            }
            else
            {
                ndot->setFillColor(yellow);
                temp = dotList.at(5).getPosition();
                temp2 = dotList.at(dotList.size() - 1).getPosition();
                temp.x = lerp(temp.x, temp2.x, 0.33);                           ///////////////////////////
                temp.y = lerp(temp.y, temp2.y, 0.33);
                ndot->setPosition(temp);
                dotList.push_back(*ndot);
                dotCounter++;

            }
        }



        if (event.type == Event::MouseButtonReleased)               //Controls clicks
        {
            acceptInputMouse = true;
        }

        if(dotCounter <3)                                           //Output text                
        { 
            text.setString("Welcome to Chaos Game!!! \n   Q=Triangle, W=Pentagon, E=Hexagon");
        }
        else if (dotCounter == 3)//FIX
        {
            text.setString("Select 4th point to start!");
        }
        else if (dotCounter>3 && dotCounter<3000)
        {
            text.setString("");
        }
        else
        {
            text.setString("Should see pattern by now \n Click anywhere to restart");
        }

        stringstream ss;
        ss << "Dot counter: " << dotCounter;
        dotText.setString(ss.str());
                  
        window.clear();                                              //draw
        window.draw(text);
        window.draw(dotText);
        for (int i = 0;i < dotList.size();i++)     
        {
            window.draw(dotList.at(i));
        }
        window.display();
    }
}
