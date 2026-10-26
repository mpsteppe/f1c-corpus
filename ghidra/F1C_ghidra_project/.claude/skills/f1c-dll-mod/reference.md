# f1c-dll-mod — deep reference

Depth for `SKILL.md` in this directory. Read when writing the tick `tick()` body, wiring
read-back logging, or (last resort) a detour. Volatile facts (addresses, offsets) are NOT
inlined here — read them live from `mods/_README.md §Reusable primitives (copy these,
don't re-derive)`.

## 1. Why a tick DLL is rung 2, not a hook

The strategy ladder in `mods/_README.md` (its "strategy ladder (why mods fail)" section) ranks
mechanisms by fragility. A tick DLL spins its own thread and only READS/WRITES memory —
the same operation `poke.py` does by hand, just automated per frame. That is why it is
safe: it never enters game code, so it cannot trip thiscall/`ret N`/wrong-thread hazards.
Per the strategy-ladder section of `mods/_README.md`, the two viable archetypes are a pure
memory write (ai_pit_retire — in-game outcome LOG-CONFIRMED ONLY, see the Current-contents
ledger) and a byte redirect at an existing call site (cut_track_dq). No mod calls a game
function from injected code. Internalize that before writing a line of C.

## 2. Annotated tick skeleton

`gen_hook.py tick <name>` emits a `tick()` that runs ~60×/sec. The shape you fill in,
following `mods/ai_pit_retire/ai_pit_retire.c` (the mechanism reference):

```c
static void tick(void) {
    /* (a) RACE GATE FIRST — bail unless we are in a live race.
     *     Read the exact gate globals + the race enum value from the Reusable-primitives
     *     section of mods/_README.md ("Race gate"): SessionType == <race value> AND
     *     RaceActiveFlag != 0. */
    if (g_SessionType != RACE_SESSION /* value: see mods/_README.md Reusable primitives */) return;
    if (g_RaceActiveFlag == 0) return;

    /* (b) HOTKEY RISING EDGE — one press = one action, not one-per-frame. */
    static int prev = 0;
    int down = (GetAsyncKeyState(HOTKEY) & 0x8000) != 0;
    if (down && !prev) {
        do_action();          /* the writes live here */
    }
    prev = down;
}
```

Notes:
- The SDK macro names (`g_SessionType`, `g_RaceActiveFlag`, `g_VehiclePtrArray`, …) come
  from `mods/sdk/f1c_sdk.h`. Regenerate with `python tools/gen_sdk.py` after a docs merge;
  the numeric values live in the SDK, not in this file.
- Change the key with `#define HOTKEY VK_F8` at the top of the .c.
- `Sleep(16)` in the generated thread loop is the ~60Hz cadence — leave it.

## 3. Vehicle iteration (copy, don't re-derive)

For a field mod across all AI cars, iterate exactly as `ai_pit_retire.c` does. The four
facts — vehicle pointer array, vehicle count, how to skip the player, and the per-driver
block stride — are all in the "Reusable primitives" section of `mods/_README.md`, under
its "Vehicle iteration" entry. Read them there; do not hardcode remembered numbers. The invariants:
- Start from the vehicle-pointer array, bounded by the live vehicle count.
- Skip the player car (compare against the player-vehicle pointer global).
- Skip cars already out (their FinishState is non-zero) so events are not re-posted.
- The confirmed writable fields (FinishState, ReasonCode, pit flag) and their meanings are
  listed in the "Reusable primitives" section of `mods/_README.md`, under its "Confirmed
  vehicle-struct writes" entry.

## 4. Read-back logging (iron rule 6) — the non-negotiable

A failure report must carry BITS, not "nothing happened". For every write:

```c
/* write, then RE-READ the same address, then log both + gate states */
WRITE(addr, value);
int got = READ(addr);
logf_("gate: sess=%d active=%d | wrote %d -> read %d @ %p",
      g_SessionType, g_RaceActiveFlag, value, got, (void*)addr);
```

The generated `logf_()` appends to `<name>_log.txt` beside the DLL. When you hand a
failure to `f1c-debug-failed-mod`, this log is the evidence: did the write land? did the
gate open? A DLL that only logs "loaded" is undebuggable.

## 5. Build + inject transcript

```
cd mods/<name> && cmd //c build.bat
  Building <name>.dll ...
  Done. Inject with:  inject.exe <name>.dll
```
`build.bat` also builds `inject.exe` from `../red-flag-dll/inject.c` if not present.
Then, with the game running and on track:
```
cd mods/<name> && ./inject.exe <name>.dll
```
Trigger the hotkey, then read `<name>_log.txt`. A landed write is NOT a confirmed mod —
only the predicted in-game observable confirms it (see `f1c-debug-failed-mod` case 3).

## 6. Detour — the last-resort rung, hazard checklist

A detour (rung 5) is the ONLY rung that runs on the game's own thread, so it is the only
place you may touch game code — and only to observe or replace, never to freely "call a
game function". Reach for it solely after rungs 1–4 are ruled out, with written
justification. Scaffold: `python tools/gen_hook.py detour <name> <addr|funcname>`.

Hazards the scaffold warns about (all crash-on-wrong):
1. **PROLOGUE_LEN** must be a whole-instruction boundary ≥5. Disassemble the target's
   first bytes (Ghidra/IDA) and sum instruction lengths until ≥5. Overwriting a partial
   instruction crashes. The scaffold defaults to 5 with a loud TODO.
2. **Calling convention** — most F1C member functions are `__thiscall` (`this` in ECX).
   The scaffold uses `__fastcall(ecx, edx, …)` as the stand-in; fix `target_t` and
   `hook()` to the real signature from the function's docs entry.
3. **Trampoline** holds the saved prologue + a JMP back; call `g_trampoline(...)` to run
   the original. Omit it to fully replace behavior.

If a detour tempts you to CALL other game internals from inside the hook, stop — that is
the forbidden path the iron rule names. Confine the detour to reading args and writing
state.

---
Canonical sources: mods/_README.md §Reusable primitives (copy these, don't re-derive), §The strategy ladder (why mods fail); CLAUDE.md §Iron rules, rule 5; tools/gen_hook.py (via _meta/toolfacts.md); mods/ai_pit_retire/README.md
Last validated: 2026-07-18 against 6bcccfe
