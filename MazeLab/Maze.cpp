#include <iostream>
#include <string>
#include "Maze.h"

using namespace std;

Maze::Maze(int height, int width, int layers)
{
	this->height = height;
	this->layers = layers;
	this->width = width;

	mazeArray = new int** [height];
	for (int i = 0; i < height; ++i)
	{
		mazeArray[i] = new int* [width];
		for (int j = 0; j < width; ++j)
		{
			mazeArray[i][j] = new int[layers];

		}
	}



	////

}