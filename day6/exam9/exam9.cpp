// exam9.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"

void printfDiv(int a, int b) {
	int div;
	div = a / b;
	printf(" div = %d \n", div);
}

void printfMul(int a, int b) {
	int mul;
	mul = a * b;
	printf(" mul = %d \n", mul);
}


void printfSum(int a, int b) {
	int sum;
	sum = a + b;
	printf(" sum = %d \n", sum);
}

int getSum(int a, int b) {
	return a + b;
}

int main()
{
	int a, b;
	int sum;

	scanf("%d %d", &a, &b);
	printfSum(a, b);

	sum = getSum(a, b);

	printf("%d \n", sum);
    return 0;
}

