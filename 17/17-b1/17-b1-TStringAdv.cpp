/* 2451899 刘哲豪 计科 */
#include "17-b1-TStringAdv.h"
#include <climits>
#include <cstring>
TStringAdv::TStringAdv(int size) : TString(size)
{
}

TStringAdv::TStringAdv(const TString& s)
{
	this->len = s.length();
	this->content = new(nothrow) char[this->len + 1];
	memcpy(this->content, s.c_str(), this->len);
}

TStringAdv::TStringAdv()
{
}
TStringAdv::TStringAdv(const TStringAdv& s) : TString(s)
{
}
TStringAdv::TStringAdv(const char* cs) : TString(cs)
{
}

TStringAdv& TStringAdv::assign(const TStringAdv& s)
{
	*this = s;
	return *this;
}

TStringAdv& TStringAdv::assign(const char* cs)
{
	*this = cs;
	return *this;
}

TStringAdv& TStringAdv::append(const TStringAdv& s)
{
	*this += s;
	return *this;
}

TStringAdv& TStringAdv::append(const char* cs)
{
	*this += cs;
	return *this;
}

TStringAdv& TStringAdv::append(const char c)
{
	*this += c;
	return *this;
}

TString& TStringAdv::insert(const TStringAdv& s, int pos)
{
	if (pos < 1 || pos > this->len + 1 || s.len == 0)
		return *this;
	else if(pos == this->len + 1)
		*this += s;
	else {
		char* newContent = new(nothrow) char[this->len + s.len + 1];
		memcpy(newContent, this->content, pos - 1);
		memcpy(newContent + pos - 1, s.content, s.len);
		memcpy(newContent + pos - 1 + s.len, this->content + pos - 1, this->len - pos + 1);
		delete[] this->content;
		this->len += s.len;
		this->content = newContent;
		this->content[this->len] = '\0';
	}
	return *this;
}

TString& TStringAdv::insert(const char* cs, int pos)
{
	// TODO: 在此处插入 return 语句
	if (pos < 1 || pos > this->len + 1 || !cs || cs[0] == '\0')
		return *this;
	else if(pos == this->len + 1)
		*this += cs;
	else {
		int slen = strlen(cs);
		char* newContent = new(nothrow) char[this->len + slen + 1];
		memcpy(newContent, this->content, pos - 1);
		memcpy(newContent + pos - 1, cs, slen);
		memcpy(newContent + pos - 1 + slen, this->content + pos - 1, this->len - pos + 1);
		delete[] this->content;
		this->len += slen;
		this->content = newContent;
		this->content[this->len] = '\0';
	}
	return *this;
}

TString& TStringAdv::insert(const char c, int pos)
{
	if (pos < 1 || pos > this->len + 1)
		return *this;
	if (c == '\0') {
		this->len = pos - 1;
		char* newContent = new(nothrow) char[this->len + 1];
		memcpy(newContent, this->content, this->len);
		delete[] this->content;
		this->content = newContent;
		newContent[this->len] = '\0';
	}
	else {
		char* newContent = new(nothrow) char[this->len + 2];
		memcpy(newContent, this->content, pos - 1);
		newContent[pos - 1] = c;
		memcpy(newContent + pos, this->content + pos - 1, this->len - pos + 1);
		delete[] this->content;
		this->len += 1;
		this->content = newContent;
		this->content[this->len] = '\0';
	}
	return *this;
}

TStringAdv& TStringAdv::erase(const TStringAdv& s)
{
	*this -= s;
	return *this;
}

TStringAdv& TStringAdv::erase(const char* cs)
{
	*this -= cs;
	return *this;
}

TStringAdv& TStringAdv::erase(const char c)
{
	*this -= c;
	return *this;
}

const TStringAdv TStringAdv::substr(const int pos, const int length) const
{
	int cpyLen = length;
	if(length <= 0 || pos <= 0 || pos > this->length())
		return TStringAdv();
	else if(pos + length > this->length() + 1 || length == INT_MAX)
		cpyLen = this->length() - pos + 1;
	TStringAdv ret(cpyLen);
	memcpy(ret.content, this->content + pos - 1, cpyLen);
	return ret;
}

char& TStringAdv::at(const int n)
{
	return (*this)[n];
}

int TStringAdv::TStringAdvLen()
{
	return this->length();
}

int TStringAdvLen(const TStringAdv& s)
{
	return s.length();
}
