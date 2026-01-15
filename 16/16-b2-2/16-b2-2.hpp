/* 2451899 ¡ı’‹∫¿ º∆ø∆ */
#include <iostream>
#include <string>
using namespace std;
template<typename T, int ROW, int COL>
class matrix {
private:
	T value[ROW][COL];
public:
	matrix operator+(const matrix& b);
	matrix& operator=(const matrix& a);
	template<typename T2, int ROW2, int COL2>
	friend ostream& operator<<(ostream& out, const matrix<T2, ROW2, COL2>& a);
	template<typename T2, int ROW2, int COL2>
	friend istream& operator>>(istream& in, matrix<T2, ROW2, COL2>& a);
};

template<typename T, int ROW, int COL>
matrix<T, ROW, COL> matrix<T, ROW, COL>::operator+(const matrix<T, ROW, COL>& b)
{
	matrix sum;
	for (int r = 0; r < ROW; r++)
		for (int c = 0; c < COL; c++)
			sum.value[r][c] = b.value[r][c] + this->value[r][c];
	return sum;
}
template<typename T, int ROW, int COL>
matrix<T, ROW, COL>& matrix<T, ROW, COL>::operator=(const matrix<T, ROW, COL>& a)
{
	for (int r = 0; r < ROW; r++)
		for (int c = 0; c < COL; c++)
			this->value[r][c] = a.value[r][c];
	return *this;
}
template<typename T, int ROW, int COL>
ostream& operator<<(ostream& out, const matrix<T, ROW, COL>& a)
{
	for (int r = 0; r < ROW; r++) {
		for (int c = 0; c < COL; c++)
			out << a.value[r][c] << ' ';
		out << endl;
	}
	return out;
}

template<typename T, int ROW, int COL>
istream& operator>>(istream& in, matrix<T, ROW, COL>& a)
{
	for (int r = 0; r < ROW; r++)
		for (int c = 0; c < COL; c++) {
			in >> a.value[r][c];
			if (!in.good())
				break;
		}
	return in;
}

