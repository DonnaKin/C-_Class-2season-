#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
using namespace std;


class Student{
public:
	int nNo;
	char szName[20];
	Student(){
		cout << "�⺻ ������"<<endl;
		nNo = 0;
		szName[0] = NULL;
	}
	Student(int nNo,char* name){
		this->nNo=nNo;
		strcpy(szName, name);
		cout << szName << "�Ű����� �ִ� ������" << endl;

	}
	~Student(){
		cout <<szName<< "�Ҹ���"<<endl;
	}


};
void a(){
	Student k(2,"�����");

}
int main(){
	/*Student* p=new Student[5];

	delete[] p;

	Student a[7];*/

	Student st2;
	a();
	Student st1(10,"ȫ�浿");
}