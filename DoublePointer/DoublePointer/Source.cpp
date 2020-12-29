#include <iostream>
using namespace std;

int func(int **ppval) {
	**ppval = 2;
	return 0;
}

int main() {
	int val = 1;
	int *pval;
	int **ppval;

	pval = &val;
	ppval = &pval;
	cout << val << " = " << *pval << " = " << **ppval << " = " << *(&val) << " = " << **(&pval) << " = " << ***(&ppval) << endl;
	cout << &val << " = " << pval << " = " << *ppval << " = " << *(&pval) << " = " << **(&ppval) << endl;
	cout << &pval << " = " << ppval << " = " << *(&ppval) << endl;
	cout << &ppval << endl;

	func(&pval);
	cout << val << endl;

	getchar();
	return 0;
}