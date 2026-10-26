# decompiled_all/ — Raw Decompiled Source (FACT tier)

666 string-anchored `.c` files: functions whose purpose is identifiable because
they reference a meaningful string (config key, assert path, UI label).

**This is ground truth.** When a `docs/` label disagrees with what a `.c` here
shows, the `.c` wins.

## Naming

`0x00XXXXXX__FUN_00XXXXXX.c` — the hex in the filename is the function's virtual
address. Line 1–2 of each file lists the strings it references (the anchor).

## Related raw-source locations (all FACT tier)

| Path | Content |
|------|---------|
| `decompiled_all/` | 666 string-anchored (this dir) |
| `analysis_pipeline/analyzed/` | 6,116+ decompiled functions (the bulk) |
| `tools/decompiled_ida/` | 495 IDA Hex-Rays (IDA-only functions) |

## Fast lookup

`python tools/mod_pipeline/asm_tools.py resolve <addr> --source` dumps the raw `.c`
plus confirmed identity, callers, and calling convention in one shot.
