#include <iostream>
using namespace std;

class MyClass {
public:
	float a, b[2];
	MyClass();
};

MyClass::MyClass()
	: a(1.0),
	b{ 2.0, 3.0 }
{
}

MyClass c;

int main() {
	cout << c.a << endl;
	cout << c.b[0] << "\t" << c.b[1] << endl;
	getchar();
	return 0;
}