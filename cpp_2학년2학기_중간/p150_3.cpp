#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>

using namespace std;


class Student{
public:
	int nNo;
	char* szName;
	void SetStudent(int no, char* pName); //������Ÿ��
	void PrintStudent();

	static int getNCount(){//static�� �ƴҰ�� getNCount(this) ��;
		//cout << nNo;//this�� �����ϴ� ������ �Ұ��� ���� static�� ����

		return nCount;
	}

	Student();
	Student(int nNo, char *Name){
		nCount++;
		cout << nCount << " : �Ű����� �ִ� ������" << endl;
		this->nNo = nNo;
		szName = new char[strlen(Name) + 1];
		strcpy(szName, Name);
	}
	~Student(){
		nCount--;
		if (szName != 0){
			cout << nCount << " : " << szName << "�Ҹ���" << endl;
			delete[] szName;
		}
		else cout << nCount << " : �̸����� �Ҹ���" << endl;
	}

protected:
	static int nCount;//�����ڿ����� �� ���̹Ƿ� private���� �����ص� ��

	
};
int Student::nCount = 0;

Student::Student(){
	nCount++;
	cout << nCount<<": �⺻������" << endl;
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

	//cout << Student::nCount;
	cout << Student::getNCount(); //getCount(); �� ȣ��

	Student stu = Student(2518, "��û");
	stu.PrintStudent();

	//cout << stu.nCount;
	cout << stu.getNCount();//getCount();�� ����������Լ��̸� ��ü�̸�.getCount();�� �ڵ����� this�� �־ �������� ��������Լ��̸� �ڵ����� ������ ������ �Լ��� ȣ��


	Student *p = new Student();//()�� �ᵵ �ǰ� �Ƚᵵ ��.
	p->PrintStudent();
	//cout << p->nCount;
	cout << p->getNCount();

	delete p;
	return 0;
}