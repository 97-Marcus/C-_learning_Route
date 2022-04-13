#pragma once
#include "CShowDialog.h"
#include "CSetDlg.h"

// CMyTabCtrl

class CMyTabCtrl : public CTabCtrl
{
	DECLARE_DYNAMIC(CMyTabCtrl)

public:
	CMyTabCtrl();
	virtual ~CMyTabCtrl();

protected:
	DECLARE_MESSAGE_MAP()

public:
	void InitTabCtrl();	//初始化

	CShowDialog m_showdialog;	//定义对象
	CSetDlg m_setdlg;			//定义对象

	bool m_expend;

	afx_msg void OnNMClick(NMHDR* pNMHDR, LRESULT* pResult);
};


