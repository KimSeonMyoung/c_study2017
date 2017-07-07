#include "stdafx.h"

extern void win32_Printf(HWND, TCHAR *, ...);

int addTen(int b)
{
	b += 10;
	return b;
}

void addTen2(int *b)
{
	*b += 10;
}

void addTen3(int &b)
{
	b += 10;
}

int *addTen4(int b)
{
	b += 10;
	return &b;
}

void testProc1(HWND hWnd)
{
	win32_Printf(hWnd, L"testproc1");

	int a, c;
	a = 5;

	c = addTen(a);
	
	win32_Printf(hWnd, L"%d", c); // 15

	addTen2(&c);

	win32_Printf(hWnd, L"%d", c); //25

	addTen3(c);

	win32_Printf(hWnd, L"%d", c); //35

	int *ap = addTen4(c);

	win32_Printf(hWnd, L"%d", c); //35
}

