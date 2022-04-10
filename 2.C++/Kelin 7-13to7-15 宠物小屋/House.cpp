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
		//��ɾ�������ɾ�����ӣ��������������
		if ((*ite)->m_pAni) //�ж���û�ж���
		{
			delete (*ite)->m_pAni;
			(*ite)->m_pAni = NULL;
		}
		delete(*ite);
		(*ite) = NULL;

		//ite++;//��ʽ1
		ite = m_lstCage.erase(ite);	//��ʽ2
		//����������ɾ������һ���ڵ㣬�书�ܵ�ͬ��ite++
	}
	m_lstCage.clear();
}