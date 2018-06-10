#include <stdio.h>

class Direction {
public:
	float x, y, z;
};

class Parameter : public Direction {
public:
	Direction target;
	Direction sensor;
};

Parameter A;
Parameter B;
Direction C;

int main() {
	A.target.x = 1.0F;
	C.x = 2.0F;
	printf("%f\t%f", A.target.x, C.x);
	getchar();

	return 0;
}