#include <iostream>
#include "Header.h"

//Header.hをインクルードすれば，共通の変数として使用可能
int val_h;
//Header.hをインクルードすれば，共通のオブジェクトとして使用可能?
MyClass myclass;

int main() {
	int macro = MACRO;
	myclass.val_c = 200;
	int ret1, ret2;
	ret1 = Func_p();
	ret2 = Func_h();

	std::cout << macro << std::endl;
	std::cout << myclass.val_c << std::endl;
	std::cout << ret1<< std::endl;
	std::cout << ret2 << std::endl;

	getchar();
	return 0;
}

//Header.hをインクルードすれば，共通の関数として使用可能
int Func_p() {
	return 300;
}