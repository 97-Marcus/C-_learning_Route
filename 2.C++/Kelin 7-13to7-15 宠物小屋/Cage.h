#pragma once
#include "Animal.h"

class CCage
{
public:
	CCage(void);
	~CCage(void);
public:
	CAnimal* m_pAni;
	int m_nId;
public:
	void InitCage(int id);
};

