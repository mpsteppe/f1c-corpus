/*
 * red_flag.dll — F1 Challenge 99-02 red flag re-enable
 *
 * Press M in-game to toggle red flag on/off.
 *
 * Feedback:
 *   - In-game text/audio message via game's own display functions
 *   - Beep on toggle (high = ON, low = OFF) as backup
 *   - Log written to red_flag_log.txt next to the DLL
 *
 * Addresses are absolute VAs — valid because F1 Challenge is a 2002
 * MSVC PE32 binary with no ASLR and always loads at 0x00400000.
 */

#include <windows.h>
#include <stdio.h>

/* ----- Red flag globals -------------------------------------------------- */

#define ADDR_RED_PHYSICS  0x008acfd4u   /* DAT_008acfd4: gates physics + exit-pit penalty */
#define ADDR_RED_ENTRY    0x008acfc8u   /* DAT_008acfc8: gates entry-pit penalty          */
#define ADDR_RED_GUIDANCE 0x008acfd8u   /* DAT_008acfd8: enables waypoint guidance to pits*/
#define ADDR_PENALTIES    0x007cef84u   /* DAT_007cef84: penalty enforcement (0=disabled) */

/* ----- Session / vehicle globals ----------------------------------------- */

#define ADDR_SESSION_TYPE  0x007c56a4u  /* DAT_007c56a4: 7=race, 6=quali, 0-5=practice  */
#define ADDR_VEHICLE_COUNT 0x005c329cu  /* DAT_005c329c: number of vehicles on track     */
#define ADDR_VEHICLE_ARRAY 0x007c54f0u  /* DAT_007c54f0: ptr to array of vehicle ptrs    */

/* ----- Native game message functions (confirmed in 004a5ea0 / 004a5f20) -- */

/* Text-only message — used in race sessions (session == 7).
   Called as: FUN_004bc0e0(string_ptr)
   Calling convention assumed __cdecl (default for MSVC 2002 internal helpers). */
typedef void (*fn_show_text_t)(const char *str);

/* Text + audio message — used in non-race sessions.
   Called as: FUN_004bba90(string_ptr, volume_float)
   0x447a0000 == 1000.0f — the volume value used in the original game code.  */
typedef void (*fn_show_audio_t)(const char *str, float volume);

#define FN_SHOW_TEXT  ((fn_show_text_t) 0x004bc0e0u)
#define FN_SHOW_AUDIO ((fn_show_audio_t)0x004bba90u)

/* ----- Hotkey ------------------------------------------------------------ */

#define HOTKEY 'M'

/* ----- State ------------------------------------------------------------- */

static volatile BOOL g_running = TRUE;
static volatile BOOL g_active  = FALSE;
static char          g_log_path[MAX_PATH];

/* ----- Helpers ----------------------------------------------------------- */

static void log_write(const char *msg)
{
    FILE *f = fopen(g_log_path, "a");
    if (!f) return;
    SYSTEMTIME t;
    GetLocalTime(&t);
    fprintf(f, "[%02d:%02d:%02d] %s\n", t.wHour, t.wMinute, t.wSecond, msg);
    fclose(f);
}

static void game_announce(const char *str)
{
    DWORD session = *(volatile DWORD *)ADDR_SESSION_TYPE;
    if (session == 7)
        FN_SHOW_TEXT(str);
    else
        FN_SHOW_AUDIO(str, 1000.0f);
}

/* ----- Core toggle ------------------------------------------------------- */

static const char MSG_ON[]  = "Red Flag";
static const char MSG_OFF[] = "Green Flag";

static void set_red_flag(BOOL on)
{
    DWORD value = on ? 2 : 0;

    *(volatile DWORD *)ADDR_RED_PHYSICS  = value;
    *(volatile DWORD *)ADDR_RED_ENTRY    = value;
    *(volatile DWORD *)ADDR_RED_GUIDANCE = on ? 1 : 0;

    /* Suspend penalty enforcement while red flag is active so that retired
       cars are not DSQ'd for traversing the pit lane under red.             */
    *(volatile DWORD *)ADDR_PENALTIES = on ? 0 : 1;

    if (on) {
        char buf[128];
        DWORD count = *(volatile DWORD *)ADDR_VEHICLE_COUNT;
        sprintf(buf, "RED FLAG ON  (guidance=1, penalties off, vehicles=%lu)", count);
        log_write(buf);
    } else {
        log_write("RED FLAG OFF (guidance=0, penalties restored)");
    }

    game_announce(on ? MSG_ON : MSG_OFF);
    Beep(on ? 1200 : 600, 150);
}

/* ----- Hotkey thread ----------------------------------------------------- */

static DWORD WINAPI hotkey_thread(LPVOID param)
{
    BOOL was_down = FALSE;
    log_write("Hotkey thread started. Press M to toggle red flag.");

    while (g_running) {
        BOOL is_down = (GetAsyncKeyState(HOTKEY) & 0x8000) != 0;

        if (is_down && !was_down) {
            g_active = !g_active;
            set_red_flag(g_active);
        }

        was_down = is_down;
        Sleep(50);
    }

    log_write("Hotkey thread stopped.");
    return 0;
}

/* ----- DLL entry point --------------------------------------------------- */

BOOL WINAPI DllMain(HINSTANCE hDll, DWORD reason, LPVOID reserved)
{
    switch (reason) {
    case DLL_PROCESS_ATTACH:
        DisableThreadLibraryCalls(hDll);

        GetModuleFileNameA(hDll, g_log_path, MAX_PATH);
        char *slash = strrchr(g_log_path, '\\');
        if (slash) *(slash + 1) = '\0';
        strcat(g_log_path, "red_flag_log.txt");

        log_write("DLL loaded into F1 Challenge Online.exe");
        CreateThread(NULL, 0, hotkey_thread, NULL, 0, NULL);
        break;

    case DLL_PROCESS_DETACH:
        g_running = FALSE;
        if (g_active) set_red_flag(FALSE);
        log_write("DLL unloaded.");
        break;
    }
    return TRUE;
}
