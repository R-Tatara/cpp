#include <iostream>
using namespace std;

class MyClass {
private:
	int a, b[2];
public:
	MyClass();
	void Set(int arg1, int arg2[]);
	void Print(void);
};

MyClass::MyClass()
	: a(1),
	b{2, 3}
{
}

void MyClass::Set(int arg1, int arg2[]) {
	this->a = arg1;
	this->b[0] = arg2[0];
	this->b[1] = arg2[1];
	return;
}

void MyClass::Print() {
	cout << "a = " << this->a << endl;
	cout << "b = " << this->b[0] << ", " << this->b[1] << endl;
	return;
}

MyClass ClassName;

int main() {
	int val1 = 4;
	int val2[2] = {5, 6};

	ClassName.Set(val1, val2);
	ClassName.Print();

	getchar();
	return 0;
}