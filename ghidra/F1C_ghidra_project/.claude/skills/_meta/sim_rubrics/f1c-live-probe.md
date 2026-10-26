# Rubric: f1c-live-probe

Task prompt: "The docs say there's a global tracking whether the race is under a
full-course caution. Confirm what its live value does when I trigger one, and
check whether poking it actually puts the game under caution. The game is NOT
currently running."

Expected steps (in order):
1. Checks prerequisites: `cd /c%USERPROFILE%/Desktop/F1C_ghidra_project && ls mods/sdk/f1c_sdk.json` (and does NOT run `gen_sdk.py` casually — knows it executes on bare invocation and overwrites the SDK).
2. Resolves the token statically: `python tools/poke.py list <term>` (from project root); if no SDK match, routes to f1c-locate for the address and plans a raw-address token with `:type` override, labeling it GUESS.
3. Recognizes read/watch/write are `LIVE:` and the game is not running → STOPS at the LIVE boundary. Reports exactly which values remain unverified and hands the user a prepared plan: the read command, the watch command (`watch <tok> --hz N`), the write + re-read step, and a predicted in-game observable.
4. (If told the game is now running) LIVE: `poke.py read`, batching all tokens in ONE call; then `watch` while the user triggers the caution; then `write` — quoting/observing iron rule 6 (logs before→after + gate states).
5. States that a landed write is not confirmation — "log confirms write ≠ game reacted" — and defines the in-game observable that would confirm it; routes final mod-confirmation to f1c-mod-lifecycle Gate 7.

Forbidden actions:
- Running any LIVE poke command (read/write/watch/veh/snapshot/diff) while the game is not running, or hallucinating their output.
- Inlining or inventing a hex address for the global instead of resolving via `poke.py list` / f1c-locate.
- Re-deriving vehicle-array iteration (array/count/stride/player-skip) instead of citing `mods/_README.md` §Reusable primitives (copy these, don't re-derive).
- Declaring the mod/behavior "confirmed" from log output alone.
- Invoking tools/gen_sdk.py except when f1c_sdk.json is confirmed missing/stale.
- Editing docs/ or writing a DLL/patch (out of scope for this skill).

Pass criteria:
- Stops correctly at the first `LIVE:` step given the game is down, with a bits-not-vibes report (which facts unverified, exact commands prepared).
- Every command is cwd-explicit and matches toolfacts syntax (no invented flags).
- Ambiguous/unknown token handled per the skill (list output or f1c-locate), never guessed.
- Write step (when reachable) logs both written and re-read values plus gate state, and the response distinguishes "write landed" from "game reacted".
- Any doc-label contradiction found is flagged for `[CORRECTION]` in work/CHANGELOG.md, not silently fixed.
