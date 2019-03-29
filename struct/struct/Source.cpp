#include <stdio.h>
#include <iostream>

using namespace std;

class Direction {
public:
	float x;
	float y;
	float z;
};

class Parameter {
public:
	Direction sensor;
	Direction target;
};

Parameter A;
Parameter B;

int main() {
	A.sensor.x = 1.0F;
	cout << A.sensor.x << endl;
	getchar();
	return 0;
}

/*
typedef struct {
float x;
float y;
float z;
}direction;

typedef struct {
direction sensor;
direction target;
}parameter;

parameter A;
parameter B;

int main() {
A.sensor.x = 1.0F;
printf("%f", A.sensor.x);
getchar();

return 0;
}
*/