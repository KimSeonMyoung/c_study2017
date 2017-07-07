#include "stdafx.h"
#include "../../engine/utils.h"

int score[3][4];

void procTest2(HWND hWnd)
{
	score[0][1] = 20;
	score[0][2] = 30;
	score[0][3] = 40;
	score[0][4] = 50;

	score[1][2] = 10;
	score[1][3] = 60;
	score[1][4] = 80;
	score[1][5] = 30;
	
	score[2][2] = 15;
	score[2][3] = 66;
	score[2][4] = 76;
	score[2][5] = 39;

	//각 학생들의 과목별 점수
	for (int i = 0; i < 4; i++) {
		win32_Printf(hWnd, L"%d %d %d %d", score[i][0], score[i][1], score[i][2], score[i][3]);
	}

	int totalScore[3];

	for (int i = 0; i <4; i++) {
		totalScore[i] = 0;
		for (int j = 0; j < 3; j++) {
			totalScore[i] += score[j][i];
		}
	}

	win32_Printf(hWnd, L"%d %d %d %d", totalScore[0], totalScore[1], totalScore[2], totalScore[3]);
	


}