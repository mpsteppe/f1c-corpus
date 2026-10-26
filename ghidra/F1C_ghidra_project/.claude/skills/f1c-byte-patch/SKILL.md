---
name: f1c-byte-patch
description: Design, register, test, and apply static byte patches to the F1 Challenge exe — call-site redirects, constant flips, branch NOPs, vtable slot swaps — with asm_tools.py (resolve/redirect math) and patch.py (manifest, verify, apply to a COPY). Use when a task says "redirect this call", "NOP this branch", "flip this constant", "apply/revert the byte patch". Do NOT use to decide whether a byte patch is the right approach — use f1c-mod-lifecycle Gate 4. Do NOT use for injected DLL logic — use f1c-dll-mod. Do NOT use for runtime tracing — use f1c-frida-trace.
---

# Byte-patch the exe (redirect / flip / NOP) — always to a COPY

## When to use / when not

You arrive here from `f1c-mod-lifecycle` Gate 5 with a chosen rung of call-site
redirect, constant flip, branch NOP, or vtable swap — and preflight already clean.
Route out: strategy/rung decisions → `f1c-mod-lifecycle`; live memory pokes →
`f1c-live-probe`; the reversible Frida twin's runtime observation →
`f1c-frida-trace`; patch applied but game doesn't react → `f1c-debug-failed-mod`.
Neither tool here needs the game running until the `LIVE:` steps.

## Prerequisites

| Prerequisite | Check command | Expected |
|---|---|---|
| Manifest exists | `cd /c%USERPROFILE%/Desktop/F1C_ghidra_project && ls mods/patches/manifest.json` | path printed (checked in) |
| Target facts preflighted | — | `f1c-mod-lifecycle` Gate 3 exit code was 0 |
| Addresses in hand | — | caller / old-target / new-target VAs from your investigation (via `f1c-locate`), never from memory |

## Procedure

### Step 1: Resolve the target function's identity

Command:
```bash
cd /c%USERPROFILE%/Desktop/F1C_ghidra_project/tools/mod_pipeline && python asm_tools.py resolve <addr> [--source]
```
Expected output: one-shot dossier — identity, **ret-imm (calling convention / arg
count)**, callers, string anchors, source path; `--source` dumps the full raw `.c`.
If instead the identity or strings don't match what your plan assumed → your doc
claim was wrong; go back to `f1c-verify-claim` before touching bytes.
Record the `ret imm` of BOTH old and new call targets — MSVC 6.0 callee cleans the
stack via `ret N`; different arg counts between targets MUST be reconciled.

### Step 2: Compute the redirect bytes (never hand-do rel32 math)

Command:
```bash
cd /c%USERPROFILE%/Desktop/F1C_ghidra_project/tools/mod_pipeline && python asm_tools.py redirect <caller> <from> <to> --at <call_va>
```
Expected output: the E8 call site(s), retarget bytes, and the stack-balance delta.
This tool only EMITS bytes — it modifies nothing.
If instead `NOTE: <n> call sites ... To target one, pass --at <call_va>.` → you
omitted `--at` with multiple sites; ALWAYS scope with `--at`. Redirect the call
SITE, not the shared function — warning/stopgo-style handlers serve MANY penalty
types and an unscoped redirect changes all of them.
If instead `!! STACK MISMATCH` → the delta is non-zero; the tool tells you which
`push` to NOP. Add that NOP as an extra patch site. Never ignore this.
If instead `No call to <from> at <va>.` or `No E8 calls ... found` → wrong caller
or wrong VA; re-investigate, do not guess.

### Step 3: Register every site in the manifest (records ORIGINAL bytes)

Command (repeat per site, same `<name>`):
```bash
cd /c%USERPROFILE%/Desktop/F1C_ghidra_project && python tools/patch.py add <name> <va-hex> "<new bytes hex>" --desc "<what/why>"
```
Expected output: `<name>: site 0x<va>  <orig> -> <new>  (<n> bytes)` — `add` reads
the exe and records the original bytes, which is what makes later verification
possible. Hex tolerates spaces/commas/`0x`.
If instead `warning: bytes ... already equal the new bytes` → exe may already be
patched; investigate before continuing.
If instead `site 0x<va> already in patch '<name>' — remove first` → duplicate;
`python tools/patch.py remove <name>` only if you own that patch.
If instead `!! COLLISION: 'A' and 'B' overlap at 0x<va>` → two patches fight over
bytes; resolve before any apply.

### Step 4: Inspect state before doing anything

Command:
```bash
cd /c%USERPROFILE%/Desktop/F1C_ghidra_project && python tools/patch.py status && python tools/patch.py show <name>
```
Expected output: per-patch state `applied` / `clean` / `FOREIGN` / `MIXED(...)`;
`show` lists each site's VA, orig→new, and current on-disk state.
If instead any site shows `FOREIGN` → **hard STOP** (see STOP section).

### Step 5: LIVE: test the same bytes reversibly with Frida FIRST

Before any on-disk write, apply the identical edits as a Frida memory patch
(verify-all-originals → write → `restore()` undo). Copy the twin pattern from
`reference.md` in this skill's directory; run it against the live game and check
the predicted observable. A patched on-disk exe may trip integrity checks — the
Frida version survives them and is reversible. For deeper runtime observation
while it runs → `f1c-frida-trace`.
If the Frida test does NOT produce the observable → do not bake anything; go to
`f1c-debug-failed-mod`.

### Step 6: Apply to a COPY

Command:
```bash
cd /c%USERPROFILE%/Desktop/F1C_ghidra_project && python tools/patch.py apply <name> --out "F1 Challenge Online (<name>).exe"
```
Expected output: originals verified, new bytes written to the named COPY (relative
`--out` resolves next to the exe); original untouched. Already-in-target-state
sites are skipped, not re-written. Rollback = delete the copy.
If instead the FOREIGN abort prints (verbatim):
`  ABORT: bytes at 0x<va> match neither original nor patch (other mod / wrong exe version). Nothing written.`
→ hard STOP; see STOP section. Nothing was written — that is the tool working.

### Step 7: LIVE: confirm in-game, then close the lifecycle

Run the COPY, test the predicted observable, then return to `f1c-mod-lifecycle`
Gate 7 (confirmation) and Gate 8 (ledger row + `[CORRECTION]`s). To un-patch an
in-place-applied exe (which you should not have): `python tools/patch.py revert
<name>` verifies patched bytes then restores originals.

## STOP — do not proceed if

- `patch.py` reports FOREIGN (or `MIXED`) at any site → wrong exe version or stale
  manifest or another mod's bytes; investigate — never force, never re-`add` over it.
- You are about to `apply` WITHOUT `--out` → patching the original exe is a STOP.
  (In-place apply creates `<exe>.prepatch.bak` once, but the rule stands: COPY only.)
- Stack delta from Step 2 is non-zero and you have not added the compensating NOP
  site → stack corruption; go back to Step 2.
- You are redirecting a shared FUNCTION instead of a call SITE (`--at`) → scope it.
- Original bytes were never recorded (site not `add`ed from the real exe) → no
  verification is possible; start at Step 3.
- The plan involves calling game internals from injected code → forbidden ladder
  violation; re-read `f1c-mod-lifecycle` Gate 4.
- Game not running at Step 5/7 (`LIVE:`) → stop; report the patch is staged but
  unconfirmed (Steps 1–4 remain valid static work; Step 6 only after Step 5
  confirms the observable).
- About to run `apply` before Step 5's Frida test confirmed the predicted
  observable → forbidden; go back to Step 5.

## Failure modes and recovery

| Symptom | Likely cause | Action |
|---|---|---|
| `ABORT: bytes at 0x<va> match neither original nor patch ...` | wrong exe / other mod / stale manifest | STOP; compare `show` output vs exe; re-investigate |
| `no patch '<name>'` | typo / never added | `python tools/patch.py status` to list |
| `bad hex byte string: '<s>'` | malformed hex arg | fix formatting; spaces/commas/`0x` are fine |
| Frida test works, disk copy doesn't | integrity check on patched exe | ship the Frida version; note in ledger |
| patch applies clean, game ignores it | wrong site / doc oversimplification | `f1c-debug-failed-mod` |

## Deep reference

Read `reference.md` in this skill's directory for manifest anatomy, a full worked
redirect with byte-level before/after, and the Frida-twin skeleton.

---
Canonical sources: `_meta/toolfacts.md` §tools/patch.py; `_meta/toolfacts.md` §tools/mod_pipeline/asm_tools.py; `tools/mod_pipeline/MODDING_PLAYBOOK.md` §Gotchas learned the hard way; `tools/mod_pipeline/MODDING_PLAYBOOK.md` §Iron rules (violate these and you break the game); `mods/_README.md` §The strategy ladder (why mods fail)
Last validated: 2026-07-18 against 6bcccfe
