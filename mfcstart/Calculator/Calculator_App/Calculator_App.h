
// Calculator_App.h : PROJECT_NAME ���� ���α׷��� ���� �� ��� �����Դϴ�.
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"		// �� ��ȣ�Դϴ�.


// CCalculator_AppApp:
// �� Ŭ������ ������ ���ؼ��� Calculator_App.cpp�� �����Ͻʽÿ�.
//

class CCalculator_AppApp : public CWinApp
{
public:
	CCalculator_AppApp();

// �������Դϴ�.
public:
	virtual BOOL InitInstance();

// �����Դϴ�.

	DECLARE_MESSAGE_MAP()
};

extern CCalculator_AppApp theApp;