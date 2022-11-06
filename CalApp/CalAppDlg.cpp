
// CalAppDlg.cpp : 구현 파일
//

#include "stdafx.h" //자주 쓰이는 헤더들 여러 개를 한꺼번에 미리 컴파일 해놓아서 나중에 다시 컴파일하지 않고 그냥 다시 쓰겠다는 헤더이다. 
#include "CalApp.h" //  해당 응용 프로그램의 기본 헤더 파일입니다.
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
	virtual void DoDataExchange(CDataExchange* pDX);   /* 다이얼로그 기반으로 컨트롤을 변수로 사용하고 싶다면 변수와 컨트롤 사이엥 주고값는 값이 일어나야한다.dataexchange의 줄임말로 dodataexchange함수다값을교환한다. CDataExchange DDV데이터유효검사를한다.	   */


// 구현입니다.
protected:
	DECLARE_MESSAGE_MAP() //메시지 맵이 클래스에서 메시지를 함수에 매핑하는 데 사용됨을 선언합니다(클래스 선언에 사용해야 합니다).
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX) //:: scope 지정함수호출자 CaboutDlg에 있는 CAbutydig함수호출 
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)//메시지 맵의 정의를 시작합니다(클래스 구현에서 사용해야 합니다).
END_MESSAGE_MAP() //메시지 맵의 정의를 종료합니다(클래스 구현에서 사용해야 합니다)



// CCalAppDlg 대화 상자



CCalAppDlg::CCalAppDlg(CWnd* pParent /*=NULL*/) //CCalapp다이얼로그앱안에 Cwnd윈도우함수앱으로 로딩한다는 뜻 
	: CDialogEx(IDD_CALAPP_DIALOG, pParent)  //
	, m_result(_T(""))
	, Result_View(_T(""))
{



	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_bEqulClk = false; //'='클릭 생성자함수 초기화
}

void CCalAppDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX); //대화상자색체나 이런거 하는클래스
									//  DDX_Control(pDX, IDC_EDIT_RESULT, m_result);

	DDX_Text(pDX, IDC_EDIT_RESULT, Result_View);
}

BEGIN_MESSAGE_MAP(CCalAppDlg, CDialogEx) //메시지맵을 설정합니다.
	ON_WM_SYSCOMMAND() //사용자메시지등록
	ON_WM_PAINT() //     이미정의된메시지를 처리해야함         
	ON_WM_QUERYDRAGICON() //최소화된(아이콘적인) 창으로 전송됩니다. 사용자가 창을 끌려고 하지만 해당 클래스에 대해 정의된 아이콘이 없습니다. 응용 프로그램은 아이콘이나 커서에 대한 핸들을 반환할 수 있습니다. 시스템은 사용자가 아이콘을 끄는 동안 이 커서 또는 아이콘을 표시합니다.
	ON_BN_CLICKED(IDC_BUTTON_0, &CCalAppDlg::OnBnClickedButton0) // 컨트롤을 눌러서 WM_COMMAND 메시지가 발생하였다면 IPram 변수에는 이메시지를 발생한 컨트롤 HWND값이 저장됩니다.
	ON_BN_CLICKED(IDC_BUTTON_1, &CCalAppDlg::OnBnClickedButton1) // 버튼은 사실 wm_command가 발생하고 이메시지와 함께 상위16비트 하위 16비트 iparam버튼의핸들값에 전달이됩니다. On_Control 으로바꿔줘도됩니다.
	ON_BN_CLICKED(IDC_BUTTON_3, &CCalAppDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON_4, &CCalAppDlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON_5, &CCalAppDlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON_6, &CCalAppDlg::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON_7, &CCalAppDlg::OnBnClickedButton7)
	ON_BN_CLICKED(IDC_BUTTON_8, &CCalAppDlg::OnBnClickedButton8)
	ON_BN_CLICKED(IDC_BUTTON_9, &CCalAppDlg::OnBnClickedButton9)
	ON_BN_CLICKED(IDC_BUTTON_10, &CCalAppDlg::OnBnClickedButton10)
	ON_BN_CLICKED(IDC_BUTTON_11, &CCalAppDlg::OnBnClickedButton11)
	ON_BN_CLICKED(IDC_BUTTON_12, &CCalAppDlg::OnBnClickedButton12)
	ON_BN_CLICKED(IDC_BUTTON_13, &CCalAppDlg::OnBnClickedButton13)
	ON_BN_CLICKED(IDC_BUTTON_14, &CCalAppDlg::OnBnClickedButton14)
	ON_BN_CLICKED(IDC_BUTTON_15, &CCalAppDlg::OnBnClickedButton15)
	ON_BN_CLICKED(IDC_BUTTON_16, &CCalAppDlg::OnBnClickedButton16)
	ON_BN_CLICKED(IDC_BUTTON_17, &CCalAppDlg::OnBnClickedButton17)
	ON_BN_CLICKED(IDC_BUTTON_18, &CCalAppDlg::OnBnClickedButton18)
	ON_BN_CLICKED(IDC_BUTTON_19, &CCalAppDlg::OnBnClickedButton19)
	ON_EN_CHANGE(IDC_EDIT_RESULT, &CCalAppDlg::OnEnChangeEditResult)
END_MESSAGE_MAP()


// CCalAppDlg 메시지 처리기

BOOL CCalAppDlg::OnInitDialog() //다이얼로그 초기화 함수
{
	CDialogEx::OnInitDialog(); //

	// 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.

	// IDM_ABOUTBOX는 시스템 명령 범위에 있어야 합니다.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX); //디버깅모드에서 조건에 대한 검증을 위해서 사용합니다. assert(조건) //0xFFF0런타임오류?
	ASSERT(IDM_ABOUTBOX < 0xF000); //  16진수  0xf000보다 작다

	CMenu* pSysMenu = GetSystemMenu(FALSE); //응용프로그램이 복사수정을 위해 메뉴에 액세스할수있도록합니다.
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX); //어플리케이션의 문자열 리소르를 가져다쓰려면 LoadString을 호출해야합니다.
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);//appendMenu지정된 메뉴 모음 드롭다운메뉴 하위메뉴 바로가기 메뉴의끝에 새항목을 추가합니다. 이기능을사용하여 메뉴항목의 내용 ,모양 동작을 지정할수있습니다. MF_SEPARATOR 구분선입니다.
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다.
	CString str = L"";
	str.Format(_T("계산기"));
	SetWindowText(str);

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
		// WM_ICONERASEBKGND 메시지 최소화 된 창으로 보내집니다 ,

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON); // 
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




//계산기 버튼관련된 코드

void CCalAppDlg::OnBnClickedButton0()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	if (m_bEqulClk) {
		m_result.Empty();
		m_bEqulClk = false;
	}

	m_result += _T("0"); //문자 0기억
	UpdateData(false); //변수에있는것을 컨트롤에 대입(화면출력)

}


void CCalAppDlg::OnBnClickedButton1()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	if (m_bEqulClk) {
		m_result.Empty();
		m_bEqulClk = false;
	}

	m_result += _T("."); //문자 0기억
	UpdateData(false); //변수에있는것을 컨트롤에 대입(화면출력)
}


void CCalAppDlg::OnBnClickedButton3()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	double op1, op2, result;

	op1 = _tstof(m_buf); //변환하는명령어
	op2 = _tstof(m_result);

	switch (m_cType)
	{

	case plu:
		result = op1 + op2; //더하기
		break;
	case mul:
		result = op1 * op2;
	case div:
		result = op1 / op2;
		break;



	}

	m_result.Format(_T("%f"), result);
	UpdateData(false);
	m_bEqulClk = true;

}


void CCalAppDlg::OnBnClickedButton4()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	if (m_bEqulClk) {
		m_result.Empty();
		m_bEqulClk = false;
	}

	m_result += _T("1"); //문자 0기억
	UpdateData(false); //변수에있는것을 컨트롤에 대입(화면출력)
}


void CCalAppDlg::OnBnClickedButton5()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	if (m_bEqulClk) {
		m_result.Empty();
		m_bEqulClk = false;
	}

	m_result += _T("2"); //문자 0기억
	UpdateData(false); //변수에있는것을 컨트롤에 대입(화면출력)
}


void CCalAppDlg::OnBnClickedButton6()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.

	if (m_bEqulClk) {
		m_result.Empty();
		m_bEqulClk = false;
	}

	m_result += _T("03"); //문자 0기억
	UpdateData(false); //변수에있는것을 컨트롤에 대입(화면출력)
}


void CCalAppDlg::OnBnClickedButton7()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.

	if (m_bEqulClk) {
		m_result.Empty();
		m_bEqulClk = false;
	}

	m_result += _T("4"); //문자 0기억
	UpdateData(false); //변수에있는것을 컨트롤에 대입(화면출력)
}


void CCalAppDlg::OnBnClickedButton8()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	if (m_bEqulClk) {
		m_result.Empty();
		m_bEqulClk = false;
	}

	m_result += _T("5"); //문자 0기억
	UpdateData(false); //변수에있는것을 컨트롤에 대입(화면출력)
}


void CCalAppDlg::OnBnClickedButton9()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CCalAppDlg::OnBnClickedButton10()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CCalAppDlg::OnBnClickedButton11()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CCalAppDlg::OnBnClickedButton12()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CCalAppDlg::OnBnClickedButton13()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CCalAppDlg::OnBnClickedButton14()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CCalAppDlg::OnBnClickedButton15()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}



//리셋버튼
void CCalAppDlg::OnBnClickedButton16()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	//m_result += T("");
	m_result.Empty();
	UpdateData(false); //변수 => 컨트롤에 출력
}


void CCalAppDlg::OnBnClickedButton17()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CCalAppDlg::OnBnClickedButton18()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CCalAppDlg::OnBnClickedButton19()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CCalAppDlg::OnEnChangeEditResult()
{
	// TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은
	// CDialogEx::OnInitDialog() 함수를 재지정 
	//하고 마스크에 OR 연산하여 설정된 ENM_CHANGE 플래그를 지정하여 CRichEditCtrl().SetEventMask()를 호출하지 않으면
	// 이 알림 메시지를 보내지 않습니다.

	// TODO:  여기에 컨트롤 알림 처리기 코드를 추가합니다.
}
