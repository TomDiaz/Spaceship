#include <iostream>
#include <SFML/Graphics.hpp>
#include "utils.h"
#include <thread>

// Función para manejar el renderizado en un hilo separado
void renderingThread(sf::RenderWindow* window,sf::Sprite* sprite)
{
    // activar el contexto de la ventana
    window->setActive(true);

    // bucle de renderizado
    while (window->isOpen())
    {
        sf::Event event;
        while (window->pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window->close();
        }

        window->clear(sf::Color::Black);
        window->draw(*sprite);
        // finalizar el frame actual
        window->display();
  
    }
}

void keywordThread(bool* running, sf::Sprite* sprite)
{
    while (*running)
    {
        if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
        {
            std::cout << "CLICK" << std::endl;
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
        {
            sprite->setPosition(100,100);
            std::cout << "Espacio presionado" << std::endl;
        }

        std::this_thread::sleep_for(std::chrono::milliseconds(50)); // Evita uso excesivo de CPU
    }
}


int main() {
    // crear la ventana (recuerda: es más seguro crearla en el hilo principal debido a limitaciones del SO)
    sf::RenderWindow window(sf::VideoMode(640, 480), "Spaceship");

    // desactivar su contexto OpenGL
    window.setActive(false);

    sf::Texture texture; 
    if (!texture.loadFromFile("./assets/ship_H.png"))
    {
        std::cout << "Error loading texture" << std::endl;
        return -1;
    }

    sf::Sprite sprite(texture);

    bool running = true;

    // lanzar el hilo de renderizado
    std::thread thread(&renderingThread, &window, &sprite);
    std::thread keythread(&keywordThread, &running, &sprite);
 
    keythread.join();
    // esperar a que el hilo de renderizado termine
    thread.join();      
       

    return 0;
}         