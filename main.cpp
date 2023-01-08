#include <SFML/Graphics.hpp>
#include "component_window.hpp"
#include "cell.hpp"

using namespace coordinates;
using namespace interact;

int main()
{
    ComponentWindow w(800, 600, "QDS");

    /*
    ScrollbarVertical* s = new ScrollbarVertical();
    s->setRatio(0.3f);
    s->setOffsetRatio(0.5f);
    s->setColor(Color::White);
    s->setScrollColors(Color(127, 127, 127), Color(25, 25, 25));
    s->updateColor();
    s->setSize(50, 225);
    s->setPosition(100, 100);
    */

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