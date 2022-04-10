#pragma once
#include <list>
#include "FoePlane.h"
using namespace std;


class CFoePlaneBox
{
public:
	list<CFoePlane*> m_lstFoePlane;
	list<CFoePlane*> m_lstBoomFoe;
public:
	CFoePlaneBox();
	~CFoePlaneBox();
public:
	void ShowAllFoePlane(HDC hdc, HDC compHdc);
	void MoveAllFoePlane();
	void ShowBoomPlane(HDC hdc, HDC compHdc);
};