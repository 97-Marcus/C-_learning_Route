#pragma once
#include <windows.h>
#include "resource.h"


class CMali
{
public:
	int m_nx;
	int m_ny;
	int m_nDirection;//方向

	HBITMAP m_hUp;
	HBITMAP m_hDown;
	HBITMAP m_hRight;
	HBITMAP m_hLeft;

	CMali() {
		m_nx = 0;
		m_ny = 0;
		m_nDirection = VK_LEFT;

		m_hUp = NULL;
		m_hDown = NULL;
		m_hRight = NULL;
		m_hLeft = NULL;
	}

	~CMali() {
		::DeleteObject(m_hUp);
		m_hUp = NULL;
		::DeleteObject(m_hDown);
		m_hDown = NULL;		
		::DeleteObject(m_hLeft);
		m_hLeft = NULL;
		::DeleteObject(m_hRight);
		m_hRight = NULL;
	}

	void InitPeople(HINSTANCE hIns) {		//初始化
		m_nx = 200;
		m_ny = 200;
		m_hUp = ::LoadBitmap(hIns, MAKEINTRESOURCE(IDB_Up));
		m_hDown = ::LoadBitmap(hIns, MAKEINTRESOURCE(IDB_Down));
		m_hRight = ::LoadBitmap(hIns, MAKEINTRESOURCE(IDB_Right));
		m_hLeft = ::LoadBitmap(hIns, MAKEINTRESOURCE(IDB_Left));
	}

	void ShowPeople(HDC hdc) {		//显示
		//1.获取窗口DC
		//2.创建兼容性DC
		HDC compDc = ::CreateCompatibleDC(hdc);
		//3.句柄选入到兼容性DC中（选入相应的位图）
		if (m_nDirection == VK_LEFT) 
		{
			::SelectObject(compDc, m_hLeft);
		}else if (m_nDirection == VK_RIGHT)
		{
			::SelectObject(compDc, m_hRight);
			}
		else if (m_nDirection == VK_UP)
		{
			::SelectObject(compDc, m_hUp);
		}
		else if (m_nDirection == VK_DOWN)
		{
			::SelectObject(compDc, m_hDown);
		}
		//4.兼容性DC里的图贴到窗口上（贴图）
		::BitBlt(hdc, m_nx, m_ny, 60, 60, compDc, 0, 0, SRCAND);//SRCAAND与操作，可以将位图的白色部分消除，只显示非白色部分
		//5.删除创建的兼容性DC
		::DeleteDC(compDc);
		compDc = NULL;
		//6.释放获取的窗口DC
	}

	void MovePeople(int direct, int step = 4) {		//移动 
		switch (direct) {
		case VK_LEFT:
		{
			if (m_nx - step <= 0) 
			{
				m_nx = 0;
			}
			else {
				m_nx -= step;
			}
			m_nDirection = VK_LEFT;
		}
		break;
		case VK_RIGHT:
		{
			if (m_nx + step >= 440)
			{
				m_nx = 440;
			}
			else {
				m_nx += step;
			}
			m_nDirection = VK_RIGHT;
		}
		break;
		case VK_UP:
		{
			if (m_ny - step <= 0)
			{
				m_ny = 0;
			}
			else {
				m_ny -= step;
			}
			m_nDirection = VK_UP;
		}
		break;
		case VK_DOWN:
		{
			if (m_ny + step >= 440) 
			{
				m_ny = 440;
			}
			else {
				m_ny += step;
			}
			m_nDirection = VK_DOWN;
		}
		break;
		}
	}

protected:
private:
};