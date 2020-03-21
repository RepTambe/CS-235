#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
#include<ostream>
#include "Deque.h"
#include "Queue.h"
#include "Stack.h"
#include "Vector.h"
#include "Station.h"
#include "DequeInterface.h"


using namespace std;


int main(int argc, char* argv[]) {
#ifdef _MSC_VER
#define _CRTDBG_MAP_ALLOC  
#include <crtdbg.h>
#define VS_MEM_CHECK _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#else
#define VS_MEM_CHECK
#endif

    VS_MEM_CHECK               // enable memory leak check



    //Take in input file and create output file
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


    // Deque<string> deq;
    Station<int> train;
    string line;
    while (getline(in, line))
    {
        string itemOne;
        int itemTwo;
        istringstream iss(line);
        iss >> itemOne;
        if (itemOne == "Add:station")
        {
            iss >> itemTwo;
            out << itemOne << " " << itemTwo << " " << train.addCar(itemTwo) << endl;


        }
        else if (itemOne == "Remove:station")
        {
            iss >> itemTwo;
            out << itemOne << " " << train.removeCar() << endl;
        }


        else if (itemOne == "Train:")
        {
            out << itemOne << " " << train.Train() << endl;
        }
        else if (itemOne == "Add:stack")
        {
            out << itemOne << " " << train.addStack() << endl;
        }

        else if (itemOne == "Remove:stack")  //remove from the stack
        {
            out << itemOne << " " << train.removeStack() << endl;
        }

        if (itemOne == "Top:stack")  //Take the top from the stack
        {
            out << itemOne << " " << train.topStack() << endl;

        }
        
        if (itemOne == "Add:queue")
        {
            out << itemOne << " " << train.addQueue() << endl;
        }
        
        if (itemOne == "Remove:queue")
        {
            out << itemOne << " " << train.removeQueue() << endl;
        }

        if (itemOne == "Top:queue")
        {
            out << itemOne << " " << train.topQueue() << endl;
        }
        
        if (itemOne == "Size:queue")
        {
            out << itemOne << " " << train.sizeQueue() << endl;
        }

        if (itemOne == "Size:stack")
        {
            out << itemOne << " " << train.sizeStack() << endl;
        }

        if (itemOne == "Find:")
        {
            out << itemOne << " " << itemTwo << train.sizeStack() << endl;
        }
    }




}