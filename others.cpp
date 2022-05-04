#pragma once
#include <SFML/Graphics.hpp>

double pow10(double x){
    int z = 1;
    while(x) z /= 10, x/=10;
    return z;
}
namespace astr{
    class entity{
        private:
            bool isInDebugging = false;
        public:
        sf::RectangleShape hitbox;
        sf::RectangleShape thing;
        entity(){
            
        }
        entity(int Hx, int Hy, int sizeX, int sizeY){
            hitbox.setSize(sf::Vector2f(Hx, Hy));
            thing.setSize(sf::Vector2f(sizeX, sizeY));
            hitbox.setFillColor(sf::Color(255, 0, 0, 120));
        }
        void setPosition(float x, float y){
            hitbox.setPosition(x, y);
            thing.setPosition(x, y);
        } 
        void rotate(double angle){
            thing.rotate(angle);
            hitbox.rotate(angle);
        }  
        sf::Vector2f getPosition(){
            return hitbox.getPosition();
        }
        sf::Vector2f getSize(){
            return hitbox.getSize();
        }
        void setOrigin(float x, float y){
            hitbox.setOrigin(x, y);
            thing.setOrigin(x, y);
        }
        void SetRot(double angle){
            hitbox.setRotation(angle);
            thing.setRotation(angle);
        }
        void setSize(sf::Vector2f s){
            hitbox.setSize(s);
            thing.setSize(s);
        }
        void setSize(float x, float y){
            hitbox.setSize(sf::Vector2f(x, y));
            thing.setSize(sf::Vector2f(x, y));
        }
        void setDebugging(bool a){
            isInDebugging = a;
        }
        void draw(sf::RenderWindow &w){
            w.draw(thing);
            if(isInDebugging) w.draw(hitbox);
        }
    };
};


namespace UI{
    class Button{
    public:
        sf::Text buttonText;
        sf::RectangleShape hitbox;
        std::string tag;

        Button(int sizeX, int sizeY, int fontSize, sf::Font &fn, std::string text, std::string tags = ""){
            hitbox.setSize(sf::Vector2f(sizeX, sizeY));

            buttonText.setFont(fn);
            buttonText.setCharacterSize(fontSize);
            buttonText.setString(text);

            tag = tags;
        }


        void setPosition(float x, float y){
            hitbox.setPosition(x, y);
            buttonText.setPosition(x , y + hitbox.getSize().y/2);
        }
        void setText(std::string s){
            buttonText.setString(s);
        }
        void setColor(sf::Color color){
            hitbox.setFillColor(color);
        }

        sf::Vector2f getPosition(){
            return hitbox.getPosition();
        }
        void drawB(){
            win.draw(hitbox);
            win.draw(buttonText);
        }
        void drawB(sf::RenderWindow &w){
            w.draw(hitbox);
            w.draw(buttonText);
        }
    };
    class Slider{
    public:
        int max = 100;
        int value = 0;
        sf::RectangleShape bar;
        sf::RectangleShape line;
        sf::Text text;
        bool inUse = 0;

        Slider(int size, int lenght, int Csize, sf::Font &fn, std::string txt){
            text.setFont(fn);
            text.setCharacterSize(Csize);

            bar.setSize(sf::Vector2f(size/3, size));
            bar.setOrigin(bar.getSize().x/2, bar.getSize().y/2);

            line.setSize(sf::Vector2f(lenght, 10));
            line.setOrigin(0, 5);
            setText(txt);
        }

        void setPosition(float x, float y){
            line.setPosition(x, y);
            text.setPosition(x + line.getSize().x + 50, line.getPosition().y);
            setValue(value);
        }
        void setTextPos(float x, float y){
            text.setPosition(x, y);
        }
        void setText(std::string s){
            text.setString(s);
        }
        void setColor(sf::Color c){
            bar.setFillColor(c);
        }
        void setValue(int val){
            value = val;
            bar.setPosition(line.getPosition().x + value * line.getSize().x/max, line.getPosition().y);
        }
        void draw(){
            win.draw(text);
            win.draw(line);
            win.draw(bar);
        }

        void draw(sf::RenderWindow &w){
            w.draw(text);
            w.draw(line);
            w.draw(bar);
        }

        int getValue(){return value;}
    };
};