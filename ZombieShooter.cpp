#include <SFML/Graphics.hpp>
#include "Player.h"
#include "ZombieArena.h"
#include "TextureHolder.h"
#include "Bullet.h"

using namespace sf;

int main()
{
	//here is the instance or texture holder
	TextureHolder holder;


    //the game will always be in one of the four state
	enum class State
	{
		PAUSED, LEVELING_UP, GAME_OVER, PLAYING
	};
	State state = State::GAME_OVER;
	
	//get the screen resolution and create sfml window
	Vector2f resolution;

	resolution.x = VideoMode::getDesktopMode().width;
	resolution.y = VideoMode::getDesktopMode().height;
	RenderWindow window(VideoMode(resolution.x, resolution.y), "ZombieAren", Style::Fullscreen);
    
	// create sfml view for the main action
	View mainView(sf::FloatRect(0, 0, resolution.x, resolution.y));

	Clock clock;

	//how long playing state been active
	Time gameTimeTotal;

	//where is mouse in world coordinates
	Vector2f mouseWorldPosition;

	//where is mouse in screen coordinates
	Vector2i mouseScreenPosition;

	//create player instance
	Player player;

	//the boundaries of the arena
	IntRect arena;

	//Create background
	VertexArray background;
	Texture textureBackground = TextureHolder::GetTexture("graphics/background_sheet.png");

	//prepare for a horde of zombies
	int numZombies;
	int numZombiesAlive;
	Zombie* zombies = nullptr;

	Bullet bullets[100];
	int currentBullet = 0;
	int bulletsSpare = 24;
	int bulletsInClip = 6;
	int clipSize = 6;
	float fireRate = 1;

	//when the fire button last pressed
	Time lastPressed;

	//main game loop
	while (window.isOpen())
	{
		Event event;

		while (window.pollEvent(event))
		{

			if (event.type == Event::KeyPressed)
			{


				// Pause a game while playing

				if (event.key.code == Keyboard::Return && state == State::PLAYING)
				{

					state = State::PAUSED;

				}

				// Restart while paused
				else if (event.key.code == Keyboard::Return && state == State::PAUSED)
				{

					state = State::PLAYING;

					// Reset the clock so there isn't a frame jump

					clock.restart();

				}

				// Start a new game while in GAME_OVER state


				else if (event.key.code == Keyboard::Return && state == State::GAME_OVER)
				{

					state = State::LEVELING_UP;

				}

				if (state == State::PLAYING)
				{

				}
			}// End event polling

		}
		 // Handle the player quitting

		if (Keyboard::isKeyPressed(Keyboard::Escape))
		{

			window.close();

		}

		// Handle WASD while playing

		if (state == State::PLAYING)
		{

			// Handle the pressing and releasing of the WASD keys

			if (Keyboard::isKeyPressed(Keyboard::W))
			{

				player.moveUp();
			
			}

			else
			{

				player.stopUp();
			
			}

			if (Keyboard::isKeyPressed(Keyboard::S))
			{

				player.moveDown();

			}

			else
			{

				player.stopDown();
			
			}

			if (Keyboard::isKeyPressed(Keyboard::A))
			{

				player.moveLeft();

			}

			else
			{

				player.stopLeft();

			}
			if (Keyboard::isKeyPressed(Keyboard::D))
			{

				player.moveRight();

			}

			else
			{

				player.stopRight();

			}

		}// End WASD while playing

		 // Handle the LEVELING up state

		if (state == State::LEVELING_UP)
		{

			// Handle the player LEVELING up

			if (event.key.code == Keyboard::Num1)
			{
				state = State::PLAYING;

			}

			if (event.key.code == Keyboard::Num2)
			{

				state = State::PLAYING;

			}

			if (event.key.code == Keyboard::Num3)
			{
				state = State::PLAYING;

			}

			if (event.key.code == Keyboard::Num4)
			{

				state = State::PLAYING;

			}

			if (event.key.code == Keyboard::Num5)
			{

				state = State::PLAYING;

			}

			if (event.key.code == Keyboard::Num6)
			{

				state = State::PLAYING;

			}

			if (state == State::PLAYING)
			{
				// Prepare the level

				arena.width = 500;

				arena.height = 500;

				arena.left = 0;

				arena.top = 0;

				//pass the vertex array by refrence to the create background function
				int tileSize = createBackground(background, arena);


				// Spawn the player in the middle of the arena

				player.spawn(arena, resolution, tileSize);

				//create horde of zombie
				numZombies = 10;

				//delete the previously allocated memory
				delete[] zombies;

				zombies = createHorde(numZombies, arena);
				numZombiesAlive = numZombies;

				// Reset the clock so there isn't a frame jump

				clock.restart();

			}

		}// End LEVELING up

		if (state == State::PLAYING)
		{

			// Update the delta time

			Time dt = clock.restart();



			// Update the total game time
			gameTimeTotal += dt;



			// Make a decimal fraction of 1 from the delta time

			float dtAsSeconds = dt.asSeconds();

			// Where is the mouse pointer

			mouseScreenPosition = Mouse::getPosition();

			// Convert mouse position to world coordinates of mainView

			mouseWorldPosition = window.mapPixelToCoords(Mouse::getPosition(), mainView);

			// Update the player

			player.update(dtAsSeconds, Mouse::getPosition());

			// Make a note of the players new position

			Vector2f playerPosition(player.getCenter());



			// Make the view centre around the player                

			mainView.setCenter(player.getCenter());

			// loop through each zombie and update them

			for (int i = 0; i < numZombies; i++)
			{
				if (zombies[i].isAlive())
				{
					zombies[i].update(dt.asSeconds(), playerPosition);
				}
			}

		}// End updating the scene

		if (state == State::PLAYING)
		{
			window.clear();

			// set the mainView to be displayed in the window And draw everything related to it
			window.setView(mainView);

			//draw background
			window.draw(background, &textureBackground);

			//draw zombies
			for (int i = 0; i < numZombies; i++)
			{
				window.draw(zombies[i].getSprite());
			}

			// Draw the player
			window.draw(player.getSprite());

		}

		if (state == State::LEVELING_UP)
		{

		}

		if (state == State::PAUSED)
		{

		}

		if (state == State::GAME_OVER)
		{

		}

		window.display();

	} // end game loop

	//delete previously allocated memory if existed
	delete[] zombies;
	
	return 0;
}
