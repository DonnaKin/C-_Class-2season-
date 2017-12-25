#include<iostream>
#include<math.h>
using namespace std;

class Complex{
	double real;
	double imaginery;
public:

	Complex(){
		real = 0;
		imaginery = 0;
	}
	Complex(double real, double imaginery){
		this->real = real;
		this->imaginery = imaginery;
	}



	void printComplex(){

		if (real == 0 && imaginery == 0){//둘다 0이면
			cout << 0 << endl;
		}
		else if (real == 0){//real만 0이면
			if (imaginery == 1 || imaginery == -1)
				cout << "i " << endl;
			else
				cout << imaginery << "i" << endl;
		}
		else if (imaginery == 0){//imaginery만 0이면
			
			cout << real << endl;
		}
		else{


			if (imaginery > 0){

				if (imaginery == 1)
					cout << real << " + " << "i " << endl;
				else
					cout << real << " + " << imaginery << "i " << endl;

			}
			else{
				if (imaginery == -1)
					cout << real << " - " << "i " << endl;
				else
					cout << real << " - " << imaginery*-1 << "i " << endl;

			}
		}
	}

	Complex& operator=(Complex &com){
		this->real = com.real;
		this->imaginery = com.imaginery;

		return *this;
	}
	/*Complex& operator+(Complex& com){
		double temp_r;
		double temp_i;
		temp_r = this->real + com.real;
		temp_i = this->imaginery + com.imaginery;
		return Complex(temp_r, temp_i);
	}*/

	Complex& operator-(Complex& com){
		double temp_r;
		double temp_i;
		temp_r = this->real - com.real;
		temp_i = this->imaginery - com.imaginery;
		return Complex(temp_r, temp_i);
	}

	Complex& operator*(Complex& com){
		double temp_r;
		double temp_i;
		temp_r = this->real * com.real;
		temp_r += this->real * com.real*-1;
		temp_i = this->real * com.imaginery;
		temp_i += this->imaginery * com.real;

		return Complex(temp_r, temp_i);
	}

	Complex& operator/(Complex& com){
		double temp_r;
		double temp_i;
		temp_r = (this->real * com.real + this->imaginery*com.imaginery) / (pow(com.real, 2) + (pow(com.imaginery, 2)));
		temp_i = (this->imaginery * com.real - this->real*com.imaginery) / (pow(com.real, 2) + (pow(com.imaginery, 2)));

		return Complex(temp_r, temp_i);
	}

	Complex& operator++(){
		cout << "전치연산 ";

		this->real++;
		return *this;
	}

	Complex operator++(int){
		cout << "후치연산 ";
		Complex prev(this->real, this->imaginery);

		this->real++;

		return prev;
	}

	friend istream& operator>>(istream& ist, Complex& com);
	friend Complex& operator+(Complex& com1, Complex& com2);


};
Complex& operator+(Complex& com1, Complex& com2){
	double temp_r;
	double temp_i;
	temp_r = com1.real + com2.real;
	temp_i = com1.imaginery + com2.imaginery;
	return Complex(temp_r, temp_i);
}
ostream& operator<<(ostream& ost, Complex& com){
	com.printComplex();

	return ost;

}

istream& operator>>(istream& ist, Complex& com){
	cout << "복소수 입력 (실수) : ";
	cin >> com.real;
	cout << "복소수 입력 (허수) : ";
	cin >> com.imaginery;

	com.printComplex();

	return ist;

}
int main(){

	cout << "complex 초기화" << endl;
	Complex c1(3,5);
	c1.printComplex();
	Complex c2(3, -5);
	c2.printComplex();
	Complex c3(-2, 4);
	c3.printComplex();
	Complex c4(-2, -4);
	c4.printComplex();
	Complex c5(3, 0);
	c5.printComplex();
	Complex c6(0, 2);
	c6.printComplex();
	Complex c7(0, 0);
	c7.printComplex();
	Complex c8(0, 5);
	c8.printComplex();

	cout<<"---------------------------------" << endl;
	cout << " complex 덧셈" << endl;
	Complex c9;
	c9 = c1 + c2;
	c1.printComplex();
	c2.printComplex();
	c9.printComplex();
	cout << "---------------------------------" << endl;
	cout << " complex 대입 "<< endl;
	c3.printComplex();
	c5.printComplex();

	c5 = c3;
	//c3.printComplex();
	cout << c3;
	c5.printComplex();
	cout << "---------------------------------" << endl;
	cout << " complex 곱셈 " << endl;
	Complex c10;
	c10 = c2 * c4;
	cout << c10;
	cout << "---------------------------------" << endl;
	cout << " complex 나눗셈 " << endl;
	c10 = c6 / c8;
	cout << c10;
	cout << "---------------------------------" << endl;
	cout << " complex ++연산 " << endl;

//	Complex c11;
	//cin >> c11;

	Complex a, b;
	b = ++c1;
	cout << "b :  " << b;
	cout << "c1 :  " << c1;

	a = c1++;
	cout << "a : " << a;
	cout << "c1 : " << c1;

}