#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
using namespace std;


class Student{
public:
	int nNo;
	char* szName;

	void printStudent(){
		if (szName!=NULL)
			cout << "번호 : " << nNo << " 이름 : " << szName << endl; 
		else
			cout << "번호 : " << nNo << " 이름 : 없음"  << endl;

	}

	//void copy(Student &st){//&st call by 레퍼런스

	//	
	//}

	Student& operator=(Student &st){//연산자 오버로딩 (중복정의)--> 사용자정의형이므로 컴파일러는모르니.. 매개변수
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
		cout << "기본 생성자" << endl;
		nNo = 0;
		szName = NULL;
	}
	Student(int nNo, char* name){
		this->nNo = nNo;

		szName = new char[strlen(name)+1];
		strcpy(szName, name);
		cout << szName << "매개변수 있는 생성자" << endl;
	}
	Student(Student &st){
		this->nNo = st.nNo;
		this->szName = new char[strlen(st.szName) + 1];
		strcpy(this->szName, st.szName);

		cout << szName<< "매개변수 있는 생성자" << endl;
	}
	~Student(){
		cout << szName << "소멸자" << endl;
		delete[] szName;
	}


};

int main(){
	Student st1(10,"홍길동");
	st1.printStudent();
	Student st2;
	st2.printStudent();

	st2 = st1;
	st1.printStudent();
	st2.printStudent();

	strcpy(st2.szName, "강아지");
	st1.printStudent();
	st2.printStudent();


	/*st2.copy(st1);
	st1.printStudent();
	st2.printStudent();

	strcpy(st2.szName, "강아지");
	st1.printStudent();
	st2.printStudent();*/
	Student st3(20, "고양이");

	st1.printStudent();
	st2.printStudent();
	st3.printStudent();

	st3 = st1;

	st1 = st1;
	st1.printStudent();

	st3 = st2 = st1;
	Student st4 = st1;
	
	
	//Student st4 =st1;//객체생성이 아직 안됬는데 대입...가야하는 곳이 명확하지 않음 디버깅에러 Student st4(st1);
}