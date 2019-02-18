#include <iostream>
using namespace std;

int func(float val, float array[3]);

int main() {
	float array[3];
	func(1.5F, array);
	cout << array[0] << "\t" << array[1] << "\t" << array[2] << endl;

	getchar();
	return 0;
}

int func(float val, float array[3]) {
	array[0] = val + 1.0F;
	array[1] = array[0] + 1.0F;
	array[2] = array[1] + 1.0F;
	
	return 0;
}


