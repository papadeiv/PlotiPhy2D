#include "Charge.h"

// Constructor
Charge::Charge(const sf::RenderWindow& window, sf::Vector2i mouseWindowPosition, bool polarity)
{
	this -> shape.setRadius(R);
	this -> shape.setPosition(window.mapPixelToCoords(sf::Vector2i(mouseWindowPosition.x - static_cast<int>(this -> shape.getRadius()), 
																   mouseWindowPosition.y - static_cast<int>(this -> shape.getRadius()))));
	this -> E_c = new ElectricField(sf::Vector2i(mouseWindowPosition.x, mouseWindowPosition.y), polarity);

	this -> horbar.setSize(sf::Vector2f(R, W));
	this -> horbar.setPosition(window.mapPixelToCoords(sf::Vector2i(mouseWindowPosition.x - static_cast<int>(R/2), mouseWindowPosition.y - static_cast<int>(W/2))));
	this -> horbar.setFillColor(sf::Color::Black);

	if(polarity)
	{
		// Positive charge
		this -> verbar.setSize(sf::Vector2f(R, W));
		this -> verbar.setPosition(window.mapPixelToCoords(sf::Vector2i(mouseWindowPosition.x + static_cast<int>(W/2), mouseWindowPosition.y - static_cast<int>(R/2))));
		this -> verbar.rotate(90);
		this -> verbar.setFillColor(sf::Color::Black);

		this -> shape.setFillColor(sf::Color(255,50,50));
	}
	else
	{
		// Negative charge
		this -> verbar.setSize(sf::Vector2f(0.f, 0.f));
		this -> shape.setFillColor(sf::Color(50,50,255));
	}
}

// Destructor
Charge::~Charge(){}

// Accessors

// Mutators

// Other Methods
void Charge::render(sf::RenderTarget* target)
{
	target -> draw(this -> shape);
	target -> draw(this -> horbar);
	target -> draw(this -> verbar);
}