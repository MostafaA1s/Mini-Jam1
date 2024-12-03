#pragma once
#include <SFML/Graphics.hpp>
#include <list>

using namespace sf;
using namespace std;

class Renderer
{
private:
	list<Drawable*> drawables;
	list<Drawable*> tempDrawables;

public:
	void AddDrawable(Drawable* drawable);
	void AddTempDrawable(Drawable* drawable);

	void RemoveDrawable(Drawable* drawable);
	void Clear();
	void Render(RenderWindow& window);
};

