#include "FoePlaneBox.h"
#include <typeinfo>
#include "FoePlaneSmall.h"
#include "FoePlaneMiddle.h"
#include "FoePlaneBig.h"
#include "../GameConfig/GameConfig.h"


CFoePlaneBox::CFoePlaneBox() {
	m_lstFoePlane.clear();
	m_lstBoomFoe.clear();
}

CFoePlaneBox::~CFoePlaneBox() {
	list<CFoePlane*>::iterator ite = m_lstFoePlane.begin();
	while (ite != m_lstFoePlane.end()) 
	{
		delete *ite;
		*ite = NULL;
		ite++;
	}
	m_lstFoePlane.clear();
	list<CFoePlane*>::iterator ite1 = m_lstBoomFoe.begin();
	while (ite1 != m_lstBoomFoe.end())
	{
		delete *ite1;
		*ite1 = NULL;
		ite1++;
	}
	m_lstBoomFoe.clear();
}

void CFoePlaneBox::ShowAllFoePlane(HDC hdc, HDC compHdc) {
	list<CFoePlane*>::iterator ite = m_lstFoePlane.begin();
	while (ite != m_lstFoePlane.end()) 
	{
		//��ʾ���ео��ɻ�
		(*ite)->ShowFoePlane(hdc, compHdc);
		ite++;
	}
}

void CFoePlaneBox::MoveAllFoePlane() {
	list<CFoePlane*>::iterator ite = m_lstFoePlane.begin();
	while (ite != m_lstFoePlane.end())
	{
		//�ƶ����зɻ�
		//RTTI	����ʱ����ʶ��
		//const type_info &ti = typeid(CFoePlaneSmall);	
		//const char*pName = ti.name();	
		//typeid type_infode�ķ���ֵ�����ʹ��

		//typeid((*ite))		 CFoePlane *
		//typeid(*(*ite))		 *(CFoePlane*)
		if (typeid(*(*ite)) == typeid(CFoePlaneSmall)) //ȷ����Ϊ�о�С�ɻ�
		{
			(*ite)->MoveFoePlane(FOEPLANE_SMALL_STEP);
		}else if (typeid(*(*ite)) == typeid(CFoePlaneMid)) //ȷ����Ϊ�о��зɻ�
		{
			(*ite)->MoveFoePlane(FOEPLANE_MIDDLE_STEP);
		}else if (typeid(*(*ite)) == typeid(CFoePlaneBig)) //ȷ����Ϊ�о���ɻ�
		{
			(*ite)->MoveFoePlane(FOEPLANE_BIG_STEP);
		}

		//�ж��Ƿ���� ������Ҫɾ��
		if ((*ite)->m_ny > BACKGOUND_MAPSIZE_HEIGH) 
		{
			ite = m_lstFoePlane.erase(ite);
			continue;
		}
		ite++;
	}
}

void CFoePlaneBox::ShowBoomPlane(HDC hdc, HDC compHdc) {
	list<CFoePlane*>::iterator ite = m_lstBoomFoe.begin();
	while (ite != m_lstBoomFoe.end()) {
		(*ite)->ShowFoePlane(hdc, compHdc);
		ite++;
	}
}