/* 2451899 刘哲豪 计科 */

/* 允许添加需要的头文件、宏定义等 */
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include "17-b1-TString.h"
using namespace std;

/* 给出 TString 类的所有成员函数的体外实现 */

/* 如果有需要的其它全局函数的实现，可以写于此处 */

TString::TString(int size)
{
	if (size < 0)
		size = 0;
	this->len = size;
	this->content = new(nothrow) char[size + 1];
	this->content[size] = '\0';
}

TString::TString(const TString& s)
{
	this->content = new(nothrow) char[s.len + 1];
	this->len = s.len;
	memcpy(this->content, s.content, s.len);
	this->content[this->len] = '\0';
}

TString::TString(const char* cs)
{
	if (cs) {
		this->len = strlen(cs);
		this->content = new(nothrow) char[this->len + 1];
		memcpy(this->content, cs, this->len);
	}
	else {
		this->content = new(nothrow) char[1];
		this->len = 0;
	}
	this->content[this->len] = '\0';
}

TString::TString()
{
	this->len = 0;
	this->content = new(nothrow) char[1];
	this->content[0] = '\0';
}

TString::~TString()
{
	if (content)
		delete[] content;
}

TString& TString::operator=(const TString& s)
{
	if (this == &s)    //不能写成*this == &s,因为==重载为了比较整个字符串是否相等
		return *this;
	if (this->content)
		delete[] this->content;
	this->content = new(nothrow) char[s.len + 1];
	this->len = s.len;
	memcpy(content, s.content, s.len);
	this->content[this->len] = '\0';
	return *this;
}

TString& TString::operator=(const char* cs)
{
	if (this->content)
		delete[] this->content;
	if (cs) {
		this->len = strlen(cs);
		this->content = new(nothrow) char[this->len + 1];
		memcpy(this->content, cs, this->len);
	}
	else {
		this->content = new(nothrow) char[1];
		this->len = 0;
	}
	this->content[this->len] = '\0';
	return *this;
}

istream& operator>>(istream& in, TString& s)
{
	char inc;
	delete[] s.content;
	s.len = 0;
	s.content = new char[1];
	s.content[0] = '\0';
	while ((inc = in.get()) != ' ' && inc != EOF && inc != '\n')
		s += inc;
	return in;
}

ostream& operator<<(ostream& out, const TString& s)
{
	if (s.len > 0)
		out << s.content;
	else
		out << "<EMPTY>";
	return out;
}

const char* TString::c_str() const
{
	return this->content;
}

TString operator+(const TString& s1, const TString& s2)
{
	TString s3(s1.len + s2.len);
	memcpy(s3.content, s1.content, s1.len);
	memcpy(s3.content + s1.len, s2.content, s2.len);
	s3.content[s3.len] = '\0';
	return s3;
}

TString operator+(const char* s1, const TString& s2)
{
	if (s1) {
		int s1len = strlen(s1);
		TString s3(s1len + s2.len);
		memcpy(s3.content, s1, s1len);
		memcpy(s3.content + s1len, s2.content, s2.len);
		s3.content[s3.len] = '\0';
		return s3;
	}
	else
		return TString(s2);
}

TString operator+(const TString& s1, const char* s2)
{
	if (s2) {
		int s2len = strlen(s2);
		TString s3(s1.len + s2len);
		memcpy(s3.content, s1.content, s1.len);
		memcpy(s3.content + s1.len, s2, s2len);
		s3.content[s3.len] = '\0';
		return s3;
	}
	else
		return TString(s1);
}

TString operator+(const TString& s1, const char c2)
{
	TString s3(s1.len + 1);
	memcpy(s3.content, s1.content, s1.len);
	s3.content[s3.len - 1] = c2;
	s3.content[s3.len] = '\0';
	return s3;
}

TString operator+(const char c1, const TString& s2)
{
	TString s3(s2.len + 1);
	s3.content[0] = c1;
	memcpy(s3.content + 1, s2.content, s2.len);
	s3.content[s3.len] = '\0';
	return s3;
}

TString& TString::operator+=(const TString& s)
{
	int newlen = this->len + s.len;
	char* newContent = new(nothrow) char[newlen + 1];
	memcpy(newContent, this->content, this->len);
	memcpy(newContent + this->len, s.content, s.len);
	newContent[newlen] = '\0';
	delete[] this->content;
	this->content = newContent;
	this->len = newlen;
	return *this;
}

TString& TString::operator+=(const char* cs)
{
	if (cs) {
		int slen = strlen(cs);
		int newlen = this->len + slen;
		char* newContent = new(nothrow) char[newlen + 1];
		memcpy(newContent, this->content, this->len);
		memcpy(newContent + this->len, cs, slen);
		newContent[newlen] = '\0';
		delete[] this->content;
		this->content = newContent;
		this->len = newlen;
	}
	return *this;
}

TString& TString::operator+=(const char c)
{
	int newlen = this->len + 1;
	char* newContent = new(nothrow) char[newlen + 1];
	memcpy(newContent, this->content, this->len);
	newContent[newlen - 1] = c;
	newContent[newlen] = '\0';
	delete[] this->content;
	this->content = newContent;
	this->len = newlen;
	return *this;
}


TString TString::operator-(const TString& s) const
{
	char* pos = strstr(this->content, s.content);
	if (pos) {
		TString s3(this->len - s.len);
		int beghalf = pos - this->content;
		memcpy(s3.content, this->content, beghalf);
		memcpy(s3.content + beghalf, pos + s.len, s3.len - beghalf);
		s3.content[s3.len] = '\0';
		return s3;
	}
	else
		return TString(*this);
}

TString TString::operator-(const char* cs) const
{
	char* pos = NULL;
	if(cs)
		pos = strstr(this->content, cs);
	if (pos) {
		int slen = strlen(cs);
		TString s3(this->len - slen);
		int beghalf = pos - this->content;
		memcpy(s3.content, this->content, beghalf);
		memcpy(s3.content + beghalf, pos + slen, s3.len - beghalf);
		s3.content[s3.len] = '\0';
		return s3;
	}
	else
		return TString(*this);
}

TString TString::operator-(const char c) const
{
	char* pos = strchr(this->content, c);
	if (pos) {
		TString s3(this->len - 1);
		int beghalf = pos - this->content;
		memcpy(s3.content, this->content, beghalf);
		memcpy(s3.content + beghalf, pos + 1, s3.len - beghalf);
		s3.content[s3.len] = '\0';
		return s3;
	}
	else
		return TString(*this);
}

TString& TString::operator-=(const TString& s)
{
	char* pos = strstr(this->content, s.content);
	if (pos) {
		this->len = this->len - s.len;
		char* newContent = new(nothrow)char[this->len + 1];
		int beghalf = pos - this->content;
		memcpy(newContent, this->content, beghalf);
		memcpy(newContent + beghalf, pos + s.len, this->len - beghalf);
		delete[] this->content;
		this->content = newContent;
		this->content[this->len] = '\0';
	}
	return *this;
}

TString& TString::operator-=(const char* cs)
{
	char* pos = NULL;
	if(cs)
		pos = strstr(this->content, cs);
	if (pos) {
		int slen = strlen(cs);
		this->len = this->len - slen;
		char* newContent = new(nothrow) char[this->len + 1];
		int beghalf = pos - this->content;
		memcpy(newContent, this->content, beghalf);
		memcpy(newContent + beghalf, pos + slen, this->len - beghalf);
		delete[] this->content;
		this->content = newContent;
		this->content[this->len] = '\0';
	}
	return *this;
}

TString& TString::operator-=(const char c)
{
	char* pos = strchr(this->content, c);
	if (pos) {
		this->len = this->len - 1;
		char* newContent = new(nothrow) char[this->len + 1];
		int beghalf = pos - this->content;
		memcpy(newContent, this->content, beghalf);
		memcpy(newContent + beghalf, pos + 1, this->len - beghalf);
		delete[] this->content;
		this->content = newContent;
		this->content[this->len] = '\0';
	}

	return *this;
}

TString TString::operator*(const int num) const
{
	TString ret(num * this->len);
	for (int i = 0; i < num; i++) 
		memcpy(ret.content + i * this->len, this->content, this->len);
	ret.content[ret.len] = '\0';
	return ret;
}

TString& TString::operator*=(const int num)
{
	if(num <= 0) {
		*this = "";
		return *this;
	}
	int newlen = num * this->len;
	char* newContent = new(nothrow) char[newlen + 1];
	for (int i = 0; i < num; i++) 
		memcpy(newContent + i * this->len, this->content, this->len);
	newContent[newlen] = '\0';
	delete[] this->content;
	this->content = newContent;
	this->len = newlen;
	return *this;
}

TString TString::operator!()
{
	TString ret(this->len);
	for (char* c = this->content; *c; c++) {
		ret.content[ret.len - (c - this->content) - 1] =  *c;
	}
	ret.content[ret.len] = '\0';
	return ret;
}

char& TString::operator[](int i)
{
	return this->content[i];
}

bool operator<(TString s1, TString s2)
{
	return strcmp(s1.content, s2.content) < 0;
}

bool operator<(const char* s1, TString s2)
{
	if (s1)
		return strcmp(s1, s2.content) < 0;
	else if (s2.len)
		return 1;
	else
		return 0;
}

bool operator<(TString s1, const char* s2)
{
	if (s2)
		return strcmp(s1.content, s2) < 0;
	else
		return 0;
}

bool operator<=(TString s1, TString s2)
{
	return strcmp(s1.content, s2.content) <= 0;
}

bool operator<=(const char* s1, TString s2)
{
	return s1 < s2 || s1 == s2;
}

bool operator<=(TString s1, const char* s2)
{
	return s1 < s2 || s1 == s2;
}

bool operator==(TString s1, TString s2)
{
	return strcmp(s1.content, s2.content) == 0;
}

bool operator==(const char* s1, TString s2)
{
	if (s1)
		return strcmp(s1, s2.content) == 0;
	else if (s2.len == 0)
		return 1;
	else
		return 0;

}

bool operator==(TString s1, const char* s2)
{
	if (s2)
		return strcmp(s1.content, s2) == 0;
	else if (s1.len == 0)
		return 1;
	else
		return 0;
}

bool operator!=(TString s1, TString s2)
{
	return !(s1 == s2);
}

bool operator!=(const char* s1, TString s2)
{
	return !(s1 == s2);
}

bool operator!=(TString s1, const char* s2)
{
	return !(s1 == s2);
}
bool operator>(TString s1, TString s2)
{
	return !(s1 <= s2);
}

bool operator>(const char* s1, TString s2)
{
	return !(s1 <= s2);
}

bool operator>(TString s1, const char* s2)
{
	return !(s1 <= s2);
}

bool operator>=(TString s1, TString s2)
{
	return !(s1 < s2);
}

bool operator>=(const char* s1, TString s2)
{
	return !(s1 < s2);
}

bool operator>=(TString s1, const char* s2)
{
	return !(s1 < s2);
}


int TString::length() const
{
	return this->len;
}
int TStringLen(const TString& s)
{
	return s.length();
}
