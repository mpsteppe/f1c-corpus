# WORKER K — F1C Struct Confidence Audit

You are auditing struct field definitions in docs/13-struct-offsets.md against
actual Ghidra decompilation source files.
Worker K of 20.

## STEP 1 — LOAD REFERENCES
1. `%USERPROFILE%\Desktop\F1C_ghidra_project\docs\13-struct-offsets.md` — audit target
2. `%USERPROFILE%\Desktop\F1C_ghidra_project\docs\12-globals-reference.md` — named globals
3. `%USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\` — source .c files

## OUTPUT FILE
Write ALL output to: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\output\struct_audit\worker_K.md

## YOUR STRUCT SECTIONS (14)

--- Section 146: CameraStruct (param_1 — camera/projection) (10 offsets) ---
## CameraStruct (param_1 — camera/projection)

Based on FUN_00541b70, FUN_00545670, FUN_0054e190. Confidence: **medium**.

| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| +0x004 | float | NearPlane | FUN_00541b70 | |
| +0x008 | float | FarPlane | FUN_00541b70 | |
| +0x01c | float | FocalX | FUN_00541b70 | |
| +0x020 | float | FocalY | FUN_00541b70 | |
| +0x080 | byte | Flags | FUN_00541b70 | Bit 0x10=mirror |
| +0x11c | float | CameraPosX | FUN_00545670 | |
| +0x120 | float | CameraDistance | FUN_0054e190 | |
| +0x124 | float | CameraPosY | FUN_00545670 | |
| +0x15c | float[16] | ViewMatrix | FUN_00541b70 | 4×4 matrix |
| +0x18c | ptr | CameraObjPtr | FUN_00515ecd | Allocated director camera |

---



--- Section 147: GridCellIterate (grid counter) (1 offsets) ---
## GridCellIterate (grid counter)

Based on FUN_004be340, FUN_004be4e0. Confidence: **medium**.

| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| +0x934 | int | CellCounter / RenderCounter | FUN_004be340, FUN_004be4e0 | Incremented per call |

---



--- Section 148: 11. SceneExtents (inferred — FUN_004bdc10) (4 offsets) ---
## 11. SceneExtents (inferred — FUN_004bdc10)

Scene bounding box extents.

| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| +0x924 | float | MinX | FUN_004bdc10 |  |
| +0x928 | float | ScaleX | FUN_004bdc10 | 1/(maxX-minX) |
| +0x92c | float | MinZ | FUN_004bdc10 |  |
| +0x930 | float | ScaleZ | FUN_004bdc10 | 1/(maxZ-minZ) |



--- Section 149: CollisionContactBufferStruct (3 offsets) ---
## CollisionContactBufferStruct

Contact buffer management.

Based on 2 function observations. Confidence: medium.

| Offset | Type | Field | Observed in | Notes |
|--------|------|-------|-------------|-------|
| +0x00 | int | ElementCount | FUN_004492d0 | Count of elements |
| +0x04 | int | AllocatedCount | FUN_004492d0 | Allocated capacity |
| +0x08 | void* | BufferPtr | FUN_004492d0 | Pointer to first element |

---



--- Section 150: CollisionShapeStruct (0x20 bytes) (9 offsets) ---
## CollisionShapeStruct (0x20 bytes)

From FUN_00448e90, FUN_00492b0. Confidence: medium.

| Offset | Type | Field | Notes |
|--------|------|-------|-------|
| +0x00 | int | Field0 | Zeroed init |
| +0x04 | int | Field1 | Zeroed init |
| +0x08 | int | Field2 | Zeroed init (FUN_00492b0) |
| +0x0c | int | Field3 | Zeroed init (FUN_00492b0) |
| +0x10 | int | Field4 | Zeroed init (FUN_00492b0) |
| +0x14 | int | Field5 | Clear in FUN_00433090 |
| +0x18 | byte | ActiveFlag | Set to 1 |
| +0x19 | byte | BVType | Bounding volume type |
| +0x1a | short | CollisionGroup | 0xffff = none |

---



--- Section 151: PositionDeltaStruct (inferred) (4 offsets) ---
## PositionDeltaStruct (inferred)

Based on 1 function observation (FUN_004faec0). Confidence: high.

3D position tracking with target/reference pointers.

| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| +0x00 | float[3] | CurrentPosition | FUN_004faec0 | x, y, z |
| +0x0c | float[3] | ComputedDelta | FUN_004faec0 | Output delta vector |
| +0x10c (0x43×4) | (ptr) | RefPtr | FUN_004faec0 | Reference position pointer |
| +0x110 (0x44×4) | (ptr) | TargetPtr | FUN_004faec0 | Target position pointer |

---



--- Section 152: Track Database Struct (int-indexed) (5 offsets) ---
## Track Database Struct (int-indexed)

Based on 1 function observation (FUN_00460a10). Confidence: low — single source, int-indexed.

| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| +0x08 | int | expected terrain type | FUN_00460a10 | [2] |
| +0x0c | int | expected surface type hash | FUN_00460a10 | [3] |
| +0x10 | int | expected terrain.ini CRC | FUN_00460a10 | [4] |
| +0x14 | int | expected track name hash | FUN_00460a10 | [5] |
| +0x18 | int | expected full path hash | FUN_00460a10 | [6] |

---



--- Section 153: Credited Functions Index (0 offsets) ---
## Credited Functions Index

All functions in docs/08-file-formats.md that contributed offset observations:

| Function | Section | Observations |
|----------|---------|-------------|
| FUN_004c3200 | .veh File Parser | 26 offsets (vehicle file slots) |
| FUN_004c18b0 | Player Career Stats | 24 offsets (career struct) |
| FUN_004c78f0 | Nationality/Driver Info | 5 offsets (vehicle array access) |
| FUN_004c2a80 | Season Scoring Updater | 4 offsets (vehicle struct) |
| FUN_004c0910 | Season Scoring | 6 offsets (standings struct) + 4 offsets (scoring DB) |
| FUN_004c2420 | Career Stats Writer | 6 offsets (PLAYERTRACKSTAT node) |
| FUN_004c1e80 | Game Options Writer | 24 offsets (same as reader) |
| FUN_004c0db0 | Game Filter Data Loader | 8 offsets (filter state) + 4 offsets (per-vehicle) |
| FUN_004c6c40 | vehgen.scn Loader | 6 offsets (vehicle struct) |
| FUN_004c7b50 | Vehicle Setup Driver Number | 4 offsets (vehicle struct) |
| FUN_004c6a10 | Driver Abbreviation Formatter | 3 offsets (vehicle struct) |
| FUN_004c11e0 | Session Config Reader | 5 offsets (game state) |
| FUN_004c0b70 | Career/Season State Reader | 4 offsets (game state) |
| FUN_004c6320 | Scene File Filter Builder | 2 offsets (scene array + filter list) |
| FUN_004c5e50 | Filter Properties Builder | 5 offsets (filter list state) |
| FUN_004c5cb0 | SceneOrder Slot Finder | 2 offsets (scene struct) |
| FUN_004b0540 | PlayerFileInit | 5 offsets (player file struct) |
| FUN_004b7300 | GameDataFileIO | 5 offsets (game data state) |
| FUN_00432bf0 | AutoLoadEntry Writer | 4 offsets (autoload entry) |
| FUN_00432a70 | Track/Session/Classes Reader | 4 offsets (autoload entry, byte offsets) |
| FUN_00432e70 | AutoLoadEntry List Loader | 9 offsets (list node + head/tail) |
| FUN_004f6300 | Vehicle Setup File Parser | 8 offsets (setup struct) |
| FUN_00460a10 | terrain.ini Parser | 12 offsets (terrain validation + track DB) |
| FUN_004c54f0 | .AIW/.SCN Filename Builder | 1 offset (scene name) |
| FUN_004c5940 | SeasonRaces Scene Sorter | 1 offset (scene array) |
| FUN_004c3d80 | Vehicle File Loader | 2 offsets (vehicle array globals) |
| FUN_0047f440 | Season Database Factory | 2 offsets (season DB struct) |
| FUN_00587ca0 | File Read Until Newline | 2 offsets (file buffer state) |
| FUN_00589898 | Buffered Char Write | 2 offsets (file buffer state) |
| FUN_00587f90 | File Tell/Seek | 3 offsets (file state) |
| FUN_0059c156 | File Seek with Validation | 3 offsets (file state) |
| FUN_0059a3a9 | Stream Creation | 4 offsets (stream struct) |
| FUN_00599081 | Buffered Stream Read | 3 offsets (stream buffer) |
| FUN_005876f0 | Buffered I/O Init | 2 offsets (buffered IO struct) |
| FUN_0058a05a | Buffer Flush/Write | 5 offsets (buffer I/O struct) |
| FUN_00599495 | File Close Wrapper | 1 offset (file handle struct) |
| FUN_005352d0 | File Read Loop | 5 offsets (read state struct) |
| FUN_00566b90 | Conditional File Close | 2 offsets (file handle struct) |
| FUN_00598d6d | OutputStream Write | 2 offsets (stream buffer) |
| FUN_00467430 | String Compare Replace | 3 offsets (string property) |
| FUN_004662c0 | UI State Reset | 2 offsets (UI state struct) |
| FUN_00469880 | UI Dialog Constructor | 5 offsets (UI dialog struct) |
| FUN_004726c0 | UI Options Constructor | 7 offsets (UI options struct) |
| FUN_00473fd0 | UI Options Constructor | 1 offset (UI options global ref) |

---



--- Section 154: Render Args Struct (inferred) (6 offsets) ---
## Render Args Struct (inferred)

Used by FUN_0058a40a, FUN_0058a4e5. Small struct for forwarding
render arguments.

Based on 2 function observations. Confidence: high.

| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| +0x08 | int | arg1 | FUN_0058a40a, FUN_0058a4e5 | First extracted arg |
| +0x0c | int | arg2 | FUN_0058a40a, FUN_0058a4e5 | Second extracted arg |
| +0x10 | int | arg3 | FUN_0058a40a | Third extracted arg |
| +0x14 | int | arg4 | FUN_0058a4e5 | Fourth arg |
| +0x18 | ptr | dispatchFn | FUN_0058a4e5 | Jump-table dispatch function |
| +0x24 | int | stateFlag | FUN_0058a4e5 | Flag checked for early-out |



--- Section 155: CollisionDamageContactStore (inferred — FUN_0045b840) (3 offsets) ---
## CollisionDamageContactStore (inferred — FUN_0045b840)

Based on FUN_0045b840. Confidence: **medium**.

| Offset | Type | Field | Notes |
|--------|------|-------|-------|
| +0x31C | int | ContactCount | Number of active contacts |
| +0x320 | float | ContactEnergy | Per-contact at stride 0x90 |
| +0x3C (per contact) | float[3] | ContactPosition | Contact world position |
| +800 (0x320) | byte | DecayDoneFlag | Flag for decay completion |

**Note:** +0x320 appears to be both ContactEnergy base and DecayDoneFlag (at offset 0x320 which = 800 decimal). Likely different fields in different struct contexts — ContactEnergy is per-contact within the stride, DecayDoneFlag is a single byte at absolute offset 0x320.

---



--- Section 156: CollisionMutexState (inferred — from FUN_0045bf90) (0 offsets) ---
## CollisionMutexState (inferred — from FUN_0045bf90)

Based on FUN_0045bf90. Confidence: **low**.

| Offset | Type | Field | Notes |
|--------|------|-------|-------|
| DAT_007cd264 | HANDLE | MutexHandle | Win32 mutex handle |
| DAT_007cd268 | int | LockState | -1 = unlocked |
| DAT_007cd26C | int | InitFlag | 1 = initialized |

---



--- Section 157: 9. Scene Instance/Node Struct (inferred) (6 offsets) ---
## 9. Scene Instance/Node Struct (inferred)

Based on observations from FUN_0055a910, FUN_004fc2f0. Confidence: low.

| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| +0x3c | int | InstanceFlags | FUN_0055a910 | Bitmask: MOVEABLE(0x1), RENDERdis(0x4), CHANGEdis(0x8), BILLBOARD(0x9), STAMP(0x10) |
| +0x50 | unknown | ClipPlaneData | FUN_0055a910 | Clipping plane data |
| +0x118 | int | NodeCount | FUN_004fc2f0 | Scene node count |
| +0x128 | ptr | NodeList | FUN_004fc2f0 | List of nodes, stride 0x100 |
| +0x13c | int | ShadowRecvCount | FUN_0055a910 | Shadow receiver count |
| +0x174 | int | ReflectorCount | FUN_0055a910 | Reflector count |

**Node flags (+0x14 bitmask):**

| Bit | Field | Observed in |
|-----|-------|-------------|
| 0x6 | COLLTARGET | FUN_0055a910 |
| 0x7 | SPHERETARGET | FUN_0055a910 |
| 0x8 | HATTARGET | FUN_0055a910 |
| 0xd | ZBUFFER_DISABLE | FUN_0055a910 |
| 0xe | SHADOW_RECEIVER | FUN_0055a910 |
| 0x11 | REFLECTOR | FUN_0055a910 |
| 0x15 | MORPH_TARGET | FUN_0055a910 |
| 0x19 | SHADOW_CASTER | FUN_0055a910 |

---



--- Section 158: AllocStruct18 (inferred, 0x18 bytes) (6 offsets) ---
## AllocStruct18 (inferred, 0x18 bytes)

Based on 1 function (FUN_00564810). Confidence: high.

0x18-byte control struct with separate inner data buffer allocation. Used for audio buffer allocation.

| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| +0x00 | int | Zeroed | FUN_00564810 | Always zeroed |
| +0x04 | int | ElementSize | FUN_00564810 | Size per element (default 8) |
| +0x08 | int | Capacity | FUN_00564810 | param_1 = capacity |
| +0x0c | int | Count | FUN_00564810 | Count/capacity |
| +0x10 | int | UserData | FUN_00564810 | param_3 (user data) |
| +0x14 | void* | DataBuffer | FUN_00564810 | Inner data buffer (param_1 * param_2 bytes) |

---



--- Section 159: Source: docs/07-pit-system.md (0 offsets) ---
## Source: docs/07-pit-system.md

Source: docs/07-pit-system.md (23 entries, 25+ offset observations)

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
0. NEVER modify any files except %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\output\struct_audit\worker_K.md.
1. Process ALL sections. For every offset in each section, run the grep.
2. Flag EVERY conflict — do not silently pick a winner.
3. New offsets: only report if seen in 2+ .c files.
4. Write to disk after each struct section.
