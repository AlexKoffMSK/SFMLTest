//#include <iostream>
#include <SFML/Graphics.hpp>
#include <random>
#include <thread>
#include <chrono>
#include <conio.h>
#include <cmath>

/*
void DrawFrame(sf::RenderWindow& window, sf::CircleShape& shape)
{
    window.clear();
    window.draw(shape);
    window.display();
}

void MoveToMouse(sf::RenderWindow& window, sf::CircleShape& shape)
{
    sf::Vector2f move_direction;
    move_direction.x = sf::Mouse::getPosition(window).x - (shape.getPosition().x + shape.getRadius());
    move_direction.y = sf::Mouse::getPosition(window).y - (shape.getPosition().y + shape.getRadius());
    DrawFrame(window, shape);
}

void MoveUpLeft(sf::RenderWindow& window, sf::CircleShape& shape, float& step_size)
{
    if (shape.getPosition().y > 0 && shape.getPosition().x > 0) //если новая позиция по Y валидна - двигаем форму
    {
        shape.move(-step_size, -step_size);
        DrawFrame(window, shape);
    }
}
void MoveUp(sf::RenderWindow& window, sf::CircleShape& shape, float& step_size)
{
    if (shape.getPosition().y > 0) //если новая позиция по Y валидна - двигаем форму
    {
        shape.move(0, -step_size);
        DrawFrame(window, shape);
    }
}
void MoveUpRight(sf::RenderWindow& window, sf::CircleShape& shape, float& step_size)
{
    if (shape.getPosition().y > 0 && shape.getPosition().x > 0) //если новая позиция по Y валидна - двигаем форму
    {
        shape.move(step_size, -step_size);
        DrawFrame(window, shape);
    }
}

void MoveDownLeft(sf::RenderWindow& window, sf::CircleShape& shape, float& step_size)
{
    if (shape.getPosition().y < window.getSize().y - shape.getRadius() * 2 && shape.getPosition().x > 0)
    {
        shape.move(-step_size, step_size);
        DrawFrame(window, shape);
    }
}
void MoveDown(sf::RenderWindow& window, sf::CircleShape& shape, float& step_size)
{
    if (shape.getPosition().y < window.getSize().y - shape.getRadius() * 2)
    {
        shape.move(0, step_size);
        DrawFrame(window, shape);
    }
}
void MoveDownRight(sf::RenderWindow& window, sf::CircleShape& shape, float& step_size)
{
    if (shape.getPosition().y < window.getSize().y - shape.getRadius() * 2 && shape.getPosition().x < window.getSize().x - shape.getRadius() * 2)
    {
        shape.move(step_size, step_size);
        DrawFrame(window, shape);
    }
}

void MoveLeft(sf::RenderWindow& window, sf::CircleShape& shape, float& step_size)
{
    if (shape.getPosition().x > 0)
    {
        shape.move(-step_size, 0);
        DrawFrame(window, shape);
    }
}
void MoveRight(sf::RenderWindow& window, sf::CircleShape& shape, float& step_size)
{
    if (shape.getPosition().x < window.getSize().x - shape.getRadius() * 2)
    {
        shape.move(step_size, 0);
        DrawFrame(window, shape);
    }
}

void MoveToWallUp(sf::RenderWindow& window, sf::CircleShape& shape, float& step_size)
{
    while (shape.getPosition().y > 0)
    {
        MoveUp(window, shape, step_size);
    }
}
void MoveToWallDown(sf::RenderWindow& window, sf::CircleShape& shape, float& step_size)
{
    while (shape.getPosition().y < window.getSize().y - shape.getRadius() * 2)
    {
        MoveDown(window, shape, step_size);
    }
}
void MoveToWallLeft(sf::RenderWindow& window, sf::CircleShape& shape, float& step_size)
{
    while (shape.getPosition().x > 0)
    {
        MoveLeft(window, shape, step_size);
    }
}

void MoveToWallRight(sf::RenderWindow& window, sf::CircleShape& shape, float& step_size)
{
    while (shape.getPosition().x < window.getSize().x - shape.getRadius() * 2)
    {
        MoveRight(window, shape, step_size);
    }
}
void MoveToWallUpLeft(sf::RenderWindow& window, sf::CircleShape& shape, float& step_size)
{
    while (shape.getPosition().y > 0 && shape.getPosition().x > 0)
    {
        MoveUpLeft(window, shape, step_size);
    }
}
void MoveToWallUpRight(sf::RenderWindow& window, sf::CircleShape& shape, float& step_size)
{
    while (shape.getPosition().y > 0 && shape.getPosition().x < window.getSize().x - shape.getRadius() * 2)
    {
        MoveUpRight(window, shape, step_size);
    }
}

void MoveToWallDownLeft(sf::RenderWindow& window, sf::CircleShape& shape, float& step_size)
{
    while (shape.getPosition().y < window.getSize().y - shape.getRadius() * 2 && shape.getPosition().x > 0)
    {
        MoveDownLeft(window, shape, step_size);
    }
}
void MoveToWallDownRight(sf::RenderWindow& window, sf::CircleShape& shape, float& step_size)
{
    while (shape.getPosition().y < window.getSize().y - shape.getRadius() * 2 && shape.getPosition().x < window.getSize().x - shape.getRadius() * 2)
    {
        MoveDownRight(window, shape, step_size);
    }
}

void MoveToBound(sf::RenderWindow& window, sf::CircleShape& shape, float& step_size)
{
    while (shape.getPosition().x > 0 && shape.getPosition().x < window.getSize().x - shape.getRadius() * 2
        && shape.getPosition().y>0 && shape.getPosition().y < window.getSize().y - shape.getRadius() * 2)
    {

    }
}

void RandomMoving(sf::RenderWindow& window, sf::CircleShape& shape, float& step_size)
{
    for (int i = 0; i < sizeof(short int); i++)
    {
        switch (rand() % 8)
        {
        case 0:
            shape.setOutlineColor(sf::Color::Blue);
            MoveUp(window, shape, step_size);
            break;
        case 1:
            shape.setOutlineColor(sf::Color::Red);
            MoveDown(window, shape, step_size);
            break;
        case 2:
            shape.setOutlineColor(sf::Color::Green);
            MoveLeft(window, shape, step_size);
            break;
        case 3:
            shape.setOutlineColor(sf::Color::Yellow);
            MoveRight(window, shape, step_size);
            break;
        case 4:
            shape.setOutlineColor(sf::Color::Cyan);
            MoveUpLeft(window, shape, step_size);
            break;
        case 5:
            shape.setOutlineColor(sf::Color::Magenta);
            MoveUpRight(window, shape, step_size);
            break;
        case 6:
            shape.setOutlineColor(sf::Color::White);
            MoveDownLeft(window, shape, step_size);
            break;
        case 7:
            shape.setOutlineColor(sf::Color::Black);
            MoveDownRight(window, shape, step_size);
            break;
        }
    }
}
*/

int main()
{
    srand(time(0));

    float step_size = 8;
    float circ_radius = 16;
    float circ_OutlineThickness = circ_radius / 4;

    float vx = 0;
    float vy = 0;

    float vector_decrease_factor = 0.9;

    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    sf::RenderWindow window(sf::VideoMode(1024, 768), "SFML works!", sf::Style::Default, settings);
    
    sf::CircleShape circ_shape(circ_radius); //CircleShape рисует форму круга, но в расчетах принимает его как квадрат

    while (window.isOpen())
    {
        sf::Event event;

        float opposit_leg_lenght = 0;
        float adjacent_leg_lenght = 0;
        //float angle = tan()

        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }

            if (event.type == sf::Event::KeyPressed)
            {
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
                {
                    //MoveToWallUp(window, circ_shape, step_size);
                    MoveUp(window, circ_shape, step_size);
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
                {
                    //MoveToWallDown(window, circ_shape, step_size);
                    MoveDown(&window, circ_shape, step_size);
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
                {
                    //MoveToWallLeft(window, circ_shape, step_size);
                    MoveLeft(window, circ_shape, step_size);
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
                {
                    //MoveToWallRight(window, circ_shape, step_size);
                    MoveRight(window, circ_shape, step_size);
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
                {
                    MoveToWallUp(window, circ_shape, step_size);
                    MoveToWallDown(window, circ_shape, step_size);
                    MoveToWallLeft(window, circ_shape, step_size);
                    MoveToWallRight(window, circ_shape, step_size);

                    MoveToWallUpLeft(window, circ_shape, step_size);
                    MoveToWallDownRight(window, circ_shape, step_size);

                    MoveToWallUpRight(window, circ_shape, step_size);
                    MoveToWallDownLeft(window, circ_shape, step_size);
                }
                //if ((sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)) && (sf::Keyboard::isKeyPressed(sf::Keyboard::W)))
                //{
                //    MoveToWallUpLeft(window, circ_shape, step_size);
                //}

                //if ((sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)) && (sf::Keyboard::isKeyPressed(sf::Keyboard::R)))
                //{
                //    int i = circ_shape.getRadius();
                //    while (circ_shape.getRadius() > 0)
                //    {
                //        i -= step_size;
                //        circ_shape.setRadius(i);
                //        //std::this_thread::sleep_for(std::chrono::milliseconds(10));
                //        DrawFrame(window, circ_shape);
                //
                //    }
                //}
            }

            //if (event.type == sf::Event::MouseMoved)
            //{
            //    circ_shape.setPosition(sf::Mouse::getPosition(window).x-circ_shape.getRadius(), sf::Mouse::getPosition(window).y - circ_shape.getRadius());
            //}

            if (event.type == sf::Event::MouseButtonPressed)
            {
                circ_shape.setPosition(sf::Mouse::getPosition(window).x - circ_shape.getRadius(), sf::Mouse::getPosition(window).y - circ_shape.getRadius());
                sf::Vector2f CenterOfCircle;
                CenterOfCircle.x = circ_shape.getPosition().x + circ_shape.getRadius();
                CenterOfCircle.y = circ_shape.getPosition().y + circ_shape.getRadius();
                
                circ_shape.setOutlineThickness(circ_OutlineThickness);
                circ_shape.setFillColor(sf::Color::Green);
            }

            if (event.type == sf::Event::MouseButtonPressed)
            {
                //circ_shape.move(sf::Mouse::getPosition(window).x - (circ_shape.getPosition().x + circ_shape.getRadius()), sf::Mouse::getPosition(window).y - (circ_shape.getPosition().y + circ_shape.getRadius()));
                
                MoveToMouse(window, circ_shape);

            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
            {
            }
        }
        
        window.clear();
        window.draw(circ_shape);
        window.display();
    }
}

//нарисовать круг по пикселям