#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System/Vector2.hpp>
#include <bits/stdc++.h>
#include "../engine/player.hpp"

extern float WIDTH, HEIGHT, DeltaTime;

void astr::player::setPosition(float x, float y){
    ship.setPosition(x, y);
}
void astr::player::setOrigin(float x, float y){
    ship.setOrigin(x, y);
}
void astr::player::setTextures(sf::Texture &txS, sf::Texture &tx2U, sf::Texture &tx3D){
    Static = txS;
    Up = tx2U;
    Down = tx3D;
}
void astr::player::draw(sf::RenderWindow &w){
    w.draw(ship);
}
void astr::player::input(){
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
void astr::player::move(float x, float y){
    ship.setPosition(ship.getPosition().x + x*DeltaTime * WIDTH/HEIGHT, ship.getPosition().y + y*DeltaTime * WIDTH/HEIGHT);
}
