#pragma once
class Player
{
private:
	int score = 0;
	int helath = 4;
	int bulletCount = 6;
	void shoot();
	void reload();

public:
	int getScore();
	void setScore(int score);

	int getHelath();
	void setHelath(int helath);

};

