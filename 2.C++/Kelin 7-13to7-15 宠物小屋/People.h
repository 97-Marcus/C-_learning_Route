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
						//��������ֵ���ݣ�������orָ��
						//ԭ��ֵ����ʱ������ֱ�Ӱѱ���a=1����ȥ�������ں����������´�����һ����a������һ���ı���b����b=1������漰�����������ͱ�����ֵ�Ĺ��̣�����ñ���������һ���ܴ���࣬��ô�ᴴ���ܾø�ֵ�ܾ� ��������ıȽϴ󡣶�ָ��Ļ����Ǵ���һ��ָ��͸�ֵһ����ַ��������������˵С�ܶ࣬�������Ǵ���һ��ָ�����a�ķ���b~
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

