// I want a class that renders an image including ppm colors.
#pragma once
#include <SFML/Graphics.hpp>
#include <iostream> 
#include "color.h"
#include "util.h"

class Renderer{

    private:
    // Set window width and height
    // 1. Render window 
    const unsigned int image_width;
    const unsigned int image_height;

    sf::Image image;
    sf::Texture texture;
    sf::Sprite sprite;

    public:
    // renderer constructor
    Renderer(unsigned int width, unsigned int height)
    : image_width(width),
      image_height(height),
      image(sf::Vector2u{width, height}),
      texture(sf::Vector2u{width, height}),
      sprite(texture)
    {}

    void setPixel(x,y,const color&);
    void drawGradient();

    // default constructor deleted

    const unsigned int getImageWidth();
    const unsigned int getImageHeight();
    const sf::Sprite& getSprite() const;

};