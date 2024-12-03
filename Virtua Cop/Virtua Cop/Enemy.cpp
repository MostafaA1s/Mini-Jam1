#include "Enemy.h"
#include <iostream>
#include "TextureHelper.h"

Enemy::Enemy() 
{
}

Enemy::Enemy(int health, int damageShoot)
{
	this->health= health;
	this->damageShoot = damageShoot;

	
}

Enemy::~Enemy()
{
}




void Enemy::SpawnIndicator(const std::string& filePath, sf::Window& window) {
    TextureHelper::getInstance().loadTexture(filePath, indicator);
    indicator.setOrigin(indicator.getGlobalBounds().width / 2, indicator.getGlobalBounds().height / 2);
    indicator.setPosition(sprite.getPosition().x - 300, sprite.getPosition().y - 300);
    indicator.setColor(sf::Color::Blue);

}
/// <summary>
/// The enemy shoots once doesn't hit shoots again doesn't hit. 
/// third he damages the player
/// </summary>
void Enemy::Shoot() 
{
    float elapsed = shootClock.getElapsedTime().asSeconds();

    if (damageShoot > 1.f)
    {
        //Player is damaged
        std::cout << "damaging\n" + damageShoot << "\n";
        shootClock.restart(); if (damageShoot <= 0)
        {//Player is damaged
        
    } else {
            damageShoot--;
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

        indicator.setColor(sf::Color::Red);
        Shoot();
    }
    else if (elapsed > 3.f) {


        indicator.setColor(sf::Color::Yellow);
    }
    else if (elapsed > .5f) {
        indicator.setColor(sf::Color::Green);
    }
}

void Enemy::setEnemySprite(const std::string& filePath, sf::Window& window)
{
	TextureHelper::getInstance().loadTexture(filePath, sprite);
	sprite.setOrigin(sprite.getGlobalBounds().width / 2, sprite.getGlobalBounds().height / 2);
	sprite.setPosition(window.getSize().x / 2, window.getSize().y / 2);
}
