#include "SFML/Graphics.hpp"
#include <cmath> // For pow()
#include <iostream>
#include "Enemy.h"

int main(int argc, char** argv) {
    Enemy enemy;
    sf::Sprite cursor;
    enemy.HitCollision(cursor);

    sf::RenderWindow renderWindow(sf::VideoMode(1780, 1000), "Demo Game");
    float translationSpeed = 0.3f; // Time for frame change
    sf::Event event;

    sf::Texture texture;
    texture.loadFromFile("C:/Game Development/C++/VirtuaCop/Mini-Jam1/Virtua Cop/Assets/Animation/DeathAnimation.png");
    int frameSizeY = 960;
    sf::IntRect rectSourceSprite(0, 0, 540, frameSizeY); // Assuming width 540, height 960 per frame
    sf::Sprite sprite(texture);
    sprite.setTextureRect(rectSourceSprite);

    sprite.setOrigin(sprite.getLocalBounds().width / 2, sprite.getLocalBounds().height / 2);
    sprite.setScale(0.5, 0.5);
    sprite.setPosition(renderWindow.getSize().x / 2, renderWindow.getSize().y / 2);

    sf::Clock frameClock;

    

    int frameCount = 3;
    int currentFrame = 0;
    int frameSizeX = 540;
  

    while (renderWindow.isOpen()) {
        while (renderWindow.pollEvent(event)) {
            if (event.type == sf::Event::EventType::Closed)
                renderWindow.close();
        }

        // Handle animation frame changes
        if (frameClock.getElapsedTime().asSeconds() > translationSpeed) 
        {
            currentFrame = (currentFrame + 1) % frameCount; // Loop through 0, 1, 2
            rectSourceSprite.left = currentFrame * frameSizeX;    // Update frame based on currentFrame
            sprite.setTextureRect(rectSourceSprite);
            frameClock.restart();
        }

    
      

        renderWindow.clear();
        renderWindow.draw(sprite);
        renderWindow.display();
    }

    return 0;
}
