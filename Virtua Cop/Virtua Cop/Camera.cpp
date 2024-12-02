#include "Camera.h"
#include <SFML/Graphics.hpp>

// Constructor
Camera::Camera(sf::RenderWindow& window, sf::Vector2f& defaultPosition, float transitionSpeed)
    : window(window), defaultPosition(defaultPosition), transitionSpeed(transitionSpeed), currentPosition(defaultPosition) {
    // Initialize the view to cover the whole window
    view.setSize(static_cast<sf::Vector2f>(window.getSize()));
    view.setCenter(defaultPosition);
    window.setView(view);
}

// Update method
void Camera::Update(float deltaTime, sf::Vector2f* enemyPosition) {
    // Determine target position
    if (enemyPosition) {
        targetPosition = *enemyPosition;
    }
    else {
        targetPosition = defaultPosition;
    }

    //Smoothly interpolate between the current position and the target position
    currentPosition.x += (targetPosition.x - currentPosition.x) * transitionSpeed * deltaTime;
    currentPosition.y += (targetPosition.y - currentPosition.y) * transitionSpeed * deltaTime;

    //Apply the updated position to the view
    view.setCenter(currentPosition);
    window.setView(view);
}
