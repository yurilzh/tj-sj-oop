/* 2451899 刘哲豪 计科 */
#include <iostream>
#include "16-b4.h"
using namespace std;

/* 给出 Date 类的所有成员函数的体外实现 */
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
	year = default_start_year;
	month = default_month;
	day = default_day;
	while (totalDay > 0) {
		int currentDay = day_of_month(year, month);
		if (totalDay > currentDay) {
			totalDay -= currentDay;
			if (month < 12)
				month++;
			else {
				year++;
				month = 1;
			}
		}
		else {
			day += totalDay - 1;
			totalDay = 0;
		}
	}
	if (year > default_max_year) {
		year = default_max_year;
		month = 12;
		day = day_of_month(year, month);
	}
}
void Date::set(int year, int month, int day)
{
	if (year > default_max_year || year < default_min_year)
		year = year ? default_year : this->year;
	if (month > 12 || month < 1)
		month = month ? default_month : this->month;
	if (day < 1 || day > day_of_month(year, month))
		day = day ? default_day : this->day;
	if (year)
		this->year = year;
	if (month)
		this->month = month;
	if (day <= day_of_month(this->year, this->month))
		this->day = day;
	else
		this->day = default_day;
}
void Date::set(int year, int month)
{
	set(year, month, default_day);
}
void Date::set(int year)
{
	set(year, default_month, default_day);
}
void Date::get(int& year, int& month, int& day)
{
	year = this->year;
	month = this->month;
	day = this->day;
}
void Date::show()
{
	cout << year << "年" << month << "月" << day << "日" << endl;
}

Date::operator int() const
{
	int totalDay = 0;
	for (int y = default_start_year; y < this->year; y++)
		totalDay += isLeapYear(y) ? 366 : 365;
	for (int m = 1; m < this->month; m++)
		totalDay += day_of_month(this->year, m);
	totalDay += this->day;
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
	out << d.year << "年" << d.month << "月" << d.day << "日";
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
	int days = 31;
	int isLeapYear = !(year % 4 || (!(year % 100) && year % 400));
	if (month == 2)
		days = isLeapYear ? 29 : 28;
	else if (month == 4 || month == 6 || month == 9 || month == 11)
		days = 30;
	return days;
}


