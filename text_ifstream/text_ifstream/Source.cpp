#include <stdio.h>
#include <fstream>
#include <conio.h>

std::ifstream ifs("../../text_ofstream/text_ofstream/test_io.txt");

int main()
{
	int key;
	int cycle = 0;
	double x1;
	double y1;

	while (1) {
		ifs.clear();
		ifs >> x1 >> y1;
		printf("input : %d\t", cycle);
		printf("%lf\t%lf\n", x1, y1);

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