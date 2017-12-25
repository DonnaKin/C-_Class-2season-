#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>

using namespace std;


class Student{
public:
	int nNo;
	char* szName;
	void SetStudent(int no, char* pName); //프로토타입
	void PrintStudent();

	static int getNCount(){//static이 아닐경우 getNCount(this) 임;
		//cout << nNo;//this로 접근하는 변수는 불가능 따라서 static만 가능

		return nCount;
	}

	Student();
	Student(int nNo, char *Name){
		nCount++;
		cout << nCount << " : 매개변수 있는 생성자" << endl;
		this->nNo = nNo;
		szName = new char[strlen(Name) + 1];
		strcpy(szName, Name);
	}
	~Student(){
		nCount--;
		if (szName != 0){
			cout << nCount << " : " << szName << "소멸자" << endl;
			delete[] szName;
		}
		else cout << nCount << " : 이름없음 소멸자" << endl;
	}

protected:
	static int nCount;//생성자에서만 쓸 것이므로 private으로 선언해도 됨

	
};
int Student::nCount = 0;

Student::Student(){
	nCount++;
	cout << nCount<<": 기본생성자" << endl;
	nNo = 0;
	//szName[0] = 0;
	szName = 0;
	//strcpy(szName, "이름없음");
}

void Student::SetStudent(int no, char* pName){
	(*this).nNo = no; //this->nNo = no;와 동일
	szName = new char[strlen(pName) + 1];
	strcpy(szName, pName);
}

void Student::PrintStudent(){
	if (szName != 0) cout << "번호 : " << nNo << ", 이름 : " << szName << endl;
	else cout << "번호 : " << nNo << endl;
}


int main(){

	//cout << Student::nCount;
	cout << Student::getNCount(); //getCount(); 를 호출

	Student stu = Student(2518, "임청");
	stu.PrintStudent();

	//cout << stu.nCount;
	cout << stu.getNCount();//getCount();가 비정적멤버함수이면 객체이름.getCount();는 자동으로 this를 넣어서 보내지만 정적멤버함수이면 자동으로 공유된 공간의 함수를 호출


	Student *p = new Student();//()를 써도 되고 안써도 됨.
	p->PrintStudent();
	//cout << p->nCount;
	cout << p->getNCount();

	delete p;
	return 0;
}