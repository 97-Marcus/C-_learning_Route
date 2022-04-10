#pragma once
#include <windows.h>

class CGameApp {
public:
	HINSTANCE m_hInstance;
	HWND m_hWnd;
public:
	CGameApp() {}
	virtual ~CGameApp() {}
public:
	void SetHandle(HINSTANCE hIns, HWND hWnd) {
		m_hInstance = hIns;
		m_hWnd = hWnd;
	}
public:
	virtual void OnCreate() {}//窗口创建消息
	virtual void OnPaint() {}//重绘消息
	virtual void OnGameRun(WPARAM wParam) {}//定时器，需要在子类中手动添加定时器并设置触发间隔
	virtual void OnKeyDown(WPARAM wParam) {}//键盘按下触发消息
	virtual void OnKeyUp(WPARAM wParam) {}//键盘抬起触发消息
	virtual void OnLbuttonDown(POINT& po) {}//鼠标左键按下触发消息
	virtual void OnLbuttonUp(POINT& po) {}//鼠标左键抬起触发消息
	virtual void OnMouseMove(POINT& po) {}//鼠标移动
};

CGameApp* Get_Object();

#define GET_OBJECT(CHILD_CLASS)\
	CGameApp* Get_Object() {\
		return new CHILD_CLASS;\
	}

#define CLASS_CONFIG(PARAM_X,PARAM_Y,PARAM_WIDTH,PARAM_HEIGH,PARAM_TITLE)\
	int nx = PARAM_X;\
	int ny = PARAM_Y;\
	int nwidth = PARAM_WIDTH;\
	int nheigh = PARAM_HEIGH;\
	CHAR* strTitle = (CHAR*)PARAM_TITLE;