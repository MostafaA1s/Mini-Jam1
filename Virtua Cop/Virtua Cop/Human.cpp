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
