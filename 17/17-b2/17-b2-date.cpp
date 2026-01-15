/* 2451899 刘哲豪 计科 */
#include <iostream>
#include <iomanip>
#include "17-b2-date.h"
using namespace std;

/* --- 给出Date类的成员函数的体外实现(含友元及其它必要的公共函数)  --- */ 

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/

Date::Date()
{
	year = default_year;
	month = default_month;
	day = default_day;
}
Date::Date(int year, int month, int day)
{
	set(year, month, day);
}
Date::Date(int totalDay)
{
	totalDay = (totalDay % all_day_num + all_day_num) % all_day_num;
	year = default_start_year;
	month = default_month;
	day = default_day;
	while (totalDay > 0) {
		int currentDay = day_of_month(year, month);
		if (totalDay >= currentDay) {
			totalDay -= currentDay;
			if (month < 12)
				month++;
			else {
				year++;
				month = 1;
			}
		}
		else {
			day += totalDay;
			totalDay = 0;
		}
	}
}
int Date::set(int year, int month, int day)
{
	if (year > default_max_year || year < default_min_year || month > 12 || month < 1 || day < 1 || day > day_of_month(year, month)) {
		this->year = default_year;
		this->month = default_month;
		this->day = default_day;
		return 1;
	}
	else {
		this->year = year;
		this->month = month;
		this->day = day;
		return 0;
	}
}
void Date::get(int& year, int& month, int& day)
{
	year = this->year;
	month = this->month;
	day = this->day;
}
void Date::show()
{
	cout << *this << endl;
}

Date::operator int() const
{
	int totalDay = 0;
	for (int y = default_start_year; y < this->year; y++)
		totalDay += isLeapYear(y) ? 366 : 365;
	for (int m = 1; m < this->month; m++)
		totalDay += day_of_month(this->year, m);
	totalDay += this->day - 1;
	return totalDay;
}

Date operator+(const Date& d1, const int n)
{
	int totalDay = int(d1) + n;
	Date ret(totalDay);
	return ret;
}

Date operator+(const int n, const Date& d1)
{
	int totalDay = int(d1) + n;
	Date ret(totalDay);
	return ret;
}

int operator-(const Date& d1, const Date& d2)
{
	return int(d1) - int(d2);
}

Date operator-(const Date& d1, const int n)
{
	return Date(int(d1) - n);
}

Date& Date::operator++()
{
	*this = Date(int(*this) + 1);
	return *this;
}
Date Date::operator++(int)
{
	Date tmp(*this);
	*this = Date(int(*this) + 1);
	return tmp;
}
Date& Date::operator--()
{
	*this = Date(int(*this) - 1);
	return *this;
}
Date Date::operator--(int)
{
	Date tmp(*this);
	*this = Date(int(*this) - 1);
	return tmp;
}

bool Date::operator<(Date& d2)
{
	return int(*this) < int(d2);
}

bool Date::operator<=(Date& d2)
{
	return int(*this) <= int(d2);
}

bool Date::operator==(Date& d2)
{
	return int(*this) == int(d2);
}

bool Date::operator!=(Date& d2)
{
	return int(*this) != int(d2);
}

bool Date::operator>(Date& d2)
{
	return int(*this) > int(d2);
}

bool Date::operator>=(Date& d2)
{
	return int(*this) >= int(d2);
}



ostream& operator<<(ostream& out, const Date& d)
{
	out << d.year << "-" << setfill('0') << setw(2) << d.month << "-" << setfill('0') << setw(2) << d.day << setfill(' ');
	return out;
}

istream& operator>>(istream& in, Date& d)
{
	int y, m, day;
	in >> y >> m >> day;
	d.set(y, m, day);
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
int isLeapYear(int y)
{
	return !(y % 4 || (!(y % 100) && y % 400));
}
int day_of_month(int year, int month)
{
	int isLeapYear = !(year % 4 || (!(year % 100) && year % 400));
	int monthDays[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	if(isLeapYear)
		monthDays[1] = 29;
	return monthDays[month - 1];
}


