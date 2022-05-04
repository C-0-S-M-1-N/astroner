#pragma once
#include <bits/stdc++.h>
#include <SFML/Graphics.hpp>
using namespace std;


#define glonT glont[i]

class bullet{
public:
    float bx, by, bW, bH;
    bool is_alive;
    sf::RectangleShape b;
    bullet(float x, float y, float w, float h){
        b.setFillColor(sf::Color::White);
        b.setSize(sf::Vector2f(w, h));
        is_alive = true;
        bx = x;
        by = y;
        bW = w;
        bH = h;

    }
    void bulletDraw(){
        if(is_alive) win.draw(b);
    }
    void update(){
        bx += 200 * WIDTH/HEIGHT * DeltaTime;
        b.setPosition(bx, by);
    }
};