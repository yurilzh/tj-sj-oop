/* 2451899 刘哲豪 计科 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
double definite_integration(double (*f)(double x), double low, double high, int divider)
{
	double width = (high - low) / divider;
	double value = 0;
	for (double i = 1; i <= divider; i++) {
		value += width * f(low + i * width);
	}
	return value;
}
int main()
{
	int n;
	double low, high;
	printf("请输入sinxdx的下限、上限及区间划分数量\n");
	scanf("%lf %lf %d", &low, &high, &n);
	printf("sinxdx[%g~%g/n=%d] : %g\n", low, high, n, definite_integration(sin, low, high, n));
	printf("请输入cosxdx的下限、上限及区间划分数量\n");
	scanf("%lf %lf %d", &low, &high, &n);
	printf("cosxdx[%g~%g/n=%d] : %g\n", low, high, n, definite_integration(cos, low, high, n));
	printf("请输入e^xdx的下限、上限及区间划分数量\n");
	scanf("%lf %lf %d", &low, &high, &n);
	printf("e^xdx[%g~%g/n=%d] : %g\n", low, high, n, definite_integration(exp, low, high, n));
}