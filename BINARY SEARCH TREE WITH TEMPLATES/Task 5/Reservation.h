#pragma once
#include <iostream>
using namespace std;

class Reservation
{
private:
	int year;
	int month;
	int day;
	int hour;
	int min;
	int sec;
public:
	Reservation() = default;
	Reservation(int, int, int, int, int, int);
	Reservation(const Reservation&);
	Reservation& operator = (const Reservation&);
	bool operator == (const Reservation&);
	bool operator < (const Reservation&);
	bool operator > (const Reservation&);
	
	void set_year(int);
	void set_month(int);
	void set_day(int);
	void set_hour(int);
	void set_min(int);
	void set_sec(int);
	
	int get_year();
	int get_month();
	int get_day();
	int get_hour();
	int get_min();
	int get_sec();

	friend ostream& operator << (ostream& out, const Reservation& obj)
	{
		out << "DATE: " << obj.day << "-" << obj.month << "-" << obj.year << "  ,  " << "TIME: " << obj.hour << ":" << obj.min << ":" << obj.sec << endl;
		return out;
	}
	friend istream& operator >> (istream& inp, Reservation& obj)
	{
		cout << " ENTER IN THIS FORMAT ( day month year hour min sec ), (all int values)" << endl;
		inp >> obj.day >> obj.month >> obj.year >> obj.hour >> obj.min >> obj.sec;

		return inp;
	}

};

int Reservation::get_year()
{
	return year;
}
int Reservation::get_month()
{
	return month;
}
int Reservation::get_day()
{
	return day;
}
int Reservation::get_hour()
{
	return hour;
}
int Reservation::get_min()
{
	return min;
}
int Reservation::get_sec()
{
	return sec;
}

void Reservation::set_year(int x)
{
	year = x;
}
void Reservation::set_month(int x)
{
	month = x;
}
void Reservation::set_day(int x)
{
	day = x;
}
void Reservation::set_hour(int x)
{
	hour = x;
}
void Reservation::set_min(int x)
{
	min = x;
}
void Reservation::set_sec(int x)
{
	sec = x;
}

Reservation::Reservation(int a, int b, int c, int x, int y, int z)
{
	set_year(a);
	set_month(b);
	set_day(c);
	set_hour(x);
	set_min(y);
	set_sec(z);	
}

Reservation::Reservation(const Reservation& obj)
{
	set_year(obj.hour);
	set_month(obj.month);
	set_day(obj.day);
	set_hour(obj.hour);
	set_min(obj.min);
	set_sec(obj.sec);
}
Reservation& Reservation::operator=(const Reservation& obj)
{
	set_year(obj.hour);
	set_month(obj.month);
	set_day(obj.day);
	set_hour(obj.hour);
	set_min(obj.min);
	set_sec(obj.sec);

	return *this;
}
bool Reservation::operator==(const Reservation& obj)
{
	return (year == obj.year && month == obj.month && day == obj.day && hour == obj.hour && min == obj.min && sec == obj.sec);
}
bool Reservation::operator<(const Reservation& obj)
{
	if (year == obj.year)
	{
		if (month == obj.month)
		{
			if (day == obj.day)
			{
				if (hour == obj.hour)
				{
					if (min == obj.min)
					{
						if (obj.sec >= obj.sec)
							return false;
						return true;
					}
					else if (min < obj.min)
						return true;
					else
						return false;
				}
				else if (hour < obj.hour)
					return true;
				else
					return false;
			}
			else if (day < obj.day)
				return true;
			else
				return false;
		}
		else if (month < obj.month)
			return true;
		else
			return false;
	}
	else if (year < obj.year)
		return true;
	else
		return false;
}
bool Reservation::operator>(const Reservation& obj)
{
	if (year == obj.year)
	{
		if (month == obj.month)
		{
			if (day == obj.day)
			{
				if (hour == obj.hour)
				{
					if (min == obj.min)
					{
						if (obj.sec <= obj.sec)
							return false;
						return true;
					}
					else if (min > obj.min)
						return true;
					else
						return false;
				}
				else if (hour > obj.hour)
					return true;
				else
					return false;
			}
			else if (day > obj.day)
				return true;
			else
				return false;
		}
		else if (month > obj.month)
			return true;
		else
			return false;
	}
	else if (year > obj.year)
		return true;
	else
		return false;
}
