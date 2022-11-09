
// CalAppCloneDlg.h : ��� ����
//

#pragma once


// CCalAppCloneDlg ��ȭ ����
class CCalAppCloneDlg : public CDialogEx
{

private:
	CFont m_font;
	char m_op_flag = 0;// 0-> ������ ���þ���, 1 -> ADD ,2 ->SUB, 3 -> MUL ,4 -> DIV// �����Դϴ�.
	char m_reset_mode = 0;
	int m_first_num = 0;
public:
	CCalAppCloneDlg(CWnd* pParent = NULL);	// ǥ�� �������Դϴ�.

// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CALAPPCLONE_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV �����Դϴ�.


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
	afx_msg void OnBnClickedOk();
	void OnSetNum(UINT a_ctrl_id);
	void OnProcessOp(UINT a_ctrl_id);
	afx_msg void OnBnClickedClearBtn();
	afx_msg void OnBnClickedOpEquBtn();
	afx_msg void OnBnClickedBackBtn();
};
