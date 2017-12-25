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
	Student(int, char*);//������Ÿ���� ������ ��� x,Ÿ�Ը� ����.


};

Student::Student(){
	cout << "�⺻ ������" << endl;
	nNo = 0;
	szName[0] = 0;
}
Student::Student(int nNo, char *b){
	cout << "�Ű����� �ִ� ������" << endl;
	nNo = nNo; //��������� �ʱ�ȭ�� �ȵ�.
	this->nNo = nNo; //this�� �������̱� ������ .�� �ƴ϶� ->
	strcpy(szName, b);

}

void Student::SetStudent(int no, char* pName){
	(*this).nNo = no;
	strcpy(szName, pName);
}
void Student::PrintStudent(){
	cout << "��ȣ:" << nNo << ", �̸�:" << szName << endl;

}

int main(){
	Student *p = new Student();
	p->PrintStudent(); //(p.PrintStudent()�� �ƴ�)

	delete p;
	
	return 0;

}
