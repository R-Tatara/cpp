#pragma comment(lib, "winmm.lib")

#include <stdio.h>
#include <windows.h>

int main() {

	JOYINFOEX JoyInfoEx;
	JoyInfoEx.dwSize = sizeof(JOYINFOEX);
	JoyInfoEx.dwFlags = JOY_RETURNALL;
		
	while (1) {
				
		if (JOYERR_NOERROR == joyGetPosEx(0, &JoyInfoEx)) { //0番のジョイスティックの情報を見る
					

			printf("dwXpos = %d\t"
				"dwYpos = %d\t"
				"dwButtons = %d  \r",
				JoyInfoEx.dwXpos,
				JoyInfoEx.dwYpos,
				JoyInfoEx.dwButtons);
		}

		else {
			printf("Joy controller error\n");
		}		
	}

	return 0;
}
