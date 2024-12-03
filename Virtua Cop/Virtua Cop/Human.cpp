#include "Human.h"

Human::Human() 
{
}

Human::~Human()
{
}

bool Human::HitCollision(sf::Sprite& cursor)
{
	if (cursor.getGlobalBounds().intersects(sprite.getGlobalBounds())) 
	{
		return true;
	}
	return false;

}

void Human::updateAnimationFrame()
{
    if (animationClock.getElapsedTime().asSeconds() > animationSpeed) {
        currentFrame = (currentFrame + 1) % frameCount;
        rectSourceSprite.left = currentFrame * animationSize.x;
        sprite.setTextureRect(rectSourceSprite);
        animationClock.restart();
    }



}
