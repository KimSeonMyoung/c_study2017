// exam4.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
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
		printf("%d -> %d�� \n", i + 1, count[i]);
	}

	//int a, b, ary[10], c[10] = { 1,1,1,1,1,1,1,1,1,1 };

	//for (a = 0; a<10; a++) {
	//	printf("%d ��° �� �Է� : ", a + 1);
	//	scanf("%d", &ary[a]);
	//}

	//for (a = 0; a<10; a++) {
	//	if (c[a] != 0) {
	//		for (b = a + 1; b<10; b++) {
	//			if (ary[a] == ary[b]) {
	//				c[a]++; c[b] = 0;
	//			}
	//		}
	//		printf("%d %6d��\n", ary[a], c[a]);
	//	}
	//}
	//

    return 0;
}

