#include "FoePlaneMiddle.h"
#include "../resource.h"
#include "../GameConfig/GameConfig.h"

CFoePlaneMid::CFoePlaneMid() {
}

CFoePlaneMid::~CFoePlaneMid() {
}

void CFoePlaneMid::InitFoePlane(HINSTANCE hIns) {
	m_foePlane = ::LoadBitmap(hIns, MAKEINTRESOURCE(IDB_FOEMIDDLE));
	m_nx = rand() % (BACKGOUND_MAPSIZE_WIDTH - FOEPLANE_MIDDLE_SIZE_WEIGH + 1);
	m_ny = -FOEPLANE_MIDDLE_SIZE_HEIGH;
	m_nBlood = FOEPLANE_MIDDLE_BLOOD;
	m_nBoomshowID = 2;
}

void CFoePlaneMid::ShowFoePlane(HDC hdc, HDC compHdc) {
	::SelectObject(compHdc, m_foePlane);
	::BitBlt(hdc, m_nx, m_ny, FOEPLANE_MIDDLE_SIZE_WEIGH, FOEPLANE_MIDDLE_SIZE_HEIGH, compHdc, 0, (2 - m_nBoomshowID) * FOEPLANE_MIDDLE_SIZE_HEIGH, SRCAND);
}

bool CFoePlaneMid::IsHitGunner(CGunner* pGunner) {
	int x = (pGunner->m_nx) + GUNNER_SIZE_WIDTH / 2;
	if (m_nx <= x && x <= m_nx + FOEPLANE_MIDDLE_SIZE_WEIGH && pGunner->m_ny >= m_ny && pGunner->m_ny <= m_ny + FOEPLANE_MIDDLE_SIZE_HEIGH) {
		return true;
	}
	return false;
}


bool CFoePlaneMid::IsHitPlayerPlane(CPlayerPlane& playerPlane) {
	int x1 = (playerPlane.m_nx) + PALYERPLANE_SIZE_WIDTH / 2;
	if (m_nx <= x1 && x1 <= m_nx + FOEPLANE_MIDDLE_SIZE_WEIGH && playerPlane.m_ny >= m_ny && playerPlane.m_ny <= m_ny + FOEPLANE_MIDDLE_SIZE_HEIGH) {
		return true;
	}
	int y1 = (playerPlane.m_ny) + PALYERPLANE_SIZE_HEIGH * 2 / 3;
	if (m_nx <= playerPlane.m_nx && playerPlane.m_nx <= m_nx + FOEPLANE_MIDDLE_SIZE_WEIGH && y1 >= m_ny && y1 <= m_ny + FOEPLANE_MIDDLE_SIZE_HEIGH) {
		return true;
	}

	int x2 = (playerPlane.m_nx) + PALYERPLANE_SIZE_WIDTH;
	int y2 = (playerPlane.m_ny) + PALYERPLANE_SIZE_HEIGH * 2 / 3;
	if (m_nx <= x2 && x2 <= m_nx + FOEPLANE_MIDDLE_SIZE_WEIGH && y2 >= m_ny && y2 <= m_ny + FOEPLANE_MIDDLE_SIZE_HEIGH) {
		return true;
	}
	return false;
}
