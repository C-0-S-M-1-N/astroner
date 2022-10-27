#pragma once
#include <SFML/Graphics.hpp>


void draw(sf::RenderWindow &w);
void UpdateLvl1();
void InputHandle1();

sf::Texture Enemy1;

void draw();
void inputHandle();
void UpadateLvl1();
void lvl1Load();

int lvl1(sf::RenderWindow &w){

    draw(w);
    return 1;
}

void draw(sf::RenderWindow &w){
    w.clear();
    
    w.display();
}

void InputHandle1(){

}

void UpdateLvl1(){

}

void lvl1Load(){

}
