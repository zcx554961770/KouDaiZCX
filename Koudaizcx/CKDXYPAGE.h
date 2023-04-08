#pragma once
#include"CPAGE2.h"
#include"CPAGE3.h"
// CKDXYPAGE 对话框

class CKDXYPAGE : public CDialogEx
{
	DECLARE_DYNAMIC(CKDXYPAGE)

public:
	CKDXYPAGE(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CKDXYPAGE();

	// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CPAGE2 m_page2;
	CPAGE3 m_page3;
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton5();
	afx_msg void OnBnClickedButton6();
	afx_msg void OnBnClickedButton7();
};
