#include <stdio.h>
#include <fstream>
#include <conio.h>
#include <windows.h>

using namespace std;
std::ofstream ofs("test_io.txt");

int main()
{
	int key;
	int cycle = 0;
	double x1;
	double y1;

	x1 = 0.0;
	y1 = 0.0;

	while (1) {
		ofs.clear();
		x1 += 0.001;
		y1 += 0.002;
		ofs << x1 << "\t" << y1 << endl;
		printf("output : %d\t", cycle);
		printf("%lf\t%lf\n", x1, y1);

		Sleep(1);
		cycle++;

		if (_kbhit()) {
			key = _getch();
			if (key == 27) { //Esc
				break;
			}
		}
	}

	return 0;
}