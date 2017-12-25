#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
using namespace std;


class Student{
public:
	int nNo;
	char szName[20];
	Student(){
		cout << "기본 생성자"<<endl;
		nNo = 0;
		szName[0] = NULL;
	}
	Student(int nNo,char* name){
		this->nNo=nNo;
		strcpy(szName, name);
		cout << szName << "매개변수 있는 생성자" << endl;

	}
	~Student(){
		cout <<szName<< "소멸자"<<endl;
	}


};
void a(){
	Student k(2,"김민주");

}
int main(){
	/*Student* p=new Student[5];

	delete[] p;

	Student a[7];*/

	Student st2;
	a();
	Student st1(10,"홍길동");
}