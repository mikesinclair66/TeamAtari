#include <SFML/Graphics.hpp>
#include "component_window.hpp"
#include "scrollbar.hpp"

using namespace coordinates;
using namespace interact;

int main()
{
    ComponentWindow w(800, 600, "QDS");

    ScrollbarVertical* s = new ScrollbarVertical();
    s->setRatio(0.3f);
    s->setOffsetRatio(0.5f);
    s->setColor(Color::White);
    s->setScrollColors(Color(127, 127, 127), Color(25, 25, 25));
    s->updateColor();
    s->setSize(50, 225);
    s->setPosition(100, 100);

    w.addComponent(s);
    w.addMouseListener(s);
    w.draw();

    return 0;
}