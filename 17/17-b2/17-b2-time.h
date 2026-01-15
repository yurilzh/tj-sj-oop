/* 2451899 刘哲豪 计科 */
#pragma once

#include <iostream>
using namespace std;
/* 如果有其它全局函数需要声明，写于此处 */
const long long spd = 86400;
/* Time类的声明 */ 
class Time {
protected:
	/* 除这三个以外，不允许再定义任何数据成员 */ 
	int hour;
	int minute;
	int second;
public:
	/* 允许需要的成员函数及友元函数的声明 */
	Time();
	Time(int year, int month, int day);
	explicit Time(int divideDay); //原来的一参构造函数，实际上是转换构造
	int set(int year = 0, int month = 0, int day = 0);
	void get(int& year, int& month, int& day);
	void show(); 
	explicit operator int() const;
	friend Time operator+(const Time& d1, const int n);
	friend Time operator+(const int n, const Time& d1);
	friend int operator-(const Time& d1, const Time& d2);
	friend Time operator-(const Time& d1, const int n);

	Time& operator++();
	Time operator++(int);
	Time& operator--();
	Time operator--(int);

	bool operator<(Time& d2);
	bool operator<=(Time& d2);
	bool operator==(Time& d2);
	bool operator!=(Time& d2);
	bool operator>(Time& d2);
	bool operator>=(Time& d2);

	friend ostream& operator<<(ostream& out, const Time& d);
	friend istream& operator>>(istream& out, Time& d);

	/* 允许加入友元声明（如果有必要） */

};
