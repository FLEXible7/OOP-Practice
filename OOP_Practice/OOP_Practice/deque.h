#pragma once
#include <iostream>
#include <deque>
#include <queue>
using namespace std;

class childExeption : public exception
{
public:
	
	string message;

	childExeption(string msg) :	message(msg) {}
	childExeption(const char* msg) : message(msg) {}
	virtual ~childExeption() {}

	virtual const char* what() const
	{
		return message.c_str();
	}
};

class MyDeque
{
public:

	deque<long long> dq;

	void pushFront(long long el)
	{
		dq.push_front(el);
	}

	void pushBack(long long el)
	{
		dq.push_back(el);
	}

	long long getBack()
	{
		if (!dq.empty())
		{
			return dq.back();
		}
		else throw childExeption("empty on getBack()");
	}

	long long getFront()
	{
		if (!dq.empty())
		{
			return dq.front();
		}
		else throw childExeption("empty on getFront()");
	}

	void popBack()
	{
		if (!dq.empty())
		{
			dq.pop_back();
		}
		else throw childExeption("empty on popBack()");
	}

	void popFront()
	{
		if (!dq.empty())
		{
			dq.pop_front();
		}
		else throw childExeption("empty on popFront()");
	}

	double getAverage()
	{
		double total = 0;
		auto it = dq.begin();
		while (it != dq.end())
		{
			total += *it;
			it++;
		}

		return total / dq.size();
	}

};