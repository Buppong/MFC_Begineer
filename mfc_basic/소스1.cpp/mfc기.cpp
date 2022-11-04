#include <afxwin.h>


class CHelloApp : public CWinApp {

public:
	virtual BOOL InitInstacne()
	{
		AfxMessageBox("Hello ,MFC");
		return FALSE;
		
	}
	virtual int ExitInstacne() {
		AfxMessageBox("ExitInstance");
		return CWinApp::ExitInstance();
	}
};

CHelloApp theApp;