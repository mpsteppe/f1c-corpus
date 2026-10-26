/*
 * rf25.c — 30s countdown + restart with position preservation
 * Fix: copies live race position (+0x4060) to qualifying slot (+0x4058)
 * before triggering restart, so FieldCopy_c330 no-op preserves standings.
 */
#include <windows.h>
#include <stdio.h>

#define HOTKEY VK_NUMPAD0
#define CONTROLLER  0x005EA618
#define EVENT_TABLE 0x005BF9A0
#define COUNTDOWN_SEC 30
#define MAX_CARS 26

static volatile BOOL g_running = TRUE;
static char g_log[MAX_PATH];
static volatile int g_saved_laps = 10;
static volatile int g_last_sec = 0;
static int g_saved_positions[MAX_CARS];
static int g_saved_qual[MAX_CARS];
static int g_saved_finishstate[MAX_CARS];
static int g_flag_applied;

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
    int dnf = 0;
    for (int i = 0; i < count && i < MAX_CARS; i++) {
        void* veh = ((volatile void**)0x007C54F0)[i];
        if (!veh || veh == player) continue;
        int orig = g_saved_finishstate[i];
        if (orig == 0) {
            /* was running, clear DSQ */
            *(volatile int*)((char*)veh + 0x4064) = 0;
            *(volatile int*)((char*)veh + 0x4068) = 0;
            *(volatile float*)((char*)veh + 0x453C) = 1.0f;
            *(volatile float*)((char*)veh + 0x0394) = 0.0f;
            *(volatile int*)((char*)veh + 0x4040) = 1;
            *(volatile int*)((char*)0x5F073C + i * 0x48C0) = 0;
            n++;
        } else {
            /* was DNF/DNF, restore original state */
            *(volatile int*)((char*)veh + 0x4064) = orig;
            *(volatile int*)((char*)veh + 0x4068) = 0;
            *(volatile float*)((char*)veh + 0x453C) = 0.1f;
            *(volatile float*)((char*)veh + 0x0394) = 1.0f;
            *(volatile int*)((char*)veh + 0x4040) = 2;
            *(volatile int*)((char*)0x5F073C + i * 0x48C0) = 2;
            dnf++;
        }
    }
    if (n > 0 || dnf > 0) {
        char buf[64];
        wsprintfA(buf, "clear_flags: %d cars reset, %d kept DNF", n, dnf);
        log_w(buf);
    }
}

static void apply_flags(void) {
    int count = *(volatile int*)0x005C329C;
    void* player = *(volatile void**)0x007C54E8;
    for (int i = 0; i < count && i < MAX_CARS; i++) {
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

static void save_positions(void) {
    int count = *(volatile int*)0x005C329C;
    int dnf_count = 0;
    for (int i = 0; i < count && i < MAX_CARS; i++) {
        void* veh = ((volatile void**)0x007C54F0)[i];
        if (!veh) continue;
        int race_pos = *(volatile int*)((char*)veh + 0x4060);
        int qual_pos = *(volatile int*)((char*)veh + 0x4058);
        int fs = *(volatile int*)((char*)veh + 0x4064);
        g_saved_positions[i] = race_pos;
        g_saved_qual[i] = qual_pos;
        g_saved_finishstate[i] = fs;
        if (fs != 0) dnf_count++;
    }
    g_flag_applied = 1;
    if (dnf_count > 0) {
        char buf[64];
        wsprintfA(buf, "Saved: %d cars already DNF/DNF", dnf_count);
        log_w(buf);
    }
}

static void lock_positions(void) {
    int count = *(volatile int*)0x005C329C;
    for (int i = 0; i < count && i < MAX_CARS; i++) {
        void* veh = ((volatile void**)0x007C54F0)[i];
        if (!veh) continue;
        int race_pos = g_saved_positions[i];
        if (race_pos > 0) {
            *(volatile int*)((char*)veh + 0x4058) = race_pos;
        }
    }
}

static void clear_dnf_grid(void) {
    int count = *(volatile int*)0x005C329C;
    int removed = 0;
    for (int g = 0; g < 48; g++) {
        uintptr_t slot = 0x005EF9A0 + g * 0x48C0;
        int flag = *(volatile int*)slot;
        if (flag != 0 && flag != 1) continue;
        void* slot_veh = *(volatile void**)(slot + 4);
        if (!slot_veh) continue;
        for (int i = 0; i < count && i < MAX_CARS; i++) {
            void* veh = ((volatile void**)0x007C54F0)[i];
            if (veh == slot_veh) {
                if (g_saved_finishstate[i] != 0) {
                    *(volatile int*)slot = -1; /* empty grid slot */
                    removed++;
                }
                break;
            }
        }
    }
    if (removed > 0) {
        char buf[64];
        wsprintfA(buf, "Grid: %d DNF slots cleared", removed);
        log_w(buf);
    }
}

static void restore_qual(void) {
    /* Restore qualifying positions after restart for clean next time */
    int count = *(volatile int*)0x005C329C;
    for (int i = 0; i < count && i < MAX_CARS; i++) {
        void* veh = ((volatile void**)0x007C54F0)[i];
        if (!veh) continue;
        int qual = g_saved_qual[i];
        if (qual > 0) {
            *(volatile int*)((char*)veh + 0x4058) = qual;
        }
    }
}

static DWORD WINAPI thread_main(LPVOID p) {
    (void)p;
    BOOL prev = FALSE;
    int phase = 0;
    DWORD phase_time = 0;

    log_w("rf28 loaded. NUMPAD0 to trigger.");

    while (g_running) {
        BOOL key = (GetAsyncKeyState(HOTKEY) & 0x8000) != 0;
        if (key && !prev && phase == 0) {
            int laps = *(volatile int*)0x007D05A0;
            g_saved_laps = (laps > 0 && laps <= 200) ? laps : 10;
            phase = 1;
            phase_time = GetTickCount();
            g_last_sec = COUNTDOWN_SEC;
            save_positions();
            log_w("RED FLAG: 30s countdown, positions saved");
            inject_commentary(0x0083);
            Beep(1200, 100);
        }
        prev = key;

        if (phase == 1) {
            apply_flags();
            DWORD elapsed = GetTickCount() - phase_time;
            int sec = COUNTDOWN_SEC - (int)(elapsed / 1000);
            if (sec != g_last_sec) {
                g_last_sec = sec;
                char buf[64];
                wsprintfA(buf, "T-%d", sec);
                log_w(buf);
                if (sec <= 5 && sec >= 1) Beep(800, 80);
            }
            if (elapsed >= COUNTDOWN_SEC * 1000) {
                char msg[64];
                wsprintfA(msg, "Timer done, laps=%d, lock_positions + restart", g_saved_laps);
                log_w(msg);
                lock_positions();
                clear_dnf_grid();
                *(volatile int*)0x007D05A0 = g_saved_laps;
                *(volatile char*)0x007CE25D = 1;
                phase = 2;
                phase_time = GetTickCount();
                Beep(600, 300);
            }
        } else if (phase == 2) {
            int gs = *(volatile int*)0x007C569C;
            if (gs == 5 && GetTickCount() - phase_time > 1000) {
                log_w("Phase 3: clearing flags");
                restore_qual();
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
        strcpy(g_log, "%USERPROFILE%\\Desktop\\f1c_ida_decompiled\\mods\\red_flag_v2\\rf28_log.txt");
        CreateThread(NULL, 0, thread_main, NULL, 0, NULL);
    } else if (reason == DLL_PROCESS_DETACH) {
        g_running = FALSE;
    }
    return TRUE;
}
