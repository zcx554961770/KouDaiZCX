// CPAGE3.cpp: 实现文件
//

#include "pch.h"
#include "Koudaizcx.h"
#include "CPAGE3.h"
#include "afxdialogex.h"


// CPAGE3 对话框

IMPLEMENT_DYNAMIC(CPAGE3, CDialogEx)

CPAGE3::CPAGE3(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG3, pParent)
	, m_edt1_cstr(_T("0x00", "0x00"))
	, m_buflen(2)
{

}

CPAGE3::~CPAGE3()
{
}

void CPAGE3::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_edt1_cstr);
	DDX_Text(pDX, IDC_EDIT2, m_buflen);
}


BEGIN_MESSAGE_MAP(CPAGE3, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &CPAGE3::OnBnClickedButton1)
END_MESSAGE_MAP()


// CPAGE3 消息处理程序

void 组包(BYTE* 数组, DWORD m_buflen)
{
	UINT_PTR pcall_明文包 = (UINT_PTR)0x0067D4E0;
	__asm
	{
		push m_buflen
		push 数组
		mov eax, dword ptr ds : [0x00D0DF1C]
		mov ecx, dword ptr ds : [eax + 0x20]
		call pcall_明文包
	}
	// _try except(1)
}
void CPAGE3::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(true);//表示把窗口上的数据 同步到关联变量
	OUT BYTE 数组[2048] = { 0 };
	字符串转字节数组(m_edt1_cstr.GetBuffer()/*包内容字符串*/, 数组/*包内容字节数组*/, m_buflen/*包长*/);
	组包(数组, m_buflen);
}
