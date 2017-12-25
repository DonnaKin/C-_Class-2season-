#include <iostream>
using namespace std;
class Shape {
protected: //private으로 바꿔보면 sizeof 봐도 부모랑 자식이랑 사이즈 같음 --> 상속은 되나 못씀
	int x, y;
	int width;
	int height;
	static int k;
	/*short x, y;
	short width;
	int height;*/ //제일큰 형의 배수에 가깝게 반올림
public:
	Shape() {
		x = y = width = height = 0;
		cout << "도형 기본생성자" << endl;
	}
	Shape(int x, int y, int w, int h) :x(x), y(y), width(w), height(h) {
		cout << "도형 매개변수 생성자" << endl;

	}
	//virtual 은 몇개를 적던 포인터 하나 ... sizeof 시 멤버변수 + 4바이트
	 virtual ~Shape() { cout << "도형 소멸" << endl; } 
	 virtual void Draw() {
		cout << "도형을 그립니다. 영역[" << x << ", " << y << ", " << width << ", " << height << "]" << endl;
	}
};
class Rectangle : public Shape {
public:
	Rectangle() {
		cout << "사각형 기본생성자" << endl;
	}
	Rectangle(int x, int y, int w, int h) :Shape(x, y, w, h) {
	}
	~Rectangle() { cout << "사각형 소멸" << endl; }
	void Draw() {
//		cout << "사각형을 그립니다. 영역[" << x << ", " << y << ", " << width << ", " << height << "]" << endl;
	}
};
class Ellipse : public Shape {
public:
	Ellipse() {
		cout << "타원 기본생성자" << endl;
	}
	Ellipse(int x, int y, int w, int h) :Shape(x, y, w, h) {

	}
	~Ellipse() { cout << "타원 소멸" << endl; }
	void Draw() {
	//	cout << "타원을 그립니다. 영역[" << x << ", " << y << ", " << width << ", " << height << "]" << endl;
	}
};
class Triangle : public Shape {
public:
	Triangle() {

		cout << "삼각형 기본생성자" << endl;
	}
	Triangle(int x, int y, int w, int h) :Shape(x, y, w, h) {//매개변수 있는 아빠 호출

	}
	~Triangle() { cout << "삼각형 소멸" << endl; }
	void Draw() {
	//	cout << "삼각형을 그립니다. 영역[" << x << ", " << y << ", " << width << ", " << height << "]" << endl;
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
	cout << "\n생성자를 호출합니다" << endl;
	shapes[0] = new Rectangle();
	shapes[1] = new Rectangle(10, 10, 100, 100);
	shapes[2] = new Ellipse();
	shapes[3] = new Ellipse(10, 10, 100, 100);
	shapes[4] = new Triangle();
	shapes[5] = new Triangle(10, 10, 100, 100);
	cout << "\n도형을 그립니다" << endl;
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
delete ((Rectangle *)pShape); // 사각형 소멸이 일어나지 않는다

system("PAUSE");

//	Rectangle *r = new Shape();//아빠만큼 만들어서 아들만큼 쓴다 ->  X
cout << "------------------------------------------------" << endl;
Shape *pShape1 = new Shape();

pShape1->Draw();
delete ((Rectangle *)pShape1); // 사각형 소멸이 일어나지 않는다
pShape1->Draw();
((Rectangle *)pShape1)->Draw();
return 0;
}*/