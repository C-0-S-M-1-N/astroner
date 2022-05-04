#pragma once
#include <SFML/Audio.hpp>
#include "others.cpp"

UI::Button backButton(200 * WIDTH/HEIGHT, 50 * WIDTH/HEIGHT, 20 * WIDTH/HEIGHT, f, "BACK");
UI::Slider sound(50 * WIDTH/HEIGHT, 200 * WIDTH/HEIGHT, 20 * WIDTH/HEIGHT, f, "SOUND(0%)");
int selecte = 1;
sf::Keyboard::Key k[2] = {sf::Keyboard::Key::Space, sf::Keyboard::Key::Escape};


void Sdisplay();
void Sinput();
void Supdate();

int settings(){
    std::thread t1(Sinput);
    Sdisplay();
    t1.join();

    return 1;
}

void Sdisplay(){
    sf::Time t = rotation.getElapsedTime();
    if(t.asMilliseconds() > 15){
        rotation.restart();
        rot += 0.01;
        background.setRotation(rot);
    }
    win.clear();
    win.draw(background);
    

    backButton.drawB();
    sound.draw();

    win.display();
}

void Sinput(){
    Time t = cR.getElapsedTime();
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::S) && t.asMilliseconds() >= 200){
        if(selecte < 3) selecte ++;
        Supdate();
        cR.restart();
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::W) && t.asMilliseconds() >= 200){
        if(selecte > 1) selecte--;
        Supdate();
        cR.restart();
    }
    if(selecte == 2 && sf::Keyboard::isKeyPressed(sf::Keyboard::A) && t.asMilliseconds() >= 100){
        if(sound.getValue() > 0) sound.setValue(sound.getValue() - 1);
        sound.inUse = 1;
        Supdate();
        cR.restart();
    }
    else if(selecte == 2 && sf::Keyboard::isKeyPressed(sf::Keyboard::D) && t.asMilliseconds() >= 100){
        if(sound.getValue() < 100) sound.setValue(sound.getValue() + 1);
        sound.inUse = 1;
        Supdate();
        cR.restart();
    }
    if(!sf::Keyboard::isKeyPressed(sf::Keyboard::A) && !sf::Keyboard::isKeyPressed(sf::Keyboard::D) && sound.inUse == 1){
        sound.inUse = 0;
        Supdate();
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) Cscene = MENIU;
}

void Supdate(){
    backButton.setColor(sf::Color(10, 10, 10, 255));
    sound.setColor (sf::Color(200, 200, 200, 255));

    switch(selecte){
    case 1:
        backButton.setColor(sf::Color(30, 30, 30, 255));
        break;
    case 2:
        if(sound.inUse) sound.setColor(sf::Color(90, 90, 90, 255));
        else sound.setColor(sf::Color(140, 140, 140, 255));
        sound.setText("SOUND("+ std::to_string(sound.getValue()) + "%)");
        theme.setVolume(sound.getValue()%101);
        break;
    }
}



