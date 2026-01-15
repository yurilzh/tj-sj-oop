/* 2451899 刘哲豪 计科 */
#pragma once



/* 如果有其它全局函数需要声明，写于此处 */

/* Date类的声明 */
class Date {
protected:
    /* 除这三个以外，不允许再定义任何数据成员 */
    int year;
    int month;
    int day;

public:
    /* 允许需要的成员函数及友元函数的声明 */
    Date();
    Date(int year, int month, int day);
    explicit Date(int divideDay); // 原来的一参构造函数，实际上是转换构造
    int set(int year = 0, int month = 0, int day = 0);
    void get(int &year, int &month, int &day);
    void show();
    explicit operator int() const;
    friend Date operator+(const Date &d1, const int n);
    friend Date operator+(const int n, const Date &d1);
    friend int operator-(const Date &d1, const Date &d2);
    friend Date operator-(const Date &d1, const int n);

    Date &operator++();
    Date operator++(int);
    Date &operator--();
    Date operator--(int);

    bool operator<(Date &d2);
    bool operator<=(Date &d2);
    bool operator==(Date &d2);
    bool operator!=(Date &d2);
    bool operator>(Date &d2);
    bool operator>=(Date &d2);

    friend ostream &operator<<(ostream &out, const Date &d);
    friend istream &operator>>(istream &out, Date &d);
    /* 允许加入友元声明（如果有必要） */
};
