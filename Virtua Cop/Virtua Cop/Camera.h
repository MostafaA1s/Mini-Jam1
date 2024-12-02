#pragma once
class Camera
{
private:
    sf::RenderWindow& window;
    sf::View view;
    sf::Vector2f defaultPosition;
    sf::Vector2f currentPosition;
    sf::Vector2f targetPosition;
    float transitionSpeed; // Speed of camera transitions
public:
	Camera(sf::RenderWindow& window, sf::Vector2f& defaultPosition, float transitionSpeed = 5.0f);
	//updating the camera focus
	void Update(float deltaTime, sf::Vector2f* enemyPosition);
};

