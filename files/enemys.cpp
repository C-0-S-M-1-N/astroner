#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "others.cpp"

namespace astr{
    class enemy{
        sf::IntRect hitbox;
        sf::Sprite body;
    public:
        enemy(sf::Vector2f size, sf::Texture &t){
            hitbox.height = size.y;
            hitbox.width = size.x;
            body.setTexture(t);
            body.setTextureRect(hitbox);
        }
        void draw(sf::RenderWindow &w){
            w.draw(body);
        }
    };
};











