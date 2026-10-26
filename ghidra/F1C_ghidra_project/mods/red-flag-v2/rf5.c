/*
 * red_flag_v5.dll — tick DLL with auto-restart + file logging
 * NUMPAD0: slow+DNF all AI, after 3s triggers mini-restart
 */
#include <windows.h>
#include <stdio.h>

#define HOTKEY VK_NUMPAD0

static volatile BOOL g_running = TRUE;
static volatile DWORD g_trigger_time = 0;
static char g_log[MAX_PATH];

static void log_w(const char* s) {
    FILE* f = fopen(g_log, "a");
    if (f) { fprintf(f, "[%lu] %s\n", GetTickCount(), s); fclose(f); }
}

static DWORD WINAPI thread_main(LPVOID p) {
    (void)p;
    BOOL prev = FALSE;
    BOOL active = FALSE;

    log_w("DLL loaded, NUMPAD0 to trigger");

    while (g_running) {
        BOOL key = (GetAsyncKeyState(HOTKEY) & 0x8000) != 0;
        if (key && !prev) {
            if (!active) {
                active = TRUE;
                g_trigger_time = GetTickCount();
                log_w("RED FLAG ACTIVATED");
                Beep(1200, 100);
            }
        }
        prev = key;

        if (active) {
            int count = *(volatile int*)0x005C329C;
            void* player = *(volatile void**)0x007C54E8;
            static int tick_n = 0;
            tick_n++;
            if (tick_n <= 3) {
                char buf[64];
                sprintf(buf, "tick %d: count=%d player=0x%08X", tick_n, count, (uintptr_t)player);
                log_w(buf);
            }

            int retired = 0;
            for (int i = 0; i < count && i < 26; i++) {
                void* veh = ((volatile void**)0x007C54F0)[i];
                if (!veh || veh == player) continue;
                *(volatile int*)((char*)veh + 0x4064) = 3;
                *(volatile int*)((char*)veh + 0x4068) = 5;
                *(volatile float*)((char*)veh + 0x453C) = 0.1f;
                retired++;
            }
            if (tick_n <= 3) {
                char buf[32];
                sprintf(buf, "  retired %d AI", retired);
                log_w(buf);
            }

            DWORD elapsed = GetTickCount() - g_trigger_time;
            if (elapsed > 3000) {
                log_w("Triggering mini-restart: laps=10, flag=1");
                *(volatile int*)0x007D05A0 = 10;
                *(volatile char*)0x007CE25D = 1;
                log_w("Restart flag written");
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
        GetModuleFileNameA(h, g_log, MAX_PATH);
        char* slash = strrchr(g_log, '\\');
        if (slash) *(slash + 1) = '\0';
        strcat(g_log, "rf5_log.txt");
        CreateThread(NULL, 0, thread_main, NULL, 0, NULL);
    }
    return TRUE;
}
