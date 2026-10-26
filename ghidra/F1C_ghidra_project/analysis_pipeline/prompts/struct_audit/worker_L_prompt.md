# WORKER L — F1C Struct Confidence Audit

You are auditing struct field definitions in docs/13-struct-offsets.md against
actual Ghidra decompilation source files.
Worker L of 20.

## STEP 1 — LOAD REFERENCES
1. `%USERPROFILE%\Desktop\F1C_ghidra_project\docs\13-struct-offsets.md` — audit target
2. `%USERPROFILE%\Desktop\F1C_ghidra_project\docs\12-globals-reference.md` — named globals
3. `%USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\` — source .c files

## OUTPUT FILE
Write ALL output to: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\output\struct_audit\worker_L.md

## YOUR STRUCT SECTIONS (14)

--- Section 160: TireForceQuadraticModel (param_1 — per-tire force model) (20 offsets) ---
## TireForceQuadraticModel (param_1 — per-tire force model)

Based on FUN_004f6950 and FUN_004f68b0. Confidence: **high**.

| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| +0x1ec | char | TireActive | FUN_004f68b0 | |
| +0x1f8 | double | ForceConst1 | FUN_004f68b0 | |
| +0x200 | double | ForceLinCoeff | FUN_004f68b0 | |
| +0x208 | double | ForceQuadCoeff | FUN_004f68b0 | |
| +0x210 | double | ForceConst2 | FUN_004f68b0 | |
| +0x218 | double | TorqueLinCoeff | FUN_004f68b0 | |
| +0x220 | double | TorqueQuadCoeff | FUN_004f68b0 | |
| +0x228 | double | TorqueCamberCoeff | FUN_004f68b0 | |
| +0x250 | double | LatForcePeak | FUN_004f68b0 | |
| +0x288 | double | LongForcePeak | FUN_004f68b0 | |
| +0x2e8 | double | CamberAngle | FUN_004f68b0 | |
| +0x2f8 | byte | ModelEnabledFlag | FUN_004f6950 | |
| +0x2fc | double | QuadraticC | FUN_004f6950 | Constant term |
| +0x304 | double | QuadraticA | FUN_004f6950 | Linear term |
| +0x30c | double | QuadraticB | FUN_004f6950 | Quadratic term |
| +0x314 | double | OutputQuadC | FUN_004f6950 | Output constant |
| +0x31c | double | OutputQuadA | FUN_004f6950 | Output linear |
| +0x324 | double | OutputQuadB | FUN_004f6950 | Output quadratic |
| +0x34c | double | AbsOutput1 | FUN_004f6950 | |
| +0x384 | double | AbsOutput2 | FUN_004f6950 | |

---



--- Section 161: PlayerOptionsFailureRates (FailureRate slots) (1 offsets) ---
## PlayerOptionsFailureRates (FailureRate slots)

Based on FUN_004aa270 (mentioned in 06-session-race-logic.md). Confidence: **medium**.

| Offset | Stride | Count | Field Name | Notes |
|--------|--------|-------|------------|-------|
| +0x5c8 | 0x24 | 7 | FailureRate[0..6] | {current=2, min=0, max=3} |

---



--- Section 162: 12. DoublyLinkedList (inferred) (3 offsets) ---
## 12. DoublyLinkedList (inferred)

Doubly-linked list node and container. Multiple offset variants.

| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| +0x1c/+0x2c | ptr | PrevPtr | FUN_005519e0, FUN_0055c2e0 | Previous node; offset varies by container |
| +0x20/+0x30 | ptr | NextPtr | FUN_005519e0, FUN_0055c2e0 | Next node; offset varies by container |
| +0x118/+0x1518 | ptr | ListHead | FUN_005519e0, FUN_0055c2e0 | Head pointer; offset varies by container |



--- Section 163: QuadFunctionCoeffs (spring/damper quadratic) (25 offsets) ---
## QuadFunctionCoeffs (spring/damper quadratic)

Coefficient set for quadratic spring/damper force computation.

Based on 5+ function observations (FUN_0043bb30, FUN_0043bb80, FUN_0043bbd0, FUN_0043e890, FUN_0043e980). Confidence: high.

| Offset | Type | Field | Observed in | Notes |
|--------|------|-------|-------------|-------|
| +0x17a8 | double | CoeffSetA[0] | FUN_0043bb30, FUN_0043e890 | Damper coeff set A (x0) |
| +0x17b0 | double | CoeffSetA[1] | FUN_0043bb30, FUN_0043e890 | Damper coeff set A (x1) |
| +0x17b8 | double | CoeffSetA[2] | FUN_0043bb30, FUN_0043e890 | Damper coeff set A (x2) |
| +0x17c0 | double | CoeffSetB[0] | FUN_0043bb30, FUN_0043e890 | Damper coeff set B (x0) |
| +0x17c8 | double | CoeffSetB[1] | FUN_0043bb30, FUN_0043e890 | Damper coeff set B (x1) |
| +0x17d0 | double | CoeffSetB[2] | FUN_0043bb30, FUN_0043e890 | Damper coeff set B (x2) |
| +0x17d8 | double | ConstTerm0 | FUN_0043bb80 | Quadratic constant A |
| +0x17e0 | double | LinearTerm0 | FUN_0043bb80 | Quadratic coefficient A |
| +0x17e8 | double | QuadTerm0 | FUN_0043bb80 | Quadratic coefficient A |
| +0x17f0 | double | ConstTerm1 | FUN_0043bb80 | Quadratic constant B |
| +0x17f8 | double | LinearTerm1 | FUN_0043bb80 | Quadratic coefficient B |
| +0x1800 | double | QuadTerm1 | FUN_0043bb80 | Quadratic coefficient B |
| +0x1808 | double | RestForceX | FUN_0043bbd0 | Spring rest force X |
| +0x1810 | double | StiffnessX | FUN_0043bbd0 | Spring stiffness X |
| +0x1818 | double | RestForceY | FUN_0043bbd0, FUN_0043e980 | Spring rest force Y |
| +0x1820 | double | StiffnessY | FUN_0043bbd0 | Spring stiffness Y |
| +0x1828 | double | RestForceZ | FUN_0043bbd0 | Spring rest force Z |
| +0x1830 | double | StiffnessZ | FUN_0043bbd0 | Spring stiffness Z |
| +0x1930 | double | ResultA | FUN_0043bb30 | Computed output A |
| +0x19e8 | double | ResultB | FUN_0043bb30 | Computed output B |
| +0x1a0c | double | Result0 | FUN_0043bb80 | Computed output 0 |
| +0x1abc | double | Result1 | FUN_0043bb80 | Computed output 1 |
| +0x1adc | double | ForceY | FUN_0043bbd0 | Output Y force |
| +0x1b94 | double | ForceX | FUN_0043bbd0 | Output X force |
| +0x1d9c | double | ForceZ | FUN_0043bbd0 | Output Z force |

---



--- Section 164: VectorPositionStruct (0x20 stride, interpolation points) (8 offsets) ---
## VectorPositionStruct (0x20 stride, interpolation points)

From FUN_004e3090. Confidence: medium.

| Offset | Type | Field | Notes |
|--------|------|-------|-------|
| +0x00 | float | SrcX | Source coordinate X |
| +0x04 | float | SrcY | Source coordinate Y |
| +0x08 | float | SrcZ | Source coordinate Z |
| +0x0c | float | TgtX | Target coordinate X |
| +0x10 | float | TgtY | Target coordinate Y |
| +0x14 | float | TgtZ | Target coordinate Z |
| +0x18 | float | Factor | Interpolation factor |
| +0x1c | float* | OutputPtr | Output pointer |
| Stride: 0x20 (32 bytes) | | | |

---



--- Section 165: InitFloatConstantsStruct (inferred) (20 offsets) ---
## InitFloatConstantsStruct (inferred)

Based on 1 function observation (FUN_004594d0). Confidence: medium.

Struct initialized with physics-related float constants (likely tire/vehicle params).

| Offset | Type | Value | Field Name | Observed in | Notes |
|--------|------|-------|------------|-------------|-------|
| +0x04 | float | 0.0 | Zero | FUN_004594d0 | Cleared |
| +0x1c | float | FLT_MAX | MaxBound1 | FUN_004594d0 | 0x7f7fffff |
| +0x20 | float | FLT_MAX | MaxBound2 | FUN_004594d0 | |
| +0x24 | float | 0.0 | Cleared1 | FUN_004594d0 | |
| +0x28 | float | 0.0 | Cleared2 | FUN_004594d0 | |
| +0x2c | float | 3.75f | PhysicsParam1 | FUN_004594d0 | |
| +0x30 | float | 0.0 | Cleared3 | FUN_004594d0 | |
| +0x34 | float | 3.25f | PhysicsParam2 | FUN_004594d0 | |
| +0x38 | float | 0.0 | Cleared4 | FUN_004594d0 | |
| +0x3c | float | 1.75f | PhysicsParam3 | FUN_004594d0 | |
| +0x40 | float | -4.19e8f | LargeNeg1 | FUN_004594d0 | |
| +0x44 | float | 0.813f | Coeff1 | FUN_004594d0 | |
| +0x48 | float | -4.19e8f | LargeNeg2 | FUN_004594d0 | |
| +0x4c | float | 0.752f | Coeff2 | FUN_004594d0 | |
| +0x50 | float | 0.0 | Cleared5 | FUN_004594d0 | |
| +0xc0 | float | 0.0 | Cleared6 | FUN_004594d0 | |
| +0xc4 | float | 0.0 | Cleared7 | FUN_004594d0 | |
| +0xc8 | float | 0.0 | Cleared8 | FUN_004594d0 | |
| +0xcc | float | 0.0 | Cleared9 | FUN_004594d0 | |
| +0xd0 | float | 0.0 | Cleared10 | FUN_004594d0 | |

---



--- Section 166: Terrain Validation Flags Struct (7 offsets) ---
## Terrain Validation Flags Struct

Based on 1 function observation (FUN_00460a10). Confidence: low. Offsets in a very large struct (>0x1b76e bytes).

| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| +0x1b754 | byte | terrain type byte 1 | FUN_00460a10 | |
| +0x1b755 | byte | terrain type byte 2 | FUN_00460a10 | |
| +0x1b76a | byte | check 1 pass (terrain) | FUN_00460a10 | |
| +0x1b76b | byte | check 2 pass (surface) | FUN_00460a10 | |
| +0x1b76c | byte | check 3 pass (CRC) | FUN_00460a10 | |
| +0x1b76d | byte | check 4 pass (track name) | FUN_00460a10 | |
| +0x1b76e | byte | check 5 pass (full path) | FUN_00460a10 | |

Note: At >112KB this may be a different struct or an offset relative to a different base pointer (e.g., a large track/track-database object).

---



--- Section 167: Source: docs/19-renderer.md (0 offsets) ---
## Source: docs/19-renderer.md

# Struct Offset Synthesis — Worker G (docs/19-renderer.md)

429 entries scanned. 161 offset observations extracted.



--- Section 168: Render Object / VTable Wrapper (inferred) (2 offsets) ---
## Render Object / VTable Wrapper (inferred)

Used by FUN_0052e170. Constructor sets vtable and initializes
observer list and property fields.

Based on 1 function observation. Confidence: low.

| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| +0x00 | ptr | vtable | FUN_0052e170 | Virtual method table |
| +0x90 | ptr | observerList | FUN_0052e170 | param_1[0x24] — observer list head |



--- Section 169: ViewportRect (inferred — param_1 in FUN_0044f680) (0 offsets) ---
## ViewportRect (inferred — param_1 in FUN_0044f680)

Based on FUN_0044f680. Confidence: **medium**.

| Index | Type | Field | Notes |
|-------|------|-------|-------|
| [0] | int | left | Viewport left |
| [1] | int | top | Viewport top |
| [2] | int | right | Viewport right |
| [3] | int | bottom | Viewport bottom |
| [4] | int | center_x | Computed center X |
| [5] | int | center_y | Computed center Y |
| [6] | int | scale_x | Fixed-point X scale |
| [7] | int | scale_y | Fixed-point Y scale |

---



--- Section 170: GridCellIndex (inferred — entry in FUN_0051d247) (0 offsets) ---
## GridCellIndex (inferred — entry in FUN_0051d247)

Based on FUN_0051d247. Confidence: **low** (stack-based array, not a persistent struct).

| Index | Type | Field | Notes |
|-------|------|-------|-------|
| [0] | int | minX | Left bound |
| [1] | int | maxX | Right bound |
| [2] | int | minZ | Bottom bound |
| [3] | int | maxZ | Top bound |
| [4] | int | minY | Near bound |
| [5] | int | maxY | Far bound |
| [6] | int | contactDistanceSq | Weighted squared distance |
| [7] | int | nonZeroCellCount | Count of occupied cells |

---



--- Section 171: 10. NetComm Session Struct (inferred) — large, multi-field (23 offsets) ---
## 10. NetComm Session Struct (inferred) — large, multi-field

Based on 14+ function observations from NetComm.cpp entries. Confidence: high (for frequently-accessed offsets).

| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| +0x0c | float | RefillTimeout | FUN_0045f950 | Client timeout refill value |
| +0x10 | float | ClientTimeout | FUN_0045f950, FUN_00464290 | Client timeout counter |
| +0x14 | int | ClientFlag | FUN_00464290, FUN_0045f950 | Client flag |
| +0x1c | float | GridTimer | FUN_00460380 | Client grid display timer |
| +0x1c | ptr? | NodeIDArray | FUN_00460cb0, FUN_0045eb50 | Node ID array (104 entries, at +0x1d4 from some refs) |
| +0x20 | int | SceneLoadedFlag | FUN_00460380 | Scene load wait flag |
| +0x28 | int | InitFlag | FUN_00464290 | First call flag |
| +0x29 | byte | OpeningFlag | FUN_00460e90, FUN_00461020, FUN_004612e0 | Track opened/closed (1=open, 0=closed) |
| +0x2c | float | OpenTimer | FUN_00461190, FUN_004612e0 | Track opening timer/-1.0f |
| +0x30 | int | BootedFlag | FUN_00461d20 | Boot notification displayed flag |
| +0x380 | float | ResetTimer | FUN_00464290, FUN_00461d20 | Reset accumulator/frame timer |
| +0x388 | int | ResetFlag | FUN_00464290 | Reset flag |
| +0x38c | float | KeepAliveAccum | FUN_0045f950 | Keep-alive accumulator |
| +0x390 | float | SyncTimeout | FUN_00464290, FUN_0045d890 | Sync/timeout accumulator |
| +0x398 | char[0x8c]×104 | PlayerNames | FUN_0045eb50 | Player name strings, stride 0x8c |
| +0x3c74 | int[104] | SlotNodeIDs | FUN_00460cb0, FUN_0045eb50 | Slot-to-node-ID mapping |
| +0x3e14 | int | SlotCount | FUN_00460cb0, FUN_0045eb50, FUN_0045fc50 | Number of active player slots |
| +0x3fc4 | int | Connected | FUN_00464290 | Connection flag |
| +0x1b770 | ptr | MsgListHead | FUN_00460e90 | Message linked list head |
| +0x1b774 | ptr | MsgListTail | FUN_00460e90 | Message linked list tail |
| +0x1b77c | int | MsgListCount | FUN_00460e90 | Message linked list count |
| +0x1b79c | int | NetworkActive | FUN_00461de0 | Network active flag |
| +0x1d4 | int[104] | NodeIDList | FUN_00460cb0 | Node ID array (also referenced from param_1 + 0x1d4) |

**CONFLICT:** +0x1c is "GridTimer" (float) in FUN_00460380 but likely same field offset reused for different purposes in different contexts. +0x1d4 is referenced as a node ID array in FUN_00460cb0 and also as part of slot struct in FUN_0045eb50 — these may reference different offsets relative to different pointer bases.

**NOTE:** The struct is very large (0x1b79c+ bytes = ~112,540 bytes). Many fields between +0x30 and +0x380 are undocumented. The stride 0x8c for player slots is consistent across FUN_0045eb50 and FUN_0045fc50.

---



--- Section 172: StreamEventDecompressor (inferred) (7 offsets) ---
## StreamEventDecompressor (inferred)

Based on 1 function (FUN_00510975). Confidence: medium.

Byte-stream event decompressor with nibble storage and dispatch callbacks.

| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| +0x00 | void* | StreamStruct | FUN_00510975 | Base pointer |
| +0x04 | code* | DispatchFn0 | FUN_00510975 | Secondary dispatch (program-change) |
| +0x14 | byte | EventStatus | FUN_00510975 | Status byte (0x4e=note, 0x1a/0x1b=control) |
| +0x18 | int | EventParam1 | FUN_00510975 | First parameter |
| +0x1c | int | EventParam2 | FUN_00510975 | Second parameter |
| +0xca | byte[16] | NibbleLo | FUN_00510975 | Low-nibble storage (uVar4 < 0x10) |
| +0xda | byte[16] | NibbleHi | FUN_00510975 | High-nibble or full byte storage |

---



--- Section 173: Pooled Struct Groupings (40 offsets) ---
## Pooled Struct Groupings

### Struct 1: Pit Crew Actor (inferred)

Based on 1 function observation (FUN_004a2a90). Confidence: **high**.

Stride 0x78, allocated as array.

| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| +0x00 | uint16 | DetailLevel | FUN_004a2a90 | detail level |
| +0x03 | byte | LollipopFlag | FUN_004a2a90 | 1 if actor name == "LOLLIPOP" |
| +0x26 | float | PosX | FUN_004a2a90 | POSITION directive x |
| +0x2a | float | PosY | FUN_004a2a90 | POSITION directive y |
| +0x2e | float | PosZ | FUN_004a2a90 | POSITION directive z |
| +0x2c | float[?] | Rotate | FUN_004a2a90 | ROTATE directive, quaternion or euler × _DAT_0059e65c |

**Notes:** Parsed from .mts pit crew model files. Wheel meshes mapped by name (LFWHEELOFF/ON, RFWHEELOFF/ON, LRWHEELOFF/ON, RRWHEELOFF/ON) to indices 0–3.

---

### Struct 2: Pit Order Config (inferred)

Based on 1 function observation (FUN_004d12c0). Confidence: **medium**.

Reads PITORDER section from file. Small config struct for pit crew ordering.

| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| +0x1a8 | int | PitOrderCount | FUN_004d12c0 | number of pit order entries |
| +0x1ac | char** | PitOrderArray | FUN_004d12c0 | array of string pointers, stride 8 per entry |

**Notes:** `ReversePitOrder` config (True/False) reverses the array. Each entry is a pit crew role name string pointer.

---

### Struct 3: Vehicle Struct — Livery/Pit Section (low offsets)

Based on 3 function observations. Confidence: **medium**.

These offsets are in the vehicle struct (0x0000–0x48C0 range) at low addresses.

| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| +0x60 | byte | PitFlag | FUN_004a6e50 | pit state flag |
| +0x61 | byte | PitState | FUN_004a6e50 | 1=entering, 2=in pits, 3=exiting, 4=collision avoid |
| +0x62 | byte | PitEntryTimer | FUN_004a6e50 | pit entry countdown |
| +0xf3 | char* | LiveryName | FUN_004ddad0 | livery name string |
| +0xf5-0xf9 | ptr | TrackLiveryList | FUN_004ddad0 | TrackLivery linked list pointer |
| +0xf6 | ptr | PitCrewLivery | FUN_004ddad0 | pit crew livery pointer |

**Notes:** FUN_004a6e50 pit state offsets at +0x60–+0x62 are distinct from session timer offsets at +0xb0–+0x104. Confidence that +0x60–+0x62, +0xf3–+0xf6 are all in the main vehicle struct.

---

### Struct 4: Vehicle Struct — Session/Pit Timer Section

Based on 2 function observations (FUN_004d2e50, FUN_004d23d0). Confidence: **high**.

Per-vehicle session timing data. Multiple functions access the same offsets consistently.

| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| +0xb0 | int | LapTimeRemaining | FUN_004d2e50, FUN_004d23d0 | consistent across both |
| +0xb4 | int | RaceTimeRemaining | FUN_004d2e50, FUN_004d23d0 | consistent across both |
| +0xb8 | int | PitTimeOffset | FUN_004d2e50, FUN_004d23d0 | pit closure offset |
| +0xc1 | byte | PenaltyFlag | FUN_004d2e50, FUN_004d23d0 | penalty state flag |
| +0xc2 | byte | FormationLapFlag | FUN_004d2e50, FUN_004d23d0 | consistent across both |
| +0xd8 | int | PitWindowOpenTime | FUN_004d2e50, FUN_004d23d0 | consistent across both |
| +0xf4 | byte | FinishState | FUN_004d2e50 | 2=finished (0=running, 1=finished, 2=DNF, 3=DSQ) |
| +0x104 | byte | ProcessedFlag | FUN_004d2e50 | flag: already processed |

**Conflicts:** None — all offsets are consistent across both functions.

**Relationship to existing docs/13:** The existing docs/13 has physics vehicle offsets in range +0x1140–+0x1dc4. These session timer offsets (+0xb0–+0x104) are at a lower address range in what appears to be the same vehicle struct.

**New offsets not in docs/13:** +0xb0, +0xb4, +0xb8, +0xc1, +0xc2, +0xd8, +0xf4, +0x104

---

### Struct 5: Part Repair/Status (maybe sub-struct of vehicle or separate)

Based on 1 function observation (FUN_004a58b0). 
[...3062 chars truncated]

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
0. NEVER modify any files except %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\output\struct_audit\worker_L.md.
1. Process ALL sections. For every offset in each section, run the grep.
2. Flag EVERY conflict — do not silently pick a winner.
3. New offsets: only report if seen in 2+ .c files.
4. Write to disk after each struct section.
