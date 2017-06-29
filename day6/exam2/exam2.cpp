// exam2.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"


int main()
{
	printf("-----------while--------- \n");
	int nIndex = 0;
	while (nIndex > 10) {
		printf("%d \n", nIndex);
		nIndex++;	
	}

	int i, j, k;
	
	for (i = 0; i < 10; i++)
	{
		printf("%d \n", i);
		for (j = 0; j < 10; j++)
		{
			printf("%d \n", j+1);
		}
	}

    return 0;
}

