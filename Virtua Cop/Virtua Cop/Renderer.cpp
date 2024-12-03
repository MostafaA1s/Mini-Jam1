#include "Renderer.h"

void Renderer::AddDrawable(Drawable* drawable)
{
	drawables.push_back(drawable);
}

void Renderer::Render(RenderWindow& window)
{
	window.clear();

	for (auto d = drawables.begin(); d != drawables.end(); d++)
	{
		window.draw(**d);
	}
	window.display();
}
