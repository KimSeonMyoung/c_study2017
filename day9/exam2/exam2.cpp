// exam2.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"


int main()
{
	double ary[] = { 1.5,20.1,16.4, 2.3, 3.5 };
	double sub = 0;
	//double *ap = ary;

	for (int i = 0; i < 5; i++)
	{
		sub += *(&ary[0] + i);
		//sub += *(ary + i);
	}

	printf("%lf \n", sub / 5);


    return 0;
}

