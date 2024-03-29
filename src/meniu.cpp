#pragma once
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <bits/stdc++.h>
#include "../engine.cpp"

extern float WIDTH, HEIGHT, DeltaTime;
extern bool open;
extern scenes Cscene;

int selectat = 1;
float rot = 0;

sf::Text welcome;
sf::Font f; //PressStart font
sf::Texture img;
sf::Sprite background;

sf::Image im;

sf::Music theme;

void Mdisplay(sf::RenderWindow&);
void inputM();
void MupdateB();

UI::Button playButton(200 * WIDTH/HEIGHT, 50 * WIDTH/HEIGHT, 20 * WIDTH/HEIGHT, f, "PLAY", "1");
UI::Button quitButton(200 * WIDTH/HEIGHT, 50 * WIDTH/HEIGHT, 20 * WIDTH/HEIGHT, f, "QUIT", "2");
UI::Button settingsButton(200 * WIDTH/HEIGHT, 50 * WIDTH/HEIGHT, 20 * WIDTH/HEIGHT, f, "SETTINGS", "3");

sf::Clock cR, rotation;

int meniu(sf::RenderWindow& win){
    std::thread inp(inputM);
    Mdisplay(win);
    inp.join();
    return 1;
}

void Mdisplay(sf::RenderWindow &win){
    sf::Time t = rotation.getElapsedTime();
    if(t.asMilliseconds() > 15){
        rotation.restart();
        rot += 0.01;
        background.setRotation(rot);
    }
    win.clear();

    win.draw(background);

    playButton.drawB(win);
    quitButton.drawB(win);
    settingsButton.drawB(win);

    win.draw(welcome);
    win.display();
}

void inputM(){
    sf::Time tR = cR.getElapsedTime();
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::S) && tR.asMilliseconds() >= 120){
        if(selectat < 3) selectat++;
        MupdateB();
        cR.restart();
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::W) && tR.asMilliseconds() >= 120){
        if(selectat > 1) selectat--;
        MupdateB();
        cR.restart();
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)){
        if(selectat == 1) {theme.stop(); Cscene = LEVELSELECTOR;}
        else if(selectat == 2) {Cscene = SETTINGS; cR.restart();}
        else if(selectat == 3){
            open = 0;
        }
        while(sf::Keyboard::isKeyPressed(sf::Keyboard::Enter));

    }
}

void MupdateB(){
    playButton.setColor(sf::Color(10, 10, 10, 255));
    quitButton.setColor(sf::Color(10, 10, 10, 255));
    settingsButton.setColor(sf::Color(10, 10, 10, 255));
    switch(selectat){
    case 1:
        playButton.setColor(sf::Color(30, 30, 30, 255));
        break;
    case 2:
        settingsButton.setColor(sf::Color(30, 30, 30, 255));
        break;
    case 3:
        quitButton.setColor(sf::Color(30, 30, 30, 255));
        break;
    }
}
