#include "stdafx.h"

void test()
{
	int a = 5;
	int b = 6;
}


void testProc3(HWND hWnd)
{
	int a = 1;
	{
		int a = 1, b = 2;
		{
			int a = 3, b = 4;
		}
	}

	test();
}