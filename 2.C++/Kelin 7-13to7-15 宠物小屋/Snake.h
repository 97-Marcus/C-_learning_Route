#pragma once
#include "Animal.h"
class CSnake :
    public CAnimal
{
public:
	CSnake(void);
	~CSnake(void);
public:
	virtual void PlayAnimal();
};

