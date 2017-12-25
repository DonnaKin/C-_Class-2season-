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
		cout << "애완동물이 말 합니다 : ";
	}*/
};

class Pup: public Pet {
public:
	Pup(char* pName) : Pet(pName){}
	
	/*void Speak(){
		cout <<szName<<"야 ~ : 멍멍 !! "<<endl;
	}*/

	void k(){
		cout << "************" << endl;
	}
};

class Cat : public Pet {
public:
	Cat(char* pName) : Pet(pName){}

	void Speak(){
		cout << szName << "야 ~ : 야옹 !! " << endl;
	}
};

int main(){
	Pet *pPet = 0;

	Pup myPup("해피");
	Cat myCat("코코");

	pPet = &myPup;
	pPet->Speak();
	//pPet->k();

	pPet = &myCat;
	pPet->Speak();
	cout << "------------------------" << endl;
	Pet *a = new Pet("토순이");
	a->Speak();
	return 0;
}