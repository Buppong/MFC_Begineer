
// CalAppDlg.cpp : ���� ����
//

#include "stdafx.h" //���� ���̴� ����� ���� ���� �Ѳ����� �̸� ������ �س��Ƽ� ���߿� �ٽ� ���������� �ʰ� �׳� �ٽ� ���ڴٴ� ����̴�. 
#include "CalApp.h" //  �ش� ���� ���α׷��� �⺻ ��� �����Դϴ�.
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
	virtual void DoDataExchange(CDataExchange* pDX);   /* ���̾�α� ������� ��Ʈ���� ������ ����ϰ� �ʹٸ� ������ ��Ʈ�� ���̿� �ְ��� ���� �Ͼ���Ѵ�.dataexchange�� ���Ӹ��� dodataexchange�Լ��ٰ�����ȯ�Ѵ�. CDataExchange DDV��������ȿ�˻縦�Ѵ�.	   */


// �����Դϴ�.
protected:
	DECLARE_MESSAGE_MAP() //�޽��� ���� Ŭ�������� �޽����� �Լ��� �����ϴ� �� ������ �����մϴ�(Ŭ���� ���� ����ؾ� �մϴ�).
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX) //:: scope �����Լ�ȣ���� CaboutDlg�� �ִ� CAbutydig�Լ�ȣ�� 
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)//�޽��� ���� ���Ǹ� �����մϴ�(Ŭ���� �������� ����ؾ� �մϴ�).
END_MESSAGE_MAP() //�޽��� ���� ���Ǹ� �����մϴ�(Ŭ���� �������� ����ؾ� �մϴ�)



// CCalAppDlg ��ȭ ����



CCalAppDlg::CCalAppDlg(CWnd* pParent /*=NULL*/) //CCalapp���̾�α׾۾ȿ� Cwnd�������Լ������� �ε��Ѵٴ� �� 
	: CDialogEx(IDD_CALAPP_DIALOG, pParent)  //
	, m_result(_T(""))
	, Result_View(_T(""))
{



	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_bEqulClk = false; //'='Ŭ�� �������Լ� �ʱ�ȭ
}

void CCalAppDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX); //��ȭ���ڻ�ü�� �̷��� �ϴ�Ŭ����
									//  DDX_Control(pDX, IDC_EDIT_RESULT, m_result);

	DDX_Text(pDX, IDC_EDIT_RESULT, Result_View);
}

BEGIN_MESSAGE_MAP(CCalAppDlg, CDialogEx) //�޽������� �����մϴ�.
	ON_WM_SYSCOMMAND() //����ڸ޽������
	ON_WM_PAINT() //     �̹����ǵȸ޽����� ó���ؾ���         
	ON_WM_QUERYDRAGICON() //�ּ�ȭ��(����������) â���� ���۵˴ϴ�. ����ڰ� â�� ������ ������ �ش� Ŭ������ ���� ���ǵ� �������� �����ϴ�. ���� ���α׷��� �������̳� Ŀ���� ���� �ڵ��� ��ȯ�� �� �ֽ��ϴ�. �ý����� ����ڰ� �������� ���� ���� �� Ŀ�� �Ǵ� �������� ǥ���մϴ�.
	ON_BN_CLICKED(IDC_BUTTON_0, &CCalAppDlg::OnBnClickedButton0) // ��Ʈ���� ������ WM_COMMAND �޽����� �߻��Ͽ��ٸ� IPram �������� �̸޽����� �߻��� ��Ʈ�� HWND���� ����˴ϴ�.
	ON_BN_CLICKED(IDC_BUTTON_1, &CCalAppDlg::OnBnClickedButton1) // ��ư�� ��� wm_command�� �߻��ϰ� �̸޽����� �Բ� ����16��Ʈ ���� 16��Ʈ iparam��ư���ڵ鰪�� �����̵˴ϴ�. On_Control ���ιٲ��൵�˴ϴ�.
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


// CCalAppDlg �޽��� ó����

BOOL CCalAppDlg::OnInitDialog() //���̾�α� �ʱ�ȭ �Լ�
{
	CDialogEx::OnInitDialog(); //

	// �ý��� �޴��� "����..." �޴� �׸��� �߰��մϴ�.

	// IDM_ABOUTBOX�� �ý��� ��� ������ �־�� �մϴ�.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX); //������忡�� ���ǿ� ���� ������ ���ؼ� ����մϴ�. assert(����) //0xFFF0��Ÿ�ӿ���?
	ASSERT(IDM_ABOUTBOX < 0xF000); //  16����  0xf000���� �۴�

	CMenu* pSysMenu = GetSystemMenu(FALSE); //�������α׷��� ��������� ���� �޴��� �׼����Ҽ��ֵ����մϴ�.
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX); //���ø����̼��� ���ڿ� ���Ҹ��� �����پ����� LoadString�� ȣ���ؾ��մϴ�.
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);//appendMenu������ �޴� ���� ��Ӵٿ�޴� �����޴� �ٷΰ��� �޴��ǳ��� ���׸��� �߰��մϴ�. �̱��������Ͽ� �޴��׸��� ���� ,��� ������ �����Ҽ��ֽ��ϴ�. MF_SEPARATOR ���м��Դϴ�.
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// �� ��ȭ ������ �������� �����մϴ�.  ���� ���α׷��� �� â�� ��ȭ ���ڰ� �ƴ� ��쿡��
	//  �����ӿ�ũ�� �� �۾��� �ڵ����� �����մϴ�.
	SetIcon(m_hIcon, TRUE);			// ū �������� �����մϴ�.
	SetIcon(m_hIcon, FALSE);		// ���� �������� �����մϴ�.

	// TODO: ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
	CString str = L"";
	str.Format(_T("����"));
	SetWindowText(str);

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
		// WM_ICONERASEBKGND �޽��� �ּ�ȭ �� â���� �������ϴ� ,

		// Ŭ���̾�Ʈ �簢������ �������� ����� ����ϴ�.
		int cxIcon = GetSystemMetrics(SM_CXICON); // 
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




//���� ��ư���õ� �ڵ�

void CCalAppDlg::OnBnClickedButton0()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	if (m_bEqulClk) {
		m_result.Empty();
		m_bEqulClk = false;
	}

	m_result += _T("0"); //���� 0���
	UpdateData(false); //�������ִ°��� ��Ʈ�ѿ� ����(ȭ�����)

}


void CCalAppDlg::OnBnClickedButton1()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	if (m_bEqulClk) {
		m_result.Empty();
		m_bEqulClk = false;
	}

	m_result += _T("."); //���� 0���
	UpdateData(false); //�������ִ°��� ��Ʈ�ѿ� ����(ȭ�����)
}


void CCalAppDlg::OnBnClickedButton3()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	double op1, op2, result;

	op1 = _tstof(m_buf); //��ȯ�ϴ¸�ɾ�
	op2 = _tstof(m_result);

	switch (m_cType)
	{

	case plu:
		result = op1 + op2; //���ϱ�
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
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	if (m_bEqulClk) {
		m_result.Empty();
		m_bEqulClk = false;
	}

	m_result += _T("1"); //���� 0���
	UpdateData(false); //�������ִ°��� ��Ʈ�ѿ� ����(ȭ�����)
}


void CCalAppDlg::OnBnClickedButton5()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	if (m_bEqulClk) {
		m_result.Empty();
		m_bEqulClk = false;
	}

	m_result += _T("2"); //���� 0���
	UpdateData(false); //�������ִ°��� ��Ʈ�ѿ� ����(ȭ�����)
}


void CCalAppDlg::OnBnClickedButton6()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.

	if (m_bEqulClk) {
		m_result.Empty();
		m_bEqulClk = false;
	}

	m_result += _T("03"); //���� 0���
	UpdateData(false); //�������ִ°��� ��Ʈ�ѿ� ����(ȭ�����)
}


void CCalAppDlg::OnBnClickedButton7()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.

	if (m_bEqulClk) {
		m_result.Empty();
		m_bEqulClk = false;
	}

	m_result += _T("4"); //���� 0���
	UpdateData(false); //�������ִ°��� ��Ʈ�ѿ� ����(ȭ�����)
}


void CCalAppDlg::OnBnClickedButton8()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	if (m_bEqulClk) {
		m_result.Empty();
		m_bEqulClk = false;
	}

	m_result += _T("5"); //���� 0���
	UpdateData(false); //�������ִ°��� ��Ʈ�ѿ� ����(ȭ�����)
}


void CCalAppDlg::OnBnClickedButton9()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
}


void CCalAppDlg::OnBnClickedButton10()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
}


void CCalAppDlg::OnBnClickedButton11()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
}


void CCalAppDlg::OnBnClickedButton12()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
}


void CCalAppDlg::OnBnClickedButton13()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
}


void CCalAppDlg::OnBnClickedButton14()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
}


void CCalAppDlg::OnBnClickedButton15()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
}



//���¹�ư
void CCalAppDlg::OnBnClickedButton16()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	//m_result += T("");
	m_result.Empty();
	UpdateData(false); //���� => ��Ʈ�ѿ� ���
}


void CCalAppDlg::OnBnClickedButton17()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
}


void CCalAppDlg::OnBnClickedButton18()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
}


void CCalAppDlg::OnBnClickedButton19()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
}


void CCalAppDlg::OnEnChangeEditResult()
{
	// TODO:  RICHEDIT ��Ʈ���� ���, �� ��Ʈ����
	// CDialogEx::OnInitDialog() �Լ��� ������ 
	//�ϰ� ����ũ�� OR �����Ͽ� ������ ENM_CHANGE �÷��׸� �����Ͽ� CRichEditCtrl().SetEventMask()�� ȣ������ ������
	// �� �˸� �޽����� ������ �ʽ��ϴ�.

	// TODO:  ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
}
