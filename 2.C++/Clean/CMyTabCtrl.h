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
	void InitTabCtrl();	//��ʼ��

	CShowDialog m_showdialog;	//�������
	CSetDlg m_setdlg;			//�������

	bool m_expend;

	afx_msg void OnNMClick(NMHDR* pNMHDR, LRESULT* pResult);
};


