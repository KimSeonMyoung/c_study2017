// exam5.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"


void ary_input(int *ap) {
	int i = 0;

	for(int i = 0; i<5; i++)
	{
		scanf("%d  \n", ap + i);
	}
	printf("%d \n", *ap);
}


int main()
{
	int ary[2];

	ary_input(ary);

	printf("%d  %d \n", ary[0], ary[1]);

	int ary2[5] = { 10,20,30,40,50 };
	
	int *ap = ary2 + 2;

	//printf("%d  %d \n", *(ap +1), *(ap+2));
	printf("%d  %d \n", ary2[1], ary2[2]);
	printf("%d  %d \n", ap[1], ap[2]);

    return 0;
}

