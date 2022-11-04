#include <iostream>




class CMFCOPEN {

public:
	void FileOpen();
	char * GetFileName();
	virtual void Read(); //자식에의해 재정의될수있다.
};


/*
void MFCOpen::Read() {
	?//아무처리를 하지않음
}

*/

char* CMFCOPEN::GetFileName() {
	//열기다이얼로그를 출력하고
	//사용자가 선택한 파일명 리턴
}


void CMFCOPEN::FileOpen() {

	char *strFileName;
	strFileName = GetFileName();
	Read(); // 실제파일을 읽는부분
}


/*
// 가상함수가 MFC에 적용되는 방식

ex)

1. 사용자가 파일을 선택할 수 있도록 열기 다이얼로그 출력
2. 사용자가 파일을 선택하면 열기다이얼로그 종료하고 선택된 파일 오픈
3. 파일 형식에 따라 데이터를 적절히 읽어들여 메모리에 로드
4. 오픈된 파일을 닫는다.
==> 누가 처리해도 동일 루틴은??>

*/
