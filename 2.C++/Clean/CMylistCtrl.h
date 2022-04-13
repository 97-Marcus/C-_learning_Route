#pragma once


// CMylistCtrl

class CMylistCtrl : public CListCtrl
{
	DECLARE_DYNAMIC(CMylistCtrl)

public:
	CMylistCtrl();
	virtual ~CMylistCtrl();

protected:
	DECLARE_MESSAGE_MAP()
public:
	CMenu m_menu;
	afx_msg void OnNMRClick(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void On32771();
	afx_msg void On32772();
	afx_msg void On32773();
	afx_msg void On32774();
};


