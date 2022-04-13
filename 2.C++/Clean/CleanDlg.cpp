
// CleanDlg.cpp: 实现文件
//

#include "pch.h"
#include "framework.h"
#include "Clean.h"
#include "CleanDlg.h"
#include "afxdialogex.h"
#include <queue>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CCleanDlg 对话框



CCleanDlg::CCleanDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_CLEAN_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);	
}

void CCleanDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PICTURE, m_picture);		//pic ctrl与具体资源绑定
	DDX_Control(pDX, IDC_TAB1, m_mytab);			//tyb ctrl与具体资源绑定
	DDX_Control(pDX, IDC_LIST2, m_searchList);
}

BEGIN_MESSAGE_MAP(CCleanDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_STN_CLICKED(IDC_PICTURE, &CCleanDlg::OnStnClickedPicture)
	ON_BN_CLICKED(IDC_BUTTON1, &CCleanDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CCleanDlg::OnBnClickedButton2)
END_MESSAGE_MAP()


// CCleanDlg 消息处理程序

BOOL CCleanDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
	m_WIN7.LoadBitmap(IDB_WIN7);
	m_WIN8.LoadBitmap(IDB_WIN8);

	m_picture.SetBitmap(m_WIN7);	//初始化 设置为win7图片

	m_mytab.InitTabCtrl();

	m_searchList.SetExtendedStyle(LVS_EX_CHECKBOXES);	//拓展样式：勾选框

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CCleanDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CCleanDlg::OnPaint()
{
	if (!m_mytab.m_expend) 
	{
		//裁剪主窗口底部的搜索结果部分

		RECT rect = { 0 };
		GetWindowRect(&rect);

		rect.bottom -= 225;
		MoveWindow(&rect);
	}

	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CCleanDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CCleanDlg::OnStnClickedPicture()
{
	// TODO: 在此添加控件通知处理程序代码

	if (m_WIN7==m_picture.GetBitmap())
	{
		m_picture.SetBitmap(m_WIN8);
	}
	else
		m_picture.SetBitmap(m_WIN7);

}


void CCleanDlg::OnBnClickedButton1()	//搜索按钮功能事件	
{
	// TODO: 在此添加控件通知处理程序代码
	queue<CString> que;

	for (int i = 0; i < m_mytab.m_showdialog.m_showlist.GetItemCount(); i++)	//遍历
	{
		if (m_mytab.m_showdialog.m_showlist.GetCheck(i)) 	//判断是否为选中状态
		{
			CString strPath = m_mytab.m_showdialog.m_showlist.GetItemText(i, 0);	//获取勾选的文本
			que.push(strPath);
		}	
	}
	m_searchList.DeleteAllItems();	//搜索前先清空 避免重复搜索添加~
	while (que.size() > 0)
	{
		CString strPath = que.front();	//取出节点里的值
		if (strPath.Right(1) != L"\\") 
		{
			strPath += L"\\";
		}
		CFileFind fileF;
		BOOL b = fileF.FindFile(strPath + L"*.*");
		while (b)
		{
			b = fileF.FindNextFile();
			if (fileF.IsDots())		//过滤.  ..
			{
				continue;
			}
			CString fileName = fileF.GetFileName();
			if (fileF.IsDirectory()) 	//判断是文件还是目录
			{	//目录	//继续找内部文件
				que.push(strPath + fileName);
			}
			else
			{	//文件	//获取后缀名
				int index = fileName.ReverseFind(L'.');
				if (index != -1)	//找到了
				{
					CString suffix = fileName.Right(fileName.GetLength() - index);
					//后缀名匹配
					if (m_mytab.m_setdlg.m_suffix.count(suffix))	//存在 匹配上了
					{
						//将拼接完的路径插入到搜索结果中
						m_searchList.InsertItem(m_searchList.GetItemCount(), strPath + fileName);
					}
				}
			}
		}
		que.pop();		//删除节点
	}
}


void CCleanDlg::OnBnClickedButton2()	//删除按钮功能事件	
{
	// TODO: 在此添加控件通知处理程序代码

	for (int i = 0; i < m_searchList.GetItemCount(); i++) 
	{
		if (m_searchList.GetCheck(i)) 		//判断第i项是否为选中状态
		{
			CString filePath = m_searchList.GetItemText(i, 0);
			if (::DeleteFile(filePath))	//选中则删除对应的磁盘的文件 成功删除返回非0值
			{
				m_searchList.DeleteItem(i);//一定要确认文件删除了再删~
				i--;	//删除了会自动往前串一个（相当于++），所以要--
			}
			else
			{
				MessageBox(L"删除文件失败[" + filePath + L"]失败！");
			}
		}
	}
}
