
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string.h>

using namespace std;

class Student{

	int nNo;
	char* szName=new char[20];
	//char szName[20];


public:
	void SetStudent(int no, char* pName);
	void PrintStudent();

	Student();
	Student(int, char*);//프로토타입은 변수명 고려 x,타입만 본다.
	~Student(){
		cout << szName << "소멸자" << endl;
	}

};

Student::Student(){
	cout << "기본 생성자" << endl;
	nNo = 0;
	szName="이름없음";
}
Student::Student(int nNo, char *b){
	cout << "매개변수 있는 생성자" << endl;
	//nNo = nNo; //멤버변수에 초기화가 안됨.
	this->nNo = nNo; //this는 포인터이기 때문에 .이 아니라 ->
	//strcpy(szName, b);
	szName=b;
}

void Student::SetStudent(int no, char* pName){
	(*this).nNo = no;
	szName=pName;
}
void Student::PrintStudent(){
	cout << "번호:" << nNo << ", 이름:" << szName << endl;

}

int main(){
	Student student;
	
	int no;
	char name[20];
	cout << "학생 번호 입력 : ";
	cin >> no;
	cout << "학생 이름 입력 : ";
	cin >> name;
	
	student.SetStudent(no, name);

	student.PrintStudent();
	//cout << "sudent의 사이즈 : "<<sizeof(student)<<endl;//-->szName이 
	cout << "sudent의 사이즈 : "<<sizeof(student)<<endl;

	Student stu = Student(2518, "임청");
	stu.PrintStudent();

	Student *p = new Student();
	p->PrintStudent(); //(p.PrintStudent()가 아님)


	Student *p1 = new Student(1111,"홍길동");


	delete p;
	delete p1;

	return 0;

}
