// exam8.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"



int main()
{
	int nNum = 0x11223344;
	unsigned char *pTest;

	pTest = (unsigned char *)&nNum;

	for (int i = 0; i < 4; i++) {
		printf("%x \n", *(pTest + i));
	}

	nNum = 0;

	// nNum : 8 �θ����
//	*(pTest + 0)= 8;
//	*(pTest + 1) = 8;
//	*(pTest + 2) = 8;
//	*(pTest + 3) = 8;

	printf("%x \n", nNum);


    return 0;
}

