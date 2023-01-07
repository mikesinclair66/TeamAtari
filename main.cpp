#include <SFML/Graphics.hpp>
#include "component_window.hpp"
#include "button.hpp"

using namespace coordinates;

int main()
{
    //sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
    ComponentWindow w(800, 600, "QDS");

    Button* btn = new Button();
    btn->setSize(Vector2f(150, 75));
    btn->setPosition(Vector2f(25, 25));
    btn->setColor(Color::Red);

    w.add(btn);
    w.draw();

    return 0;
}