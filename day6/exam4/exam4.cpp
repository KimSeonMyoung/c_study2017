// exam4.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"


int main()
{

	//int i = 1;
	//int sum1 = 0, sum2 = 0; // sum1 ¦��, sum2 Ȧ��
	//while (i <= 100)
	//{
	//	if (i % 2 == 0)
	//		sum1 += i;
	//	else
	//		sum2 += i;
	//	i++;
	//}
	//printf("¦����=%d \n", sum1);
	//printf("Ȧ����=%d \n", sum2);

	/*int i = 1;
	int sum = 0;
	while (i <= 100) {
		if ((i % 2) == 1) 
		sum += i;
		i++;
	}
	printf("1���� 100���� Ȧ���� ����%d �Դϴ�. \n", sum);*/


	int i, j;

	int totalNum = 10;

	for (i = 1; i<totalNum; i++) //<--ù��° for��

	{

		for (j = 1; j<10; j++) //<--�ι�° for��

		{

			printf("%d x %d = %d\n", i, j, i*j);

		}

		printf("----------------�������\n");

	}



��ó: http://amy82.tistory.com/204 [Manual Transmission..]



	return 0;

}

