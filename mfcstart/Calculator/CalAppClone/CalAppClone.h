
// CalAppClone.h : PROJECT_NAME ���� ���α׷��� ���� �� ��� �����Դϴ�.
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"		// �� ��ȣ�Դϴ�.


// CCalAppCloneApp:
// �� Ŭ������ ������ ���ؼ��� CalAppClone.cpp�� �����Ͻʽÿ�.
//

class CCalAppCloneApp : public CWinApp
{
public:
	CCalAppCloneApp();

// �������Դϴ�.
public:
	virtual BOOL InitInstance();

// �����Դϴ�.

	DECLARE_MESSAGE_MAP()
};

extern CCalAppCloneApp theApp;