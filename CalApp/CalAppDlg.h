
// CalAppDlg.h : ��� ����
//

#pragma once //winwm���ϰ��� ���̺귯������ ���°�
#include "afxwin.h"


// CCalAppDlg ��ȭ ����
class CCalAppDlg : public CDialogEx
{
// �����Դϴ�.
public:
	CCalAppDlg(CWnd* pParent = NULL);	// ǥ�� �������Դϴ�.

// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CALAPP_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV �����Դϴ�.

public:
	CString m_buf; // editcontrol ���� �ӽ÷α���ϴ� ���ڸ��������
	CString m_result; //����Ʈ ��Ʈ�� ����
	bool m_bEqulClk;
	int m_cType;


// �����Դϴ�.
protected:
	HICON m_hIcon;

	// ������ �޽��� �� �Լ�
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
