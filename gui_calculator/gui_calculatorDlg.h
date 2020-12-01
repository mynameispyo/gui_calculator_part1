// gui_calculatorDlg.h : header file
//

#pragma once


// CguicalculatorDlg dialog
class CguicalculatorDlg : public CDialogEx
{
	// Construction
public:
	CguicalculatorDlg(CWnd* pParent = nullptr); // standard constructor

   // Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_GUI_CALCULATOR_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX); // DDX/DDV support


   // Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton0();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton5();
	afx_msg void OnBnClickedButton6();
	afx_msg void OnBnClickedButton7();
	afx_msg void OnBnClickedButton8();
	afx_msg void OnBnClickedButton9();
	afx_msg void OnBnClickedButtonReset();

	afx_msg void OnBnClickedButtonPlus();

	void AddDigit(char digit);

private:
	CString m_resultText;
	CFont m_font;
	CButton m_btn0, m_btn1, m_btn2, m_btn3, m_btn4, m_btn5, m_btn6, m_btn7, m_btn8, m_btn9;
	CButton m_btnMul, m_btnDiv, m_btnPlus, m_btnMinus, m_btnEqual, m_btnReset;
	CEdit m_editResult;

	double m_firstNum;
	double m_secondNum;
	BOOL m_opClicked;
	CString m_op;

public:
	afx_msg void OnBnClickedButtonEqual();
	afx_msg void OnBnClickedButtonMinus();
	afx_msg void OnBnClickedButtonMul();
	afx_msg void OnBnClickedButtonDiv();
};
