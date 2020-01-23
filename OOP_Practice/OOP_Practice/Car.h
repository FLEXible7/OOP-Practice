#pragma once
#include <cstdint>
#include <iostream>
using namespace std;


class SpeedException : public exception
{
public:

	string message;

	SpeedException(string msg) : message(msg) {}
	SpeedException(const char* msg) : message(msg) {}
	virtual ~SpeedException() {}

	virtual const char* what() const
	{
		return message.c_str();
	}
};

class CarSpeed
{
public:

	uint_least64_t currSpeed, maxSpeed;

	CarSpeed()							{ currSpeed = 0, maxSpeed = 0; }
	CarSpeed(uint_least64_t newMaxSp)	{ currSpeed = 0, maxSpeed = newMaxSp; }
	virtual ~CarSpeed()					{}

	uint_least64_t getMaxSpeed()		{ return maxSpeed; }
	uint_least64_t getCurrSpeed() { return currSpeed; }
	uint_least64_t setNewSpeed(uint_least64_t newSpeed) { return currSpeed = newSpeed > maxSpeed ? maxSpeed : newSpeed; }
	uint_least64_t stopCar() { return currSpeed = 0; }
	
	uint_least64_t operator++()
	{
		uint_least64_t tmp = currSpeed;
		if (currSpeed + 1 > maxSpeed) currSpeed = maxSpeed;
		else ++currSpeed;
		return tmp;
	}

	uint_least64_t operator--()
	{
		uint_least64_t tmp = currSpeed;
		if (currSpeed != 0) --currSpeed;
		return tmp;
	}

	uint_least64_t operator++(int)
	{
		if (currSpeed + 1 > maxSpeed) currSpeed = maxSpeed;
		else currSpeed++;
		return currSpeed;
	}

	uint_least64_t operator--(int)
	{
		if (currSpeed != 0) currSpeed--;
		return currSpeed;
	}

	uint_least64_t operator+(uint_least64_t extraSpeed)
	{
		if (currSpeed + extraSpeed > maxSpeed) currSpeed = maxSpeed;
		else currSpeed += extraSpeed;
		return currSpeed;
	}

	uint_least64_t operator-(uint_least64_t extraSpeed)
	{
		if (currSpeed - extraSpeed < 0) currSpeed = 0;
		else currSpeed -= extraSpeed;
		return currSpeed;
	}

};