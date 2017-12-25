#include <iostream> 
using namespace std;
class Student{ 
public:
	int nNo;
	char szName[14];
	double height;
	int num;
	static short nCnt;
	Student(){ nNo = ++nCnt; strcpy_s(szName, "ȫ�浿"); }
	void setStudent(int no, char* pName){ nNo = no; strcpy_s(szName, pName); }
	void printStudent(){ cout << nNo << " : " << szName << endl; }
	static int getnCnt(){ return nCnt; } }; 
short Student::nCnt = 5;

struct a{
	int b;
	short* ad;
	char a7[3];
	
};
void main(){

	cout << sizeof(a)<<endl;
	Student stu;
	cout << sizeof(double) <<
		endl;
	cout << sizeof(stu)<<endl;
	stu.printStudent(); 
	cout << stu.getnCnt() << endl; 
	Student *pstu = new Student(); 
}
