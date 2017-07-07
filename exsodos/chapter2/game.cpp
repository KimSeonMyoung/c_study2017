#include "stdafx.h"

#include <windows.h>
#include <objidl.h>
#include <gdiplus.h>
using namespace Gdiplus;
#pragma comment (lib,"Gdiplus.lib")

int g_MapRooms[][64] = {
	{
		3, 0, 0, 0, 0, 0, 0, 3,
		1,14,14,14,14,14,14, 1,
		1,14,14,14,14,14,14, 1,
		1,14,14,14,14,47,14, 1,
		1,14,14,14,14,14,14, 1,
		1,14,14,14,14,14,14, 1,
		1,14,14,14,14,14,14, 1,
		2, 2, 2, 2, 2, 2, 2, 2
	},
	{
		3, 0, 0, 0, 0, 0, 0, 3,
		1,14,14,14,14,14,14, 1,
		1,14,14,14,14,14,14, 1,
		1,14,14,10,10,14,14, 1,
		1,14,14,10,14,14,14, 1,
		1,14,14,14,14,14,14, 1,
		1,14,14,14,14,14,14, 1,
		2, 2, 2, 2, 2, 2, 2, 2
}
};

int g_MapAttarBlock[][64] = {
	{
		1, 1, 1, 1, 1, 1, 1, 1,
		1, 0, 0, 0, 0, 0, 0, 1,
		1, 0, 0, 0, 0, 0, 0, 1,
		1, 0, 0, 0, 0, 0, 0, 1,
		1, 0, 0, 0, 0, 0, 0, 1,
		1, 0, 0, 0, 0, 0, 0, 1,
		1, 0, 0, 0, 0, 0, 0, 1,
		1, 1, 1, 1, 1, 1, 1, 1
	},
	{
		1, 1, 1, 1, 1, 1, 1, 1,
		1, 0, 0, 0, 0, 0, 0, 1,
		1, 0, 0, 0, 0, 0, 0, 1,
		1, 0, 0, 0, 0, 0, 0, 1,
		1, 0, 0, 0, 0, 0, 0, 1,
		1, 0, 0, 0, 0, 0, 0, 1,
		1, 0, 0, 0, 0, 0, 0, 1,
		1, 1, 1, 1, 1, 1, 1, 1
	}
};

// 캐릭터 리젠위치, 열림스위치의 위치, 탈출구 위치
int g_StageInfo[][7] = {
	{ 3,3,5,3,7,2,31 },
	{ 1,1,5,3,7,5,47 }
};

int g_nCurrentStage;
int g_nPlayerXpos;
int g_nPlayerYpos;

// 문열림 스위치 오브젝트
int g_nItemSwitchXpos = 5;
int g_nItemSwitchYpos = 3;
int g_nItemSwitchSprIndex;
int g_nItemSwitchStatus = 0; // 0 -> 스위치 멈춤, 1 -> 스위치 작동

// 탈출구 오브젝트
int g_nExitPosX, g_nExitPosY;
int g_nExitStatus = 0; // 0:대기 1:닫기 2:열기

const int g_nTileSize = 16;
const int g_nTileXCount = 8;


DWORD g_dwGdiLoopFsm = 0; //루프상태제어

//// 문열림 닫힘 오브젝트
//int g_nItemDoorXpos = 2;
//int g_nItemDoorYpos = 7;
//int g_nItemDoorSprIndex = 50;
//int g_nItemDoorStatus = 0; // 0 -> 문닫힘, 1 -> 문열림



void StartStage(int nStage)
{

	g_nPlayerXpos = g_StageInfo[nStage][0];
	g_nPlayerYpos = g_StageInfo[nStage][1];

	// 스위치
	g_nItemSwitchXpos = g_StageInfo[nStage][2];
	g_nItemSwitchYpos = g_StageInfo[nStage][3];
	g_nItemSwitchSprIndex = g_StageInfo[nStage][6];
	g_nItemSwitchStatus = 0; //비활성상태

	//탈출구
	g_nExitPosX = g_StageInfo[nStage][4];
	g_nExitPosY = g_StageInfo[nStage][5];
	g_nExitStatus = 1;
}

void StartGame()
{
	g_nCurrentStage = 0;
	StartStage(g_nCurrentStage);

	g_dwGdiLoopFsm = 10; //랜더링 활성화 
	
}

int getMapTile(int(*pMap)[64], int mx, int my)
{
	return pMap[g_nCurrentStage][my * 8 + mx];
}

int setMapTile(int(*pMap)[64], int mx, int my, int nNewTile)
{
	int oldTile = pMap[g_nCurrentStage][my * 8 + mx];
	pMap[g_nCurrentStage][my * 8 + mx] = nNewTile;
	return oldTile;
}

void eventKeyDown(WPARAM wParam)
{

	int savePosx = g_nPlayerXpos;
	int savePosy = g_nPlayerYpos;
	switch (wParam)
	{
	case VK_UP:
		g_nPlayerYpos--;
		break;
	case VK_DOWN:
		g_nPlayerYpos++;
		break;
	case VK_LEFT:
		g_nPlayerXpos--;
		break;
	case VK_RIGHT:
		g_nPlayerXpos++;
		break;
	default:
		break;
	}
	// 벽과 충돌 처리
	if (getMapTile(g_MapAttarBlock, g_nPlayerYpos , g_nPlayerXpos) == 1)
	{
		g_nPlayerXpos = savePosx;
		g_nPlayerYpos = savePosy;
	}
}

void drawTileIndex(Graphics *pGrp, Image *pImgBasicTile, int nPosX, int nPosY, int nTileIndex)
{
	//int nTileIndex = pMap[nPosX + nPosY* g_nTileXCount];

	pGrp->DrawImage(pImgBasicTile, Rect(nPosX * 16, nPosY * 16, g_nTileSize, g_nTileSize)
		, g_nTileSize * (nTileIndex % g_nTileXCount)
		, g_nTileSize * (nTileIndex / g_nTileXCount)
		, g_nTileSize, g_nTileSize, 
		UnitPixel);
}

void drawTile(Graphics *pGrp, Image *pImgBasicTile, int nPosX, int nPosY, int *pMap)
{
	int nTileIndex = pMap[nPosX + nPosY* g_nTileXCount];

	drawTileIndex(pGrp, pImgBasicTile, nPosX, nPosY, nTileIndex);
}


void GDIPLUS_Loop(MSG &msg)
{
	//----------------------------------------------------------------------
	//gdi plus 초기화 코드 
	GdiplusStartupInput gdiplusStartupInput;
	ULONG_PTR           gdiplusToken;

	// Initialize GDI+.
	GdiplusStartup(&gdiplusToken, &gdiplusStartupInput, NULL);
	//-----------------------------------------------------------------------

	{
		bool quit = false;
		//gdiplus 가 셧다운 되기전에 객체들이 삭제되어야 하므로 일부러 지역변수선언을 한단계 내려서 사용했다.
		Gdiplus::Rect rectScreen(0, 0, 320, 240);
		Bitmap bmpMem(rectScreen.Width, rectScreen.Height);
		Graphics* graphBackBuffer = Graphics::FromImage(&bmpMem);

		Pen penRed(Color(255, 0, 0));
		Gdiplus::SolidBrush brushBlack(Color(0, 0, 0));
		Gdiplus::SolidBrush brushWhite(Color(255, 255, 255));
		FontFamily  fontFamily(L"굴림");
		Font        font(&fontFamily, 12, FontStyleRegular, UnitPixel);
		static LONG prev_tick;
		static SYSTEMTIME time;

		Image imgBasicTile(L"../../res/basic_tile/basictiles.png");
		Image imgPlayer(L"../../res/charater.png");


		while (!quit) {

			if (PeekMessage(&msg, NULL, NULL, NULL, PM_REMOVE))
			{
				if (msg.message == WM_QUIT)
					quit = true;
				TranslateMessage(&msg);
				DispatchMessage(&msg);
			}
			else {
				switch (g_dwGdiLoopFsm)
				{
				case 0:
					break;
				case 10:
				{
					GetSystemTime(&time);
					LONG time_ms = (time.wSecond * 1000) + time.wMilliseconds;
					float fDelta = (time_ms - prev_tick) / 1000.f;
					prev_tick = time_ms;

					// 게임 로직
					{
						//캐릭터위치가 스위치에 있는지 검사
						if (g_nItemSwitchStatus == 0)
						{
							if (g_nItemSwitchXpos == g_nPlayerXpos && g_nItemSwitchYpos == g_nPlayerYpos)
							{
								g_nItemSwitchStatus = 1;
								g_nExitStatus = 2;
								//setMapTile(g_MapAttarBlock, g_nExitPosX, g_nExitPosY, 0);
								//setMapTile(g_MapRooms, g_nExitPosX, g_nExitPosY, 50); //문열림 표시

								//g_MapAttarBlock[g_nCurrentStage][8 * 7 + 2] = 0; // (7,2) 위치 막힘 제거
							}
						}
						else {

							// 탈출구 로직 처리
							switch (g_nExitStatus)
							{
							case 0:
								// 대기
								break;
							case 1:
								// 문닫기
							{
								setMapTile(g_MapAttarBlock, g_nExitPosX, g_nExitPosY, 1);
								setMapTile(g_MapRooms, g_nExitPosX, g_nExitPosY, 48);
								g_nExitStatus = 0; // 대기 상태로...
							}
							break;
							case 2:
								// 문열기
								setMapTile(g_MapAttarBlock, g_nExitPosX, g_nExitPosY, 0);
								setMapTile(g_MapRooms, g_nExitPosX, g_nExitPosY, 50);
								g_nExitStatus = 0; // 대기 상태로...
								break;
							default:
								break;
							}

							// 문으로 나가기 검사
							//if (g_MapRooms[g_nCurrentStage][g_nPlayerYpos * 8 + g_nPlayerXpos] == 50) 
							if (g_nPlayerXpos == g_nExitPosX && g_nPlayerYpos == g_nExitPosY)
							{
								g_nCurrentStage += 1; //다음판으로 
								StartStage(g_nCurrentStage);
							}

							//// 캐릭터가 스위치를 눌리고 문에 있는지 검사
							//if (g_nItemDoorStatus == 0)
							//{
							//	if (g_nItemDoorXpos == g_nPlayerXpos && g_nItemDoorYpos == g_nPlayerYpos)
							//	{
							//		g_nItemDoorStatus = 1;

							//		
							//	}
							//}

						}
					}

					// 랜더링
					// Get DC
					HDC hdc = GetDC(msg.hwnd);
					{
						Graphics graphics(hdc);
						graphBackBuffer->FillRectangle(&brushBlack, rectScreen);


						// 지도 그리기
						for (int ix = 0; ix < 8; ix++) {
							for (int jy = 0; jy < 8; jy++) {
								drawTile(graphBackBuffer, 
									&imgBasicTile, 
									ix, jy, g_MapRooms[g_nCurrentStage]);
							}
						}

						// 플레이어 그리기
						//graphBackBuffer->DrawImage(&imgPlayer, Rect((g_nPlayerXpos * 16) - 8, (g_nPlayerYpos * 16) - 12, 32, 32), 0, 0, 64, 64, UnitPixel);
						graphBackBuffer->DrawImage(&imgPlayer,
							Rect((g_nPlayerXpos * 16) - 8, (g_nPlayerYpos * 16) - 16, 32, 32), //대상위치 
							0, 64 * 2, 64, 64, //원본위치 
							UnitPixel
						);

						// 각종 아이템 ,트리거, 기구물 그리기
						if (g_nItemSwitchStatus == 0) {
							drawTileIndex(graphBackBuffer, &imgBasicTile, 
								g_nPlayerXpos, g_nPlayerYpos, 
								g_nItemSwitchSprIndex
							);
						}
						else {
							//
						
						}/*if
							(g_nItemDoorStatus == 0){
							drawTileIndex(graphBackBuffer, &imgBasicTile, 
								g_nPlayerXpos, g_nPlayerYpos, 
								g_nItemSwitchSprIndex);
						}*/
						graphics.ScaleTransform(2.0, 2.0);
						graphics.DrawImage(&bmpMem, rectScreen);
						graphics.ResetTransform();
					}
					ReleaseDC(msg.hwnd, hdc);
				}
				break;
				default:
					break;
				}


			}
		}
	}

	//--------------------------------------
	//gdi plus 종료코드 
	GdiplusShutdown(gdiplusToken);
	//--------------------------------------


}

