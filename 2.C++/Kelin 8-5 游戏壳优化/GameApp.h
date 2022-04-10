#pragma once
#include <windows.h>

class CGameApp;		//��������

typedef void(CGameApp::* P_FUN) ();

//����һ����Ϣӳ��ṹ
struct MessageEntry {
	int MessageID;	//��ϢID
	P_FUN p_Fun;	//���Ա����ָ��
};

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
	//��ȡ�������Ϣӳ���
	virtual const MessageEntry* GetMessageMap() = 0;
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