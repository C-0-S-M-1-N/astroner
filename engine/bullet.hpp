#pragma once
#include <SFML/Graphics/RenderWindow.hpp>
#include <bits/stdc++.h>
#include <SFML/Graphics.hpp>


#define glonT glont[i]

extern float WIDTH;
extern float HEIGHT;
extern float DeltaTime;

class bullet{
public:
    float bx, by, bW, bH;
    bool is_alive;
    sf::RectangleShape b;
    bullet(float, float, float, float);
    
    void bulletDraw(sf::RenderWindow&);
    void update();
};
