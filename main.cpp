#include <SFML/Graphics.hpp>
#include "component_window.hpp"
#include "button.hpp"

using namespace coordinates;
using namespace interact;

int main()
{
    ComponentWindow w(800, 600, "QDS");

    Button* btn = new Button();
    btn->setColor(Color::Red);
    btn->setAlternateColor(Color::Yellow);
    btn->updateColor();
    btn->setSize(150, 75);
    btn->setPosition(25, 25);

    w.addComponent(btn);
    w.addMouseListener(btn);
    w.draw();

    return 0;
}