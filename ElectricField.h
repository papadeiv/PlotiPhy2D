#pragma once

#include "Utils.h"
#include "Mesh.h"
#include "Arrow.h"

class ElectricField
{
	private:
		
		// Attributes
		float x0, y0;
		float flux;

		// Methods

	public:
		
		// Constructor
		ElectricField(Mesh& mesh);
		ElectricField(sf::Vector2i centre, bool polarity);
		// Destructor
		virtual ~ElectricField();

		// Public Attributes
		std::vector<sf::Vector2f> field; // Instantiation of vector field in polar coordinates = {magnitude: rho, angle: theta}
		std::vector<Arrow*> arrows; // Instantiation of arrows representing the vector field
		
		// Accessors

		// Mutators
		void scale();

		// Other Methods
		sf::Vector2f getFieldValues(float x, float y);
		void update(Mesh& mesh);
		void render(sf::RenderTarget* target);
};