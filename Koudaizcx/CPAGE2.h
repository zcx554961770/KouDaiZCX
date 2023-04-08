#pragma once


// CPAGE2 对话框

class CPAGE2 : public CDialogEx
{
	DECLARE_DYNAMIC(CPAGE2)

public:
	CPAGE2(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CPAGE2();

	// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG2 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	// //关联的控件变量
	CString m_edt1_cstr;
	afx_msg void OnBnClickedButton1();
	virtual LRESULT WindowProc(UINT message, WPARAM wParam, LPARAM lParam);
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedButton2();
};
