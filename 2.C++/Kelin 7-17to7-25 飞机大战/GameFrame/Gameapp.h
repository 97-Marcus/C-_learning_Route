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
	virtual void OnCreate() {}//���ڴ�����Ϣ
	virtual void OnPaint() {}//�ػ���Ϣ
	virtual void OnGameRun(WPARAM wParam) {}//��ʱ������Ҫ���������ֶ���Ӷ�ʱ�������ô������
	virtual void OnKeyDown(WPARAM wParam) {}//���̰��´�����Ϣ
	virtual void OnKeyUp(WPARAM wParam) {}//����̧�𴥷���Ϣ
	virtual void OnLbuttonDown(POINT& po) {}//���������´�����Ϣ
	virtual void OnLbuttonUp(POINT& po) {}//������̧�𴥷���Ϣ
	virtual void OnMouseMove(POINT& po) {}//����ƶ�
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