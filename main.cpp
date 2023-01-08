#include <SFML/Graphics.hpp>
#include "splash.hpp"

using namespace coordinates;

int main()
{
    Splash s(900, 700, "QDS");
    s.draw();

    return 0;
}