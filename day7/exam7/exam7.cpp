// exam7.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
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
		printf("삽입할 위치와 값을 입력하세요. (나가시려면 15이상 입력하세요) \n");
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

