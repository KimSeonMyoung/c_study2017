// exam3.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"


int main()
{
	int ary[5] = { 10, 20, 30, 40, 50 };
	int *ap = ary;

	printf("%d \n", *(ary + 1));
	printf("%d \n", *(ap + 1));
	
	// �����Ͱ��� �ٲٴ°�
	ap += 1;
	printf("%d \n", *(ap + 1));

	//ary = ary + 1;  // �б⸸ �����ϰ� ���Ⱑ ���� �ʴ´�!!!!!!!!!!

    return 0;
}

