// exam2.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"


int sum(int a, int b)
{
	return a + b;
}

int mul(int c, int d)
{
	return c * d;
}

double avr(int a, int b)
{
	return (a + b) / 2.0;
}

int main()
{
	int(*fp)(int, int);
	fp = sum;
	printf("%Id \n", fp(3, 4));

	fp = mul;
	printf("%Id \n", fp(3, 4));

	double(*fp2)(int, int);
	fp2 = avr;
	printf("%lf \n", fp2(3, 4));

	int(*fps[2])(int, int);
	fps[0] = sum;
	fps[1] = mul;

	for (int i = 0; i < 2; i++)
	{
		printf("%Id \n", fps[i](3, 4));
	}


    return 0;
}

