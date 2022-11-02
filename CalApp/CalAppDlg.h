
// CalAppDlg.h : 헤더 파일
//

#pragma once //winwm파일같은 라이브러리쓸때 쓰는것
#include "afxwin.h"


// CCalAppDlg 대화 상자
class CCalAppDlg : public CDialogEx
{
// 생성입니다.
public:
	CCalAppDlg(CWnd* pParent = NULL);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CALAPP_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.

public:
	CString m_buf; // editcontrol 문자 임시로기억하는 숫자멤버벼변수
	CString m_result; //에디트 컨트롤 변수
	bool m_bEqulClk;
	int m_cType;


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
	afx_msg void OnBnClickedButton();
//	CEdit m_result;
	CString m_result;
};
