#include <iostream>
using namespace std;
class Shape {
protected: //private���� �ٲ㺸�� sizeof ���� �θ�� �ڽ��̶� ������ ���� --> ����� �ǳ� ����
	int x, y;
	int width;
	int height;
	static int k;
	/*short x, y;
	short width;
	int height;*/ //����ū ���� ����� ������ �ݿø�
public:
	Shape() {
		x = y = width = height = 0;
		cout << "���� �⺻������" << endl;
	}
	Shape(int x, int y, int w, int h) :x(x), y(y), width(w), height(h) {
		cout << "���� �Ű����� ������" << endl;

	}
	//virtual �� ��� ���� ������ �ϳ� ... sizeof �� ������� + 4����Ʈ
	 virtual ~Shape() { cout << "���� �Ҹ�" << endl; } 
	 virtual void Draw() {
		cout << "������ �׸��ϴ�. ����[" << x << ", " << y << ", " << width << ", " << height << "]" << endl;
	}
};
class Rectangle : public Shape {
public:
	Rectangle() {
		cout << "�簢�� �⺻������" << endl;
	}
	Rectangle(int x, int y, int w, int h) :Shape(x, y, w, h) {
	}
	~Rectangle() { cout << "�簢�� �Ҹ�" << endl; }
	void Draw() {
//		cout << "�簢���� �׸��ϴ�. ����[" << x << ", " << y << ", " << width << ", " << height << "]" << endl;
	}
};
class Ellipse : public Shape {
public:
	Ellipse() {
		cout << "Ÿ�� �⺻������" << endl;
	}
	Ellipse(int x, int y, int w, int h) :Shape(x, y, w, h) {

	}
	~Ellipse() { cout << "Ÿ�� �Ҹ�" << endl; }
	void Draw() {
	//	cout << "Ÿ���� �׸��ϴ�. ����[" << x << ", " << y << ", " << width << ", " << height << "]" << endl;
	}
};
class Triangle : public Shape {
public:
	Triangle() {

		cout << "�ﰢ�� �⺻������" << endl;
	}
	Triangle(int x, int y, int w, int h) :Shape(x, y, w, h) {//�Ű����� �ִ� �ƺ� ȣ��

	}
	~Triangle() { cout << "�ﰢ�� �Ҹ�" << endl; }
	void Draw() {
	//	cout << "�ﰢ���� �׸��ϴ�. ����[" << x << ", " << y << ", " << width << ", " << height << "]" << endl;
	}
};
int main() {
	/*/Rectangle r1; Ellipse e1; Triangle t1; Rectangle r2(1, 2, 3, 4);Ellipse e2(5, 6, 7, 8);	Triangle t2(9, 0, 1, 2);
	r1.Draw();
	e1.Draw();
	t1.Draw();
	r2.Draw();
	e2.Draw();
	t2.Draw();
	
	cout << sizeof(Ellipse) << endl;
	cout << sizeof(Triangle) << endl;*/
	Shape* shapes[6];
	cout << "\n�����ڸ� ȣ���մϴ�" << endl;
	shapes[0] = new Rectangle();
	shapes[1] = new Rectangle(10, 10, 100, 100);
	shapes[2] = new Ellipse();
	shapes[3] = new Ellipse(10, 10, 100, 100);
	shapes[4] = new Triangle();
	shapes[5] = new Triangle(10, 10, 100, 100);
	cout << "\n������ �׸��ϴ�" << endl;
	for (int i = 0; i < 6; i++) {
		shapes[i]->Draw();
	}	for (int i = 0; i < 6; i++) {
		delete shapes[i];
	}
	
	cout << sizeof(Shape) << endl;

	cout << sizeof(Rectangle) << endl;
}
/*int main(){
Rectangle * pRect = 0;
pRect = new Rectangle(10, 10, 100, 100);
pRect->Draw();
((Shape *)pRect)->Draw();
delete pRect;
system("PAUSE");
cout << "------------------------------------------------" << endl;
Shape * pShape = new Rectangle;
pShape = new Rectangle(10, 10, 100, 100);
pShape->Draw();
((Rectangle *)pShape)->Draw();
delete ((Rectangle *)pShape); // �簢�� �Ҹ��� �Ͼ�� �ʴ´�

system("PAUSE");

//	Rectangle *r = new Shape();//�ƺ���ŭ ���� �Ƶ鸸ŭ ���� ->  X
cout << "------------------------------------------------" << endl;
Shape *pShape1 = new Shape();

pShape1->Draw();
delete ((Rectangle *)pShape1); // �簢�� �Ҹ��� �Ͼ�� �ʴ´�
pShape1->Draw();
((Rectangle *)pShape1)->Draw();
return 0;
}*/