// Show_Result.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "Calculator_App.h"
#include "Show_Result.h"
#include "afxdialogex.h"


// Show_Result 대화 상자입니다.

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


// Show_Result 메시지 처리기입니다.
