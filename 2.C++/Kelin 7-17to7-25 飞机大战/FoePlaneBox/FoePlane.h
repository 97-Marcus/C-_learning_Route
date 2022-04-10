#pragma once
#include <windows.h>
#include "../PlayerPlane/PlayerPlane.h"

class CFoePlane
{
public:
	HBITMAP m_foePlane;
	int m_nx;
	int m_ny;
	int m_nBlood;
	int m_nBoomshowID;
public:
	CFoePlane();
	~CFoePlane();
public:
	virtual void InitFoePlane(HINSTANCE hIns) = 0;
	void MoveFoePlane(int step);
	virtual void ShowFoePlane(HDC hdc, HDC compHdc) = 0;
	virtual bool IsHitGunner(CGunner* pGunner) = 0;
	virtual bool IsHitPlayerPlane(CPlayerPlane& playerPlane) = 0;
};
