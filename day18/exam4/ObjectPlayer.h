#pragma once

struct S_ObjectPlayer {

	irr::core::vector2df m_vPosition;
	Image *m_pImg;
	Image *mPlayerBullet;
	int m_nlife;


	//Image mPlayerBullet;
	irr::core::vector2df m_vDirection;
	irr::f64 m_fVelocity;
	irr::f64 m_fSize;
	int m_nFSM;
	double m_flifeTime;


	
};


extern void S_ObjectPlayer_OnApply(S_ObjectPlayer *pThis, double fDelta);
extern void S_ObjectPlayer_OnRender(S_ObjectPlayer *pThis, Graphics *pGrp);
extern void S_ObjectPlayer_Setup(S_ObjectPlayer *pThis,
	irr::core::vector2df &startPos,
	Image *pImg,
	/*Image *PlayerBullet,*/
	irr::core::vector2df &vStartPos,
	irr::core::vector2df &vTaegetPos,
	irr::f64 fVolumeSize);