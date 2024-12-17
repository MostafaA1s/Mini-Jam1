#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Player.h"
#include "Renderer.h"
#include "TextureHelper.h"
#include "Enemy.h"

enum GameState { UNDIF, MENU, GAME, EXIT, TEAM , PAUSE}; // 16 december
GameState gameState = GameState::MENU;
Player player;
list<Enemy> enemies;
sf::Font font;
//Renderer renderer;
vector<sf::Vector2i> buttonsPositions; // 16 december



int windowWidth = 1920;
int windowHeight = 1080;

bool gameStarted = false;


//Init All Sprites
Sprite bk, fg;
vector<Sprite> hearts;

//sf::Texture heartTexture;
//void spawnEnemy()
//{
//	Enemy newEnemy(5, 1, &player);
//
//
//	// Randomize position
//
//	float x = static_cast<float>(rand() % 1920);
//	float y = static_cast<float>(rand() % 1080);
//	newEnemy.sprite.setPosition(x, y);
//
//	enemies.push_back(newEnemy);
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

void updateHearts(int currentHealth) {
	for (int i = 0; i < hearts.size(); ++i) {
		hearts[i].setColor(i < currentHealth ? sf::Color::White : sf::Color(0, 0, 0, 100)); // Dim hearts that are "lost"
	}
}

void drawHearts(sf::RenderWindow& window) {
	for (const auto& heart : hearts) {
		window.draw(heart);
	}
}


//void renderMenu(sf::RenderWindow& window, GameState& gameState) {
//	sf::Font font;
//	if (!font.loadFromFile("Data/font.ttf")) {
//		std::cerr << "Error: Failed to load font.\n";
//		return;
//	}
//
//	sf::Text title("Virtua Cop Clone", font, 50);
//	title.setPosition(300, 100);
//	title.setFillColor(sf::Color::White);
//
//	sf::Text startOption("Press Enter to Start", font, 30);
//	startOption.setPosition(300, 300);
//	startOption.setFillColor(sf::Color::White);
//
//	window.clear();
//	window.draw(title);
//	window.draw(startOption);
//	window.display();
//
//	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
//		gameState = GAME;
//	}
//}

void LoadAssets()
{
	TextureHelper::getInstance().loadTexture("Data/bk.png", bk);
	bk.setOrigin(bk.getGlobalBounds().width / 2, bk.getGlobalBounds().height / 2);
	bk.setPosition(windowWidth / 2, windowHeight / 2);

	TextureHelper::getInstance().loadTexture("Data/fg.png", fg);
	fg.setOrigin(fg.getGlobalBounds().width / 2, fg.getGlobalBounds().height / 2);
	fg.setPosition(windowWidth / 2, windowHeight / 2 - 5);


	buttonsPositions.push_back(sf::Vector2i(715, 404));
	buttonsPositions.push_back(sf::Vector2i(1204, 514));
	buttonsPositions.push_back(sf::Vector2i(715, 575));
	buttonsPositions.push_back(sf::Vector2i(1204, 678));
	buttonsPositions.push_back(sf::Vector2i(715, 743));
	buttonsPositions.push_back(sf::Vector2i(1204, 841));
	
	


	
	
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
//void renderMenu()
//{
//
//	//sf::Text title("Virtua Cop Clone", font, 50);
//	//title.setPosition(300, 100);
//	//title.setFillColor(sf::Color::White);
//
//	//sf::Text startOption("Press Enter to Start", font, 30);
//	//startOption.setPosition(300, 300);
//	//startOption.setFillColor(sf::Color::White);
//	//renderer.AddTempDrawable(&title);
//	//renderer.AddTempDrawable(&startOption);
//
//}


GameState buttonClicked(sf::Vector2i mousePos)
{
	for (int i = 0; i < 6; i += 2)
	{
		if (mousePos.x > buttonsPositions[i].x && mousePos.x < buttonsPositions[i + 1].x &&
			mousePos.y > buttonsPositions[i].y && mousePos.y < buttonsPositions[i + 1].y)
		{
			if (i == 0) return GAME; 
			if (i == 2) return EXIT;  
			if (i == 4) return TEAM; 
		}
	}
	return MENU; 
	/*if (mousePos.x > buttonsPositions[0].x && mousePos.x < buttonsPositions[1].x &&
		mousePos.y > buttonsPositions[0].y && mousePos.y < buttonsPositions[1].y)
		return GAME;
	else if (mousePos.x > buttonsPositions[2].x && mousePos.x < buttonsPositions[3].x &&
		mousePos.y > buttonsPositions[2].y && mousePos.y < buttonsPositions[3].y)
		return EXIT;
	else if (mousePos.x > buttonsPositions[4].x && mousePos.x < buttonsPositions[5].x &&
		mousePos.y > buttonsPositions[4].y && mousePos.y < buttonsPositions[5].y)
		return TEAM;*/
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
	mainMenuSprite.setPosition(window.getSize().x / 2, window.getSize().y / 2);






	window.clear();

	window.draw(mainMenuSprite);
	window.display();

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
		//restart();
		gameState = GAME;
	}
#pragma region 16 december
	
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && (gameState == MENU || gameState == TEAM))
	{
	
		sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
		std::cout << "Mouse Position: (" << mousePosition.x << ", " << mousePosition.y << ")\n";
#pragma region Start game button
		gameState = buttonClicked(mousePosition);
#pragma endregion

	}
#pragma endregion
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


	std::cout << "left clicked \n";

	if (gameState == GAME)
	{
		for (auto& enemy : enemies)
		{
			if (enemy.isAlive && enemy.CheckCollision(cursorSprite))
			{
				std::cout << "Enemy hit!\n";
				//if (!enemy.isAlive) {
				//	// Enemy died; spawn a new one
				//	spawnEnemy();
				//	enemies.remove(enemy);
				//}
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

void HandelPlayerInput(sf::Window& window, Sound& ls, Sound& rs)
{
	updateCursor(window);
	sf::Event event;
	while (window.pollEvent(event)) {
		if (event.type == sf::Event::Closed)
			window.close();

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::T) && gameState == GameState::MENU)
		{
			gameState = TEAM;
		}
#pragma region 16 december
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		{
			
			if (gameState == GameState::TEAM)
			{
				gameState = GameState::MENU;
			}
		}
#pragma endregion
	
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && gameState == GameState::MENU)
		{
			gameState = GAME;
		}

		if (event.type == sf::Event::MouseButtonPressed)
		{
			if (event.mouseButton.button == sf::Mouse::Left)
			{
				ls.play();
				LeftMouseClicked();
			}
			if (event.mouseButton.button == sf::Mouse::Right)
			{
				rs.play();
				RightMouseClicked();
			}

		}
	}
}



void RestartGame()
{
	player.Reset();
	enemies.clear();
	Enemy e1(1, 2, &player);
	Enemy e2(2, 2, &player, 1500);

	Enemy e3(3, 2, &player, 950);

	enemies.push_back(e1);
	enemies.push_back(e2);
	enemies.push_back(e3);

	gameState = MENU;

}
void GameLoop(sf::RenderWindow& window)
{
	updateHearts(player.getHelath());

#pragma region 16 december


	if (player.getHelath() <= 0) {  // Check if player lost all health
		RestartGame(); // Reset the game
		return;
	}
#pragma endregion
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
			window.setMouseCursorVisible(true);

			//sf::Sprite menuCursor;
			//TextureHelper::getInstance().loadTexture("Data/menucursor.png", menuCursor);
			//menuCursor.setOrigin(menuCursor.getGlobalBounds().width / 2, menuCursor.getGlobalBounds().height / 2);
			//menuCursor.setScale(1.f, 1.f);
			//sf::Vector2i mousePos = sf::Mouse::getPosition(window);
			//menuCursor.setPosition(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));

		}
		else if (gameState == GAME)
		{
			window.setMouseCursorVisible(false);

			InitGame();
			GameLoop(window);

		}
		else if (gameState == EXIT)
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
	sf::SoundBuffer music;
	if (music.loadFromFile("Data/1.mp3") == false)
	{
		std::cerr << "Error: Could not load music" << "\n";
	}
	sf::Sound bkMusic(music);
	bkMusic.setVolume(30);
	bkMusic.setLoop(true);
	bkMusic.play();
	sf::SoundBuffer shootSound;
	if (shootSound.loadFromFile("Data/shot.mp3") == false)
	{
		std::cerr << "Error: Could not load music" << "\n";
	}
	sf::Sound shootSoundPlayer(shootSound);

	sf::SoundBuffer relodSound;
	if (relodSound.loadFromFile("Data/reload.mp3") == false)
	{
		std::cerr << "Error: Could not load music" << "\n";
	}
	sf::Sound relodSoundPlayer(relodSound);


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
	Enemy e2(2, 2, &player, 1500);

	Enemy e3(3, 2, &player, 950);


	enemies.push_back(e1);
	enemies.push_back(e2);
	enemies.push_back(e3);


	// Main Loop
	while (window.isOpen())
	{
		elapsedTime += clock.restart().asSeconds();

		HandelPlayerInput(window, shootSoundPlayer, relodSoundPlayer);


		Update(window, elapsedTime, timeStep);




	}

	return 0;

}
