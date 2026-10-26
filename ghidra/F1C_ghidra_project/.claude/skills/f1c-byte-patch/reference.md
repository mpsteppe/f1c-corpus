# f1c-byte-patch — reference: manifest anatomy, worked redirect, Frida twin

## Manifest anatomy — `mods/patches/manifest.json`

Structure (from `tools/patch.py` source; the manifest is checked in):

```json
{
 "exe": "%USERPROFILE%\\Desktop\\F1 Challenge V10\\F1 Challenge Online.exe",
 "patches": {
   "<name>": {
     "desc": "<free text from --desc>",
     "sites": [
       {"va": <int VA>, "orig": "<hex of original bytes>", "new": "<hex of new bytes>"}
     ]
   }
 }
}
```

- One patch = one `<name>` = many `sites` (each `add` with the same name appends).
- `orig` is READ FROM THE EXE at `add` time — this recorded original is the whole
  safety mechanism. If a site was never `add`ed against the real target exe, no
  later verification is possible.
- Site length = byte length of `new` (orig is recorded at the same length).

### Site-state semantics (what `status` / `show` print per site)

| State | Meaning | Action |
|---|---|---|
| `clean` | on-disk bytes == recorded original | safe to `apply` |
| `applied` | on-disk bytes == recorded new | already patched; `apply` skips it |
| `FOREIGN` | bytes match NEITHER | **hard STOP** — other mod or wrong exe version |
| `MIXED(...)` | patch's sites disagree (some applied, some not/foreign) | investigate site by site with `show` |

`apply`/`revert` verify every site first and on any FOREIGN print (verbatim):
`  ABORT: bytes at 0x<va> match neither original nor patch (other mod / wrong exe version). Nothing written.`
Nothing is partially written. Overlapping patches are flagged at `add`/`status`
time as `!! COLLISION: 'A' and 'B' overlap at 0x<va>`.

### Copy vs in-place

- `apply <name> --out "COPY.exe"` → writes a patched COPY (relative name resolves
  next to the exe). Original untouched. Rollback = delete the copy. **This is the
  only mode this skill permits.**
- In-place `apply` (no `--out`) creates `<exe>.prepatch.bak` once (first ever
  apply) and then mutates the original — a STOP per the skill and per
  `tools/mod_pipeline/MODDING_PLAYBOOK.md` §Iron rules (violate these and you
  break the game) rule 2 ("Never modify the original exe").

## Worked redirect with byte-level before/after

**Address provenance note:** all addresses/bytes below are reproduced from
`tools/mod_pipeline/MODDING_PLAYBOOK.md` §Worked example (fully reproducible
with the tools) and `tools/mod_pipeline/mods/cut_track_dq/apply_cut_track_dq.py`
— the cut_track_dq mod, the one in-game-confirmed patch. Cite those files as the
canonical home; never reuse these addresses for a different mod. Per skill
conventions, every address-bearing line carries a `doc-anchors` provenance tag —
strip the tags to recover the verbatim source text.

Goal: cutting the track = instant DQ. Two penalty calls inside the steward
routine are retargeted to the DQ handler.

Step-1/2 tool runs (PLAYBOOK, via _meta/doc-anchors.md):

```
# identify the DQ handler by its string
python asm_tools.py resolve 0x004bc0e0        # -> "Disqualified:", ret imm 4   # per doc-anchors
# redirect the two cut-track penalty calls in the steward routine
python asm_tools.py redirect 0x004bccc0 0x004bbc60 0x004bc0e0 --at 0x004bd0c1  # warning->DQ, delta 0 (per doc-anchors)
python asm_tools.py redirect 0x004bccc0 0x004bbd60 0x004bc0e0 --at 0x004bd0b3  # stopgo->DQ, delta 4 -> NOP push at 0x004bd0aa (per doc-anchors)
```

Byte-level before/after (PLAYBOOK, via _meta/doc-anchors.md):

```
0x004bd0aa  6a0a       -> 9090        NOP the stopgo `push 0xA`   [doc-anchors]
0x004bd0b3  e8a8ecffff -> e828f0ffff  stopgo -> DQ                [doc-anchors]
0x004bd0c1  e89aebffff -> e81af0ffff  warning -> DQ               [doc-anchors]
```

Read the three edits like this:

- `e8 xx xx xx xx` is a rel32 CALL. Retargeting = keeping `e8`, replacing the
  4-byte little-endian displacement (`rel32 = target - (site + 5)`). asm_tools
  does this math; never do it by hand.
- The stopgo target cleans 4 more stack bytes than the DQ target (`ret imm`
  difference reported as `delta 4`). One caller-side `push 0xA` (`6a 0a`, the
  stop/go seconds argument) must therefore be NOPped (`90 90`) or the stack is
  corrupted on every call. The redirect tool names the exact push VA.
- The `--at` scoping is why only the CUT-TRACK branch changed: the warning and
  stopgo handlers are shared by many penalty types (pit speeding, blue flag,
  wrong way); redirecting the functions themselves would have changed all of them.
- Three sites, one patch name — in patch.py terms, three `add <name> ...` calls,
  then one `apply <name> --out`.

The equivalent apply-script form (EDITS tuple list, verify-all-then-write-copy)
and the gate-by-gate lifecycle mapping live in
`.claude/skills/f1c-mod-lifecycle/reference.md`.

## The Frida twin skeleton (Step 5's reversible test)

Pattern from `tools/mod_pipeline/mods/cut_track_dq/cut_track_dq.js` — same sites
as the manifest, applied to the RUNNING process:

- `EDITS` = list of `{ va, orig, patch }` hex entries (identical bytes to the
  manifest sites).
- `apply()`:
  1. For EVERY edit, `readByteArray` at `va` and compare to `orig`. Any mismatch
     → abort with "wrong version or already patched" — nothing written (mirror of
     patch.py's FOREIGN abort).
  2. Only then, per edit: `Memory.protect(p, n, 'rwx')` then `writeByteArray`.
- `globalThis.restore()` — writes all `orig` bytes back; in-session undo.
- Run: `frida -p <F1C pid> -l <name>.js`.

Why Frida first: reversible (restore or just restart the game), and it survives
on-disk integrity checks that can reject a patched exe (`tools/mod_pipeline/
MODDING_PLAYBOOK.md` §Gotchas learned the hard way). Confirm the predicted
observable live, then bake with `patch.py apply --out`. Ship BOTH artifacts with
the mod (`mods/_README.md` §How mods are made: every mod ships an `apply_*.py`
and a Frida `.js`).

## Gotchas checklist (numbered, from the PLAYBOOK)

1. **Redirect the call SITE (`--at`), not the shared function** — shared handlers
   serve many penalty types.
2. **MSVC 6.0 callee-cleans via `ret N`** — always reconcile the stack delta the
   redirect tool reports; NOP the exact push it names.
3. **thiscall: `this` rides in ECX**, not on the stack — matters the moment any
   analysis or hook touches a member function (Frida `args[0]` is the first STACK
   arg, not `this`).
4. **A patched on-disk exe may trip integrity checks / AV** — Frida memory patch
   first; if the disk copy is rejected, ship the Frida version.
5. **Don't infer behavior from doc summaries** — e.g. penalty severity uses a
   threshold, not a simple count (see §Gotchas learned the hard way); read the
   branch in raw `.c` before patching it.

---
Canonical sources: `_meta/toolfacts.md` §tools/patch.py; `_meta/toolfacts.md` §tools/mod_pipeline/asm_tools.py; `tools/mod_pipeline/MODDING_PLAYBOOK.md` §Worked example (fully reproducible with the tools); `tools/mod_pipeline/MODDING_PLAYBOOK.md` §Gotchas learned the hard way; `mods/_README.md` §How mods are made
Last validated: 2026-07-18 against 6bcccfe
