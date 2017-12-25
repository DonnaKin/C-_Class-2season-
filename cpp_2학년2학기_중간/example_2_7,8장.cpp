#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

using namespace std;


class Student{
public:
	int nNo;
	char *szName;

	Student(){
		cout << "�⺻������" << endl;
		this->nNo = 0;
		this->szName = 0;
	}
	Student(int nNo, char *name){
		cout << "�Ű����� �ִ� ������" << endl;
		this->nNo = nNo;
		szName = new char[strlen(name) + 1];
		strcpy(this->szName, name);

	}
	Student(Student &st){
		cout << "�Ű����� �ִ� ������" << endl;
		this->nNo = st.nNo;
		szName = new char[strlen(st.szName) + 1];
		strcpy(this->szName, st.szName);
	}

	Student &operator=(Student &st){//call by reference  -->�Ҵ翬���� �ߺ�����(assign)
		cout << "���۷�����" << endl;
		if (this != &st){
			this->nNo = st.nNo;
			this->szName = new char[strlen(st.szName) + 1];
			strcpy(this->szName, st.szName);
		}
		return *this;
	}
	//Student &operator=(Student &st){//call by reference  -->�Ҵ翬���� �ߺ�����(assign)
	//	if (this != &st){
	//		this->nNo = st.nNo;
	//		this->szName = new char[strlen(st.szName) + 1];
	//		strcpy(this->szName, st.szName);
	//	}
	//	return *this;
	//}
	void printStudent(){
		if (szName != NULL)
			cout << "��ȣ : " << nNo << "\t�̸� : " << szName << endl;
		else
			cout << "��ȣ : " << nNo << "\t�̸� : ����" << endl;

	}
	~Student(){

		if (szName != NULL){
			cout << szName << "�Ҹ���" << endl;
			delete[] szName;
		}
		else
			cout << "�̸� ���� �Ҹ���" << endl;

	}

};

int main(){
	Student s1(5, "������");
	Student s2;
	s1.printStudent();
	s2.printStudent();
	s2 = s1;
	s1.printStudent();
	s2.printStudent();
	strcpy(s2.szName, "�����");
	s1.printStudent();
	s2.printStudent();


	Student s3;
	s3.printStudent();
	
	s3 = s2 = s1;

	s1.printStudent();
	s2.printStudent();
	s3.printStudent();

	Student s4(10,"������");

	s4 = s4;

	s4.printStudent();

	Student s5 = s4;
	s5.printStudent();
}
