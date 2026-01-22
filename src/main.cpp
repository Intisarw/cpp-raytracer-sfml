#include <SFML/Graphics.hpp>
#include <optional>
#include <fstream>
#include <iostream>
#include <cstdint>
#include "vec3.h"
#include "color.h"

int main() {


    int image_width = 256;
    int image_height = 256;

    std::cout << "P3\n" << image_width << ' ' << image_height << "\n255\n";

    for (int j = 0; j < image_height; j++) {
        std::clog << "\rScanlines remaining: " << (image_height - j) << ' ' << std::flush;
        for (int i = 0; i < image_width; i++) {
            auto pixel_color = color(
                double(i) / (image_width - 1),
                double(j) / (image_height - 1),
                0.0
            );
            write_color(std::cout, pixel_color);
        }
    }

    std::clog << "\rDone.                 \n";

    // ------------------------------------------------------------------------------------ WINDOW START

    sf::RenderWindow window();

    while (window.isOpen()) {
        while (auto eventOpt = window.pollEvent()) {
            const sf::Event& event = *eventOpt;

            if (event.is<sf::Event::Closed>()) {
                window.close();
            }
        }

        window.clear();
        window.draw();
        window.display();
    }

    return 0;
}
