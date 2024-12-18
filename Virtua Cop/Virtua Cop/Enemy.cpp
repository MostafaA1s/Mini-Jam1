#include "Enemy.h"
#include <iostream>
#include "TextureHelper.h"


Enemy::Enemy()
{
}

Enemy::Enemy(int health, int damageShoot, Player* player, float x , float y)
{
	this->health = health;
	this->damageShoot = damageShoot;
	this->p = player;
	TextureHelper::getInstance().loadTexture("Data/enemy.png", sprite);

	sprite.setOrigin(sprite.getGlobalBounds().width / 2, sprite.getGlobalBounds().height / 2);
	sprite.setPosition(x, y);
	sprite.setScale(0.35f, 0.35f);
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
/// The enemy shoots once, doesn't hit, shoots again, doesn't hit.
/// On the third attempt, the enemy damages the player.
/// </summary>
void Enemy::Shoot(bool isPaused) // 16 december
{
	// Accumulate elapsed time only if not paused

	if (isPaused)
		return; // Do nothing when paused

	float elapsed = shootClock.getElapsedTime().asSeconds();

	if (elapsed > 1.f) // Shoot every 1 second
	{
		if (damageShoot <= 1)
		{
			// Damage the player on the third shot
			std::cout << "SHOOT PLAYER" << "\n";
			p->Damage(1);
			damageShoot = 3; // Reset the counter
		}
		else
		{
			// Missed shot
			std::cout << "TRYING TO DAMAGE: " << damageShoot << "\n";
			damageShoot--;
		}

		shootClock.restart(); // Restart clock after shooting
	}
}


/// <summary>
/// Changes the color of the indicator over time.
/// </summary>
void Enemy::UpdateIndicator(bool isPaused) // 16 december
{
	static sf::Time totalPausedTime;     // Time accumulated while paused
	static sf::Time pauseStartTime;      // When pause starts

	if (isPaused)
	{
		// On pause, track the time when pausing started
		if (pauseStartTime == sf::Time::Zero)
		{
			pauseStartTime = indicatorColorClock.getElapsedTime();
		}
		return; // Exit when paused
	}
	else if (pauseStartTime != sf::Time::Zero)
	{
		// On resume, add the paused duration to totalPausedTime
		totalPausedTime += indicatorColorClock.getElapsedTime() - pauseStartTime;
		pauseStartTime = sf::Time::Zero;
	}

	// Calculate effective elapsed time (excluding pauses)
	float elapsed = (indicatorColorClock.getElapsedTime() - totalPausedTime).asSeconds();

	// Update indicator colors based on elapsed time
	if (elapsed > 6.f)
	{
		this->indicator.setColor(sf::Color::Red);
		Shoot(isPaused); // Call Shoot when the time exceeds 6 seconds
	}
	else if (elapsed > 3.f)
	{
		this->indicator.setColor(sf::Color::Yellow);
	}
	else if (elapsed > 0.5f)
	{
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