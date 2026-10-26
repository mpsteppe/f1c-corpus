# WORKER M — F1C Struct Confidence Audit

You are auditing struct field definitions in docs/13-struct-offsets.md against
actual Ghidra decompilation source files.
Worker M of 20.

## STEP 1 — LOAD REFERENCES
1. `%USERPROFILE%\Desktop\F1C_ghidra_project\docs\13-struct-offsets.md` — audit target
2. `%USERPROFILE%\Desktop\F1C_ghidra_project\docs\12-globals-reference.md` — named globals
3. `%USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\` — source .c files

## OUTPUT FILE
Write ALL output to: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\output\struct_audit\worker_M.md

## YOUR STRUCT SECTIONS (14)

--- Section 174: SessionStruct / SessionTimers (param_1 — session struct) (19 offsets) ---
## SessionStruct / SessionTimers (param_1 — session struct)

Based on FUN_004d0f10 and FUN_00411120, FUN_004a5e10. Confidence: **high**.

| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| +0x14 | int | ActiveFlag | FUN_004a5e60, FUN_004a5e80 | Non-zero = active |
| +0x24 | int | Count1 | FUN_00411120 | Stride 0x24 group 1 |
| +0x30 | int | Count2 | FUN_00411120 | |
| +0x3c | int | Count3 | FUN_00411120 | |
| +0x44 | ptr | ListHead | FUN_0046ae60 | Session entries list |
| +0x48 | int | Count | FUN_0046ae60 | |
| +0x4c | int | Count | FUN_0046ae60 | |
| +0x50 | int | Count | FUN_0046ae60 | |
| +0x54 | int | Count4 | FUN_00411120 | |
| +0x60 | int | Count5 | FUN_00411120 | |
| +0xac | int | BestTime | FUN_004d0f10 | 0x7fffffff = DNF |
| +0xb8 | float | MaxSessionTime | FUN_004d0f10 | 7200.0 (2 hours) |
| +0xbc | float | TimeMultiplier | FUN_004d0f10 | 1.0 |
| +0x128 | int[26] | SectorFlags | FUN_004d0f10 | Initialized to -1 |
| +0x180 | byte | StateFlag / FlagA | FUN_004a5e60, FUN_004a5e80 | |
| +0x184 | int | SessionState / FlagB | FUN_004a5e10, FUN_004a5e60, FUN_004a5e80 | 0=idle, 1=active, 4=finished |
| +0x190 | short | LapCount | FUN_004d0f10 | 0xffff |
| +0x192 | byte | CurrentSector | FUN_004d0f10 | 0xff |
| +0x280 | int[52] | PitWindowHistory | FUN_004d0f10 | Zeroed |

---



--- Section 175: UNUSED / ABSENT OFFSETS (0 offsets) ---
## UNUSED / ABSENT OFFSETS

Offsets +0x1130 and +0x1132 do NOT appear in any 06-session-race-logic function entries.
These are confirmed DirectX false positives in this document.

---

**End of Worker A struct synthesis. Total consolidated: 30 struct definitions from 996 offset observations across 287 struct sections.**

---



--- Section 176: 13. BoolFloatToggle (inferred — FUN_0059d6ff) (2 offsets) ---
## 13. BoolFloatToggle (inferred — FUN_0059d6ff)

Boolean-to-float conversion toggle.

| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| +0x1065 | byte | BoolFlag | FUN_0059d6ff | Toggle |
| +0x3584 | float | FloatParam | FUN_0059d6ff | 0.0 or 1.0 |



--- Section 177: WheelStateArray (stride 0x464, 4 wheels) (3 offsets) ---
## WheelStateArray (stride 0x464, 4 wheels)

Per-wheel state array for suspension/velocity history.

Based on 3+ function observations (FUN_00412f0, FUN_00413e230, FUN_0041ad0). Confidence: medium.

| Offset | Type | Field | Notes |
|--------|------|-------|-------|
| +0x338 | float[0x119] | WheelStates | Per-wheel state array |
| +0x1c5c-0x1c68 | float | SuspHistory | Suspension displacement history (prev/cur pairs) |
| +0x1e38-0x1e44 | float | VelHistory | Wheel velocity history (prev/cur pairs) |
| Stride: 0x464 (4 wheels × 0x119 × 4 = per wheel stride) | | | |

---



--- Section 178: TraversalBoundStruct (5 offsets) ---
## TraversalBoundStruct

From FUN_00443af0. Confidence: low.

| Offset | Type | Field | Notes |
|--------|------|-------|-------|
| +0x1e14 | int | TraversalMode | 1 or 2 |
| +0x3d0 | double | BoundA | First bound |
| +0x834 | double | BoundB | Second bound |
| +0xc98 | double | BoundC | Third bound |
| +0x10fc | double | BoundD | Fourth bound |

---



--- Section 179: SteeringTorqueOutputStruct (inferred) (2 offsets) ---
## SteeringTorqueOutputStruct (inferred)

Based on 1 function observation (FUN_00423ca0). Confidence: medium.

Output struct for steering torque/force computation.

| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| +0x10 (param_1[4]) | float | OrthogonalResult | FUN_00423ca0 | Perpendicular force component |
| +0x18 (param_1[6]) | float | PrimaryResult | FUN_00423ca0 | Signed torque/force output |

---



--- Section 180: Scene Array Entry (stride 0x18c) (1 offsets) ---
## Scene Array Entry (stride 0x18c)

Based on 4 function observations (FUN_004c54f0, FUN_004c5cb0, FUN_004c6330, FUN_004c5940). Confidence: high — stride 0x18c consistently used across scene enumeration functions.

| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| +0x104 | char* | scene name/identifier | FUN_004c54f0, FUN_004c5cb0, FUN_004c6330 | string identifier for scene |

---



--- Section 181: RenderContext (inferred) (31 offsets) ---
## RenderContext (inferred)

Large render device/context struct used by multiple functions including
FUN_005550e0, FUN_0053eb70, FUN_004c71c0, FUN_00554700, FUN_00586700,
FUN_00540f00. Int-indexed access (param_1[N]) common. Controls D3D device,
render states, buffers.

Based on 18+ function observations. Confidence: high.

| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| +0x0000 | int* | vtablePtr | FUN_004c71c0, FUN_005550e0, FUN_0053eb70, FUN_0054ca00 | Virtual method table |
| +0x1100 (0x440) | ptr | deviceVtableObj | FUN_005550e0, FUN_0053eb70, FUN_0053ead0, FUN_00554700, FUN_00586700 | Interface ptr with vtable at *(*this+0x440); used for D3D state calls |
| +0x1398 (0x4e6) | int | valueSlot1 | FUN_00554700 | Property value slot |
| +0x139c (0x4e7) | int | valueSlotIndex | FUN_00554700 | Property index/value slot 2 |
| +0x13e0 (0x4f8) | int | bufferType | FUN_00540f00 | Format/type flag for buffer alloc |
| +0x12a8 (0x4ea) | int | renderStateFlags | FUN_005550e0, FUN_0053eb70 | Bitmask: bit 28 = initialized, bit 8 = fog, bit 9 = debug |
| +0x12b0 (0x4ec) | int | renderLimit | FUN_005550e0 | Max iterations per bucket |
| +0x12c4 (0x4f1) | int | initializedFlag | FUN_005550e0 | 1 = already initialized |
| +0x12c8 (0x4f2) | int | colorValue | FUN_005550e0 | Cached color/int value |
| +0x12cc (0x4f3) | int | currentMaterialID | FUN_005550e0 | Tracks active material/texture |
| +0x12d0 (0x4f4) | int | renderDebugMode | FUN_005550e0 | 0=normal, non-0=debug overlay |
| +0x12d8 (0x4f6) | int | textOverlayMode | FUN_005550e0 | Non-0 enables debug text |
| +0x14f0 (0x53c) | int | extraFlag | FUN_005550e0 | Guard/state flag checked at end of render |
| +0x152c (0x54b) | ptr | textureResource | FUN_0053ead0 | Texture resource ptr |
| +0x1524 (0x549) | ptr | resourceA | FUN_0053ead0 | Freed on cleanup |
| +0x1528 (0x54a) | ptr | resourceB | FUN_0053ead0 | Freed on cleanup |
| +0x152c | ptr | extraTexture | FUN_0053f270, FUN_0053ead0 | Released via FUN_0053f6e0 |
| +0x13a0 | int | renderState | FUN_0053f270 | Set to 1 during cleanup |
| +0x13a8 | int | cleanupFlags | FUN_0053f270 | Bit 28 = needs cleanup |
| +0x1140 | ptr | frontBuffer | FUN_0053f270 | D3D front buffer |
| +0x113c | ptr | backBuffer | FUN_0053f270 | D3D back buffer |
| +0x1144 | ptr | depthStencil | FUN_0053f270 | D3D depth/stencil |
| +0x14f0..0x1504 | int[5] | viewportDims | FUN_0053f270 | Zeroed during cleanup |
| +0x1518 | ptr | textureList | FUN_0053f270 | Linked list of loaded textures |
| +0x1580 | ptr | targetList | FUN_0053f270 | Linked list of render targets |
| +0x704 | float[16] | viewMatrix | FUN_004c71c0 | View transformation 4x4 |
| +0x744 | float[16] | worldMatrix | FUN_004c71c0 | World transformation 4x4 |
| +0x83c | float[3]×4 | wheelPositions | FUN_004c71c0 | 4 wheel positions, stride 0x128 |
| +0x34f8 | float[4] | diffuseColor | FUN_004c71c0 | Diffuse lighting RGBA |
| +0x3510 | float[4] | specularColor | FUN_004c71c0 | Specular lighting RGBA |
| +0x3540 | int | envMapHandle | FUN_004c71c0 | Environment map texture handle |



--- Section 182: Pixel Compositing Struct (inferred) (2 offsets) ---
## Pixel Compositing Struct (inferred)

Used by FUN_00503e36. Holds source and destination image
pointers for compositing/blitting.

Based on 1 function observation. Confidence: low.

| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| +0x00 | ptr | srcPtr | FUN_00503e36 | Source image struct |
| +0x04 | ptr | dstPtr | FUN_00503e36 | Dest image struct (offset via +0x18) |



--- Section 183: CollisionRaycastPlane (inferred — param_1 in FUN_0044ba40) (6 offsets) ---
## CollisionRaycastPlane (inferred — param_1 in FUN_0044ba40)

Based on FUN_0044ba40. Confidence: **medium**.

| Offset | Type | Field | Notes |
|--------|------|-------|-------|
| +0x004 | int | PlaneActive | Guard flag |
| +0x008 | double | OriginX | Plane origin X |
| +0x010 | double | PlaneWidth | Plane width |
| +0x018 | double | OriginY | Plane origin Y |
| +0x020 | double | PlaneHeight | Plane height |
| +0x028 | float[1024] | ResultBuffer | 32×32 raycast results |

---



--- Section 184: CollisionTerrainSurface (inferred — from FUN_0045ca20) (2 offsets) ---
## CollisionTerrainSurface (inferred — from FUN_0045ca20)

Based on FUN_0045ca20. Confidence: **low**.

| Offset | Type | Field | Notes |
|--------|------|-------|-------|
| +0x424 | float[8] | SurfaceDataBlock | 8-dword block per surface entry |
| +0x1124[surfaceIdx] | float | SurfaceCache | Cached surface value |

---



--- Section 185: 11. Player Slot Struct (stride 0x8c) (2 offsets) ---
## 11. Player Slot Struct (stride 0x8c)

Based on observations from FUN_0045eb50, FUN_0045fc50. Confidence: medium.

| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| +0x00 | int | NodeID | FUN_0045eb50 | Network node ID |
| +0x04–0x8b | char[0x87] | PlayerName | FUN_0045eb50 | Player name string |

Note: This is a sub-struct within the NetComm session struct, stride 0x8c per slot, starting at various base offsets (+0x398 for names, +0x3c74 for IDs, +0x3d0 for slot data).

---



--- Section 186: AudioConfigFlagsStruct (inferred) (1 offsets) ---
## AudioConfigFlagsStruct (inferred)

Based on 1 function (FUN_00551480). Confidence: low.

Simple config flags struct.

| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| +0x04 | uint | AudioConfigFlags | FUN_00551480 | Bit 12 set, bits 13-14 cleared |

---



--- Section 187: Summary of new offsets for docs/13 (7 offsets) ---
## Summary of new offsets for docs/13

New offsets discovered (not in existing docs/13 as of 2026-07-15):

| Range | Struct | New Offsets |
|-------|--------|-------------|
| Vehicle struct — session timer | Vehicle | +0xb0, +0xb4, +0xb8, +0xc1, +0xc2, +0xd8, +0xf4, +0x104 |
| Vehicle struct — pit state | Vehicle | +0x60, +0x61, +0x62 |
| Vehicle struct — livery | Vehicle | +0xf3, +0xf5, +0xf6 |
| Vehicle struct — high | Vehicle | +0x3450, +0x48a4, +0x32C8 |
| Pit crew actor | Separate (stride 0x78) | +0x00, +0x03, +0x26, +0x2a, +0x2e, +0x2c |
| Pit order config | Separate | +0x1a8, +0x1ac |
| Part repair (maybe vehicle sub-struct) | TBD | +0x28, +0x36, +0x58, +0x60, +0x6c, +0x76, +0xb6, +0xec, +0xf0, +0xf6, +0x128, +0x12c, +0x136, +0x17c |

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
0. NEVER modify any files except %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\output\struct_audit\worker_M.md.
1. Process ALL sections. For every offset in each section, run the grep.
2. Flag EVERY conflict — do not silently pick a winner.
3. New offsets: only report if seen in 2+ .c files.
4. Write to disk after each struct section.
