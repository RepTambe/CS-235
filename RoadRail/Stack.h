#include<string>
#include<sstream>
#include "DequeInterface.h"

using namespace std;

#ifndef STACK_H
#define STACK_H


#include "Deque.h"
template <typename T>
class Stack
{
private:

	Deque<T> deque;

public:
	Stack(void) {}
	~Stack(void) {}




	/** Insert item at front of deque */
	virtual void push_front(const T& value)
	{

		deque.push_front(value);

	}




	/** Insert item at rear of deque */
	virtual void push_back(const T& value)
	{
		deque.push_back(value);
	}



	/** Remove the front item of the deque */
	virtual void pop_front(void)
	{

		return deque.pop_front();

	}

	/** Remove the rear item of the deque */
	virtual void pop_back(void)
	{

		return deque.pop_back();
	}

	/** Return the front item of the deque (Do not remove) */
	virtual T& front(void)
	{
		return deque.front();
	}

	/** Return the rear item of the deque (Do not remove) */
	virtual T& top(void)
	{
		return deque.back();
	}

	/** Return the number of items in the deque */
	virtual size_t size(void) const
	{
		return deque.size();
	}

	/** Return true if deque is empty */
	virtual bool empty(void) const
	{
		return deque.empty();
	}

	/** Return item in deque at index (0 based) */
	virtual T& at(size_t index)
	{
		return deque.at(index);
	}

	/** Return the deque items */
	virtual std::string toString(void) const
	{
		return deque.toString();

	}



};



#endif

