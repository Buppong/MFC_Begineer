
// CalAppDlg.cpp : ���� ����
//

#include "stdafx.h" //���� ���̴� ����� ���� ���� �Ѳ����� �̸� ������ �س��Ƽ� ���߿� �ٽ� ���������� �ʰ� �׳� �ٽ� ���ڴٴ� ����̴�. 
#include "CalApp.h" //�ۼ������� ���� �ش�
#include "CalAppDlg.h" // �ۻ������� ���� ���̾�α� �ش�
#include "afxdialogex.h" //??
#define plu 1 //�̰� �׳ɴ��ϰ� ���⸦ �ϸ� ���ϰ���������ʾƼ� ����� �����ؾ���.
#define sub 2 
#define mul 3 //�ϴܵ����ϰ��ִµ� #define���� �ϸ� ȿ�������ٸ���? �Ϲ� �Լ��μ����������� ������
#define div 4 


#ifdef _DEBUG //����� ��ũ�� �����Դϴ�.�����Ϸ��� �⺻������ ���������ʴ��� ����ڰ� ����� ����Ҽ��ֽ��ϴ�.
#define new DEBUG_NEW //���ο����׻��� define~~~�̷������� �����Ҽ��ִ�.
#endif   // ����� ������


// ���� ���α׷� ������ ���Ǵ� CAboutDlg ��ȭ �����Դϴ�.

class CAboutDlg : public CDialogEx  // syntax class~:public CdialogEx�� ������ ����̹����� ���մϴ�.
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

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX) //:: scope �����Լ�ȣ���� CaboutDlg�� �ִ� CAbutydig�Լ�ȣ�� 
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CCalAppDlg ��ȭ ����



CCalAppDlg::CCalAppDlg(CWnd* pParent /*=NULL*/) //CCalapp���̾�α׾۾ȿ� Cwnd�������Լ������� �ε��Ѵٴ� �� 
	: CDialogEx(IDD_CALAPP_DIALOG, pParent)  //
	, m_result(_T(""))
{



	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CCalAppDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX); //��ȭ���ڻ�ü�� �̷��� �ϴ�Ŭ����
	//  DDX_Control(pDX, IDC_EDIT_RESULT, m_result);
	DDX_Text(pDX, m_result);
}

BEGIN_MESSAGE_MAP(CCalAppDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
END_MESSAGE_MAP()


// CCalAppDlg �޽��� ó����

BOOL CCalAppDlg::OnInitDialog()
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

	// TODO: ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.

	return TRUE;  // ��Ŀ���� ��Ʈ�ѿ� �������� ������ TRUE�� ��ȯ�մϴ�.
}

void CCalAppDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CCalAppDlg::OnPaint()
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
HCURSOR CCalAppDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

