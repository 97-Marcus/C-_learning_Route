#include "BackGround.h"
#include "../resource.h"
#include "../GameConfig/GameConfig.h"

CBackGround::CBackGround() {
	m_nx = 0;
	m_ny = 0;
	m_backUp = NULL;
	m_backDown = NULL;
}

CBackGround::~CBackGround() {
	m_nx = 0;
	m_ny = 0;
	::DeleteObject(m_backUp);
	::DeleteObject(m_backDown);
}

void CBackGround::InitBackGround(int x, int y, HINSTANCE hIns) {
	m_nx = x;
	m_ny = y;
	m_backUp = ::LoadBitmap(hIns, MAKEINTRESOURCE(IDB_BACKGROUND));
	m_backDown = ::LoadBitmap(hIns, MAKEINTRESOURCE(IDB_BACKGROUND));
}

void CBackGround::ShowBackGround(HDC hdc, HDC compHdc) {
	::SelectObject(compHdc, m_backDown);
	::BitBlt(hdc, m_nx, m_ny, BACKGOUND_MAPSIZE_WIDTH, BACKGOUND_MAPSIZE_HEIGH, compHdc, 0, 0, SRCCOPY);
	::SelectObject(compHdc, m_backUp);
	::BitBlt(hdc, m_nx, m_ny - BACKGOUND_MAPSIZE_HEIGH, BACKGOUND_MAPSIZE_WIDTH, BACKGOUND_MAPSIZE_HEIGH, compHdc, 0, 0, SRCCOPY);
}

void CBackGround::MoveBackGround(int step) {
	if (m_ny + step >= 550) 
	{
		m_ny = 0;
	}
	else {
		m_ny += step;
	}
}