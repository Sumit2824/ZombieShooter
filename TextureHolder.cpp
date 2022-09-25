#include "TextureHolder.h"

//Include assert feature
#include <assert.h>

TextureHolder* TextureHolder::m_s_Instance = nullptr;
TextureHolder::TextureHolder()
{
	assert(m_s_Instance == nullptr);
	m_s_Instance = this;
}

Texture& TextureHolder::GetTexture(string const& filename)
{
	// get a reference to m_texture using m_s_Instance
	auto& m = m_s_Instance->m_Textures;
	
	/*
		auto is equivalent of map<string, texture>
		create an iterator to hold key-value-pair (kvp)
		add search for the required kvp
		using the passed in filename
	*/

	auto keyValuePair = m.find(filename);

	//Did you find a match?

	if (keyValuePair != m.end())
	{
		/*
			yes
			return the texture
			the second part of kvp the texture
		*/
		return keyValuePair->second;
	}
	else
	{
		/*
			file name not found
			create a new key value pair using the file name
			load the texture from the file in usual way
			return the texture to the calling code
		*/
		auto& texture = m[filename];
		texture.loadFromFile(filename);
		return texture;
	}
}
