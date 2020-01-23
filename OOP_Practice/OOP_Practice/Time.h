#include <iostream>
using namespace std;

class Time
{
public:

	int hours, minutes, seconds;

	Time() { hours = 0, minutes = 0, seconds = 0; }
	Time(int h, int m, int s) { hours = h, minutes = m, seconds = s; }
	virtual ~Time() {}

	void addSeconds(int s)
	{
		seconds += s;

		if (seconds >= 60)
		{
			int extraMinutes, tmp_s = seconds;

			seconds = tmp_s % 60;
			extraMinutes = tmp_s / 60;
			minutes += extraMinutes;

			if (minutes >= 60)
			{
				int extraHours, tmp_m = minutes;
				minutes = tmp_m % 60;
				extraHours = tmp_m / 60;
				hours += extraHours;
			}

		}

	}

	string compareTimes(Time time)
	{
		int res_h, res_m, res_s;

		res_h = hours - time.hours;
		res_m = minutes - time.minutes;
		res_s = seconds - time.seconds;

		if (res_h > 0) return "larger";
		else if (res_h < 0) return "less";
		else
		{
			if (res_m > 0) return "larger";
			else if (res_m < 0) return "less";
			else
			{
				if (res_s > 0) return "larger";
				else if (res_s < 0) return "less";
				else return "equal";
			}
		}
	}

	int intoSeconds()
	{
		return (seconds + minutes * 60 + hours * 3600);
	}

	Time& operator++()
	{
		addSeconds(1);
		return *this;
	}
	Time& operator++(int)
	{
		Time& tmp = *this;
		addSeconds(1);
		return tmp;
	}

	friend ostream& operator<< (ostream& out, const Time& t);

	friend istream& operator>> (istream& out, const Time& t);
};
