#pragma once
#include "SFML/Graphics.hpp"
#include "string.h"
class Human
{
	
public:
	int health;
	sf::Sprite sprite;

#pragma region Animation
	sf::IntRect rectSourceSprite;
	sf::Clock animationClock;
	int frameCount=3;
	int currentFrame=2;
	int animationSpeed;
	sf::Vector2i animationSize;
	
#pragma endregion
	Human();
	virtual	~Human();
	
	virtual bool HitCollision(sf::Sprite& cursor);

#pragma region Animation

	void updateAnimationFrame();
#pragma endregion

};

