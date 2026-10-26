# 35 — Mod Target Index (candidate patch points)

Ranked list of functions that enforce, validate, or gate game behavior — the
branches a byte-patch or DLL-hook mod wants to relax, redirect, or bypass. Derived
from the enforcement/validation strings each function references.

- **Tool:** `tools/build_mod_targets.py` (re-runnable)
- **Data:** `work/mod_targets.csv` (155 rows)
- **Inputs:** `tools/ida_strings.csv` (string→function xrefs, byte-level) +
  `work/source_atlas.csv` (subsystem file tags)

## Confidence model — CRITICAL, do not skip

| Claim | Basis | Confidence |
|-------|-------|-----------|
| function *references* string S | IDA byte-level xref | **FACT** |
| `file` subsystem tag | function references a `\Source\xxx.cpp` string | **FACT** (41/155 rows) |
| `category` / `rank` | keyword scoring of the string | **JUDGMENT** (subjective, mine) |
| "patch function X changes rule Y" | inference from the string's meaning | **HYPOTHESIS** |

Only **one** target is IN-GAME CONFIRMED: `0x004bc0e0` (`"Disqualified:"`), the DQ
handler proven moddable by the cut=DQ mod (see `mods/`, project memory
`first-mod`). The other **154 are candidate hypotheses** — the string→function
link is fact, but "this is the lever to change the behavior" must be verified per
target (read the function, patch, test in-game) before shipping a mod.

## Ranking

| rank | category | count | mod use |
|------|----------|-------|---------|
| 5 | race_rule | 20 | flip/bypass penalties, DQ, flags |
| 4 | physics_limit | 42 | relax clamps/limits (grip, fuel, wear caps) |
| 3 | data_gate | 43 | bypass validation to load custom data (tires, meshes, tracks) |
| 2 | config_valid | 50 | loosen input validation |

## Rank-5 race-rule cluster (penalty / steward system)

`func_addr` = function referencing the rule string. **CONFIRMED** = in-game proven;
all others **CANDIDATE**.

| func_addr | rule string | status |
|-----------|-------------|--------|
| `0x004bc0e0` | Disqualified: | **CONFIRMED** (cut=DQ mod) |
| `0x0041a720` | Cut Track / Speeding In Pitlane | candidate |
| `0x0041a940` | Ignored Stop/Go Penalty | candidate |
| `0x004bba90` | Penalty: | candidate |
| `0x004bbc60` | Warning: | candidate |
| `0x004bbd60` | Stop/Go Penalty: | candidate |
| `0x004bc4e0` | Ignored Stop/Go Penalty | candidate |
| `0x004bccc0` | Cut Track / Speeding In Pitlane | candidate |
| `0x004a47e0` | STOP/GO: | candidate |
| `0x004aa270` | Get fines instead of penalties | candidate |
| `0x0042c440` | Pit Lane Assistance: | candidate |
| `0x004f4270` (vehload.cpp) | %s is an illegal .SVM file | candidate |
| `0x0054a870` / `0x005508a0` | Illegal mesh file name %s | candidate |
| `0x00552470` | Illegal font file type %s | candidate |
| `0x0055b6b0` (vehgfx.cpp) / `0x0055b8c0` | Illegal scene file name %s | candidate |

The `0x004bbxxx`–`0x004bcxxx` block is the penalty *dispatch* cluster — contiguous,
one confirmed member, the natural place to prototype rule mods.

## Verification protocol before treating a candidate as a mod point

1. `python tools/investigate.py <addr>` — dossier: source, globals, callers.
2. Read the function; confirm the string sits on an enforcement branch (not just a
   log line).
3. Identify the patch: redirect call / flip compare / NOP the branch.
4. Apply via `tools/mod_pipeline/` (reads real exe bytes), test in-game, then mark
   the row CONFIRMED here.

Full rows: `work/mod_targets.csv`.
