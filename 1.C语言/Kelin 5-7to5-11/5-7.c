//
////Ӧ�ó���ʵ�� ���� �������еĳ���
////�������������ָ�룬�����������޷��޸ľ������
//
////ǰһ��Ӧ��ʵ�� ���� ͨ��һ��Ӧ�ó���A����һ��Ӧ�ó���B����AΪǰһ��Ӧ��ʵ��
////ǰһ��Ӧ��ʵ�� VS Ӧ�ó�����Ӵ��� ���� �ر�A����B�Ƿ�ᱻ�رգ�����ر���Ϊ�Ӵ���
//
//
//#include <windows.h>
//
//LRESULT CALLBACK MYWNDPROC(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);//����ж�һ��ָ��ָ������ͣ�ȥ��һ��*����ȥ��������
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
//	//���������е�ĳһλ��ֵ�û��ж���û��ֵ����
//	//CS_HREDRAW��CS_VREDRAW��Щ��ʽ�ڼ������ı�����ʽΪÿ����ʽ�Ķ�������ֵ��ֻ��һ��1��Ҫ��������ʽ����������0x00000001 | 0x00000010 �ͱ��0x00000011,�������������ͬʱʹ��������ʽ������΢��̶��ġ�
//	//0x00000011 & 0x00000001 ���Ϊ0x00000001������ʽӦ���ˣ�0x00000011 & 0x00000000 ���Ϊ0x00000000������ʽû��Ӧ��
//	//ע������|��||��&��&&������ǰ��Ϊλ���㣬����Ϊ�߼�����
//	ex.cbSize = sizeof(ex);
//	ex.cbClsExtra = 0;
//	ex.cbWndExtra = 0;
//	ex.hInstance = hInstance;
//	ex.hIcon = NULL;
//	ex.hCursor = NULL;
//	ex.hbrBackground = CreateSolidBrush(RGB(0, 255, 0));
//	ex.hIconSm = NULL;
//	ex.lpfnWndProc = MYWNDPROC;
//	//��Ϣ������(������ʽ�����Ƚ��ȳ�)
//	ex.lpszMenuName = NULL;
//	//ex.lpszClassName = "aaa";
//		//������Ϊ�ļ����õ���Unicode�ַ�����"aaa"�Ƕ��ֽ��ַ�������C������C�����������ԣ����Կ���ʹ�ã���C++�л�������⣬����������ֻҪ������������Ͳ�����Ϊ�Ǵ���c++����ǿ�������ԣ����ϸ������������𿪣�ֻҪ���Ͳ��Ծͻᱨ��
//	//ex.lpszClassName = L"aaa";  
//		//ͨ���,����һ����ʹ����������һ�ַ�ʽ����Kelin 5-7�ļ��Ҽ��������ԡ����ַ�������Unicode�ַ�����Ϊ���ֽڡ�
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
//	//��Ϣѭ��
//	while (GetMessage(&Msg, NULL, 0, 0))
//	{
//		//������Ϣ
//		TranslateMessage(&Msg);
//		//�ַ���Ϣ
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
