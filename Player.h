#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class Player
{
public:
	Player();
	void spawn(IntRect arena, Vector2f resolution, int tilesize);

	// call this at the end of every game
	void resetPlayerStats();

	//hansle the player getting hit by a zombie 
	bool hit(Time timeHit);

	//how long ago was the player last hit
	Time getLastHitTime();

	//where is the player
	FloatRect getPosition();

	//where is the center of the player
	Vector2f getCenter();

	//what angle is the player facing
	float getRotation();

	//send a copy of the sprite to the main function
	Sprite getSprite();

	//Player movement
	void moveLeft();
	void moveRight();
	void moveUp();
	void moveDown();

	//stop player movement
	void stopLeft();
	void stopRight();
	void stopUp();
	void stopDown();

	//we will call this function once every frame
	void update(float elapsedTime, Vector2i mousePosition);

	//Pickups
	void upgradeSpeed();
	void upgradeHealth();

	//Increase max health
	void increaseHealthLevel(int amount);

	//how much health player currently got?
	int getHealth();


private:
	const float START_SPEED = 200;
	const float START_HEALTH = 100;

	//where is the player 
	Vector2f m_Position;
	Sprite m_Sprite;
	Texture m_Texture;
	Vector2f m_Resolution;
	IntRect m_Arena;
	int m_TileSize;
	bool m_UpPressed;
	bool m_DownPressed;
	bool m_LeftPressed;
	bool m_RightPressed;
	int m_Health;
	int m_MaxHealth;
	Time m_LastHit;
	float m_Speed;
};
