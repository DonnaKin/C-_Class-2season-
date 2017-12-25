#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string.h>
using namespace std;
class Pet {
public:
	char szName[20];
	Pet(char* pName){ 
		strcpy(szName, pName);
	}
	virtual void Speak()= 0;
	/*virtual void Speak(){
		cout << "�ֿϵ����� �� �մϴ� : ";
	}*/
};

class Pup: public Pet {
public:
	Pup(char* pName) : Pet(pName){}
	
	/*void Speak(){
		cout <<szName<<"�� ~ : �۸� !! "<<endl;
	}*/

	void k(){
		cout << "************" << endl;
	}
};

class Cat : public Pet {
public:
	Cat(char* pName) : Pet(pName){}

	void Speak(){
		cout << szName << "�� ~ : �߿� !! " << endl;
	}
};

int main(){
	Pet *pPet = 0;

	Pup myPup("����");
	Cat myCat("����");

	pPet = &myPup;
	pPet->Speak();
	//pPet->k();

	pPet = &myCat;
	pPet->Speak();
	cout << "------------------------" << endl;
	Pet *a = new Pet("�����");
	a->Speak();
	return 0;
}