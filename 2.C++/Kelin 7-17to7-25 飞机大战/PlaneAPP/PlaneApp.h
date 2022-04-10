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
	virtual void OnCreate();//���ڴ�����Ϣ
	virtual void OnPaint();//�ػ���Ϣ
	virtual void OnGameRun(WPARAM wParam);//��ʱ������Ҫ���������ֶ���Ӷ�ʱ�������ô������
	//virtual void OnKeyDown(WPARAM wParam);//���̰��´�����Ϣ
public:
	void SetTimmer();
	void GameOver();
};