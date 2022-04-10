#pragma once
#include "FoePlane.h"


class CFoePlaneMid :public CFoePlane
{
public:
	CFoePlaneMid();
	~CFoePlaneMid();
public:
	virtual void InitFoePlane(HINSTANCE hIns);
	virtual void ShowFoePlane(HDC hdc, HDC compHdc);
	virtual bool IsHitGunner(CGunner* pGunner);
	virtual bool IsHitPlayerPlane(CPlayerPlane& playerPlane);
};