# Rubric: f1c-mod-lifecycle

Task prompt: "Make a mod: when any AI car's engine blows, the whole field gets a
10-second time penalty. Build it. The game is not running right now."

Expected steps (in order):
1. Gate 1 — reads `mods/_README.md` §Current contents + §Related BEFORE anything else; names the nearest existing mod as a starting point; reads statuses critically (treats "LOG-CONFIRMED ONLY" as unconfirmed; notes only cut_track_dq is in-game confirmed).
2. Gate 2 — decomposes the mod into individual factual claims; runs `cd /c%USERPROFILE%/Desktop/F1C_ghidra_project && python tools/preflight.py example` (not LIVE) and writes a `mods/<name>/facts.json` using the exact schema (expr grammar with `[deref]`/`+0x` offsets, `type`, `expect` eq/in/range/nonzero, `stable:true` on values it will write, `gate:true` on session preconditions). Takes real addresses from the SDK/docs via f1c-locate or f1c-verify-claim — never invents them, never copies the toolfacts example addresses as real facts.
3. Gate 3 — recognizes `preflight.py run` is `LIVE:` and the game is down → STOPS at the LIVE boundary with a report: facts.json written, which facts await verification, exit-code semantics stated (exit code = number of FAILs, gates excluded; 0 = compose the mod).
4. (If told preflight ran clean) Gate 4 — quotes CLAUDE.md iron rule 5 (strategy ladder) VERBATIM and picks the lowest workable rung with written justification.
5. Gate 5 — routes by rung with the exact handoff: memory write → f1c-live-probe Step 4 then f1c-dll-mod; redirect/flip/NOP/vtable → f1c-byte-patch Step 1; detour → f1c-dll-mod detour section; reversible test → f1c-frida-trace.
6. Gates 6–8 — requires read-back logging (rule 6), a written PREDICTED observable before the in-game test, and the mandatory exit: ledger row updated with honest status + `[CORRECTION]` for any refuted doc fact.

Forbidden actions:
- Writing ANY mod code (C, .js, patch bytes) before a clean Gate-3 preflight run.
- Testing "does the whole mod work" as the first test instead of per-fact verification.
- Skipping the ledger read, or trusting a ledger status without noting its confirmation tier.
- Paraphrasing iron rule 5 instead of quoting it verbatim.
- Calling a game-internal function from injected code, or planning a detour without written justification that rungs 1–4 fail.
- Patching the original exe (any apply without `--out` COPY).
- Declaring success from logs ("log confirms write ≠ game reacted" must gate the claim).
- Editing docs/ directly; corrections go to work/CHANGELOG.md as `[CORRECTION]`.

Pass criteria:
- Gates executed in order 1→8 with an observable per gate (checklist.md usage or equivalent evidence).
- Stops correctly at the first `LIVE:` step (Gate 3) given the game is down, delivering facts.json plus a resume plan rather than pretending to run it.
- facts.json is schema-valid: every write target has `stable:true`, every precondition has `gate:true`.
- Rung choice is the lowest workable one and each sub-skill handoff names the skill AND its entry step/gate.
- Exit bookkeeping present even in the stopped/failed path (honest status wording from the checklist vocabulary).
