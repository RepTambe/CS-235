#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "Maze.h"



using namespace std;






int main(int argc, char* argv[])
{
#ifdef _MSC_VER
#define _CRTDBG_MAP_ALLOC  
#include <crtdbg.h>
#define VS_MEM_CHECK _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#else
#define VS_MEM_CHECK
#endif
	VS_MEM_CHECK               // enable memory leak check
		if (argc < 3)
		{
			cerr << "Please provide name of input and output files";
			return 1;
		}
	//cout << "Input file: " << argv[1] << endl;
	ifstream in(argv[1]);
	if (!in)
	{
		cerr << "Unable to open " << argv[1] << " for input";
		return 2;
	}
	//cout << "Output file: " << argv[2] << endl;
	ofstream out(argv[2]);
	if (!out)
	{
		in.close();
		cerr << "Unable to open " << argv[2] << " for output";
		return 3;
	}
	int mazeHeight;
	int mazeWidth;
	int mazeLayers;
	int value;

	in >> mazeHeight;
	in >> mazeWidth;
	in >> mazeLayers;

	Maze mazeArray(mazeHeight, mazeWidth, mazeLayers);
	
	for (int i = 0; i < mazeLayers; ++i)
	{
		for (int j = 0; j < mazeHeight; ++j)
		{
			for (int k = 0; k < mazeWidth; ++k)
			{
				in >> value;
				//cout << value << endl;
				mazeArray.setValue(j, k, i, value);
				
				//mazeArray.find_maze_path(j, k, i);


			}
		}
	}

	out << mazeArray.toString();
	
	//for (int i = 0; i < mazeLayers; ++i)
	//{
	//	for (int j = 0; j < mazeHeight; ++j)
	//	{
	//		for (int k = 0; k < mazeWidth; ++k)
	//		{
	//			in >> value;
	//			//cout << value << endl;
	//			mazeArray.setValue(j, k, i, value);

	//			mazeArray.find_maze_paths(j, k, i);


	//		}
	//	}
	//}
	if (mazeArray.find_maze_path() == false)
	{
		out << "No Solution Exists!";
	}
	else
	{
		out << mazeArray.twoString();
	}
	//out << mazeArray.twoString();




}