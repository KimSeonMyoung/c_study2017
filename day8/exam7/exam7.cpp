// exam7.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"


void assign(int *test)
{
	*test = 100;
}

void getSum(int a, int b, int *nSum) {
	
	*nSum = a + b;

}

void exchange(int *c, int *m) {
	int temp;
	temp = *c;
	*c = *m;
	*m = temp;
}

int main()
{
	int test = 0;

	assign(&test);

	printf("%d \n", test);
	///////////////////////////////////////////
	getSum(5, 6, &test);
	printf("%d \n", test);

	int c = 7, m = 8;

	exchange(&c, &m);

	printf("c = %d ,m = %d", c, m);

    return 0;
}

