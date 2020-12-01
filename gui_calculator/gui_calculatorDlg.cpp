#include "pch.h"
#include "framework.h"
#include "gui_calculator.h"
#include "gui_calculatorDlg.h"
#include "afxdialogex.h"
#include "string.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

	// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

   // Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CguicalculatorDlg dialog



CguicalculatorDlg::CguicalculatorDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_GUI_CALCULATOR_DIALOG, pParent)
	, m_resultText(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CguicalculatorDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_RESULT, m_resultText);
	DDX_Control(pDX, IDC_BUTTON_0, m_btn0);
	DDX_Control(pDX, IDC_BUTTON_1, m_btn1);
	DDX_Control(pDX, IDC_BUTTON_2, m_btn2);
	DDX_Control(pDX, IDC_BUTTON_3, m_btn3);
	DDX_Control(pDX, IDC_BUTTON_4, m_btn4);
	DDX_Control(pDX, IDC_BUTTON_5, m_btn5);
	DDX_Control(pDX, IDC_BUTTON_6, m_btn6);
	DDX_Control(pDX, IDC_BUTTON_7, m_btn7);
	DDX_Control(pDX, IDC_BUTTON_8, m_btn8);
	DDX_Control(pDX, IDC_BUTTON_9, m_btn9);

	DDX_Control(pDX, IDC_BUTTON_DIV, m_btnDiv);
	DDX_Control(pDX, IDC_BUTTON_MUL, m_btnMul);
	DDX_Control(pDX, IDC_BUTTON_PLUS, m_btnPlus);
	DDX_Control(pDX, IDC_BUTTON_MINUS, m_btnMinus);
	DDX_Control(pDX, IDC_BUTTON_EQUAL, m_btnEqual);
	DDX_Control(pDX, IDC_BUTTON_RESET, m_btnReset);

	DDX_Control(pDX, IDC_EDIT_RESULT, m_editResult);
}

BEGIN_MESSAGE_MAP(CguicalculatorDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_0, &CguicalculatorDlg::OnBnClickedButton0)
	ON_BN_CLICKED(IDC_BUTTON_1, &CguicalculatorDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON_2, &CguicalculatorDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON_3, &CguicalculatorDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON_4, &CguicalculatorDlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON_5, &CguicalculatorDlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON_6, &CguicalculatorDlg::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON_7, &CguicalculatorDlg::OnBnClickedButton7)
	ON_BN_CLICKED(IDC_BUTTON_8, &CguicalculatorDlg::OnBnClickedButton8)
	ON_BN_CLICKED(IDC_BUTTON_9, &CguicalculatorDlg::OnBnClickedButton9)
	ON_BN_CLICKED(IDC_BUTTON_RESET, &CguicalculatorDlg::OnBnClickedButtonReset)
	ON_BN_CLICKED(IDC_BUTTON_PLUS, &CguicalculatorDlg::OnBnClickedButtonPlus)
	ON_BN_CLICKED(IDC_BUTTON_EQUAL, &CguicalculatorDlg::OnBnClickedButtonEqual)
	ON_BN_CLICKED(IDC_BUTTON_MINUS, &CguicalculatorDlg::OnBnClickedButtonMinus)
	ON_BN_CLICKED(IDC_BUTTON_MUL, &CguicalculatorDlg::OnBnClickedButtonMul)
	ON_BN_CLICKED(IDC_BUTTON_DIV, &CguicalculatorDlg::OnBnClickedButtonDiv)
END_MESSAGE_MAP()


// CguicalculatorDlg message handlers

BOOL CguicalculatorDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);   // Set big icon
	SetIcon(m_hIcon, FALSE);  // Set small icon

	// TODO: Add extra initialization here
	m_font.CreateFont(32, 0, 0, 0, FW_BOLD, 0, 0, 0, DEFAULT_CHARSET, 0, 0, 0, 0,
		_T("Microsoft Sans Serif"));
	m_btn0.SetFont(&m_font);
	m_btn1.SetFont(&m_font);
	m_btn2.SetFont(&m_font);
	m_btn3.SetFont(&m_font);
	m_btn4.SetFont(&m_font);
	m_btn5.SetFont(&m_font);
	m_btn6.SetFont(&m_font);
	m_btn7.SetFont(&m_font);
	m_btn8.SetFont(&m_font);
	m_btn9.SetFont(&m_font);

	m_btnDiv.SetFont(&m_font);
	m_btnMul.SetFont(&m_font);
	m_btnPlus.SetFont(&m_font);
	m_btnMinus.SetFont(&m_font);
	m_btnEqual.SetFont(&m_font);
	m_btnReset.SetFont(&m_font);

	m_editResult.SetFont(&m_font);

	m_resultText = "0";
	m_firstNum = 0;
	m_secondNum = 0;
	m_opClicked = FALSE;
	UpdateData(FALSE);

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CguicalculatorDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CguicalculatorDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CguicalculatorDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}
CString add_thousnd_commas(CString n) {
	CString output;
	output += "";
	for (int i = n.GetLength() - 1; i >= 0; i--) {
		output = n[i] + output;
		if ((n.GetLength() - i) % 3 == 0 && ((i) != 0)) {
			output = ',' + output;
		}
	}
	return output;
}
CString convert_comma_num_to_normal(CString n) {
	CString output;
	output += "";
	for (int i = 0; i < n.GetLength(); i++) {
		if (n[i] != ',') {
			output += n[i];
		}
	}
	return output;
}

void CguicalculatorDlg::OnBnClickedButtonReset()
{
	m_resultText = "0";
	UpdateData(FALSE);
}


void CguicalculatorDlg::AddDigit(char digit) {
	UpdateData(TRUE);  // get the value from the edit control, and assign it to m_resultText

	if (m_resultText == '0' || m_opClicked) {
		m_resultText = digit;
		m_opClicked = FALSE;
	}
	else {

		// Mission: Add "," at every three digits
		CString ori = convert_comma_num_to_normal(m_resultText);
		ori += digit;
		m_resultText = add_thousnd_commas(ori);
	}

	UpdateData(FALSE); // send m_resultText to the edit control
}

void CguicalculatorDlg::OnBnClickedButton0()
{
	AddDigit('0');
}


void CguicalculatorDlg::OnBnClickedButton1()
{
	AddDigit('1');
}

void CguicalculatorDlg::OnBnClickedButton2()
{
	AddDigit('2');
}

void CguicalculatorDlg::OnBnClickedButton3()
{
	AddDigit('3');
}

void CguicalculatorDlg::OnBnClickedButton4()
{
	AddDigit('4');
}

void CguicalculatorDlg::OnBnClickedButton5()
{
	AddDigit('5');
}

void CguicalculatorDlg::OnBnClickedButton6()
{
	AddDigit('6');
}

void CguicalculatorDlg::OnBnClickedButton7()
{
	AddDigit('7');
}

void CguicalculatorDlg::OnBnClickedButton8()
{
	AddDigit('8');
}

void CguicalculatorDlg::OnBnClickedButton9()
{
	AddDigit('9');
}


void CguicalculatorDlg::OnBnClickedButtonPlus()
{
	UpdateData(TRUE); // get the value from the edit control
	m_firstNum = _tstof(convert_comma_num_to_normal(m_resultText));
	m_opClicked = TRUE;
	m_op = "+";
}

void CguicalculatorDlg::OnBnClickedButtonMinus()
{
	UpdateData(TRUE); // get the value from the edit control
	m_firstNum = _tstof(convert_comma_num_to_normal(m_resultText));
	m_opClicked = TRUE;
	m_op = "-";
}

void CguicalculatorDlg::OnBnClickedButtonMul()
{
	UpdateData(TRUE); // get the value from the edit control
	m_firstNum = _tstof(convert_comma_num_to_normal(m_resultText));
	m_opClicked = TRUE;
	m_op = "*";
}

void CguicalculatorDlg::OnBnClickedButtonDiv()
{
	UpdateData(TRUE); // get the value from the edit control
	m_firstNum = _tstof(convert_comma_num_to_normal(m_resultText));
	m_opClicked = TRUE;
	m_op = "/";
}


void CguicalculatorDlg::OnBnClickedButtonEqual()
{
	UpdateData(TRUE); // get the value from the edit control
	m_secondNum = _tstof(convert_comma_num_to_normal(m_resultText));
	double res;
	if (m_op == "+") {
		res = m_firstNum + m_secondNum;
	}
	else if (m_op == "-") {
		res = m_firstNum - m_secondNum;
	}
	else if (m_op == "*") {
		res = m_firstNum * m_secondNum;
	}
	else if (m_op == "/") {
		res = m_firstNum / m_secondNum;
	}
	m_resultText.Format(_T("%g"), res);
	m_resultText = add_thousnd_commas(m_resultText);
	UpdateData(FALSE); // send the update value to the edit control

	m_opClicked = FALSE;
}
 

/*
Homework
1. add "," at every three digits
2. working with all four different operators (+, -, x, /)
3. computing without pressing equal button (e.g. 1 + 2 + 3 = ?)
 current version: 1 + 2 = 3
*/


