//
////应用程序实例 —— 正在运行的程序
////句柄——类似于指针，但区别在于无法修改句柄内容
//
////前一个应用实例 —— 通过一个应用程序A打开另一个应用程序B，则A为前一个应用实例
////前一个应用实例 VS 应用程序的子窗口 —— 关闭A，看B是否会被关闭，如果关闭则为子窗口
//
//
//#include <windows.h>
//
//LRESULT CALLBACK MYWNDPROC(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);//如何判断一个指针指向的类型：去掉一个*，再去掉变量名
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
//	//给二进制中的某一位赋值用或，判断有没有值用与
//	//CS_HREDRAW和CS_VREDRAW这些样式在计算机里的保存形式为每个样式的二进制数值中只有一个1，要是两个样式或起来，则0x00000001 | 0x00000010 就变成0x00000011,则程序把这个当成同时使用两个样式，这是微软固定的。
//	//0x00000011 & 0x00000001 结果为0x00000001所以样式应用了，0x00000011 & 0x00000000 结果为0x00000000所以样式没有应用
//	//注意区分|和||，&和&&的区别，前者为位运算，后者为逻辑运算
//	ex.cbSize = sizeof(ex);
//	ex.cbClsExtra = 0;
//	ex.cbWndExtra = 0;
//	ex.hInstance = hInstance;
//	ex.hIcon = NULL;
//	ex.hCursor = NULL;
//	ex.hbrBackground = CreateSolidBrush(RGB(0, 255, 0));
//	ex.hIconSm = NULL;
//	ex.lpfnWndProc = MYWNDPROC;
//	//消息处理函数(队列形式——先进先出)
//	ex.lpszMenuName = NULL;
//	//ex.lpszClassName = "aaa";
//		//报错，因为文件采用的是Unicode字符集而"aaa"是多字节字符集，在C中由于C是弱类型语言，所以可以使用，但C++中会出现问题，弱类型语言只要两种类型相近就不会认为是错误。c++则是强类型语言，会严格将两种类型区别开，只要类型不对就会报错。
//	//ex.lpszClassName = L"aaa";  
//		//通配符,但不一定好使，可以用另一种方式：“Kelin 5-7文件右键——属性——字符集：将Unicode字符集改为多字节”
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
//	//消息循环
//	while (GetMessage(&Msg, NULL, 0, 0))
//	{
//		//翻译消息
//		TranslateMessage(&Msg);
//		//分发消息
//		DispatchMessage(&Msg);
//	}
//
//	return 0;
//}
//
//LRESULT CALLBACK MYWNDPROC(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
//{
//	switch (message)
//	{
//	case WM_CLOSE:
//		PostQuitMessage(0);
//		break;
//	}
//	return DefWindowProc(hWnd, message, wParam, lParam);
//}
