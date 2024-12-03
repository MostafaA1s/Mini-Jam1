#include <iostream>
#include <SFML/Graphics.hpp>
#include "Renderer.h"

//#include <box2d/box2d.h>

void LeftMouseClicked()
{
	std::cout << "left clicked \n";
}

void RightMouseClicked()
{
	std::cout << "right clicked \n";
}

void HandelPlayerInput(sf::Window& window)
{

	sf::Event event;
	while (window.pollEvent(event)) {
		if (event.type == sf::Event::Closed)
			window.close();

		if (event.type == sf::Event::MouseButtonPressed)
		{
			if (event.mouseButton.button == sf::Mouse::Left)
			{

				LeftMouseClicked();
			}
			if (event.mouseButton.button == sf::Mouse::Right)
			{

				RightMouseClicked();
			}

		}
	}

	sf::Vector2i mousePos = sf::Mouse::getPosition(window);

	//if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	//{
	//	std::cout << "left clicked \n";
	//}

	//if (sf::Mouse::isButtonPressed(sf::Mouse::Right))
	//{
	//	std::cout << "right clicked \n";
	//}
}




void Update(float& elapsedTime, float timeSt)
{
	if (elapsedTime >= timeSt)
	{
		elapsedTime = 0.0f;
		
	}
}

int main()
{
	int windowWidth = 1920;
	int windowHeight = 1080;
	sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "7aret el sakaeen");
	Renderer renderer;
	window.setFramerateLimit(60);
	float timeStep = 1.0f / 60.0f; // 60 FPS
	sf::Clock clock;
	float elapsedTime = 0.0f;

	bool started = false;




	// Main Loop
	while (window.isOpen())
	{
		elapsedTime += clock.restart().asSeconds();

		HandelPlayerInput(window);


		Update(elapsedTime, timeStep);


		// Rendering

		renderer.Render(window);
	}

	return 0;

}
