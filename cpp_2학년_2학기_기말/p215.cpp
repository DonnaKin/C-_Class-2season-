#include <iostream>
using namespace std;
class Horse {
public:
	Horse(){
		cout << "��(Horse) ������" << endl;

	}
	virtual ~Horse(){
		cout << "��(Horse) �Ҹ���" << endl;
	}

	virtual void Speak(){
		cout << "��(Horse)�� ��ϴ�. ������~ " << endl;
	}
};

class Bird {
public:
	Bird(){
		cout << "��(Bird) ������" << endl;

	}
	virtual ~Bird(){
		cout << "��(Bird) �Ҹ���" << endl;
	}

	virtual void Speak(){
		cout << "��(Bird)�� ��ϴ�. ±±±~ " << endl;
	}
	virtual void Fly(){
		cout << "�ϴ��� �� �� �ֽ��ϴ�." << endl;
	}
};

class Pegasus : public Bird, public Horse {
public:
	Pegasus(){
		cout << "�䰡����(Pegasus) ������" << endl;

	}
	~Pegasus(){
		cout << "�䰡����(Pegasus) �Ҹ���" << endl;
	}

	void Speak(){
		cout << "�䰡����(Pegasus)�� ��ϴ�. ������~ " << endl;
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