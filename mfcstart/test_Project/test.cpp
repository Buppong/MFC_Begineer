#include<afxwin.h> //mfc���ø����̼ǿ� ���� ������Դϴ�. 



/*public, p,rivate, protected �Դϴ�. �̷��� ������ ��ür ���� ���α׷����� �߿��� �ڷ��� ���� �����Դϴ�.

*/

//�������α׷� Ŭ������ �����Ѵ�.
class ChelloApp : public CWinApp { //���Ŭ���� �Ļ�Ŭ���� ��ӵǾ����� �������� ���ٱ����� �����̵ȴ�.

public:
	virtual BOOL InitInstance();

};

class CMainFrame : public CFrameWnd
{
public:
	CMainFrame();

protected:
	afx_msg void OnPaint();
	afx_msg void OnButtonDown(UINT nFlags, CPoint point);
	DECLARE_MESSAGE_MAP();

};


//���� ���α׷� ��ü�� �����Ѵ�.
ChelloApp theApp;

//���������� Ŭ������ �����Ѵ�.
BOOL ChelloApp::InitInstance()
{

}
