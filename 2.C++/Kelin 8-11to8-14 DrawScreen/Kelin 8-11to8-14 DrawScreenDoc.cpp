
// Kelin 8-11to8-14 DrawScreenDoc.cpp: CKelin811to814DrawScreenDoc 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "Kelin 8-11to8-14 DrawScreen.h"
#endif

#include "Kelin 8-11to8-14 DrawScreenDoc.h"

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CKelin811to814DrawScreenDoc

IMPLEMENT_DYNCREATE(CKelin811to814DrawScreenDoc, CDocument)

BEGIN_MESSAGE_MAP(CKelin811to814DrawScreenDoc, CDocument)
END_MESSAGE_MAP()


// CKelin811to814DrawScreenDoc 构造/析构

CKelin811to814DrawScreenDoc::CKelin811to814DrawScreenDoc() noexcept
{
	// TODO: 在此添加一次性构造代码

}

CKelin811to814DrawScreenDoc::~CKelin811to814DrawScreenDoc()
{
}

BOOL CKelin811to814DrawScreenDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: 在此添加重新初始化代码
	// (SDI 文档将重用该文档)

	return TRUE;
}




// CKelin811to814DrawScreenDoc 序列化

void CKelin811to814DrawScreenDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: 在此添加存储代码
	}
	else
	{
		// TODO: 在此添加加载代码
	}
}

#ifdef SHARED_HANDLERS

// 缩略图的支持
void CKelin811to814DrawScreenDoc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// 修改此代码以绘制文档数据
	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

	CString strText = _T("TODO: implement thumbnail drawing here");
	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle((HFONT) GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 36;

	CFont fontDraw;
	fontDraw.CreateFontIndirect(&lf);

	CFont* pOldFont = dc.SelectObject(&fontDraw);
	dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(pOldFont);
}

// 搜索处理程序的支持
void CKelin811to814DrawScreenDoc::InitializeSearchContent()
{
	CString strSearchContent;
	// 从文档数据设置搜索内容。
	// 内容部分应由“;”分隔

	// 例如:     strSearchContent = _T("point;rectangle;circle;ole object;")；
	SetSearchContent(strSearchContent);
}

void CKelin811to814DrawScreenDoc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl *pChunk = nullptr;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != nullptr)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

// CKelin811to814DrawScreenDoc 诊断

#ifdef _DEBUG
void CKelin811to814DrawScreenDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CKelin811to814DrawScreenDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CKelin811to814DrawScreenDoc 命令
