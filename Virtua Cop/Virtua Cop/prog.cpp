#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Player.h"
#include "Renderer.h"
#include "TextureHelper.h"
#include "Enemy.h"

enum GameState { UNDIF, MENU, GAME, EXIT, TEAM };
GameState gameState = GameState::MENU;
Player player;
list<Enemy> enemies;
sf::Font font;
//Renderer renderer;



int windowWidth = 1920;
int windowHeight = 1080;

bool gameStarted = false;


//Init All Sprites
Sprite bk, fg;
vector<Sprite> hearts;

//sf::Texture heartTexture;
//
// 
// 
//void restart() {
//	player.setHelath(1);
//}

void initializeHearts(int initialHealth) {


	hearts.clear(); 
	for (int i = 0; i < initialHealth; ++i) {
		sf::Sprite heart;
		TextureHelper::getInstance().loadTexture("Data/heart.png", heart);

		heart.setPosition(10 + i * 100, 10);
		hearts.push_back(heart);
	}
}

void updateHearts(int currentHealth, sf::Window& window) {
	for (int i = 0; i < hearts.size(); ++i) {
		hearts[i].setColor(i < currentHealth ? sf::Color::White : sf::Color(0, 0, 0, 100)); // Dim hearts that are "lost"
	}
	if (currentHealth <= 0) {
		//gameState = MENU;
		window.close();

		
	}
}

void drawHearts(sf::RenderWindow& window) {
	for (const auto& heart : hearts) {
		window.draw(heart);
	}
}


void renderMenu(sf::RenderWindow& window, GameState& gameState) {
	sf::Font font;
	if (!font.loadFromFile("Data/font.ttf")) {
		std::cerr << "Error: Failed to load font.\n";
		return;
	}


	//sf::Text title("Virtua Cop Clone", font, 50);
	//title.setPosition(300, 100);
	//title.setFillColor(sf::Color::White);

	//sf::Text startOption("Press Enter to Start", font, 30);
	//startOption.setPosition(300, 300);
	//startOption.setFillColor(sf::Color::White);
	
	sf::Sprite mainMenuSprite;
	TextureHelper::getInstance().loadTexture("Data/MainMenu.png", mainMenuSprite);
	mainMenuSprite.setOrigin(mainMenuSprite.getGlobalBounds().width / 2, mainMenuSprite.getGlobalBounds().height / 2);
	mainMenuSprite.setPosition(window.getSize().x/2, window.getSize().y / 2);





	window.clear();
	/*window.draw(title);
	window.draw(startOption);*/
	window.draw(mainMenuSprite);
	window.display();

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
		//restart();
		gameState = GAME;
	}
}

void LoadAssets()
{
	TextureHelper::getInstance().loadTexture("Data/bk.png", bk);
	bk.setOrigin(bk.getGlobalBounds().width / 2, bk.getGlobalBounds().height / 2);
	bk.setPosition(windowWidth / 2, windowHeight / 2);

	TextureHelper::getInstance().loadTexture("Data/fg.png", fg);
	fg.setOrigin(fg.getGlobalBounds().width / 2, fg.getGlobalBounds().height / 2);
	fg.setPosition(windowWidth / 2, windowHeight / 2 - 5);

	//TextureHelper::getInstance().loadTexture("Data/enemy.png", enemy);
	//enemy.setScale(0.4f, 0.4f);

	//enemy.setOrigin(enemy.getGlobalBounds().width / 2, enemy.getGlobalBounds().height / 2);
	//enemy.setPosition(250, 550);
}

void InitGame()
{
	if (gameStarted) return;
	gameStarted = true;
	initializeHearts(player.getHelath());

}


void LoadFont()
{
	if (!font.loadFromFile("Data/font.ttf")) {
		std::cerr << "Error: Failed to load font.\n";
		return;
	}
}
void renderMenu()
{

	sf::Text title("Virtua Cop Clone", font, 50);
	title.setPosition(300, 100);
	title.setFillColor(sf::Color::White);

	sf::Text startOption("Press Enter to Start", font, 30);
	startOption.setPosition(300, 300);
	startOption.setFillColor(sf::Color::White);
	//renderer.AddTempDrawable(&title);
	//renderer.AddTempDrawable(&startOption);

}


sf::Sprite cursorSprite;
void InitCursur()
{
	cursorSprite.setOrigin(cursorSprite.getGlobalBounds().width / 2, cursorSprite.getGlobalBounds().height / 2);
	cursorSprite.setScale(0.1f, 0.1f);
}
void updateCursor(sf::Window& window) {
	sf::Vector2i mousePos = sf::Mouse::getPosition(window);
	cursorSprite.setPosition(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));
}



void handleMouseClick() {

	//if (cursorSprite.getGlobalBounds().intersects(enemy.getGlobalBounds())) {
	//	std::cout << "Enemy hit!\n";
	//	// Logic to reduce enemy health
	//}
	std::cout << "left clicked \n";

	if (gameState == GAME)
	{
		for (auto& enemy : enemies)
		{
			if (enemy.isAlive && enemy.CheckCollision(cursorSprite))
			{
				std::cout << "Enemy hit!\n";
			}
		}
	}
}





void LeftMouseClicked()
{
	if (gameState == GameState::GAME)
		if (player.shoot())
			handleMouseClick();
}

void RightMouseClicked()
{
	std::cout << "right clicked \n";
	if (gameState == GameState::GAME)
		player.reload();
}

void HandelPlayerInput(sf::Window& window)
{
	updateCursor(window);
	sf::Event event;
	while (window.pollEvent(event)) {
		if (event.type == sf::Event::Closed)
			window.close();



		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && gameState == GameState::MENU)
		{
			gameState = GAME;
		}


		if (sf::Keyboard::isKeyPressed(sf::Keyboard::T) && gameState == GameState::MENU)
		{
			gameState = TEAM;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) && gameState == GameState::TEAM) {
			gameState = MENU;
			

		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) && gameState == GameState::MENU) {

			window.close();
		}

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
}




void GameLoop(sf::RenderWindow& window)
{
	updateHearts(player.getHelath(),window);

	window.clear();
	window.draw(bk);


	for (auto& enemy : enemies)
	{
		if (enemy.isAlive)
		{
			window.draw(enemy.sprite);
			window.draw(enemy.indicator);
			//enemy.updateAnimationFrame();
			enemy.UpdateIndicator();
		}
	}

	//e1.UpdateIndicator();


	window.draw(fg);




	//DrawHUD
	drawHearts(window);




	window.draw(cursorSprite);
	window.display();
}



void Update(sf::RenderWindow& window, float& elapsedTime, float timeSt)
{
	if (elapsedTime >= timeSt)
	{
		elapsedTime = 0.0f;


		if (gameState == MENU)
		{
			renderMenu(window, gameState);
		}
		else if (gameState == GAME)
		{
			InitGame();
			GameLoop(window);

		}
		
		else if (gameState == EXIT )
		{
			window.close();
		}
		else if (gameState == TEAM)
		{
			sf::Sprite teamSprite;
			TextureHelper::getInstance().loadTexture("Data/Team.png", teamSprite);
			teamSprite.setOrigin(teamSprite.getGlobalBounds().width / 2, teamSprite.getGlobalBounds().height / 2);
			teamSprite.setPosition(window.getSize().x / 2, window.getSize().y / 2);
			window.clear();
			window.draw(teamSprite);
			window.display();


		}


	}
}




int main()
{
	//sf::SoundBuffer music;
	//if (music.loadFromFile("Data/1.mp3") == false)
	//{
	//	std::cerr << "Error: Could not load music" << "\n";
	//}
	//sf::Sound bkMusic(music);
	//bkMusic.setVolume(30);
	//bkMusic.setLoop(true);
	//bkMusic.play();

	sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "7aret el sakaeen");
	window.setMouseCursorVisible(false);

	TextureHelper::getInstance().loadTexture("Data/mousecursor.png", cursorSprite);
	InitCursur();


	LoadFont();
	LoadAssets();

	window.setFramerateLimit(60);
	float timeStep = 1.0f / 60.0f; // 60 FPS
	sf::Clock clock;
	float elapsedTime = 0.0f;

	bool started = false;

	Enemy e1(1, 2, &player);

	enemies.push_back(e1);


	// Main Loop
	while (window.isOpen())
	{
		elapsedTime += clock.restart().asSeconds();

		HandelPlayerInput(window);


		Update(window, elapsedTime, timeStep);


	}

	return 0;

}
