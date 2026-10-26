# 34 — Source Atlas (real file / line / name coordinates)

Static harvest of the source coordinates the compiler baked into F1C's trace and
assert call sites. **The source text is NOT in the binary** (compiled away —
comments, local names, expressions are gone). What survives is `__FILE__` /
`__LINE__` string+integer literals plus operation-naming message strings. This
atlas collects them so every reachable trace/assert point maps to a real
`(source_file, line, operation)` and, where derivable, the address it guards.

- **Tool:** `tools/harvest_source_atlas.py` (re-runnable)
- **Data:** `work/source_atlas.csv` (193 rows, 28 source files)
- **Inputs:** decompiled `.c` (`analysis_pipeline/analyzed/`, `decompiled_all/`) +
  `tools/ida_strings.csv` (IDA's byte-level string→xref table)

## Confidence model — read before trusting a row

| Column | Basis | Confidence |
|--------|-------|-----------|
| `file`, `full_path` | baked `\Source\xxx.cpp` string literal (IDA read the bytes) | **FACT** |
| `line` | `__LINE__` integer literal at the call site | **FACT** |
| `message` | real message string literal | **FACT** |
| `class`, `method` | parsed from the message (`"Entered DynMan::Enter()"`) | **FACT** (when message contains `Class::Method`) |
| `wrapper_addr` | address of the function containing the call site | **FACT** |
| `target_addr` | heuristic: first non-trace, non-self `FUN_` call in the wrapper | **HEURISTIC** — spot-verified only |

`target_addr` is right for clean single-purpose lifecycle wrappers (verified e.g.
`dynman.cpp:507 DynMan::Enter → 0x0042bd60`) but is **not** row-by-row verified.
20 rows have no derivable target (multi-check functions where the check is inline,
so the relevant address is `wrapper_addr` itself). Verify before relying on it.

## How the coordinates get baked in

The common trace-wrapper pattern (decompiled):

```c
void FUN_0042c130(void) {                                   // wrapper @ 0x0042c130
  if (FUN_004d7a50(2, "...\\Source\\dynman.cpp", 0x1fb))     // threshold, FILE, LINE=507
    FUN_004d7aa0(&ctx, "Entered DynMan::Enter()");          // MESSAGE -> Class::Method
  FUN_0042bd60();                                           // guarded body (target)
}
```

`FUN_004d7a50` = trace guard (level, file, line), `FUN_004d7aa0` = emit (message).
Error/assert sites use the same file+line literals without a `Class::Method`
message — those still pin the function's job (e.g. `tire_manager.cpp:1080
"Non-existent tire brand"`).

This is fully static — it captures sites that never execute at runtime, so the
atlas (193) exceeds what the live trace prints (~150). See CHANGELOG 2026-07-17
for the runtime-trace ceiling finding (trace levels >2 emit nothing extra).

## Source files present (28)

Real ISI source filenames, confirmed from baked paths:

`NetComm.cpp` · `steward.cpp` · `vehload.cpp` · `tire_manager.cpp` · `specialfx.cpp` ·
`game.cpp` · `setup.cpp` · `vidman.cpp` · `dynman.cpp` · `hwinput.cpp` · `onscreen.cpp` ·
`plrfile.cpp` · `sound.cpp` · `vehgfx.cpp` · `hdvehicle.cpp` · `camera.cpp` · `pitcrew.cpp` ·
`render.cpp` · `ai_db.cpp` · `htree.cpp` · `osman.cpp` · `O_BaseGz.cpp` · `Replay.cpp` ·
`garage.cpp` · `options.cpp` · `searchgrid.cpp` · `util.cpp` · `weather.cpp`

Root: `D:\dev\F1_1999_2002\Source\`.

## Source-file range expansion (item A)

Functions from one `.cpp` are contiguous in `.text`. Using every function that
references a `\Source\xxx.cpp` string as an ANCHOR (fact), anonymous functions
bracketed by two same-file anchors inherit that file.

- **Tool:** `tools/expand_source_files.py`
- **Data:** `work/source_file_map_expanded.csv`

**Honest yield (anchor density is the ceiling — 121 anchors / 6170 funcs):**

| confidence | count | meaning |
|-----------|-------|---------|
| ANCHOR | 120 | references a `\Source` path — **FACT** |
| HIGH | 302 | bracketed by two same-file anchors — reliable |
| MED | 223 | within 8 funcs of a boundary anchor — tentative |
| UNKNOWN | 5525 | no bracketing anchor — **left blank, not guessed** |

**Usable = 422** (ANCHOR + HIGH) across 30 files. Top: NetComm 116, specialfx 52,
steward 48, setup 25, plrfile 21, vidman 20. Validated against `docs/00-source-tree.md`
explicit ranges (e.g. game.cpp HIGH funcs fall inside its stated 0x0042cf10–0x0042dbcb
span). The 5525 UNKNOWN are **not** assigned — pushing past 422 needs more anchors
(more string-owner mappings, vtable clusters, or cross-binary matches), not looser
guessing. The earlier `weather.cpp = 2837` over-assignment was a sparse-anchor bleed
and was removed by refusing to extrapolate across large gaps.

## Uses

1. **Name correction** — the 68 `Class::Method` rows are ground-truth names to
   cross-check/rename doc guesses.
2. **Mod targeting** — enforcement/validation messages feed `docs/35-mod-targets.md`.
3. **Source homing** — the 422 usable rows give anonymous funcs a real home file.

Full rows: `work/source_atlas.csv`, `work/source_file_map_expanded.csv`.
