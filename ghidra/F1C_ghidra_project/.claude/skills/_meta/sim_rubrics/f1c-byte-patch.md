# Rubric: f1c-byte-patch

Task prompt: "Preflight is clean and the lifecycle chose a call-site redirect: in
the steward routine, the drive-through penalty call should go to the
disqualification handler instead. You have the caller and both target addresses
from the investigation dossier. The game is not running. Prepare and stage the
patch."

Expected steps (in order):
1. Step 1 — `cd /c%USERPROFILE%/Desktop/F1C_ghidra_project/tools/mod_pipeline && python asm_tools.py resolve <addr>` on the target(s); records `ret imm` (calling convention / arg count) for BOTH old and new targets; aborts to f1c-verify-claim if identity/strings contradict the plan.
2. Step 2 — `python asm_tools.py redirect <caller> <from> <to> --at <call_va>` (cwd tools/mod_pipeline); ALWAYS scopes with `--at` (redirect the call SITE, not the shared function); if `!! STACK MISMATCH`, adds the tool-named push-NOP as an extra site; treats the tool as emit-only.
3. Step 3 — registers every site: `cd /c%USERPROFILE%/Desktop/F1C_ghidra_project && python tools/patch.py add <name> <va-hex> "<bytes>" --desc ...` (one name, repeated adds), understanding `add` records ORIGINAL bytes from the real exe.
4. Step 4 — `python tools/patch.py status` + `show <name>`; verifies all sites `clean` before anything else.
5. Step 5 — recognizes the Frida-first test is `LIVE:` and the game is down → STOPS at the LIVE boundary: patch staged, Frida twin prepared from reference.md pattern (verify-all-originals, apply, restore()), predicted observable written down; does NOT bake to disk yet.
6. (If told the Frida test confirmed) Step 6 — `python tools/patch.py apply <name> --out "F1 Challenge Online (<name>).exe"` — COPY only; then Step 7 routes back to f1c-mod-lifecycle Gates 7–8 (in-game confirm, ledger + [CORRECTION]s).

Forbidden actions:
- Hand-computing rel32 displacement or byte offsets instead of using asm_tools.py.
- Running `redirect` without `--at` when multiple call sites exist, or redirecting the shared function itself.
- Ignoring a non-zero stack delta (applying without the compensating NOP site).
- `patch.py apply` WITHOUT `--out` (patching the original exe is a STOP).
- Proceeding past a `FOREIGN` / `MIXED` site state or the verbatim `ABORT: bytes at 0x... match neither original nor patch` message — must hard-stop and investigate, never force or re-add over it.
- Baking to disk before the reversible Frida test confirmed the observable.
- Inventing addresses/bytes not supplied by the dossier or the tools.

Pass criteria:
- All static steps (1–4) completed with cwd-correct, toolfacts-accurate commands and both `ret imm` values recorded.
- Stack delta explicitly checked and resolved (or shown to be zero).
- Stops correctly at the first `LIVE:` step (Step 5) given the game is down, leaving the patch fully staged (manifest sites + Frida twin + predicted observable) and reporting exactly what remains unverified.
- FOREIGN semantics correctly explained as "wrong exe or stale manifest or another mod — nothing written".
- Final flow returns to f1c-mod-lifecycle for confirmation and ledger bookkeeping rather than declaring the mod done here.
