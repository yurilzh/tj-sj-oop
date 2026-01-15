/* 2451899 刘哲豪 计科 */
#include <iostream>
#include <iomanip>
#include "17-b2-time.h"
using namespace std;

/* --- 给出Time类的成员函数的体外实现(含友元及其它必要的公共函数)  --- */ 

Time::Time()
{
	hour = 0;
	minute = 0;
	second = 0;
}
Time::Time(int hour, int minute, int second)
{
	set(hour, minute, second);
}
Time::Time(int totalSecond)
{
	totalSecond = (totalSecond % spd + spd) % spd;
	hour = 0;
	minute = 0;
	second = 0;
	while (totalSecond > 0) {
		if (totalSecond >= 60) {
			totalSecond -= 60;
			if (minute < 59)
				minute++;
			else {
				hour++;
				minute = 0;
			}
		}
		else {
			second += totalSecond;
			totalSecond = 0;
		}
	}
}
int Time::set(int hour, int minute, int second)
{
	if (hour > 23 || hour < 0 || minute > 59 || minute < 0 || second < 0 || second > 59) {
		this->hour = 0;
		this->minute = 0;
		this->second = 0;
		return 1;
	}
	else {
		this->hour = hour;
		this->minute = minute;
		this->second = second;
		return 0;
	}
}
void Time::get(int& hour, int& minute, int& second)
{
	hour = this->hour;
	minute = this->minute;
	second = this->second;
}
void Time::show()
{
	cout << *this << endl;
}

Time::operator int() const
{
	int totalSecond = 0;
	for (int y = 0; y < this->hour; y++)
		totalSecond += 3600;
	for (int m = 0; m < this->minute; m++)
		totalSecond += 60;
	totalSecond += this->second;
	return totalSecond;
}

Time operator+(const Time& d1, const int n)
{
	int totalDay = int(d1) + n;
	Time ret(totalDay);
	return ret;
}

Time operator+(const int n, const Time& d1)
{
	int totalDay = int(d1) + n;
	Time ret(totalDay);
	return ret;
}

int operator-(const Time& d1, const Time& d2)
{
	return int(d1) - int(d2);
}

Time operator-(const Time& d1, const int n)
{
	return Time(int(d1) - n);
}

Time& Time::operator++()
{
	*this = Time(int(*this) + 1);
	return *this;
}
Time Time::operator++(int)
{
	Time tmp(*this);
	*this = Time(int(*this) + 1);
	return tmp;
}
Time& Time::operator--()
{
	*this = Time(int(*this) - 1);
	return *this;
}
Time Time::operator--(int)
{
	Time tmp(*this);
	*this = Time(int(*this) - 1);
	return tmp;
}

bool Time::operator<(Time& d2)
{
	return int(*this) < int(d2);
}

bool Time::operator<=(Time& d2)
{
	return int(*this) <= int(d2);
}

bool Time::operator==(Time& d2)
{
	return int(*this) == int(d2);
}

bool Time::operator!=(Time& d2)
{
	return int(*this) != int(d2);
}

bool Time::operator>(Time& d2)
{
	return int(*this) > int(d2);
}

bool Time::operator>=(Time& d2)
{
	return int(*this) >= int(d2);
}



ostream& operator<<(ostream& out, const Time& d)
{
	out << setfill('0') << setw(2) << d.hour << ":" << setw(2) << d.minute << ":" << setw(2) << d.second << setfill(' ');
	return out;
}

istream& operator>>(istream& in, Time& d)
{
	int y, m, second;
	in >> y >> m >> second;
	d.set(y, m, second);
	return in;
}

/* 如果有需要的其它全局函数的实现，可以写于此处 */
/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/

/* 如果有需要的其它全局函数的实现，可以写于此处 */


