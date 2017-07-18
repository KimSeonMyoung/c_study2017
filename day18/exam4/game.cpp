#include "stdafx.h"


HWND g_hWnd;

#define MAX_BULLET_LIST 1000
#define MAX_EFFECT_BULLETDIE_LIST 1000
#define MAX_PLAYERBULLET_LIST 1000

BYTE g_KeyStatus[256];
S_ObjectPlayer g_objPlayer, *g_PlayerBullet_List[MAX_PLAYERBULLET_LIST];
S_ObjectBullet *g_pBullet_List[MAX_BULLET_LIST];

S_ObjectEffectBulletDie *g_pEffectBulletDie_List[MAX_EFFECT_BULLETDIE_LIST];



Image *g_pImgSpaceShip;


irr::f64 g_fAcctick = 0;
irr::f64 g_PlayerAtk = 0;

bool GameOver(S_ObjectPlayer* pThis)
{
	if (pThis->m_nlife <= 0) 
	{
		return true;
	}

	return false;
}

// -1 : 생성 실패
int AddBullet()
{
	int i;
	Image* playerbulletImg = new Image(L"../../res/fire.png");
	for (i = 0; i < MAX_BULLET_LIST; i++) {
		if (g_pBullet_List[i] == NULL) {
			S_ObjectBullet *ptr = (S_ObjectBullet *)malloc(sizeof(S_ObjectBullet));
			ObjectBullet_Setup(ptr, irr::core::vector2df(rand()%640-320, -240)/*총알발사 위치*/, g_objPlayer.m_vPosition, rand()%20/*총알크기*/ , rand() % 50 + 200/*총알발사속도*/);
			g_pBullet_List[i] = ptr;
			return i;
		}
	}


	return -1;
}

int AddBullet1()
{
	int i;
	Image* playerbulletImg = new Image(L"../../res/fire.png");
	for (i = 0; i < MAX_BULLET_LIST; i++) {
		if (g_pBullet_List[i] == NULL) {
			S_ObjectBullet *ptr = (S_ObjectBullet *)malloc(sizeof(S_ObjectBullet));
			ObjectBullet_Setup(ptr, irr::core::vector2df(rand() % 640 - 320, -240)/*총알발사 위치*/, g_objPlayer.m_vPosition, rand() % 16/*총알크기*/, rand() % 50 + 200/*총알발사속도*/);
			g_pBullet_List[i] = ptr;
			return i;
		}
	}


	return -1;
}
int AddBullet2()
{
	int i;
	Image* playerbulletImg = new Image(L"../../res/fire.png");
	for (i = 0; i < MAX_BULLET_LIST; i++) {
		if (g_pBullet_List[i] == NULL) {
			S_ObjectBullet *ptr = (S_ObjectBullet *)malloc(sizeof(S_ObjectBullet));
			ObjectBullet_Setup(ptr, irr::core::vector2df(rand() % 640 - 320, -240)/*총알발사 위치*/, g_objPlayer.m_vPosition, rand() % 20/*총알크기*/, rand() % 50 + 200/*총알발사속도*/);
			g_pBullet_List[i] = ptr;
			return i;
		}
	}


	return -1;
}

// 플레이어 발사//////////////////////////
//int AddPlayerBullet()
//{
//	int i;
//	Image* playerbulletImg = new Image(L"../../res/fire.png");
//	for (i = 0; i < MAX_PLAYERBULLET_LIST; i++) {
//		if (g_PlayerBullet_List[i] == NULL) {
//			S_ObjectPlayer *ptr = (S_ObjectPlayer *)malloc(sizeof(S_ObjectPlayer));
//			S_ObjectPlayer_Setup(ptr, irr::core::vector2df(16, 16), playerbulletImg, irr::core::vector2df(16, 16), irr::core::vector2df(16, 16), irr::f64(16));
//			g_PlayerBullet_List[i] = ptr;
//			return i;
//		}
//	}
//
//
//	return -1;
//}


int AddEffectBulletDie(irr::core::vector2df pos)
{
	int i;
	Image* img = new Image(L"../../res/boom.png");
	for (i = 0; i < MAX_EFFECT_BULLETDIE_LIST; i++) {
		if (g_pEffectBulletDie_List[i] == NULL) {
			S_ObjectEffectBulletDie *ptr = (S_ObjectEffectBulletDie *)malloc(sizeof(S_ObjectEffectBulletDie));
			ObjectEffectBulletDie_Setup(ptr, pos, img);
			g_pEffectBulletDie_List[i] = ptr;
			return i;
		}
	}
	return -1;
}

void ClearDeadBulletObj()
{
	int i;
	for (i = 0; i < MAX_BULLET_LIST; i++) {

		if (g_pBullet_List[i] != NULL && g_pBullet_List[i]->m_nFSM == 999) {
			free(g_pBullet_List[i]);
			g_pBullet_List[i] = NULL;
		}
	}
}

void ClearDeadEffectBulletDieObj()
{
	int i;
	for (i = 0; i < MAX_EFFECT_BULLETDIE_LIST; i++) {

		if (g_pEffectBulletDie_List[i] != NULL && g_pEffectBulletDie_List[i]->m_nFSM == 999) {
			free(g_pEffectBulletDie_List[i]);
			g_pEffectBulletDie_List[i] = NULL;
		}
	}
}


void OnLoop(double fDelta)
{

	if(!GameOver(&g_objPlayer))
	{
		if (fDelta < 0 || fDelta > 1.0) {
			fDelta = 0;
		}
		//시체처리
		ClearDeadBulletObj();
		ClearDeadEffectBulletDieObj();

		//총알 발사
		g_fAcctick += fDelta * 20;
		if (g_fAcctick > 3.0) {
			g_fAcctick = 0.0;
			AddBullet();
			AddBullet1();
			AddBullet2();
		}
		// 플레이어 총알 발사
		//g_PlayerAtk += fDelta * 10;
		//if (g_PlayerAtk > 3.0) {
		//	g_PlayerAtk = 0.0;

		//	AddPlayerBullet();

		//}


		//플레이어 처리
		S_ObjectPlayer_OnApply(&g_objPlayer, fDelta);

		//총알 처리
		for (int i = 0; i < MAX_BULLET_LIST; i++) {

			S_ObjectBullet *ptr = g_pBullet_List[i];
			if (ptr != NULL) {
				ObjectBullet_OnApply(ptr, fDelta);
			}
		}

		//파괴 효과
		for (int i = 0; i < MAX_EFFECT_BULLETDIE_LIST; i++) {

			S_ObjectEffectBulletDie *ptr = g_pEffectBulletDie_List[i];
			if (ptr != NULL) {
				ObjectEffectBulletDie_OnApply(ptr, fDelta);
			}
		}
	}
}
double tempa = 0;
void OnRender(double fDelta, Graphics *pGrp)
{
	pGrp->Clear(Color(0, 0, 0));


	if (!GameOver(&g_objPlayer))
	{
		TCHAR szBuf[256];
		 tempa += fDelta;
		swprintf(szBuf,L"%.0lf\n", tempa);
		OutputDebugString(szBuf);

		if (fDelta > 0) {
			plusEngine::printf(pGrp, 0, 0, L"fps : %lf", 1.0 / fDelta);
		}
		else {
			plusEngine::printf(pGrp, 0, 0, L"fps : %lf", 1000.f);
		}
		Pen pen(Color(0, 0, 0));
		//Pen pen2(Color(255, 0, 0));
		/*pGrp->DrawRectangle(&pen, 0, 0, 640, 480);
		pGrp->DrawLine(&pen, 0, 240, 640, 240);
		pGrp->DrawLine(&pen, 320, 0, 320, 480);*/

		Matrix originMat(1, 0, 0, 1, 320, 240);
		pGrp->SetTransform(&originMat);

		S_ObjectPlayer_OnRender(&g_objPlayer, pGrp);

		for (int i = 0; i < MAX_BULLET_LIST; i++) {
			S_ObjectBullet *ptr = g_pBullet_List[i];
			if (ptr != NULL) {
				ObjectBullet_OnRender(ptr, pGrp);
			}
		}
		//파괴 효과
		for (int i = 0; i < MAX_EFFECT_BULLETDIE_LIST; i++) {

			S_ObjectEffectBulletDie *ptr = g_pEffectBulletDie_List[i];
			if (ptr != NULL) {
				ObjectEffectBulletDie_OnRender(ptr, pGrp);
			}
		}

		pGrp->ResetTransform();
	}
	else
	{
		TCHAR szBuf[256];
		swprintf(szBuf,L"Game Over!");


	}
}

void OnCreate(HWND hWnd)
{
	g_hWnd = hWnd;
	plusEngine::fpOnLoop = OnLoop;
	plusEngine::fpOnRender = OnRender;
	//키상태 초기화 
	for (int i = 0; i < 256; i++) {
		g_KeyStatus[i] = 0;
	}

	for (int i = 0; i < MAX_BULLET_LIST; i++) {
		g_pBullet_List[i] = NULL;
	}
	for (int i = 0; i < MAX_EFFECT_BULLETDIE_LIST; i++) {
		g_pEffectBulletDie_List[i] = NULL;
	}

	g_pImgSpaceShip = new Image(L"../../res/spaceship_crop.png");

	S_ObjectPlayer_Setup(&g_objPlayer, irr::core::vector2df(16, 16), g_pImgSpaceShip, irr::core::vector2df(16,16), irr::core::vector2df(16,16), irr::f64 (16));

	//ObjectBullet_Setup(&g_TestBullet, irr::core::vector2df(-160, -120), g_objPlayer.m_vPosition, 8, 30);

}

void OnDestory(HWND hWnd)
{
	delete g_pImgSpaceShip;
	

	int i;
	for (i = 0; i < MAX_BULLET_LIST; i++) {
		if (g_pBullet_List[i] != NULL) {
			free(g_pBullet_List[i]);
		}
	}
}