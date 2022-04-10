//WinMain.cpp
// window 应用程序，多字符集
#include <windows.h>
#include <windowsx.h>
#include "Gameapp.h"

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
HINSTANCE hIns = 0;  //全局变量，程序实例句柄

int CALLBACK WinMain(HINSTANCE hInstance, HINSTANCE hPreInstance, LPSTR lpCmdLine, int nShowCmd)
{
	//-----------------------------------------------------
	HWND hwnd = 0;
	MSG msg;       //  装消息的结构体
	WNDCLASSEX wndclass;
	//-----------------------------------------------------

	hIns = hInstance;
	LPCSTR lClassName = "yue";				//窗口类名CN
	extern int nx;							//窗口位置X
	extern int ny;							//窗口位置Y
	extern int nwidth;						//窗口宽度W
	extern int nheigh;						//窗口高度H
	extern CHAR* strTitle;					//窗口标题名T
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

	//----------------------创建窗口过程-----------------------------------
	//  1. 设计
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
	// 2.  注册
	if (RegisterClassEx(&wndclass) == FALSE)
	{
		MessageBox(0, "注册失败", "提示", MB_OK);
		return 0;
	}
	//  3.  创建
	hwnd = CreateWindow(lClassName, strTitle, WS_OVERLAPPEDWINDOW, pos_x, pos_y, nWidth, nHeight, 0, 0, hInstance, 0);
	if (hwnd == 0)
	{
		MessageBox(0, "创建失败", "提示", MB_OK);
		return 0;
	}
	//  4.  显示窗口
	ShowWindow(hwnd, SW_SHOW);
	//---------------------------创建窗口过程-----------------------------------------

	//----------------------------消息循环-------------------------------------------
	while (GetMessage(&msg, 0, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	//----------------------------消息循环-------------------------------------------

	return 0;
}

CGameApp* pGameAPP = Get_Object();	//获取子类
const MessageEntry* MsgMap = pGameAPP->GetMessageMap();	//获取子类的消息映射表的首地址

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