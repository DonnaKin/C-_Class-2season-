#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>

using namespace std;



class Student{
	int nNo;
	char* szName;
public:
	void SetStudent(int no, char* pName); //프로토타입
	void PrintStudent();
	Student();
	Student(int nNo, char *Name){
		cout << "매개변수 있는 생성자" << endl;
		this->nNo = nNo;
		szName = new char[strlen(Name)+1];
		strcpy(szName, Name);
	}
	~Student(){
		if (szName != 0){
			cout << szName << "소멸자" << endl;
			delete[] szName;
		}
		else cout << "이름없음 소멸자" << endl;
	}
};

Student::Student(){
	cout << "기본생성자" << endl;
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
	int no;
	char name[20];
	Student student;


	cout << sizeof(Student) << endl;

	cout << "학생 번호 입력: ";
	cin >> no;
	cout << "학생 이름 입력: ";
	cin >> name;
	student.SetStudent(no, name);
	student.PrintStudent();
	//	Student stu;

	Student stu = Student(2518, "임청");
	stu.PrintStudent();

	Student *p = new Student();//()를 써도 되고 안써도 됨.
	p->PrintStudent();

	Student *p1 = new Student(1111, "홍길동");
	p1->PrintStudent();

	delete p;
	delete p1;
	return 0;
}