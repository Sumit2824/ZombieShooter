#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class Pickup
{
public:
	Pickup(int type);
	
	//prepare a new pickup

	void setArena(IntRect arena);
	void spawn();

	//check the position of the pickup
	FloatRect getPosition();

	//Get the sprite for drawing 
	Sprite getSprite();

	//Let pickup update itself each frame
	void update(float elapsedTime);

	//Is this pickup currently spawned?
	bool isSpawned();

	// get the goodness from the pickup
	int gotIt();

	//Upgrade the value of each pickup4
	void upgarde();

private:
	// Start value for health pickups

	const int HEALTH_START_VALUE = 50;
	const int AMMO_START_VALUE = 12;
	const int START_WAIT_TIME = 10;
	const int START_SECONDS_TO_LIVE = 5;

	//The sprite that represents this pickup
	Sprite m_Sprite;

	//The arena it exist in
	IntRect m_Arena;

	//How much is this pickup worth?
	int m_Value;

	//What type of pickup is this?
	//1 = health, 2 = ammo, 
	int m_Type;

	//Handle spawning and disappearing
	bool m_Spawned;
	float m_SecondSinceSpawn;
	float m_SecondsSinceDeSpawn;
	float m_SecondToLive;
	float m_SecondsToWait;



};


