// exam4.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"


int main()
{
	int ary[] = { 2,8,15,1,8,5,19,19,3,5,6,6,2,8,2,12 ,12,12,12 };
	int count[20] = { 0 };
	int a = 0;

	for (int i = 0; i < sizeof(ary)/sizeof(ary[0]); i++) {
		printf("%d \n", ary[i]);
		count[ary[i] - 1]++;
	}
	for (int i = 0; i < sizeof(ary) / sizeof(ary[0]); i++) {
		printf("%d -> %d개 \n", i + 1, count[i]);
	}

	//int a, b, ary[10], c[10] = { 1,1,1,1,1,1,1,1,1,1 };

	//for (a = 0; a<10; a++) {
	//	printf("%d 번째 수 입력 : ", a + 1);
	//	scanf("%d", &ary[a]);
	//}

	//for (a = 0; a<10; a++) {
	//	if (c[a] != 0) {
	//		for (b = a + 1; b<10; b++) {
	//			if (ary[a] == ary[b]) {
	//				c[a]++; c[b] = 0;
	//			}
	//		}
	//		printf("%d %6d개\n", ary[a], c[a]);
	//	}
	//}
	//

    return 0;
}

