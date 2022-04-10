#pragma once
#include <windows.h>
#include "../GunnerBox/Gunner.h"

class CPlayerPlane
{
public:
	HBITMAP m_player;
	int m_nx;
	int m_ny;
public:
	CPlayerPlane();
	~CPlayerPlane();
public:
	void InitPlayerPlane(int x, int y, HINSTANCE hIns);
	void ShowPlayerPlane(HDC hdc, HDC compHdc);
	void MovePlayerPlane(int direct, int step);
	CGunner* SendGunner(HINSTANCE hIns);
};
