// CMylistCtrl.cpp: 实现文件
//

#include "pch.h"
#include "Clean.h"
#include "CMylistCtrl.h"


// CMylistCtrl

IMPLEMENT_DYNAMIC(CMylistCtrl, CListCtrl)

CMylistCtrl::CMylistCtrl()
{
	m_menu.LoadMenu(IDR_MENU1);
}

CMylistCtrl::~CMylistCtrl()
{
}


BEGIN_MESSAGE_MAP(CMylistCtrl, CListCtrl)
	ON_NOTIFY_REFLECT(NM_RCLICK, &CMylistCtrl::OnNMRClick)
	ON_COMMAND(ID_32771, &CMylistCtrl::On32771)
	ON_COMMAND(ID_32772, &CMylistCtrl::On32772)
	ON_COMMAND(ID_32773, &CMylistCtrl::On32773)
	ON_COMMAND(ID_32774, &CMylistCtrl::On32774)
END_MESSAGE_MAP()



// CMylistCtrl 消息处理程序




void CMylistCtrl::OnNMRClick(NMHDR* pNMHDR, LRESULT* pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码

	//	弹出菜单资源
	//	获取光标相对于屏幕的位置
	POINT po = { 0 };
	::GetCursorPos(&po);
	//m_menu.GetSubMenu(0)	//指向第几级菜单 0指向的是编辑 1指向的是12
	m_menu.GetSubMenu(0)->TrackPopupMenu(TPM_LEFTALIGN | TPM_LEFTBUTTON, po.x, po.y, this);
											//屏幕位置标志		鼠标键标志	
	*pResult = 0;
}


void CMylistCtrl::On32771()
{
	CString folderPath = theApp.GetFolderPath(this->m_hWnd);
	if (folderPath != L"")
	{
		InsertItem(GetItemCount(), folderPath);
	}
}

void CMylistCtrl::On32772()
{
	for (int i = 0; i < GetItemCount(); i++) 	//遍历 
	{
		if (GetCheck(i)) {	//	判断是否勾选了
			DeleteItem(i);	//	勾选则删除  删除了一个以后如果i++ 那就会错失一个 所以后面i--
			i--;
		}
	}
}

void CMylistCtrl::On32773()
{
	DeleteAllItems();
}


void CMylistCtrl::On32774()
{
	//	发送退出的消息	//默认是给当前类发的 但实际上要给主对话框发送才能真的退出 所以要获取主窗口
	AfxGetMainWnd()->PostMessage(WM_CLOSE);
}
