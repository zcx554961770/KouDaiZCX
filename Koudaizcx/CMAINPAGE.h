#pragma once

#include"CKDXYPAGE.h"
#include"CPAGE2.h"
#include"CPAGE3.h"
// CMAINPAGE 对话框

class CMAINPAGE : public CDialogEx
{
	DECLARE_DYNAMIC(CMAINPAGE)

public:
	CMAINPAGE(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CMAINPAGE();

	// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG4 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CTabCtrl m_tabpage;
	virtual BOOL OnInitDialog();
	afx_msg void OnTcnSelchangeTab1(NMHDR* pNMHDR, LRESULT* pResult);
	//初始三个窗口
	CKDXYPAGE m_page1;
	CPAGE2  m_page2;
	CPAGE3  m_page3;
};
