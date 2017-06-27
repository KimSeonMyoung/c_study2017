// exam1.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"


int main()
{
	// 10진수
	printf("%d \n", 12);

	// 8진수는 앞에 0을 붙인다 010 -> 8
	printf("%d \n", 014);

	// 16진수
	printf("%d \n", 0xc);

	// 10진수 8진수 16진수
	printf("%d \n", 12);
	printf("%o \n", 12);
	printf("%x \n", 12);

    return 0;
}

