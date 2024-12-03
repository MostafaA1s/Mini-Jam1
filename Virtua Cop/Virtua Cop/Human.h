#pragma once
#include "SFML/Graphics.hpp"
#include "string.h"
class Human
{
	
public:
	int health;
	sf::Sprite sprite;
	Human();
	virtual	~Human();
	
	virtual bool HitCollision(sf::Sprite& cursor);


};

