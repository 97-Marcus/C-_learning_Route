// CSetDlg.cpp: 实现文件
//

#include "pch.h"
#include "Clean.h"
#include "CSetDlg.h"
#include "afxdialogex.h"
#include "CMyTreeCrtl.h"


// CSetDlg 对话框

IMPLEMENT_DYNAMIC(CSetDlg, CDialogEx)

CSetDlg::CSetDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG2, pParent)
{

}

CSetDlg::~CSetDlg()
{
}

void CSetDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO1, m_comb);
	DDX_Control(pDX, IDC_TREE1, m_tree);
}


BEGIN_MESSAGE_MAP(CSetDlg, CDialogEx)
	ON_CBN_CLOSEUP(IDC_COMBO1, &CSetDlg::OnCbnCloseupCombo1)
	ON_BN_CLICKED(IDC_BUTTON1, &CSetDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON3, &CSetDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON2, &CSetDlg::OnBnClickedButton2)
END_MESSAGE_MAP()


// CSetDlg 消息处理程序

BOOL CSetDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化

	m_comb.AddString(L"默认目录...");
	m_comb.AddString(L"请选择目录...");

	m_comb.SelectString(-1, L"默认目录...");	//-1：从列表开始处查找字符串

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}


void CSetDlg::OnCbnCloseupCombo1()
{
	CString selstr = L"";
	// TODO: 在此添加控件通知处理程序代码
	// 选中项的下标 根据下表来判断是选择的下拉列表的哪一项~但是因为加了路径以后请选择目录那一条会往下移动
	// 所以他的下标不固定 可以通过判断字符来辅助进行~
	int index = m_comb.GetCurSel();
	m_comb.GetLBText(index, selstr);

	if (selstr== L"请选择目录...")
	{
		CString foldpath = theApp.GetFolderPath(this->m_hWnd);
		if (foldpath != L"") 
		{
			m_comb.InsertString(0, foldpath);
			m_comb.SelectString(-1, foldpath);
		}
		else {
			m_comb.SelectString(-1, L"默认目录...");
		}
	}
}


void CSetDlg::OnBnClickedButton1()	//确定
{
	// TODO: 在此添加控件通知处理程序代码

	// 先获取编辑框上的内容~
	CString selstr = L"";
	m_comb.GetLBText(m_comb.GetCurSel(), selstr);

	if (selstr == L"默认目录...") 
	{
		selstr = L"C:";
	}

	m_tree.DeleteAllItems();	//	插入前先清空 因为功能需求中只需要展示一个目录下的文件
	//tree 插入一项
	HTREEITEM itemRoot = m_tree.InsertItem(selstr);	

	m_tree.InsertChildItem(itemRoot, selstr);
}


void CSetDlg::OnBnClickedButton3()	//完成按钮
{
	// TODO: 在此添加控件通知处理程序代码
	set<HTREEITEM>::iterator ite = m_tree.m_st.begin();
	while (ite != m_tree.m_st.end()) 
	{
		if (m_tree.GetCheck(*ite)) 
		{
			CString txt = m_tree.GetItemText(*ite);
			int index = txt.ReverseFind(L'.');
			if (index != -1) {
				CString suffix = txt.Right(txt.GetLength() - index);	//截取后缀名
				m_suffix.insert(suffix);	//选中多个文件 具有相同的后缀名 只会保留一个
			}
		}
		ite++;
	}
	CString str = L"";
	set<CString>::iterator iteL = m_suffix.begin();
	while (iteL != m_suffix.end())
	{
		str += *iteL + L"|";
		iteL++;
	}
	MessageBox(L"设置完成，" + str);
}


void CSetDlg::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	m_tree.DeleteAllItems();
	m_tree.m_st.clear();
	m_suffix.clear();
}
