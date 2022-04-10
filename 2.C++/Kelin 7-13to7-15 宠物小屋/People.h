#pragma once
#include <string>
using namespace std;
#include "Animal.h"
#include "Cage.h"
#include "House.h"

class CPeople
{
public:
	CPeople(void);
	~CPeople(void);
public:
	int m_nMoney;
	string m_nstrName;
public:
	void InitPeople(string& name, int money);
						//尽量不用值传递，用引用or指针
						//原因：值传递时并不是直接把变量a=1传过去，而是在函数里面重新创建了一个跟a的类型一样的变量b，让b=1，因此涉及到变量创建和变量赋值的过程，如果该变量类型是一个很大的类，那么会创建很久赋值很久 ，性能损耗比较大。而指针的话就是创建一个指针和赋值一个地址，性能损耗相对来说小很多，引用则是创建一个指向变量a的符号b~
	void ShowPeople();
	bool BuyAnimal(CAnimal* pAni, int AnimalKind);
	CCage* CreateCage();
	void PushAnimal(CCage* pCage, CAnimal* pAnimal);
	void PushCage(CHouse* pHouse, CCage* pCage);
	void LookAnimal(CHouse* pHouse, int Id);
	void PlayWithAniamal(CHouse* pHouse, int Id);
	void KillAnimal(CHouse* pHouse, int Id);
	void DestoryCage(CHouse* pHouse, int Id);
};

