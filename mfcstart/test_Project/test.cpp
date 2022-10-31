#include<afxwin.h> //mfc어플리케이션에 대한 주헤더입니다. 



/*public, p,rivate, protected 입니다. 이러한 개념은 객체r 지향 프로그래밍의 중요한 자료의 은폐 개념입니다.

*/

//응용프로그램 클래스를 선언한다.
class ChelloApp : public CWinApp { //상속클래스 파생클래스 상속되어지는 과정에서 접근권한이 변경이된다.

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


//응용 프로그램 객체를 선언한다.
ChelloApp theApp;

//응용프고르매 클래스를 정의한다.
BOOL ChelloApp::InitInstance()
{

}
