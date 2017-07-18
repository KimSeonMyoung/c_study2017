#include "stdafx.h"

void S_ObjectPlayer_OnApply(S_ObjectPlayer *pThis, double fDelta)
{
	int PlayerSpeed = 500;
	int playerbulletspeed = 1000;

	if (g_KeyStatus[VK_LEFT]) {
		pThis->m_vPosition += fDelta * PlayerSpeed * irr::core::vector2df(-1, 0);
		if (pThis->m_vPosition.X <= -320) {
			pThis->m_vPosition.X += 1000;
		}
	}
	if (g_KeyStatus[VK_RIGHT]) {
		pThis->m_vPosition += fDelta * PlayerSpeed * irr::core::vector2df(1, 0);
		if (pThis->m_vPosition.X >= 640) {
			pThis->m_vPosition.X -= 1000;
		}
	}

	if (g_KeyStatus[VK_UP]) {
		pThis->m_vPosition += fDelta * PlayerSpeed * irr::core::vector2df(0, -1);
		if (pThis->m_vPosition.Y <= -240) {
			pThis->m_vPosition.Y += 1000;
		}
	}
	if (g_KeyStatus[VK_DOWN]) {
		pThis->m_vPosition += fDelta * PlayerSpeed * irr::core::vector2df(0, 1);
		if (pThis->m_vPosition.Y >= 480) {
			pThis->m_vPosition.Y -= 1000;
		}
	}
	if (g_KeyStatus[VK_SPACE]) {
		pThis->m_vPosition += fDelta *  playerbulletspeed * irr::core::vector2df(0, -1);
	}
}

void S_ObjectPlayer_OnRender(S_ObjectPlayer *pThis, Graphics *pGrp)
{
	//spaceship_crop.png
	pGrp->DrawImage(pThis->m_pImg, RectF(pThis->m_vPosition.X - 43 / 2, pThis->m_vPosition.Y - 35 / 2, 43, 35));

	pGrp->DrawImage(pThis->mPlayerBullet, RectF(pThis->m_vPosition.X - 40 / 2, pThis->m_vPosition.Y - 40 / 2, 40, 40));
}

void S_ObjectPlayer_Setup(S_ObjectPlayer *pThis, 
	irr::core::vector2df &startPos, 
	Image *pImg,
	/*Image *PlayerBullet,*/ 
	irr::core::vector2df &vStartPos,
	irr::core::vector2df &vTaegetPos, 
	irr::f64 fVolumeSize)
{

	pThis->m_pImg = pImg;
	pThis->m_vPosition = startPos;
	pThis->m_nlife = 20;


	/*pThis->mPlayerBullet = PlayerBullet;*/

	pThis->m_fSize = fVolumeSize;
	pThis->m_vDirection = vTaegetPos - vStartPos;
	pThis->m_vDirection.normalize();
	pThis->m_flifeTime = 0;
	pThis->m_nFSM = 0; //ready
	

}