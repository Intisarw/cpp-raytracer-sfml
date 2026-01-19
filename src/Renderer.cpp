#include "Renderer.hpp"

const sf::Sprite& Renderer::getSprite()const {
    return sprite;
}

void Renderer::setPixel(x,y,const color&) {
    if(x >= getImageWidth() || y>= getImageHeight()){
        return;
    }

    // 2 convert math color to sfml color
    sf::Color px = toSFMLColor(c);

    // 3. Here's how 
    image.setPixel(x, y, px);
    
}

//writes to screen
void Renderer::drawGradient(){
    //looping over the gradient
    for(int j = 0 ; j < image_width; j ++){
        for(int i = 0 ; i < image_width; i++){

            double r = static_cast<double>(x)/ (image_width -1);
            double g = static_cast<double>(y)/ (image_height -1);
        
            setPixel(x, y, color(r, g , 0.0));
        }
    }
}

const unsigned int Renderer::getImageWidth(){return image_width;}
const unsigned int Renderer::getImageHeight(){return image_height;}
