#include "Enemy.h"
#include <iostream>
#include "TextureHelper.h"

Enemy::Enemy() 
{
}

Enemy::Enemy(int health, int damageShoot, const std::string& filePath)
{
	this->health= health;
	this->damageShoot = damageShoot;
	
}

Enemy::~Enemy()
{
}

void Enemy::Shoot(int& playerHealth)
{
	playerHealth--;
}

void Enemy::SpawnIndicator(const std::string& filePath)
{
	indicator.setPosition(sprite.getPosition().x, sprite.getPosition().y);
	TextureHelper::getInstance().loadTexture("C:/Game Development/C++/VirtuaCop/Mini-Jam1/Virtua Cop/Assets/Textures/enemy1.png", indicator);


}
