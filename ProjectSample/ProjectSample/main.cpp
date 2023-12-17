#include "common.h"
#include "function1.h"
#include <iostream>

int main() {
	std::cout << "COMMON_VAL: " << COMMON_VAL << std::endl;
	Sample();

	MyClass myClass;
	myClass.MyFunction();
	return 0;
}

