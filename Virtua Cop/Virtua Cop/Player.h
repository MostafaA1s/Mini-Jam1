#pragma once
class Player
{
private:
	int score = 0;
	int helath = 4;
	int bulletCount = 6;


public:
	int getScore();
	void IncScore(int score);
	bool shoot();
	void reload();
	int getHelath();
	void setHelath(int health);
	void Damage(int helath);

};

