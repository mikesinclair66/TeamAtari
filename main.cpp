#include <SFML/Graphics.hpp>
#include "component_window.hpp"
#include "button.hpp"

using namespace coordinates;

int main()
{
    //sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
    ComponentWindow w(800, 600, "QDS");

    Button* btn = new Button();
    btn->setSize(150, 75);
    btn->setPosition(25, 25);
    btn->setColor(Color::Red);

    w.addComponent(btn);
    w.addMouseListener(btn);
    w.draw();

    return 0;
}