/* 2451899 刘哲豪 计科 */

#pragma once

#include <iostream>
using namespace std;

/* 补全TString类的定义，所有成员函数均体外实现，不要在此处体内实现 */
class TString {
protected:
	char* content;
	int   len;
	/* 根据需要定义所需的数据成员、成员函数、友元函数等 */
	TString(int size);
public:
	/* 根据需要定义所需的数据成员、成员函数、友元函数等 */
	TString(const TString& s);
	TString(const char* cs);
	TString();
	~TString();

	friend istream& operator>>(istream& in, TString& s);
	friend ostream& operator<<(ostream& out, const TString& s);

	const char* c_str() const;

	TString& operator=(const TString& s);
	TString& operator=(const char* cs);

	friend TString operator+(const TString& s1, const TString& s2);
	friend TString operator+(const char* s1, const TString& s2);
	friend TString operator+(const TString& s1, const char* s2);
	friend TString operator+(const TString& s1, const char c2);
	friend TString operator+(const char c1, const TString& s2);

	TString& operator+=(const TString& s);
	TString& operator+=(const char* cs);
	TString& operator+=(const char c);

	TString operator-(const TString& s) const;
	TString operator-(const char* cs) const;
	TString operator-(const char c) const;

	TString& operator-=(const TString& s);
	TString& operator-=(const char* cs);
	TString& operator-=(const char c);

	TString operator*(const int num) const;
	TString& operator*=(const int num);

	TString operator!();

	friend bool operator<(TString s1, TString s2);
	friend bool operator<(const char* s1, TString s2);
	friend bool operator<(TString s1, const char* s2);

	friend bool operator<=(TString s1, TString s2);
	friend bool operator<=(const char* s1, TString s2);
	friend bool operator<=(TString s1, const char* s2);

	friend bool operator==(TString s1, TString s2);
	friend bool operator==(const char* s1, TString s2);
	friend bool operator==(TString s1, const char* s2);

	friend bool operator!=(TString s1, TString s2);
	friend bool operator!=(const char* s1, TString s2);
	friend bool operator!=(TString s1, const char* s2);

	friend bool operator>(TString s1, TString s2);
	friend bool operator>(const char* s1, TString s2);
	friend bool operator>(TString s1, const char* s2);

	friend bool operator>=(TString s1, TString s2);
	friend bool operator>=(const char* s1, TString s2);
	friend bool operator>=(TString s1, const char* s2);

	int length() const;
	char& operator[](int i);
};

/* 如果有其它全局函数需要声明，写于此处 */
int TStringLen(const TString& s);
/* 如果有需要的宏定义、只读全局变量等，写于此处 */
