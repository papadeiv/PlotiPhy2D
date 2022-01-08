#include "Mesh.h"

// Constructor
Mesh::Mesh(const sf::RenderWindow& window)
{
	this -> update(window);
}

// Destructor
Mesh::~Mesh(){}

// Accessors

// Mutators

// Other Methods
void Mesh::update(const sf::RenderWindow& window)
{
	// Computes number of horizontal mesh lines
	this -> ho = int(window.getSize().y)/(this -> unit);
	// Computes number of vertical mesh lines
	this -> ve = int(window.getSize().x)/(this -> unit);
	// Initialise grid object accordngly
	this -> grid = new sf::VertexArray(sf::Lines, 2*(this -> ve + this -> ho));
	// Build new grid
	this -> build(window);
}

void Mesh::build(const sf::RenderWindow& window)
{
	// Builds horizontal mesh lines
	for(int j=0, unit_multiplier=1; j < 2*(this -> ho); j+=2, unit_multiplier++)
	{
		// Builds start-point along x=0
		(*(this -> grid))[j].position = sf::Vector2f(0, unit_multiplier*(this -> unit));
		(*(this -> grid))[j].color = sf::Color(0,0,255,70);

		// Builds end-point along x=width
		(*(this -> grid))[j+1].position = sf::Vector2f(window.getSize().x, unit_multiplier*(this -> unit));
		(*(this -> grid))[j+1].color = sf::Color(255,255,0,70);
	}
	// Builds vertical mesh lines
	for(int j=2*(this -> ho), unit_multiplier=1; j < 2*(this -> ve + this -> ho); j+=2, unit_multiplier++)
	{
		// Builds start-point along y=0
		(*(this -> grid))[j].position = sf::Vector2f(unit_multiplier*(this -> unit), 0);
		(*(this -> grid))[j].color = sf::Color(255,0,0,70);

		// Builds end-point along y=height
		(*(this -> grid))[j+1].position = sf::Vector2f(unit_multiplier*(this -> unit), window.getSize().y);
		(*(this -> grid))[j+1].color = sf::Color(0,255,0,70);
	}
	// Builds nodes of the mesh
	this -> nodes.clear();
	for(int j=0; j < this -> ve; j++)
	{
		for(int k=0; k < this -> ho; k++)
		{
			this -> nodes.push_back(sf::Vector2i(j*(this -> unit), k*(this -> unit)));
		}
	}

}

void Mesh::render(sf::RenderTarget* target)
{
	target -> draw(*(this -> grid));
	
	/*for(int j=0; j < this -> nodes.size(); j++)
	{
		sf::CircleShape circle;
		circle.setFillColor(sf::Color::White);
		circle.setRadius(20.f - 0.01*j);
		circle.setPosition(this -> nodes.at(j).x - circle.getRadius(), this -> nodes.at(j).y - circle.getRadius());
		//target -> draw(circle);
		std::cout << "[x=" << nodes.at(j).x << ", y=" << nodes.at(j).y << "], r=" << circle.getRadius() << std::endl;
	}*/
}