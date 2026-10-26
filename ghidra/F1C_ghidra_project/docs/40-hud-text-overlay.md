# docs/40-hud-text-overlay.md — HUD Text Overlay System

**Status:** CONFIRMED via Frida live intercept (2026-07-22).  
**Reference mod:** `mods/grid_reorder/gr21.c` (working implementation).

---

## Architecture

Two-level indirection:

```
0x007cd204          ← global address (static, never changes)
  [+0x00] uint32_t  ← pointer to inner heap object (can change per session)
    inner_ptr       ← base of slot manager (e.g. 0x03c571e0 in test session)
```

**Always read the inner pointer fresh:**
```c
uintptr_t inner = *(volatile uint32_t*)0x007cd204;
```

---

## Slot Array Layout

8 slots. Each slot is **0x5c (92) bytes**.

| Field  | Offset from slot base | Type      | Notes                        |
|--------|-----------------------|-----------|------------------------------|
| text   | `+0x3c`               | `char[?]` | Null-terminated display text |
| timer  | `+0x90`               | `float`   | >0 = displayed; ≤0 = free   |

Slot n base address: `inner + n * 0x5c`

```c
#define SLOT_COUNT      8
#define SLOT_STRIDE     0x5c
#define SLOT_TEXT_OFF   0x3c
#define SLOT_TIMER_OFF  0x90
```

---

## How the game uses slots

| Function       | Address      | Role                                                   |
|----------------|--------------|--------------------------------------------------------|
| `b9c0`         | `0x0045b9c0` | thiscall slot writer — ECX=inner_ptr, arg0=text string |
| `b430`         | `0x0045b430` | Reset slot (sets timer = -1.0f)                        |
| `b500`         | `0x0045b500` | Find free slot (timer ≤ 0), returns slot index         |
| `b480`         | `0x0045b480` | Duplicate check — if text already in any slot, skip    |
| `ba60`         | `0x0045ba60` | Clear matching text from all slots                     |
| `bde0`         | `0x0045bde0` | Thin wrapper: calls ba60 (clear)                       |
| `bdf0`         | `0x0045bdf0` | Thin wrapper: calls b9a0 (reset all)                   |
| `BD10`         | `0x0045BD10` | Text line-wrap + render (NOT thiscall)                 |

**"PAUSED" flow (confirmed via trace):**
- `FUN_004fa7e0` runs every frame while paused
- Copies `DAT_005c35c8` ("PAUSED") → `0x5ec4cc` (scratch buffer)
- Calls `BD10(0x5ec4cc, ...)`
- Internally calls `b9c0` with ECX=inner_ptr, timer=5.0f
- Game rewrites it every frame → never expires while paused

`0x5ec4cc` is a scratch/comparison buffer, NOT the slot storage. Penalty text (e.g. steward messages) uses transient stack addresses as input to BD10.

---

## Writing custom text from injected code

**DO NOT call b9c0 or any game function from injected thread.** thiscall, wrong thread, callee-cleanup — instant crash.

**Safe approach: pure memory write to slot array.**

```c
/* Write text to first free HUD slot. No game function calls. */
static void hud_write(const char *msg) {
    uintptr_t inner = *(volatile uint32_t*)0x007cd204;
    if (!inner) return;
    for (int n = 0; n < 8; n++) {
        float *timer = (float*)(inner + n * 0x5c + 0x90);
        if (*timer <= 0.0f) {
            char *text = (char*)(inner + n * 0x5c + 0x3c);
            strncpy(text, msg, 31);
            text[31] = '\0';
            *timer = 1.5f;
            return;
        }
    }
}

/* Keep an existing slot alive. Call every ~50ms from your thread. */
static void hud_refresh(const char *msg) {
    uintptr_t inner = *(volatile uint32_t*)0x007cd204;
    if (!inner) return;
    BOOL found = FALSE;
    for (int n = 0; n < 8; n++) {
        char  *text  = (char*)(inner + n * 0x5c + 0x3c);
        float *timer = (float*)(inner + n * 0x5c + 0x90);
        if (strncmp(text, msg, strlen(msg)) == 0) {
            *timer = 1.5f;
            found = TRUE;
            break;
        }
    }
    if (!found) hud_write(msg);
}
```

**Timer semantics:** the render loop decrements timer by dt each frame (~0.016 at 60fps). Setting timer=1.5f from a 50ms loop keeps the slot perpetually alive. Set timer=5.0f for a one-shot 5-second display.

---

## Discovery notes

- `0x5ec4cc` initially appeared to be the slot storage — it is NOT. It is a transient scratch buffer that bd10 reads as input. The slot array lives at `inner_ptr`.
- First write attempt failed (wrote to slot[0]) because write_idx was at 5 and b500 allocated a different slot. Fix: scan all slots for timer≈5.0 after b9c0 fires, not slot[0].
- `readUtf8String(N)` in Frida fails on slot memory (embedded nulls). Use `readCString()`.
- The inner heap pointer (0x03c571e0 in one session) CAN change across game restarts. Always dereference 0x7cd204[0] fresh.
- Frida `onLeave` hook runs on the game thread → memory writes from there are safe. Injected DLL thread is separate → only pure memory reads/writes are safe, no function calls.

---

## Confirmed working

`mods/grid_reorder/gr21.c` displays "RED FLAG" during the 5-second red-flag countdown:
1. At NUMPAD1 press: `hud_write_red_flag()` finds free slot, writes text + timer=1.5f
2. Every 50ms in phase 1 loop: `hud_refresh_red_flag()` resets timer to 1.5f
3. At restart: stops refreshing — slot expires naturally

Screenshot confirmed: single "RED FLAG" entry in top-center overlay, same position as penalty/PAUSED messages.
