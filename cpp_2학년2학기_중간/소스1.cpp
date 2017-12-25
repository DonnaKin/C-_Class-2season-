#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>

using namespace std;

class Point{
	char *pName;
	int x, y;
	void setxy(int x, int y){
		this->x = x;
		this->y = y;

	}
public:
	Point(){
		pName = 0;
		setxy(0, 0);
	}
	Point(Point& p){
		pName = new char[strlen(p.pName) + 1];
		strcpy(pName, p.pName);
		setxy(p.x, p.y);

	}
	Point& operator=(Point& p){
		if (this != &p){
			pName = new char[strlen(p.pName) + 1];
			//pName = new char[5];
			strcpy(pName, p.pName);
			setxy(p.x, p.y);			
		}
		return *this;
	}
	



	void setData(char *name, int x, int y){
		pName = new char[11];
		strcpy(pName, name);
		setxy(x, y);
	}
	void printData(){
		if(pName)  cout << pName <<" : " ;
		cout << x << "," << y << endl;
	}
	~Point()
	{
		if (pName){
			delete[] pName;
			pName = 0;
		}
	}
};
int main(){
	int su;
	cin >> su;
	Point *arr = new Point[su];
	char poName[11];
	for (int i = 0; i < su; i++){
		cout << "Á¡ÀÌ¸§ : ";
		cin >> poName;
		arr[i].setData(poName, 2 * i, 3 * i);
	}
	for (int i = 0; i < su; i++) arr[i].printData();
	Point ind = arr[0];
	
	Point po1, po2, po3;

	po1 = arr[1];
	po3 = po2 = arr[2];
	po2 = po2;
	delete[] arr;

	return 0;

}