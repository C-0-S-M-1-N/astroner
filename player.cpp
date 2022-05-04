#pragma once
#include <SFML/Graphics.hpp>
#include "main.cpp"

sf::Texture Static;
sf::Texture Down;
sf::Texture Up;


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
        player();
        void setPosition(float x, float y);
        void setOrigin(float x, float y);
        void setTextures(sf::Texture &tx, sf::Texture &tx2, sf::Texture &tx3);
        
        void draw(sf::RenderWindow &w);
        void input();
        void update();
        
        sf::Vector2f getPosition();
        sf::Vector2f getSize();
        void move(float x, float y);

    };
    void player::setPosition(float x, float y){
        ship.setPosition(x, y);
    }
    void player::setOrigin(float x, float y){
        ship.setOrigin(x, y);
    }
    void player::setTextures(sf::Texture &txS, sf::Texture &tx2U, sf::Texture &tx3D){
        Static = txS;
        Up = tx2U;
        Down = tx3D;
    }
    void player::draw(sf::RenderWindow &w){
        w.draw(ship);
    }
    void player::input(){
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::W) && getPosition().y > 0){
            move(0, -100);
            ship.setTexture(Up);
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::S) && getPosition().y < HEIGHT - getSize().y){
            move(0, 100);
            ship.setTexture(Down);
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::A) && getPosition().x > 0){
            move(-80, 0);
            ship.setTexture(Static);
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::D) && getPosition().x < WIDTH - getSize().x){
            move(80, 0);
            ship.setTexture(Static);
        }
    }
    void player::move(float x, float y){
        ship.setPosition(ship.getPosition().x + x*DeltaTime * WIDTH/HEIGHT, ship.getPosition().y + y*DeltaTime * WIDTH/HEIGHT);
    }
};
