// exam7.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
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

	printf("�ּҰ��� ��� : %u \n", "hello");
	printf("ù��° ���ڸ� ��� : %c \n", *"hello");
	printf("ù��° ���ڸ� ��� : %c \n", "hello"[0]);

	char *pStr = "hello world";

	printf("�ּҰ��� ��� : %u \n", pStr);
	printf("ù��° ���ڸ� ��� : %c \n", pStr[0]);
	printf("ù��° ���ڸ� ��� : %c \n", *pStr);


	for (int i = 0; pStr[i] != 0x00; i++)
	{
		printf("%c", *(pStr + i));
	}

	printf("\n");

	// hello�� �ѱ�� ����Ʈ
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

