#pragma once

#include "../GameFrame/Gameapp.h"
#include "../BackGround/BackGround.h"
#include "../PlayerPlane/PlayerPlane.h"
#include "../GunnerBox/GunnerBox.h"
#include "../FoePlaneBox/FoePlaneBox.h"

class CPlaneApp :public CGameApp
{
public:
	CBackGround m_back;
	CGunnerBox m_gunbox;
	CPlayerPlane m_player;
	CFoePlaneBox m_foebox;
public:
	CPlaneApp();
	~CPlaneApp();
public:
	virtual void OnCreate();//窗口创建消息
	virtual void OnPaint();//重绘消息
	virtual void OnGameRun(WPARAM wParam);//定时器，需要在子类中手动添加定时器并设置触发间隔
	//virtual void OnKeyDown(WPARAM wParam);//键盘按下触发消息
public:
	void SetTimmer();
	void GameOver();
};