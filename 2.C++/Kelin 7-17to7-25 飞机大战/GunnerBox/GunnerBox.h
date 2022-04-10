#pragma once
#include <windows.h>
#include "Gunner.h"
#include <list>
using namespace std;


class CGunnerBox
{
public:
	list<CGunner*> m_lstGunner;
public:
	CGunnerBox();
	~CGunnerBox();
public:
	void ShowAllGunner(HDC hdc, HDC compHdc);
	void MoveAllGunner(int step);
};