#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string.h>

using namespace std;

struct Student{
	int nNo;
	char szName[20];
	void SetStudent(int no, char* pName);
	void PrintStudent();

	
};



void Student::SetStudent(int no, char* pName){
	(*this).nNo = no;
	strcpy(szName, pName); 
}
void Student::PrintStudent(){
	cout << "번호:" << nNo << ", 이름:" << szName << endl;

}

int main(){
	int no;
	char name[20];
	Student student;

	cout << "학생 번호 입력 : ";
	cin >>no;

	cout << "학생 이름 입력 : ";
	cin >> name;
	student.SetStudent(no, name);
	student.PrintStudent();

	student.nNo = 10;

	return 0;

}
