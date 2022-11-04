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

//MFC가 기본적으로 제공하는 코드


//////////////////프로그래머가 작성하는부분

class CMyopen:: public MFCOPEN {
public:
	virtual void Read();

};

void CMyOpen::Read() {

}