/* 2451899 刘哲豪 计科 */
#include "16-b7.h"
#include <iostream>
#include <string>
using namespace std;
//输出“星期x”
const int _error_week = -1;
static string lower(const string& str)
{
	string ret(str);
	for (int i = 0; i < int(str.length()); i++)
		if (ret[i] <= 'Z' && ret[i] >= 'A')
			ret[i] = ret[i] - 'A' + 'a';
	return ret;
}

static bool is_equal(const string& s1, const string& s2, bool is_case_sense = false)
{
	if (is_case_sense)
		return s1 == s2;
	else
		return lower(s1) == lower(s2);
}
ostream& operator<<(ostream& out, const week& w)
{
	switch (w) {
		case week::sun:
			out << "星期日";
			break;
		case week::mon:
			out << "星期一";
			break;
		case week::tue:
			out << "星期二";
			break;
		case week::wed:
			out << "星期三";
			break;
		case week::thu:
			out << "星期四";
			break;
		case week::fri:
			out << "星期五";
			break;
		case week::sat:
			out << "星期六";
			break;
		default:
			out << "错误";
			break;
	};
	return out;
}

istream& operator>>(istream& in, week& w)
{
	string input;
	in >> input;
	if(is_equal(input, "sun"))
		w = week::sun;
	else if(is_equal(input, "mon"))
		w = week::mon;
	else if(is_equal(input, "tue"))
		w = week::tue;
	else if(is_equal(input, "wed"))
		w = week::wed;
	else if(is_equal(input, "thu"))
		w = week::thu;
	else if(is_equal(input, "fri"))
		w = week::fri;
	else if(is_equal(input, "sat"))
		w = week::sat;
	else
		w = week(_error_week); 
	return in;
}

week& operator++(week& w)
{
	w = week((int(w) + 1) % 7);
	return w;
}

week& operator--(week& w)
{
	w = week((int(w) + 6) % 7);
	return w;
}

week operator++(week& w, int)
{
	week temp = w;
	w = week((int(w) + 1) % 7);
	return temp;
}

week operator--(week& w, int)
{
	week temp = w;
	w = week((int(w) + 6) % 7);
	return temp;
}

week operator+(const week& w, int n)
{
	return week((int(w) + n) % 7);
}

week operator-(const week& w, int n)
{
	return week((int(w) - n % 7 + 7) % 7);
}

week& operator+=(week& w, int n)
{
	w = week((int(w) + n) % 7);
	return w;
}

week& operator-=(week& w, int n)
{
	w = week((int(w) - n % 7 + 7) % 7);
	return w;
}
