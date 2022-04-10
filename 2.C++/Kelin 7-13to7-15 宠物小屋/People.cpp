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
		cout << "����ɹ�" << endl;\
	}\
	m_nMoney -= ANIMAL_COST;

bool CPeople::BuyAnimal(CAnimal* pAni, int AnimalKind) {
	if (pAni == NULL) 
	{
		cout << "û�ж���������������" << endl;
		return false;
	}
	switch (AnimalKind)
	{
	case ANIMAL_KIDN_CAT:
	{
		//if (m_nMoney - ANIMAL_COST_CAT < 0) {
		//	cout << "��è��Ǯ������~����Ǯ������~" << endl;
		//	return false;
		//}
		//m_nMoney -= ANIMAL_COST_CAT;

		BUY_ANIMAL(ANIMAL_COST_CAT, "��è��Ǯ������~����Ǯ������~")
	}
	break;
	case ANIMAL_KIDN_DOG:
	{
		BUY_ANIMAL(ANIMAL_COST_DOG, "�򹷹�Ǯ������~����Ǯ������~")
	}
	break;
	case ANIMAL_KIDN_SNAKE:
	{
		BUY_ANIMAL(ANIMAL_COST_SNAKE, "��С��Ǯ������~����Ǯ������~")
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
		cout << "���������ӱ�ţ����Ӧ>0����" << endl;
		cin >> Id;
	} while (Id <= 0);
	pCage->InitCage(Id);

	return pCage;
}

void CPeople::PushAnimal(CCage* pCage, CAnimal* pAnimal) {
	if (pCage == NULL) 
	{
		cout << "û�����ӣ�����װ���ﰡ" << endl;
		return;
	}
	if (pAnimal == NULL)
	{
		cout << "û�ж������װ���Ӱ�" << endl;
		return;
	}
	pCage->m_pAni = pAnimal;
	cout << "����ɹ�װ��������" << endl;
}

void CPeople::PushCage(CHouse* pHouse, CCage* pCage) {
	if (pHouse == NULL) 
	{
		cout << "û�з��Ӱ�" << endl;
		return;
	}
	if (pCage == NULL) 
	{
		cout << "û��������" << endl;
	}
	pHouse->m_lstCage.push_back(pCage);
	cout << "���ӳɹ��ŵ�������ȥ��" << endl;
}

void CPeople::LookAnimal(CHouse* pHouse, int Id) {
	if (pHouse == NULL)
	{
		cout << "û�з��Ӱ�����ȻҲû�����ӺͶ�����뿴������" << endl;
		return;
	}
	//�鿴���ӣ�id==0�Ļ����ǲ鿴�������ӣ�id=1�Ͳ鿴1�������Դ�����~
	if (Id == 0)//����鿴����������Ķ���
	{
		list<CCage*>::iterator ite = pHouse->m_lstCage.begin();
		while (ite != pHouse->m_lstCage.end()) 
		{
			if (*ite)//���ж���û������
			{
				cout << "���ӱ�ţ�ID=" << (*ite)->m_nId << "	";
				if ((*ite)->m_pAni) //�ж���������û�ж���
				{
					(*ite)->m_pAni->ShowAnimal();
				}
				else {
					cout << "û�ж���ѽ~" << endl;
				}
			}
			ite++;
		}

	}
	else {//����ƥ��ĳ��������Ķ���
		list<CCage*>::iterator ite = pHouse->m_lstCage.begin();
		while (ite != pHouse->m_lstCage.end()) 
		{
			if (*ite) 
			{
				if ((*ite)->m_nId == Id) //ƥ��ɹ�
				{
					cout << "���ӱ�ţ�ID=" << (*ite)->m_nId << "	";
					if ((*ite)->m_pAni) //�ж���������û�ж���
					{
						(*ite)->m_pAni->ShowAnimal();
					}
					else {
						cout << "û�ж���ѽ~" << endl;
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
		cout << "û�з��Ӱ�����ȻҲû�����ӺͶ�����Ǹ��¶����Լ������" << endl;
		return;
	}
	list<CCage*>::iterator ite = pHouse->m_lstCage.begin();
	while (ite != pHouse->m_lstCage.end())//����
	{
		if ((*ite) && (*ite)->m_nId == Id) //ƥ�䵽����
		{
			if ((*ite)->m_pAni)
			{
				cout << "name = " << m_nstrName << "�������~" << "	";
				(*ite)->m_pAni->PlayAnimal();
			}
			return;
		}
		ite++;
	}
	cout << "û���ҵ����ӺͶ���һ������~" << endl;
}

void CPeople::KillAnimal(CHouse* pHouse, int Id) {
	if (pHouse == NULL)
	{
		cout << "û�з��Ӱ�����ȻҲû�����ӺͶ������Ҫɱ��or���������ˣ����Ѿ��ǹ¶���~" << endl;
		return;
	}
	list<CCage*>::iterator ite = pHouse->m_lstCage.begin();
	while (ite != pHouse->m_lstCage.end())//����
	{
		if ((*ite) && (*ite)->m_nId == Id) //ƥ�䵽����
		{
			if ((*ite)->m_pAni) 
			{
				delete (*ite)->m_pAni;
				(*ite)->m_pAni = NULL;
			}
			cout << "�ɹ�ɱ������" << endl;
			return;
		}
		ite++;
	}
	cout << "û��ƥ�䵽���ӣ�ɱ������ʧ��" << endl;
}

void CPeople::DestoryCage(CHouse* pHouse, int Id) {
	if (pHouse == NULL)
	{
		cout << "û�з��Ӱ�����ȻҲû�����ӣ�û�취���������~" << endl;
		return;
	}
	list<CCage*>::iterator ite = pHouse->m_lstCage.begin();
	while (ite != pHouse->m_lstCage.end())//����
	{
		if ((*ite) && (*ite)->m_nId == Id) //ƥ�䵽����
		{
			//���ж����޶���еĻ�ɾ������
			if ((*ite)->m_pAni) 
			{
				delete (*ite)->m_pAni;
				(*ite)->m_pAni = NULL;
			}
			//��������
			delete (*ite);
			(*ite) = NULL;
			
			//ɾ������ڵ�
			pHouse->m_lstCage.erase(ite);

			cout << "�ɹ���������" << endl;
			return;
		}
		ite++;
	}
	cout << "û���ҵ���Ҫ���ٵ�����" << endl;
}
