// exam6.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"


int main()
{
	int test1 = 100;
	int *pTest1;

	pTest1 = &test1;

	printf("%d %d \n", pTest1, *pTest1);

	test1 = 200;
	// *pTest1 = 200;


	// * -> ����������
	// & -> �ּҿ�����
	printf(" *pTest1 -> %d \n  pTest1 -> %d \n  &test1 -> %d\n", *pTest1, pTest1, &test1);
	printf("sizeof(pTest1) -> %d \n", sizeof(pTest1));

	/////////////////////////////////////////////////////////////////////////////////////////////////
	printf(" /////////////////////////////////////////////////////////// ");

	int a;
	int *ap = &a;
	// int *ap;
	// ap = &a;
	a = 300;
	
	printf("%d , %d \n", a, *ap);
	 
	a = 500;

	printf("%d , %d \n", a, *ap);

	///////////////////////////////////////////////////////////////////////
	printf(" /////////////////////////////////////////////////////////// ");

	int b1;
	int b2;

	b1 = 1;

	b2 = b1;

	printf("%d , %d \n", b1, b2);

	b2 = 2;

	printf("%d , %d \n", b1, b2);

    return 0;
}

