// exam1.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"


int main()
{

	char word[50];
	word[0] = 'L';
	word[1] = 'O';
	word[2] = 'V';
	word[3] = 'E';
	word[4] = '\0'; // 0x00,NULL

	printf("%s \n", word);

	TCHAR word2[50];
	word2[0] = L'사';
	word2[1] = L'랑';
	word2[2] = L'a';
	word2[3] = L'\0';

	printf("char size : %d TCHAR size : %d \n", sizeof(char), sizeof(TCHAR));

	

    return 0;
}

