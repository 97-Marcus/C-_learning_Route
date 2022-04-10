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

	//1.设计窗口（最复杂）
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

	//2.注册窗口
	RegisterClassEx(&ex);

	//3.创建窗口
	hWnd = CreateWindow(ex.lpszClassName, "原谅绿", WS_OVERLAPPEDWINDOW, 50, 50, 500, 500, NULL, NULL, hInstance, NULL);

	//4.显示窗口
	ShowWindow(hWnd, SW_SHOW);

	//定时器须在创建窗口之后，消息循环之前
	SetTimer(hWnd, 1, 500, NULL);
	SetTimer(hWnd, 2, 1000, NULL);

	//消息循环
	while (GetMessage(&Msg, NULL, 0, 0))
	{
		TranslateMessage(&Msg);
		DispatchMessage(&Msg);
	}

	return 0;
}

//要求：两矩形以不同速度平移，当键盘按下A时快的矩形停止平移，B时另一个矩形停止平移。

LRESULT CALLBACK MYWNDPROC(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	static int x1 = 50, x2 = 50;
	HDC hDc;
	PAINTSTRUCT pS;
	switch (message)
	{
	case WM_PAINT:	//重绘消息
		hDc = BeginPaint(hWnd, &pS);
		Rectangle(hDc, x1, 100, x1 + 50, 150);
		Rectangle(hDc, x2, 200, x2 + 50, 250);
		EndPaint(hWnd, &pS);
		break;
	case WM_KEYDOWN:
		if (65 == wParam) 
		{
			KillTimer(hWnd, 1);//杀死定时器1
		}
		if (66 == wParam) 
		{
			KillTimer(hWnd, 2);//杀死定时器2
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

//现象：只有第二个矩形显现，断点调试可以发现，每次ruturn回去时，x1和x2的值均会重新变成50。
//原因：MYWNDPROC是头文件写好的死循环函数，因此每次循环进消息处理函数都将定义x1=50，而上一次的x1=50+5=55，作为局部变量在上一个循环函数结束时已经被回收。
//处理方式，将int x1前加上一个static（静态修饰符），static变量能保持上次调用后的结果，int在函数返回后就销毁了，下次调用又重新建立。