/*
 * red_flag_v2.c — Red Flag mod: puncture injection + AI retirement
 *
 * NUMPAD0: inject tire punctures → AI pits → retire AI → player enters pits → restart
 *
 * Build: C:\msys64\mingw32\bin\gcc.exe -shared -o red_flag_v2.dll red_flag_v2.c -lkernel32 -O2
 */
#include <windows.h>
#include <stdio.h>

#define HOTKEY VK_NUMPAD0

#define ADDR_VEHICLE_COUNT  0x005C329C
#define ADDR_VEHICLE_ARRAY  0x007C54F0
#define ADDR_PLAYER_VEHICLE 0x007C54E8

/* Driver block */
#define ADDR_DRIVER_BASE    0x005F0DEC
#define OFF_PUNCTURE_FL     3568
#define OFF_PUNCTURE_FR     3816
#define OFF_PUNCTURE_RL     4064
#define OFF_PUNCTURE_RR     4312

/* Vehicle struct */
#define OFF_FINISH_STATE    0x4064
#define OFF_REASON_CODE     0x4068
#define OFF_PIT_LANE_STATE  0x4040

/* Restart */
#define ADDR_RESTART_FLAG   0x007CE25D
#define ADDR_PIT_ENTRY      0x007CE258
#define ADDR_LAP_COUNT      0x007D05A0
#define ADDR_GAME_STATE     0x007C569C

/* Commentary */
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

    *(volatile float*)(CONTROLLER + 0xaf8 + eid * 4) = 0.0f;
    *(volatile float*)(CONTROLLER + 0xae8) = 0.0f;
    *(volatile int*)(CONTROLLER + 0x135c) = 1;
}

static void puncture_all_ai(void) {
    int count = *(volatile int*)ADDR_VEHICLE_COUNT;
    void* player = *(volatile void**)ADDR_PLAYER_VEHICLE;
    for (int i = 0; i < count && i < 26; i++) {
        void* veh = ((volatile void**)ADDR_VEHICLE_ARRAY)[i];
        if (!veh || veh == player) continue;

        char* driverBlock = (char*)ADDR_DRIVER_BASE + i * 0x48C0;
        *(volatile float*)(driverBlock + OFF_PUNCTURE_FL) = 0.77f;
        *(volatile float*)(driverBlock + OFF_PUNCTURE_FR) = 0.77f;
        *(volatile float*)(driverBlock + OFF_PUNCTURE_RL) = 0.77f;
        *(volatile float*)(driverBlock + OFF_PUNCTURE_RR) = 0.77f;

        /* Read-back first driver to verify write landed */
        if (i == 0) {
            float rb = *(volatile float*)(driverBlock + OFF_PUNCTURE_RR);
            char msg[64];
            wsprintfA(msg, "  driver0 RR: wrote 0.77f, read-back=%.4f at 0x%08X",
                     rb, (unsigned)(driverBlock + OFF_PUNCTURE_RR));
            log_w(msg);
        }
    }
}

static void retire_all_ai(void) {
    int count = *(volatile int*)ADDR_VEHICLE_COUNT;
    void* player = *(volatile void**)ADDR_PLAYER_VEHICLE;
    for (int i = 0; i < count && i < 26; i++) {
        void* veh = ((volatile void**)ADDR_VEHICLE_ARRAY)[i];
        if (!veh || veh == player) continue;

        *(volatile int*)((char*)veh + OFF_FINISH_STATE) = 3;
        *(volatile int*)((char*)veh + OFF_REASON_CODE) = 5;
    }
}

static DWORD WINAPI thread_main(LPVOID p) {
    (void)p;
    BOOL prev = FALSE;
    int phase = 0;
    DWORD phase_time = 0;

    log_w("red_flag_v2 loaded. NUMPAD0 to trigger.");

    while (g_running) {
        BOOL key = (GetAsyncKeyState(HOTKEY) & 0x8000) != 0;
        if (key && !prev && phase == 0) {
            int laps = *(volatile int*)ADDR_LAP_COUNT;
            g_saved_laps = (laps > 0 && laps <= 200) ? laps : 10;

            phase = 1;
            phase_time = GetTickCount();
            log_w("RED FLAG: injecting punctures on all AI");
            puncture_all_ai();
            inject_commentary(0x0083);
            Beep(1200, 100);
        }
        prev = key;

        if (phase == 1) {
            /* After 5s: retire AI (they should be entering pits) */
            if (GetTickCount() - phase_time > 5000) {
                log_w("Retiring all AI (DSQ)");
                retire_all_ai();
                phase = 2;
            }
        } else if (phase == 2) {
            int pit_entry = *(volatile int*)ADDR_PIT_ENTRY;
            if (pit_entry == 1 && GetTickCount() - phase_time > 2000) {
                char msg[64];
                wsprintfA(msg, "Player in pits, laps=%d, restarting", g_saved_laps);
                log_w(msg);
                *(volatile int*)ADDR_LAP_COUNT = g_saved_laps;
                *(volatile char*)ADDR_RESTART_FLAG = 1;
                phase = 3;
                phase_time = GetTickCount();
                Beep(600, 200);
            }
        } else if (phase == 3) {
            int gs = *(volatile int*)ADDR_GAME_STATE;
            if (gs == 5 && GetTickCount() - phase_time > 500) {
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
        strcat(g_log, "red_flag_v2_log.txt");
        CreateThread(NULL, 0, thread_main, NULL, 0, NULL);
    } else if (reason == DLL_PROCESS_DETACH) {
        g_running = FALSE;
    }
    return TRUE;
}
