/* 2451899 刘哲豪 计科 */

#pragma once

#include <iostream>
using namespace std;


/* 如果有其它全局函数需要声明，写于此处 */
int day_of_month(int year, int month);
int isLeapYear(int y);
/* 如果有需要的宏定义、只读全局变量等，写于此处 */
const int default_year = 2000;
const int default_month = 1;
const int default_day = 1;
const int default_start_year = 1900;
const int default_max_year = 2099;
const int default_min_year = default_start_year;
const char dateDividerCh = '.';
/* 补全Date类的定义，所有成员函数均体外实现，不要在此处体内实现 */
class Date {
private:
	int year;
	int month;
	int day;
	/* 不允许添加数据成员 */
public:
	Date();
	Date(int year, int month, int day);
	Date(int divideDay); //原来的一参构造函数，实际上是转换构造
	void set(int year, int month, int day);
	void set(int year, int month);
	void set(int year);
	void get(int& year, int& month, int& day);
	void show(); 
	//old
	operator int() const;
	friend Date operator+(const Date& d1, const int n);
	friend Date operator+(const int n, const Date& d1);
	friend int operator-(const Date& d1, const Date& d2);
	friend Date operator-(const Date& d1, const int n);

	Date& operator++();
	Date operator++(int);
	Date& operator--();
	Date operator--(int);

	bool operator<(Date& d2);
	bool operator<=(Date& d2);
	bool operator==(Date& d2);
	bool operator!=(Date& d2);
	bool operator>(Date& d2);
	bool operator>=(Date& d2);

	friend ostream& operator<<(ostream& out, const Date& d);
	friend istream& operator>>(istream& out, Date& d);
	/* 根据需要定义所需的成员函数、友元函数等(不允许添加数据成员) */

};

