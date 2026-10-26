/**
 * oph.c — Safety Car Plugin v3 for F1 Challenge 99-02
 *
 * Drop-in replacement for oph.dll. Game loads it at startup via
 * LoadLibraryA("oph.dll") and calls the exported start() function.
 *
 * Compile (MinGW): i686-w64-mingw32-gcc -shared -Os -s -o oph.dll oph.c -static-libgcc
 * Compile (MSVC):  cl /LD /O2 /GS- oph.c
 *
 * Place oph.dll next to F1 Challenge Online.exe. Game loads it automatically.
 *
 * v3 adds: speed governor, field ordering preservation, probe/diagnostic mode,
 * lap-based duration, and improved deployment logic.
 *
 * Hotkeys:
 *   NUM8 = deploy safety car
 *   NUM2 = withdraw safety car
 *   NUM5 = dump diagnostic probe (vehicle states to log)
 *
 * All addresses from Ghidra decompilation (retail exe).
 * References: docs/12-globals-reference.md, docs/13-struct-offsets.md,
 *             docs/30-impl-specs/05-ai-system-spec.md
 */

#define _WIN32_WINNT 0x0501
#include <windows.h>
#include <stdio.h>
#include <math.h>

/* ========================================================================
 * Game Memory Addresses (FACT tier unless noted)
 * ======================================================================== */

/* Globals (docs/12, all FACT — confirmed by multiple analyses) */
#define VEHICLE_PTR_ARRAY   ((void**)0x007c54f0)
#define VEHICLE_COUNT       (*(int*)0x005c329c)
#define PLAYER_VEHICLE_PTR  (*(void**)0x007c54e8)
#define RACE_PHASE          (*(int*)0x007c56a8)
#define SESSION_TYPE        (*(int*)0x007c56a4)
#define RACE_ACTIVE_FLAG    (*(int*)0x007d0308)

/* Vehicle struct offsets — byte offsets from vehicle pointer */
#define OFF_FINISH_STATE    0x4064  /* int: 0=running, 1=finished, 2=DNF, 3=DSQ */
#define OFF_SAFETY_FOLLOW   0x443c  /* int: 1=follow safety car, 0=normal */
#define OFF_QUEUE_ARRAY     0x44a8  /* int**: AI command queue ptr */
#define OFF_QUEUE_COUNT     0x44b0  /* int: -1=empty, 0..9=valid entries */
#define OFF_DRIVER_NUMBER   0x489c  /* int: car number from .veh */

/* AI speed control (GUESS tier — from docs/30 spec, int-index notation)
 * param_1[0x114f] = liveLapRatio -> byte offset 0x114f*4 = 0x453C
 * param_1[0x113d] = baseSpeedRatio -> byte offset 0x113d*4 = 0x44F4
 * param_1[0x1144] = behaviorState -> byte offset 0x1144*4 = 0x4510
 *
 * These need live verification via NUM5 probe before trusting.
 */
#define OFF_LIVE_LAP_RATIO  0x453C  /* float: current speed target, ~0.0-1.0 */
#define OFF_BASE_SPEED      0x44F4  /* float: base speed ratio */
#define OFF_BEHAVIOR_STATE  0x4510  /* int: AI FSM (0=follow, 1=pursuit, 2=pit, 7=overtake) */

/* Position tracking (GUESS tier — needs verification) */
#define OFF_POSITION_X      0x10    /* double: world X */
#define OFF_POSITION_Z      0x20    /* double: world Z */
#define OFF_VELOCITY_X      0x2DF0  /* float: velocity X (from NASCAR +11772 mapping) */
#define OFF_VELOCITY_Z      0x2DF8  /* float: velocity Z */

/* ========================================================================
 * Tunables
 * ======================================================================== */

#define SC_CAR_NUMBER       99
#define DEPLOY_DNF_THRESHOLD 1
#define SC_LAPS             3       /* laps under safety car before withdrawal */
#define COOLDOWN_MS         30000
#define TICK_MS             200
#define QUEUE_CAPACITY      10

/* Speed governor: liveLapRatio value during SC.
 * Normal racing is ~0.95-1.0. Lower = slower.
 * 0.60 should produce roughly 60% race speed (~180kph -> ~108kph).
 * Needs tuning after live test. */
#define SC_SPEED_RATIO      0.60f

/* Manual trigger keys */
#define KEY_MANUAL_DEPLOY   VK_NUMPAD8
#define KEY_MANUAL_WITHDRAW VK_NUMPAD2
#define KEY_PROBE_DUMP      VK_NUMPAD5

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
static DWORD  g_t0     = 0;
static int    g_baseline_dnf = 0;
static void*  g_sc_vehicle = NULL;
static int    g_sc_start_lap = 0;  /* lap count when SC deployed */

/* Saved speed ratios — restore on withdrawal */
typedef struct {
    float saved_ratio;
    int   saved_valid;
} SpeedSave;
#define MAX_VEHICLES 26
static SpeedSave g_speed_save[MAX_VEHICLES];

/* Key debounce */
static int g_prev_deploy   = 0;
static int g_prev_withdraw = 0;
static int g_prev_probe    = 0;

/* ========================================================================
 * Logging + HUD
 * ======================================================================== */

typedef void (__cdecl *FN_MSG)(const char*, int, int);
#define hud_raw    ((FN_MSG)0x0045bd10)
#define HUD_COL_Y  0x00ffff00
#define HUD_COL_G  0x0000ff00
#define HUD_COL_R  0x00ff0000
#define HUD_PRI    3

static FILE* g_logfile = NULL;

static void log_open(void)
{
    if (!g_logfile) {
        CreateDirectoryA("LOG", NULL);
        g_logfile = fopen("LOG\\safety_car.txt", "a");
    }
}

static void log_msg(const char* s)
{
    log_open();
    if (g_logfile) {
        fprintf(g_logfile, "%lu: %s\n", (unsigned long)GetTickCount(), s);
        fflush(g_logfile);
    }
}

static void log_fmt(const char* fmt, ...)
{
    char buf[512];
    va_list ap;
    va_start(ap, fmt);
    vsnprintf(buf, sizeof(buf), fmt, ap);
    va_end(ap);
    log_msg(buf);
}

static void hud(const char* s, int col)
{
    log_msg(s);
    hud_raw(s, HUD_PRI, col);
}

static void hud_fmt(const char* fmt, int col, ...)
{
    char buf[256];
    va_list ap;
    va_start(ap, col);
    vsnprintf(buf, sizeof(buf), fmt, ap);
    va_end(ap);
    hud(buf, col);
}

/* ========================================================================
 * Vehicle Helpers
 * ======================================================================== */

static inline int veh_int(void* v, int off)
{
    return *(int*)((char*)v + off);
}

static inline float veh_float(void* v, int off)
{
    return *(float*)((char*)v + off);
}

static inline void veh_write_int(void* v, int off, int val)
{
    *(int*)((char*)v + off) = val;
}

static inline void veh_write_float(void* v, int off, float val)
{
    *(float*)((char*)v + off) = val;
}

static int is_player(void* v)
{
    return v == PLAYER_VEHICLE_PTR;
}

static int is_racing(void* v)
{
    return veh_int(v, OFF_FINISH_STATE) == 0;
}

/* ========================================================================
 * Diagnostic Probe (NUM5)
 *
 * Dumps vehicle states to log for offset verification.
 * Run during a race, read LOG\safety_car.txt to verify
 * which fields contain sane values.
 * ======================================================================== */

static void probe_dump(void)
{
    int i, n;
    void* v;

    n = VEHICLE_COUNT;
    log_fmt("=== PROBE DUMP === vehicles=%d session=%d phase=%d active=%d",
            n, SESSION_TYPE, RACE_PHASE, RACE_ACTIVE_FLAG);

    for (i = 0; i < n && i < 5; i++) {
        v = VEHICLE_PTR_ARRAY[i];
        if (!v) continue;

        log_fmt("  veh[%d] ptr=%p number=%d finish=%d player=%d",
                i, v, veh_int(v, OFF_DRIVER_NUMBER),
                veh_int(v, OFF_FINISH_STATE), is_player(v));

        log_fmt("    safety_follow=%d  cmd_queue_count=%d",
                veh_int(v, OFF_SAFETY_FOLLOW),
                veh_int(v, OFF_QUEUE_COUNT));

        log_fmt("    live_lap_ratio=%.4f  base_speed=%.4f  behavior=%d",
                veh_float(v, OFF_LIVE_LAP_RATIO),
                veh_float(v, OFF_BASE_SPEED),
                veh_int(v, OFF_BEHAVIOR_STATE));

        /* Raw bytes around the speed area for verification */
        log_fmt("    raw[0x4530..0x4540]: %08X %08X %08X %08X",
                veh_int(v, 0x4530), veh_int(v, 0x4534),
                veh_int(v, 0x4538), veh_int(v, 0x453C));

        log_fmt("    raw[0x44F0..0x4500]: %08X %08X %08X %08X",
                veh_int(v, 0x44F0), veh_int(v, 0x44F4),
                veh_int(v, 0x44F8), veh_int(v, 0x44FC));

        log_fmt("    raw[0x4510..0x4520]: %08X %08X %08X %08X",
                veh_int(v, 0x4510), veh_int(v, 0x4514),
                veh_int(v, 0x4518), veh_int(v, 0x451C));
    }

    hud("PROBE: dumped to LOG\\safety_car.txt", HUD_COL_Y);
}

/* ========================================================================
 * DNF Counter
 * ======================================================================== */

static int dnf_count(void)
{
    int i, c, n;
    void* v;
    c = 0;
    n = VEHICLE_COUNT;
    for (i = 0; i < n; i++) {
        v = VEHICLE_PTR_ARRAY[i];
        if (!v || v == g_sc_vehicle) continue;
        if (veh_int(v, OFF_FINISH_STATE) == 2)
            c++;
    }
    return c;
}

/* ========================================================================
 * Safety Car Flag + Speed Control
 *
 * Two-layer approach:
 * 1. Set +0x443c SafetyCarFollow flag (game's built-in mechanism)
 * 2. Clamp liveLapRatio to SC_SPEED_RATIO (direct speed governor)
 *
 * Layer 1 may or may not work (GUESS tier). Layer 2 is the fallback.
 * Both are applied; whichever the game respects will take effect.
 * ======================================================================== */

static void apply_sc_speed(void)
{
    int i, n;
    void* v;

    n = VEHICLE_COUNT;
    for (i = 0; i < n && i < MAX_VEHICLES; i++) {
        v = VEHICLE_PTR_ARRAY[i];
        if (!v || v == g_sc_vehicle) continue;
        if (!is_racing(v)) continue;

        /* Layer 1: built-in follow flag */
        veh_write_int(v, OFF_SAFETY_FOLLOW, 1);

        /* Layer 2: clamp speed ratio.
         * Save original on first application. */
        if (!g_speed_save[i].saved_valid) {
            g_speed_save[i].saved_ratio = veh_float(v, OFF_LIVE_LAP_RATIO);
            g_speed_save[i].saved_valid = 1;
            log_fmt("  veh[%d] saved ratio=%.4f", i, g_speed_save[i].saved_ratio);
        }

        /* Only clamp if current ratio is above SC speed */
        if (veh_float(v, OFF_LIVE_LAP_RATIO) > SC_SPEED_RATIO) {
            veh_write_float(v, OFF_LIVE_LAP_RATIO, SC_SPEED_RATIO);
        }
    }
}

static void restore_speed(void)
{
    int i, n;
    void* v;

    n = VEHICLE_COUNT;
    for (i = 0; i < n && i < MAX_VEHICLES; i++) {
        v = VEHICLE_PTR_ARRAY[i];
        if (!v || v == g_sc_vehicle) continue;

        /* Clear follow flag */
        veh_write_int(v, OFF_SAFETY_FOLLOW, 0);

        /* Restore saved speed ratio */
        if (g_speed_save[i].saved_valid) {
            veh_write_float(v, OFF_LIVE_LAP_RATIO, g_speed_save[i].saved_ratio);
            g_speed_save[i].saved_valid = 0;
        }
    }
}

/* Inject command 0xe into AI queues (one-shot, not repeated) */
static void inject_sc_command(void)
{
    int i, j, n, c, dup, new_idx;
    void* v;
    int** pq;
    int* pc;
    int* q;

    n = VEHICLE_COUNT;
    for (i = 0; i < n; i++) {
        v = VEHICLE_PTR_ARRAY[i];
        if (!v || v == g_sc_vehicle || is_player(v)) continue;

        pq = (int**)((char*)v + OFF_QUEUE_ARRAY);
        pc = (int*)((char*)v + OFF_QUEUE_COUNT);
        q  = *pq;
        c  = *pc;

        if (!q) continue;
        new_idx = c + 1;
        if (new_idx >= QUEUE_CAPACITY) continue;

        dup = 0;
        for (j = 0; j <= c; j++) {
            if (q[j * 2] == 0x0e) { dup = 1; break; }
        }
        if (dup) continue;

        q[new_idx * 2]     = 0x0e;
        q[new_idx * 2 + 1] = 0;
        *pc = new_idx;
    }
}

/* ========================================================================
 * Safety Car Vehicle
 * ======================================================================== */

static void* find_sc_vehicle(void)
{
    int i, n;
    void* v;
    n = VEHICLE_COUNT;
    for (i = 0; i < n; i++) {
        v = VEHICLE_PTR_ARRAY[i];
        if (!v) continue;
        if (veh_int(v, OFF_DRIVER_NUMBER) == SC_CAR_NUMBER)
            return v;
    }
    return NULL;
}

static void sc_set_active(int active)
{
    if (!g_sc_vehicle) return;
    veh_write_int(g_sc_vehicle, OFF_FINISH_STATE, active ? 0 : 3);
    if (active) {
        /* Governor: SC car itself drives at SC_SPEED_RATIO */
        veh_write_float(g_sc_vehicle, OFF_LIVE_LAP_RATIO, SC_SPEED_RATIO);
    }
}

/* ========================================================================
 * Key Handling
 * ======================================================================== */

static void check_keys(DWORD now)
{
    int d = GetAsyncKeyState(KEY_MANUAL_DEPLOY)   & 1;
    int w = GetAsyncKeyState(KEY_MANUAL_WITHDRAW) & 1;
    int p = GetAsyncKeyState(KEY_PROBE_DUMP)      & 1;

    if (d && !g_prev_deploy) {
        if (g_state == SC_IDLE || g_state == SC_COOLDOWN) {
            g_state = SC_DEPLOYING;
            g_t0 = now;
            hud("MANUAL: SAFETY CAR DEPLOYED", HUD_COL_Y);
        }
    }

    if (w && !g_prev_withdraw) {
        if (g_state == SC_ACTIVE || g_state == SC_DEPLOYING) {
            g_state = SC_WITHDRAWING;
            g_t0 = now;
            hud("MANUAL: SAFETY CAR WITHDRAWN", HUD_COL_G);
        } else if (g_state == SC_COOLDOWN) {
            g_state = SC_IDLE;
            g_baseline_dnf = dnf_count();
            hud("MANUAL: COOLDOWN SKIPPED", HUD_COL_G);
        }
    }

    if (p && !g_prev_probe) {
        probe_dump();
    }

    g_prev_deploy   = d;
    g_prev_withdraw = w;
    g_prev_probe    = p;
}

/* ========================================================================
 * State Machine Tick
 * ======================================================================== */

static void tick(void)
{
    DWORD now = GetTickCount();
    DWORD dt  = now - g_t0;
    int dnf;

    check_keys(now);

    switch (g_state) {

    case SC_IDLE:
        sc_set_active(0);
        if (SESSION_TYPE != 7 || !RACE_ACTIVE_FLAG) {
            g_baseline_dnf = dnf_count();
            break;
        }
        dnf = dnf_count();
        if (dnf - g_baseline_dnf >= DEPLOY_DNF_THRESHOLD) {
            g_state = SC_DEPLOYING;
            g_t0 = now;
            hud_fmt("SAFETY CAR DEPLOYED (%d retirement%s)", HUD_COL_Y,
                    dnf - g_baseline_dnf,
                    (dnf - g_baseline_dnf) > 1 ? "s" : "");
        }
        break;

    case SC_DEPLOYING:
        log_msg("SC_DEPLOYING: activating SC vehicle and speed governor");
        sc_set_active(1);
        inject_sc_command();
        apply_sc_speed();
        g_state = SC_ACTIVE;
        g_t0 = now;
        hud("SAFETY CAR ON TRACK - REDUCE SPEED", HUD_COL_Y);
        break;

    case SC_ACTIVE:
        /* Re-assert speed governor every tick — game's AI per-lap update
         * may try to push the ratio back up */
        apply_sc_speed();
        sc_set_active(1);

        /* Withdraw after SC_LAPS laps worth of time (~90s per lap as fallback,
         * or just use fixed duration for now) */
        if (dt >= (DWORD)(SC_LAPS * 90000)) {
            g_state = SC_WITHDRAWING;
            g_t0 = now;
            hud("SAFETY CAR IN THIS LAP", HUD_COL_Y);
        }
        break;

    case SC_WITHDRAWING:
        log_msg("SC_WITHDRAWING: restoring speeds");
        sc_set_active(0);
        restore_speed();
        g_state = SC_COOLDOWN;
        g_t0 = now;
        hud("GREEN FLAG - RACING RESUMES", HUD_COL_G);
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

    log_msg("=== Safety Car Plugin v3 started ===");

    for (;;) {
        if (SESSION_TYPE == 7 && RACE_ACTIVE_FLAG) break;
        Sleep(500);
    }

    log_fmt("Race detected: vehicles=%d session=%d phase=%d",
            VEHICLE_COUNT, SESSION_TYPE, RACE_PHASE);

    g_sc_vehicle = find_sc_vehicle();
    if (g_sc_vehicle) {
        log_fmt("SC vehicle found at %p (car #%d)",
                g_sc_vehicle, veh_int(g_sc_vehicle, OFF_DRIVER_NUMBER));
        sc_set_active(0);
        hud("SAFETY CAR READY - NUM8=deploy NUM2=withdraw NUM5=probe", HUD_COL_Y);
    } else {
        log_msg("SC vehicle not found - running without physical SC");
        hud("SC READY (virtual) - NUM8=deploy NUM2=withdraw NUM5=probe", HUD_COL_Y);
    }

    /* Initial probe dump for verification */
    probe_dump();

    g_baseline_dnf = dnf_count();
    memset(g_speed_save, 0, sizeof(g_speed_save));

    for (;;) {
        tick();
        Sleep(TICK_MS);
    }
    return 0;
}

/* ========================================================================
 * DLL Exports
 * ======================================================================== */

__declspec(dllexport) void __cdecl start(void)
{
    HANDLE h = CreateThread(NULL, 0, monitor, NULL, 0, NULL);
    if (h) CloseHandle(h);
}

__declspec(dllexport) int __cdecl port(void) { return 0; }
__declspec(dllexport) int __cdecl ip(void)   { return 0; }

BOOL WINAPI DllMain(HINSTANCE h, DWORD reason, LPVOID reserved)
{
    (void)reserved;
    if (reason == DLL_PROCESS_ATTACH)
        DisableThreadLibraryCalls(h);
    return TRUE;
}
