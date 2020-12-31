#include <iostream>
using namespace std;

void PrintArg(int argc, char **argv) {
	cout << "argc = " << argc << endl;

	for (int i = 0; i < argc; i++) {
		cout << "argv[" << i << "]  = " << argv[i] << endl;
	}
	return;
}

//argc : ˆø”‚ÌŒÂ”Aargv[] : ˆø”‚Ì’l
int main(int argc, char *argv[]) {
	PrintArg(argc, argv);

	getchar();
	return 0;
}