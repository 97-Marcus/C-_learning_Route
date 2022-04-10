#include "PlayerPlane.h"
#include "../resource.h"
#include "../GameConfig/GameConfig.h"


CPlayerPlane::CPlayerPlane() {
	m_player = NULL;
	m_nx = 0;
	m_ny = 0;
}
CPlayerPlane::~CPlayerPlane() {
	::DeleteObject(m_player);
	m_player = NULL;
	m_nx = 0;
	m_ny = 0;
}

void CPlayerPlane::InitPlayerPlane(int x, int y, HINSTANCE hIns) {
	m_nx = x;
	m_ny = y;
	m_player = ::LoadBitmap(hIns, MAKEINTRESOURCE(IDB_PLAYERPLANE));
}

void CPlayerPlane::ShowPlayerPlane(HDC hdc, HDC compHdc) {
	::SelectObject(compHdc, m_player);
	::BitBlt(hdc, m_nx, m_ny, PALYERPLANE_SIZE_WIDTH, PALYERPLANE_SIZE_HEIGH, compHdc, 0, 0, SRCAND);
}

void CPlayerPlane::MovePlayerPlane(int direct, int step) {
	switch (direct)
	{
	case VK_LEFT:
		{
			if (m_nx - step <= 0)
				m_nx = 0;
			else 
				m_nx -= step;
		}
		break;
	case VK_RIGHT:
		{
			if (m_nx + step >= BACKGOUND_MAPSIZE_WIDTH - PALYERPLANE_SIZE_WIDTH)
				m_nx = BACKGOUND_MAPSIZE_WIDTH - PALYERPLANE_SIZE_WIDTH;
			else
				m_nx += step;
		}
	break;
	case VK_UP:
		{
			if (m_ny - step <= 0)
				m_ny = 0;
			else
				m_ny -= step;
		}
	break;
	case VK_DOWN:
		{
			if (m_ny + step >= BACKGOUND_MAPSIZE_HEIGH - PALYERPLANE_SIZE_HEIGH)
				m_nx = BACKGOUND_MAPSIZE_HEIGH - PALYERPLANE_SIZE_HEIGH;
			else
				m_ny += step;
		}
	break;
	}
}

CGunner* CPlayerPlane::SendGunner(HINSTANCE hIns) {
	CGunner* pGunner = new CGunner;
	pGunner->InitGunner(m_nx + (PALYERPLANE_SIZE_WIDTH - GUNNER_SIZE_WIDTH) / 2, m_ny - GUNNER_SIZE_HEIGH, hIns);

	return pGunner;
}