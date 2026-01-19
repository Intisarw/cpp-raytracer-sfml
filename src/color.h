#include "Vec3.hpp"
#include <iostream>
#include <SFML/Graphics/Color.hpp>
#include <cmath>
#include "util.h"

using color = Vec3;

//writing color to a buffer
inline sf::Color toSFMLColor(const color& c){
    double r = std::sqrt(c.getX());
    double g = std::sqrt(c.getY());
    double b = std::sqrt(c.getZ());

    // sets a value from 0 - 1 for the x, y and z
    r = clamp(r, 0.0, 0.999);
    g = clamp(g, 0.0, 0.999);
    b = clamp(b, 0.0, 0.999);

    auto ir = static_cast<std::uint8_t> (255.99 * r);
    auto ig = static_cast<std::uint8_t> (255.99 * g);
    auto ib = static_cast<std::uint8_t> (255.99 * b);

    return sf::Color(ir, ig, ib);
}