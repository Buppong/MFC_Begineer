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


/*
// �����Լ��� MFC�� ����Ǵ� ���

ex)

1. ����ڰ� ������ ������ �� �ֵ��� ���� ���̾�α� ���
2. ����ڰ� ������ �����ϸ� ������̾�α� �����ϰ� ���õ� ���� ����
3. ���� ���Ŀ� ���� �����͸� ������ �о�鿩 �޸𸮿� �ε�
4. ���µ� ������ �ݴ´�.
==> ���� ó���ص� ���� ��ƾ��??>

*/
