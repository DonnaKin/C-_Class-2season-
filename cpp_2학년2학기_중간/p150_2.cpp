#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>

using namespace std;



class Student{
	int nNo;
	char* szName;
public:
	void SetStudent(int no, char* pName); //������Ÿ��
	void PrintStudent();
	Student();
	Student(int nNo, char *Name){
		cout << "�Ű����� �ִ� ������" << endl;
		this->nNo = nNo;
		szName = new char[strlen(Name)+1];
		strcpy(szName, Name);
	}
	~Student(){
		if (szName != 0){
			cout << szName << "�Ҹ���" << endl;
			delete[] szName;
		}
		else cout << "�̸����� �Ҹ���" << endl;
	}
};

Student::Student(){
	cout << "�⺻������" << endl;
	nNo = 0;
	//szName[0] = 0;
	szName = 0;
	//strcpy(szName, "�̸�����");
}

void Student::SetStudent(int no, char* pName){
	(*this).nNo = no; //this->nNo = no;�� ����
	szName = new char[strlen(pName) + 1];
	strcpy(szName, pName);
}

void Student::PrintStudent(){
	if (szName != 0) cout << "��ȣ : " << nNo << ", �̸� : " << szName << endl;
	else cout << "��ȣ : " << nNo << endl;
}




int main(){
	int no;
	char name[20];
	Student student;


	cout << sizeof(Student) << endl;

	cout << "�л� ��ȣ �Է�: ";
	cin >> no;
	cout << "�л� �̸� �Է�: ";
	cin >> name;
	student.SetStudent(no, name);
	student.PrintStudent();
	//	Student stu;

	Student stu = Student(2518, "��û");
	stu.PrintStudent();

	Student *p = new Student();//()�� �ᵵ �ǰ� �Ƚᵵ ��.
	p->PrintStudent();

	Student *p1 = new Student(1111, "ȫ�浿");
	p1->PrintStudent();

	delete p;
	delete p1;
	return 0;
}