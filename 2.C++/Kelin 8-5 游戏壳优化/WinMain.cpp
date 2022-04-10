//WinMain.cpp
// window Ӧ�ó��򣬶��ַ���
#include <windows.h>
#include <windowsx.h>
#include "Gameapp.h"

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
HINSTANCE hIns = 0;  //ȫ�ֱ���������ʵ�����

int CALLBACK WinMain(HINSTANCE hInstance, HINSTANCE hPreInstance, LPSTR lpCmdLine, int nShowCmd)
{
	//-----------------------------------------------------
	HWND hwnd = 0;
	MSG msg;       //  װ��Ϣ�Ľṹ��
	WNDCLASSEX wndclass;
	//-----------------------------------------------------

	hIns = hInstance;
	LPCSTR lClassName = "yue";				//��������CN
	extern int nx;							//����λ��X
	extern int ny;							//����λ��Y
	extern int nwidth;						//���ڿ��W
	extern int nheigh;						//���ڸ߶�H
	extern CHAR* strTitle;					//���ڱ�����T
	int pos_x = nx;
	if (pos_x < 0) {
		pos_x = 0;
	}
	int pos_y = ny;
	if (pos_y < 0) {
		pos_y = 0;
	}
	int nWidth = nwidth;
	if (nWidth <= 0) {
		nWidth = 500;
	}
	int nHeight = nheigh;
	if (nHeight <= 0) {
		nHeight = 500;
	}

	//----------------------�������ڹ���-----------------------------------
	//  1. ���
	wndclass.cbClsExtra = 0;
	wndclass.cbWndExtra = 0;
	wndclass.cbSize = sizeof(wndclass);
	wndclass.hbrBackground = (HBRUSH)COLOR_WINDOW;
	wndclass.hCursor = LoadCursor(0, MAKEINTRESOURCE(IDC_ARROW));
	wndclass.hIcon = 0;
	wndclass.hIconSm = 0;
	wndclass.hInstance = hInstance;
	wndclass.lpfnWndProc = WindowProc;
	wndclass.lpszClassName = lClassName;
	wndclass.lpszMenuName = 0;
	wndclass.style = CS_HREDRAW | CS_VREDRAW;
	// 2.  ע��
	if (RegisterClassEx(&wndclass) == FALSE)
	{
		MessageBox(0, "ע��ʧ��", "��ʾ", MB_OK);
		return 0;
	}
	//  3.  ����
	hwnd = CreateWindow(lClassName, strTitle, WS_OVERLAPPEDWINDOW, pos_x, pos_y, nWidth, nHeight, 0, 0, hInstance, 0);
	if (hwnd == 0)
	{
		MessageBox(0, "����ʧ��", "��ʾ", MB_OK);
		return 0;
	}
	//  4.  ��ʾ����
	ShowWindow(hwnd, SW_SHOW);
	//---------------------------�������ڹ���-----------------------------------------

	//----------------------------��Ϣѭ��-------------------------------------------
	while (GetMessage(&msg, 0, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	//----------------------------��Ϣѭ��-------------------------------------------

	return 0;
}

CGameApp* pGameAPP = Get_Object();	//��ȡ����
const MessageEntry* MsgMap = pGameAPP->GetMessageMap();	//��ȡ�������Ϣӳ�����׵�ַ

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	const MessageEntry* p = MsgMap;
	while (p && p->MessageID != 0) 
	{
		if (p->MessageID == uMsg) 
		{
			(pGameAPP->*(p->p_Fun))();
			break;
		}
		p++;
	}
	return DefWindowProc(hwnd, uMsg, wParam, lParam);
}