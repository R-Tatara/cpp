#include <stdio.h>
#include <conio.h>

int main() {
	char key = 0;

	while (1) {
		if (_kbhit()) {
			key = _getch();
		}

		switch (key) {
		case 0x48:
			puts("ArrowUp");
			break;
		case 0x50:
			puts("ArrowDown");
			break;
		case 0x4B:
			puts("ArrowLeft");
			break;
		case 0x4D:
			puts("ArrowRight");
			break;
		case 0x49:
			puts("PageUp");
			break;
		case 0x51:
			puts("PageDown");
			break;
		case 0x1B:
			puts("Esc");
			return 0;
		default:
			break;
		}
		key = 0;
	}
}