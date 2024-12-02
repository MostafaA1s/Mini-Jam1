#pragma once
#include "Human.h"
class Enemy : public Human
{
	/*
	spawn Indicator -> (changes color from green to yellow to red )
	int damage shoot -> counter two bullets until the player is damaged
	shoot()
	*/
private: 
	int damageShoot;
	public:
		sf::Sprite indicator;

		Enemy();
		Enemy(int health, int damageShoot, const std::string& filePath);
		~Enemy();
		void Shoot(int& playerHealth);
		void SpawnIndicator(const std::string& filePath);


		
};

