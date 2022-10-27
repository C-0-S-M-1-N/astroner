#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <bits/stdc++.h>
#include <cmath>
#include "../engine.cpp"

extern sf::Font f2;
extern float WIDTH, HEIGHT, DeltaTime;

const int LEVELS = 10;
int Ls = 1;
int level = 0;
bool ret = 0;
std::vector<std::string> levelNames = {
    "NULL NAME",
    "LEVEL 1.\n\n{InsertName}",
    "LEVEL 2.\n\n{InsertName}",
    "LEVEL 3.\n\n{InsertName}",
    "LEVEL 4.\n\n{InsertName}",
    "LEVEL 5.\n\n{InsertName}",
    "LEVEL 6.\n\n{InsertName}",
    "LEVEL 7.\n\n{InsertName}",
    "LEVEL 8.\n\n{InsertName}",
    "LEVEL 9.\n\n{InsertName}",
    "LEVEL 10.\n\n{InsertName}",
};

class pointLevel{
private:
    sf::CircleShape ob;
    sf::CircleShape mark;
    sf::Color normal;
    sf::Color selected;
    std::string tags;
public:
    pointLevel(int size = 10, sf::Color n = sf::Color::White, sf::Color s = sf::Color::Red){
        ob.setRadius(size);
        mark.setRadius(size+size/4);
        normal = n;
        selected  = s;
        ob.setFillColor(normal);
        mark.setFillColor(sf::Color(0 , 0, 0, 0));
        mark.setOrigin(mark.getGlobalBounds().width/2, mark.getGlobalBounds().height/2);
        ob.setOrigin(ob.getGlobalBounds().width/2, ob.getGlobalBounds().height/2);
    }
    sf::CircleShape getPoint(){
        return this->ob;
    }
    void highLight(){
        mark.setFillColor(selected);
    }
    void unHighLight(){
        mark.setFillColor(sf::Color(0 ,0, 0, 0));
    }
    void setPosition(float x, float y){
        ob.setPosition(x, y);
        mark.setPosition(x, y);
    }
    void setOrigin(float x, float y){
        ob.setOrigin(x, y);
        mark.setOrigin(x, y);
    }
    void setSize(float x){
        ob.setRadius(x);
        mark.setRadius(x);
    }
    void setColor(sf::Color n, sf::Color s){
        normal = n;
        selected = s;
        ob.setFillColor(normal);
    }
    void display(sf::RenderWindow &win){
        win.draw(mark);
        win.draw(ob);
    }
    void setTag(const std::string t){
        tags = t;
    }
    std::string getTag(){
        return tags;
    }
    void complete(){
        ob.setFillColor(sf::Color::Green);
    }
};

sf::Texture bck; //background
pointLevel endL(50);
std::vector<pointLevel> v = {pointLevel(20), pointLevel(20), pointLevel(20), pointLevel(20), pointLevel(20), pointLevel(20), pointLevel(20), pointLevel(20), pointLevel(20)};

sf::Text levelName;

static sf::Clock inpc;

void sDisplaY(sf::RenderWindow&);
void sLoad();
void iP(); //input, n.am alt nume :/
void Updt(); //update, e la fel la input

int saves(sf::RenderWindow& win){
    std::thread t1(iP);
    sDisplaY(win);
    t1.join();
    if(ret)	return Ls;
	else return 0;
}

void sDisplaY(sf::RenderWindow &win){
    win.clear();
    for(auto i:v) i.display(win);
    endL.display(win);

    win.draw(levelName);

    win.display();
}

void sLoad(){
    levelName.setFont(f2);
    levelName.setPosition(0, HEIGHT-100);
    levelName.setCharacterSize(15 * WIDTH/HEIGHT);
    int l = 0;
    int spacing = WIDTH/LEVELS; 
    v[0].setPosition(l, 1001 * HEIGHT/WIDTH);
    l += spacing;
    v[1].setPosition(l, 903 * HEIGHT/WIDTH);
    l += spacing;
    v[2].setPosition(l, 681 * HEIGHT/WIDTH);
    l += spacing;
    v[3].setPosition(l, 617 * HEIGHT/WIDTH);
    l += spacing;
    v[4].setPosition(l, 292 * HEIGHT/WIDTH);
    l += spacing;
    v[5].setPosition(l, 861 * HEIGHT/WIDTH);
    l += spacing;
    v[6].setPosition(l, 365 * HEIGHT/WIDTH);
    l += spacing;
    v[7].setPosition(l, 116 * HEIGHT/WIDTH);
    l += spacing;
    v[8].setPosition(l, 617 * HEIGHT/WIDTH);
    l += spacing;
    endL.setPosition(l, HEIGHT/2-50);
}

void iP(){
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)){
        ret = 1;
        return;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D) && inpc.getElapsedTime().asMilliseconds() >= 200){
        Ls++;
        if(Ls > LEVELS) Ls = 1;
        Updt();
        inpc.restart();
        return;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A) && inpc.getElapsedTime().asMilliseconds() >= 200){
        Ls--;
        if(Ls < 1) Ls = LEVELS;
        Updt();
        inpc.restart();
        return;
    }
    ret = 0;
}

void Updt(){
    levelName.setString(levelNames[Ls]);

    for(int i = 0; i<v.size(); i++){
        if(i+1 == Ls) v[i].highLight();
        else v[i].unHighLight();
    }
}
