/* 2451899 刘哲豪 计科 */
#pragma once

const double PI = 3.141592;
class Shape {
protected:
    //根据需要加入相应的成员，也可以为空
public:
    virtual void ShapeName() = 0; //此句不准动
    //根据需要加入相应的成员，也可以为空
    virtual double area() { return 0; };
};

//此处给出五个类的定义(成员函数采用体外实现形式)
class Circle : public Shape {
protected:
    double r;
public:
    Circle(double radius);
	virtual void ShapeName();
    virtual double area();
};
class Square : public Shape {
protected:
    double a;
public:
	Square(double side);
	virtual void ShapeName();
    virtual double area();
};
class Rectangle : public Shape {
protected:
    double a, b;
public:
	Rectangle(double length, double width);
	virtual void ShapeName();
    virtual double area();
};
class Triangle : public Shape {
protected:
    double a, b, c;
public:
	Triangle(double side1, double side2, double side3);
	virtual void ShapeName();
    virtual double area();
};
class Trapezoid : public Shape {
protected:
    double a, b, h;
public:
	Trapezoid(double upperBase, double lowerBase, double height);
	virtual void ShapeName();
    virtual double area();
};

