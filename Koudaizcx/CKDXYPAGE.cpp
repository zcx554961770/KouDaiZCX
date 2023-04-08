// CKDXYPAGE.cpp: 实现文件
//

#include "pch.h"
#include "Koudaizcx.h"
#include "CKDXYPAGE.h"
#include "afxdialogex.h"
#include "HOOK_BUF.h"

// CKDXYPAGE 对话框

IMPLEMENT_DYNAMIC(CKDXYPAGE, CDialogEx)

CKDXYPAGE::CKDXYPAGE(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG1, pParent)
{

}

CKDXYPAGE::~CKDXYPAGE()
{
}

void CKDXYPAGE::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CKDXYPAGE, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &CKDXYPAGE::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CKDXYPAGE::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CKDXYPAGE::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &CKDXYPAGE::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON5, &CKDXYPAGE::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON6, &CKDXYPAGE::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON7, &CKDXYPAGE::OnBnClickedButton7)
	ON_BN_CLICKED(IDC_BUTTON8, &CKDXYPAGE::OnBnClickedButton8)
	ON_BN_CLICKED(IDC_BUTTON9, &CKDXYPAGE::OnBnClickedButton9)
END_MESSAGE_MAP()


// CKDXYPAGE 消息处理程序

//技能打坐
void CKDXYPAGE::OnBnClickedButton1()
{

	// TODO: 在此添加控件通知处理程序代码
	UINT_PTR pcall = 0x67D4E0;
	_asm {
		sub esp, 0x100
		mov esi, esp
		mov word ptr ds : [esi] , 0x2E    // 2E 2A 不同 
		mov eax, dword ptr ds : [0xD0DF1C]
		push 2
		push esi
		mov ecx, dword ptr ds : [eax + 0x20]
		call pcall
		add esp, 0x100
	}
	::MessageBoxA(0, "调用打坐技能", "OK", MB_OK);
}

//取消打坐
void CKDXYPAGE::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	UINT_PTR pcall = 0x67D4E0;
	_asm {
		sub esp, 0x100
		mov esi, esp
		mov word ptr ds : [esi] , 0x2A    // 2E 2A 不同 
		mov eax, dword ptr ds : [0xD0DF1C]
		push 2
		push esi
		mov ecx, dword ptr ds : [eax + 0x20]
		call pcall
		add esp, 0x100
	}
	::MessageBoxA(0, "调用取消打坐技能", "OK", MB_OK);
}

//显示控制台
void CKDXYPAGE::OnBnClickedButton3()
{
	// TODO: 在此添加控件通知处理程序代码
	AllocConsole();//显示控制台
	FILE* file = 0;
	freopen_s(&file, "CONOUT$", "w+t", stdout);

}

//naked_Hook取包内容
void CKDXYPAGE::OnBnClickedButton4()
{
	printf("Hook取包内容 地址=%p\n", Hook取包内容);
	//naked_Hook取包内容
	printf("naked_Hook取包内容 地址=%p\n", naked_Hook取包内容);
}

//hook明文包
void CKDXYPAGE::OnBnClickedButton5()
{
	// TODO: 在此添加控件通知处理程序代码
	//目标地址 = 当前指令地址 + 指令长度 + 偏移量
	//偏移量 = 目标地址 - 当前指令地址 - 指令长度;
	//计算当前要写入的偏移量
	MessageBeep(1);
	DWORD  目标地址 = (DWORD)naked_Hook取包内容;// 0x79835844;  naked_Hook取包内容
	DWORD  偏移量 = 目标地址 - 0x0067D4E7 - 5;//79EB2D30
	//E9+偏移量
	if (R1(0x0067D4E7) != 0xE9) //
	{//没有被HOOK过
	 //写入E9 写入偏移量 写入长度5字节
		BYTE 五字节jmp机器码[5] = { 0xE9,0,0,0,0 };
		W4((UINT_PTR)五字节jmp机器码 + 1, 偏移量); // 0xE9 80 17 15 63
		BYTE* 地址 = (BYTE*)0x0067D4E7; // 当前指令地址

		DWORD 内存页面属性 = PAGE_EXECUTE_READWRITE; //内存页面属性 标记为 可执行EXECUTE 可读READ 可写WRITE
		DWORD 原来的内存页面属性 = 0;
		VirtualProtect(地址, 5, 内存页面属性, &原来的内存页面属性);  //改写页面属性
	  //  memcpy_s(地址, 5, 五字节jmp机器码, 5); //可以写了
		{
			地址[0] = 五字节jmp机器码[0];
			地址[1] = 五字节jmp机器码[1];
			地址[2] = 五字节jmp机器码[2];
			地址[3] = 五字节jmp机器码[3];
			地址[4] = 五字节jmp机器码[4];

		}
		VirtualProtect(地址, 5, 原来的内存页面属性, &原来的内存页面属性); //还原页面属性

	}
}


void CKDXYPAGE::OnBnClickedButton6()
{
	// TODO: 在此添加控件通知处理程序代码
	m_page2.DoModal();//模态
	//m_page1.ShowWindow(SW_SHOW); //非模态
}


void CKDXYPAGE::OnBnClickedButton7()
{
	// TODO: 在此添加控件通知处理程序代码
	m_page3.DoModal();//模态
	//m_page1.ShowWindow(SW_SHOW); //非模态
}

#include"MonsterList.h"
void CKDXYPAGE::OnBnClickedButton8()
{
	// TODO: 在此添加控件通知处理程序代码
		//MonsterList a;
	//a.遍历数组();
	MonsterList::遍历数组();
}


void CKDXYPAGE::OnBnClickedButton9()
{
	// TODO: 在此添加控件通知处理程序代码
	//目标地址 = 当前指令地址 + 指令长度 + 偏移量
	//偏移量 = 目标地址 - 当前指令地址 - 指令长度;
	//计算当前要写入的偏移量
	MessageBeep(1);
	DWORD  目标地址 = (DWORD)naked_Hook取包内容;// 0x79835844;  naked_Hook取包内容
	DWORD  偏移量 = 目标地址 - 0x0067D4E7 - 5;//79EB2D30
	//E9+偏移量
	if (R1(0x0067D4E7) == 0xE9) //
	{//没有被HOOK过
	 //写入E9 写入偏移量 写入长度5字节
		BYTE 五字节jmp机器码[5] = { 0x64,0xA1,0,0,0 };

		BYTE* 地址 = (BYTE*)0x0067D4E7; // 当前指令地址

		DWORD 内存页面属性 = PAGE_EXECUTE_READWRITE; //内存页面属性 标记为 可执行EXECUTE 可读READ 可写WRITE
		DWORD 原来的内存页面属性 = 0;
		VirtualProtect(地址, 5, 内存页面属性, &原来的内存页面属性);  //改写页面属性
	  //  memcpy_s(地址, 5, 五字节jmp机器码, 5); //可以写了
		{
			地址[0] = 五字节jmp机器码[0];
			地址[1] = 五字节jmp机器码[1];
			地址[2] = 五字节jmp机器码[2];
			地址[3] = 五字节jmp机器码[3];
			地址[4] = 五字节jmp机器码[4];

		}
		VirtualProtect(地址, 5, 原来的内存页面属性, &原来的内存页面属性); //还原页面属性

	}
}
