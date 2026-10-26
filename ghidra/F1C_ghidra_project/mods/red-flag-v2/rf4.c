/*
 * red_flag_v4.dll — tick DLL with auto-restart
 * NUMPAD0: slow+DNF all AI, after 3s triggers mini-restart
 */
#include <windows.h>

#define HOTKEY VK_NUMPAD0

static volatile BOOL g_running = TRUE;
static volatile DWORD g_trigger_time = 0;

static DWORD WINAPI thread_main(LPVOID p) {
    (void)p;
    BOOL prev = FALSE;
    BOOL active = FALSE;

    while (g_running) {
        BOOL key = (GetAsyncKeyState(HOTKEY) & 0x8000) != 0;
        if (key && !prev) {
            if (!active) {
                active = TRUE;
                g_trigger_time = GetTickCount();
                Beep(1200, 100);
            }
        }
        prev = key;

        if (active) {
            int count = *(volatile int*)0x005C329C;
            void* player = *(volatile void**)0x007C54E8;
            for (int i = 0; i < count && i < 26; i++) {
                void* veh = ((volatile void**)0x007C54F0)[i];
                if (!veh || veh == player) continue;
                *(volatile int*)((char*)veh + 0x4064) = 3;
                *(volatile int*)((char*)veh + 0x4068) = 5;
                *(volatile float*)((char*)veh + 0x453C) = 0.1f;
            }

            if (GetTickCount() - g_trigger_time > 3000) {
                *(volatile int*)0x007D05A0 = 10;   /* 10 laps */
                *(volatile char*)0x007CE25D = 1;    /* mini-restart */
                Beep(600, 200);
                active = FALSE;
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
