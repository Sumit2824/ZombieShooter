#include "ZombieArena.h"

int createBackground(VertexArray& rVA, IntRect arena)

	{
		const int TILE_SIZE = 50;
		const int TILE_TYPE = 3;
		const int VERTS_IN_QUAD = 4;
		int worldWidth = arena.width / TILE_SIZE;
		int worldHeight = arena.height / TILE_SIZE;
		rVA.setPrimitiveType(Quads);

		//set the size of vertex
		rVA.resize(worldWidth* worldHeight* VERTS_IN_QUAD);
		int currentVertex = 0;

		for (int w = 0; w < worldWidth; w++)
		{
			for (int h = 0; h < worldHeight; h++)
			{
				// position each vertex in the current quad
				rVA[currentVertex + 0].position = Vector2f(w * TILE_SIZE, h * TILE_SIZE);
				rVA[currentVertex + 1].position = Vector2f((w * TILE_SIZE) + TILE_SIZE, h * TILE_SIZE);
				rVA[currentVertex + 2].position = Vector2f((w * TILE_SIZE) + TILE_SIZE, (h * TILE_SIZE) + TILE_SIZE);
				rVA[currentVertex + 3].position = Vector2f(w * TILE_SIZE, (h * TILE_SIZE) + TILE_SIZE);
				
				// position ready for the next vertices
				currentVertex += VERTS_IN_QUAD;
			}
		}

		return TILE_SIZE;
	}