/*
 * rf7.c — proper state machine
 * NUMPAD0: Phase1=slow+DSQ → Phase2=restart (on pit entry) → Phase3=clear(3s) → done
 */
#include <windows.h>
#include <stdio.h>

#define HOTKEY VK_NUMPAD0

#define CONTROLLER  0x005EA618
#define EVENT_TABLE 0x005BF9A0

static volatile BOOL g_running = TRUE;
static char g_log[MAX_PATH];
static volatile int g_saved_laps = 10;

static void log_w(const char* s) {
    FILE* f = fopen(g_log, "a");
    if (f) { fprintf(f, "[%lu] %s\n", GetTickCount(), s); fclose(f); }
}

static void inject_commentary(int eid) {
    int table_pri   = *(volatile int*)(EVENT_TABLE + eid * 0x14 + 0x00);
    int table_score = *(volatile int*)(EVENT_TABLE + eid * 0x14 + 0x10);
    uintptr_t qhead = CONTROLLER + 0x864;

    *(volatile int*)(qhead + 0x00) = eid;
    *(volatile int*)(qhead + 0x04) = table_score;
    *(volatile int*)(qhead + 0x08) = 0;
    *(volatile float*)(qhead + 0x0c) = -1.0f;
    *(volatile int*)(qhead + 0x10) = -1;
    *(volatile int*)(qhead + 0x14) = -1;
    *(volatile int*)(qhead + 0x18) = -1;
    *(volatile int*)(qhead + 0x1c) = table_pri;

    *(volatile float*)(CONTROLLER + 0xaf8 + eid * 4) = 0.0f;  /* reset event cooldown ts */
    *(volatile float*)(CONTROLLER + 0xae8) = 0.0f;             /* reset playback timestamp */
    *(volatile int*)(CONTROLLER + 0x135c) = 1;                 /* Starter: trigger playback */
}

static void clear_flags(void) {
    int count = *(volatile int*)0x005C329C;
    void* player = *(volatile void**)0x007C54E8;
    for (int i = 0; i < count && i < 26; i++) {
        void* veh = ((volatile void**)0x007C54F0)[i];
        if (!veh || veh == player) continue;
        if (*(volatile int*)((char*)veh + 0x4064) == 3) {
            *(volatile int*)((char*)veh + 0x4064) = 0;
            *(volatile int*)((char*)veh + 0x4068) = 0;
            *(volatile float*)((char*)veh + 0x453C) = 1.0f;
            *(volatile float*)((char*)veh + 0x0394) = 0.0f;
            *(volatile int*)((char*)veh + 0x4040) = 1;
            *(volatile int*)((char*)0x5F073C + i * 0x48C0) = 0;
        }
    }
}

static void apply_flags(void) {
    int count = *(volatile int*)0x005C329C;
    void* player = *(volatile void**)0x007C54E8;
    int n = 0;
    for (int i = 0; i < count && i < 26; i++) {
        void* veh = ((volatile void**)0x007C54F0)[i];
        if (!veh || veh == player) continue;
        if (*(volatile int*)((char*)veh + 0x4064) != 3) {
            *(volatile int*)((char*)veh + 0x4064) = 3;
            *(volatile int*)((char*)veh + 0x4068) = 5;
            *(volatile float*)((char*)veh + 0x453C) = 0.1f;
            *(volatile float*)((char*)veh + 0x0394) = 1.0f;
            *(volatile int*)((char*)veh + 0x4040) = 2;
            *(volatile int*)((char*)0x5F073C + i * 0x48C0) = 2;
            n++;
        }
    }
    (void)n;
}

static DWORD WINAPI thread_main(LPVOID p) {
    (void)p;
    BOOL prev = FALSE;
    int phase = 0;      /* 0=idle, 1=pre-restart, 2=post-restart, 3=done */
    DWORD phase_time = 0;

    log_w("rf7 loaded. NUMPAD0 to trigger.");

    while (g_running) {
        BOOL key = (GetAsyncKeyState(HOTKEY) & 0x8000) != 0;
        if (key && !prev && phase == 0) {
            int laps = *(volatile int*)0x007D05A0;
            g_saved_laps = (laps > 0 && laps <= 200) ? laps : 10;

            phase = 1;
            phase_time = GetTickCount();
            log_w("RED FLAG Phase 1: slowing AI");
            inject_commentary(0x0083);  /* PWS_RED01.mp2 */
            log_w("PWS_RED01 injected");
            Beep(1200, 100);
        }
        prev = key;

        if (phase == 1) {
            apply_flags();
            /* Restart when player PHYSICALLY enters pit lane */
            int pit_entry = *(volatile int*)0x007CE258;
            if (pit_entry == 1 && GetTickCount() - phase_time > 2000) {
                char msg[64];
                wsprintfA(msg, "Phase 2: player in pit lane, laps=%d, restarting", g_saved_laps);
                log_w(msg);
                *(volatile int*)0x007D05A0 = g_saved_laps;
                *(volatile char*)0x007CE25D = 1;
                phase = 2;
                phase_time = GetTickCount();
                Beep(600, 200);
            }
        } else if (phase == 2) {
            /* Wait for GameState to return to 5 (race), min 500ms after restart write */
            int gs = *(volatile int*)0x007C569C;
            if (gs == 5 && GetTickCount() - phase_time > 500) {
                log_w("Phase 3: clearing flags, cars exit pits");
                phase = 3;
                phase_time = GetTickCount();
            }
        } else if (phase == 3) {
            clear_flags();
            if (GetTickCount() - phase_time > 3000) {
                log_w("Done.");
                phase = 0;
                Beep(300, 300);
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
        strcat(g_log, "rf7_log.txt");
        CreateThread(NULL, 0, thread_main, NULL, 0, NULL);
    } else if (reason == DLL_PROCESS_DETACH) {
        g_running = FALSE;
    }
    return TRUE;
}
