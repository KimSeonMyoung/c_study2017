// exam7.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"

void dumpBuf(int nBuf[]) {
	for (int i = 0; i <sizeof(nBuf)/sizeof(nBuf[0]); i++) {
		printf("%d", nBuf[i]);
	}
	printf("\n");
}

int main()
{

	int nBuf[16] = {  };

	bool bLoop = true;
	while (bLoop) {
		int index, nValue;
		printf("������ ��ġ�� ���� �Է��ϼ���. (�����÷��� 15�̻� �Է��ϼ���) \n");
		scanf("%d %d", &index, &nValue);
	
		if (index > 15 ) bLoop = false;

		//nBuf[index + 1] = nBuf[index];
		
		for (int i = 15; i > index; i--) {
			nBuf[i] = nBuf[i - 1];
		}

		nBuf[index] = nValue;

		dumpBuf(nBuf);
	}
	
    return 0;
}

