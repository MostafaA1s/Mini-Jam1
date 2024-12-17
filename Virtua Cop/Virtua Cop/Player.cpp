#include "Player.h"
#include <iostream>

bool Player::shoot()
{
	if (bulletCount <= 6 && bulletCount > 0) 
	{
		bulletCount --;
		return true;
	}
	if (bulletCount <= 0) 
	{
		//reload
		return false;

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

void Player::IncScore(int sc)
{
	this->score += sc;

}


int Player::getHelath()
{
	std::cout << helath << "\n";
	return helath;
}

void Player::Damage(int h)
{
	helath -= h;
	std::cout <<"waaaaaaaaaaaaaaaaa222222\n";

	if (helath <= 0)
	{

	}

}

#pragma region 16 december

void Player::Reset()
{
	helath = 4; // Reset health to full
	bulletCount = 6; // Reset ammo
}
#pragma endregion





