#pragma once
#include "FoePlane.h"

class CFoePlaneBig :public CFoePlane
{
public:
	CFoePlaneBig();
	~CFoePlaneBig();
public:
	virtual void InitFoePlane(HINSTANCE hIns);
	virtual void ShowFoePlane(HDC hdc, HDC compHdc);
	virtual bool IsHitGunner(CGunner* pGunner);
	virtual bool IsHitPlayerPlane(CPlayerPlane& playerPlane);
};