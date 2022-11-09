
// CalAppCloneDlg.cpp : ���� ����
//

#include "stdafx.h"
#include "CalAppClone.h"
#include "CalAppCloneDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ���� ���α׷� ������ ���Ǵ� CAboutDlg ��ȭ �����Դϴ�.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

	// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

// �����Դϴ�.
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


// CCalAppCloneDlg ��ȭ ����



CCalAppCloneDlg::CCalAppCloneDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_CALAPPCLONE_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CCalAppCloneDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CCalAppCloneDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDOK, &CCalAppCloneDlg::OnBnClickedOk)
	ON_COMMAND_RANGE(IDC_BUTTON0, IDC_BUTTON9, OnSetNum)
	ON_COMMAND_RANGE(IDC_OP_ADD, IDC_OP_DIV_BTN, OnProcessOp)
	ON_BN_CLICKED(IDC_CLEAR_BTN, &CCalAppCloneDlg::OnBnClickedClearBtn) //�Լ������� �̰ſ� �߰����ؾ߽����̵ȴ�.
	ON_BN_CLICKED(IDC_OP_EQU_BTN, &CCalAppCloneDlg::OnBnClickedOpEquBtn)
	ON_BN_CLICKED(IDC_BACK_BTN, &CCalAppCloneDlg::OnBnClickedBackBtn)
END_MESSAGE_MAP()


// CCalAppCloneDlg �޽��� ó����

BOOL CCalAppCloneDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// �ý��� �޴��� "����..." �޴� �׸��� �߰��մϴ�.

	// IDM_ABOUTBOX�� �ý��� ��� ������ �־�� �մϴ�.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
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

	// �� ��ȭ ������ �������� �����մϴ�.  ���� ���α׷��� �� â�� ��ȭ ���ڰ� �ƴ� ��쿡��
	//  �����ӿ�ũ�� �� �۾��� �ڵ����� �����մϴ�.
	SetIcon(m_hIcon, TRUE);			// ū �������� �����մϴ�.
	SetIcon(m_hIcon, FALSE);		// ���� �������� �����մϴ�.
	m_font.CreatePointFont(200, L"����");
	GetDlgItem(IDC_SHOW_NUM_EDIT)->SetFont(&m_font);
	SetDlgItemInt(IDC_SHOW_NUM_EDIT, 0); //��ư�����ؼ� �����ϴ� �Լ�


// TODO: ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.

	return TRUE;  // ��Ŀ���� ��Ʈ�ѿ� �������� ������ TRUE�� ��ȯ�մϴ�.
}

void CCalAppCloneDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// ��ȭ ���ڿ� �ּ�ȭ ���߸� �߰��� ��� �������� �׸�����
//  �Ʒ� �ڵ尡 �ʿ��մϴ�.  ����/�� ���� ����ϴ� MFC ���� ���α׷��� ��쿡��
//  �����ӿ�ũ���� �� �۾��� �ڵ����� �����մϴ�.

void CCalAppCloneDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // �׸��⸦ ���� ����̽� ���ؽ�Ʈ�Դϴ�.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Ŭ���̾�Ʈ �簢������ �������� ����� ����ϴ�.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// �������� �׸��ϴ�.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// ����ڰ� �ּ�ȭ�� â�� ���� ���ȿ� Ŀ���� ǥ�õǵ��� �ý��ۿ���
//  �� �Լ��� ȣ���մϴ�.
HCURSOR CCalAppCloneDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}




//Ȯ�ι�ư
void CCalAppCloneDlg::OnBnClickedOk()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	//CDialogEx::OnOK();
}


// ��ư�׷�ȭ
void CCalAppCloneDlg::OnSetNum(UINT a_ctrl_id)
{

	int num = GetDlgItemInt(IDC_SHOW_NUM_EDIT);

	if (m_reset_mode == 0) {
		SetDlgItemInt(IDC_SHOW_NUM_EDIT, num * 10 + a_ctrl_id - IDC_BUTTON0);
	}
	else {
		m_reset_mode = 0;
		SetDlgItemInt(IDC_SHOW_NUM_EDIT, a_ctrl_id - IDC_BUTTON0);
	}

}



void CCalAppCloneDlg::OnBnClickedClearBtn()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	SetDlgItemInt(IDC_SHOW_NUM_EDIT, 0);
}


void CCalAppCloneDlg::OnBnClickedOpEquBtn()
{
	int second_num = GetDlgItemInt(IDC_SHOW_NUM_EDIT);
	int result = 0;
	switch (m_op_flag)
	{
	case 1: //ADD
		result = m_first_num + second_num;
		break;
	case 2: //SUB
		result = m_first_num - second_num;
		break;
	case 3: //MUL
		result = m_first_num * second_num;
		break;
	case 4: //DIV
		if (second_num != 0) {
			result = m_first_num / second_num;
		}
		break;

	}
	SetDlgItemInt(IDC_SHOW_NUM_EDIT, result);
	
}


void CCalAppCloneDlg::OnProcessOp(UINT a_ctrl_id) {

	if (m_reset_mode == 0) {
		m_op_flag = a_ctrl_id - IDC_OP_ADD + 1;
		m_reset_mode = 1;
		m_first_num = GetDlgItemInt(IDC_SHOW_NUM_EDIT);
	}
}


void CCalAppCloneDlg::OnBnClickedBackBtn()
{
	int num = GetDlgItemInt(IDC_SHOW_NUM_EDIT);
	SetDlgItemInt(IDC_SHOW_NUM_EDIT, num / 10);

}



