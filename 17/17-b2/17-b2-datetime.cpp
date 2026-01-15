/* 2451899 刘哲豪 计科 */
#include <iostream>
#include <iomanip>
#include "17-b2-datetime.h"
using namespace std;

/* --- 给出DateTime类的成员函数的体外实现(含友元及其它必要的公共函数)  --- */ 
DateTime::DateTime()
{
}
DateTime::DateTime(int year, int month, int day, int hour, int minutes, int second)
{
	this->set(year, month, day, hour, minutes, second);
}

DateTime::DateTime(long long dividerSecond) : Date(int((dividerSecond % spy + spy) % spy / spd)), Time(dividerSecond % spd)
{
}

void DateTime::set(int year, int month, int day, int hour, int minutes, int second)
{
	if (this->Date::set(year, month, day) || this->Time::set(hour, minutes, second)) {
		this->Date::set();
		this->Time::set();
	}
}

void DateTime::get(int& year, int& month, int& day, int& hour, int& minutes, int& second)
{
	this->Date::get(year, month, day);
	this->Time::get(hour, minutes, second);
}
DateTime& DateTime::operator++()
{
	*this = DateTime(static_cast<long long>(*this) + 1);
	return *this;
}
DateTime DateTime::operator++(int)
{
	DateTime tmp(*this);
	*this = DateTime(static_cast<long long>(*this) + 1);
	return tmp;
}
DateTime& DateTime::operator--()
{
	*this = DateTime(static_cast<long long>(*this) - 1);
	return *this;
}
DateTime DateTime::operator--(int)
{
	DateTime tmp(*this);
	*this = DateTime(static_cast<long long>(*this) - 1);
	return tmp;
}

DateTime::operator long long() const
{
	return spd * int(Date(*this)) + int(Time(*this));
}

DateTime operator+(const DateTime& d1, const long long n)
{
	return DateTime(static_cast<long long>(d1) + n);
}

DateTime operator+(const DateTime& d1, const int n)
{
	return d1 + static_cast<long long>(n);
}

DateTime operator+(const long long n, const DateTime& d1)
{
	return DateTime(static_cast<long long>(d1) + n);
}

DateTime operator+(const int n, const DateTime& d1)
{
	return d1 + static_cast<long long>(n);
}

long long operator-(const DateTime& d1, const DateTime& d2)
{
	return static_cast<long long>(d1) - static_cast<long long>(d2);
}

DateTime operator-(const DateTime& d1, const long long n)
{
	return DateTime(static_cast<long long>(d1) - n);
}

DateTime operator-(const DateTime& d1, const int n)
{
	return d1 - static_cast<long long>(n);
}

ostream& operator<<(ostream& out, const DateTime& d)
{
	out << Date(d) << " " << Time(d);
	return out;
}

istream& operator>>(istream& in, DateTime& d)
{
	int y, m, day, h, min, s;
	in >> y >> m >> day >> h >> min >> s;
	d.set(y, m, day, h, min, s);
	return in;
}

bool DateTime::operator<(DateTime& d2)
{
	return static_cast<long long>(*this) < static_cast<long long>(d2);
}

bool DateTime::operator<=(DateTime& d2)
{
	return static_cast<long long>(*this) <= static_cast<long long>(d2);
}

bool DateTime::operator==(DateTime& d2)
{
	return static_cast<long long>(*this) == static_cast<long long>(d2);
}

bool DateTime::operator!=(DateTime& d2)
{
	return static_cast<long long>(*this) != static_cast<long long>(d2);
}

bool DateTime::operator>(DateTime& d2)
{
	return static_cast<long long>(*this) > static_cast<long long>(d2);
}

bool DateTime::operator>=(DateTime& d2)
{
	return static_cast<long long>(*this) >= static_cast<long long>(d2);
}

void DateTime::show()
{
	cout << Date(*this) << " " << Time(*this) << endl;
}

