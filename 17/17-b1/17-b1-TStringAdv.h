/* 2451899 ¡ı’‹∫¿ º∆ø∆ */
#pragma once
#include "17-b1-TString.h"
#include <iostream>
#include <climits>
using namespace std;

class TStringAdv : public TString {
private:
	TStringAdv(int size);
public:
	TStringAdv(const TString& s);
	TStringAdv();
	TStringAdv(const TStringAdv& s);
	TStringAdv(const char* cs);
	TStringAdv& assign(const TStringAdv& s);
	TStringAdv& assign(const char* cs);
	TStringAdv& append(const TStringAdv& s);
	TStringAdv& append(const char* cs);
	TStringAdv& append(const char c);
	TString& insert(const TStringAdv& s, int pos);
	TString& insert(const char* cs, int pos);
	TString& insert(const char c, int pos);
	TStringAdv& erase(const TStringAdv& s);
	TStringAdv& erase(const char* cs);
	TStringAdv& erase(const char c);
	const TStringAdv substr(const int pos, const int length = INT_MAX) const;
	char& at(const int n);
	int TStringAdvLen();
};

int TStringAdvLen(const TStringAdv& s);
