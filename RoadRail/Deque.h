#include<string>
#include<sstream>
#include "DequeInterface.h"

using namespace std;

#ifndef DEQUE_H
#define DEQUE_H


#include "Deque.h"
template <typename T>
class Deque : public DequeInterface<T>
{
private:
	size_t capacity;
	size_t num_items;
	size_t front_index;
	size_t rear_index;
	T* the_data;


public:
	Deque(void) :
		capacity(DEFAULT_CAPACITY), num_items(0), front_index(0), rear_index(DEFAULT_CAPACITY - 1), the_data(new T[DEFAULT_CAPACITY]) {}
	~Deque()
	{
		delete[] the_data;
	}

	/*
	bool isFull()
	{
		return((front_ == 0 && rear == size - 1) || front == rear + 1);
	}
	bool isEmpty()
	{
		return (front == -1);
	}
	*/
	void reallocate()
	{
		size_t new_capacity = 2 * capacity;
		T* new_data = new T[new_capacity];
		size_t old = front_index;
		for (size_t i = 0; i < num_items; ++i)
		{
			new_data[i] = the_data[old];
			old = (old + 1) % capacity;
		}
		front_index = 0;
		rear_index = num_items - 1;
		capacity = new_capacity;

		swap(the_data, new_data);
		delete[] new_data;
	}

	/** Insert item at front of deque */
	virtual void push_front(const T& value)
	{
		if (num_items == capacity)
		{
			reallocate();
		}
		num_items++;
		front_index = (front_index - 1) % capacity;
		the_data[front_index] = value;
	}




	/** Insert item at rear of deque */
	virtual void push_back(const T& value)
	{
		if (num_items == capacity)
		{
			reallocate();
		}
		num_items++;
		rear_index = (rear_index + 1) % capacity;
		the_data[rear_index] = value;
	}



	/** Remove the front item of the deque */
	virtual void pop_front(void)
	{
		num_items--;
		front_index = (front_index + 1) % capacity;
		return;

	}

	/** Remove the rear item of the deque */
	virtual void pop_back(void)
	{
		num_items--;
		rear_index = (rear_index - 1) % capacity;
		return;
	}

	/** Return the front item of the deque (Do not remove) */
	virtual T& front(void)
	{
		return the_data[front_index];
	}

	/** Return the rear item of the deque (Do not remove) */
	virtual T& back(void)
	{
		return the_data[rear_index];
	}

	/** Return the number of items in the deque */
	virtual size_t size(void) const
	{
		return num_items;
	}

	/** Return true if deque is empty */
	virtual bool empty(void) const
	{
		if (num_items == 0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	/** Return item in deque at index (0 based) */
	virtual T& at(size_t index)
	{
		return the_data[index];
	}

	/** Return the deque items */
	virtual std::string toString(void) const
	{
		stringstream outputString;
		if (empty())
		{
			return "Empty";
		}
		for (unsigned int i = front_index; i != rear_index; i = (i + 1) % capacity)
		{
			outputString << the_data[i] << " ";
		}
		outputString << the_data[rear_index];
		return outputString.str();

	}
	std::string findInd(T value) const
	{

	}


	friend ostream& operator<<(ostream& os, const Deque& Deque)
	{
		return os << Deque.toString();
	}

};



#endif
