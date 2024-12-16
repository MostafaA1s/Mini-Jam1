#pragma once
#include "Human.h"
class Enemy : public Human
{
	/*
	spawn Indicator -> (changes color from green to yellow to red )
	int damage shoot -> counter two bullets until the player is damaged
	shoot()
	*/
	public:
		int damageShoot;
		sf::Sprite indicator;
		sf::Clock indicatorColorClock; // when can the indicator color changes
		sf::Clock shootClock; // when can the enemy shoots
		

		Enemy();
		Enemy(int health, int damageShoot);
		~Enemy();
		void Shoot();

		void SpawnIndicator(const std::string& filePath, sf::Window& window);

		void UpdateIndicator();

		void setEnemySprite(const std::string& filePath, sf::Window& window);



		
};

