/* 2451899 刘哲豪 计科 */
//允许添加需要的系统头文件及命名空间
#include "18-b1.h"
#include <iostream>
#include <cmath>
using namespace std;

//此处给出五个类的成员函数的实现
Circle::Circle(double radius)
{
	this->r = radius;
}
Square::Square(double side)
{
	this->a = side;
}
Rectangle::Rectangle(double length, double width)
{
	this->a = length;
	this->b = width;
}
Triangle::Triangle(double side1, double side2, double side3)
{
	this->a = side1;
	this->b = side2;
	this->c = side3;
}
Trapezoid::Trapezoid(double upperBase, double lowerBase, double height)
{
	this->a = upperBase;
	this->b = lowerBase;
	this->h = height;
}
void Circle::ShapeName()
{
	cout << "Circle" << endl;
}
void Square::ShapeName() 
{
	cout << "Square" << endl;
}
void Rectangle::ShapeName() 
{
	cout << "Rectangle" << endl;
}
void Triangle::ShapeName() 
{
	cout << "Triangle" << endl;
}
void Trapezoid::ShapeName() 
{
	cout << "Trapezoid" << endl;
}
double Circle::area()
{
	return (r <= 0) ? 0 : PI * r * r;
}
double Square::area() 
{
	return (a <= 0) ? 0 : a * a;
}
double Rectangle::area() 
{
	return (a <= 0 || b <= 0) ? 0 : a * b;
}
double Triangle::area() 
{
	return (a <= 0 || b <= 0 || c <= 0 || (a + b <= c) || (a + c <= b) || (b + c <= a)) ? 0 : sqrt((a + b + c) / 2 * ((a + b + c) / 2 - a) * ((a + b + c) / 2 - b) * ((a + b + c) / 2 - c));
}
double Trapezoid::area() 
{
	return (a <= 0 || b <= 0 || h <= 0) ? 0 : (a + b) * h / 2;
}

