
// CalAppCloneDlg.cpp : 구현 파일
//

#include "stdafx.h"
#include "CalAppClone.h"
#include "CalAppCloneDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

	// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

// 구현입니다.
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


// CCalAppCloneDlg 대화 상자



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
	ON_BN_CLICKED(IDC_CLEAR_BTN, &CCalAppCloneDlg::OnBnClickedClearBtn) //함수썼을때 이거에 추가를해야실행이된다.
	ON_BN_CLICKED(IDC_OP_EQU_BTN, &CCalAppCloneDlg::OnBnClickedOpEquBtn)
	ON_BN_CLICKED(IDC_BACK_BTN, &CCalAppCloneDlg::OnBnClickedBackBtn)
END_MESSAGE_MAP()


// CCalAppCloneDlg 메시지 처리기

BOOL CCalAppCloneDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.

	// IDM_ABOUTBOX는 시스템 명령 범위에 있어야 합니다.
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

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.
	m_font.CreatePointFont(200, L"굴림");
	GetDlgItem(IDC_SHOW_NUM_EDIT)->SetFont(&m_font);
	SetDlgItemInt(IDC_SHOW_NUM_EDIT, 0); //버튼관련해서 설정하는 함수


// TODO: 여기에 추가 초기화 작업을 추가합니다.

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
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

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 응용 프로그램의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CCalAppCloneDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CCalAppCloneDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}




//확인버튼
void CCalAppCloneDlg::OnBnClickedOk()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	//CDialogEx::OnOK();
}


// 버튼그룹화
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
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
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



