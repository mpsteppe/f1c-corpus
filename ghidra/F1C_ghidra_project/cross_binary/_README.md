# cross_binary — isiMotor1 family DELTA finder

Self-contained workspace. Finds functions in sibling isiMotor1 games that do
**NOT** exist in F1C, and (inverse pass) sibling versions of F1C's own
gap functions. Token-cheap: all matching is offline byte-level Python. DeepSeek
workers only ever see the NOVEL delta, never full corpora.

## Goal (corrected framing)

NOT "read every sibling." Instead:
- **dedup** sibling funcs that are byte-identical (mod relocation) to F1C = skip
- **novel** = sibling func with no F1C match = candidate (feed to workers)
- **gap-fill** (future pass) = sibling func matching an F1C region Ghidra/IDA
  failed to split → recover F1C's own algorithm from the cleaner sibling build

## Pipeline

```
IDA export  ->  fingerprint (byte_sigs + strings)  ->  xbin_match  ->  delta  ->  DS workers
 (offline)          (offline)                          (offline)     (offline)   (tokens here only)
```

1. **Export** each sibling: `<name>_byte_sigs.csv` + `<name>_strings.csv`
   via `tools/ida_*_export.py` pattern (idat.exe headless, PowerShell).
2. **Match**: `python cross_binary/scripts/xbin_match.py <name>`
   → `_delta/<name>_classified.csv` + `_delta/<name>_novel.csv`
3. **Decompile only novels** → `_decomp/<name>/` (IDA Hex-Rays on delta addrs).
4. **Classify** novels with DeepSeek workers (batch launcher, new mode).

## Matching signals (xbin_match.py)

| Verdict     | Rule | Meaning |
|-------------|------|---------|
| BYTE_EXACT  | full MD5 identical | duplicate (relocation-free leaf) |
| BYTE_MASK   | (size, masked-head) identical | duplicate mod relocation — **primary signal** |
| STRING      | shared 1:1 meaningful string | same func (currently inert, see TODO) |
| NOVEL       | none of the above | **keep — the delta** |

`mask()` zeros E8/E9 rel32 targets + in-image absolute addresses (0x400000–0x8fffff)
so shared engine code that differs only by relocation hashes identical. BinDiff-lite.

## Validation (correctness gate — PASSED)

Ran F1C vs NASCAR 2003 (known ground truth: prior pipeline matched 2,449 byte
+ 340 string = 2,789 F1C funcs, `tools/cross_binary_all_matches.csv`).
- Raw (size,head) only: 1,351 — FAIL (missed relocated funcs)
- **With masking: 3,614 matched — PASS** (exceeds prior full pipeline)

Masking is the reason the gate passes. Do not remove it.

## Current status

| Sibling | Fingerprints | Matched | Novel | Notes |
|---------|:-:|:-:|:-:|---|
| nascar03 | ✓ | 52.9% | 3,386 | 2002-gen, matches well |
| nascar04 | ✓ | 41.1% | 4,755 | 2002-gen |
| f1_2002_demo | ✓ | 44.9% | 4,087 | closest clean sibling |
| scgt | ✓ | **3.0%** | 2,378 | 1999 older compiler → mostly FALSE novels, EXCLUDED from delta |
| f1_2002_full | ✗ packed | — | — | SafeDisc; HIGH value (same gen, full set) — worth runtime dump |
| f1_2000 / f1_2001 | ✗ packed | — | — | SafeDisc + older gen → low yield, skip |
| rFactor | EXCLUDED | — | — | isiMotor2, wrong engine |

**Unified delta (xbin_dedup.py → `_delta/unified_novel.csv`, 9,645 clusters):**
- **206 triple-confirmed** (demo+nascar03+nascar04, absent from F1C) — crown jewels
- 579 double → **785 cross-confirmed** high-priority
- 8,860 single-sibling = game-specific / residual-false, low priority

Only same-compiler-generation siblings fed to dedup. SCGT excluded (compiler gap).

## TODO / known gaps

- **STRING signal inert**: F1C `ida_strings.csv` has empty `referencing_functions`;
  the `ida_data_xrefs.csv` join yields 0 (string addrs don't intersect data-global
  addrs). Byte-mask already exceeds baseline so deferred. To fix: export F1C
  string xrefs properly (IDA `XrefsTo` on each string EA) into a refs column.
- **Gap-fill pass** (stage 5b) not built: match sibling funcs against F1C
  `.text` gap regions (0x47fc54 etc.) rather than known funcs.
- **3DConfig.exe set + F1 2002 WIP demo**: scan for assertion strings with
  `.cpp`/line + RTTI `.?AV` (debug residue) — separate cheap pass, not func-delta.

## Files

- `scripts/xbin_match.py` — the matcher (stdlib only)
- `_fingerprints/` — per-sibling byte_sigs + strings (or reuse tools/)
- `_delta/` — classified + novel CSVs per sibling
- `_decomp/` — Hex-Rays .c for novel funcs only
