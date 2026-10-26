# WORKER E — F1C Struct Offset Synthesis

You are consolidating struct offset observations from documented function entries
into unified struct definitions.
Worker E of 18.

## STEP 1 — LOAD REFERENCE

Read the current struct reference first:
  `%USERPROFILE%\Desktop\F1C_ghidra_project\docs\13-struct-offsets.md`

## YOUR OUTPUT FILE

Write ALL output to: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\output\struct_synth\worker_E.md

## YOUR DOC FILES

- docs/10-vehicle-physics.md  (80 entries, 257 offset observations)

## TASK

For each doc file in your list:
1. Read the entire file
2. Find every `## FUN_` entry that contains a struct offset table
   (look for `**Struct offsets` sections with `| +0x` rows)
3. Extract ALL offset observations: offset, type, field name, which function uses it
4. Group offsets by the struct they belong to. Infer struct identity from:
   - Parameter name and usage context (param_1 as vehicle ptr, param_2 as tire ptr, etc.)
   - Offset ranges (vehicle struct uses 0x0000–0x48C0, tire uses stride 0xF8, etc.)
   - Which functions access it (physics functions = vehicle/tire struct, AI = AI struct)
5. For each struct, output a consolidated table:

```
## StructName (inferred)

Based on N function observations. Confidence: high/medium/low.

| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| +0x0000 | int | field_name | FUN_XXXXXXXX, FUN_YYYYYYYY | consistent across N uses |
| +0x0004 | float | field_name | FUN_ZZZZZZZZ | conflicts: FUN_A says int, FUN_B says float |
```

**Conflict resolution rules:**
- If 2+ functions agree on type and 1 disagrees → majority wins, note the outlier
- If usage suggests different struct types at same offset → split into separate structs
- `*(double *)` = 8-byte double, `*(float *)` = 4-byte float, `*(int *)` = 4-byte int
- `param_1[0x4a]` = int-indexed, real byte offset = 0x4a * 4

Write to disk periodically. Do not accumulate entire output in memory.

## RULES
0. NEVER move, rename, or delete any files.
1. Process ALL doc files in your list.
2. Include the source function address for every offset observation.
3. Flag conflicts explicitly — do not silently pick one.
4. Group by struct, not by source doc file.
