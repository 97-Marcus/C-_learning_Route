// CShowDialog.cpp: 实现文件
//

#include "pch.h"
#include "Clean.h"
#include "CShowDialog.h"
#include "afxdialogex.h"


// CShowDialog 对话框

IMPLEMENT_DYNAMIC(CShowDialog, CDialogEx)

CShowDialog::CShowDialog(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG1, pParent)
{

}

CShowDialog::~CShowDialog()
{
}

void CShowDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_showlist);
}


BEGIN_MESSAGE_MAP(CShowDialog, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON3, &CShowDialog::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON1, &CShowDialog::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CShowDialog::OnBnClickedButton2)
END_MESSAGE_MAP()


// CShowDialog 消息处理程序


void CShowDialog::OnBnClickedButton1()	//添加目录功能
{
	// TODO: 在此添加控件通知处理程序代码

	CString folderPath = theApp.GetFolderPath(this->m_hWnd);
	if (folderPath != L"") 
	{
		m_showlist.InsertItem(m_showlist.GetItemCount(), folderPath);
	}
}

void CShowDialog::OnBnClickedButton2()	//删除目录功能
{
	// TODO: 在此添加控件通知处理程序代码
	for (int i = 0; i < m_showlist.GetItemCount(); i++) 	//遍历 
	{
		if (m_showlist.GetCheck(i)) {	//	判断是否勾选了
			m_showlist.DeleteItem(i);	//	勾选则删除  删除了一个以后如果i++ 那就会错失一个 所以后面i--
			i--;
		}
	}
}

void CShowDialog::OnBnClickedButton3()	//清空目录功能
{
	// TODO: 在此添加控件通知处理程序代码
	m_showlist.DeleteAllItems();
}


BOOL CShowDialog::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	// 设置 listctr1 的样式  前面带勾选~
	m_showlist.SetExtendedStyle(LVS_EX_CHECKBOXES);		//拓展样式风格

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}
