#include "Player.h"

void Player::shoot()
{
	if (bulletCount <= 6 && bulletCount > 0) {
		bulletCount -= bulletCount;
	}
	if (bulletCount <= 0) {
		//reload
	}
}

//reset the bullet to 6 when reloading
void Player::reload()
{
	bulletCount = 6;

}

int Player::getScore()
{
	return score;
}

void Player::setScore(int score)
{
	this->score = score;
}

int Player::getHelath()
{
	return helath;
}

void Player::setHelath(int helath)
{
	this->helath = helath;
}

