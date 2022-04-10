#include <windows.h>
#include <stdio.h>
#include <time.h>
#include "resource.h"

LRESULT CALLBACK MYWNDPROC(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

//����λͼ���
HBITMAP hBitmap_Background;
HBITMAP hBitmap_Apple;
HBITMAP hBitmap_SnakeBody;
HBITMAP hBitmap_SnakeHead_Up;
HBITMAP hBitmap_SnakeHead_Down;
HBITMAP hBitmap_SnakeHead_Left;
HBITMAP hBitmap_SnakeHead_Right;

typedef struct Node 
{
	int x;
	int y;
	struct Node* pNext;
	struct Node* pLast;
}Snake;

typedef struct Node1
{
	int x;
	int y;
}Apple;

enum FX { UP, DOWN, LEFT, RIGHT };
enum FX fx = UP;

Snake* pHead = NULL;
Snake* pTail = NULL;

Apple apple = { 5, 5 };

void AddNote(int x, int y);
void ShowSnake(HDC hDc);
void Move();
void ShowBackground(HDC hDc);
void ShowApple(HDC hdc);
BOOL IsEatApple();
void NewApple();
BOOL IsBumpWall();
BOOL IsEatItself();

BOOL bFlag = TRUE;
//BUG:��һ����ʱ�������ڿ��ٸı����η������ٷ��򣬱����������ᷢ����ͷ��ҧ����
//���������Լ������һ����ʱ��������ֻ�ܸı�һ�η�������һ����ǣ�����һ���������Ѿ��ı�����ʸı�,�ڶ�ʱ����Ϣ�ͼ�����Ϣ���ñ�ǽ������ơ�

int CALLBACK WinMain(HINSTANCE hInstance,
					 HINSTANCE hPrevlnstance,
					 LPSTR lpCmdLine,
					 int nCmdShow)
{
	WNDCLASSEX ex;
	HWND hWnd;
	MSG Msg;

	//����λͼ
	hBitmap_Background = LoadBitmap(hInstance, MAKEINTRESOURCE(IDB_BITMAP1));//LoadBitmap(��ǰӦ��ʵ�����, λͼ·��)��λͼ·���ڵ���ͼƬʱ�Ѿ��Զ��궨���ˣ�����MAKEINTRESOURCE�������ɵõ�·��
	//����ʧ��ʱ�᷵��NULL�����¶ϵ�鿴hBitmap_Background��ֵ���ж��Ƿ���سɹ�
	hBitmap_Apple = LoadBitmap(hInstance, MAKEINTRESOURCE(IDB_BITMAP2));
	hBitmap_SnakeBody = LoadBitmap(hInstance, MAKEINTRESOURCE(IDB_BITMAP3));
	hBitmap_SnakeHead_Up = LoadBitmap(hInstance, MAKEINTRESOURCE(IDB_BITMAP5));
	hBitmap_SnakeHead_Down = LoadBitmap(hInstance, MAKEINTRESOURCE(IDB_BITMAP7));
	hBitmap_SnakeHead_Left = LoadBitmap(hInstance, MAKEINTRESOURCE(IDB_BITMAP6));
	hBitmap_SnakeHead_Right = LoadBitmap(hInstance, MAKEINTRESOURCE(IDB_BITMAP4));

	AddNote(3, 3);
	AddNote(3, 4);
	AddNote(3, 5);

	srand((unsigned int)time(NULL));

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
	hWnd = CreateWindow(ex.lpszClassName, "̰����", WS_OVERLAPPEDWINDOW, 50, 50, 615, 638, NULL, NULL, hInstance, NULL);

	//4.��ʾ����
	ShowWindow(hWnd, SW_SHOW);

	//��ʱ�����ڴ�������֮����Ϣѭ��֮ǰ
	SetTimer(hWnd, 1, 500, NULL);

	//��Ϣѭ��
	while (GetMessage(&Msg, NULL, 0, 0))
	{
		TranslateMessage(&Msg);
		DispatchMessage(&Msg);
	}

	return 0;
}


LRESULT CALLBACK MYWNDPROC(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	HDC hDc;
	PAINTSTRUCT pS;

	switch (message)
	{
	case WM_CLOSE:	//�ر���Ϣ
		PostQuitMessage(0);
		break;
	case WM_PAINT:	//�ػ���Ϣ
		hDc = BeginPaint(hWnd, &pS);
		//��ʾ����
		ShowBackground(hDc);
		//��ʾ��
		ShowSnake(hDc);
		//��ʾƻ��
		ShowApple(hDc);
		EndPaint(hWnd, &pS);
		break;
	case WM_KEYDOWN:	//������Ϣ
		switch (wParam)
		{
		case VK_UP:
			if (fx != DOWN && TRUE==bFlag) 
			{
				fx = UP;
			}
			break;
		case VK_DOWN:
			if (fx != UP && TRUE == bFlag)
			{
				fx = DOWN;
				bFlag = FALSE;
			}
			break;
		case VK_RIGHT:
			if (fx != LEFT && TRUE == bFlag)
			{
				fx = RIGHT;
				bFlag = FALSE;
			}
			break;
		case VK_LEFT:
			if (fx != RIGHT && TRUE == bFlag)
			{
				fx = LEFT;
				bFlag = FALSE;
			}
			break;
		}
		hDc = GetDC(hWnd);
		ShowBackground(hDc);
		ShowSnake(hDc); 
		ShowApple(hDc);
		ReleaseDC(hWnd, hDc);
		bFlag = TRUE;
		break;
	case WM_TIMER:	//��ʱ����Ϣ
		Move();
		//�ж��Ƿ�Ե�ƻ��
		if (IsEatApple())
		{
			//�Ե�
			//�䳤
			AddNote(-10, -10);
			//�ڣ�-10��-10����λ�û��һ�������������ߵ��ƶ������漰����ڵ����һ������������������ͻ᳤���ߺ��棬���ֻҪ��ʼλ�ò��ڻ����ڣ����ɴﵽ�߱䳤��Ŀ�ġ�
			//��ƻ��
			NewApple();
		}
		hDc = GetDC(hWnd);
		ShowBackground(hDc);
		ShowSnake(hDc);
		ShowApple(hDc);
		ReleaseDC(hWnd, hDc);

		//�ж���Ϸ�Ƿ������ײǽ ��ҧ��
		if (IsEatItself() || IsBumpWall())
		{
			KillTimer(hWnd, 1);
			//�����ɱ����ʱ���Ļ�����ô�Ի��򵯳����������OK���µĻص�������Ȼ�ỽ���µ�̰���߼����н��������Ҫ��ɱ����ʱ���ٵ�����Ϸ�����Ĵ���
			MessageBox(hWnd, "GameOver����Ϸ������", "��ʾ", MB_OK);
		}
		break;
	}

	return DefWindowProc(hWnd, message, wParam, lParam);
}

void ShowBackground(HDC hDc)
{
	//1.����������DC
	HDC hDcmen = CreateCompatibleDC(hDc);
	//2.��������DC����һ��λͼ
	SelectObject(hDcmen, hBitmap_Background);
	//3.����
	BitBlt(hDc, 0, 0, 600, 600, hDcmen, 0, 0, SRCCOPY);
	//4.ɾ��������DC
	DeleteDC(hDcmen);
}

void AddNote(int x, int y) 
{
	Snake* pTemp = (Snake*)malloc(sizeof(Snake));
	pTemp->x = x;
	pTemp->y = y;
	pTemp->pLast = NULL;
	pTemp->pNext = NULL;

	if (NULL == pHead) 
	{
		pHead = pTemp;
	} 
	else
	{
		pTail->pNext = pTemp;
		pTemp->pLast = pTail;
	}
	pTail = pTemp;
}

void ShowSnake(HDC hDc)
{
	HDC hdcmen = CreateCompatibleDC(hDc);
	Snake* pMark = pHead->pNext;

	//1.��ʾ��ͷ
	switch (fx)
	{
	case UP:
		SelectObject(hdcmen, hBitmap_SnakeHead_Up);
		break;
	case DOWN:
		SelectObject(hdcmen, hBitmap_SnakeHead_Down);
		break;
	case LEFT:
		SelectObject(hdcmen, hBitmap_SnakeHead_Left);
		break;
	case RIGHT:
		SelectObject(hdcmen, hBitmap_SnakeHead_Right);
		break;
	default:
		break;
	}
	BitBlt(hDc, pHead->x * 30, pHead->y * 30, 30, 30, hdcmen, 0, 0, SRCCOPY);

	//2.��ʾ����
	SelectObject(hdcmen, hBitmap_SnakeBody);
	while (pMark != NULL) 
	{
		BitBlt(hDc, pMark->x * 30, pMark->y * 30, 30, 30, hdcmen, 0, 0, SRCCOPY);
		pMark = pMark->pNext;
	}
	DeleteDC(hdcmen);
}

void Move()
{
	Snake* pMark = pTail;
	//1.�ƶ�����
	while (pMark != pHead) 
	{
		pMark->x = pMark->pLast->x;
		pMark->y = pMark->pLast->y;
		pMark = pMark->pLast;
	}
	//2.�ƶ���ͷ
	switch (fx) 
	{
	case UP:
		pHead->y--;
		break;
	case DOWN:
		pHead->y++;
		break;
	case LEFT:
		pHead->x--;
		break;
	case RIGHT:
		pHead->x++;
		break;
	default:
		break;
	}
}

void ShowApple(HDC hDc)
{
	HDC hdcmen = CreateCompatibleDC(hDc);
	SelectObject(hdcmen, hBitmap_Apple);
	BitBlt(hDc, apple.x * 30, apple.y * 30, 30, 30, hdcmen, 0, 0, SRCCOPY);
	DeleteDC(hdcmen);
}

BOOL IsEatApple()
{
	if (apple.x == pHead->x && apple.y == pHead->y) 
	{
		return TRUE;
	}
	return FALSE;
}

void NewApple()
{
	int x;
	int y;
	Snake* pMark = pHead;

	do 
	{
		//��������ɵ�ƻ�����ܳ�����ǽ�� 
		x = rand() % 18 + 1;
		y = rand() % 18 + 1;

		pMark = pHead;
		//Ҳ���ܳ������ߵ�����
		while (pMark != NULL) 
		{
			if (pMark->x == x && pMark->y == y) //ƻ�������غ�
			{
				break;
			}
			pMark = pMark->pNext;
		}
	} while (pMark != NULL);

	apple.x = x;
	apple.y = y;
}

BOOL IsBumpWall()
{
	if (pHead->x == 0 || pHead->x == 19 || pHead->y == 0 || pHead->y == 19) 
	{
		return TRUE;
	}
	return FALSE;
}

BOOL IsEatItself()
{
	Snake* pMark = pHead->pNext;
	while (pMark != NULL)
	{
		if (pHead->x == pMark->x && pHead->y == pMark->y) 
		{
			return TRUE;
		}
		pMark = pMark->pNext;
	}
	return FALSE;
}

/*
���ܳ��ֵ�BUG��
����Ҫ����ͼ����ʱ�����׳��ִ�����ͼ��˸������ԭ������ͼ�޷���һ����ʱ��������ȫ�����ꡣҲ������˵�ġ�˫���塱���⡣

���˼·������������HDC1��HDC2��HDC3���Ƚ�HDC3������λͼ��ת��HDC2�У���ȫ�������HDC2�����һ���Ŵ����ͼ���ٽ�HDC2����HDC1�У��ﵽһ����ʱ��������ֻ��һ����ͼ��Ŀ�ģ��򲻻ᷢ����ͼ�����������
*/