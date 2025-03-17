#include <iostream>
#include <SFML/Graphics.hpp>
#include "utils.h"

using namespace sf;

int main() {
    RenderWindow window(VideoMode(640, 480), "Spaceship");

    while (window.isOpen()) {
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed)
                window.close();
        }

        window.clear(Color::Black);
        window.display();
    }

   

    return 0;
}