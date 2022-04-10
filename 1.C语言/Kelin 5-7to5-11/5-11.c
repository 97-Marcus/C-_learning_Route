#include <windows.h>
#include <stdio.h>

LRESULT CALLBACK MYWNDPROC(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

int CALLBACK WinMain(HINSTANCE hInstance,
	HINSTANCE hPrevlnstance,
	LPSTR lpCmdLine,
	int nCmdShow)
{
	WNDCLASSEX ex;
	HWND hWnd;
	MSG Msg;

	//1.��ƴ��ڣ���ӣ�
	ex.style = CS_HREDRAW | CS_VREDRAW;
	ex.cbSize = sizeof(ex);
	ex.cbClsExtra = 0;
	ex.cbWndExtra = 0;
	ex.hInstance = hInstance;
	ex.hIcon = NULL;
	ex.hCursor = NULL;
	ex.hbrBackground = CreateSolidBrush(RGB(0, 255, 0));
	ex.hIconSm = NULL;
	ex.lpfnWndProc = MYWNDPROC;
	ex.lpszMenuName = NULL;
	ex.lpszClassName = "aaa";

	//2.ע�ᴰ��
	RegisterClassEx(&ex);

	//3.��������
	hWnd = CreateWindow(ex.lpszClassName, "ԭ����", WS_OVERLAPPEDWINDOW, 50, 50, 500, 500, NULL, NULL, hInstance, NULL);

	//4.��ʾ����
	ShowWindow(hWnd, SW_SHOW);

	//��ʱ�����ڴ�������֮����Ϣѭ��֮ǰ
	SetTimer(hWnd, 1, 500, NULL);
	SetTimer(hWnd, 2, 1000, NULL);

	//��Ϣѭ��
	while (GetMessage(&Msg, NULL, 0, 0))
	{
		TranslateMessage(&Msg);
		DispatchMessage(&Msg);
	}

	return 0;
}

//Ҫ���������Բ�ͬ�ٶ�ƽ�ƣ������̰���Aʱ��ľ���ֹͣƽ�ƣ�Bʱ��һ������ֹͣƽ�ơ�

LRESULT CALLBACK MYWNDPROC(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	static int x1 = 50, x2 = 50;
	HDC hDc;
	PAINTSTRUCT pS;
	switch (message)
	{
	case WM_PAINT:	//�ػ���Ϣ
		hDc = BeginPaint(hWnd, &pS);
		Rectangle(hDc, x1, 100, x1 + 50, 150);
		Rectangle(hDc, x2, 200, x2 + 50, 250);
		EndPaint(hWnd, &pS);
		break;
	case WM_KEYDOWN:
		if (65 == wParam) 
		{
			KillTimer(hWnd, 1);//ɱ����ʱ��1
		}
		if (66 == wParam) 
		{
			KillTimer(hWnd, 2);//ɱ����ʱ��2
		}
		break;
	case WM_TIMER:
		hDc = GetDC(hWnd);
		if (1 == wParam) 
		{
			x1 += 5;
			Rectangle(hDc, x1, 100, x1 + 50, 150);
		}
		if (2 == wParam) 
		{
			x2 += 5;
			Rectangle(hDc, x2, 200, x2 + 50, 250);
		}
		ReleaseDC(hWnd, hDc);
		break;
	}

	return DefWindowProc(hWnd, message, wParam, lParam);
}

//����ֻ�еڶ����������֣��ϵ���Կ��Է��֣�ÿ��ruturn��ȥʱ��x1��x2��ֵ�������±��50��
//ԭ��MYWNDPROC��ͷ�ļ�д�õ���ѭ�����������ÿ��ѭ������Ϣ��������������x1=50������һ�ε�x1=50+5=55����Ϊ�ֲ���������һ��ѭ����������ʱ�Ѿ������ա�
//����ʽ����int x1ǰ����һ��static����̬���η�����static�����ܱ����ϴε��ú�Ľ����int�ں������غ�������ˣ��´ε��������½�����