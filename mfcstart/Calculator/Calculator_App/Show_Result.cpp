// Show_Result.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "Calculator_App.h"
#include "Show_Result.h"
#include "afxdialogex.h"


// Show_Result ��ȭ �����Դϴ�.

IMPLEMENT_DYNAMIC(Show_Result, CDialogEx)

Show_Result::Show_Result(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_CALCULATOR_APP_DIALOG, pParent)
{

}

Show_Result::~Show_Result()
{
}

void Show_Result::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(Show_Result, CDialogEx)
END_MESSAGE_MAP()


// Show_Result �޽��� ó�����Դϴ�.
