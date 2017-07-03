// exam2.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include <string.h>

int main()
{
	// 문자열의 초기화 방법 3가지

	char str1[10] = { 'h','e','l','l','o' };
	char str2[] = { 'h','e','l','l','o','\0' };

	char str3[] = "hello";

	char str4[16];
	
	//문자열의 개수를 구하는 함수
	printf("size : %d \n", strlen(str3));
	
	for (int i = 0; i < strlen(str3); i++) 
	{
		str4[i] = str3[i];
	}
	
	printf("str4[] = %s \n", str4);

    return 0;
}

