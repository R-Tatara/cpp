#include <math.h> 
#include <iostream> 

bool IsPrime(int num) {
	double sqrtNum = sqrt(num);

	 //—áŠOˆ—
	if (num < 2) {
		return false;
	}
	else if (num == 2) {
		return true;
	}
	//‹ô”‚Ìˆ—
	else if (num % 2 == 0) {
		return false;
	}

	//Šï”‚Ìˆ—
	for (int i = 3; i <= (int)sqrtNum; i += 2) {
		if (num % i == 0) {
			return false;
		}
	}

	return true;
}

int main() {
	for (int i = 0; i < 1000; i++) {
		std::cout << i << "\t" << IsPrime(i) << std::endl;
	}
	return 0;
}