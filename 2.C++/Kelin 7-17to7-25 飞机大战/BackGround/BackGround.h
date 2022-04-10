#pragma once
#include <windows.h>

class CBackGround
{
public:
	int m_nx;
	int m_ny;
	HBITMAP m_backUp;
	HBITMAP m_backDown;
public:
	CBackGround();
	~CBackGround();
public:
	void InitBackGround(int x, int y, HINSTANCE hIns);
	void ShowBackGround(HDC hdc, HDC compHdc);
	void MoveBackGround(int step);
};
