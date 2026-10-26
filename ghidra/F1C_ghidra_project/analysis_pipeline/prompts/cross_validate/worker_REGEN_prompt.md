# WORKER REGEN — F1C Re-documentation (47 functions)

You are re-writing documentation for 47 functions whose existing entries
were found to have errors during cross-validation. Read each source .c file and
write a complete, accurate replacement entry.

## STEP 1 — LOAD REFERENCES

Before processing any functions, read these files:
1. %USERPROFILE%\Desktop\F1C_ghidra_project\docs\12-globals-reference.md
2. %USERPROFILE%\Desktop\F1C_ghidra_project\docs\13-struct-offsets.md

## YOUR OUTPUT FILE

Write ALL output to:
%USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\output\cross_validate\worker_REGEN.md

Format:
```
=== TRIAGE LINES ===

=== FULL ENTRIES ===
<!-- target: docs/XX-name.md -->
## FUN_00XXXXXX — Name
...
```

Leave TRIAGE LINES section empty. Write each <!-- target: --> comment before its entry.
Write to the output file after every 5 functions to avoid data loss.

## FUNCTIONS TO RE-DOCUMENT (47)

1. FUN_00406AB0
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00406ab0__FUN_00406ab0.c
   target doc: docs/20-math-utilities.md
   known errors: [WRONG_DESC] Claims "Forwards call to another function. No additional logic" but source is 38-line constructor with vtab
2. FUN_00409970
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00409970__FUN_00409970.c
   target doc: docs/20-math-utilities.md
   known errors: [WRONG_DESC] Claims float self-copy at +0x18; source shows conditional multi-function call with 5 sub-calls
3. FUN_0044F540
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044f540__FUN_0044f540.c
   target doc: docs/unknown
   known errors: [MISSING_DETAIL] return handle masked, not boolean; [MISSING_GLOBAL] DAT_005ea438
4. FUN_0045D240
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0045d240__FUN_0045d240.c
   target doc: docs/20-math-utilities.md
   known errors: - [MISSING_CALLS] FUN_00561f60, FUN_00561f80 not documented
- [MISSING_RETURN] Always returns 1, not documented
5. FUN_00470230
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00470230__FUN_00470230.c
   target doc: docs/20-math-utilities.md
   known errors: [MISSING_CALLS] Doc says "forwards call, no additional logic" but source sets vtable AND calls FUN_0048b420(0,0,0,0,1,0)
6. FUN_0047A210
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0047a210__FUN_0047a210.c
   target doc: docs/20-math-utilities.md
   known errors: - [WRONG_DESCRIPTION] Doc claims "Function Call Wrapper". Source shows constructor: calls FUN_004668e0(0, 0x3f800000), s
7. FUN_0047BE00
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0047be00__FUN_0047be00.c
   target doc: docs/20-math-utilities.md
   known errors: [WRONG_DIRECTION] Condition inverted: doc says "if count exceeds val" but source calls when count <= val
8. FUN_0047C0A0
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0047c0a0__FUN_0047c0a0.c
   target doc: docs/20-math-utilities.md
   known errors: - [WRONG_DESCRIPTION] Doc claims "Sqrt Approximation / Distance Calc". Source shows string copy from FUN_00489920() to g
9. FUN_00486010
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00486010__FUN_00486010.c
   target doc: docs/20-math-utilities.md
   known errors: - [WRONG_CONST] Doc claims all fields zeroed; byte at +0x65 set to 1
10. FUN_00487260
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00487260__FUN_00487260.c
   target doc: docs/20-math-utilities.md
   known errors: [WRONG_LOGIC] Case 4 logic wrong — vtable call happens on both branches after FUN_00487740, not only "if both false"
11. FUN_0048E4B0
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0048e4b0__FUN_0048e4b0.c
   target doc: docs/unknown
   known errors: [MISSING_GLOBALS] DAT_005ea438; [MISSING_CALLS] FUN_00490920, FUN_004918d0; [INCOMPLETE_LOGIC]
12. FUN_00495B60
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00495b60__FUN_00495b60.c
   target doc: docs/20-math-utilities.md
   known errors: [PARTIAL] Stub "General utility function"; source has specific 4-iteration loop with conditional copy using FUN_00499a70
13. FUN_004999E0
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004999e0__FUN_004999e0.c
   target doc: docs/20-math-utilities.md
   known errors: - [WRONG_DESCRIPTION] Doc claims "Function Call Wrapper". Source shows initializer: sets [0]=0, [1]=0xffffffff, calls FU
14. FUN_0049CFC0
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0049cfc0__FUN_0049cfc0.c
   target doc: docs/20-math-utilities.md
   known errors: - [WRONG_DESC] Fabricated "Sets size, format for each slot" — speculative render target claim unsupported by source
15. FUN_004A3570
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004a3570__FUN_004a3570.c
   target doc: docs/20-math-utilities.md
   known errors: [MISSING_CALLS] Missing FUN_004a2840(0) call in bit-0 reset loop
16. FUN_004B32A0
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004b32a0__FUN_004b32a0.c
   target doc: docs/20-math-utilities.md
   known errors: - [WRONG_DESC] G/B extraction oversimplified — involves masking/shifting packed format
- [MISSING_CALLS] 8 called sub-fu
17. FUN_004C13C0
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004c13c0__FUN_004c13c0.c
   target doc: docs/20-math-utilities.md
   known errors: [WRONG_GLOBAL] claims DAT_005c329c referenced but not in source; uses FUN_004c1370() for count
**Corrected entry in:** w
18. FUN_004CAED0
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004caed0__FUN_004caed0.c
   target doc: docs/20-math-utilities.md
   known errors: 1. Title says "18-field" float comparison but source shows exactly 16 float fields: +0x0c/10/14/18/1c/20/24/28/2c (9), +
19. FUN_004CC970
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004cc970__FUN_004cc970.c
   target doc: docs/unknown
   known errors: [INACCURATE_FORMULA] missing _DAT_005aceb4 multiplier & mask; [MISSING_CALL] FUN_004b9cf0; [MISSING_GLOBALS] 12+ globals
20. FUN_004DCF80
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004dcf80__FUN_004dcf80.c
   target doc: docs/unknown
   known errors: [MISSING_CALL] FUN_00566650 call order; [MISSING_GLOBAL] DAT_005ea438
21. FUN_004DF110
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004df110__FUN_004df110.c
   target doc: docs/17-physics-collision.md
   known errors: - [MISSING_GLOBAL] .c references DAT_0059e440 not mentioned in entry
- [MISSING_GLOBAL] .c references _DAT_0059e46c not 
22. FUN_004EA930
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004ea930__FUN_004ea930.c
   target doc: docs/20-math-utilities.md
   known errors: [PARTIAL] Placeholder entry; source has 21 lines of clear 3D vector subtraction
23. FUN_004EE2D0
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004ee2d0__FUN_004ee2d0.c
   target doc: docs/unknown
   known errors: [FALSE_GLOBAL] claims _DAT_0059e8d0 not in source; [MISSING_GLOBALS] _DAT_008afeec/8 not documented
**Corrected entry in
24. FUN_00506971
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00506971__FUN_00506971.c
   target doc: docs/unknown
   known errors: [MISSING_CALLS] virtual dispatch calls; [INACCURATE_CALL] surface lock semantics
25. FUN_0050B260
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050b260__FUN_0050b260.c
   target doc: docs/20-math-utilities.md
   known errors: [MISSING_ARGS] Doc omits args (8,1) from FUN_00507496 call
26. FUN_00520FC6
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00520fc6__FUN_00520fc6.c
   target doc: docs/20-math-utilities.md
   known errors: [PARTIAL] Placeholder entry; source has 55 lines packed SSE vector normalization
27. FUN_005276C5
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005276c5__FUN_005276c5.c
   target doc: docs/20-math-utilities.md
   known errors: [WRONG_FIELD_LABEL] Doc swapped buffer [10] START and [0xb] END field descriptions
28. FUN_00534AAC
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00534aac___AIL_shutdown_0.c
   target doc: docs/unknown
   known errors: - [MISCATEGORIZATION] Miles Sound System audio thunk, not math utility
29. FUN_00548E20
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00548e20__FUN_00548e20.c
   target doc: docs/20-math-utilities.md
   known errors: [WRONG_VTABLE] claims "Assigns vtable pointer" but no vtable write exists
**Corrected entry in:** worker_C_batch_469_530
30. FUN_005507A0
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005507a0__FUN_005507a0.c
   target doc: docs/20-math-utilities.md
   known errors: [WRONG_CONST] Title says "7 Fields" but source zeroes 8 dwords (indices 0-7)
31. FUN_00556220
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00556220__FUN_00556220.c
   target doc: docs/20-math-utilities.md
   known errors: - [WRONG_CONST] Doc claims "13 dwords" zeroed; source zeroes 17 dwords (skips index 1)
32. FUN_0055BE20
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0055be20__FUN_0055be20.c
   target doc: docs/20-math-utilities.md
   known errors: [WRONG_RETURN] Claims returns copy status; function is void
33. FUN_0055D460
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0055d460__FUN_0055d460.c
   target doc: docs/unknown
   known errors: - [MISSING_ANALYSIS] Raw decompilation dump
- [MISSING_GLOBALS] Uses _DAT_0059e430, _DAT_0059e43c, DAT_008b8f28 not docu
34. FUN_0055EBA0
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0055eba0__FUN_0055eba0.c
   target doc: docs/20-math-utilities.md
   known errors: - [WRONG_DESCRIPTION] Doc says "thunk — compares two paths, returns 0 or 1" (5 bytes). Source is 366 bytes: 3D vector ma
35. FUN_00560340
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00560340__FUN_00560340.c
   target doc: docs/unknown
   known errors: [STUB_ONLY] missing else branch, globals, struct offsets
36. FUN_00567010
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00567010__FUN_00567010.c
   target doc: docs/20-math-utilities.md
   known errors: [PARTIAL] Placeholder "1 line" — source has 13 lines with 2 sub-calls
37. FUN_0056A390
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0056a390__FUN_0056a390.c
   target doc: docs/unknown
   known errors: [INCOMPLETE] stub entry — missing globals DAT_005e5238/3c/40, struct offsets, calls list
**Corrected entry in:** worker_
38. FUN_00587DD0
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00587dd0___strncpy.c
   target doc: docs/20-math-utilities.md
   known errors: - [WRONG_DESCRIPTION] Doc claims "NOT FOUND / decompiled file missing" but source file exists (0x00587dd0___strncpy.c, M
39. FUN_0058B92A
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0058b92a__FUN_0058b92a.c
   target doc: docs/unknown
   known errors: - [MISSING_ANALYSIS] Raw decompilation dump
- [MISCATEGORIZATION] Filesystem path resolver, not math utility
- [MISSING_
40. FUN_0058BC68
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0058bc68__FUN_0058bc68.c
   target doc: docs/20-math-utilities.md
   known errors: - [WRONG_CATEGORY] Doc describes as math comparison but function reads globals _DAT_005b8c80, _DAT_005b8d48, _DAT_005b8d
41. FUN_0058C411
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0058c411____freebuf.c
   target doc: docs/20-math-utilities.md
   known errors: [MISSING_CALLS] Missing FUN_0058aa6f (buffer free) from Calls section
42. FUN_0059325D
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059325d__FUN_0059325d.c
   target doc: docs/20-math-utilities.md
   known errors: - [WRONG_DESCRIPTION] Doc says "CRT _ftol2 — float-to-long rounding". Source shows CRT heap init: HeapCreate, HeapDestro
43. FUN_00593446
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00593446__FUN_00593446.c
   target doc: docs/20-math-utilities.md
   known errors: [MISSING_CALLS] Missing preconditions on vtable dispatch, missing else-if branch with FUN_0059379b
44. FUN_00594AB4
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00594ab4__FUN_00594ab4.c
   target doc: docs/20-math-utilities.md
   known errors: - [WRONG_CATEGORY] Doc describes as pure math utility but function accesses globals PTR_LOOP_005e796c, DAT_008d41b8 (OS 
45. FUN_00595DC8
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00595dc8__FUN_00595dc8.c
   target doc: docs/20-math-utilities.md
   known errors: - [MISSING_ANALYSIS] Entry is raw decompilation dump only — no human-readable analysis present. No **Key logic**, **Glob
46. FUN_0059A854
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059a854__FUN_0059a854.c
   target doc: docs/20-math-utilities.md
   known errors: - [WRONG_CONST] Vtable address wrong: doc PTR_FUN_005b7e34, source PTR_LAB_005b9ce4
- [WRONG_CALL] param_2 omitted from 
47. FUN_0059B490
   source: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059b490__FUN_0059b490.c
   target doc: docs/20-math-utilities.md
   known errors: [WRONG_TAG] Tag "File time conversion" incorrect — actual code is dynamic buffer reallocation
**Corrected entry in:** wo

## ENTRY FORMAT

```
<!-- target: docs/XX-name.md -->
## FUN_00XXXXXX — Descriptive Name

Source: filename.cpp | Confidence: high/medium/low
One-line summary.

**Key logic:**
- Step-by-step behavior, exact constants, all branches
- Name algorithms (dot product, lerp, clamp, PID, etc.)

**Struct offsets (param_1):**
| Offset | Field | Type | Notes |
|--------|-------|------|-------|

**Globals:**
- `DAT_XXXXXXXX` (KnownName if in docs/12) — read / written

**Calls:** FUN_AAAAAA (purpose), FUN_BBBBBB (purpose)

**Moddability:** configurable | hardcoded | hookable
```

## GHIDRA PATTERNS
- `*(double *)(ptr + 0x1330)` = struct field at offset +0x1330, type double
- `param_1[0x4a]` = byte offset 0x4a * 4 = 0x128
- `unaff_EBX/ESI/EBP` = register-allocated `this` pointer
- `DAT_XXXXXXXX` = global — resolve from docs/12 if possible

## RULES
1. NEVER skip a function. Write an entry for all 47 functions.
2. Read the .c source carefully — accuracy is critical, prior entries had errors.
3. The "known errors" field tells you what was wrong — fix those specifically.
4. Write `<!-- target: docs/XX-name.md -->` before EVERY entry using the doc given.
5. For each function: read .c file, write entry, append to output file.
6. DO NOT modify any existing files. Only write to the output file above.
