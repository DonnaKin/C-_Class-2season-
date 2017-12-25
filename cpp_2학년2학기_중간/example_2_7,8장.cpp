#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

using namespace std;


class Student{
public:
	int nNo;
	char *szName;

	Student(){
		cout << "기본생성자" << endl;
		this->nNo = 0;
		this->szName = 0;
	}
	Student(int nNo, char *name){
		cout << "매개변수 있는 생성자" << endl;
		this->nNo = nNo;
		szName = new char[strlen(name) + 1];
		strcpy(this->szName, name);

	}
	Student(Student &st){
		cout << "매개변수 있는 생성자" << endl;
		this->nNo = st.nNo;
		szName = new char[strlen(st.szName) + 1];
		strcpy(this->szName, st.szName);
	}

	Student &operator=(Student &st){//call by reference  -->할당연산자 중복정의(assign)
		cout << "오퍼레이터" << endl;
		if (this != &st){
			this->nNo = st.nNo;
			this->szName = new char[strlen(st.szName) + 1];
			strcpy(this->szName, st.szName);
		}
		return *this;
	}
	//Student &operator=(Student &st){//call by reference  -->할당연산자 중복정의(assign)
	//	if (this != &st){
	//		this->nNo = st.nNo;
	//		this->szName = new char[strlen(st.szName) + 1];
	//		strcpy(this->szName, st.szName);
	//	}
	//	return *this;
	//}
	void printStudent(){
		if (szName != NULL)
			cout << "번호 : " << nNo << "\t이름 : " << szName << endl;
		else
			cout << "번호 : " << nNo << "\t이름 : 없음" << endl;

	}
	~Student(){

		if (szName != NULL){
			cout << szName << "소멸자" << endl;
			delete[] szName;
		}
		else
			cout << "이름 없음 소멸자" << endl;

	}

};

int main(){
	Student s1(5, "강아지");
	Student s2;
	s1.printStudent();
	s2.printStudent();
	s2 = s1;
	s1.printStudent();
	s2.printStudent();
	strcpy(s2.szName, "고양이");
	s1.printStudent();
	s2.printStudent();


	Student s3;
	s3.printStudent();
	
	s3 = s2 = s1;

	s1.printStudent();
	s2.printStudent();
	s3.printStudent();

	Student s4(10,"망아지");

	s4 = s4;

	s4.printStudent();

	Student s5 = s4;
	s5.printStudent();
}
