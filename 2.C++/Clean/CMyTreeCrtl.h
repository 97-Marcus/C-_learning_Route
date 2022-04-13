#pragma once
#include<set>
using namespace std;

// CMyTreeCrtl

class CMyTreeCrtl : public CTreeCtrl
{
	DECLARE_DYNAMIC(CMyTreeCrtl)

public:
	CMyTreeCrtl();
	virtual ~CMyTreeCrtl();

protected:
	DECLARE_MESSAGE_MAP()

public:
	void InsertChildItem(HTREEITEM item,CString strpath);
	afx_msg void OnTvnItemexpanding(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnNMClick(NMHDR* pNMHDR, LRESULT* pResult);

public:
	set<HTREEITEM>  m_st;
};


