// exam3.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"
#include <stdlib.h>

int main()
{
	char szInpuBuf[] = "23,45,67,100,45";

	char szTemp[16]; // ��ū ���� ���� 
	int szTempIndex = 0;

	// ,�������� �����  szTempIndex++
	int nSum = 0;

	for (int i = 0; i < sizeof(szInpuBuf)/sizeof(szInpuBuf[0]); i++) 
	{
		if (szInpuBuf[i] == ',' || /*szInpuBuf[i] ==NULL*/   i== sizeof(szInpuBuf) / sizeof(szInpuBuf[0]) -1 )
		{
			szTemp[szTempIndex] = NULL;
			printf("%s \n", szTemp);
			int nNum = atoi(szTemp);
			nSum += nNum;
			szTempIndex = 0;
			//break;
		}
		else {
			szTemp[szTempIndex++] = szInpuBuf[i];
		}
		
		
	}
	printf("sum %d", nSum);
    return 0;
}

