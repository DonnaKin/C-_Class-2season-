#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

class Phone{
protected:
	char szNumber[20];

public:
	Phone(){
		cout << "Phone�⺻������" << endl;
		szNumber[0] = 0;
	}
	Phone(char* pszNumber){
		cout << "Phone�Ű�����������" << endl;
		strcpy(szNumber, pszNumber);
	}
	virtual ~Phone(){
		cout << "Phone�Ҹ���" << endl;
	}
public:
	void SetNumber(char* pNo){
		strcpy(szNumber, pNo);
	}
	char* GetNumber(){
		return szNumber;
	}
	void Call(){
		cout << GetNumber() << "�� ��ȭ�� �Ǵ�." << endl;
	}
	virtual void ShowInfo(){
		cout << "��ȭ��ȣ: " << GetNumber() << endl;
	}
};

class Camera{
public:
	Camera(){
		cout <<  "Camera������" << endl;
	}
	virtual ~Camera(){
		cout << "Camera�Ҹ���" << endl;
	}
public:
	void Shutter(){
		cout << "������ ��´�" << endl;
	}
};

class MobilePhone : public Phone, public Camera{
public:
	MobilePhone(){
		cout << "MobilePhone ������ #1\n";
	}
	MobilePhone(char* pNumber) :Phone(pNumber){
		cout << "MobilePhone ������ #2\n";
	}
	virtual ~MobilePhone(){
		cout << "MobilePhone �Ҹ���" << endl;
	}
public:
	void ShowInfo(){
		Phone::ShowInfo();
		cout << "200�� ȭ�� ī�޶�!" << endl;
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