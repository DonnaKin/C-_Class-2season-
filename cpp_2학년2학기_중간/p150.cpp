
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
	Student(int, char*);//������Ÿ���� ������ ��� x,Ÿ�Ը� ����.
	~Student(){
		cout << szName << "�Ҹ���" << endl;
	}

};

Student::Student(){
	cout << "�⺻ ������" << endl;
	nNo = 0;
	szName="�̸�����";
}
Student::Student(int nNo, char *b){
	cout << "�Ű����� �ִ� ������" << endl;
	//nNo = nNo; //��������� �ʱ�ȭ�� �ȵ�.
	this->nNo = nNo; //this�� �������̱� ������ .�� �ƴ϶� ->
	//strcpy(szName, b);
	szName=b;
}

void Student::SetStudent(int no, char* pName){
	(*this).nNo = no;
	szName=pName;
}
void Student::PrintStudent(){
	cout << "��ȣ:" << nNo << ", �̸�:" << szName << endl;

}

int main(){
	Student student;
	
	int no;
	char name[20];
	cout << "�л� ��ȣ �Է� : ";
	cin >> no;
	cout << "�л� �̸� �Է� : ";
	cin >> name;
	
	student.SetStudent(no, name);

	student.PrintStudent();
	//cout << "sudent�� ������ : "<<sizeof(student)<<endl;//-->szName�� 
	cout << "sudent�� ������ : "<<sizeof(student)<<endl;

	Student stu = Student(2518, "��û");
	stu.PrintStudent();

	Student *p = new Student();
	p->PrintStudent(); //(p.PrintStudent()�� �ƴ�)


	Student *p1 = new Student(1111,"ȫ�浿");


	delete p;
	delete p1;

	return 0;

}
