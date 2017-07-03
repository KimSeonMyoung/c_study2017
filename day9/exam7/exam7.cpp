// exam7.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"


int main()
{
	/*char str[80] = "dream";
	int count = 0;

	int i = 0;

	while (str[i] != '\0') {
		count++;
	}*/

	printf("주소값을 출력 : %u \n", "hello");
	printf("첫번째 문자를 출력 : %c \n", *"hello");
	printf("첫번째 문자를 출력 : %c \n", "hello"[0]);

	char *pStr = "hello world";

	printf("주소값을 출력 : %u \n", pStr);
	printf("첫번째 문자를 출력 : %c \n", pStr[0]);
	printf("첫번째 문자를 출력 : %c \n", *pStr);


	for (int i = 0; pStr[i] != 0x00; i++)
	{
		printf("%c", *(pStr + i));
	}

	printf("\n");

	// hello를 넘기고 프린트
	pStr += 6;
	for (int i = 0; pStr[i] != 0x00; i++)
	{
		printf("%c", *(pStr + i));
	}

	printf("\n");

	pStr -= 6;

	char szBuf[256];
	for (int i = 0; pStr[i] != 0x00; i++) 
	{
		szBuf[i] = pStr[i];
	}

	pStr = szBuf;

	for (int i = 0; pStr[i] != 0x00; i++)
	{
		switch (pStr[i])
		{
			case 'l':
				pStr[i] = 'r';
				break;
			case  'r':
				pStr[i] = 'l';
				break;
		}
	}
	printf("%s \n", pStr);


    return 0;
}

