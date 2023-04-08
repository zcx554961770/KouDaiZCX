// CPAGE2.cpp: 实现文件
//

#include "pch.h"
#include "Koudaizcx.h"
#include "CPAGE2.h"
#include "afxdialogex.h"


// CPAGE2 对话框

IMPLEMENT_DYNAMIC(CPAGE2, CDialogEx)

CPAGE2::CPAGE2(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG2, pParent)
	, m_edt1_cstr(_T(""))
{

}

CPAGE2::~CPAGE2()
{
}

void CPAGE2::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_edt1_cstr);
}


BEGIN_MESSAGE_MAP(CPAGE2, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &CPAGE2::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CPAGE2::OnBnClickedButton2)
END_MESSAGE_MAP()


// CPAGE2 消息处理程序

 // UpdateData(true);//从窗口把数据保存到关联的变量 m_edt1_cstr
void CPAGE2::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	CString	一行字符串 = "------------------------------------\r\n";
	m_edt1_cstr = m_edt1_cstr + 一行字符串;
	UpdateData(false); //将字符串写入到窗口
}
LRESULT CPAGE2::WindowProc(UINT message, WPARAM wParam, LPARAM lParam)
{
	//  SendMessageA(h, WM_USER + 150, 0, (LPARAM)csLine);
	if (message == WM_USER + 150)
	{
		//把 lParam //csLine 添加到控件编辑框

		char* 一行字符串 = (char*)lParam;// "1111111adf随意111111111111\r\n";
		m_edt1_cstr = m_edt1_cstr + 一行字符串;
		UpdateData(false);//从变量更新到窗口

	}
	return CDialogEx::WindowProc(message, wParam, lParam);
}
HWND g_窗口2句柄 = 0;
BOOL CPAGE2::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	g_窗口2句柄 = m_hWnd;
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}

void CPAGE2::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	CString	一行字符串 = "数据已清理-----------------------------\r\n";
	m_edt1_cstr = 一行字符串;
	UpdateData(false); //将字符串写入到窗口
}
