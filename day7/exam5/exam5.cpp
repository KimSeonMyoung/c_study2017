// exam5.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"


int main()
{
	// a b c
	// a = ary1[i]
	// b = temp
	// c = ary1[(sizeof(ary1) / sizeof(ary1[0]))-1-i]



	////배열을 반대로 만든다.
	//int temp = 0,ary1[] = {1,2,3,4,5};
	////왜 반까지만 해야하나 

	//// i = 0   52341
	////i - 2    54321
	//// 3      54321
	////4  52341
	//
	//for (int i = 0; i < sizeof(ary1) / sizeof(ary1[0])/2; i++) {

	//	temp = ary1[i];

	//	ary1[i] = ary1[(sizeof(ary1) / sizeof(ary1[i])) - 1 - i];

	//	ary1[(sizeof(ary1) / sizeof(ary1[i])) - 1 - i] = temp;

	//}

	//// 첫번째 for문 조건식에서 /2를 해야 반대로 나온다
	//for (int i = 0; i < sizeof(ary1) / sizeof(ary1[0]); i++) {
	//	printf("%d \n", ary1[i]);
	//}
	

	//// 첫번째 for문 조건식에서 /2를 빼고 이걸 돌리면 반대로 나온다.
	//for (int i = (sizeof(ary1) / sizeof(ary1[i]))-1; i >= 0; i--) {
	//	printf("%d \n", ary1[i]);
	//}


	///////////////////////////////////////////////
	//// 배열의 작은수가 왼쪽부터 정렬되게 하기 ///
	///////////////////////////////////////////////


	int temp = 0, ary2[] = { 3,9,27,14,83,99,1 };

	for (int i = 0; i < sizeof(ary2) / sizeof(ary2[0]) - 1; i++) 
	{
		for (int j = i + 1; j < sizeof(ary2) / sizeof(ary2[0]); j++) 
		{
			if (ary2[i] > ary2[j]) 
			{
				temp = ary2[i];
				ary2[i] = ary2[j];
				ary2[j] = temp;
			}
		}
	}
	for (int i = 0; i < sizeof(ary2) / sizeof(ary2[0]); i++) {
		printf("%d ", ary2[i]);
	}




	///////////////////////////////////////////////
	////// 배열의 큰수가 왼쪽부터 정렬되게 하기 ///
	///////////////////////////////////////////////

	//int temp = 0, ary2[] = { 3,9,27,14,83,99,1 };

	//for (int i = 0; i < sizeof(ary2) / sizeof(ary2[0]) - 1; i++)
	//{
	//	for (int j = i + 1; j < sizeof(ary2) / sizeof(ary2[0]); j++)
	//	{
	//		if (ary2[i] < ary2[j])
	//		{
	//			temp = ary2[i];
	//			ary2[i] = ary2[j];
	//			ary2[j] = temp;
	//		}
	//	}
	//}


	//for (int i = 0; i < sizeof(ary2) / sizeof(ary2[0]); i++) {
	//	printf("%d \n", ary2[i]);
	//}




    return 0;
}

