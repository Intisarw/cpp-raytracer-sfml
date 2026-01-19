#include <SFML/Graphics.hpp>
#include <optional>
#include <fstream>
#include <iostream>
#include <cstdint>
#include "Renderer.hpp"
#include "Vec3.hpp"
#include "drawShape.hpp"

int main() {



    sf::CircleShape shape(50.f);
    shape.setFillColor(sf::Color(100,250,50));
    // ------------------------------------------------------------------------------------ WINDOW START

    sf::RenderWindow window(sf::VideoMode(sf::Vector2u{renderer.getImageWidth(), renderer.getImageHeight()}), "Test");

    while (window.isOpen()) {
        while (auto eventOpt = window.pollEvent()) {
            const sf::Event& event = *eventOpt;

            if (event.is<sf::Event::Closed>()) {
                window.close();
            }
        }

        window.clear();
        window.draw(shape);
        window.display();
    }

    return 0;
}
