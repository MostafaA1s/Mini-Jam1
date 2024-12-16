#pragma once
#include "SFML/Graphics.hpp"
#include "string.h"
class Human
{
	
public:
	int health;
	sf::Sprite sprite;
	sf::Clock movementClock;
#pragma region Animation
	//sf::IntRect rectSourceSprite;
	//sf::Clock animationClock;
	//int frameCount;
	//int currentFrame;
	//int animationSpeed;
	//sf::Vector2i animationSize;
#pragma endregion
	Human();
	virtual	~Human();
	
	virtual bool HitCollision(sf::Sprite& cursor);

	void updateAnimationFrame();

	
};

