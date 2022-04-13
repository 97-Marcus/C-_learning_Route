#pragma once
#include "CMyTreeCrtl.h"

// CSetDlg 对话框

class CSetDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CSetDlg)

public:
	CSetDlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CSetDlg();

// 对话框数据
	enum { IDD = IDD_DIALOG2 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CComboBox m_comb;
	CMyTreeCrtl m_tree;
	set<CString> m_suffix;

public:
	virtual BOOL OnInitDialog();
	afx_msg void OnCbnCloseupCombo1();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton2();
};
