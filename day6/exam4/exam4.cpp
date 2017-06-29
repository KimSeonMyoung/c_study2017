// exam4.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"


int main()
{

	//int i = 1;
	//int sum1 = 0, sum2 = 0; // sum1 짝수, sum2 홀수
	//while (i <= 100)
	//{
	//	if (i % 2 == 0)
	//		sum1 += i;
	//	else
	//		sum2 += i;
	//	i++;
	//}
	//printf("짝수합=%d \n", sum1);
	//printf("홀수합=%d \n", sum2);

	/*int i = 1;
	int sum = 0;
	while (i <= 100) {
		if ((i % 2) == 1) 
		sum += i;
		i++;
	}
	printf("1부터 100까지 홀수의 합은%d 입니다. \n", sum);*/


	int i, j;

	int totalNum = 10;

	for (i = 1; i<totalNum; i++) //<--첫번째 for문

	{

		for (j = 1; j<10; j++) //<--두번째 for문

		{

			printf("%d x %d = %d\n", i, j, i*j);

		}

		printf("----------------띄워쓰기\n");

	}



출처: http://amy82.tistory.com/204 [Manual Transmission..]



	return 0;

}

