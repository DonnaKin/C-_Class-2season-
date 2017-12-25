#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

class Phone{
protected:
	char szNumber[20];

public:
	Phone(){
		cout << "Phone기본생성자" << endl;
		szNumber[0] = 0;
	}
	Phone(char* pszNumber){
		cout << "Phone매개변수생성자" << endl;
		strcpy(szNumber, pszNumber);
	}
	virtual ~Phone(){
		cout << "Phone소멸자" << endl;
	}
public:
	void SetNumber(char* pNo){
		strcpy(szNumber, pNo);
	}
	char* GetNumber(){
		return szNumber;
	}
	void Call(){
		cout << GetNumber() << "로 전화를 건다." << endl;
	}
	virtual void ShowInfo(){
		cout << "전화번호: " << GetNumber() << endl;
	}
};

class Camera{
public:
	Camera(){
		cout <<  "Camera생성자" << endl;
	}
	virtual ~Camera(){
		cout << "Camera소멸자" << endl;
	}
public:
	void Shutter(){
		cout << "사진을 찍는다" << endl;
	}
};

class MobilePhone : public Phone, public Camera{
public:
	MobilePhone(){
		cout << "MobilePhone 생성자 #1\n";
	}
	MobilePhone(char* pNumber) :Phone(pNumber){
		cout << "MobilePhone 생성자 #2\n";
	}
	virtual ~MobilePhone(){
		cout << "MobilePhone 소멸자" << endl;
	}
public:
	void ShowInfo(){
		Phone::ShowInfo();
		cout << "200만 화소 카메라!" << endl;
	}
};

int main(){
	Phone *p1 = new Phone();
	p1->Call();
	p1->GetNumber();
	p1->SetNumber("01032414875");
	p1->ShowInfo();
	//p1->Shutter();
	cout << "----------------------------------------" << endl;
	Phone *p2 = new MobilePhone();
	p2->Call();
	p2->GetNumber();
	p2->SetNumber("01032414875");
	p2->ShowInfo();
	//p2->Shutter();
	cout << "----------------------------------------" << endl;
	MobilePhone *m1 = new MobilePhone();
	m1->Call();
	m1->GetNumber();
	m1->SetNumber("01032414875");
	m1->ShowInfo();
	m1->Shutter();
	cout << "----------------------------------------" << endl;

	delete p1;
	delete p2;
	delete m1;
}