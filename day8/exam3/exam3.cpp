// exam3.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include <stdlib.h>

int main()
{
	char szInpuBuf[] = "23,45,67,100,45";

	char szTemp[16]; // 토큰 저장 버퍼 
	int szTempIndex = 0;

	// ,기준으로 끊어내기  szTempIndex++
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

