#include "stdafx.h"
#include "../../engine/utils.h"



void procTest7(HWND hWnd)
{
	int ary[][4] = {
		{1,2,3,4},
		{5,6,7,8},
		{9,10,11,12}
	};

	//int (*)[4]
	int (*ap)[4];

	ap = ary;

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 4; j++) {
			win32_Printf(hWnd, L"%d", ap[i][j]);
		}
	}
	win32_Printf(hWnd, L"-----------------");

}