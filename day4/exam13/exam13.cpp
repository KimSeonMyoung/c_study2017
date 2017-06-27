// exam13.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"


int main()
{
	int num1, num2;

	num1 = 10;
	num2 = 7;

	printf("두수의 합 : %d \n", num1 + num2);
	printf("두수의 빼기 : %d \n", num1 - num2);
	printf("두수의 곱하기 : %d \n", num1 * num2);
	printf("두수의 나누기 : %lf \n", (float)num1 / (float)num2);
	printf("두수의 나머지 : %d \n", num1 % num2);


    return 0;
}

