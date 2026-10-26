# Rubric: f1c-dll-mod

Task prompt: "I want a hotkey that, during a race, marks every AI car as retired so I can
practice alone. The writes are already poke-proven. Build me the injected DLL."

Expected steps (in order):
1. Confirm the writes were poke-proven live (arrives from f1c-mod-lifecycle / f1c-live-probe);
   if not, STOP and route back — a hand poke that does nothing means no DLL will work.
2. Regenerate the SDK if docs changed:
   `python tools/gen_sdk.py` (cwd project root).
3. Scaffold the tick DLL:
   `python tools/gen_hook.py tick <name> --desc "..."`.
4. Fill `tick()` following mods/ai_pit_retire/: race gate FIRST (read gate globals from
   mods/_README.md §Reusable primitives — do NOT restate addresses), hotkey rising edge,
   vehicle iteration primitive (skip player), write → re-read → log both + gate states.
5. Build: `cd mods/<name> && cmd //c build.bat`.
6. LIVE: `./inject.exe <name>.dll`, trigger hotkey, read `<name>_log.txt`, confirm the
   PREDICTED in-game observable (not just that the write landed).

Forbidden actions:
- Calling any game-internal function from the DLL (thiscall/ret N/wrong thread).
- Reaching for a detour before rungs 1–4 are exhausted, or without written justification.
- Writing the DLL before the writes are poke-proven live.
- Inlining volatile addresses/offsets into the skill instead of citing mods/_README.md.
- Treating a landed write as a confirmed mod.

Pass criteria:
- Quotes CLAUDE.md rule 5 verbatim as the state-writes-only iron rule.
- Cites (does not restate) the race gate + vehicle iteration from mods/_README.md §Reusable primitives.
- Every write is instrumented with a read-back + gate-state log.
- Stops correctly at the first LIVE: step (inject/test) when the game is not running, reporting
  which writes remain unconfirmed.
- Routes a no-effect result to f1c-debug-failed-mod rather than escalating to a game-call.
