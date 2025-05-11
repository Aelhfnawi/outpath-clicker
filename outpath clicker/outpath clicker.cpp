#include <iostream>
#include <Windows.h>

using namespace std;

bool autoClickerActive = false;

void autoClick() {
    while (autoClickerActive) {
        // Simulate left click
        mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
        mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
        if (GetAsyncKeyState(VK_SHIFT) & 0x8000)
        {
            autoClickerActive = false;
            cout << "Clicking paused.\n";
            return;
        }
        Sleep(10);  // Adjusted to 10 ms interval
    }
}




int main() {
    cout << "Welcome, Elhfnawi!\n";

    while (true) {
        if (GetAsyncKeyState('T') & 0x8001) {
            autoClickerActive = !autoClickerActive;
            autoClick();
            cout << (autoClickerActive ? "Auto Clicker activated!\n" : "Auto Clicker deactivated.\n");
            Sleep(200);  // Avoid multiple toggles on one key press
        }

        //if (GetAsyncKeyState(VK_F2) & 0x8001) {
        //    autoKey(VK_F2);
        //    Sleep(10); // Avoid multiple key presses on one key press
        //}

        if (GetAsyncKeyState(VK_SHIFT) & 0x8000) {
            autoClickerActive = false;
            cout << "Clicking paused.\n";
            Sleep(200);  // Avoid multiple pauses on one key press
        }
    }

    return 0;
}
