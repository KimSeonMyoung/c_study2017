// exam5.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"


int main()
{
	// a b c
	// a = ary1[i]
	// b = temp
	// c = ary1[(sizeof(ary1) / sizeof(ary1[0]))-1-i]



	////�迭�� �ݴ�� �����.
	//int temp = 0,ary1[] = {1,2,3,4,5};
	////�� �ݱ����� �ؾ��ϳ� 

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

	//// ù��° for�� ���ǽĿ��� /2�� �ؾ� �ݴ�� ���´�
	//for (int i = 0; i < sizeof(ary1) / sizeof(ary1[0]); i++) {
	//	printf("%d \n", ary1[i]);
	//}
	

	//// ù��° for�� ���ǽĿ��� /2�� ���� �̰� ������ �ݴ�� ���´�.
	//for (int i = (sizeof(ary1) / sizeof(ary1[i]))-1; i >= 0; i--) {
	//	printf("%d \n", ary1[i]);
	//}


	///////////////////////////////////////////////
	//// �迭�� �������� ���ʺ��� ���ĵǰ� �ϱ� ///
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
	////// �迭�� ū���� ���ʺ��� ���ĵǰ� �ϱ� ///
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

