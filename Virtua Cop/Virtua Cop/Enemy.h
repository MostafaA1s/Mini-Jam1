#pragma once
#include "Human.h"

#include "Player.h"

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
	bool isAlive = true;
	Player* p;
	Enemy();
	Enemy(int health, int damageShoot, Player* p, float x = 550, float y = 600);
	~Enemy();
	void Shoot(bool isPaused);

	void SpawnIndicator();

	void UpdateIndicator(bool isPaused);


	bool CheckCollision(const sf::Sprite& cursor);
	void TakeDamage(int damage);
	void Die();



};

