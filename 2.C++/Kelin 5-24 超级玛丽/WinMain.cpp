//WinMain.cpp
// window Ӧ�ó��򣬶��ַ���
#include<windows.h>
#include "Mali.h"

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
	LPCSTR lClassName = "yue"; //��������
	int nx = 0;                  //����λ��X
	int ny = 0;                  //����λ��Y
	int nwidth = 0;              //���ڿ��
	int nheigh = 0;              //���ڸ߶�
	const CHAR* strTitle = "yue";         //���ڱ�����
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
	//---------------------------�������ڹ���------------------------------------------------

	//----------------------------��Ϣѭ��-------------------------------------------
	while (GetMessage(&msg, 0, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	//----------------------------��Ϣѭ��-------------------------------------------

	return 0;
}

CMali* pMali = NULL;

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
	case WM_CREATE: //���ڴ�����Ϣ
	{
		if (pMali == NULL) {
			pMali = new CMali;
			pMali->InitPeople(hIns);
		}
	}
	break;
	case WM_PAINT:  //�ػ���Ϣ
	{
		PAINTSTRUCT ps = { 0 };
		HDC hdc = ::BeginPaint(hwnd, &ps);
		//������������������������������������������������������������������������������������
		if (pMali != NULL) 
		{
			pMali->ShowPeople(hdc);
		}
		//������������������������������������������������������������������������������������
		::EndPaint(hwnd, &ps);
	}
	break;
	//case WM_TIMER:   //��ʱ������Ҫ�������������ֶ���Ӷ�ʱ�������ô������
	//{

	//}
	//break;
	case WM_KEYDOWN:  //���̰��´�����Ϣ
	{
		if (pMali != NULL)
		{
			pMali->MovePeople(wParam);
		}
		RECT rect = { 0,0,500,500 };//�������ڶ���Ҫˢ�£����Դ�С����������
		::InvalidateRect(hwnd,&rect,TRUE);//��Ч����ˢ�´��ڣ�
										  //FALSE�����¹켣����������һλ�õ�λͼ  TRUE�ƶ��������һλ��
	}
	break;
	//case WM_KEYUP:  //����̧�𴥷���Ϣ
	//{

	//}
	//break;
	//case WM_LBUTTONDOWN: //���������´�����Ϣ
	//{

	//}
	//break;
	//case WM_LBUTTONUP: //������̧�𴥷���Ϣ
	//{

	//}
	//break;
	//case WM_MOUSEMOVE:  //����ƶ�
	//{

	//}
	//break;
	case WM_CLOSE:
	{
		int res = ::MessageBox(NULL, "[WM_CLOSE] �Ƿ�ȷ���˳�", "��ʾ", MB_OKCANCEL);
		if (res == IDOK) { //��� ��ȷ������ť

		}
		else if (res == IDCANCEL) {//�����ȡ������ť��������Ĭ�ϵ���Ϣ���� DefWindowProc 

			return 0;
		}
		else {
			return 0;
		}
	}
	break;
	case WM_DESTROY:
	{
		//::MessageBox(NULL, "WM_DESTROY", "��ʾ", MB_OK);
		//�ͷ���Ϸ��Դ
		if (pMali) 
		{
			delete pMali;
			pMali = NULL;
		}
		PostQuitMessage(0);
	}
	break;
	case WM_QUIT:
	{
		::MessageBox(NULL, "WM_QUIT", "��ʾ", MB_OK);
	}
	break;
	}
	return DefWindowProc(hwnd, uMsg, wParam, lParam);

}