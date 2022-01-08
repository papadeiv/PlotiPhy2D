#pragma once

#include "Utils.h"
#include "ElectricField.h"

class Charge
{
	private:
		
		// Attributes
		sf::CircleShape shape;
		sf::RectangleShape horbar, verbar;
		
		// Methods

	public:
		
		// Constructor
		Charge(const sf::RenderWindow& window, sf::Vector2i mouseWindowPosition, bool polarity);
		// Destructor 
		virtual ~Charge();

		// Public Attributes
		ElectricField* E_c;
		
		// Accessors

		// Mutators

		// Other Methods
		void render(sf::RenderTarget* target);
};