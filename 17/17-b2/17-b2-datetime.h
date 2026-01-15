/* 2451899 刘哲豪 计科 */
#pragma once

#include "17-b2-date.h"
#include "17-b2-time.h"

/* 如果有其它全局函数需要声明，写于此处 */
const long long spy = spd * all_day_num;
/* DateTimeTime类的基本要求：
	1、不允许定义任何数据成员
	2、尽量少定义成员函数 
*/

class DateTime:public Date, public Time {
protected:
	/* 不允许再定义任何数据成员 */ 

public:
	/* 不允许再定义任何数据成员，允许需要的成员函数及友元函数的声明 */
	DateTime();
	DateTime(int year, int month, int day, int hour, int minutes, int second);
	explicit DateTime(long long dividerSecond); //原来的一参构造函数，实际上是转换构造
	void set(int year = 0, int month = 0, int day = 0, int hour = 0, int minutes = 0, int second = 0);
	void get(int& year, int& month, int& day, int& hour, int& minutes, int& second);
	void show(); 
	explicit operator long long() const;
	friend DateTime operator+(const DateTime& d1, const long long n);
	friend DateTime operator+(const DateTime& d1, const int n);
	friend DateTime operator+(const long long n, const DateTime& d1);
	friend DateTime operator+(const int n, const DateTime& d1);
	friend long long operator-(const DateTime& d1, const DateTime& d2);
	friend DateTime operator-(const DateTime& d1, const long long n);
	friend DateTime operator-(const DateTime& d1, const int n);

	DateTime& operator++();
	DateTime operator++(int);
	DateTime& operator--();
	DateTime operator--(int);

	bool operator<(DateTime& d2);
	bool operator<=(DateTime& d2);
	bool operator==(DateTime& d2);
	bool operator!=(DateTime& d2);
	bool operator>(DateTime& d2);
	bool operator>=(DateTime& d2);

	friend ostream& operator<<(ostream& out, const DateTime& d);
	friend istream& operator>>(istream& out, DateTime& d);

	/* 允许加入友元声明（如果有必要） */

};
