#include "Cage.h"
#include <iostream>
using namespace std;

CCage::CCage(void) {
	m_pAni = NULL;
	m_nId = 0;
}

CCage::~CCage(void) {

}

void CCage::InitCage(int id) {
	m_nId = id;
}

