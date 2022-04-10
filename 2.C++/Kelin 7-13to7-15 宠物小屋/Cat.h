#pragma once
#include "Animal.h"

class CCat :
    public CAnimal
{
public:
    CCat(void);
    ~CCat(void);
public:
    virtual void PlayAnimal();
};

