/*
 * red_flag_v3.dll — minimal tick DLL
 * NUMPAD0 triggers: write DNF+slow to all AI, loop every 50ms
 */
#include <windows.h>

#define HOTKEY VK_NUMPAD0

static volatile BOOL g_running = TRUE;
static volatile BOOL g_active = FALSE;

static DWORD WINAPI thread_main(LPVOID p) {
    (void)p;
    BOOL prev = FALSE;

    while (g_running) {
        BOOL key = (GetAsyncKeyState(HOTKEY) & 0x8000) != 0;
        if (key && !prev) {
            g_active = !g_active;
            if (g_active) Beep(1200, 100); else Beep(600, 100);
        }
        prev = key;

        if (g_active) {
            int count = *(volatile int*)0x005C329C;
            void* player = *(volatile void**)0x007C54E8;
            for (int i = 0; i < count && i < 26; i++) {
                void* veh = ((volatile void**)0x007C54F0)[i];
                if (!veh || veh == player) continue;
                *(volatile int*)((char*)veh + 0x4064) = 2;
                *(volatile int*)((char*)veh + 0x4068) = 5;
                *(volatile float*)((char*)veh + 0x453C) = 0.1f;
            }
        }
        Sleep(50);
    }
    return 0;
}

BOOL WINAPI DllMain(HINSTANCE h, DWORD reason, LPVOID r) {
    (void)r;
    if (reason == DLL_PROCESS_ATTACH) {
        DisableThreadLibraryCalls(h);
        CreateThread(NULL, 0, thread_main, NULL, 0, NULL);
    } else if (reason == DLL_PROCESS_DETACH) {
        g_running = FALSE;
    }
    return TRUE;
}
