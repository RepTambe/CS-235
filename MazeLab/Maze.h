#ifndef MAZE_H
#define MAZE_H
#include<iostream>
#include <string>
#include <sstream>
#include <fstream>
#include "MazeClassInterface.h"

using namespace std;

class Maze : public MazeInterface
{


private:
	int height;
	int width;
	int layers;
	int value;
	int*** mazeArray;

	//string outputString;

public:
	Maze(int height, int width, int layers);
	enum CellValue { OPEN, BLOCKED, PATH, EXIT, TEMPORARY };

	//Maze(void) {}
	~Maze(void) 
	{
		for (int i = 0; i < height; ++i)
		{
			for (int j = 0; j < width; ++j)
			{
				delete[] mazeArray[i][j];
			}
			delete[] mazeArray[i];
		}
		delete[] mazeArray;
	}
	

	virtual void setValue(int height, int width, int layer, int value)
	{
		mazeArray[height][width][layer] = value;
	}



	/** Output maze (same order as input maze)
	  @return string of 2D layers
	*/
	virtual std::string toString() const
	{
		stringstream iss;
		string outputString;
		string position;
		outputString += "Solve Maze:";
		outputString += "\n";
		for (int i = 0; i < layers; ++i)
		{
			position = to_string(i + 1);
			outputString += "Layer ";
			outputString += position;
			outputString += "\n";
			for (int j = 0; j < height; ++j)
			{
				for (int k = 0; k < width; ++k)
				{

					if (mazeArray[j][k][i] == 0)
					{
						outputString += "_ ";
					}
					else
					{
						outputString += "X ";
					}
					//iss << mazeArray[j][k][i] << " ";
					iss << outputString << " ";

				}
				iss << endl;
				outputString += "\n";
			}
			outputString += "\n";
		}
		//return iss.str();
		return outputString;
	}
	/** Solve maze
	   @return true if solveable, else false
	*/
	virtual bool find_maze_path()
	{
		return find_maze_paths(0, 0, 0);
	}

	

	bool find_maze_paths(int Height, int Width, int Layers)
	{
	
		// check boundary (base case #1)
		if ((Height < 0) || (Height >= height) ||
			(Width < 0) || (Width >= width) ||
			(Layers < 0) || (Layers >= layers)) return false;

		if (mazeArray[Height][Width][Layers] != OPEN) return false; // blocked (base case #2)

		if ((Height == height - 1) && (Width == width - 1) && (Layers == layers - 1))
		{
			mazeArray[Height][Width][Layers] = EXIT; // Success! (base case #3)
			return true;
		}

		mazeArray[Height][Width][Layers] = PATH; // Recursive case
		if (find_maze_paths(Height, Width - 1, Layers) ||
			find_maze_paths(Height, Width + 1, Layers) ||
			find_maze_paths(Height - 1, Width, Layers) ||
			find_maze_paths(Height + 1, Width, Layers) ||
			find_maze_paths(Height, Width, Layers - 1) ||
			find_maze_paths(Height, Width, Layers + 1) ) return true;
		mazeArray[Height][Width][Layers] = TEMPORARY;
		return false;
	}

	virtual std::string twoString()
	{
		stringstream iss;
		string outputString;
		string position;
		outputString += "Solution:";
		outputString += "\n";

		for (int i = 0; i < layers; ++i)
		{
			position = to_string(i + 1);
			outputString += "Layer ";
			outputString += position;
			outputString += "\n";

			for (int j = 0; j < height; ++j)
			{
				for (int k = 0; k < width; ++k)
				{
					//iss << mazeArray[j][k][i] << " ";
					if (mazeArray[j][k][i] == TEMPORARY)
					{
						outputString += "_ ";
					}
					else if (mazeArray[j][k][i] == BLOCKED)
					{
						outputString += "X ";
					}
					else if (mazeArray[j][k][i] == OPEN)
					{
						outputString += "_ ";
					}
					else if (mazeArray[j][k][i] == EXIT)
					{
						outputString += "3 ";
					}
					else if (mazeArray[j][k][i] == PATH)
					{
						outputString += "2 ";
					}
					else
					{
						outputString = "No Solution Exists";
						return outputString;
					}
				}
				iss << endl;
				outputString += "\n";
			}
			outputString += "\n";
		}
		return outputString;
	}


	


};


#endif