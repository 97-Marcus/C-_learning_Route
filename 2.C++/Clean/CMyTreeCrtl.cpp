// CMyTreeCrtl.cpp: 实现文件
//

#include "pch.h"
#include "Clean.h"
#include "CMyTreeCrtl.h"

// CMyTreeCrtl

IMPLEMENT_DYNAMIC(CMyTreeCrtl, CTreeCtrl)

CMyTreeCrtl::CMyTreeCrtl()
{

}

CMyTreeCrtl::~CMyTreeCrtl()
{
}

BEGIN_MESSAGE_MAP(CMyTreeCrtl, CTreeCtrl)
	ON_NOTIFY_REFLECT(TVN_ITEMEXPANDING, &CMyTreeCrtl::OnTvnItemexpanding)
	ON_NOTIFY_REFLECT(NM_CLICK, &CMyTreeCrtl::OnNMClick)
END_MESSAGE_MAP()

// CMyTreeCrtl 消息处理程序

void CMyTreeCrtl::InsertChildItem(HTREEITEM item, CString strpath) {

	if (item == NULL || strpath == L"")
	{
		return;
	}

	CFileFind filefine;
	BOOL b = filefine.FindFile(strpath+L"\\*.*");

	while (b)
	{
		b = filefine.FindNextFile();
		if (filefine.IsDots()) {	//判断有没有.或者.. 如果有 的话就不用获取了
			continue;
		}
		CString failName = filefine.GetFileName();	//获取文件名

		this->InsertItem(failName, item);

	}

}

void CMyTreeCrtl::OnTvnItemexpanding(NMHDR* pNMHDR, LRESULT* pResult)
{
	LPNMTREEVIEW pNMTreeView = reinterpret_cast<LPNMTREEVIEW>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码

	HTREEITEM expandItem = pNMTreeView->itemNew.hItem;	//获取鼠标点击的那项
	CString expandText = GetItemText(expandItem);	//点击的项的文件名

	// 遍历 寻找父项
	CString parentText = expandText;
	HTREEITEM parentItem = GetParentItem(expandItem);
	while (parentItem)	//如果有父项
	{
		parentText = GetItemText(parentItem) + L"\\" + parentText;	//拼接路径
		parentItem = GetParentItem(parentItem);
	}

	// 获取子项
	HTREEITEM childItem = GetChildItem(expandItem);	
	while (childItem)	//如果有子项
	{
		CString childText = GetItemText(childItem);		//获取子项的文件名
		CString path = parentText + L"\\" + childText;	//拼接路径

		if (!GetChildItem(childItem))	//如果没有的话 就插入 有的话就不插入
		{
			InsertChildItem(childItem, path);				//使用前面封装好的方法进行添加~
		}
		childItem = GetNextSiblingItem(childItem);		//查询后面的兄弟项
	}

	*pResult = 0;
}


void CMyTreeCrtl::OnNMClick(NMHDR* pNMHDR, LRESULT* pResult)
{
	// TODO: 在此添加控件通知处理程序代码

	// 获取鼠标点击的那一项
	POINT po = { 0 };
	GetCursorPos(&po);//获取坐标
	ScreenToClient(&po);//屏幕->客户区

	HTREEITEM clickItem = HitTest(po);
	m_st.insert(clickItem);	//点击的那项放到set里

	*pResult = 0;
}
