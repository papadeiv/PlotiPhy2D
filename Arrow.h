#pragma once

#include "Utils.h"

class Arrow: public sf::Shape
{
	private:

		// Attributes
		sf::RectangleShape shaft;
		sf::CircleShape head;
		std::size_t head_points=3;

		// Methods

	public:

		// Constructor
		Arrow(sf::Vector2f polarCoords, sf::Vector2f position);
		// Destructor
		~Arrow();

		// Accessors
		std::size_t getPointCount() const;
		sf::Vector2f getPoint(std::size_t index) const;

		// Mutators

		// Other Methods
		void render(sf::RenderTarget* target);

};