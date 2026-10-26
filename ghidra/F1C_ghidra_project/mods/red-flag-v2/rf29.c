/*
 * rf29.c — Red flag with DNF car grid exclusion via SceneRenderUpdate hook
 *
 * Approach: Before restart, patch the `call SceneRenderUpdate` at 0x42C409
 * in DynMan_Restart to jump to our trampoline. The trampoline checks if
 * the vehicle (ecx) is in the DNF list — if so, skips the call entirely.
 * DNF cars never get grid-placed; their struct retains retired state.
 *
 * Speed cap raised from 0.1 to 0.35 (~110 km/h) for realism.
 */
#include <windows.h>
#include <stdio.h>

#define HOTKEY VK_NUMPAD0
#define CONTROLLER  0x005EA618
#define EVENT_TABLE 0x005BF9A0
#define COUNTDOWN_SEC 5
#define MAX_CARS 26
#define SPEED_CAP_SLOW 0.35f

/* DynMan_Restart call site: 0x42C409 = E8 xx xx xx xx (call SceneRenderUpdate) */
#define CALL_SITE       0x0042C409
#define CALL_SIZE       5
/* SceneRenderUpdate is at 0x4C6D90 */
#define SCENE_RENDER_UPDATE 0x004C6D90

static volatile BOOL g_running = TRUE;
static char g_log[MAX_PATH];
static volatile int g_saved_laps = 10;
static volatile int g_last_sec = 0;
static int g_saved_positions[MAX_CARS];
static int g_saved_qual[MAX_CARS];
static int g_saved_finishstate[MAX_CARS];
static int g_saved_reasoncode[MAX_CARS];
static int g_flag_applied;

/* Hook state */
static BYTE g_orig_bytes[CALL_SIZE];
static BOOL g_hook_installed = FALSE;
static void* g_dnf_ptrs[MAX_CARS];
static int g_dnf_count = 0;

static void log_w(const char* s) {
    FILE* f = fopen(g_log, "a");
    if (f) { fprintf(f, "[%lu] %s\n", GetTickCount(), s); fclose(f); }
}

/* ----- SceneRenderUpdate hook trampoline -----
 *
 * Built as raw x86 machine code in an executable page.
 * ecx = vehicle ptr, [esp+4] = 1 (pushed arg).
 * Checks ecx against g_dnf_ptrs[0..g_dnf_count-1].
 * If DNF: ret 4 (skip call, clean stack).
 * If not: jmp SceneRenderUpdate (tail-call).
 */
static BYTE* g_trampoline = NULL;

static BOOL build_trampoline(void) {
    /*
     * 50               push eax
     * 52               push edx
     * B8 00000000       mov eax, 0
     * loop (offset 5):
     * 3B 05 [&g_dnf_count]  cmp eax, [g_dnf_count]
     * 7D 0E            jge not_dnf (offset 25)
     * 8B 14 85 [&g_dnf_ptrs] mov edx, [g_dnf_ptrs + eax*4]
     * 39 D1            cmp ecx, edx
     * 74 05            je is_dnf (offset 22)
     * 40               inc eax
     * EB EE            jmp loop (offset 5)
     * is_dnf (offset 22):
     * 5A               pop edx
     * 58               pop eax
     * C2 04 00         ret 4
     * not_dnf (offset 25):
     * 5A               pop edx
     * 58               pop eax
     * B8 [SceneRenderUpdate] mov eax, 0x004C6D90
     * FF E0            jmp eax
     */
    g_trampoline = (BYTE*)VirtualAlloc(NULL, 64,
        MEM_COMMIT | MEM_RESERVE, PAGE_EXECUTE_READWRITE);
    if (!g_trampoline) return FALSE;

    BYTE* p = g_trampoline;
    *p++ = 0x50;                                    /* push eax */
    *p++ = 0x52;                                    /* push edx */
    *p++ = 0xB8; *(DWORD*)p = 0; p += 4;           /* mov eax, 0 */
    /* offset 7: loop */
    *p++ = 0x3B; *p++ = 0x05;                       /* cmp eax, [imm32] */
    *(DWORD*)p = (DWORD)(uintptr_t)&g_dnf_count; p += 4;
    *p++ = 0x7D; *p++ = 0x13;                       /* jge +19 -> not_dnf */
    *p++ = 0x8B; *p++ = 0x14; *p++ = 0x85;          /* mov edx, [eax*4+imm32] */
    *(DWORD*)p = (DWORD)(uintptr_t)&g_dnf_ptrs; p += 4;
    *p++ = 0x39; *p++ = 0xD1;                       /* cmp ecx, edx */
    *p++ = 0x74; *p++ = 0x03;                       /* je +3 -> is_dnf */
    *p++ = 0x40;                                     /* inc eax */
    *p++ = 0xEB;                                     /* jmp loop */
    /* calculate relative offset back to loop (offset 7) */
    *(char*)p = (char)(7 - (int)(p - g_trampoline + 1)); p++;
    /* is_dnf: */
    *p++ = 0x5A;                                     /* pop edx */
    *p++ = 0x58;                                     /* pop eax */
    *p++ = 0xC2; *(WORD*)p = 4; p += 2;             /* ret 4 */
    /* not_dnf: */
    *p++ = 0x5A;                                     /* pop edx */
    *p++ = 0x58;                                     /* pop eax */
    *p++ = 0xB8; *(DWORD*)p = SCENE_RENDER_UPDATE; p += 4; /* mov eax, addr */
    *p++ = 0xFF; *p++ = 0xE0;                        /* jmp eax */

    return TRUE;
}

static BOOL install_hook(void) {
    if (!g_trampoline && !build_trampoline())
        return FALSE;

    DWORD old_protect;
    memcpy(g_orig_bytes, (void*)CALL_SITE, CALL_SIZE);

    if (!VirtualProtect((void*)CALL_SITE, CALL_SIZE, PAGE_EXECUTE_READWRITE, &old_protect))
        return FALSE;

    BYTE patch[CALL_SIZE];
    patch[0] = 0xE8;
    DWORD rel = (DWORD)((uintptr_t)g_trampoline - (CALL_SITE + 5));
    memcpy(patch + 1, &rel, 4);
    memcpy((void*)CALL_SITE, patch, CALL_SIZE);

    VirtualProtect((void*)CALL_SITE, CALL_SIZE, old_protect, &old_protect);
    FlushInstructionCache(GetCurrentProcess(), (void*)CALL_SITE, CALL_SIZE);
    g_hook_installed = TRUE;
    return TRUE;
}

static void remove_hook(void) {
    if (!g_hook_installed) return;
    DWORD old_protect;
    VirtualProtect((void*)CALL_SITE, CALL_SIZE, PAGE_EXECUTE_READWRITE, &old_protect);
    memcpy((void*)CALL_SITE, g_orig_bytes, CALL_SIZE);
    VirtualProtect((void*)CALL_SITE, CALL_SIZE, old_protect, &old_protect);
    FlushInstructionCache(GetCurrentProcess(), (void*)CALL_SITE, CALL_SIZE);
    g_hook_installed = FALSE;
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

static void save_positions(void) {
    int count = *(volatile int*)0x005C329C;
    int dnf_count = 0;
    g_dnf_count = 0;
    for (int i = 0; i < count && i < MAX_CARS; i++) {
        void* veh = ((volatile void**)0x007C54F0)[i];
        if (!veh) continue;
        g_saved_positions[i] = *(volatile int*)((char*)veh + 0x4060);
        g_saved_qual[i] = *(volatile int*)((char*)veh + 0x4058);
        g_saved_finishstate[i] = *(volatile int*)((char*)veh + 0x4064);
        g_saved_reasoncode[i] = *(volatile int*)((char*)veh + 0x4068);
        BYTE ret_flag = *(volatile BYTE*)((char*)veh + 0x4410);
        if (g_saved_finishstate[i] != 0 || ret_flag != 0) {
            if (g_saved_finishstate[i] == 0)
                g_saved_finishstate[i] = 2;
            g_dnf_ptrs[g_dnf_count++] = veh;
            dnf_count++;
        }
    }
    g_flag_applied = 1;
    if (dnf_count > 0) {
        char buf[80];
        wsprintfA(buf, "Saved: %d pre-existing DNFs, hook will skip them", dnf_count);
        log_w(buf);
    }
}

static void apply_flags(void) {
    int count = *(volatile int*)0x005C329C;
    void* player = *(volatile void**)0x007C54E8;
    for (int i = 0; i < count && i < MAX_CARS; i++) {
        void* veh = ((volatile void**)0x007C54F0)[i];
        if (!veh || veh == player) continue;
        if (g_saved_finishstate[i] != 0) continue;
        *(volatile int*)((char*)veh + 0x4064) = 2;    /* FinishState = DNF */
        *(volatile int*)((char*)veh + 0x4068) = 6;    /* ReasonCode = puncture */
        *(volatile BYTE*)((char*)veh + 0x4410) = 1;   /* RetiredFlag */
        *(volatile BYTE*)((char*)veh + 0x45F4) = 0;   /* ActiveFlag */
        *(volatile float*)((char*)veh + 0x453C) = SPEED_CAP_SLOW;
    }
}

static void lock_positions(void) {
    int count = *(volatile int*)0x005C329C;
    for (int i = 0; i < count && i < MAX_CARS; i++) {
        void* veh = ((volatile void**)0x007C54F0)[i];
        if (!veh) continue;
        if (g_saved_finishstate[i] != 0) {
            /* DNF car: QualPos=99 (known safe max from oph.dll) */
            *(volatile int*)((char*)veh + 0x4058) = 198;
        } else {
            int race_pos = g_saved_positions[i];
            if (race_pos > 0)
                *(volatile int*)((char*)veh + 0x4058) = race_pos;
        }
    }
}

static void clear_flags(void) {
    int count = *(volatile int*)0x005C329C;
    void* player = *(volatile void**)0x007C54E8;
    for (int i = 0; i < count && i < MAX_CARS; i++) {
        void* veh = ((volatile void**)0x007C54F0)[i];
        if (!veh || veh == player) continue;
        int orig = g_saved_finishstate[i];
        if (orig == 0) {
            *(volatile int*)((char*)veh + 0x4064) = 0;
            *(volatile int*)((char*)veh + 0x4068) = 0;
            *(volatile float*)((char*)veh + 0x453C) = 1.0f;
            *(volatile BYTE*)((char*)veh + 0x4410) = 0;
            *(volatile BYTE*)((char*)veh + 0x45F4) = 1;
            *(volatile int*)((char*)veh + 0x4040) = 1;
        } else {
            *(volatile int*)((char*)veh + 0x4064) = orig;
            *(volatile int*)((char*)veh + 0x4068) = g_saved_reasoncode[i];
            *(volatile BYTE*)((char*)veh + 0x4410) = 1;
            *(volatile BYTE*)((char*)veh + 0x45F4) = 0;
            *(volatile float*)((char*)veh + 0x453C) = 1.0f;
            *(volatile int*)((char*)veh + 0x4040) = 2;
        }
    }
}

static DWORD WINAPI thread_main(LPVOID p) {
    (void)p;
    BOOL prev = FALSE;
    int phase = 0;
    DWORD phase_time = 0;

    log_w("rf29 loaded. NUMPAD0 to trigger red flag.");

    while (g_running) {
        BOOL key = (GetAsyncKeyState(HOTKEY) & 0x8000) != 0;
        if (key && !prev && phase == 0) {
            int laps = *(volatile int*)0x007D05A0;
            g_saved_laps = (laps > 0 && laps <= 200) ? laps : 10;
            phase = 1;
            phase_time = GetTickCount();
            g_last_sec = COUNTDOWN_SEC;
            save_positions();
            log_w("RED FLAG: 30s countdown started");
            inject_commentary(0x0083);
            Beep(1200, 100);
        }
        prev = key;

        if (phase == 1) {
            /* Phase 1: Countdown — hold retirement flags, slow cars */
            apply_flags();
            DWORD elapsed = GetTickCount() - phase_time;
            int sec = COUNTDOWN_SEC - (int)(elapsed / 1000);
            if (sec != g_last_sec) {
                g_last_sec = sec;
                char buf[64];
                wsprintfA(buf, "T-%d", sec);
                log_w(buf);
                if (sec >= 1) Beep(800, 50);
            }
            if (elapsed >= COUNTDOWN_SEC * 1000) {
                /* Phase 2: Write grid order (DNFs get QualPos past grid), restart */
                lock_positions();

                /* Hook SceneRenderUpdate BEFORE restart — DNF cars skip rebuild */
                if (g_dnf_count > 0) {
                    if (install_hook())
                        log_w("Hook installed: skipping SceneRenderUpdate for DNF cars");
                    else
                        log_w("WARNING: hook install failed");
                }

                *(volatile int*)0x007D05A0 = g_saved_laps;
                *(volatile char*)0x007CE25D = 1;
                phase = 2;
                phase_time = GetTickCount();
                log_w("Restart triggered");
                Beep(600, 300);
            }
        } else if (phase == 2) {
            /* Phase 2: Wait for restart to complete (gs=5) */
            int gs = *(volatile int*)0x007C569C;
            if (gs == 5 && GetTickCount() - phase_time > 500) {
                log_w("Restart complete, clearing flags");
                phase = 3;
                phase_time = GetTickCount();
            }
            if (GetTickCount() - phase_time > 10000) {
                log_w("Restart timeout, clearing flags");
                phase = 3;
                phase_time = GetTickCount();
            }
        } else if (phase == 3) {
            /* Phase 3: Clear flags for active cars, re-retire DNFs.
               Hammer for 10s at 10ms to win vs formation code setting ActiveFlag=1 */
            clear_flags();
            if (GetTickCount() - phase_time > 10000) {
                remove_hook();
                log_w("Red flag sequence complete. Hook removed.");
                phase = 0;
                Beep(300, 300);
            }
        }

        Sleep(phase == 3 ? 10 : 50);
    }
    return 0;
}

BOOL WINAPI DllMain(HINSTANCE h, DWORD reason, LPVOID r) {
    (void)r;
    if (reason == DLL_PROCESS_ATTACH) {
        DisableThreadLibraryCalls(h);
        strcpy(g_log, "%USERPROFILE%\\Desktop\\f1c_ida_decompiled\\mods\\red_flag_v2\\rf29_log.txt");
        CreateThread(NULL, 0, thread_main, NULL, 0, NULL);
    } else if (reason == DLL_PROCESS_DETACH) {
        g_running = FALSE;
        Sleep(100);
        remove_hook();
    }
    return TRUE;
}
