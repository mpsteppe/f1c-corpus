# Sim 4 — f1c-byte-patch (staging dry-run)

- Date: 2026-07-20. Model: Sonnet (general-purpose subagent), fresh context.
- Harness: read-only session, game not running; `patch.py add/apply` forbidden (manifest writes), drafted instead.
- Task prompt (from rubric, plus one clarifier that the addresses are recoverable from the repo): "Preflight is clean and the lifecycle chose a call-site redirect: in the steward routine, the drive-through penalty call should go to the disqualification handler instead. You have the caller and both target addresses from the investigation dossier. The game is not running. Prepare and stage the patch."
- Rubric: `.claude/skills/_meta/sim_rubrics/f1c-byte-patch.md`

## Agent final report

## Patch staged. Stopped at the LIVE boundary (game not running), as required.

### Chronological account

**1. Oriented via the skill.** Invoked `f1c-byte-patch` (matches the task's own phrasing: "the lifecycle chose a call-site redirect... preflight is clean"). Read its `SKILL.md` procedure and the rubric at `.claude/skills/_meta/sim_rubrics/f1c-byte-patch.md`, which pins down the exact expected step order and forbidden actions for this task.

**2. Recovered the addresses from the mod ledger, per iron rule 3.** Read `%USERPROFILE%\Desktop\F1C_ghidra_project\mods\_README.md` — the only in-game-confirmed mod is `cut_track_dq` (steward routine `FUN_004bccc0`, redirects penalty calls → `FUN_004bc0e0` "Disqualified:"). Read `tools\mod_pipeline\mods\cut_track_dq\apply_cut_track_dq.py` and `cut_track_dq.js` — these document three byte edits at `0x004bd0aa`/`0x004bd0b3`/`0x004bd0c1`, and the game has no literal "drive-through" string; its only pit-lane penalty is "Stop/Go Penalty" (`FUN_004bbd60`), which is the functional equivalent the task means by "drive-through penalty call." Confirmed this reading against `docs\35-mod-targets.md` (rank-5 race-rule cluster) and `docs\06-session-race-logic.md` / `docs\30-impl-specs\10-...spec.md` — no separate "drive-through" concept exists; Stop/Go is it.

**3. Located the caller and read its full source.** `python tools/investigate.py 0x004bccc0 --snippet` (per iron rule 2, batching the address) gave the dossier: mod-target tags "Cut Track"/"Speeding in Pitlane", callees including `FUN_004BBD60(Stop/Go Penalty Handler)` and `FUN_004BC0E0(Disqualification Handler)`. Then read the full 317-line source `decompiled_all\0x004bccc0__FUN_004bccc0.c` directly to see all penalty branches (cut-track, pit-lane speeding, wrong-way, ignored blue flags).

**4. Step 1 — resolved both targets' identity and calling convention** (never hand-derived):
```
cd tools/mod_pipeline && python asm_tools.py resolve 0x004bbd60 --source
cd tools/mod_pipeline && python asm_tools.py resolve 0x004bc0e0 --source
```
Results: `FUN_004bbd60` ("Stop/Go Penalty:") — **ret imm 8** (2 stack args); `FUN_004bc0e0` ("Disqualified:") — **ret imm 4** (1 stack arg). Both are `__thiscall`. Recorded per skill requirement — the arg-count mismatch (2 vs 1) flags a stack-balance problem to resolve in Step 2, not ignore.

**5. Step 2 — computed the redirect (tool-only, never hand math).** First ran unscoped to see all sites (as the tool requires before scoping):
```
python asm_tools.py redirect 0x004bccc0 0x004bbd60 0x004bc0e0
```
Output: **3 call sites** (`0x004bce10` pit-speeding, `0x004bd0b3` cut-track, `0x004bd6f8` ignored-blue-flags) — exactly the "shared handler, many penalty types" warning the skill flags. Per iron rule ("redirect the call SITE, never the shared function"), scoped to the one site with prior in-game confirmation and canonical documentation (`.claude/skills/f1c-byte-patch/reference.md` §Worked redirect explicitly names this exact site as "stopgo -> DQ"):
```
python asm_tools.py redirect 0x004bccc0 0x004bbd60 0x004bc0e0 --at 0x004bd0b3
```
Output: `!! STACK MISMATCH`, delta 4 → tool names the fix: **NOP the `push imm8` at `0x004bd0aa`** (`6a0a` → `9090`); call site `0x004bd0b3`: `e8a8ecffff` → `e828f0ffff`. This matches the reference doc's canonical worked example byte-for-byte, cross-validating the derivation.

**6. Verified live-exe state independently (read-only, no manifest touch).** Read raw bytes at both VAs directly from `%USERPROFILE%\Desktop\F1 Challenge V10\F1 Challenge Online.exe` via a one-off Python section-header walk (no writes):
```
0x4bd0aa -> file-offset 0xbd0aa: 6a0a
0x4bd0b3 -> file-offset 0xbd0b3: e8a8ecffff
```
Both match the expected **original** bytes — exe is unpatched, no drift from the shipped `cut_track_dq` copy. Also ran the allowed read-only check:
```
python tools/patch.py status
```
→ `(no patches defined — use add)` — manifest (`mods/patches/manifest.json`) is empty, so no collision risk.

**7. Step 3 — patch registration: DRAFTED, not executed** (hard constraint forbids `patch.py add`, which writes the manifest file). Exact commands to run when unblocked:
```
python tools/patch.py add steward_stopgo_to_dq 0x004bd0aa "9090" --desc "NOP push 0xA (stop/go duration arg) - stack balance for Stop/Go(2-arg)->DQ(1-arg) redirect, steward routine FUN_004bccc0 cut-track branch"
python tools/patch.py add steward_stopgo_to_dq 0x004bd0b3 "e828f0ffff" --desc "redirect Stop/Go Penalty call (FUN_004bbd60) -> Disqualification Handler (FUN_004bc0e0) at call site 0x004bd0b3 in steward routine FUN_004bccc0"
```
Patch name `steward_stopgo_to_dq` deliberately distinct from the shipped `cut_track_dq` — this patch touches only the stop/go call the task specifies, not the separate warning-handler redirect (`0x004bd0c1`, a different old-target/function) that the full `cut_track_dq` mod also includes.

**8. Step 4 — inspection: DRAFTED.** Would run `python tools/patch.py status && python tools/patch.py show steward_stopgo_to_dq` after Step 3 lands; expect both sites `clean` (on-disk bytes == recorded original, per the independent verification in step 6).

**9. Step 5 — LIVE boundary: STOPPED here, per instructions.** The game is not running, so the Frida-first reversible test (required before any disk bake) cannot be executed. Drafted the twin script content (not written to disk), adapted from `cut_track_dq.js`:
```javascript
'use strict';
const EDITS = [
  { va: '0x004bd0aa', orig: '6a0a',       patch: '9090'       }, // NOP push 0xA (stopgo duration)
  { va: '0x004bd0b3', orig: 'e8a8ecffff', patch: 'e828f0ffff' }, // Stop/Go -> DQ
];
function hexToBytes(h){const a=[];for(let i=0;i<h.length;i+=2)a.push(parseInt(h.substr(i,2),16));return a;}
function apply(){
  for (const e of EDITS){
    const cur = ptr(e.va).readByteArray(e.orig.length/2);
    const curHex = Array.from(new Uint8Array(cur)).map(b=>b.toString(16).padStart(2,'0')).join('');
    if (curHex !== e.orig){ console.log('[steward_stopgo_to_dq] ABORT: '+e.va+' expected '+e.orig+' found '+curHex); return; }
  }
  for (const e of EDITS){
    Memory.protect(ptr(e.va), e.patch.length/2, 'rwx');
    ptr(e.va).writeByteArray(hexToBytes(e.patch));
    console.log('[steward_stopgo_to_dq] patched '+e.va+': '+e.orig+' -> '+e.patch);
  }
  console.log('[steward_stopgo_to_dq] active.');
}
globalThis.restore = function(){ for (const e of EDITS){ Memory.protect(ptr(e.va), e.orig.length/2,'rwx'); ptr(e.va).writeByteArray(hexToBytes(e.orig)); } console.log('restored.'); };
apply();
```
Predicted observable (to check once the game runs): on a race-session, 2nd+ cut-track offense (`param_1[0x34] >= 2`, cut score ≤ `_DAT_005acb30`), the HUD message changes from "Stop/Go Penalty: Cut Track" to "Disqualified: Cut Track", and the vehicle's penalty-state field (`+0xc`) goes to `3` (DSQ) instead of entering stop/go countdown. Run: `frida -p <F1C pid> -l steward_stopgo_to_dq.js`.

**10. Where and why I stopped.** Per the skill's explicit STOP condition ("Game not running at Step 5/7 → stop; report the patch is staged but unconfirmed") and the session's hard read-only/no-mutation constraint, I did not run `patch.py add`, did not run the Frida script, and did not run `patch.py apply` (which additionally requires `--out` and Step-5 confirmation first, neither satisfiable here). Steps 1–4 are fully valid, tool-verified, and reproducible; Steps 5 onward remain drafted-only until the game is running and the manifest write is permitted.

**Unverified/remaining:**
- Registering the two sites in `mods/patches/manifest.json` (commands given above).
- Confirming the predicted observable live via the Frida twin before baking to disk.
- `patch.py apply steward_stopgo_to_dq --out "F1 Challenge Online (steward_stopgo_to_dq).exe"` only after that confirmation.
- Returning to `f1c-mod-lifecycle` Gates 7–8 for in-game confirmation and ledger/`[CORRECTION]` bookkeeping.

No files were created, edited, or deleted; no mutating command was run. `mods/patches/manifest.json` remains `{"exe": "...", "patches": {}}`.
