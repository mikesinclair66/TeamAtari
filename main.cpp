#include <SFML/Graphics.hpp>
#include "component_window.hpp"
#include "cell.hpp"
#include "button.hpp"

using namespace interact;
using namespace coordinates;

int main()
{
    ComponentWindow w(800, 600, "QDS");

    Cell* cell = new Cell();
    cell->textBox->setColor(Color::Red);
    cell->textBox->setString("12345");
    cell->setSize(225, 40);
    cell->setPosition(100, 100);
    cell->setTextIndicatorColor(Color::Magenta);

    w.addBoundary(cell);
    w.addMouseListener(cell);
    w.addKeyListener(cell);

    Button* btn = new Button();
    btn->setSize(100, 40);
    btn->setPosition(400, 200);
    btn->setColor(Color(255, 255, 0));
    btn->setAlternateColor(Color(0, 0, 255));
    btn->updateColor();

    w.addBoundary(btn);
    w.addMouseListener(btn);

    w.draw();

    return 0;
}