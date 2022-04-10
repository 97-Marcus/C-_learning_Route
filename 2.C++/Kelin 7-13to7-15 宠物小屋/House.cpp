#include "House.h"

#include <iostream>
using namespace std;

CHouse::CHouse(void) {
	m_lstCage.clear();
}

CHouse::~CHouse(void) {
	list<CCage*>::iterator ite = m_lstCage.begin();
	while (ite != m_lstCage.end()) 
	{
		//先删除动物，再删除笼子，最后回收清空链表
		if ((*ite)->m_pAni) //判断有没有动物
		{
			delete (*ite)->m_pAni;
			(*ite)->m_pAni = NULL;
		}
		delete(*ite);
		(*ite) = NULL;

		//ite++;//方式1
		ite = m_lstCage.erase(ite);	//方式2
		//擦除，返回删除的下一个节点，其功能等同于ite++
	}
	m_lstCage.clear();
}