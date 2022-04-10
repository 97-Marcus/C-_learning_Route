
// Kelin 8-11to8-14 DrawScreenView.cpp: CKelin811to814DrawScreenView 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "Kelin 8-11to8-14 DrawScreen.h"
#endif

#include "Kelin 8-11to8-14 DrawScreenDoc.h"
#include "Kelin 8-11to8-14 DrawScreenView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CKelin811to814DrawScreenView

IMPLEMENT_DYNCREATE(CKelin811to814DrawScreenView, CView)

BEGIN_MESSAGE_MAP(CKelin811to814DrawScreenView, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)

	ON_COMMAND_RANGE(ID_CURVE, ID_SAVE, &CKelin811to814DrawScreenView::DealToolBar)	//设置一定范围 ：ID_CURVE 到 ID_SAVE

	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONDOWN()
	ON_COMMAND(ID_WITHDRAW, &CKelin811to814DrawScreenView::OnWithdraw)
END_MESSAGE_MAP()

// CKelin811to814DrawScreenView 构造/析构

CKelin811to814DrawScreenView::CKelin811to814DrawScreenView() noexcept
{
	// TODO: 在此处添加构造代码

	m_toolBarId = 0;

	// 获取屏幕分辨率大小	（桌面窗口大小）
	x = ::GetSystemMetrics(SM_CXSCREEN);
	y = ::GetSystemMetrics(SM_CYSCREEN);

	CWindowDC wdc(GetDesktopWindow());	//获取桌面窗口DC

	CDC cdc;
	cdc.CreateCompatibleDC(&wdc);	//创建兼容性DC

	CBitmap* pMap = new CBitmap;
	pMap->CreateCompatibleBitmap(&wdc, x, y);	//创建兼容性位图

	cdc.SelectObject(pMap);// 选入一张位图
	cdc.BitBlt(0, 0, x, y, &wdc, 0, 0, SRCCOPY);//从窗口DC传输到兼容性DC中，以便图片保存到本地

	//压栈：将桌面原始图 保存到栈
	m_st.push(pMap);

}

CKelin811to814DrawScreenView::~CKelin811to814DrawScreenView()
{
	//回收位图 取出栈内所有元素
	//方案一：
	int i = m_st.size();

	for (int j = 0; j < i; j++) 
	{
		m_st.top()->DeleteObject();	//删除句柄
		delete m_st.top();
		m_st.top() = NULL;

		m_st.pop();
	}
	//方案二：
	//while (m_st.empty() == false) 
	//{
	//	m_st.top()->DeleteObject();	//删除句柄
	//	delete m_st.top();
	//	m_st.top() = NULL;

	//	m_st.pop();
	//}
}

BOOL CKelin811to814DrawScreenView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CKelin811to814DrawScreenView 绘图

void CKelin811to814DrawScreenView::OnDraw(CDC* /*pDC*/)
{
	CKelin811to814DrawScreenDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码

	CClientDC clientDC(this);
	
	CDC cdc;
	cdc.CreateCompatibleDC(&clientDC);	//创建兼容性DC

	cdc.SelectObject(m_st.top());	//将栈中保存的图选入到兼容性DC中
	clientDC.BitBlt(0, 0, x, y, &cdc, 0, 0, SRCCOPY);
}


// CKelin811to814DrawScreenView 打印

BOOL CKelin811to814DrawScreenView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CKelin811to814DrawScreenView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CKelin811to814DrawScreenView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CKelin811to814DrawScreenView 诊断

#ifdef _DEBUG
void CKelin811to814DrawScreenView::AssertValid() const
{
	CView::AssertValid();
}

void CKelin811to814DrawScreenView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CKelin811to814DrawScreenDoc* CKelin811to814DrawScreenView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CKelin811to814DrawScreenDoc)));
	return (CKelin811to814DrawScreenDoc*)m_pDocument;
}
#endif //_DEBUG


// CKelin811to814DrawScreenView 消息处理程序


//处理工具栏命令的消息
void CKelin811to814DrawScreenView::DealToolBar(UINT id) {
	//TRACE("%d  ", id);	//调试 输出的是宏后面的32790-32798

	if (id == ID_QUIT) {//	程序退出

		//PostMessage(WM_CLOSE);	//给视图发送的	 主窗口还在 应该给主对话框发送
		AfxGetMainWnd()->PostMessage(WM_CLOSE);
	}
	else if (id == ID_COLORPANEL)	//颜色选择面板
	{
		CColorDialog color;
		int res = color.DoModal();
		if (res == IDOK) //点击了确定
		{
			//获取选择的颜色
			m_color = color.GetColor();
		}
		else {

		}
	}
	else if (id == ID_SAVE)		//点击保存
	{
		TCHAR szFilter[] =
			_T("jpg(*.jpg;*.jpeg)|*.jpg;*.jpeg|")
			_T("png(*.png)|*.png|")
			_T("bmp(*.bmp)|*.bmp|")
			_T("All Files(*.*)|*.*||");

			CFileDialog dlg(FALSE, L"jpg", L"picture", OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, szFilter, this);
							//另存为 默认的文件后缀 默认的文件名（不包含后缀）文件过滤器 父窗口

			int res = dlg.DoModal();	//弹出框
			if (res == IDOK) //点击确定
			{
				CString str1 = dlg.GetPathName();	//获取路径
				/*CString str2 = dlg.GetFileName();
				CString str3 = dlg.GetFileExt();
				CString str4 = dlg.GetFileTitle();*/	//该程序中暂不需要

				CImage image;
				//image 对象 和 具体需要保存的图片（栈顶的图）进行绑定
				image.Attach((HBITMAP)m_st.top()->m_hObject);
				if (S_OK == image.Save(str1)) {
					MessageBox(L"保存成功！");
				}								//保存到指定路径
				image.Detach();	//解除绑定
			}
			else if (res == IDCANCEL) {	//点击取消
			
			}

	}
	else
	{
		m_toolBarId = id;
	}
}


void CKelin811to814DrawScreenView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	if (m_toolBarId == ID_FILL) //当鼠标左键选中填充按钮按下
	{
		CClientDC client(this);

		//创建指定颜色的画刷并选入到设备中
		CBrush brush(m_color);
		client.SelectObject(brush);

		COLORREF color = ::GetPixel(client, point.x, point.y);	//获取某个像素点的颜色
		client.ExtFloodFill(point.x, point.y, color, FLOODFILLSURFACE);	//填充（某点往外扩散至遇到不同颜色为边界的模式）
	}
	else {
		m_pointBegin = point;//记录点
	}

	CView::OnLButtonDown(nFlags, point);
}

void CKelin811to814DrawScreenView::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CClientDC clientDC(this);

	CDC cdc;
	cdc.CreateCompatibleDC(&clientDC);
	CBitmap* pMap = new CBitmap;
	pMap->CreateCompatibleBitmap(&clientDC, x, y);
	cdc.SelectObject(pMap);
	cdc.BitBlt(0, 0, x, y, &clientDC, 0, 0, SRCCOPY);

	m_st.push(pMap);

	CView::OnLButtonUp(nFlags, point);
}


void CKelin811to814DrawScreenView::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	if (nFlags == MK_LBUTTON) {

		CClientDC clientDC(this);

		if (m_toolBarId == ID_CURVE) {	//绘制曲线

			CPen pen(PS_SOLID, 1, m_color);
			clientDC.SelectObject(pen);

			clientDC.MoveTo(m_pointBegin);
			clientDC.LineTo(point);

			m_pointBegin = point;	//曲线特性：起点是上一次的终点
		}
		else {

			//创建缓冲DC
			CDC cachecdc;
			cachecdc.CreateCompatibleDC(&clientDC);
			CBitmap map;
			map.CreateCompatibleBitmap(&clientDC, x, y);
			cachecdc.SelectObject(map);

			//绘制之前先覆盖一次，以消除上一次鼠标移动的痕迹
			CDC cdc;
			cdc.CreateCompatibleDC(&cachecdc);
			cdc.SelectObject(m_st.top());
			cachecdc.BitBlt(0, 0, x, y, &cdc, 0, 0, SRCCOPY);

			switch (m_toolBarId)
			{
				case ID_LINE:	//绘制直线
					{
						CPen pen(PS_SOLID, 1, m_color);
						cachecdc.SelectObject(pen);

						cachecdc.MoveTo(m_pointBegin);
						cachecdc.LineTo(point);
					}
					break;
				case ID_RECTANGLE:	//绘制矩形
					{
						CPen pen(PS_SOLID, 1, m_color);
						cachecdc.SelectObject(pen);

						cachecdc.SelectStockObject(NULL_BRUSH);//选入一个预定义的空画刷
						cachecdc.Rectangle(m_pointBegin.x, m_pointBegin.y, point.x, point.y);
					}
					break;
				case ID_CIRCLE:	 //绘制实心圆
					{
						CBrush brush(m_color);
						cachecdc.SelectObject(brush);

						cachecdc.SelectStockObject(NULL_PEN);//选入一个预定义的空画笔
						cachecdc.Ellipse(m_pointBegin.x, m_pointBegin.y, point.x, point.y);
					}
				break;
				case ID_TRIANGLE:	 //绘制三角形
					{
						CPen pen(PS_SOLID, 1, m_color);
						cachecdc.SelectObject(pen);

						cachecdc.SelectStockObject(NULL_BRUSH);//选入一个预定义的空画刷
						//计算三角形三个点的坐标
						POINT po[3] = {
							{(point.x + m_pointBegin.x) / 2,m_pointBegin.y},
							{m_pointBegin.x,point.y},
							{point.x,point.y}
						};
						cachecdc.Polygon(po,3);
					}
				break;
			}

			//最后再传输到窗口上
			clientDC.BitBlt(0, 0, x, y, &cachecdc, 0, 0, SRCCOPY);
		}
	}

	CView::OnMouseMove(nFlags, point);
}



void CKelin811to814DrawScreenView::OnWithdraw()
{
	// TODO: 在此添加命令处理程序代码

	if (m_st.size() > 1) {		//	出栈，但需要注意，最后一张图需要保留~

		delete m_st.top();
		m_st.top() = NULL;

		m_st.pop();

		PostMessage(WM_PAINT);
	}
}
