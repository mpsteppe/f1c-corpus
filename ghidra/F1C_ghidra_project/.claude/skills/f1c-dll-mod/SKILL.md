---
name: f1c-dll-mod
description: Build an injected tick/hotkey DLL that writes game state each frame (and, only as a last resort, an inline detour). Use when a mod needs continuous logic — poll a state, poke globals on a hotkey, run a virtual safety car — after poke-proving the writes live. Do NOT use to author the mod plan or pick a strategy rung (use f1c-mod-lifecycle first), to prove a single memory write live (use f1c-live-probe), to redirect an existing call site with static bytes (use f1c-byte-patch), or to debug a DLL that injects but the game ignores (use f1c-debug-failed-mod).
---

# Build an injected tick/hotkey DLL

Defensive-modding context ONLY: this targets the user's own single-player copy of
F1 Challenge 99-02 for feature restoration. It is not a general injection kit.

## When to use / when not

- Use for: per-frame polling logic that WRITES game state (hotkey → poke globals /
  vehicle fields; watch a condition → set a flag). The tick DLL is the proven archetype.
- Prerequisite mindset: you arrive here from `f1c-mod-lifecycle` having already
  poke-proven every write live (see `f1c-live-probe`). A DLL only automates writes a
  hand `poke.py` already produced the behavior for.
- Route out: static call-site redirect → `f1c-byte-patch`. Reversible live tracing →
  `f1c-frida-trace`. It injects but the game does not react → `f1c-debug-failed-mod`.

## Iron rule — STATE WRITES ONLY (CLAUDE.md rule 5, verbatim)

> **Mod strategy ladder:** data file > memory write (poke-proven, then tick DLL) >
> call-site byte redirect > vtable swap > detour. **Never call game internals from
> injected code** (thiscall `this`, `ret imm` stack cleanup, wrong thread).
> Patch a COPY of the exe, verify original bytes first, test with Frida before baking.

A tick DLL is rung 2 ("memory write … then tick DLL"). It reads and writes globals and
struct fields. It NEVER calls a game function: thiscall wants `this` in ECX, MSVC callees
clean the stack with `ret N`, and your thread is not the game's — calling in is the
spectacular-failure path. Detour (rung 5) is the only rung that runs on the game's thread,
and it is the last resort.

## Prerequisites

| Prerequisite | Check command | Expected |
|---|---|---|
| SDK header fresh | `cd /c%USERPROFILE%/Desktop/F1C_ghidra_project && ls mods/sdk/f1c_sdk.h mods/sdk/f1c_sdk.json` | both exist; regen after any docs merge (see Step 0) |
| MinGW32 toolchain | `ls "C:/msys64/mingw32/bin/gcc.exe"` | file exists (build.bat hardcodes this path) |
| Writes already poke-proven | — | you ran `f1c-live-probe` / `preflight.py run` with zero FAILs before coming here |

## Procedure

### Step 0: Regenerate the SDK if docs changed

The scaffold's `f1c_sdk.h` names come from the SDK. Regenerate after ANY docs merge.

```bash
cd /c%USERPROFILE%/Desktop/F1C_ghidra_project && python tools/gen_sdk.py
```
Expected output: a one-line count summary; `mods/sdk/f1c_sdk.h` and `f1c_sdk.json` rewritten.
If instead you see nothing / an error → the docs inputs are missing; STOP and check
`docs/12-globals-reference.md` exists. (⚠ this tool runs on bare invocation — only run when you mean to.)

### Step 1: Scaffold the tick DLL

```bash
cd /c%USERPROFILE%/Desktop/F1C_ghidra_project && python tools/gen_hook.py tick <name> --desc "what it does"
```
Expected output: `scaffolded mods/<name>/ :` then `<name>.c`, `build.bat`, `README.md`.
(The `--desc "text"` is baked into the generated README; a bare trailing word is silently ignored.)
If instead you see `mods/sdk/f1c_sdk.json missing` → run Step 0 first.

### Step 2: Fill in `tick()` — writes only

Edit `mods/<name>/<name>.c`. The generated `tick()` runs ~60×/sec. Follow the
`mods/ai_pit_retire/` exemplar — the reference hotkey tick DLL for the mechanism (current
status: see the Current-contents ledger in `mods/_README.md`):
1. Gate on the race condition FIRST — read the race gate (SessionType + RaceActiveFlag);
   the exact globals are in `mods/_README.md §Reusable primitives (copy these, don't
   re-derive)` under "Race gate". Do NOT restate the addresses here — read them there.
2. For a hotkey mod, act on the `GetAsyncKeyState(HOTKEY)` RISING edge only (edit
   `#define HOTKEY` in the .c), so one press = one action.
3. Iterate vehicles using the array / count / player-skip / stride primitive documented in
   the "Reusable primitives" section of `mods/_README.md` (see its "Vehicle iteration"
   entry). Skip the player.
4. For each write: write, then RE-READ, then log both values AND the gate states (iron
   rule 6). A DLL that cannot report its own read-backs cannot be debugged.
5. Only WRITE globals/fields the SDK macros expose. Never call a game function.

### Step 3: Build

```bash
cd /c%USERPROFILE%/Desktop/F1C_ghidra_project/mods/<name> && cmd //c build.bat
```
Expected output: `Building <name>.dll ...` then `Done. Inject with: inject.exe <name>.dll`.
Note: `build.bat` ends with `pause`, so it waits for a keypress — press Enter to return, or
run `cmd //c "echo.| build.bat"` to auto-dismiss it.
If instead you see `ERROR: ...gcc.exe not found` → MinGW32 missing at `C:\msys64\mingw32\bin`;
STOP. If you see `FAILED` → a C compile error; fix the .c and rebuild.

### Step 4: LIVE — inject and test against a predicted observable

`LIVE:` (game running, in a race). From `mods/<name>/`:
```bash
cd /c%USERPROFILE%/Desktop/F1C_ghidra_project/mods/<name> && ./inject.exe <name>.dll
```
Then trigger the hotkey in-game. Read `<name>_log.txt` next to the DLL for the read-backs.
Confirm the PREDICTED in-game observable actually happened — a landed write is NOT a
confirmed mod (see `f1c-debug-failed-mod` case 3, ai_pit_retire).
If the log shows writes landing but the game does not react → `f1c-debug-failed-mod`.

## Detour rung (last resort ONLY)

Only after rungs 1–4 are ruled out, and with WRITTEN justification of why each lower rung
failed. Scaffold: `python tools/gen_hook.py detour <name> <addr|funcname>`. You MUST set
`PROLOGUE_LEN` to a whole-instruction boundary ≥5 (disassemble the target; wrong length
crashes) and match the real calling convention. A detour runs on the game's thread — it is
the one rung permitted to touch game code, and only to observe/replace, per the docs entry.
Read `reference.md` in this skill's directory before writing any detour.

## STOP — do not proceed if

- You have NOT poke-proven the writes on a live game → stop, go to `f1c-live-probe` /
  `f1c-mod-lifecycle`. A hand poke that does nothing means no DLL built on it will work.
- You are about to call a game-internal function from the DLL → forbidden, re-read the ladder above.
- Game is not running but the step is `LIVE:` → stop; report which writes remain unverified.
- Reaching for a detour before rungs 1–4 are exhausted → stop; justify in writing or drop down.
- About to test the whole mod as the first check instead of confirming per-write read-backs → stop; log bits first.

## Failure modes and recovery

| Symptom | Likely cause | Action |
|---|---|---|
| `...gcc.exe not found` | MinGW32 missing | install MSYS2 mingw32 at `C:\msys64\mingw32\bin`; STOP until present |
| `mods/sdk/f1c_sdk.json missing` | SDK not generated | run Step 0 (`python tools/gen_sdk.py`) |
| DLL loads, log written, game unchanged | log-confirmed-only trap | `f1c-debug-failed-mod` case 3; re-check gate + `stable:` on the target field |
| Game crashes on inject | called game code / bad detour prologue | you violated the iron rule or set PROLOGUE_LEN wrong; revert to state-writes-only |

## Deep reference

Read `reference.md` in this skill's directory for the annotated tick skeleton walkthrough,
the read-back logging pattern, the build/inject transcript, and the detour hazard checklist.

---
Canonical sources: CLAUDE.md §Iron rules, rule 5; mods/_README.md §Reusable primitives (copy these, don't re-derive), §The strategy ladder (why mods fail); tools/gen_hook.py (via _meta/toolfacts.md); mods/ai_pit_retire/README.md (exemplar)
Last validated: 2026-07-18 against 6bcccfe
