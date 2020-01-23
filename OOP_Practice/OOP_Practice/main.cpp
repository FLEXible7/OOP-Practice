#include <iostream>
#include "Time.h"
#include "deque.h"
#include "Car.h"
using namespace std;

ostream& operator << (ostream& out, const Time& t)
{
	out << t.hours << " : " << t.minutes << " : " << t.seconds;
	return out;
}

istream& operator >> (istream& in, Time& t)
{
	in >> t.seconds >> t.minutes >> t.hours;
	return in;
}


int main()
{
	char c; uint_least64_t mSpeed, val; cin >> c >> mSpeed;
	CarSpeed cs(mSpeed);
	while (cin >> c) {
		switch (c) {
		case 'i':cout << ++cs << "\n"; break;
		case 'd':cout << --cs << "\n"; break;
		case 'w':cout << cs++ << "\n"; break;
		case 's':cout << cs-- << "\n"; break;
		case 'v':cin >> val; cout << cs.setNewSpeed(val) << "\n"; break;
		case 'c':cout << cs.getCurrSpeed() << "\n"; break;
		case 'm':cout << cs.getMaxSpeed() << "\n"; break;
		case 'p':cout << cs.stopCar() << "\n"; break;
		}
	}
}