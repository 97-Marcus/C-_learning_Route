#include <windows.h>
#include <stdio.h>
#include <time.h>
#include "resource.h"

LRESULT CALLBACK MYWNDPROC(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

//定义位图句柄
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
//BUG:在一个定时器周期内快速改变两次方向或多少方向，比如→↑，则会发生回头自咬现象。
//解决方案：约束其在一个定时器周期内只能改变一次方向，引入一个标记，若在一个周期内已经改变过则不允改变,在定时器消息和键盘消息中用标记进行限制。

int CALLBACK WinMain(HINSTANCE hInstance,
					 HINSTANCE hPrevlnstance,
					 LPSTR lpCmdLine,
					 int nCmdShow)
{
	WNDCLASSEX ex;
	HWND hWnd;
	MSG Msg;

	//加载位图
	hBitmap_Background = LoadBitmap(hInstance, MAKEINTRESOURCE(IDB_BITMAP1));//LoadBitmap(当前应用实例句柄, 位图路径)，位图路径在导入图片时已经自动宏定义了，利用MAKEINTRESOURCE函数即可得到路径
	//加载失败时会返回NULL，可下断点查看hBitmap_Background的值来判断是否加载成功
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
	hWnd = CreateWindow(ex.lpszClassName, "贪吃蛇", WS_OVERLAPPEDWINDOW, 50, 50, 615, 638, NULL, NULL, hInstance, NULL);

	//4.显示窗口
	ShowWindow(hWnd, SW_SHOW);

	//定时器须在创建窗口之后，消息循环之前
	SetTimer(hWnd, 1, 500, NULL);

	//消息循环
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
	case WM_CLOSE:	//关闭消息
		PostQuitMessage(0);
		break;
	case WM_PAINT:	//重绘消息
		hDc = BeginPaint(hWnd, &pS);
		//显示背景
		ShowBackground(hDc);
		//显示蛇
		ShowSnake(hDc);
		//显示苹果
		ShowApple(hDc);
		EndPaint(hWnd, &pS);
		break;
	case WM_KEYDOWN:	//键盘消息
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
	case WM_TIMER:	//定时器消息
		Move();
		//判断是否吃到苹果
		if (IsEatApple())
		{
			//吃到
			//变长
			AddNote(-10, -10);
			//在（-10，-10）的位置会多一段蛇身，但由于蛇的移动过程涉及链表节点的下一个，因此马上这节蛇身就会长到蛇后面，因此只要初始位置不在画面内，即可达到蛇变长的目的。
			//新苹果
			NewApple();
		}
		hDc = GetDC(hWnd);
		ShowBackground(hDc);
		ShowSnake(hDc);
		ShowApple(hDc);
		ReleaseDC(hWnd, hDc);

		//判断游戏是否结束（撞墙 自咬）
		if (IsEatItself() || IsBumpWall())
		{
			KillTimer(hWnd, 1);
			//如果不杀死定时器的话，那么对话框弹出后甚至点击OK后，新的回调函数依然会唤起新的贪吃蛇继续行进，因此需要先杀死定时器再弹出游戏结束的窗口
			MessageBox(hWnd, "GameOver！游戏结束！", "提示", MB_OK);
		}
		break;
	}

	return DefWindowProc(hWnd, message, wParam, lParam);
}

void ShowBackground(HDC hDc)
{
	//1.创建兼容性DC
	HDC hDcmen = CreateCompatibleDC(hDc);
	//2.给兼容性DC关联一张位图
	SelectObject(hDcmen, hBitmap_Background);
	//3.传输
	BitBlt(hDc, 0, 0, 600, 600, hDcmen, 0, 0, SRCCOPY);
	//4.删除兼容性DC
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

	//1.显示蛇头
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

	//2.显示蛇身
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
	//1.移动蛇身
	while (pMark != pHead) 
	{
		pMark->x = pMark->pLast->x;
		pMark->y = pMark->pLast->y;
		pMark = pMark->pLast;
	}
	//2.移动蛇头
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
		//随机新生成的苹果不能出现在墙上 
		x = rand() % 18 + 1;
		y = rand() % 18 + 1;

		pMark = pHead;
		//也不能出现在蛇的身上
		while (pMark != NULL) 
		{
			if (pMark->x == x && pMark->y == y) //苹果与蛇重合
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
可能出现的BUG：
若需要的贴图过多时，容易出现窗口贴图闪烁的现象，原因是贴图无法在一个定时器周期内全部贴完。也就是所说的“双缓冲”问题。

解决思路：建立兼容性HDC1，HDC2，HDC3，先将HDC3关联的位图都转入HDC2中，待全部传完后，HDC2将变成一整张大的贴图，再将HDC2传入HDC1中，达到一个定时器周期内只传一张贴图的目的，则不会发生贴图贴不完的现象。
*/