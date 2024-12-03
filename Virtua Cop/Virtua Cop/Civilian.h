#pragma once
#include "Human.h"
class Civilian : public Human
{
public:
	Civilian();
	~Civilian();
	Civilian(sf::Sprite& sprite, int health);
};

