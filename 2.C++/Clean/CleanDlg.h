
// CleanDlg.h: 头文件
//

#pragma once

#include "CMyTabCtrl.h"

// CCleanDlg 对话框
class CCleanDlg : public CDialogEx
{
// 构造
public:
	CCleanDlg(CWnd* pParent = nullptr);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CLEAN_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()

public:
	CBitmap m_WIN7;
	CBitmap m_WIN8;

	CStatic m_picture;
	afx_msg void OnStnClickedPicture();
	CMyTabCtrl m_mytab;
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	CListCtrl m_searchList;
};
