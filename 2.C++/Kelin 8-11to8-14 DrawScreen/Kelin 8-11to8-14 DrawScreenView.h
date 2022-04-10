
// Kelin 8-11to8-14 DrawScreenView.h: CKelin811to814DrawScreenView 类的接口
//

#pragma once

#include <stack>
using namespace std;


class CKelin811to814DrawScreenView : public CView
{
protected: // 仅从序列化创建
	CKelin811to814DrawScreenView() noexcept;
	DECLARE_DYNCREATE(CKelin811to814DrawScreenView)

// 特性
public:
	CKelin811to814DrawScreenDoc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 实现
public:
	virtual ~CKelin811to814DrawScreenView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()

public:
	stack<CBitmap*> m_st;	//存储位图的指针
	int x;
	int y;
	CPoint m_pointBegin;	//记录鼠标按下的起始坐标点
	int m_toolBarId;
	COLORREF m_color;

public:

	void DealToolBar(UINT);	//工具栏处理函数声明
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnWithdraw();
};

#ifndef _DEBUG  // Kelin 8-11to8-14 DrawScreenView.cpp 中的调试版本
inline CKelin811to814DrawScreenDoc* CKelin811to814DrawScreenView::GetDocument() const
   { return reinterpret_cast<CKelin811to814DrawScreenDoc*>(m_pDocument); }
#endif

