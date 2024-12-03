#include "Renderer.h"

void Renderer::AddDrawable(Drawable* drawable)
{
	drawables.push_back(drawable);
}

void Renderer::AddTempDrawable(Drawable* drawable)
{
	tempDrawables.push_back(drawable);

}

void Renderer::RemoveDrawable(Drawable* drawable)
{
	drawables.remove(drawable);

}

void Renderer::Clear()
{
	tempDrawables.clear();
}


void Renderer::Render(RenderWindow& window)
{
	window.clear();
	for (auto d = drawables.begin(); d != drawables.end(); d++)
	{
		window.draw(**d);
	}
	for (auto d = tempDrawables.begin(); d != tempDrawables.end(); d++)
	{
		window.draw(**d);
	}
	window.display();
	Clear();
}
