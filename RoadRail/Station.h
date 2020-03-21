#include<string>
#include<sstream>
#include "DequeInterface.h"

using namespace std;

#ifndef STATION_H
#define STATION_H


#include "Deque.h"
#include "Queue.h"
#include "Stack.h"
#include "Vector.h"
template <typename T>
class Station
{
private:
	Vector<T> train;
	Stack<T> stack;
	Queue<T> queue;
	bool empty = true;
	bool occupied = true;
	T turnTableCar;

public:
	Station(void) {}
	~Station(void) {}


	std::string addCar(const T& car)
	{
		if (empty == true)
		{
			turnTableCar = car;
			//train.push_front(turnTableCar);
			empty = false;
			return "OK";
		}
		else
		{
			return "Turntable occupied!";
		}

	}
	std::string removeCar(void)
	{
		if (empty == false)
		{
			train.push_back(turnTableCar);
			empty = true;
			return "OK";
		}
		else
		{
			return "Turntable empty!";
		}
	}
	std::string topCar(void)
	{
		if (empty == false)
		{
			return turnTableCar;
		}
	}
	std::string addStack(void)
	{
		if (empty == false)
		{
			stack.push_back(turnTableCar);
			occupied = true;
			empty = true;
			return "OK";
		}
		else
		{

			occupied = false;
			return "Turntable empty!";
		}
	}
	std::string removeStack(void)
	{
		if (stack.empty() == true)
		{
			return "Stack empty!";
		}

		else
		{
			turnTableCar = stack.top();
			empty = false;
			stack.pop_back();
			return "OK";
		}

	}
	std::string topStack(void)  // Display the train car at the head of Stack Roundhouse
	{
		if (stack.empty() == true)
		{
			return "Stack empty!";
		}
		else
		{
			return to_string(stack.top());
			//return stack.toString();
		}

	}

	std::string sizeStack(void)  //returns the size of the stack
	{
		return to_string(stack.size());
	}


	std::string Train(void)  //returns all values on the train
	{
		return train.toString();
	}
	
	
	std::string addQueue(void)  //adds a Que value
	{
		if (empty == false)
		{
			queue.push_back(turnTableCar);
			empty = true;
			return "OK";
		}
		else
		{

			return "Turntable empty!";
		}
	}
	std::string removeQueue(void)  //Removes a value from Que
	{
		if (queue.empty() == true)
		{
			return "Queue empty!";
		}

		else
		{
			turnTableCar = queue.front();
			empty = false;
			queue.pop_front();
			return "OK";
		}
	}
	std::string topQueue(void)
	{
		return to_string(queue.front());
	}
	std::string sizeQueue(void)
	{
		return to_string(queue.size());
	}
	

	std::string findFunc(T value)
	{
		
	}

	

	friend ostream& operator<<(ostream& os, const Station& Station)
	{
		return os << Station.toString();
	}

};



#endif
