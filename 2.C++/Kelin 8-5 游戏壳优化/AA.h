#pragma once
#include"GameApp.h"

#define WM_AAA (WM_USER+1)		
		//�Զ�����Ϣ��Ҫ��(WM_USER+1)��ʼ����Ҫ��ϵͳ�ĳ�ͻ

class CAA :public CGameApp
{
public:
	CAA(void);
	~CAA(void);
public:
	void OnCreate();
	void OnPaint();
	void OnAAA();
public:
	virtual const MessageEntry* GetMessageMap();
};

