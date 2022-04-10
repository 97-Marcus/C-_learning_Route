#pragma once
#include "Animal.h"

class CDog :
    public CAnimal
{
public:
	CDog(void);
	~CDog(void);
public:
	virtual void PlayAnimal();
};

