#include "Arrow.h"

// Constructor
Arrow::Arrow(sf::Vector2f polarCoords, sf::Vector2f position)
{
	// Create the shaft of the arrow
	this -> shaft.setPosition(position);
	this -> shaft.setSize(sf::Vector2f(polarCoords.x, W/2)); // rho
	this -> shaft.rotate(polarCoords.y); // theta
	this -> shaft.setFillColor(sf::Color::Magenta);
	// Create the head of the arrow
	this -> head.setPointCount(this -> head_points);
	this -> head.setRadius(0.125*(polarCoords.x));
	this -> head.setPosition(position + sf::Vector2f(polarCoords.x*cos(polarCoords.y*PI/180), polarCoords.x*sin(polarCoords.y*PI/180)));
	this -> head.setOrigin(this -> head.getRadius(), this -> head.getRadius());
	this -> head.setRotation(polarCoords.y+90);
	this -> head.setFillColor(sf::Color::Magenta);
}

// Destructor
Arrow::~Arrow(){}

// Accessors
std::size_t Arrow::getPointCount() const
{
	return 3;
}

sf::Vector2f Arrow::getPoint(std::size_t index) const
{
	return sf::Vector2f(0.f, 0.f);
}

// Mutators

// Other Methods
void Arrow::render(sf::RenderTarget* target)
{
	target -> draw(this -> shaft);
	target -> draw(this -> head);
}
