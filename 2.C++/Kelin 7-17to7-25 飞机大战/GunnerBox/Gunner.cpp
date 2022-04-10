#include "Gunner.h"
#include "../resource.h"
#include "../GameConfig/GameConfig.h"

CGunner::CGunner() {
	m_hGunner = NULL;
	m_nx = 0;
	m_ny = 0;
}

CGunner::~CGunner() {
	::DeleteObject(m_hGunner);
	m_hGunner = NULL;
	m_nx = 0;
	m_ny = 0;
}

void CGunner::InitGunner(int x, int y, HINSTANCE hIns) {
	m_nx = x;
	m_ny = y;
	m_hGunner = ::LoadBitmap(hIns, MAKEINTRESOURCE(IDB_GUNNER));
}

void CGunner::ShowGunner(HDC hdc, HDC compHdc) {
	::SelectObject(compHdc, m_hGunner);
	::BitBlt(hdc, m_nx, m_ny, GUNNER_SIZE_WIDTH, GUNNER_SIZE_HEIGH, compHdc, 0, 0, SRCAND);
}

void CGunner::MoveGunner(int step) {
	m_ny -= step;
}