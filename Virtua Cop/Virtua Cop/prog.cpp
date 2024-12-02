#include <SFML/Graphics.hpp>
#include <box2d/box2d.h>

int main() {
    // SFML Setup
    sf::RenderWindow window(sf::VideoMode(400, 400)/*sf::VideoMode(1920, 1080)*/, "Box2D + SFML Test");
    window.setFramerateLimit(60);

    // Box2D World Setup
    b2Vec2 gravity(0.0f, -9.8f); // Gravity vector
    b2World world(gravity);

    // Ground Body (Static)
    b2BodyDef groundBodyDef;
    groundBodyDef.position.Set(0.0f, -10.0f); // Position at the bottom
    b2Body* groundBody = world.CreateBody(&groundBodyDef);

    b2PolygonShape groundBox;
    groundBox.SetAsBox(50.0f, 10.0f); // Size of the ground
    groundBody->CreateFixture(&groundBox, 0.0f); // Density = 0.0 for static objects

    // Dynamic Body (Falling Box)
    b2BodyDef dynamicBodyDef;
    dynamicBodyDef.type = b2_dynamicBody;
    dynamicBodyDef.position.Set(0.0f, 15.0f); // Starting position
    b2Body* dynamicBody = world.CreateBody(&dynamicBodyDef);

    b2PolygonShape dynamicBox;
    dynamicBox.SetAsBox(1.0f, 1.0f); // Size of the box

    b2FixtureDef fixtureDef;
    fixtureDef.shape = &dynamicBox;
    fixtureDef.density = 1.0f; // Mass density
    fixtureDef.friction = 0.3f; // Friction
    dynamicBody->CreateFixture(&fixtureDef);

    // SFML Shapes for Rendering
    sf::RectangleShape groundRect(sf::Vector2f(800.0f, 20.0f)); // Ground is a wide rectangle
    groundRect.setFillColor(sf::Color::Red);
    groundRect.setPosition(0.0f, 580.0f); // Bottom of the screen

    sf::RectangleShape boxRect(sf::Vector2f(40.0f, 40.0f)); // Box is a square
    boxRect.setFillColor(sf::Color::Green);
    boxRect.setOrigin(20.0f, 20.0f); // Center origin for proper positioning

    // Main Loop
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Box2D Simulation Step
        float timeStep = 1.0f / 60.0f; // 60 FPS
        int32 velocityIterations = 6;
        int32 positionIterations = 2;
        world.Step(timeStep, velocityIterations, positionIterations);

        // Update Box Position
        b2Vec2 position = dynamicBody->GetPosition();
        boxRect.setPosition(position.x * 40.0f + 400.0f, 600.0f - position.y * 40.0f); // Scale and translate to screen

        // Rendering
        window.clear();
        window.draw(groundRect);
        window.draw(boxRect);
        window.display();
    }

    return 0;
}
