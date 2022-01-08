#pragma once

#include "Utils.h"
#include "Charge.h"
#include "Mesh.h"

class Scene
{
	private:
		
		// Attributes
		sf::RenderWindow* window;
		sf::Event event;
		sf::View view;
		Mesh* mesh;

		std::vector<Charge*> distribution;
		ElectricField* E; // Total field, scaled (distribution's)
		ElectricField* E0;// Trial field, unscaled (single charge contribution)
		
		// Methods

	public:
		
		// Constructor
		Scene();
		// Destructor 
		virtual ~Scene();
		
		// Accessors
		void print();
		
		// Mutators

		// Other Methods
		bool running();
		void update();
		void render();
};