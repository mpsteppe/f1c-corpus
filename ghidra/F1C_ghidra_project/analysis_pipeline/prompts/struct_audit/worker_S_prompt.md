# WORKER S — F1C Struct Confidence Audit

You are auditing struct field definitions in docs/13-struct-offsets.md against
actual Ghidra decompilation source files.
Worker S of 20.

## STEP 1 — LOAD REFERENCES
1. `%USERPROFILE%\Desktop\F1C_ghidra_project\docs\13-struct-offsets.md` — audit target
2. `%USERPROFILE%\Desktop\F1C_ghidra_project\docs\12-globals-reference.md` — named globals
3. `%USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\` — source .c files

## OUTPUT FILE
Write ALL output to: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\output\struct_audit\worker_S.md

## YOUR STRUCT SECTIONS (14)

--- Section 258: Linked List Node (generic, multiple layouts) (14 offsets) ---
## Linked List Node (generic, multiple layouts)

Multiple linked-list implementations coexist. Common patterns:

**Layout A (offset 0x100):** Used by FUN_0054a2d0, FUN_0054a270
| +0x100 | ptr | HeadPtr | Linked list head |
| +0x104 | ptr | NextPtr | Per-node next pointer |

**Layout B (offset +0x204 head):** Used by FUN_0054abe0, FUN_0054ac30
| +0x204 | ptr | ListHead | Linked list head |
| +0x10 | ptr | NextNode | Next pointer |
| +0x140 | ptr | PrevNode | Previous pointer |

**Layout C (offset +0x1ac parent):** Used by FUN_005419d0
| +0x1ac | ptr | ParentPtr | Parent node |
| +0x1b0 | ptr | ListHead | Child list head |
| +0x1b4 | ptr | PrevPtr | Previous sibling |
| +0x1b8 | ptr | NextPtr | Next sibling |

**Layout D (offset +0x1e4):** Used by FUN_0053c5d0
| +0x1e4 | ptr | PrevPtr | Previous node |
| +0x1e8 | ptr | NextPtr | Next node |

**Layout E (offset +0xf8 list):** Used by FUN_00545090
| +0xf8 | ptr | ListHead | List anchor |
| +0x1b4 | ptr | Prev | Previous node (param_2) |
| +0x1b8 | ptr | Next | Next node (param_2) |

---



--- Section 259: Unused Empty Struct Offset Headers (0 offsets) ---
## Unused Empty Struct Offset Headers

The following functions have `**Struct offsets**` headers but no data rows:

FUN_0053e410, FUN_0058afe3, FUN_005984d3, FUN_00597bdc, FUN_0059bd00, 
FUN_005820c0, FUN_00584340, FUN_005866f0, FUN_005888e0, FUN_00588910,
FUN_00588a5e, FUN_00589a53, FUN_0058af53, FUN_0058b10d, FUN_0058b2e5,
FUN_00590458, FUN_00593dd0, FUN_005a6060, FUN_00586bd0, FUN_00587070,
FUN_00588958, FUN_00588f86, FUN_0058a366, FUN_0058cb90, FUN_0058d1e0,
FUN_0058da50, FUN_00599ef2, FUN_0059b761, FUN_0059bb92, FUN_0059d490,
FUN_0059ef70, FUN_005a0b10, FUN_005a48a0, FUN_005a6610 (63 total)

---

Generated from `extracted_offsets_20.json` — 235 observations, 172 with offset data, 63 empty headers.

---



--- Section 260: 19. Bounds2D (inferred) (4 offsets) ---
## 19. Bounds2D (inferred)

2D bounding box int pair.

| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| +0x120 | int | XMin | FUN_005977c4 |  |
| +0x124 | int | XMax | FUN_005977c4 |  |
| +0x140 | int | YMin | FUN_005977c4 |  |
| +0x144 | int | YMax | FUN_005977c4 |  |



--- Section 261: SuspensionDamperCoeffs (coeff array used by multiple functions) (8 offsets) ---
## SuspensionDamperCoeffs (coeff array used by multiple functions)

From FUN_00436470 (quadratic spring). Confidence: medium.

| Offset | Type | Field | Notes |
|--------|------|-------|-------|
| +0x04 | double | BiasA | Bias for channel A |
| +0x0c | double | LinearA | Linear coefficient A |
| +0x14 | double | QuadA | Quadratic coefficient A |
| +0x1c | double | BiasB | Bias for channel B |
| +0x24 | double | LinearB | Linear coefficient B |
| +0x2c | double | QuadB | Quadratic coefficient B |
| +0x34 | double | ResultA | Output result A |
| +0x3c | double | ResultB | Output result B |

---



--- Section 262: JointHingeBarStruct (inferred) (8 offsets) ---
## JointHingeBarStruct (inferred)

Inside JointArray/HingeArray (stride 0x30) from FUN_0056d930.

| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| +0x00 | char* | NameString | FUN_0056d930 | |
| +0x04 | (ptr) | NegBodyPtr | FUN_0056d930 | Negative body reference |
| +0x08 | double | DerivedSpring1 | FUN_0056d930 | Computed spring/tension value |
| +0x0c | (ptr) | PosBodyPtr | FUN_0056d930 | Positive body reference |
| +0x10 | double | DerivedSpring2 | FUN_0056d930 | Computed spring/tension value |
| +0x14 | double[6] | PositionOrientation | FUN_0056d930 | 6 doubles |
| +0x2c | int | LinkCounter | FUN_0056d930 | Joint index |
| +0x30 | - | StructStride | FUN_0056d930 | 0x30 |

---



--- Section 263: Vehicle Array Entry (stride 0x424) (46 offsets) ---
## Vehicle Array Entry (stride 0x424)

Based on 4 function observations (FUN_004c78f0, FUN_004c3d80, FUN_004c2a80, FUN_004c7b50). Confidence: high — consistent stride 0x424, documented in setup.cpp loader.

| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| +0x00 | char* | filename | FUN_004c3200, FUN_004c78f0 | from .veh file |
| +0x02 | char* | HDVehicle file path | FUN_004c3200 | |
| +0x04 | char* | HeadPhysics file path | FUN_004c3200 | |
| +0x06 | char* | Sounds file path | FUN_004c3200 | |
| +0x08 | char* | Graphics file path | FUN_004c3200 | |
| +0x0a | char* | GenString | FUN_004c3200 | |
| +0x0e–+0x10 | float×3 | Eyepoint | FUN_004c3200 | |
| +0x11–+0x13 | float×3 | CameraTarget | FUN_004c3200 | |
| +0x14–+0x16 | float×3 | MirrorPos | FUN_004c3200 | |
| +0x17–+0x19 | float×3 | MirrorNorm | FUN_004c3200 | |
| +0x1a–+0x1c | float×3 | SteeringWheelAxis | FUN_004c3200 | |
| +0x1d | char* | Number | FUN_004c3200, FUN_004c78f0 | also written as char string |
| +0x1f | char* | (unknown) | FUN_004c3200, FUN_004c78f0 | |
| +0x2f | char* | Driver name | FUN_004c3200, FUN_004c78f0 | |
| +0x3f | char* | Description | FUN_004c3200, FUN_004c78f0 | |
| +0x4f | char* | Engine file | FUN_004c3200 | |
| +0x5f | char* | Manufacturer | FUN_004c3200 | |
| +0x6f | char* | Classes | FUN_004c3200 | |
| +0x7c | char* | name field (at +0x7c) | FUN_004c3fe0, FUN_004c3f80 | used by name lookup |
| +0xaf | char* | FullTeamName | FUN_004c3200 | |
| +0xbc | char* | vehicle name | FUN_004c3f80, FUN_004c3fe0 | consistent across lookups |
| +0xcf | char* | TeamFounded | FUN_004c3200 | |
| +0xd3 | char* | TeamHeadquarters | FUN_004c3200 | |
| +0xe3 | char* | TeamStarts | FUN_004c3200 | |
| +0xe7 | char* | TeamPoles | FUN_004c3200 | |
| +0xeb | char* | TeamWins | FUN_004c3200 | |
| +0xef | char* | TeamWorldChampionships | FUN_004c3200 | |
| +0xf5 | void* | TrackLivery linked list | FUN_004c3200 | |
| +0x403c | int | SeasonPoints | FUN_004c2a80 | score accumulation |
| +0x4060 | int | FinishPosition | FUN_004c2a80 | qualifying/race position |
| +0x4064 | int | FinishState | FUN_004c2a80 | 0=running, 1=finished, 2=DNF, 3=DSQ |
| +0x409c | float | BestLapTime | FUN_004c2a80 | |
| +0x4620 | char* | DriverName | FUN_004c6a10, FUN_004c7b50 | full name string |
| +0x4660 | char[] | Nationality | FUN_004c6c40 | max 0x17 chars |
| +0x4677 | char | null terminator | FUN_004c6c40 | |
| +0x4678 | char* | Description | FUN_004c78f0 | from .veh +0x3f |
| +0x46b8 | char* | Number | FUN_004c78f0 | from .veh +0x1f |
| +0x46f8 | char[] | Abbreviation | FUN_004c6a10 | max 15 chars |
| +0x4707 | char | null terminator | FUN_004c6a10 | |
| +0x4714 | char* | VehicleDescription | FUN_004c7b50 | vehicle description path |
| +0x4894 | int | vehicle index | FUN_004c6c40, FUN_004c78f0 | index in vehicle array |
| +0x4898 | int | VehicleIndex | FUN_004c7b50 | duplicate of +0x4894? |
| +0x489c | int | DriverNumber | FUN_004c7b50 | driver number |
| +0x48a0 | int | (unknown) | FUN_004c7b50 | |
| +0x48a4 | int | flag (-1 after load) | FUN_004c6c40 | |
| +0x48a8 | int | flag (-1 after load) | FUN_004c6c40 | |
| +13000 | int | first-load flag | FUN_004c6c40 | 0 = first time (offscreen offset?) |

**Note on +0xbc vs +0x7c:** Both appear as name fields in lookup functions. May be different field names or aliases. +0xbc used by FUN_004c3f80 (vehicle name lookup), +0x7c by FUN_004c3fe0 (name comparison).

**Note on offset +13000:** This is suspiciously large. May be byte-indexed relative to a different base, not from same struct.

---



--- Section 264: Buffered I/O Stream Struct (3 offsets) ---
## Buffered I/O Stream Struct

Based on 1 function observation (FUN_00599081). Confidence: low.

| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| +0x00 | void* | vtablePtr | FUN_00599081 | virtual method table |
| +0x1c | byte* | BufferPtr | FUN_00599081 | read buffer base |
| +0x2c | int* | BufferEnd | FUN_00599081 | buffer limit pointer |

---



--- Section 265: Buffer/Mesh Allocation Struct (inferred) (11 offsets) ---
## Buffer/Mesh Allocation Struct (inferred)

Used by FUN_00403350. Manages multi-dimensional buffer allocation
with 3 buffer pointers (A/B/C) and 4 dimension fields.

Based on 1 function observation. Confidence: high.

| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| +0x08 | int | initializedFlag | FUN_00403350 | Set to 1 after alloc |
| +0x0c | int | countA | FUN_00403350 | dimA + 1 |
| +0x10 | int | countB | FUN_00403350 | dimB + countA |
| +0x14 | int | totalCount | FUN_00403350 | countB + dimC |
| +0x150 | ptr | bufferBPtr | FUN_00403350 | dimB × 0x1C array |
| +0x154 | ptr | bufferAPtr | FUN_00403350 | dimC × 0x1C array |
| +0x158 | ptr | bufferCPtr | FUN_00403350 | dimD × dimC × 0x1C 2D array |
| +0x15c | int | dimA | FUN_00403350 | First dimension |
| +0x160 | int | dimB | FUN_00403350 | Second dimension |
| +0x164 | int | dimC | FUN_00403350 | Third dimension |
| +0x168 | int | dimD | FUN_00403350 | Fourth dimension |



--- Section 266: Notes (0 offsets) ---
## Notes

- Many FUN_ entries do NOT have formal struct offset tables — they describe
  offsets inline in prose. All inline offsets in 19-renderer.md have been
  captured in this synthesis.
- The large RenderContext struct spans many functions and likely represents
  the main `RenderDevice` or `Renderer` C++ class with D3D device interface,
  render states, buffers, and per-frame state.
- UI functions (FUN_0048*) share a common UI control struct pattern with
  vtable at +0x00 and various state fields in the +0x00-0x200 range. The
  exact field layout varies by control type but follows a consistent pattern.
- offset 0x14 appears as "flags" in many contexts — this is polymorphic and
  depends on the struct type.

---



--- Section 267: CollisionProxyRegistration (inferred — param_1 in FUN_0044f0e0) (3 offsets) ---
## CollisionProxyRegistration (inferred — param_1 in FUN_0044f0e0)

Based on FUN_0044f0e0 + FUN_0044f0a0. Confidence: **medium**.

| Offset | Type | Field | Observed in | Notes |
|--------|------|-------|-------------|-------|
| +0x37C | byte[256] | ProxyActiveFlags | FUN_0044f0e0, FUN_0044f0a0 | Per-proxy active flag |
| +0x87C | int[256] | ProxyChildIndices | FUN_0044f0e0, FUN_0044f0a0 | Per-proxy child indices |
| +0xC88 | int[12] | ProxyLeafNodes | FUN_0044f0e0, FUN_0044f0a0 | Leaf node indices |

---



--- Section 268: RPMPerGearSubStruct (stride 0x0c, 5 gears) (3 offsets) ---
## RPMPerGearSubStruct (stride 0x0c, 5 gears)

Based on 1 function observation (FUN_004f6bf0). Confidence: **high**.

Per-gear RPM limits loaded from .svm. Stride = 0x0c (12 bytes) for 5 gears (0–4). The gear index is param_3, offset computed as `gear × 0x0c`.

| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| +0x04 + gear×0xc | float | MinimumRPM | FUN_004f6bf0 | × RPM_TO_RAD conversion |
| +0x08 + gear×0xc | float | MaximumRPM | FUN_004f6bf0 | × RPM_TO_RAD conversion |
| +0x0c + gear×0xc | float | NaturalRPM_recip | FUN_004f6bf0 | 1.0 / (NaturalRPM × RPM_TO_RAD); stored as reciprocal |

**Note:** 3 fields × 4 bytes = 12 bytes = 0x0c stride, confirming float (not double) per field.

---



--- Section 269: Source: docs/21-audio-network-internals.md (0 offsets) ---
## Source: docs/21-audio-network-internals.md

Source: docs/21-audio-network-internals.md (181 entries, 77+ offset observations)

---



--- Section 270: Summary (0 offsets) ---
## Summary

**File analyzed:** docs/02-ai-system.md (1536 lines, ~65 `## FUN_` entries)

**Result:** Extracted ~120 offset observations across 9 distinct structs. 2 conflicts identified (see below).

---



--- Section 271: Struct 5: SlipCurveEntry (stride 0x18 = 24 bytes) (6 offsets) ---
## Struct 5: SlipCurveEntry (stride 0x18 = 24 bytes)

Based on 2 function observations (FUN_004d5f70, FUN_004d75d0).
Confidence: **medium** — stride (0x18) confirmed by linear search in
FUN_004d75d0.

| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| +0x00 | char* | name | FUN_004d75d0 | searched by name string (linear comparison) |
| +0x04 | unknown | pad_or_id | — | 4 bytes gap, no documented access |
| +0x08 | float | peakSlip | FUN_004d5f70 | computed: max point of cubic spline evaluation |
| +0x0c | float | peakGrip | FUN_004d5f70 | computed: max grip from spline; all coeffs normalized by this |
| +0x10 | int | pointCount | FUN_004d5f70 | number of data points (≥3, first must be 0.0) |
| +0x14 | ptr | splineData | FUN_004d5f70 | array of cubic spline coefficients (stride 0x20 = 4 doubles per segment) |

**Type inference:** peakSlip/peakGrip sized as float (4 bytes each). If both
were double (8 bytes each), they would overflow the 0x18 stride. The doc does
not specify types; this is a best-fit inference.

**Spline data format:** Each segment at +0x14[i] = 4 doubles (a, b, c, d) for
cubic polynomial: ax³ + bx² + cx + d. Total spline = (pointCount - 1) × 4
doubles.

---



## TASK
For each struct section:
1. Extract all offset rows from the section (lines with `| +0x`)
2. For each offset: grep analyzed/ for files containing that offset pattern
   e.g. `grep -rl "+ 0x1330" analysis_pipeline/analyzed/`
3. Read matched .c files and verify: does the dereference type match docs/13?
   - `*(double *)(param + 0xXXX)` → double
   - `*(float *)(param + 0xXXX)` → float
   - `*(int *)(param + 0xXXX)` → int/dword
   - `param_1[0x4a]` → int-indexed, byte offset = 0x4a × 4
4. Grade confidence: HIGH (3+ agree), MEDIUM (1-2 agree), LOW (no .c evidence)
5. Flag CONFLICTS: same offset claimed as different types

## OUTPUT FORMAT

```
=== AUDIT RESULTS ===
## StructName

| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
|--------|-------------|--------------|------------|-------------|-----------|
| +0x0000 | int | field_name | HIGH | 5 files agree | none |
| +0x1330 | double | ??? | LOW | 0 files | FUN_X says float |

=== NEW OFFSETS DISCOVERED ===
| Struct | Offset | Type | Found In | Notes |
|--------|--------|------|----------|-------|
```

## RULES
0. NEVER modify any files except %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\output\struct_audit\worker_S.md.
1. Process ALL sections. For every offset in each section, run the grep.
2. Flag EVERY conflict — do not silently pick a winner.
3. New offsets: only report if seen in 2+ .c files.
4. Write to disk after each struct section.
