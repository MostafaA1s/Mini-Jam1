#pragma once
#include <SFML/Graphics.hpp>
#include <list>

using namespace sf;
using namespace std;

class Renderer
{
private:
	list<Drawable*> drawables;
public:
	void AddDrawable(Drawable* drawable);
	void Render(RenderWindow& window);
};

