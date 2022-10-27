#include "../engine/bullet.hpp"
#include <SFML/Graphics/RenderWindow.hpp>


#define glonT glont[i]

extern float WIDTH;
extern float HEIGHT;
extern float DeltaTime;


bullet::bullet(float x, float y, float w, float h){
     b.setFillColor(sf::Color::White);
     b.setSize(sf::Vector2f(w, h));
     is_alive = true;
     bx = x;
     by = y;
     bW = w;
     bH = h;
}

void bullet::bulletDraw(sf::RenderWindow& win){ if(is_alive) win.draw(b); }
void bullet::update(){
	bx += 200 * WIDTH/HEIGHT * DeltaTime;
	b.setPosition(bx, by);
}
