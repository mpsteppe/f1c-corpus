/*
 * rf20.c — minimal countdown + restart, no onscreen call
 * NUMPAD0: Phase1=slow+DSQ → Phase1b=countdown(beep only) → Phase2=restart → Phase3=clear → done
 */
#include <windows.h>
#include <stdio.h>

#define HOTKEY VK_NUMPAD0
#define CONTROLLER  0x005EA618
#define EVENT_TABLE 0x005BF9A0

static volatile BOOL g_running = TRUE;
static char g_log[MAX_PATH];
static volatile int g_saved_laps = 10;
static volatile int g_countdown = 0;

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
    *(volatile float*)(CONTROLLER + 0xaf8 + eid * 4) = 0.0f;
    *(volatile float*)(CONTROLLER + 0xae8) = 0.0f;
    *(volatile int*)(CONTROLLER + 0x135c) = 1;
}

static void clear_flags(void) {
    int count = *(volatile int*)0x005C329C;
    void* player = *(volatile void**)0x007C54E8;
    int n = 0;
    for (int i = 0; i < count && i < 26; i++) {
        void* veh = ((volatile void**)0x007C54F0)[i];
        if (!veh || veh == player) continue;
        int was = *(volatile int*)((char*)veh + 0x4064);
        *(volatile int*)((char*)veh + 0x4064) = 0;
        *(volatile int*)((char*)veh + 0x4068) = 0;
        *(volatile float*)((char*)veh + 0x453C) = 1.0f;
        *(volatile float*)((char*)veh + 0x0394) = 0.0f;
        *(volatile int*)((char*)veh + 0x4040) = 1;
        *(volatile int*)((char*)0x5F073C + i * 0x48C0) = 0;
        if (was == 3) n++;
    }
    if (n > 0) {
        char buf[64];
        wsprintfA(buf, "clear_flags: reset %d DSQ cars", n);
        log_w(buf);
    }
}

static void apply_flags(void) {
    int count = *(volatile int*)0x005C329C;
    void* player = *(volatile void**)0x007C54E8;
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
        }
    }
}

static DWORD WINAPI thread_main(LPVOID p) {
    (void)p;
    BOOL prev = FALSE;
    int phase = 0;
    DWORD phase_time = 0;

    log_w("rf23 loaded. NUMPAD0 to trigger.");

    while (g_running) {
        BOOL key = (GetAsyncKeyState(HOTKEY) & 0x8000) != 0;
        if (key && !prev && phase == 0) {
            int laps = *(volatile int*)0x007D05A0;
            g_saved_laps = (laps > 0 && laps <= 200) ? laps : 10;

            phase = 1;
            phase_time = GetTickCount();
            log_w("RED FLAG Phase 1: slowing AI");
            inject_commentary(0x0083);
            Beep(1200, 100);
        }
        prev = key;

        if (phase == 1) {
            apply_flags();
            DWORD t = GetTickCount() - phase_time;
            int pit_entry = *(volatile int*)0x007CE258;
            int override = (key && t > 2000);
            int timeout = (t > 30000);
            if ((pit_entry == 1 || override || timeout) && t > 2000) {
                if (!pit_entry)
                    log_w("Phase 1: pit sensor missed, forced advance");
                phase = 11;
                phase_time = GetTickCount();
                g_countdown = 5;
                log_w("Phase 1b: 5s countdown (beep only)");
            }
        } else if (phase == 11) {
            DWORD elapsed = GetTickCount() - phase_time;
            int sec = 5 - (int)(elapsed / 1000);
            if (sec >= 1 && sec != g_countdown) {
                g_countdown = sec;
                char buf[64];
                wsprintfA(buf, "Countdown %d", sec);
                log_w(buf);
                Beep(800, 80);
            }
            if (elapsed >= 5000) {
                char msg[64];
                wsprintfA(msg, "Phase 2: countdown done, laps=%d, restarting", g_saved_laps);
                log_w(msg);
                *(volatile int*)0x007D05A0 = g_saved_laps;
                *(volatile char*)0x007CE25D = 1;
                phase = 2;
                phase_time = GetTickCount();
                Beep(600, 200);
            }
        } else if (phase == 2) {
            int gs = *(volatile int*)0x007C569C;
            if (gs == 5 && GetTickCount() - phase_time > 500) {
                log_w("Phase 3: clearing flags");
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
        strcpy(g_log, "%USERPROFILE%\\Desktop\\f1c_ida_decompiled\\mods\\red_flag_v2\\rf23_log.txt");
        CreateThread(NULL, 0, thread_main, NULL, 0, NULL);
    } else if (reason == DLL_PROCESS_DETACH) {
        g_running = FALSE;
    }
    return TRUE;
}
