/**
 * oph.c — Safety Car Plugin v2 for F1 Challenge 99-02
 *
 * Drop-in replacement for oph.dll. Game loads it at startup via
 * LoadLibraryA("oph.dll") and calls the exported start() function.
 *
 * Compile (MinGW): i686-w64-mingw32-gcc -shared -Os -s -o oph.dll oph.c -static-libgcc
 * Compile (MSVC):  cl /LD /O2 /GS- oph.c
 *
 * Place oph.dll next to F1 Challenge Online.exe. Game loads it automatically.
 *
 * Safety car vehicle: drop zzz_safety_car.veh (Number=99) in your season directory.
 * The game auto-loads it; this DLL finds it by car number and manages its state.
 *
 * All addresses from Ghidra decompilation (retail exe).
 * References: docs/12-globals-reference.md, docs/13-struct-offsets.md
 */

#define _WIN32_WINNT 0x0501
#include <windows.h>
#include <stdio.h>

/* ========================================================================
 * Game Memory Addresses
 * ========================================================================
 */

/* Globals (see docs/12) */
#define VEHICLE_PTR_ARRAY   ((void**)0x007c54f0)   /* array of vehicle struct ptrs */
#define VEHICLE_COUNT       (*(int*)0x005c329c)     /* number of active vehicles */
#define VEH_FILE_COUNT      (*(int*)0x008ac390)     /* count of loaded .veh definitions */
#define RACE_PHASE          (*(int*)0x007c56a8)     /* 0..7 race phase */
#define SESSION_TYPE        (*(int*)0x007c56a4)     /* 7=race, 6=quali, etc */
#define RACE_ACTIVE_FLAG    (*(int*)0x007d0308)     /* 1 when race is live */

/* Vehicle struct offsets (AI section, see docs/13) */
#define OFF_FINISH_STATE    0x4064   /* int: 0=running, 1=finished, 2=DNF, 3=DSQ */
#define OFF_SAFETY_FOLLOW   0x443c   /* int: 1=follow safety car, 0=normal */
#define OFF_QUEUE_ARRAY     0x44a8   /* int**: AI command queue (allocated, capacity=10) */
#define OFF_QUEUE_COUNT     0x44b0   /* int: last-filled index; -1=empty, 0..9=valid entries */
#define OFF_DRIVER_NUMBER   0x489c   /* int: car number from .veh Number field (docs/06:1237) */

/* Safety car vehicle identification */
#define SC_CAR_NUMBER       99       /* Number= value in zzz_safety_car.veh */

/* ========================================================================
 * Tunables
 * ========================================================================
 */

#define DEPLOY_DNF_THRESHOLD    1       /* DNF count to trigger safety car */
#define ACTIVE_DURATION_MS      90000   /* how long safety car stays out */
#define COOLDOWN_MS             45000   /* min time between deployments */
#define TICK_MS                 200     /* monitor thread interval */
#define QUEUE_CAPACITY          10      /* max commands in AI queue */

/* Manual trigger keys (testing) */
#define KEY_MANUAL_DEPLOY       VK_NUMPAD8  /* force safety car deployment (Num8) */
#define KEY_MANUAL_WITHDRAW     VK_NUMPAD2  /* force safety car withdrawal (Num2) */

/* ========================================================================
 * State Machine
 * ======================================================================== */

typedef enum {
    SC_IDLE = 0,
    SC_DEPLOYING,
    SC_ACTIVE,
    SC_WITHDRAWING,
    SC_COOLDOWN
} State;

static State  g_state  = SC_IDLE;
static DWORD  g_t0     = 0;       /* time current state started */
static int    g_baseline_dnf = 0; /* DNF count at last reset */

/* Safety car vehicle — found at startup by car number 99 */
static void*  g_sc_vehicle = NULL;

/* Debounce for manual trigger keys */
static int g_prev_deploy_key   = 0;
static int g_prev_withdraw_key = 0;

/* ========================================================================
 * Core Helpers
 * ======================================================================== */

/* Count vehicles with FinishState == 2 (DNF). Excludes the SC car. */
static int dnf_count(void)
{
    int i, c, n;
    void* v;
    c = 0;
    n = VEHICLE_COUNT;
    for (i = 0; i < n; i++) {
        v = VEHICLE_PTR_ARRAY[i];
        if (!v || v == g_sc_vehicle) continue;
        if (*(int*)((char*)v + OFF_FINISH_STATE) == 2)
            c++;
    }
    return c;
}

/* Set SafetyCarFollowFlag on all race vehicles (excludes SC car itself).
 * If enable=1, also inject command 0xe into each AI's command queue.
 */
static void safety_flags(int enable)
{
    int i, j, n;
    int c, dup, new_idx;
    void* v;
    int** pq;
    int*  pc;
    int*  q;

    n = VEHICLE_COUNT;
    for (i = 0; i < n; i++) {
        v = VEHICLE_PTR_ARRAY[i];
        if (!v || v == g_sc_vehicle) continue;

        /* Always set the flag */
        *(int*)((char*)v + OFF_SAFETY_FOLLOW) = enable ? 1 : 0;

        if (!enable) continue;

        /* Direct queue injection — avoids __thiscall calling convention.
         * Queue layout: int pairs [cmd, arg, cmd, arg, ...] 
         * Count at OFF_QUEUE_COUNT (-1 = empty)
         */
        pq = (int**)((char*)v + OFF_QUEUE_ARRAY);
        pc = (int*)((char*)v + OFF_QUEUE_COUNT);
        q  = *pq;
        c  = *pc;

        if (!q) continue;

        /* c is last-filled index: -1=empty, 0..9=valid entries */
        new_idx = c + 1;  /* -1+1=0 for empty queue */
        if (new_idx >= QUEUE_CAPACITY) continue;

        /* Dedup: when c=-1, loop body never runs */
        dup = 0;
        for (j = 0; j <= c; j++) {
            if (q[j * 2] == 0x0e) { dup = 1; break; }
        }
        if (dup) continue;

        /* Append (0x0e, 0) after last filled entry */
        q[new_idx * 2]     = 0x0e;
        q[new_idx * 2 + 1] = 0;
        *pc = new_idx;
    }
}

/* ========================================================================
 * Safety Car Vehicle Management
 * ========================================================================
 * Scans VEHICLE_PTR_ARRAY for the car with Number=99 (OFF_DRIVER_NUMBER).
 * Must be called after DynMan::Init() has run — i.e., once the race is live.
 */

static void* find_sc_vehicle(void)
{
    int i, n;
    void* v;
    n = VEHICLE_COUNT;
    for (i = 0; i < n; i++) {
        v = VEHICLE_PTR_ARRAY[i];
        if (!v) continue;
        if (*(int*)((char*)v + OFF_DRIVER_NUMBER) == SC_CAR_NUMBER)
            return v;
    }
    return NULL;
}

/* Park (active=0) or release (active=1) the safety car.
 * Parked: FinishState=3 (DSQ) — excluded from scoring and race-end logic.
 * Active: FinishState=0 (running) — car drives the track like a normal AI.
 *
 * TODO: add speed governor (clamp AI target speed to ~80 km/h).
 * TODO: teleport to pit lane when parked (needs world-position write offset).
 * TODO: set +0x4400 on followers to SC car world position for physical follow.
 */
static void sc_set_active(int active)
{
    if (!g_sc_vehicle) return;
    *(int*)((char*)g_sc_vehicle + OFF_FINISH_STATE) = active ? 0 : 3;
}

/* ========================================================================
 * HUD Display + File Log
 * ========================================================================
 * void __cdecl FUN_0045bd10(const char* str, int priority, int color)
 * Priority 2=medium, 3=high. Color 0x1020304 = auto (default per priority).
 *
 * Also writes every message to LOG\oph_debug.txt for crash diagnosis.
 */

typedef void (__cdecl *FN_MSG)(const char*, int, int);
#define hud_raw    ((FN_MSG)0x0045bd10)
#define HUD_COL_Y  0x00ffff00   /* yellow */
#define HUD_COL_G  0x0000ff00   /* green */
#define HUD_COL_R  0x00ff0000   /* red */
#define HUD_PRI    3

static void log_msg(const char* s)
{
    FILE* f = fopen("LOG\\oph_debug.txt", "a");
    if (f) { fprintf(f, "%lu: %s\n", (unsigned long)GetTickCount(), s); fclose(f); }
}

static void hud(const char* s, int col)
{
    log_msg(s);
    hud_raw(s, HUD_PRI, col);
}

/* ========================================================================
 * Manual Key Override
 * ========================================================================
 * Check for F9 (deploy) / F10 (withdraw) at the start of each tick.
 * Uses rising-edge detection to fire once per press.
 */

static void check_manual_keys(DWORD now)
{
    int deploy_down   = GetAsyncKeyState(KEY_MANUAL_DEPLOY)   & 1;
    int withdraw_down = GetAsyncKeyState(KEY_MANUAL_WITHDRAW) & 1;

    /* F9 rising edge: deploy safety car */
    if (deploy_down && !g_prev_deploy_key) {
        /* Force IDLE → DEPLOYING transition regardless of DNF count */
        if (g_state == SC_IDLE || g_state == SC_COOLDOWN) {
            g_state = SC_DEPLOYING;
            g_t0    = now;
            hud("MANUAL: SAFETY CAR DEPLOYED (NUM8)", HUD_COL_Y);
        } else {
            hud("MANUAL: Already in safety car mode", HUD_COL_R);
        }
    }

    /* F10 rising edge: withdraw safety car */
    if (withdraw_down && !g_prev_withdraw_key) {
        if (g_state == SC_ACTIVE || g_state == SC_DEPLOYING) {
            g_state = SC_WITHDRAWING;
            g_t0    = now;
            hud("MANUAL: SAFETY CAR WITHDRAWN (NUM2)", HUD_COL_G);
        } else if (g_state == SC_COOLDOWN) {
            /* Skip cooldown — go straight back to IDLE */
            g_state = SC_IDLE;
            g_t0    = now;
            g_baseline_dnf = dnf_count();
            hud("MANUAL: COOLDOWN SKIPPED (F10)", HUD_COL_G);
        } else {
            hud("MANUAL: Safety car not active", HUD_COL_Y);
        }
    }

    g_prev_deploy_key   = deploy_down;
    g_prev_withdraw_key = withdraw_down;
}

/* ========================================================================
 * State Machine Tick
 * ======================================================================== */

static void tick(void)
{
    DWORD now, dt;
    int dnf;

    now = GetTickCount();
    dt  = now - g_t0;

    /* Manual key override — checked every tick */
    check_manual_keys(now);

    switch (g_state) {

    case SC_IDLE:
        /* Keep SC car parked (DSQ) and re-arm DNF baseline */
        sc_set_active(0);
        if (SESSION_TYPE != 7 || !RACE_ACTIVE_FLAG) {
            g_baseline_dnf = dnf_count();
            break;
        }
        dnf = dnf_count();
        if (dnf - g_baseline_dnf >= DEPLOY_DNF_THRESHOLD) {
            g_state = SC_DEPLOYING;
            g_t0    = now;
            hud("SAFETY CAR DEPLOYED", HUD_COL_Y);
        }
        break;

    case SC_DEPLOYING:
        log_msg("tick: SC_DEPLOYING - calling sc_set_active(1)");
        sc_set_active(1);
        log_msg("tick: sc_set_active done - calling safety_flags(1)");
        safety_flags(1);
        log_msg("tick: safety_flags done");
        g_state = SC_ACTIVE;
        g_t0    = now;
        hud("SAFETY CAR ON TRACK - REDUCE SPEED", HUD_COL_Y);
        break;

    case SC_ACTIVE:
        /* Heartbeat: re-assert flags and SC active state every ~5 s */
        if (dt % 5000 < TICK_MS) {
            sc_set_active(1);
            safety_flags(1);
        }
        if (dt >= ACTIVE_DURATION_MS) {
            g_state = SC_WITHDRAWING;
            g_t0    = now;
            hud("SAFETY CAR RETURNING TO PITS", HUD_COL_Y);
        }
        break;

    case SC_WITHDRAWING:
        sc_set_active(0);
        safety_flags(0);
        g_state = SC_COOLDOWN;
        g_t0    = now;
        hud("RACING - GREEN FLAG", HUD_COL_G);
        break;

    case SC_COOLDOWN:
        sc_set_active(0);
        if (dt >= COOLDOWN_MS) {
            g_state = SC_IDLE;
            g_baseline_dnf = dnf_count();
        }
        break;
    }
}

/* ========================================================================
 * Monitor Thread
 * ======================================================================== */

DWORD WINAPI monitor(LPVOID lp)
{
    (void)lp;

    log_msg("monitor: thread started, waiting for race");

    /* Wait for race session to start (DynMan::Init runs before this point) */
    for (;;) {
        if (SESSION_TYPE == 7 && RACE_ACTIVE_FLAG) break;
        Sleep(500);
    }

    log_msg("monitor: race detected, scanning vehicles");

    /* Locate the safety car vehicle by its car number (99) */
    {
        char buf[128];
        sprintf(buf, "monitor: VEHICLE_COUNT=%d SESSION_TYPE=%d RACE_ACTIVE_FLAG=%d",
                VEHICLE_COUNT, SESSION_TYPE, RACE_ACTIVE_FLAG);
        log_msg(buf);
    }
    g_sc_vehicle = find_sc_vehicle();
    if (g_sc_vehicle) {
        char buf[64];
        sprintf(buf, "monitor: SC vehicle found at %p", g_sc_vehicle);
        log_msg(buf);
        sc_set_active(0);   /* park immediately — DSQ from scoring */
        hud("SAFETY CAR PLUGIN ACTIVE - NUM8=DEPLOY NUM2=WITHDRAW", HUD_COL_Y);
    } else {
        log_msg("monitor: SC vehicle NOT found");
        hud("SC PLUGIN: no safety car found (add zzz_safety_car.veh, Number=99)", HUD_COL_R);
        hud("SC PLUGIN: running without physical SC vehicle", HUD_COL_Y);
    }

    g_baseline_dnf = dnf_count();

    for (;;) {
        tick();
        Sleep(TICK_MS);
    }
    return 0;
}

/* ========================================================================
 * DLL Exports
 * ========================================================================
 * Game does:
 *   h = LoadLibraryA("oph.dll");
 *   start = GetProcAddress(h, "start");
 *   port  = GetProcAddress(h, "port");   // stored, never called
 *   ip    = GetProcAddress(h, "ip");     // stored, never called
 *   start();
 */

__declspec(dllexport) void __cdecl start(void)
{
    HANDLE h = CreateThread(NULL, 0, monitor, NULL, 0, NULL);
    if (h) CloseHandle(h);
}

__declspec(dllexport) int __cdecl port(void) { return 0; }
__declspec(dllexport) int __cdecl ip(void)   { return 0; }

/* ========================================================================
 * DllMain
 * ======================================================================== */

BOOL WINAPI DllMain(HINSTANCE h, DWORD reason, LPVOID reserved)
{
    if (reason == DLL_PROCESS_ATTACH)
        DisableThreadLibraryCalls(h);
    return TRUE;
}
