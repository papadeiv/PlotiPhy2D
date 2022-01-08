#pragma once

#include "Utils.h"

class Mesh
{
	private:
		
		// Attributes
		sf::VertexArray* grid;
		int unit = 40;
		int ho,ve;

		// Methods

	public:
		
		// Constructor
		Mesh(const sf::RenderWindow& window);
		// Destructor
		virtual ~Mesh();

		// Public Attributes
		std::vector<sf::Vector2i> nodes;

		// Accessors

		// Mutators

		// Other Methods
		void update(const sf::RenderWindow& window);
		void build(const sf::RenderWindow& window);
		void render(sf::RenderTarget* target);
};