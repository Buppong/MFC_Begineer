
// CalAppDlg.cpp : 구현 파일
//

#include "stdafx.h" //자주 쓰이는 헤더들 여러 개를 한꺼번에 미리 컴파일 해놓아서 나중에 다시 컴파일하지 않고 그냥 다시 쓰겠다는 헤더이다. 
#include "CalApp.h" //앱성성으로 생긴 해더
#include "CalAppDlg.h" // 앱생성으로 생긴 다이얼로그 해더
#include "afxdialogex.h" //??
#define plu 1 //이게 그냥더하고 뺴기를 하면 더하고뺴지지가않아서 상수로 정의해야함.
#define sub 2 
#define mul 3 //일단따라하고있는데 #define으로 하면 효율이좀다른가? 일반 함수로선언했을떄와 차이점
#define div 4 


#ifdef _DEBUG //디버그 매크로 지원입니다.컴파일러가 기본적으로 지원되지않더라도 사용자가 만들어 사용할수있습니다.
#define new DEBUG_NEW //새로운디버그생성 define~~~이런식으로 설정할수있다.
#endif   // 디버그 지정끝


// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.

class CAboutDlg : public CDialogEx  // syntax class~:public CdialogEx는 배경색과 배경이미지를 정합니다.
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

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX) //:: scope 지정함수호출자 CaboutDlg에 있는 CAbutydig함수호출 
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CCalAppDlg 대화 상자



CCalAppDlg::CCalAppDlg(CWnd* pParent /*=NULL*/) //CCalapp다이얼로그앱안에 Cwnd윈도우함수앱으로 로딩한다는 뜻 
	: CDialogEx(IDD_CALAPP_DIALOG, pParent)  //
	, m_result(_T(""))
{



	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CCalAppDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX); //대화상자색체나 이런거 하는클래스
	//  DDX_Control(pDX, IDC_EDIT_RESULT, m_result);
	DDX_Text(pDX, m_result);
}

BEGIN_MESSAGE_MAP(CCalAppDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
END_MESSAGE_MAP()


// CCalAppDlg 메시지 처리기

BOOL CCalAppDlg::OnInitDialog()
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

	// TODO: 여기에 추가 초기화 작업을 추가합니다.

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
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

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 응용 프로그램의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CCalAppDlg::OnPaint()
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
HCURSOR CCalAppDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

