#include<SFML/Graphics.hpp>
#include<bits/stdc++.h>

namespace astr{
	class player{
    private:
        sf::IntRect hitbox;
        sf::Sprite ship;
        sf::Texture Static, Up, Down;
    public:
        player(sf::Vector2f size){
            hitbox.width = size.x;
            hitbox.height = size.y;
            ship.setTextureRect(hitbox);
        }
        void setPosition(float x, float y);
        void setOrigin(float x, float y);
        void setTextures(sf::Texture &tx, sf::Texture &tx2, sf::Texture &tx3);
        
        void draw(sf::RenderWindow &w);
        void input();
        void update();
        
        sf::Vector2f getPosition(){ return ship.getPosition(); }
        sf::Vector2f getSize() {return sf::Vector2f(hitbox.width, hitbox.height); };
        void move(float x, float y);

    };
};

