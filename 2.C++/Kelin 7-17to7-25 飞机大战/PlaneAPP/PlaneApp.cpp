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
	//随机数种子
	srand((unsigned int)time(NULL));

	//创建定时器
	SetTimmer();

	//初始化背景
	m_back.InitBackGround(0, 0, this->m_hInstance);
	m_player.InitPlayerPlane((BACKGOUND_MAPSIZE_WIDTH - PALYERPLANE_SIZE_WIDTH) / 2, BACKGOUND_MAPSIZE_HEIGH - PALYERPLANE_SIZE_HEIGH, this->m_hInstance);

}//窗口创建消息

void CPlaneApp::OnPaint() {

	//获取窗口DC
	PAINTSTRUCT ps = { 0 };
	HDC hdc = ::BeginPaint(this->m_hWnd, &ps);

	//创建缓冲的兼容性DC和兼容性位图（缓存中间区~）
	HDC cacheDC = ::CreateCompatibleDC(hdc);
	HBITMAP cachemap = ::CreateCompatibleBitmap(hdc, BACKGOUND_MAPSIZE_WIDTH, BACKGOUND_MAPSIZE_HEIGH);
	::SelectObject(cacheDC, cachemap);

	//创建兼容性DC
	HDC compDC = ::CreateCompatibleDC(cacheDC);
	m_back.ShowBackGround(cacheDC, compDC);
	m_player.ShowPlayerPlane(cacheDC, compDC);
	m_gunbox.ShowAllGunner(cacheDC, compDC);
	m_foebox.ShowAllFoePlane(cacheDC, compDC);
	m_foebox.ShowBoomPlane(cacheDC, compDC);
	
	//闪烁问题实际是刷新率的问题，没有同时刷新，解决方式可以是把所有要贴的先贴到一个缓存中间区，然后再一次性贴到窗口dc上。（双缓冲）
	BitBlt(hdc, 0, 0, BACKGOUND_MAPSIZE_WIDTH, BACKGOUND_MAPSIZE_HEIGH, cacheDC, 0, 0, SRCCOPY);

	//删除释放DC
	DeleteDC(compDC);
	compDC = NULL;

	::DeleteObject(cachemap);
	cachemap = NULL;
	DeleteDC(cacheDC);
	cacheDC = NULL;

	::EndPaint(this->m_hWnd, &ps);

}//重绘消息

void CPlaneApp::OnGameRun(WPARAM wParam) {
	switch (wParam)
	{
	case TIMER_BACKGROUND_MOVE_ID:	//背景移动
		{
			m_back.MoveBackGround(4);
		}
		break;
	case TIMER_PLAYERPLANE_MOVE_ID:	//玩家飞机移动
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
	case TIMER_GUNNER_MOVE_ID:	//炮弹移动
		{
			m_gunbox.MoveAllGunner(GUNNER_MOVE_STEP);
		}
		break;
	case TIMER_GUNNER_SEND_ID:	//炮弹发射
		{
			CGunner* pGunner = m_player.SendGunner(this->m_hInstance);
			m_gunbox.m_lstGunner.push_back(pGunner);
		}
		break;
	case TIMER_SMALLFOE_CREATE_ID:	//创建敌军小飞机
		{
			CFoePlane* pFoe = new CFoePlaneSmall;
			pFoe->InitFoePlane(this->m_hInstance);
			//加到敌军飞机盒子里
			m_foebox.m_lstFoePlane.push_back(pFoe);
		}
		break;
	case TIMER_MIDDLEFOE_CREATE_ID:	//创建敌军中飞机
		{
			CFoePlane* pFoe = new CFoePlaneMid;
			pFoe->InitFoePlane(this->m_hInstance);
			//加到敌军飞机盒子里
			m_foebox.m_lstFoePlane.push_back(pFoe);
		}
		break;
	case TIMER_BIGFOE_CREATE_ID:	//创建敌军大飞机
		{
			CFoePlane* pFoe = new CFoePlaneBig;
			pFoe->InitFoePlane(this->m_hInstance);
			//加到敌军飞机盒子里
			m_foebox.m_lstFoePlane.push_back(pFoe);
		}
		break;
	case TIMER_FOEPLANE_MOVE_ID:	//敌军飞机移动
		{
			m_foebox.MoveAllFoePlane();
		}
		break;
	case TIMER_CHEAK_ISHIT_ID:	//敌军飞机是否撞击玩家飞机or炮弹
		{
			bool isBOOM = false;
			list<CFoePlane*>::iterator iteFoe = m_foebox.m_lstFoePlane.begin();
			while (iteFoe != m_foebox.m_lstFoePlane.end()) 
			{
				//遍历所有敌军飞机
				//判断是否撞击玩家飞机
				if ((*iteFoe)->IsHitPlayerPlane(m_player)) 
				{
					//撞击则游戏结束
					GameOver();
					return;
				}
				//判断是否撞击炮弹
				list<CGunner*>::iterator iteGun = m_gunbox.m_lstGunner.begin();
				while (iteGun != m_gunbox.m_lstGunner.end())	//遍历所有炮弹 
				{
					if ((*iteFoe)->IsHitGunner((*iteGun))) //判断敌军飞机是否撞击到了炮弹
					{
						{
							//撞击需要删除炮弹
							iteGun = m_gunbox.m_lstGunner.erase(iteGun);
							//因为erase的返回值是下一个，等同于已经++了，所以利用break和continue
							//敌军飞机血量减少
							(*iteFoe)->m_nBlood -= GUNNER_HURT_BLOOD;
							//判断血量是否为0，为0则显示爆炸
							if ((*iteFoe)->m_nBlood <= 0) {
								isBOOM = true;
								//移动敌军飞机（从正常链表移动到爆炸链表）
								m_foebox.m_lstBoomFoe.push_back(*iteFoe);
								//删除正常链表里已经移动完的敌军飞机
								iteFoe = m_foebox.m_lstFoePlane.erase(iteFoe);
								//因为erase的返回值是下一个，等同于已经++了，所以利用isBOOM作为标记值							break;
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
	case TIMER_BOOMPLANE_CHANGE_ID:	//敌军飞机爆炸效果切换
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

}//定时器，需要在子类中手动添加定时器并设置触发间隔

//void CPlaneApp::OnKeyDown(WPARAM wParam) {
//	
//	//m_player.MovePlayerPlane(wParam, PLAYERPLANE_MOVE_STEP);
//
//}//键盘按下触发消息

void CPlaneApp::SetTimmer() {

	//设置背景移动的定时器
	::SetTimer(this->m_hWnd, TIMER_BACKGROUND_MOVE_ID, TIMER_BACKGROUND_MOVE_FREQUENCY_MS, NULL);

	//设置监测键盘是否按下的定时器(玩家飞机移动)
	::SetTimer(this->m_hWnd, TIMER_PLAYERPLANE_MOVE_ID, TIMER_PLAYERPLANE_MOVE_FREQUENCY_MS, NULL);

	//炮弹移动的定时器
	::SetTimer(this->m_hWnd, TIMER_GUNNER_MOVE_ID, TIMER_GUNNER_MOVE_FREQUENCY_MS, NULL);

	//炮弹发射的定时器
	::SetTimer(this->m_hWnd, TIMER_GUNNER_SEND_ID, TIMER_GUNNER_SEND_FREQUENCY_MS, NULL);

	//创建敌军小飞机的定时器
	::SetTimer(this->m_hWnd, TIMER_SMALLFOE_CREATE_ID, TIMER_SMALLFOE_CREATE_FREQUENCY_MS, NULL);

	//创建敌军中飞机的定时器
	::SetTimer(this->m_hWnd, TIMER_MIDDLEFOE_CREATE_ID, TIMER_MIDDLEFOE_CREATE_FREQUENCY_MS, NULL);

	//创建敌军大飞机的定时器
	::SetTimer(this->m_hWnd, TIMER_BIGFOE_CREATE_ID, TIMER_BIGFOE_CREATE_FREQUENCY_MS, NULL);

	//敌军飞机移动的定时器
	::SetTimer(this->m_hWnd, TIMER_FOEPLANE_MOVE_ID, TIMER_FOEPLANE_MOVE_FREQUENCY_MS, NULL);

	//敌军飞机是否撞击的定时器
	::SetTimer(this->m_hWnd, TIMER_CHEAK_ISHIT_ID, TIMER_CHEAK_ISHIT_FREQUENCY_MS, NULL);

	//切换飞机爆炸效果的定时器
	::SetTimer(this->m_hWnd, TIMER_BOOMPLANE_CHANGE_ID, TIMER_BOOMPLANE_FREQUENCY_MS, NULL);
}


void CPlaneApp::GameOver() {
	//杀死所有定时器
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

	//提示游戏结束
	::MessageBox(this->m_hWnd, "GameOver", "提示", MB_OK);

	//发送程序退出消息
	PostMessage(this->m_hWnd, WM_DESTROY, 0, 0);
}