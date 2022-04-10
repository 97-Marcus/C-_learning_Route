#include "FoePlane.h"

CFoePlane::CFoePlane() {
	m_foePlane = NULL;
	m_nx = 0;
	m_ny = 0;
	m_nBlood = 0;
	m_nBoomshowID = 0;
}

CFoePlane::~CFoePlane() {
	::DeleteObject(m_foePlane);
	m_foePlane = NULL;
	m_nx = 0;
	m_ny = 0;
	m_nBlood = 0;
	m_nBoomshowID = 0;
}

void CFoePlane::MoveFoePlane(int step) {
	m_ny += step;
}