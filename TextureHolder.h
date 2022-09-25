#pragma once
#ifndef TEXTURE_HOLDER_H
#define TEXTURE_HOLDER_H
#include <SFML/Graphics.hpp>
#include <map>

using namespace sf;
using namespace std;

class TextureHolder
{
public:
	TextureHolder();
	
	static Texture& GetTexture(string const& filename);

private:
	//A map container from stl that holds related pairs
	map< string, Texture> m_Textures;

	//A pointer of the same type as class itself the only instance
	static TextureHolder* m_s_Instance;
};


#endif // !TEXTURE_HOLDER_H
