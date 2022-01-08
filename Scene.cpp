#include "Scene.h"

// Constructor
Scene::Scene()
{
	this -> window = nullptr;
	this -> window = new sf::RenderWindow(sf::VideoMode(1920,1080), "Electric field visualiser", sf::Style::Default);
	this -> window -> setFramerateLimit(60);
	this -> view = this -> window -> getDefaultView();
	this -> mesh = new Mesh(*this -> window);

	this -> E = new ElectricField(*this -> mesh);
	this -> E0 = new ElectricField(*this -> mesh);
}

// Destructor
Scene::~Scene()
{
	delete this -> window;
}

// Accessors

// Mutators

// Other Methods 
bool Scene::running()
{
	return this -> window -> isOpen();
}

void Scene::update()
{
	while(this -> window -> pollEvent(this -> event))
	{
		switch(this -> event.type)
		{
			case sf::Event::Closed: this -> window -> close();
				break;

			case sf::Event::KeyPressed:
				break;

			case sf::Event::Resized:
				view.setSize({static_cast<float>(event.size.width), static_cast<float>(event.size.height)});
				this -> window -> setView(view);
				this -> mesh -> update(*this -> window);

				this -> E -> update(*this -> mesh);
				this -> E0 -> update(*this -> mesh);
				break;

			case sf::Event::MouseButtonPressed:
				if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
	            {
	              // Add negatively charged parricle to the distribution (i.e. polarity=false)
	              this -> distribution.push_back(new Charge(*this -> window, sf::Mouse::getPosition(*this -> window), false));
	            }
	            else if(sf::Mouse::isButtonPressed(sf::Mouse::Right))
	            {
	              // Add positievly charged parricle to the distribution (i.e. polarity=true)
	              this -> distribution.push_back(new Charge(*this -> window, sf::Mouse::getPosition(*this -> window), true));
	            }
	            // Compute electric field of the charge (magnitude = rho, direction = theta) @ current node
				for(int c=0; c<(this -> mesh -> nodes.size()); c++)
				{
					this -> E0 -> field.at(c) = distribution.back() -> E_c -> getFieldValues(static_cast<float>(this -> mesh -> nodes.at(c).x),
																							 static_cast<float>(this -> mesh -> nodes.at(c).y));
				}
				// Maps the field values continuosly in [0,1] for scaling purposing on the window
				this -> E0 -> scale();
				// Adds the scaled field contribution of the last charge to the total field
				for(int c=0; c<(this -> mesh -> nodes.size()); c++)
				{
					this -> E -> field.at(c).x += this -> E0 -> field.at(c).x; // Compute magnitude
					this -> E -> field.at(c).y += this -> E0 -> field.at(c).y; // Compute direction
				}
				// Final scale of the total field after having summed the latest contribution
				this -> E -> scale();
				// Computes the arrow field associated to the scaled total field
				this -> E -> arrows.clear();
				for(int c=0; c<(this -> mesh -> nodes.size()); c++)
				{
					this -> E -> arrows.push_back(new Arrow(sf::Vector2f(this -> E -> field[c].x, this -> E -> field[c].y),
															sf::Vector2f(static_cast<float>(this -> mesh -> nodes.at(c).x), 
																		 static_cast<float>(this -> mesh -> nodes.at(c).y))));
				}
	            break;
		}
	}
}

void Scene::render()
{
	// Clearing window from previous frame
	this -> window -> clear(sf::Color::Black);

	// Rendering objects in the current frame
	this -> mesh -> render(this -> window); // Computational mesh
	// Total electric field
	this -> E -> render(this -> window);
	// Discrete (point-like) charge's distribution
	for(auto* charge: this -> distribution)
	{
		charge -> render(this -> window);
	}

	// Ending the frame-loop by displaying rendered objects
	this -> window -> display();
}