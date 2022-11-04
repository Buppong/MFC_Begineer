#include<iostream>


using namespace std;


class Parent {

public:
	virtual void print() {
		cout << "이곳은 Parent입니다." << endl;
	}
};

class Child : public Parent {
public:
	virtual void print() {
		cout << "이곳은 ~~입니다" << endl;
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

////MFC의 기본구조의 이해 = 가상함수에 대한 이해필요
/*가상함수란? 가상함수는 부모클래스에서 상속받은 클래스에서 재정의할것으로
기대하고 정의해놓은 함수입니다. virtual이라는 예약어를 함수앞에 붙여서 생성할수
있으며 이렇게 생성된 가상함수는 파생클래스에서 재정의하면 이전에 정의되었던
내용들은 모두 새롭게 정의된내용들로 교체됩니다.\

가상함수를 사용해야하는 이유 
컴파일러는 함수를 호출할때 매우복잡한 과정을 거치게됩니다. 그렇기에 컴파일러는 함수를 호출하는
코드는 컴파일 타임에 메모리주소로 변환시킵니다. 이것을 정적바인딩이라고합니다. 일반함수의 경우
모두 이러한 정적바인딩을 하게됩니다 하지만 일반함수를 오버로딩하게 되면 정적바인딩으로 인해
문제가 될수있습니다. 강상함수가 아닌 보통의 경우 부모클래스형 멤버 함수를 호출할떄 컴파일러는 정적
타입을 보고 이타입에 맞는 멤버함수를 호출하기때문입니다.

*/



