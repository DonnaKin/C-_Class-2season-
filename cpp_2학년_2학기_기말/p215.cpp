#include <iostream>
using namespace std;
class Horse {
public:
	Horse(){
		cout << "말(Horse) 생성자" << endl;

	}
	virtual ~Horse(){
		cout << "말(Horse) 소멸자" << endl;
	}

	virtual void Speak(){
		cout << "말(Horse)이 웁니다. 히히힝~ " << endl;
	}
};

class Bird {
public:
	Bird(){
		cout << "새(Bird) 생성자" << endl;

	}
	virtual ~Bird(){
		cout << "새(Bird) 소멸자" << endl;
	}

	virtual void Speak(){
		cout << "새(Bird)가 웁니다. 짹짹짹~ " << endl;
	}
	virtual void Fly(){
		cout << "하늘을 날 수 있습니다." << endl;
	}
};

class Pegasus : public Bird, public Horse {
public:
	Pegasus(){
		cout << "페가수스(Pegasus) 생성자" << endl;

	}
	~Pegasus(){
		cout << "페가수스(Pegasus) 소멸자" << endl;
	}

	void Speak(){
		cout << "페가수스(Pegasus)가 웁니다. 히히힝~ " << endl;
	//	Horse::Speak();
	//	Bird::Speak();
	}
	
};

int main(){
	Pegasus *p = new Pegasus();
	p->Speak();
	p->Fly();
	delete p;

	cout << "------------------------------"<<endl;
	Horse *h = new Pegasus();
	h->Speak();
	//h->Fly();
	delete h;

	cout << "------------------------------" << endl;
	Bird *b = new Pegasus();
	b->Speak();
	b->Fly();

	//h->Fly();
	delete h;
}