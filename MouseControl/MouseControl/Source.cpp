#include <iostream>
#include <windows.h>
using namespace std;

int main() {
    POINT pt;
    HWND hWnd;

    while(1) {
		Sleep(1000);
		GetCursorPos(&pt); //マウスの現在の座標を取得する
		cout << pt.x << "\t" << pt.y << endl;
    }

    /*
    SetCursorPos(pt.x + 10, pt.y + 10); //SetPhysicalCursorPos(0, 0);
    mouse_event(MOUSEEVENTF_LEFTDOWN,0,0,0,0);  //Push (MOUSEEVENTF_RIGHTDOWN or MOUSEEVENTF_MIDDLEDOWN)
    mouse_event(MOUSEEVENTF_LEFTUP,0,0,0,0);    //Release (MOUSEEVENTF_RIGHTUP or MOUSEEVENTF_MIDDLEUP)
    mouse_event(MOUSEEVENTF_WHEEL,0,0,-1,0);    //Wheel down
    mouse_event(MOUSEEVENTF_WHEEL,0,0,1,0);     //Wheel up 
    hWnd = WindowFromPoint(pt);
    SendMessage(hWnd,WM_SETTEXT,0,(LPARAM)"abc"); //Input character
    */

    getchar();
    return 0;
}