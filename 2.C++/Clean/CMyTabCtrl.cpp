// CMyTabCtrl.cpp: 实现文件
//

#include "pch.h"
#include "Clean.h"
#include "CMyTabCtrl.h"


// CMyTabCtrl

IMPLEMENT_DYNAMIC(CMyTabCtrl, CTabCtrl)

CMyTabCtrl::CMyTabCtrl()
{

}

CMyTabCtrl::~CMyTabCtrl()
{
}


BEGIN_MESSAGE_MAP(CMyTabCtrl, CTabCtrl)
	ON_NOTIFY_REFLECT(NM_CLICK, &CMyTabCtrl::OnNMClick)
END_MESSAGE_MAP()



// 初始化


void CMyTabCtrl::InitTabCtrl() {

	//初始化tab
	InsertItem(0, L"清扫目录");
	InsertItem(1, L"显示目录");
	InsertItem(2, L"设置目录");
	InsertItem(3, L"扫描删除");

	//先获取原始的宽度高度	
	RECT rect = { 0 };
	GetItemRect(0, &rect);
	//设置tab的宽度高度
	CSize size(-1, rect.bottom - rect.top + 15);
	SetItemSize(size);

	//创建showdlg 非模态对话框
	m_showdialog.Create(m_showdialog.IDD, this);
	//先获取原来的窗口位置
	RECT rectdlg = { 0 };
	m_showdialog.GetClientRect(&rectdlg);
	//向下移动一些 显示出tab
	rectdlg.top += 37;
	rectdlg.bottom += 37;
	m_showdialog.MoveWindow(&rectdlg);
	m_showdialog.ShowWindow(SW_SHOW);

	SetCurSel(0);	//设置默认的第一个标签	//也可以不设置 默认就是第一个~

	//CsetDlg 初始化

	//创建showdlg 非模态对话框
	m_setdlg.Create(m_setdlg.IDD, this);
	//先获取原来的窗口位置
	RECT rectdlg1 = { 0 };
	m_setdlg.GetClientRect(&rectdlg1);
	//向下移动一些 显示出tab
	rectdlg1.top += 37;
	rectdlg1.bottom += 37;
	m_setdlg.MoveWindow(&rectdlg1);
	m_setdlg.ShowWindow(SW_HIDE);

	m_expend = false;
}

void CMyTabCtrl::OnNMClick(NMHDR* pNMHDR, LRESULT* pResult)
{
	int index = GetCurSel();
	switch (index)
	{
	case 0:
		{m_showdialog.ShowWindow(SW_SHOW);
		 m_setdlg.ShowWindow(SW_HIDE);}
		break;
	case 1:	
		{
			m_showdialog.ShowWindow(SW_SHOW);
			m_setdlg.ShowWindow(SW_HIDE);
		
			RECT rect = { 0 };
			AfxGetMainWnd()->GetWindowRect(&rect);

			if (m_expend) {	
						//要收缩
				rect.bottom -= 225;
				m_expend = false;
			}
			else {
						//要展开
				rect.bottom += 225;
				m_expend = true;
			}
			AfxGetMainWnd()->MoveWindow(&rect);
		}
		break;
	case 2:
		{m_showdialog.ShowWindow(SW_HIDE);
		 m_setdlg.ShowWindow(SW_SHOW);}
		break;
	case 3:
		{m_showdialog.ShowWindow(SW_HIDE);
		 m_setdlg.ShowWindow(SW_HIDE);}
		break;
	}
	*pResult = 0;
}
