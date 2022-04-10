#pragma once
#include"GameApp.h"

#define WM_AAA (WM_USER+1)		
		//自定义消息需要从(WM_USER+1)开始，不要和系统的冲突

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

