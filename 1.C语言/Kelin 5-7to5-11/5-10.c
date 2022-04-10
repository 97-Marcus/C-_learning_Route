//#include <windows.h>
//#include <stdio.h>
//
//LRESULT CALLBACK MYWNDPROC(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
//
//int CALLBACK WinMain(HINSTANCE hInstance,
//	HINSTANCE hPrevlnstance,
//	LPSTR lpCmdLine,
//	int nCmdShow)
//{
//	WNDCLASSEX ex;
//	HWND hWnd;
//	MSG Msg;
//
//	//1.设计窗口（最复杂）
//	ex.style = CS_HREDRAW | CS_VREDRAW;
//	ex.cbSize = sizeof(ex);
//	ex.cbClsExtra = 0;
//	ex.cbWndExtra = 0;
//	ex.hInstance = hInstance;
//	ex.hIcon = NULL;
//	ex.hCursor = NULL;
//	ex.hbrBackground = CreateSolidBrush(RGB(0, 255, 0));
//	ex.hIconSm = NULL;
//	ex.lpfnWndProc = MYWNDPROC;
//	ex.lpszMenuName = NULL;
//	ex.lpszClassName = "aaa";
//
//	//2.注册窗口
//	RegisterClassEx(&ex);
//
//	//3.创建窗口
//	hWnd = CreateWindow(ex.lpszClassName, "原谅绿", WS_OVERLAPPEDWINDOW, 50, 50, 500, 500, NULL, NULL, hInstance, NULL);
//
//	//4.显示窗口
//	ShowWindow(hWnd, SW_SHOW);
//
//	//定时器须在创建窗口之后，消息循环之前
//	SetTimer(hWnd, 1, 500, NULL);
//
//	//消息循环
//	while (GetMessage(&Msg, NULL, 0, 0))
//	{
//		TranslateMessage(&Msg);
//		DispatchMessage(&Msg);
//	}
//
//	return 0;
//}
//
//LRESULT CALLBACK MYWNDPROC(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
//{
//	int x, y;
//	char str[20] = {0};
//	HDC hDc;
//	PAINTSTRUCT pS;
//	HBRUSH hBrush;
//
//	switch (message)
//	{
//	case WM_CLOSE:
//		PostQuitMessage(0);
//		break;
//	//case WM_KEYDOWN:
//	//	if (65 == wParam)
//	//	{
//	//		MessageBox(hWnd, "要想生活过得去 头上总得有点绿", "忍者神龟", MB_OK);
//	//	}
//	//	//当键盘按下A的时候弹出一个对话框
//	//	break;
//	case WM_KEYDOWN:
//		//要求：当键盘按下的时候画一个圆
//	    //只有在重绘消息中用beginPaint和endPaint，其余消息中都直接用getDC和releaseDC即可
//		hDc = GetDC(hWnd);
//		hBrush = CreateSolidBrush(RGB(255, 0, 0));//创建了红色的画刷
//		SelectObject(hDc, hBrush);//关联两个设备（画刷和hDc关联 达到上色目的）,其返回值为关联前的同一类型设备，比如现在其返回值为默认的白色的画刷而不关联的红色画刷，若有需要可以用一个变量来记录
//		Ellipse(hDc, 120, 120, 180, 180);
//		ReleaseDC(hWnd,hDc);
//		break;
//	/*
//	case WM_LBUTTONDOWN:
//		x = LOWORD(lParam);
//		y = HIWORD(lParam);//取坐标
//		//sprintf(str, "%d,%d", x, y);//不安全
//		sprintf_s(str,20,"%d,%d",x,y);//格式化写入
//		MessageBox(hWnd, str, "提示", MB_OK);
//		//点击鼠标后将提示鼠标的坐标位置
//		
//		//MessageBox(hWnd, "要想生活过得去 头上总得有点绿", "忍者神龟", MB_OK);
//		////当鼠标左键按下的时候弹出一个对话框
//		break;
//	*/
//		//要求：鼠标点击位置花一个直径为50*50的圆，鼠标点击位置为圆心
//	case WM_LBUTTONDOWN:
//		x = LOWORD(lParam);
//		y = HIWORD(lParam);//取坐标
//		hDc = GetDC(hWnd);
//		Ellipse(hDc, x - 25, y - 25, x + 25, y + 25);
//		ReleaseDC(hWnd, hDc);
//	break;
//	case WM_PAINT:	//重绘消息
//		hDc = BeginPaint(hWnd, &pS);//用完hDc后需要归还，否则别的消息无法获取
//		Rectangle(hDc, 100, 100, 250, 200);//窗口出来的时候就有一个矩形
//		EndPaint(hWnd, &pS);//归还
//		break;
//	case WM_TIMER:
//		MessageBox(hWnd, "你是不是傻", "服不服", MB_OK);
//	}
//	//该程序采用了水平刷新和竖直刷新，当窗口发生变化的时候（最大最小化等任意窗口大小拉伸改变），会触发重绘消息，因此在本程序中，点击生成的圆在窗口改变后会消失，如果只采用水平刷新，那么竖直拉动窗口发生变化时不会触发重绘消息，圆不会消失，只有水平变化时才会消失。
//	return DefWindowProc(hWnd, message, wParam, lParam);
//}
