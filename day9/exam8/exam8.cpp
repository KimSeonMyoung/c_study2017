// exam8.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"


int main()
{
	char *strItems = "pike, plate famor, lather grove, sword, dager";

	char nIndexTable[32];

	// �ε��� ���̺� ����
	int nCount = 0;
	int i;
	for (int i = 0; strItems[i] != 0x00; i++) 
	{
		if (strItems[i] == ',')
		{
			nIndexTable[nCount++] = i;
		}
	}
	nIndexTable[nCount] = i;

	int nIndex = 0;
	printf("select index : ");
	scanf("%d", &nIndex);
	
	char *pTemp = &(strItems[nIndexTable[nIndex]]);
	int nSize =( nIndexTable[nIndex + 1] - nIndexTable[nIndex])-1;
	pTemp += 1;

	for (int i = 0; i < nSize; i++) 
	{
		printf("%c", pTemp[i]);
	}

	printf("\n");

	return 0;
}

