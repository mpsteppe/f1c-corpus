/*
 * rf6.c — tick DLL: NUMPAD0 toggles. Keeps AI DSQ'd + slow.
 * Auto-restarts after 5s, then re-applies flags after restart.
 */
#include <windows.h>
#include <stdio.h>

#define HOTKEY VK_NUMPAD0

static volatile BOOL g_running = TRUE;
static char g_log[MAX_PATH];

static void log_w(const char* s) {
    FILE* f = fopen(g_log, "a");
    if (f) { fprintf(f, "[%lu] %s\n", GetTickCount(), s); fclose(f); }
}

static void apply_red_flag(void) {
    int count = *(volatile int*)0x005C329C;
    void* player = *(volatile void**)0x007C54E8;
    int n = 0;
    for (int i = 0; i < count && i < 26; i++) {
        void* veh = ((volatile void**)0x007C54F0)[i];
        if (!veh || veh == player) continue;
        *(volatile int*)((char*)veh + 0x4064) = 3;
        *(volatile int*)((char*)veh + 0x4068) = 5;
        *(volatile float*)((char*)veh + 0x453C) = 0.1f;
        n++;
    }
    if (n > 0) {
        char buf[64];
        sprintf(buf, "Applied DSQ+slow to %d AI", n);
        log_w(buf);
    }
}

static DWORD WINAPI thread_main(LPVOID p) {
    (void)p;
    BOOL prev = FALSE;
    BOOL active = FALSE;
    DWORD trigger_time = 0;
    int last_gs = 0;

    log_w("rf6 loaded. NUMPAD0 to trigger.");

    while (g_running) {
        BOOL key = (GetAsyncKeyState(HOTKEY) & 0x8000) != 0;
        if (key && !prev) {
            if (!active) {
                active = TRUE;
                trigger_time = GetTickCount();
                log_w("RED FLAG ACTIVATED");
                Beep(1200, 100);
            }
        }
        prev = key;

        if (active) {
            apply_red_flag();

            int gs = *(volatile int*)0x007C569C;
            if (gs != last_gs) {
                char buf[32];
                sprintf(buf, "GameState: %d", gs);
                log_w(buf);
                last_gs = gs;
            }

            DWORD elapsed = GetTickCount() - trigger_time;
            if (elapsed > 5000 && gs == 5) {
                log_w("Triggering restart: laps=10");
                *(volatile int*)0x007D05A0 = 10;
                *(volatile char*)0x007CE25D = 1;
                log_w("Restart flag written. Deactivating.");
                Beep(600, 200);
                active = FALSE;  /* done */
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
        strcat(g_log, "rf6_log.txt");
        CreateThread(NULL, 0, thread_main, NULL, 0, NULL);
    } else if (reason == DLL_PROCESS_DETACH) {
        g_running = FALSE;
    }
    return TRUE;
}
