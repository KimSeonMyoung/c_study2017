#include "stdafx.h"

extern void win32_Printf(HWND, TCHAR *, ...);

void testProc3(HWND hWnd)
{
	double ary[] = { 0.1,0.3,0.5,0.7,0.9 };

	static int nCount = 0;

	win32_Printf(hWnd, L"%lf", ary[nCount % 5]);
	nCount++;
}