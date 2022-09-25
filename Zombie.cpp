#include "Zombie.h"
#include "TextureHolder.h"
#include <cstdlib>
#include <ctime>

using namespace std;


void Zombie::spawn(float startX, float startY, int type, int seed)
{
	switch (type)
	{
	case 0:		//Boater
		m_Sprite = Sprite(TextureHolder::GetTexture("graphics/bloater.png"));
		m_Speed = BLOATER_SPEED;
		m_Health = BLOTER_HEALTH;
		break;

	case 1:		//cahser
		m_Sprite = Sprite(TextureHolder::GetTexture("graphics/chaser.png"));
		m_Speed = CHASER_SPEED;
		m_Health = CHASER_HEALTH;
		break;

	case 2:		//crawler
		m_Sprite = Sprite(TextureHolder::GetTexture("graphics/crawler.png"));
		m_Speed = CRAWLER_SPEED;
		m_Health = CRAWLER_HEALTH;
		break;
	}

	//create speed modifier to make zombie unique

	srand((int)time(0) * seed);
	float modifier = (rand() % MAX_VARIANCE) + OFFSET;

	//Express this as a fraction of 1

	modifier /= 100;	//equals between .7 - 1
	m_Speed *= modifier;

	m_Position.x = startX;
	m_Position.y = startY;
	m_Sprite.setPosition(25, 25);
	m_Sprite.setPosition(m_Position);
}
bool Zombie::hit()
{
	m_Health--;

	if (m_Health < 0)
	{
		m_Alive = false;
		m_Sprite.setTexture(TextureHolder::GetTexture("graphics/blood.png"));
		return true;
	}

	return false;
}

bool Zombie::isAlive()
{
	return m_Alive;
}

FloatRect Zombie::getPosition()
{
	return m_Sprite.getGlobalBounds();
}

Sprite Zombie::getSprite()
{
	return m_Sprite;
}

void Zombie::update(float elapsedTime, Vector2f playerPosition)
{
	float playerX = playerPosition.x;
	float playerY = playerPosition.y;

	if (playerX > m_Position.x)
	{
		m_Position.x = m_Position.x + m_Speed * elapsedTime;
	}

	if (playerY > m_Position.y)
	{
		m_Position.y = m_Position.y + m_Speed * elapsedTime;
	}

	if (playerX < m_Position.x)
	{
		m_Position.x = m_Position.x - m_Speed * elapsedTime;
	}

	if (playerY < m_Position.y)
	{
		m_Position.y = m_Position.y - m_Speed * elapsedTime;
	}

	m_Sprite.setPosition(m_Position);
	
	float angle = (atan2(playerY - m_Position.y, playerX - m_Position.x) * 180 )/ 3.14;

	m_Sprite.setRotation(angle);
}
