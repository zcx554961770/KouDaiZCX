// CMAINPAGE.cpp: 实现文件
//

#include "pch.h"
#include "Koudaizcx.h"
#include "CMAINPAGE.h"
#include "afxdialogex.h"


// CMAINPAGE 对话框

IMPLEMENT_DYNAMIC(CMAINPAGE, CDialogEx)

CMAINPAGE::CMAINPAGE(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG4, pParent)
{

}

CMAINPAGE::~CMAINPAGE()
{
}

void CMAINPAGE::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TAB1, m_tabpage);
}


BEGIN_MESSAGE_MAP(CMAINPAGE, CDialogEx)
	ON_NOTIFY(TCN_SELCHANGE, IDC_TAB1, &CMAINPAGE::OnTcnSelchangeTab1)
END_MESSAGE_MAP()


// CMAINPAGE 消息处理程序


BOOL CMAINPAGE::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	m_tabpage.InsertItem(0, "测试");
	m_tabpage.InsertItem(1, "抓包");
	m_tabpage.InsertItem(2, "组包");
	m_tabpage.InsertItem(3, "预留1");
	m_tabpage.InsertItem(4, "预留2");
	//创建3个窗口
	RECT rtab;
	m_tabpage.GetWindowRect(&rtab);//获取 m_tabpage的矩形大小 SetWindowRect SetClientRect 没这函数 MoveWindow
	rtab.left += 3;
	rtab.right -= 30;
	rtab.bottom -= 60;
	rtab.top -= 12;

	m_page1.Create(IDD_DIALOG1);
	m_page1.ShowWindow(SW_SHOW); //显示窗口
	m_page1.SetParent(&m_tabpage);//把m_tabpage设置为m_page1的父窗口
	m_page1.MoveWindow(&rtab, true);

	m_page2.Create(IDD_DIALOG2);
	m_page2.ShowWindow(SW_HIDE); //显示窗口
	m_page2.SetParent(&m_tabpage);//把m_tabpage设置为m_page1的父窗口
	m_page2.MoveWindow(&rtab, true);

	m_page3.Create(IDD_DIALOG3);
	m_page3.ShowWindow(SW_HIDE); //显示窗口
	m_page3.SetParent(&m_tabpage);//把m_tabpage设置为m_page1的父窗口
	m_page3.MoveWindow(&rtab, true);



	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}


void CMAINPAGE::OnTcnSelchangeTab1(NMHDR* pNMHDR, LRESULT* pResult)
{
	// TODO: 在此添加控件通知处理程序代码
	*pResult = 0;
	//::MessageBoxA(0, 0, 0, 0);
	TRACE("选中 m_tabpage.GetCurSel()=%d \r\n", m_tabpage.GetCurSel());

	switch (m_tabpage.GetCurSel())
	{
	case 0:
	{
		//只显示窗口1
		m_page1.ShowWindow(SW_SHOW); //显示窗口
		m_page2.ShowWindow(SW_HIDE); //隐藏窗口
		m_page3.ShowWindow(SW_HIDE); //隐藏窗口

		break;
	}
	case 1:
	{
		//只显示窗口2

		m_page1.ShowWindow(SW_HIDE);
		m_page2.ShowWindow(SW_SHOW);
		m_page3.ShowWindow(SW_HIDE);
		break;
	}
	case 2:
	{
		//只显示窗口3  其它的多余窗口要隐藏 ShowWindow 
		m_page1.ShowWindow(SW_HIDE);
		m_page2.ShowWindow(SW_HIDE);
		m_page3.ShowWindow(SW_SHOW);
		break;
	}
	case 3:
	{
		m_page1.ShowWindow(SW_HIDE);
		m_page2.ShowWindow(SW_HIDE);
		m_page3.ShowWindow(SW_HIDE);
		break;
	}
	case 4:
	{
		m_page1.ShowWindow(SW_HIDE);
		m_page2.ShowWindow(SW_HIDE);
		m_page3.ShowWindow(SW_HIDE);
		break;
	}

	}
}
