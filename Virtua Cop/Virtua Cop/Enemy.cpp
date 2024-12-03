#include "Enemy.h"
#include <iostream>
#include "TextureHelper.h"


Enemy::Enemy()
{
}

Enemy::Enemy(int health, int damageShoot, Player* player)
{
	this->health = health;
	this->damageShoot = damageShoot;
	this->p = player;
	TextureHelper::getInstance().loadTexture("Data/enemy.png", sprite);

	sprite.setOrigin(sprite.getGlobalBounds().width / 2, sprite.getGlobalBounds().height / 2);
	sprite.setPosition(350, 650);
	sprite.setScale(0.4f, 0.4f);
	SpawnIndicator();


}

Enemy::~Enemy()
{
}




void Enemy::SpawnIndicator()
{
	TextureHelper::getInstance().loadTexture("Data/ind.png", indicator);
	indicator.setScale(0.3f, 0.3f);
	indicator.setOrigin(indicator.getGlobalBounds().width / 2, indicator.getGlobalBounds().height / 2);
	indicator.setPosition(sprite.getPosition().x - 90, sprite.getPosition().y - 110);
	//indicator.setColor(sf::Color::Blue);

}
/// <summary>
/// The enemy shoots once doesn't hit shoots again doesn't hit. 
/// third he damages the player
/// </summary>
void Enemy::Shoot()
{
	float elapsed = shootClock.getElapsedTime().asSeconds();
	//std::cout << elapsed << "\n";

	if (elapsed > 1.f)
	{
		//Player is damaged

		if (damageShoot <= 0)
		{//Player is damaged
			std::cout << "SHOOT PLAYER" << "\n";

			p->Damage(1);
			damageShoot = 3;
		}
		else
		{
			std::cout << "  TRYING TO damagE" + damageShoot << "\n";
			damageShoot--;
			shootClock.restart();

		}
	}

}

/// <summary>
/// changing the color of the indicator over time
/// </summary>

void Enemy::UpdateIndicator() {
	float elapsed = indicatorColorClock.getElapsedTime().asSeconds();

	if (elapsed > 6.f)
	{
		this->indicator.setColor(sf::Color::Red);
		Shoot();
	}
	else if (elapsed > 3.f) {


		this->indicator.setColor(sf::Color::Yellow);
	}
	else if (elapsed > .5f) {
		this->indicator.setColor(sf::Color::Green);
	}

}

bool Enemy::CheckCollision(const sf::Sprite& cursor)
{
	if (cursor.getGlobalBounds().intersects(sprite.getGlobalBounds())) {
		TakeDamage(1);
		return true;
	}
	return false;
}

void Enemy::TakeDamage(int damage)
{
	if (!isAlive) return;
	health -= damage;
	if (health <= 0) {
		Die();
	}
}

void Enemy::Die()
{

#pragma region Animation
	frameCount = 3;
	currentFrame = 0;
	animationSpeed = 0.3f;
	sprite.setTextureRect(rectSourceSprite);
	animationSize.x = 540;
	animationSize.y = 960;
	rectSourceSprite = sf::IntRect(0, 0, animationSize.x, animationSize.y);
	TextureHelper::getInstance().loadTexture("Data/deathAnimation.png", sprite);

	updateAnimationFrame();
#pragma endregion
	std::cout << "Enemy Died!\n";

	isAlive = false;
}