/* 2451899 刘哲豪 计科 */
#pragma once

#include <iostream>
using namespace std;
/* 1、给出各种类的定义
   2、不允许定义全局变量（不含const和#define）
   3、不允许添加其它系统头文件
*/
class integral {
protected:
	double low;
	double up;
	int divider;
	double definite_integration(double (*f)(double x)) const;
	virtual const char* func_name() const = 0;
public:
	virtual double value() const = 0;
	friend istream& operator>>(istream& in, integral& fRef);
};

class integral_sin : public integral {
	const char* funcName = "sinxdx";
public:
	virtual double value() const;
	virtual const char* func_name() const;
};

class integral_cos : public integral {
	const char* funcName = "cosxdx";
public:
	virtual double value() const;
	virtual const char* func_name() const;
};
class integral_exp : public integral {
	const char* funcName = "e^xdx";
public:
	virtual double value() const;
	virtual const char* func_name() const;
};
