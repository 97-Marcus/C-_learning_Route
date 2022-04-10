#pragma once
#include <list>
using namespace std;
#include "Cage.h"

class CHouse
{
public:
	CHouse(void);
	~CHouse(void);
public:
	list<CCage*> m_lstCage;
};

