#include "People.h"
#include "Def_config.h"
#include <iostream>
using namespace std;

CPeople::CPeople(void) {
	m_nMoney = 0;
	m_nstrName = "	";
}

CPeople::~CPeople(void) {
	m_nMoney = 0;
	m_nstrName = "	";
}

void CPeople::InitPeople(string& name, int money) {
	m_nMoney = money;
	m_nstrName = name;
}

void CPeople::ShowPeople() {
	cout << "people info:name" << m_nstrName << ",money=" << m_nMoney << endl;
}

#define BUY_ANIMAL(ANIMAL_COST,TIPS)\
	if (m_nMoney - ANIMAL_COST < 0){\
	cout << TIPS << endl;\
	return false;\
	}\
	else\
	{\
		cout << "购买成功" << endl;\
	}\
	m_nMoney -= ANIMAL_COST;

bool CPeople::BuyAnimal(CAnimal* pAni, int AnimalKind) {
	if (pAni == NULL) 
	{
		cout << "没有动物啦，不用买了" << endl;
		return false;
	}
	switch (AnimalKind)
	{
	case ANIMAL_KIDN_CAT:
	{
		//if (m_nMoney - ANIMAL_COST_CAT < 0) {
		//	cout << "买猫咪钱不够噢~攒攒钱再来吧~" << endl;
		//	return false;
		//}
		//m_nMoney -= ANIMAL_COST_CAT;

		BUY_ANIMAL(ANIMAL_COST_CAT, "买猫咪钱不够噢~攒攒钱再来吧~")
	}
	break;
	case ANIMAL_KIDN_DOG:
	{
		BUY_ANIMAL(ANIMAL_COST_DOG, "买狗狗钱不够噢~攒攒钱再来吧~")
	}
	break;
	case ANIMAL_KIDN_SNAKE:
	{
		BUY_ANIMAL(ANIMAL_COST_SNAKE, "买小蛇钱不够噢~攒攒钱再来吧~")
	}
	break;
	}
	return true;
}

CCage* CPeople::CreateCage() {
	CCage* pCage = new CCage;
	int Id = 0;
	do 
	{
		cout << "请输入笼子编号（编号应>0）：" << endl;
		cin >> Id;
	} while (Id <= 0);
	pCage->InitCage(Id);

	return pCage;
}

void CPeople::PushAnimal(CCage* pCage, CAnimal* pAnimal) {
	if (pCage == NULL) 
	{
		cout << "没有笼子，不能装动物啊" << endl;
		return;
	}
	if (pAnimal == NULL)
	{
		cout << "没有动物，不用装笼子啊" << endl;
		return;
	}
	pCage->m_pAni = pAnimal;
	cout << "动物成功装进笼子啦" << endl;
}

void CPeople::PushCage(CHouse* pHouse, CCage* pCage) {
	if (pHouse == NULL) 
	{
		cout << "没有房子啊" << endl;
		return;
	}
	if (pCage == NULL) 
	{
		cout << "没有笼子啦" << endl;
	}
	pHouse->m_lstCage.push_back(pCage);
	cout << "笼子成功放到房子里去啦" << endl;
}

void CPeople::LookAnimal(CHouse* pHouse, int Id) {
	if (pHouse == NULL)
	{
		cout << "没有房子啊，当然也没有笼子和动物，你想看空气吗？" << endl;
		return;
	}
	//查看笼子，id==0的话，是查看所有笼子，id=1就查看1号笼子以此类推~
	if (Id == 0)//代表查看所有笼子里的动物
	{
		list<CCage*>::iterator ite = pHouse->m_lstCage.begin();
		while (ite != pHouse->m_lstCage.end()) 
		{
			if (*ite)//先判断有没有笼子
			{
				cout << "笼子编号：ID=" << (*ite)->m_nId << "	";
				if ((*ite)->m_pAni) //判断笼子里有没有动物
				{
					(*ite)->m_pAni->ShowAnimal();
				}
				else {
					cout << "没有动物呀~" << endl;
				}
			}
			ite++;
		}

	}
	else {//遍历匹配某号笼子里的动物
		list<CCage*>::iterator ite = pHouse->m_lstCage.begin();
		while (ite != pHouse->m_lstCage.end()) 
		{
			if (*ite) 
			{
				if ((*ite)->m_nId == Id) //匹配成功
				{
					cout << "笼子编号：ID=" << (*ite)->m_nId << "	";
					if ((*ite)->m_pAni) //判断笼子里有没有动物
					{
						(*ite)->m_pAni->ShowAnimal();
					}
					else {
						cout << "没有动物呀~" << endl;
					}
					return;
				}
			}
			ite++;
		}
	}
}

void CPeople::PlayWithAniamal(CHouse* pHouse, int Id) {
	if (pHouse == NULL)
	{
		cout << "没有房子啊，当然也没有笼子和动物，你是个孤儿，自己玩儿吧" << endl;
		return;
	}
	list<CCage*>::iterator ite = pHouse->m_lstCage.begin();
	while (ite != pHouse->m_lstCage.end())//遍历
	{
		if ((*ite) && (*ite)->m_nId == Id) //匹配到笼子
		{
			if ((*ite)->m_pAni)
			{
				cout << "name = " << m_nstrName << "正在玩儿~" << "	";
				(*ite)->m_pAni->PlayAnimal();
			}
			return;
		}
		ite++;
	}
	cout << "没有找到笼子和动物一块儿玩儿~" << endl;
}

void CPeople::KillAnimal(CHouse* pHouse, int Id) {
	if (pHouse == NULL)
	{
		cout << "没有房子啊，当然也没有笼子和动物，不需要杀死or抛弃动物了，你已经是孤儿了~" << endl;
		return;
	}
	list<CCage*>::iterator ite = pHouse->m_lstCage.begin();
	while (ite != pHouse->m_lstCage.end())//遍历
	{
		if ((*ite) && (*ite)->m_nId == Id) //匹配到笼子
		{
			if ((*ite)->m_pAni) 
			{
				delete (*ite)->m_pAni;
				(*ite)->m_pAni = NULL;
			}
			cout << "成功杀死动物" << endl;
			return;
		}
		ite++;
	}
	cout << "没有匹配到笼子，杀死动物失败" << endl;
}

void CPeople::DestoryCage(CHouse* pHouse, int Id) {
	if (pHouse == NULL)
	{
		cout << "没有房子啊，当然也没有笼子，没办法销毁笼子嗷~" << endl;
		return;
	}
	list<CCage*>::iterator ite = pHouse->m_lstCage.begin();
	while (ite != pHouse->m_lstCage.end())//遍历
	{
		if ((*ite) && (*ite)->m_nId == Id) //匹配到笼子
		{
			//先判断有无动物，有的话删除动物
			if ((*ite)->m_pAni) 
			{
				delete (*ite)->m_pAni;
				(*ite)->m_pAni = NULL;
			}
			//销毁笼子
			delete (*ite);
			(*ite) = NULL;
			
			//删除链表节点
			pHouse->m_lstCage.erase(ite);

			cout << "成功销毁笼子" << endl;
			return;
		}
		ite++;
	}
	cout << "没有找到需要销毁的笼子" << endl;
}
