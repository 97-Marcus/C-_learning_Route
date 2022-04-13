#pragma once
#include "CMylistCtrl.h"

// CShowDialog 对话框

class CShowDialog : public CDialogEx
{
	DECLARE_DYNAMIC(CShowDialog)

public:
	CShowDialog(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CShowDialog();

// 对话框数据
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();

public:

	CMylistCtrl m_showlist;
	virtual BOOL OnInitDialog();
};
