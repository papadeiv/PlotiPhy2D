#include "ElectricField.h"

// Constructors
ElectricField::ElectricField(Mesh& mesh)
{
	field.resize(mesh.nodes.size(), sf::Vector2f(0.f, 0.f));
}

ElectricField::ElectricField(sf::Vector2i centre, bool polarity)
{
	this -> x0 = static_cast<float>(centre.x);
	this -> y0 = static_cast<float>(centre.y);
	if(polarity)
	{
		// Positive charge
		this -> flux = 0;
	}
	else
	{
		// Negative charge
		this -> flux = +180;
	}
}

// Destructor
ElectricField::~ElectricField(){}

// Accessors

// Mutators
void ElectricField::scale()
{
	float A = 10.f, B = 100.f;
	std::vector<float> scaled_rho;
	// Extract the magnitude only from the field values
	for(int j=0; j < this -> field.size(); j++)
	{
		scaled_rho.push_back(this -> field.at(j).x);
	}
	// Extract minimum(=a) and maximum(=b) values of the field
	float a = *std::min_element(scaled_rho.begin(), scaled_rho.end());
	if(a==0.f)
	{
		a = EPS;
	}
	float b = *std::max_element(scaled_rho.begin(), scaled_rho.end());
	float c = -b/a;
	// Build the affine map [a,b] -> [A,B]
	float beta = (B-c*A)/(1.f-c);
	float alpha = (A-beta)/a;
	// Scale field values
	for(int j=0; j < this -> field.size(); j++)
	{
		this -> field.at(j).x = alpha*scaled_rho.at(j) + beta;
	}

}

// Other Methods
sf::Vector2f ElectricField::getFieldValues(float x, float y)
{
	float rho =0.f, theta=0.f;
	if(sqrt(pow(this -> x0 - x, 2) + pow(this -> y0 - y, 2)) > 40)
	{
		rho = 1/(pow(this -> x0 - x, 2) + pow(this -> y0 - y, 2));
		if(this -> x0 - x > 0)
		{
			theta = this -> flux + atan((this -> y0 - y)/(this -> x0 - x))*(180/PI);
		}
		else
		{
			theta = this -> flux + atan((this -> y0 - y)/(this -> x0 - x))*(180/PI) - 180;
		}
	}

	return sf::Vector2f(rho, theta);
}

void ElectricField::update(Mesh& mesh)
{
	field.clear();
	field.resize(mesh.nodes.size(), sf::Vector2f(0.f, 0.f));
}

void ElectricField::render(sf::RenderTarget* target)
{
	for(auto* arrow: this -> arrows)
	{
		arrow -> render(target);
	}
}