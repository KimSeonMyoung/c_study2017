// exam9.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"


int main()
{
	int ary[5] = { 10,20,30,40,50 };
	int *pAry;

	pAry = ary;

	for (int i = 0; i < sizeof(ary) / sizeof(ary[0]); i++) {
		printf("%d %d %d \n", pAry[i], *(pAry+i), *(ary+i));
	}
	
	// �����͸� �迭�� ������ �ִ°�?

	//ary = pAry;

	//�ȵȴ�

    return 0;
}

