/* 2451899 刘哲豪 计科 */
#pragma once

#include <iostream>
using namespace std;

enum week { sun, mon, tue, wed, thu, fri, sat };

/* 允许添加相应的函数声明 */
ostream& operator<<(ostream& out, const week& w);
istream& operator>>(istream& in, week& w);

week& operator++(week& w);
week& operator--(week& w);
week operator++(week& w, int);
week operator--(week& w, int);

week operator+(const week& w, int n);
week operator-(const week& w, int n);

week& operator+=(week& w, int n);
week& operator-=(week& w, int n);

