#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/System/Vector2.hpp>

extern float WIDTH, HEIGHT, DeltaTime;

double pow10(double);

namespace astr{
	class entity{
	private:
		bool isInDebugging = false;
	public:
		sf::RectangleShape hitbox, thing;
		entity(int, int, int, int);
	
		void setPosition(float, float);
		void rotate(double);
	
		sf::Vector2f getPosition();				
		sf::Vector2f getSize();
	
		void setOrigin(float, float);			
		void SetRot(double);
		void setSize(float, float);
		void setSize(sf::Vector2f);
		void setDebugging(bool);

		void draw(sf::RenderWindow&);
	};

}; //end of namespace astr

namespace UI{

class Button{
public:
	sf::Text buttonText;
	sf::RectangleShape hitbox;
	std::string tag;

	Button(int, int, int, sf::Font&, std::string, std::string);
	//setters

	void setPosition(float, float);
	void setText(std::string);
	void setColor(sf::Color color);

	sf::Vector2f getPosition();

	void drawB(sf::RenderWindow&);
};

class Slider{
	int max = 100, value{0};
public:
	bool inUse{false};
	sf::RectangleShape bar, line; 		sf::Text text;


	Slider(int, int, int, sf::Font&, std::string);
	
	void setPosition(float, float);
	void setTextPos(float, float);
	void setText(std::string s);
	void setColor(sf::Color);
	void setValue(int);

	int getValue(void);

	void draw(sf::RenderWindow&);
	

};

}; //end of namespace UI
