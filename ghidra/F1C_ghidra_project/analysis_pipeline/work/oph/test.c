#include <windows.h>
BOOL WINAPI DllMain(HINSTANCE h, DWORD r, LPVOID) { return TRUE; }
__declspec(dllexport) void start(void) {}
