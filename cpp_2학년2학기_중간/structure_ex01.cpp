#include <iostream>

using namespace std;

struct A{

	int a;
};
typedef struct{
	int b;
}B;
struct {
	int c;
}C;
int main(){
	A k1;
	k1.a= 10;

	B k2;
	k2.b = 20;

//	C k3;
//	k3.c = 30;
}