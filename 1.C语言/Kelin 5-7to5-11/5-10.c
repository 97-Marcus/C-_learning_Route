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
//	//1.��ƴ��ڣ���ӣ�
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
//	//2.ע�ᴰ��
//	RegisterClassEx(&ex);
//
//	//3.��������
//	hWnd = CreateWindow(ex.lpszClassName, "ԭ����", WS_OVERLAPPEDWINDOW, 50, 50, 500, 500, NULL, NULL, hInstance, NULL);
//
//	//4.��ʾ����
//	ShowWindow(hWnd, SW_SHOW);
//
//	//��ʱ�����ڴ�������֮����Ϣѭ��֮ǰ
//	SetTimer(hWnd, 1, 500, NULL);
//
//	//��Ϣѭ��
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
//	//		MessageBox(hWnd, "Ҫ���������ȥ ͷ���ܵ��е���", "�������", MB_OK);
//	//	}
//	//	//�����̰���A��ʱ�򵯳�һ���Ի���
//	//	break;
//	case WM_KEYDOWN:
//		//Ҫ�󣺵����̰��µ�ʱ��һ��Բ
//	    //ֻ�����ػ���Ϣ����beginPaint��endPaint��������Ϣ�ж�ֱ����getDC��releaseDC����
//		hDc = GetDC(hWnd);
//		hBrush = CreateSolidBrush(RGB(255, 0, 0));//�����˺�ɫ�Ļ�ˢ
//		SelectObject(hDc, hBrush);//���������豸����ˢ��hDc���� �ﵽ��ɫĿ�ģ�,�䷵��ֵΪ����ǰ��ͬһ�����豸�����������䷵��ֵΪĬ�ϵİ�ɫ�Ļ�ˢ���������ĺ�ɫ��ˢ��������Ҫ������һ����������¼
//		Ellipse(hDc, 120, 120, 180, 180);
//		ReleaseDC(hWnd,hDc);
//		break;
//	/*
//	case WM_LBUTTONDOWN:
//		x = LOWORD(lParam);
//		y = HIWORD(lParam);//ȡ����
//		//sprintf(str, "%d,%d", x, y);//����ȫ
//		sprintf_s(str,20,"%d,%d",x,y);//��ʽ��д��
//		MessageBox(hWnd, str, "��ʾ", MB_OK);
//		//���������ʾ��������λ��
//		
//		//MessageBox(hWnd, "Ҫ���������ȥ ͷ���ܵ��е���", "�������", MB_OK);
//		////�����������µ�ʱ�򵯳�һ���Ի���
//		break;
//	*/
//		//Ҫ�������λ�û�һ��ֱ��Ϊ50*50��Բ�������λ��ΪԲ��
//	case WM_LBUTTONDOWN:
//		x = LOWORD(lParam);
//		y = HIWORD(lParam);//ȡ����
//		hDc = GetDC(hWnd);
//		Ellipse(hDc, x - 25, y - 25, x + 25, y + 25);
//		ReleaseDC(hWnd, hDc);
//	break;
//	case WM_PAINT:	//�ػ���Ϣ
//		hDc = BeginPaint(hWnd, &pS);//����hDc����Ҫ�黹����������Ϣ�޷���ȡ
//		Rectangle(hDc, 100, 100, 250, 200);//���ڳ�����ʱ�����һ������
//		EndPaint(hWnd, &pS);//�黹
//		break;
//	case WM_TIMER:
//		MessageBox(hWnd, "���ǲ���ɵ", "������", MB_OK);
//	}
//	//�ó��������ˮƽˢ�º���ֱˢ�£������ڷ����仯��ʱ�������С�������ⴰ�ڴ�С����ı䣩���ᴥ���ػ���Ϣ������ڱ������У�������ɵ�Բ�ڴ��ڸı�����ʧ�����ֻ����ˮƽˢ�£���ô��ֱ�������ڷ����仯ʱ���ᴥ���ػ���Ϣ��Բ������ʧ��ֻ��ˮƽ�仯ʱ�Ż���ʧ��
//	return DefWindowProc(hWnd, message, wParam, lParam);
//}
