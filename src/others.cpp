#include "../engine/others.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

extern float WIDTH, HEIGHT, DeltaTime;

double pow10(double x){
    int z = 1;
    while(x) z /= 10, x/=10;
    return z;
}
astr::entity::entity(int Hx, int Hy, int sizeX, int sizeY){
    hitbox.setSize(sf::Vector2f(Hx, Hy));
    thing.setSize(sf::Vector2f(sizeX, sizeY));
	hitbox.setFillColor(sf::Color(255, 0, 0, 120));
}
void astr::entity::setPosition(float x, float y){
	hitbox.setPosition(x, y);
    thing.setPosition(x, y);
} 
void astr::entity::rotate(double angle){
    thing.rotate(angle);
    hitbox.rotate(angle);
}  
sf::Vector2f astr::entity::getPosition(){
    return hitbox.getPosition();
}
sf::Vector2f astr::entity::getSize(){
    return hitbox.getSize();
}
void astr::entity::setOrigin(float x, float y){
    hitbox.setOrigin(x, y);
    thing.setOrigin(x, y);
}
void astr::entity::SetRot(double angle){
    hitbox.setRotation(angle);
    thing.setRotation(angle);
}
void astr::entity::setSize(sf::Vector2f s){
    hitbox.setSize(s);
    thing.setSize(s);
}
void astr::entity::setSize(float x, float y){
    hitbox.setSize(sf::Vector2f(x, y));
    thing.setSize(sf::Vector2f(x, y));
}
void astr::entity::setDebugging(bool a){
    isInDebugging = a;
}
void astr::entity::draw(sf::RenderWindow &w){
    w.draw(thing);
    if(isInDebugging) w.draw(hitbox);
}


UI::Button::Button(int sizeX, int sizeY, int fontSize, sf::Font &fn, std::string text, std::string tags = ""){
    hitbox.setSize(sf::Vector2f(sizeX, sizeY));

    buttonText.setFont(fn);
    buttonText.setCharacterSize(fontSize);
    buttonText.setString(text);

    tag = tags;
}

void UI::Button::setPosition(float x, float y){
   hitbox.setPosition(x, y);
   buttonText.setPosition(x , y + hitbox.getSize().y/2);
}
void UI::Button::setText(std::string s){
    buttonText.setString(s);
}
void UI::Button::setColor(sf::Color color){
    hitbox.setFillColor(color);
}

sf::Vector2f UI::Button::getPosition(){
    return hitbox.getPosition();
}
void UI::Button::drawB(sf::RenderWindow &w){
    w.draw(hitbox);
    w.draw(buttonText);
}

UI::Slider::Slider(int size, int lenght, int Csize, sf::Font &fn, std::string txt){
    text.setFont(fn);
    text.setCharacterSize(Csize);

    bar.setSize(sf::Vector2f(size/3, size));
    bar.setOrigin(bar.getSize().x/2, bar.getSize().y/2);

    line.setSize(sf::Vector2f(lenght, 10));
    line.setOrigin(0, 5);
    setText(txt);
}

void UI::Slider::setPosition(float x, float y){
    line.setPosition(x, y);
    text.setPosition(x + line.getSize().x + 50, line.getPosition().y);
    setValue(value);
}
void UI::Slider::setTextPos(float x, float y){
    text.setPosition(x, y);
}
void UI::Slider::setText(std::string s){
    text.setString(s);
}
void UI::Slider::setColor(sf::Color c){
    bar.setFillColor(c);
}
void UI::Slider::setValue(int val){
    value = val;
    bar.setPosition(line.getPosition().x + value * line.getSize().x/max, line.getPosition().y);
}

void UI::Slider::draw(sf::RenderWindow &w){
    w.draw(text);
    w.draw(line);
    w.draw(bar);
}

int UI::Slider::getValue(){return value;}
