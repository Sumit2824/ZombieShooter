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
				
				//Define the position in the texture for current quad either grass, stone, brush or wall
				if (h == 0 || h== worldHeight - 1 || w == 0 || w == worldWidth - 1)
				{
					// use wall texture
					rVA[currentVertex + 0].texCoords = Vector2f(0, 0 + TILE_TYPE * TILE_SIZE);
					rVA[currentVertex + 1].texCoords = Vector2f(TILE_SIZE, 0 + TILE_TYPE * TILE_SIZE);
					rVA[currentVertex + 2].texCoords = Vector2f(TILE_SIZE, TILE_SIZE + TILE_TYPE * TILE_SIZE);
					rVA[currentVertex + 3].texCoords = Vector2f(0, TILE_SIZE + TILE_TYPE * TILE_SIZE);
				}
				else
				{
					// use random floor texture
					srand((int)time(0) + h * w - h);
					int mOrG = (rand() % TILE_TYPE);
					int verticalOffset = mOrG * TILE_SIZE;
					rVA[currentVertex + 0].texCoords = Vector2f(0, 0 + verticalOffset);
					rVA[currentVertex + 1].texCoords = Vector2f(TILE_SIZE, 0 + verticalOffset);
					rVA[currentVertex + 2].texCoords = Vector2f(TILE_SIZE, TILE_SIZE + verticalOffset);
					rVA[currentVertex + 3].texCoords = Vector2f(0, TILE_SIZE + verticalOffset);
				}

				// position ready for the next vertices
				currentVertex += VERTS_IN_QUAD;
			}
		}

		return TILE_SIZE;
	}