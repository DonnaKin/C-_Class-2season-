#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
using namespace std;


class Student{
public:
	int nNo;
	char* szName;

	void printStudent(){
		if (szName!=NULL)
			cout << "��ȣ : " << nNo << " �̸� : " << szName << endl; 
		else
			cout << "��ȣ : " << nNo << " �̸� : ����"  << endl;

	}

	//void copy(Student &st){//&st call by ���۷���

	//	
	//}

	Student& operator=(Student &st){//������ �����ε� (�ߺ�����)--> ������������̹Ƿ� �����Ϸ��¸𸣴�.. �Ű�����
		if (this != &st){
			this->nNo = st.nNo;
			if (this->szName != NULL)
				delete[] this->szName;
			this->szName = new char[strlen(st.szName) + 1];
			strcpy(this->szName, st.szName);
		}
		return *this;
		//return st;

	}

	Student(){
		cout << "�⺻ ������" << endl;
		nNo = 0;
		szName = NULL;
	}
	Student(int nNo, char* name){
		this->nNo = nNo;

		szName = new char[strlen(name)+1];
		strcpy(szName, name);
		cout << szName << "�Ű����� �ִ� ������" << endl;
	}
	Student(Student &st){
		this->nNo = st.nNo;
		this->szName = new char[strlen(st.szName) + 1];
		strcpy(this->szName, st.szName);

		cout << szName<< "�Ű����� �ִ� ������" << endl;
	}
	~Student(){
		cout << szName << "�Ҹ���" << endl;
		delete[] szName;
	}


};

int main(){
	Student st1(10,"ȫ�浿");
	st1.printStudent();
	Student st2;
	st2.printStudent();

	st2 = st1;
	st1.printStudent();
	st2.printStudent();

	strcpy(st2.szName, "������");
	st1.printStudent();
	st2.printStudent();


	/*st2.copy(st1);
	st1.printStudent();
	st2.printStudent();

	strcpy(st2.szName, "������");
	st1.printStudent();
	st2.printStudent();*/
	Student st3(20, "�����");

	st1.printStudent();
	st2.printStudent();
	st3.printStudent();

	st3 = st1;

	st1 = st1;
	st1.printStudent();

	st3 = st2 = st1;
	Student st4 = st1;
	
	
	//Student st4 =st1;//��ü������ ���� �ȉ�µ� ����...�����ϴ� ���� ��Ȯ���� ���� ����뿡�� Student st4(st1);
}