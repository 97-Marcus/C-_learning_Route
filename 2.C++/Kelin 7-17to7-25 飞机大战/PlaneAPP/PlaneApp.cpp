#include "PlaneApp.h"
#include "../GameConfig/GameConfig.h"
#include <time.h>
#include "../FoePlaneBox/FoePlane.h"
#include "../FoePlaneBox/FoePlaneBig.h"
#include "../FoePlaneBox/FoePlaneMiddle.h"
#include "../FoePlaneBox/FoePlaneSmall.h"

GET_OBJECT(CPlaneApp)
CLASS_CONFIG(WND_PARAM_X, WND_PARAM_Y, WND_PARAM_WIDTH, WND_PARAM_HEIGH, WND_PARAM_TITLE)

CPlaneApp::CPlaneApp() {

}
CPlaneApp::~CPlaneApp() {

}

void CPlaneApp::OnCreate() {
	//���������
	srand((unsigned int)time(NULL));

	//������ʱ��
	SetTimmer();

	//��ʼ������
	m_back.InitBackGround(0, 0, this->m_hInstance);
	m_player.InitPlayerPlane((BACKGOUND_MAPSIZE_WIDTH - PALYERPLANE_SIZE_WIDTH) / 2, BACKGOUND_MAPSIZE_HEIGH - PALYERPLANE_SIZE_HEIGH, this->m_hInstance);

}//���ڴ�����Ϣ

void CPlaneApp::OnPaint() {

	//��ȡ����DC
	PAINTSTRUCT ps = { 0 };
	HDC hdc = ::BeginPaint(this->m_hWnd, &ps);

	//��������ļ�����DC�ͼ�����λͼ�������м���~��
	HDC cacheDC = ::CreateCompatibleDC(hdc);
	HBITMAP cachemap = ::CreateCompatibleBitmap(hdc, BACKGOUND_MAPSIZE_WIDTH, BACKGOUND_MAPSIZE_HEIGH);
	::SelectObject(cacheDC, cachemap);

	//����������DC
	HDC compDC = ::CreateCompatibleDC(cacheDC);
	m_back.ShowBackGround(cacheDC, compDC);
	m_player.ShowPlayerPlane(cacheDC, compDC);
	m_gunbox.ShowAllGunner(cacheDC, compDC);
	m_foebox.ShowAllFoePlane(cacheDC, compDC);
	m_foebox.ShowBoomPlane(cacheDC, compDC);
	
	//��˸����ʵ����ˢ���ʵ����⣬û��ͬʱˢ�£������ʽ�����ǰ�����Ҫ����������һ�������м�����Ȼ����һ������������dc�ϡ���˫���壩
	BitBlt(hdc, 0, 0, BACKGOUND_MAPSIZE_WIDTH, BACKGOUND_MAPSIZE_HEIGH, cacheDC, 0, 0, SRCCOPY);

	//ɾ���ͷ�DC
	DeleteDC(compDC);
	compDC = NULL;

	::DeleteObject(cachemap);
	cachemap = NULL;
	DeleteDC(cacheDC);
	cacheDC = NULL;

	::EndPaint(this->m_hWnd, &ps);

}//�ػ���Ϣ

void CPlaneApp::OnGameRun(WPARAM wParam) {
	switch (wParam)
	{
	case TIMER_BACKGROUND_MOVE_ID:	//�����ƶ�
		{
			m_back.MoveBackGround(4);
		}
		break;
	case TIMER_PLAYERPLANE_MOVE_ID:	//��ҷɻ��ƶ�
		{
			if (::GetAsyncKeyState(VK_LEFT)) {
				m_player.MovePlayerPlane(VK_LEFT, PLAYERPLANE_MOVE_STEP);
			}
			if (::GetAsyncKeyState(VK_RIGHT)) {
				m_player.MovePlayerPlane(VK_RIGHT, PLAYERPLANE_MOVE_STEP);
			}
			if (::GetAsyncKeyState(VK_UP)) {
				m_player.MovePlayerPlane(VK_UP, PLAYERPLANE_MOVE_STEP);
			}
			if (::GetAsyncKeyState(VK_DOWN)) {
				m_player.MovePlayerPlane(VK_DOWN, PLAYERPLANE_MOVE_STEP);
			}
		}
		break;
	case TIMER_GUNNER_MOVE_ID:	//�ڵ��ƶ�
		{
			m_gunbox.MoveAllGunner(GUNNER_MOVE_STEP);
		}
		break;
	case TIMER_GUNNER_SEND_ID:	//�ڵ�����
		{
			CGunner* pGunner = m_player.SendGunner(this->m_hInstance);
			m_gunbox.m_lstGunner.push_back(pGunner);
		}
		break;
	case TIMER_SMALLFOE_CREATE_ID:	//�����о�С�ɻ�
		{
			CFoePlane* pFoe = new CFoePlaneSmall;
			pFoe->InitFoePlane(this->m_hInstance);
			//�ӵ��о��ɻ�������
			m_foebox.m_lstFoePlane.push_back(pFoe);
		}
		break;
	case TIMER_MIDDLEFOE_CREATE_ID:	//�����о��зɻ�
		{
			CFoePlane* pFoe = new CFoePlaneMid;
			pFoe->InitFoePlane(this->m_hInstance);
			//�ӵ��о��ɻ�������
			m_foebox.m_lstFoePlane.push_back(pFoe);
		}
		break;
	case TIMER_BIGFOE_CREATE_ID:	//�����о���ɻ�
		{
			CFoePlane* pFoe = new CFoePlaneBig;
			pFoe->InitFoePlane(this->m_hInstance);
			//�ӵ��о��ɻ�������
			m_foebox.m_lstFoePlane.push_back(pFoe);
		}
		break;
	case TIMER_FOEPLANE_MOVE_ID:	//�о��ɻ��ƶ�
		{
			m_foebox.MoveAllFoePlane();
		}
		break;
	case TIMER_CHEAK_ISHIT_ID:	//�о��ɻ��Ƿ�ײ����ҷɻ�or�ڵ�
		{
			bool isBOOM = false;
			list<CFoePlane*>::iterator iteFoe = m_foebox.m_lstFoePlane.begin();
			while (iteFoe != m_foebox.m_lstFoePlane.end()) 
			{
				//�������ео��ɻ�
				//�ж��Ƿ�ײ����ҷɻ�
				if ((*iteFoe)->IsHitPlayerPlane(m_player)) 
				{
					//ײ������Ϸ����
					GameOver();
					return;
				}
				//�ж��Ƿ�ײ���ڵ�
				list<CGunner*>::iterator iteGun = m_gunbox.m_lstGunner.begin();
				while (iteGun != m_gunbox.m_lstGunner.end())	//���������ڵ� 
				{
					if ((*iteFoe)->IsHitGunner((*iteGun))) //�жϵо��ɻ��Ƿ�ײ�������ڵ�
					{
						{
							//ײ����Ҫɾ���ڵ�
							iteGun = m_gunbox.m_lstGunner.erase(iteGun);
							//��Ϊerase�ķ���ֵ����һ������ͬ���Ѿ�++�ˣ���������break��continue
							//�о��ɻ�Ѫ������
							(*iteFoe)->m_nBlood -= GUNNER_HURT_BLOOD;
							//�ж�Ѫ���Ƿ�Ϊ0��Ϊ0����ʾ��ը
							if ((*iteFoe)->m_nBlood <= 0) {
								isBOOM = true;
								//�ƶ��о��ɻ��������������ƶ�����ը����
								m_foebox.m_lstBoomFoe.push_back(*iteFoe);
								//ɾ�������������Ѿ��ƶ���ĵо��ɻ�
								iteFoe = m_foebox.m_lstFoePlane.erase(iteFoe);
								//��Ϊerase�ķ���ֵ����һ������ͬ���Ѿ�++�ˣ���������isBOOM��Ϊ���ֵ							break;
						}
						continue;
					}
					iteGun++;
				}
				if (isBOOM)
				{
					isBOOM = false;
				}
				else
				{
					iteFoe++;
				}
			}
		}
		break;
	case TIMER_BOOMPLANE_CHANGE_ID:	//�о��ɻ���ըЧ���л�
		{
			list<CFoePlane*>::iterator ite = m_foebox.m_lstBoomFoe.begin();
			while (ite != m_foebox.m_lstBoomFoe.end()) {
				(*ite)->m_nBoomshowID--;
				if ((*ite)->m_nBoomshowID < 0)
				{
					delete (*ite);
					(*ite) = NULL;
					ite = m_foebox.m_lstBoomFoe.erase(ite);
					continue;
				}
				ite++;
			}
		}
		break;
	}
	RECT rect = { 0,0,BACKGOUND_MAPSIZE_WIDTH ,BACKGOUND_MAPSIZE_HEIGH };
	::InvalidateRect(this->m_hWnd, &rect, FALSE);

}//��ʱ������Ҫ���������ֶ���Ӷ�ʱ�������ô������

//void CPlaneApp::OnKeyDown(WPARAM wParam) {
//	
//	//m_player.MovePlayerPlane(wParam, PLAYERPLANE_MOVE_STEP);
//
//}//���̰��´�����Ϣ

void CPlaneApp::SetTimmer() {

	//���ñ����ƶ��Ķ�ʱ��
	::SetTimer(this->m_hWnd, TIMER_BACKGROUND_MOVE_ID, TIMER_BACKGROUND_MOVE_FREQUENCY_MS, NULL);

	//���ü������Ƿ��µĶ�ʱ��(��ҷɻ��ƶ�)
	::SetTimer(this->m_hWnd, TIMER_PLAYERPLANE_MOVE_ID, TIMER_PLAYERPLANE_MOVE_FREQUENCY_MS, NULL);

	//�ڵ��ƶ��Ķ�ʱ��
	::SetTimer(this->m_hWnd, TIMER_GUNNER_MOVE_ID, TIMER_GUNNER_MOVE_FREQUENCY_MS, NULL);

	//�ڵ�����Ķ�ʱ��
	::SetTimer(this->m_hWnd, TIMER_GUNNER_SEND_ID, TIMER_GUNNER_SEND_FREQUENCY_MS, NULL);

	//�����о�С�ɻ��Ķ�ʱ��
	::SetTimer(this->m_hWnd, TIMER_SMALLFOE_CREATE_ID, TIMER_SMALLFOE_CREATE_FREQUENCY_MS, NULL);

	//�����о��зɻ��Ķ�ʱ��
	::SetTimer(this->m_hWnd, TIMER_MIDDLEFOE_CREATE_ID, TIMER_MIDDLEFOE_CREATE_FREQUENCY_MS, NULL);

	//�����о���ɻ��Ķ�ʱ��
	::SetTimer(this->m_hWnd, TIMER_BIGFOE_CREATE_ID, TIMER_BIGFOE_CREATE_FREQUENCY_MS, NULL);

	//�о��ɻ��ƶ��Ķ�ʱ��
	::SetTimer(this->m_hWnd, TIMER_FOEPLANE_MOVE_ID, TIMER_FOEPLANE_MOVE_FREQUENCY_MS, NULL);

	//�о��ɻ��Ƿ�ײ���Ķ�ʱ��
	::SetTimer(this->m_hWnd, TIMER_CHEAK_ISHIT_ID, TIMER_CHEAK_ISHIT_FREQUENCY_MS, NULL);

	//�л��ɻ���ըЧ���Ķ�ʱ��
	::SetTimer(this->m_hWnd, TIMER_BOOMPLANE_CHANGE_ID, TIMER_BOOMPLANE_FREQUENCY_MS, NULL);
}


void CPlaneApp::GameOver() {
	//ɱ�����ж�ʱ��
	::KillTimer(this->m_hWnd, TIMER_BACKGROUND_MOVE_ID);
	::KillTimer(this->m_hWnd, TIMER_PLAYERPLANE_MOVE_ID);
	::KillTimer(this->m_hWnd, TIMER_GUNNER_MOVE_ID);
	::KillTimer(this->m_hWnd, TIMER_GUNNER_SEND_ID);
	::KillTimer(this->m_hWnd, TIMER_SMALLFOE_CREATE_ID);
	::KillTimer(this->m_hWnd, TIMER_MIDDLEFOE_CREATE_ID);
	::KillTimer(this->m_hWnd, TIMER_BIGFOE_CREATE_ID);
	::KillTimer(this->m_hWnd, TIMER_FOEPLANE_MOVE_ID);
	::KillTimer(this->m_hWnd, TIMER_CHEAK_ISHIT_ID);
	::KillTimer(this->m_hWnd, TIMER_BOOMPLANE_CHANGE_ID);

	//��ʾ��Ϸ����
	::MessageBox(this->m_hWnd, "GameOver", "��ʾ", MB_OK);

	//���ͳ����˳���Ϣ
	PostMessage(this->m_hWnd, WM_DESTROY, 0, 0);
}