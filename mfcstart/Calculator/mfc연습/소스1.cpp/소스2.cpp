#include <iostream>




class CMFCOPEN {

public:
	void FileOpen();
	char * GetFileName();
	virtual void Read(); //�ڽĿ����� �����ǵɼ��ִ�.
};


/*
void MFCOpen::Read() {
	?//�ƹ�ó���� ��������
}

*/

char* CMFCOPEN::GetFileName() {
	//������̾�α׸� ����ϰ�
	//����ڰ� ������ ���ϸ� ����
}


void CMFCOPEN::FileOpen() {

	char *strFileName;
	strFileName = GetFileName();
	Read(); // ���������� �дºκ�
}

//MFC�� �⺻������ �����ϴ� �ڵ�


//////////////////���α׷��Ӱ� �ۼ��ϴºκ�

class CMyopen:: public MFCOPEN {
public:
	virtual void Read();

};

void CMyOpen::Read() {

}