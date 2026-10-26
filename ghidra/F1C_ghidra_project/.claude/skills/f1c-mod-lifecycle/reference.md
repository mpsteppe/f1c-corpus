# f1c-mod-lifecycle — reference: the cut_track_dq end-to-end walkthrough

The ONE in-game-confirmed mod (per the ledger, `mods/_README.md` §Related (not yet
consolidated here)): cutting the track = instant DQ. It is the reference
implementation for the whole lifecycle and for `f1c-byte-patch`.

**Address provenance note:** every address and byte string below is reproduced
from its canonical sources — `tools/mod_pipeline/MODDING_PLAYBOOK.md`
§Worked example (fully reproducible with the tools) and
`tools/mod_pipeline/mods/cut_track_dq/` (`apply_cut_track_dq.py`,
`cut_track_dq.js`). Cite those files; do not treat this walkthrough as the
canonical home of any address, and never reuse these addresses for other mods.
Per skill conventions, every address-bearing line carries a `doc-anchors`
provenance tag — strip the tags to recover the verbatim source text.

## The worked-example commands (PLAYBOOK, via _meta/doc-anchors.md)

```
# identify the DQ handler by its string
python asm_tools.py resolve 0x004bc0e0        # -> "Disqualified:", ret imm 4   # per doc-anchors
# redirect the two cut-track penalty calls in the steward routine
python asm_tools.py redirect 0x004bccc0 0x004bbc60 0x004bc0e0 --at 0x004bd0c1  # warning->DQ, delta 0 (per doc-anchors)
python asm_tools.py redirect 0x004bccc0 0x004bbd60 0x004bc0e0 --at 0x004bd0b3  # stopgo->DQ, delta 4 -> NOP push at 0x004bd0aa (per doc-anchors)
```

(cwd for these is `tools/mod_pipeline/` — see `f1c-byte-patch` for the modern
step-by-step form of the same commands.)

Resulting edits (PLAYBOOK, via _meta/doc-anchors.md):

```
0x004bd0aa  6a0a       -> 9090        NOP the stopgo `push 0xA`   [doc-anchors]
0x004bd0b3  e8a8ecffff -> e828f0ffff  stopgo -> DQ                [doc-anchors]
0x004bd0c1  e89aebffff -> e81af0ffff  warning -> DQ               [doc-anchors]
```

Followed by, in the PLAYBOOK: "In-game confirmed: any registered cut now
disqualifies."

## How the walkthrough maps onto the 8 gates

| Lifecycle gate | What cut_track_dq did |
|---|---|
| 1 Ledger | (It CREATED the first ledger-confirmed entry; today you would find it there and copy it.) |
| 2 Claims | Anchor by the player-facing string ("Disqualified:") → the handler; identity + `ret imm 4` (arg count / stack cleanup) from `asm_tools.py resolve` |
| 3 Preflight | Facts here were byte-level FACTs (resolve/redirect read the exe directly — FACT tier per `INDEX.md` §Trust tiers — READ THIS BEFORE TRUSTING ANY FILE) |
| 4 Rung | Rung 3, call-site byte redirect — the game supplies correct args itself; no injected code at all |
| 5 Implement | `asm_tools.py redirect` per CALL SITE (`--at`), not per function — the warning/stopgo handlers are shared by many penalty types; redirecting the function would change ALL of them |
| 5 (stack) | Non-zero stack delta (4) between old and new targets → the tool pinpointed the exact `push` to NOP; skipping this corrupts the stack |
| 6 Logging | Edits baked into an apply script that verifies-then-writes, plus a reversible Frida twin tested first |
| 7 Confirm | Predicted observable written in advance: "cut a corner → instant DQ"; user tested in-game; prediction held |
| 8 Exit | Ledger row: in-game confirmed |

## apply_cut_track_dq.py — the apply-script anatomy every rung-3 mod copies

Header docstring states scope and safety (verbatim): "Only these two call sites
(the cut-track branch) are touched; pit-speeding, blue-flag and wrong-way
penalties are unaffected." and "Writes a MODDED COPY; never modifies the
original. Verifies original bytes first."

The EDITS table (from the script, via _meta/doc-anchors.md):

```python
# (VA, expected_original_hex, new_hex, note)
EDITS = [
    (0x004bd0aa, "6a0a",       "9090",       "NOP push 0xA (stopgo seconds)"),  # per doc-anchors
    (0x004bd0b3, "e8a8ecffff", "e828f0ffff", "stopgo call -> DQ"),              # per doc-anchors
    (0x004bd0c1, "e89aebffff", "e81af0ffff", "warning call -> DQ"),             # per doc-anchors
]
```

Script structure (the pattern every `apply_*.py` must copy):

1. `SRC` = absolute path to the original exe; `IMAGE_BASE = 0x00400000` (per doc-anchors / INDEX.md — non-ASLR).
2. `sections(data)` — parse the PE section table from raw bytes (no deps).
3. `va_to_fo(secs, va)` — VA → file offset via section mapping; error if unmapped.
4. **Verify + stage loop**: for every edit, read the bytes at the file offset and
   compare to `expected_original_hex`. On mismatch: print expected vs found,
   "Aborting — wrong exe version or already patched.", `sys.exit(1)`. No partial
   application — ALL edits verified before ANY write.
5. **Apply to copy**: patch the in-memory buffer, write to
   `F1 Challenge Online (CutTrackDQ).exe` beside the original. Original untouched.
   Rollback = delete the copy.

## cut_track_dq.js — the Frida twin (test-first rung)

Same EDITS list (`{ va, orig, patch }`), applied to the RUNNING process instead of
the file: `apply()` first verifies ALL original bytes via `readByteArray` (aborts
on any mismatch with "wrong version or already patched"), then
`Memory.protect(p, n, 'rwx')` + `writeByteArray` per edit. Exposes
`globalThis.restore()` writing the original bytes back — in-session undo.
Run: `frida -p <F1C pid> -l cut_track_dq.js`.

This is PLAYBOOK iron rule 5 ("Test with Frida first, bake to exe second",
`tools/mod_pipeline/MODDING_PLAYBOOK.md` §Iron rules (violate these and you break
the game)) made concrete: reversible, survives on-disk integrity checks, and
confirms behavior live BEFORE any exe copy exists. For richer runtime
observation while the twin runs → `f1c-frida-trace`.

## Why this mod worked when others stalled

Compare the ledger (`mods/_README.md` §Current contents): the stalled mods either
built code on an unverified GUESS-tier fact or stopped at "writes land" without an
in-game observable. cut_track_dq stayed on FACT-tier byte reads end to end, scoped
its change to two call sites, fixed the stack delta the tool reported, tested
reversibly first, and had a falsifiable prediction. That is the lifecycle.

---
Canonical sources: `tools/mod_pipeline/MODDING_PLAYBOOK.md` §Worked example (fully reproducible with the tools); `tools/mod_pipeline/MODDING_PLAYBOOK.md` §Iron rules (violate these and you break the game); `tools/mod_pipeline/MODDING_PLAYBOOK.md` §Gotchas learned the hard way; `mods/_README.md` §Current contents; `INDEX.md` §Trust tiers — READ THIS BEFORE TRUSTING ANY FILE
Last validated: 2026-07-18 against 6bcccfe
