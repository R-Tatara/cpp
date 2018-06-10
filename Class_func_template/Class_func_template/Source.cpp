#include <iostream>
using namespace std;

void func1(float &, float &);
void func2(float &, float &);

class MyClass {
public:
	float a, b, c[2];
	MyClass();
};

MyClass::MyClass()
	: a(1.0),
	b(2.0),
	c{ 3.0, 4.0 }
{
}

MyClass c;

int main() {
	cout << c.a << "\t" << c.b << endl;
	cout << c.c[0] << "\t" << c.c[1] << endl;
	func1(c.a, c.b);
	func2(c.c[0], c.c[1]);
	cout << c.a << "\t" << c.b << endl;
	cout << c.c[0] << "\t" << c.c[1] << endl;
	getchar();
	return 0;
}

void func1(float &x, float &y) {
	x = 5;
	y = 6;
	return;
}

void func2(float &x, float &y) {
	x = 7;
	y = 8;
	return;
}