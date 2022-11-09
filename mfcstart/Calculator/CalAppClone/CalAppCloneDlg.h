
// CalAppCloneDlg.h : 헤더 파일
//

#pragma once


// CCalAppCloneDlg 대화 상자
class CCalAppCloneDlg : public CDialogEx
{

private:
	CFont m_font;
	char m_op_flag = 0;// 0-> 연산자 선택안함, 1 -> ADD ,2 ->SUB, 3 -> MUL ,4 -> DIV// 생성입니다.
	char m_reset_mode = 0;
	int m_first_num = 0;
public:
	CCalAppCloneDlg(CWnd* pParent = NULL);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CALAPPCLONE_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	void OnSetNum(UINT a_ctrl_id);
	void OnProcessOp(UINT a_ctrl_id);
	afx_msg void OnBnClickedClearBtn();
	afx_msg void OnBnClickedOpEquBtn();
	afx_msg void OnBnClickedBackBtn();
};
