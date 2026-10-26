# f1c-debug-failed-mod — triage tree

Work TOP TO BOTTOM. Nodes are ordered by HISTORICAL FREQUENCY (per `_meta/CATALOG.md`) —
the first node is the most common cause. Do not skip: early nodes are cheap and likely.
No exe-image addresses are inlined here; the worked cases with real offsets live in
`case-studies.md` (marked historical snapshot).

Entry condition: the mod BUILDS and RUNS (injects/patches/logs) but the game does not
produce the predicted observable, or it crashes.

---

## Node 1 — Stale-ledger facts (MOST COMMON)

Symptom: the mod was built against facts that are no longer true, or were overstated in the
ledger.

Check:
- Re-read the Current-contents ledger in `mods/_README.md` for THIS mod, and cross-read its own
  `apply_*.py` header / `README.md`. If they disagree, the artifacts win (case 2).
- Re-run preflight over the mod's `facts.json` PER FACT. `LIVE:` (game running):
  `cd /c%USERPROFILE%/Desktop/F1C_ghidra_project && python tools/preflight.py run mods/<name>/facts.json`
  Expected: `0 hard failure(s).` Any `FAIL` line names a fact that is now false.
  If `facts.json` does not exist (e.g. ai_pit_retire has none), create one FIRST from the
  mod's writes — start from the template (`python tools/preflight.py example`) and fill in
  each fact (expr + type + expect) from the mod's `.c` / README — then run it.

Resolve: fix the failing FACT (locate the real offset/global via `f1c-locate` +
`f1c-verify-claim`), then rebuild. Do NOT patch the C to paper over it.
Not this? → Node 2.

---

## Node 2 — Log-confirmed-only trap (writes land, game ignores)

Symptom: the log shows perfect read-backs (`wrote 2 -> read 2`) but the in-game outcome
never appears. This is the ai_pit_retire pattern (case 3).

Two sub-causes:

(a) **The game re-derives the value every tick**, clobbering your write. Test stability.
`LIVE:` (game running, in a race), using the field's SDK/docs type for `<field-type>`:
```bash
cd /c%USERPROFILE%/Desktop/F1C_ghidra_project && python tools/preflight.py probe "[<ptr-expr>]+<offset>:<field-type>" --secs 3
```
Expected: a steady value if the game leaves it alone. A value that changes on its own = the
game owns that field; your write is overwritten. In a `facts.json`, encode this as
`"stable": true` so preflight FAILs when the game rewrites it.

(b) **You wrote the wrong field** — the game reads a DIFFERENT field for the behavior you
want. Confirm which field drives the behavior by watching during the action (`f1c-live-probe`
snapshot→diff, or a `f1c-frida-trace` watch agent) rather than assuming the documented one.

Resolve: find the field the game actually READS for this behavior; re-point the write.
Not this? → Node 3.

---

## Node 3 — GUESS-tier offset in the chain (never live-probed)

Symptom: a value reads as garbage (very large/small, NaN), or the mod acts on the wrong
thing. A GUESS-tier offset (from `docs/13-struct-offsets.md`) was used without live verification. This is the
safety_car speed-offset pattern (case 1 in `case-studies.md` carries the literal offset).

Check: probe the suspect offset live and sanity-check the range you expect. `LIVE:` (game
running), using the field's SDK/docs type for `<field-type>`:
```bash
cd /c%USERPROFILE%/Desktop/F1C_ghidra_project && python tools/preflight.py probe "[<ptr-expr>]+<offset>:<field-type>" --secs 2
```
Expected: a value in the physically sensible range. Garbage/NaN → the offset is wrong.

Resolve: locate the correct offset (dump the struct region, `f1c-live-probe` snapshot/diff,
or cross-read the raw `.c` via `f1c-verify-claim`). Log a `[CORRECTION]` for the wrong offset.
Not this? → Node 4.

---

## Node 4 — Calling convention / stack (crash or corruption)

Symptom: crash on inject, crash after the hotkey, or subtle corruption — usually after a
call redirect or a detour.

Checks:
- **Did injected code CALL a game function?** Forbidden. thiscall wants `this` in ECX; your
  thread is not the game's. This is the spectacular-failure path
  (the strategy-ladder section of `mods/_README.md`). Remove the call; go state-writes-only.
- **Byte-redirect stack imbalance:** if you redirected a call between handlers that clean
  different numbers of stack bytes (`ret N`), the stack corrupts. Re-run
  `cd /c%USERPROFILE%/Desktop/F1C_ghidra_project/tools/mod_pipeline && python asm_tools.py redirect <caller> <from> <to> --at <call_va>`
  and read the stack-delta line — a non-zero delta names the exact `push` to NOP.
- **Detour PROLOGUE_LEN:** must be a whole-instruction boundary ≥5. A partial-instruction
  overwrite crashes.

Resolve: drop the game-call, fix the push fixup, or fix PROLOGUE_LEN.
Not this? → Node 5.

---

## Node 5 — Wrong thread / tick timing / race gate never true

Symptom: the action never fires at all, or fires but the game is not in the state you assumed.

Checks:
- **Race gate:** does the condition ever become true? Confirm the gate globals live. `LIVE:`
  (game running, in a race):
  `cd /c%USERPROFILE%/Desktop/F1C_ghidra_project && python tools/poke.py read SessionType RaceActiveFlag`
  Expected: the race values (per the "Race gate" entry in the Reusable-primitives section of
  `mods/_README.md`) when you
  are actually in a race. If your gate never matches, the tick returns early forever.
- **Timing:** a per-frame write may land in a frame the game overwrites later in the same
  frame — relates back to Node 2's stability test.

Resolve: correct the gate condition; confirm it live before rebuilding.
Not this? → Node 6.

---

## Node 6 — Wrong rung on the strategy ladder

Symptom: none of the above, and the mechanism itself is fragile — you started too high on the
ladder (a detour or a game-call) when a lower rung would work.

Check the ladder in `mods/_README.md` (its "strategy ladder (why mods fail)" section): data file >
memory write (poke-proven, then tick DLL) > call-site byte redirect > vtable swap > detour.
Ask: could this be a pure memory write proven with `poke.py` first? Could it be a byte
redirect at an existing call site (so the game supplies the args)?

Resolve: drop to the lowest rung that can produce the behavior, re-prove with `poke.py` on a
live game BEFORE writing any C, then rebuild via `f1c-mod-lifecycle`.

---

## Every exit (all nodes)

1. Update this mod's Status in the `mods/_README.md` Current-contents ledger to match the evidence.
2. File a `[CORRECTION]` per refuted doc fact — route to `f1c-doc-audit` for the format.
3. Write the failure report in BITS: logged writes, read-backs, gate states, stability result
   (template in `case-studies.md`).

---
Canonical sources: mods/_README.md §Current contents, §Reusable primitives (copy these, don't re-derive), §The strategy ladder (why mods fail); tools/preflight.py, tools/poke.py, tools/mod_pipeline/asm_tools.py (via _meta/toolfacts.md); tools/mod_pipeline/MODDING_PLAYBOOK.md §Gotchas learned the hard way
Last validated: 2026-07-18 against 6bcccfe
