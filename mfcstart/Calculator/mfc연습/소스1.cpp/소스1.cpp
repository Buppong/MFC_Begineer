#include<iostream>


using namespace std;


class Parent {

public:
	virtual void print() {
		cout << "�̰��� Parent�Դϴ�." << endl;
	}
};

class Child : public Parent {
public:
	virtual void print() {
		cout << "�̰��� ~~�Դϴ�" << endl;
	}
};


class Dot {
public: 
	virtual void Draw() { cout << "Dot...." << endl; }
	void ScreenPrint();
};

void Dot::ScreenPrint()
{
	Draw();
}

class Line :public Dot {
public:
	void Draw() { cout << "Line" << endl; }
};

void main() {

	Line line;
	line.ScreenPrint();
	line.Draw();

	Parent* p = new Parent;
	Child* c = new Child;

	p->print();
	p = c;
	p->print();
	
}

////MFC�� �⺻������ ���� = �����Լ��� ���� �����ʿ�
/*�����Լ���? �����Լ��� �θ�Ŭ�������� ��ӹ��� Ŭ�������� �������Ұ�����
����ϰ� �����س��� �Լ��Դϴ�. virtual�̶�� ���� �Լ��տ� �ٿ��� �����Ҽ�
������ �̷��� ������ �����Լ��� �Ļ�Ŭ�������� �������ϸ� ������ ���ǵǾ���
������� ��� ���Ӱ� ���ǵȳ����� ��ü�˴ϴ�.\

�����Լ��� ����ؾ��ϴ� ���� 
�����Ϸ��� �Լ��� ȣ���Ҷ� �ſ캹���� ������ ��ġ�Ե˴ϴ�. �׷��⿡ �����Ϸ��� �Լ��� ȣ���ϴ�
�ڵ�� ������ Ÿ�ӿ� �޸��ּҷ� ��ȯ��ŵ�ϴ�. �̰��� �������ε��̶���մϴ�. �Ϲ��Լ��� ���
��� �̷��� �������ε��� �ϰԵ˴ϴ� ������ �Ϲ��Լ��� �����ε��ϰ� �Ǹ� �������ε����� ����
������ �ɼ��ֽ��ϴ�. �����Լ��� �ƴ� ������ ��� �θ�Ŭ������ ��� �Լ��� ȣ���ҋ� �����Ϸ��� ����
Ÿ���� ���� ��Ÿ�Կ� �´� ����Լ��� ȣ���ϱ⶧���Դϴ�.

*/



