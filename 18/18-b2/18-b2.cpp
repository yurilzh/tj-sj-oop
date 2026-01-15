/* 2451899 刘哲豪 计科 */
#include <iostream>
#include <cmath>
#include "18-b2.h"
using namespace std;

/* 1、给出各种类的实现（体外实现）
   2、不允许定义全局变量（不含const和#define）
   3、不允许添加其它系统头文件
*/

double integral::definite_integration(double (*f)(double x)) const
{
	double width = (up - low) / divider;
	double value = 0;
	for (double i = 1; i <= divider; i++) {
		value += width * f(low + i * width);
	}
	cout << this->func_name() << "[" << this->low << "~" << this->up << "/n=" << this->divider << "] : " << value << endl;
	return value;
}
istream& operator>>(istream& in, integral& fRef)
{
	cout << "请输入" << fRef.func_name() << "的下限、上限及区间划分数量" << endl;
	cin >> fRef.low >> fRef.up >> fRef.divider;
	return in;
}


double integral_sin::value() const
{
	return this->definite_integration(sin);
}
const char* integral_sin::func_name() const
{
	return this->funcName;
}

double integral_cos::value() const
{
	return this->definite_integration(cos);
}
const char* integral_cos::func_name() const
{
	return this->funcName;
}

double integral_exp::value() const
{
	return this->definite_integration(exp);
}
const char* integral_exp::func_name() const
{
	return this->funcName;
}

