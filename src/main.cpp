#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{
    sf::RenderWindow window(sf::VideoMode({640, 480}), "Spaceship");
    window.setFramerateLimit(60);
    
    sf::Texture texture;
    if (!texture.loadFromFile("assets/ship_H.png"))
    {
        std::cout << "Error loading texture\n";
        return -1;
    }

    sf::Sprite sprite(texture);

    while (window.isOpen())
    {
        // EVENTOS
        while (auto event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
        }

        // INPUT (tiempo real)
        if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
        {
            std::cout << "CLICK\n";
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::Space))
        {
            sprite.setPosition({100.f, 100.f});
            std::cout << "Espacio presionado\n";
        }

        // RENDER
        window.clear(sf::Color::Black);
        window.draw(sprite);
        window.display();
    }

    return 0;
}