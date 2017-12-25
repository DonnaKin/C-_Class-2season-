#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string.h>

using namespace std;

class Student{

	int nNo;
	char szName[20];
public:
	void SetStudent(int no, char* pName);
	void PrintStudent();

	Student();
	Student(int, char*);//프로토타입은 변수명 고려 x,타입만 본다.


};

Student::Student(){
	cout << "기본 생성자" << endl;
	nNo = 0;
	szName[0] = 0;
}
Student::Student(int nNo, char *b){
	cout << "매개변수 있는 생성자" << endl;
	nNo = nNo; //멤버변수에 초기화가 안됨.
	this->nNo = nNo; //this는 포인터이기 때문에 .이 아니라 ->
	strcpy(szName, b);

}

void Student::SetStudent(int no, char* pName){
	(*this).nNo = no;
	strcpy(szName, pName);
}
void Student::PrintStudent(){
	cout << "번호:" << nNo << ", 이름:" << szName << endl;

}

int main(){
	Student *p = new Student();
	p->PrintStudent(); //(p.PrintStudent()가 아님)

	delete p;
	
	return 0;

}
