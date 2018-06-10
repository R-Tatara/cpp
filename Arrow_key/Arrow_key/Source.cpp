#include <stdio.h>
#include <conio.h>

int main(void) {
	char key = 0;

	while (1) {
		if (_kbhit()) {
			key = _getch();
		}

		if (key == 0x48) { //ª
			puts("ª");
			key = 0;
		}
		else if (key == 0x50) { //«
			puts("«");
			key = 0;
		}
		else if (key == 0x49) { //PgUp
			puts("Up");
			key = 0;
		}
		else if (key == 0x51) { //PgDn
			puts("Dn");
			key = 0;
		}
		else if (key == 0x4B) { //©
			puts("©");
			key = 0;
		}
		else if (key == 0x4D) { //¨
			puts("¨");
			key = 0;
		}
		else if (key == 27) { //Esc
			return 0;
		}
	}
}