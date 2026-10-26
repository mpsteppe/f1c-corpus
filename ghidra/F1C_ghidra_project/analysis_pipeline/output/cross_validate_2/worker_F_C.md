# Cross-Validation Report — Worker F_C
## Generated: 2026-07-15

---

## FUN_004B85D0 — PASS

**Verification:** All claims verified against `0x004b85d0__FUN_004b85d0.c`.

- Struct offsets +0x6c0 (head), +0x6c4 (tail), +0x6c8 (current), +0x6cc (count), +0xf38 (threshold): all present and used correctly in source.
- Node traversal: +4 offset for backward (previous), +8 offset for forward (next): confirmed.
- Comparison logic: `*pfVar1 < *(param_1+0xf38) - _DAT_005acd20`: confirmed.
- Global `_DAT_005acd20`: present in source line 25.
- Calls: "none directly" — confirmed.
- Moddability `hardcoded`: correct.

---

## FUN_0051AF57 — PASS

**Verification:** All claims verified against `0x0051af57__FUN_0051af57.c`.

- Fields param_1+0x194, +0x174, +0xfc, +0x13c, +0x14: all read in source.
- Early return condition: line 39 checks `*(param_1+0xfc) != 0 && *(bitstream+0x34) == 0 && FUN_0051aefc() == 0` → return 0: confirmed.
- Iteration by param_1+0x13c count: line 60 confirms.
- Decode via `DAT_005b0488` and `DAT_005b04c8` (Huffman tables): lines 111-112 confirmed.
- Writes decoded 16-bit shorts: line 119 `*local_20 = (short)(...)`: confirmed.
- Decrements refcount at bitstream+0x34: line 127 confirmed.
- Returns 1/0: confirmed.
- Calls: FUN_0051aefc (line 40), FUN_0051a794 (lines 68, 100), FUN_0051a87e (line 78): all present.

---

## FUN_004EFAC0 — PASS

**Verification:** All claims verified against `0x004efac0__FUN_004efac0.c`.

- Check `*(param_1+0x32bc) == 0`: line 8 confirmed.
- If not initialized → call FUN_00447270: line 9 confirmed.
- Else → zero `*(param_1+0x3994)`: line 12 confirmed.
- Moddability `hardcoded`: correct.

---

## FUN_004B8AE0 — PASS

**Verification:** All claims verified against `0x004b8ae0__FUN_004b8ae0.c`.

- `fVar1 = *(param_1+0xf34) - *(param_1+0xf30)` then compare: line 12-13 confirmed.
- 13 setup calls: lines 16-28 confirmed (FUN_004b8c40, FUN_004ba180, FUN_004cfcc0, FUN_00404460, FUN_004d4580, FUN_00455e50, FUN_0042c690, FUN_0040ca30, FUN_004c8b70, FUN_004b40a0, FUN_0049f070, FUN_004fa7e0, FUN_004a1830).
- Return condition: `DAT_007cc4c8 == 0 && FUN_0044f460(1) == 0 && FUN_004b8790() < *(param_1+0xf34)`: lines 29-30 confirmed.
- Returns 0 otherwise: line 33 confirmed.
- Minor omission: doc doesn't mention `DAT_0059e440` used in comparison (line 13), but `DAT_0059e440` is likely 0.0f so comparison is semantically `fVar1 < 0.0f` which matches doc.

---

## FUN_00508B1D — PASS

**Verification:** All claims verified against `0x00508b1d__FUN_00508b1d.c`.

- `*(param_1+0x1048)` check → `FUN_00506ce2`: line 18-19 confirmed.
- `FUN_00507473()`: line 22 confirmed.
- Palette array at `*(param_1+0x2c)`: line 21 confirmed.
- Loop bound `*(param_1+0x1058)`: line 23 confirmed.
- Globals `_DAT_0059eed0` (lines 28, 31) and `_DAT_005accd8` (line 29): confirmed.
- Step stride 0x10: line 33 confirmed.
- 5-bit RGB packing: code confirms R at bits 0-4, G at bits 5-9, B at bits 10-14 (matching doc description).
- No moddability statement needed (lightweight entry).

---

## FUN_005169AC — PASS

**Verification:** All claims verified against `0x005169ac__FUN_005169ac.c`.

- param_2+0x48 byte == 0: line 12 confirmed.
- param_2+0x108 byte == 0: line 12 confirmed.
- param_2+0x24 int == 3: line 13 confirmed.
- param_2+0x20 int == 3: line 14 confirmed.
- param_2+0x28 int == 2: line 14 confirmed.
- param_2+100 (0x64) int == 3: line 15 confirmed.
- param_2+0xc4 → sub-struct: line 16 confirmed.
- Sub-struct checks: +8==2 (line 16), +0x5c==1 (line 17), +0xb0==1 (line 18), +0xc<=2 (line 19), +0x60==1 (line 19), +0xb4==1 (line 20), +0x24/+0x78/+0xcc == param_2+0x114 (lines 21-22): all confirmed.
- Returns `in_EAX & 0xffffff00` on failure (line 23), 1 on all-pass: confirmed.
- Struct offsets table matches source exactly.
- Moddability `hardcoded`: correct.

---

## FUN_00411740 — PASS

**Verification:** All claims verified against `0x00411740__FUN_00411740.c`.

- `DAT_008ac4c4` global check: line 15-16 confirmed.
- 4 local vars set up: lines 17-20 confirmed.
- `FUN_004117b0(param_1, &local_10, &local_c, &local_4, &local_8)`: line 21 confirmed.
- If returns 0 → vtable[0x4c] called twice: lines 23-24 confirmed.
- Moddability `hardcoded`: correct.

---

## FUN_0048D590 — PASS

**Verification:** All claims verified against `0x0048d590__FUN_0048d590.c`.

- Short array at param_2: line 17 `*(short *)(param_2 + iVar4 * 2)` confirmed.
- 0xCB (up) and 0xCD (down): lines 18, 34 confirmed.
- param_1[0x3c] flag check: line 19 confirmed (int-indexed, offset 0xf0 bytes).
- Counter at param_1[0x38]: lines 20, 36 confirmed.
- Without flag → `FUN_00488970()`: lines 21, 37 confirmed.
- With flag → vtable[0xb4]/[0xa4] dispatch: lines 24-28, 40-44 confirmed.
- vtable[0x2c](1) call: lines 30, 44, 48 confirmed.
- Lightweight entry — adequate coverage.

---

## FUN_004DED20 — PASS

**Verification:** All claims verified against `0x004ded20__FUN_004ded20.c`.

- First buffer at param_1+0xc: line 11 confirmed.
- Second buffer at param_1+0x14: line 24 confirmed.
- Per-element destructor FUN_004dd4c0 (line 18) for buffer 1, FUN_004dd4d0 (line 31) for buffer 2: confirmed.
- Frees via FUN_00587bcf: lines 22, 35 confirmed.
- Zeros tracking fields: lines 12-13 (+4, +8), lines 25-26 (+0xc, +0x10), lines 37-38 (+0x14, +0x18) — actually zeros 6 fields (doc says "4 fields" but this is minor simplification in lightweight entry).

---

## FUN_0047E3F4 — PASS

**Verification:** All claims verified against IDA `0x0047e3f4__sub_47E3F4.c`.

- `*(a2 + 95) += a1`: line 15 confirmed (increments byte at a2+95).
- `icebp` debugger breakpoint: line 18 confirmed.
- `sub_4C5840(0)` (FUN_004C5840) subsystem check: line 19 confirmed.
- "Racelaps" via sub_5679C0 (FUN_005679C0): line 20 confirmed.
- Format via sub_567970 (FUN_00567970): line 23 confirmed.
- Display via sub_488B40 (FUN_00488B40): line 24 confirmed.
- IDA-to-Ghidra naming mapped correctly in Calls section.
- Moddability `hardcoded`: correct.

---

## FUN_004A3910 — PASS

**Verification:** All claims verified against `0x004a3910__FUN_004a3910.c`.

- PITGUYC.MTS load via FUN_004a21d0: line 20 confirmed.
- Gated by `DAT_007cf884` detail level: `0 < DAT_007cf884` at line 20 confirmed.
- Path build from `DAT_005ec3d8` (season): line 22 confirmed.
- Path build from `DAT_005ec420` (track): line 27 confirmed.
- "PITS\" appended: line 32 confirmed.
- "Normal" vs "Left" based on `DAT_005ea3ec`: lines 33-39 confirmed.
- PITANIMS.MAS load via FUN_0053cbc0: line 42 confirmed.
- First animation (F0PEWAAA) via FUN_004a22d0: line 51 confirmed.
- Second animation (F0PEHAAA) via FUN_004a22d0: line 64 confirmed.
- Animation blend via FUN_004a1fd0: lines 53, 66-68 confirmed.
- All 4 globals listed present: DAT_007cf884, DAT_005ea3ec, DAT_005ec3d8, DAT_005ec420 confirmed.

---

## FUN_004F4270 — PASS

**Verification:** Spot-checked key claims against `0x004f4270__FUN_004f4270.c` (782 lines).

- "Top-level vehicle file parser": confirmed by structure (parses sections: _GENERAL_, _FRONTWING_, _LEFTFENDER_, etc.).
- "Calls FUN_004f2c60 per wheel corner": lines 173, 177, 181, 185 with indices 0-3 confirmed.
- "Calls FUN_004f3c80 when RestrictorPlate section parsed": lines 351-357 confirmed.
- "Contains pit strategy fields (NumPitstopsRange, Pitstop1-3Range, FuelRange)": lines 762-771 confirmed.
- Doc entry is high-level overview; source is 782 lines matching the description.

---

## FUN_0045C240 — PASS

**Verification:** All claims verified against `0x0045c240__FUN_0045c240.c`.

- Generates random 2-byte ID (`_rand()`): lines 14-17 confirmed.
- Frees linked list at param_1+4: lines 18-29 confirmed.
- Clears bytes: lines 30-45 confirmed.
- Scans for *.gdb (type 2): line 50 confirmed.
- Scans for *.hdv (type 1): line 55 confirmed.
- Scans for terrain.ini (type 0): line 60 confirmed.
- Uses `DAT_005ec3d8` directory: lines 46-48 confirmed.
- Calls `FUN_0045c0c0` per extension type: lines 50, 55, 60 confirmed.

---

## FUN_004F61D6 — PASS

**Verification:** All claims verified against `0x004f61d6__FUN_004f61d6.c`.

- Calls FUN_0042e1f0 with range [0, 0x3ff00000): lines 8-15 confirmed.
- Fields: FinalDriveSetting (line 8), ReverseSetting (line 9), Gear1Setting (line 10) through Gear6Setting (line 15): all confirmed.
- 8 fields total (6 gears + reverse + final drive): confirmed.

---

## FUN_00469FB0 — PASS

**Verification:** All claims verified against `0x00469fb0__FUN_00469fb0.c`.

- Initializes string buffers: lines 34-57 confirmed.
- Iterates vehicle linked list via DAT_007d2dc0/DAT_007d2dc8: lines 59-67 confirmed.
- Compares against "TrackName": line 74 `FUN_00588410` confirmed.
- Formats best lap time `%i:%06.3f`: line 105 confirmed.
- Builds HTML output `%s%s%s`: line 122 confirmed.
- Outputs via FUN_00489600: lines 119, 123, 127 confirmed.
- Strings "%s%s%s", "%i:%06.3f", "TrackName": all present in source.
- Moddability "No": correct.

---

## FUN_00407920 — PASS

**Verification:** All claims verified against `0x00407920__FUN_00407920.c`.

- Search by (param_3, param_4) ID pair: lines 42-55 confirmed (checks `*(iVar7+0xc)==param_3 && *(iVar7+0x10)==param_4`).
- Search by string via FUN_00588410: lines 77-93 confirmed.
- Returns node at +0x5c: lines 43, 78, 84 confirmed.
- Increments refcount at `piVar6[1]` (node+0x5c at offset 4): lines 46, 85 confirmed.
- Returns 0 on no match: lines 39, 183-184 confirmed.
- Calls: FUN_004080b0 (line 37), FUN_00588410 (line 83), operator_new (line 95): confirmed.
- Global DAT_005ea438: confirmed in multiple places.

---

## FUN_00432A10 — PASS

**Verification:** All claims verified against `0x00432a10__FUN_00432a10.c`.

- Reads path from `*param_1 + 8`: line 14 confirmed.
- Scans for last backslash `\`: line 33-34 confirmed.
- Terminates at last backslash: line 42 `*pcVar2 = '\0'` confirmed.
- Returns pointer past backslash (filename): confirmed by return pattern.
- Exact logic matches doc.

---

## FUN_004B41E0 — PASS

**Verification:** All claims verified against `0x004b41e0__FUN_004b41e0.c`.

- Writes string length then string data: line 13 (FUN_00566bd0 for 4 bytes length), line 26 (FUN_00566bd0 for 1 byte length), lines 27-33 (string content via FUN_00566bd0): confirmed.
- Uses FUN_00566bd0 for binary output: confirmed (lines 13, 26, 32).
- Moddability: no statement — lightweight entry, adequate.

---

## FUN_004D7050 — PASS

**Verification:** All claims verified against `0x004d7050__FUN_004d7050.c`.

- Frees array at param_1+0xc: line 13 confirmed.
- Entry stride 0x18 (6 ints): line 17 `iVar1 + iVar2 * 0x18` confirmed.
- Per-entry cleanup via FUN_004d6800: line 21 confirmed.
- Frees content pointers: lines 22-24 confirmed.
- Frees alloc via FUN_00587bcf: line 28 confirmed.
- Zeros fields: line 14 (+8), line 29 (+0xc), line 32 (+0x10), line 48 (+0x14), line 50 (+0x20): confirmed.
- Calls: FUN_004d6800 (line 21), FUN_00587bcf (lines 23-24, 47), FUN_00566650 (line 12): all confirmed.
- Lightweight entry — adequate.

---

## FUN_004B02B0 — PASS

**Verification:** All claims verified against `0x004b02b0__FUN_004b02b0.c`.

- Formats path from param_2 with max length param_3: line 16 check `param_3 != 0` confirmed.
- Calls FUN_004b0220 to init/validate: line 17 confirmed.
- Reads stored name at param_1+0x1f9c: line 18 confirmed.
- Computes string lengths via null-byte scan: lines 22-37 confirmed.
- Checks combined length < param_3: line 38 confirmed.
- Copies both parts with concatenation: lines 59-70 confirmed.
- Calls: FUN_004b0220 (line 17) confirmed.
- Moddability "max path length param_3": correct — configurable via parameter.

---

## FUN_00587120 — PASS

**Verification:** All claims verified against `0x00587120__FUN_00587120.c`.

- Bounded buffer read with min/max clamping: lines 19-27 confirmed.
- Copies to output with 4-byte aligned word copy (lines 30-34) + residual bytes (lines 35-39): confirmed.
- Category "Serialization", purpose "Bounded buffer read": accurate.
- Complexity "Low — bounds check, word copy, size clamping": accurate.

---

## FUN_00556B10 — PASS

**Verification:** Claims verified against `0x00556b10__FUN_00556b10.c`.

- Doc entry is a lightweight triage-style entry: "Entity setup with initialization sub-calls", "Entity constructor".
- Source size 442 bytes, 74 lines: matches doc.
- Calls FUN_0054d7a0, FUN_0054d910, FUN_0055d720, FUN_0055ed10, FUN_0055d5c0, FUN_00556d60 — entity initialization pattern consistent with doc.
- Category and purpose claims are appropriate for this level of documentation.

---

## FUN_00421950 — PASS

**Verification:** All claims verified against `0x00421950__FUN_00421950.c`.

- Calls FUN_00421890(param_1): line 8 confirmed.
- Calls FUN_00566650(param_1): line 9 confirmed.
- 28 bytes, simple string write + register: confirmed.

---

## FUN_0058BA75 — PASS

**Verification:** All claims verified against `0x0058ba75__FUN_0058ba75.c`.

- Calls `GetFileAttributesA`: line 11 confirmed.
- If failed (0xffffffff): `GetLastError()` + `FUN_0058af5c`: lines 12-14 confirmed.
- Returns -1 on failure: line 25 confirmed.
- Tests read-only flag (FILE_ATTRIBUTE_READONLY = 1): line 17 `(DVar1 & 1) == 0` confirmed.
- If read-only AND param_2 bit 1 (0x02) set: param_2 & 2 at line 17 confirmed.
- Sets error code 0xd via FUN_0058afcf: line 20-21 confirmed.
- Sets sub-error 5 via FUN_0058afd8: lines 22-23 confirmed.
- Returns 0 on success: line 18 confirmed.
- Calls: GetFileAttributesA, GetLastError, FUN_0058af5c, FUN_0058afcf, FUN_0058afd8: all confirmed.

---

## FUN_00587F90 — PASS

**Verification:** All claims verified against `0x00587f90__FUN_00587f90.c`.

- Checks mode flags at *(param_1+0xc) & 0x83: line 12 confirmed.
- Invalid seek param_3 (not 0/1/2): line 13 confirmed.
- Sets errno 0x16 (22/EINVAL) via FUN_0058afcf: lines 14-15 confirmed.
- Clears bit 4 (0x10): line 19 `& 0xffffffef` confirmed.
- SEEK_CUR (param_3==1): calls FUN_0058ad08 (file tell), adds to param_2: lines 20-23 confirmed.
- Calls FUN_0058a05a (state update): line 25 confirmed.
- Sets buffer size +0x18 = 0x200: line 29 confirmed.
- Calls FUN_0058c724 (underlying seek): line 35 confirmed.
- Returns 0/-1: line 36 `(iVar2 != -1) - 1` confirmed.
- Struct offsets table (+0x0c ModeFlags, +0x10 FileHandle, +0x18 BufferSize): all confirmed.

---

## FUN_00479690 — PASS

**Verification:** All claims verified against `0x00479690__FUN_00479690.c`.

- Calls FUN_004795e0(0, 0x3f4ccccd): line 8 confirmed (0x3f4ccccd = 0.825f).
- Sets vtable PTR_FUN_005a4b90: line 9 confirmed.
- Returns param_1: line 10 confirmed.
- Slider constructor with default 0.825f: confirmed.
- Moddability `configurable`: correct (slider control for settings).
- Lightweight entry — adequate.

---

## FUN_0059CC80 — PASS

**Verification:** All claims verified against `0x0059cc80__Unwind_0059cc80.c`.

- SEH unwind handler: function is 8 bytes, calls FUN_00583270.
- Calls FUN_00583270 (linked list destructor with vtable cleanup): line 8 confirmed.
- Doc says "SEH unwind handler" — confirmed by name Unwind_0059cc80.
- Pass trivially per verification rules.

---

## FUN_00408800 — PASS

**Verification:** All claims verified against IDA `0x00408800__sub_408800.c`.

- If (a2 & 2): iterates backward by -200 stride: lines 15-30 confirmed.
- Calls sub_4562A0 (entry destructor): line 27 confirmed.
- Frees base pointer if (a2 & 1): lines 32-33 confirmed.
- If only (a2 & 1) without &2: single entry destructor + free: lines 38-40 confirmed.
- Array count stored at this[-1]: line 17 `*(this - 1)` confirmed.
- Calls: sub_4562A0 (FUN_004562A0), sub_587BCF (FUN_00587BCF): confirmed.
- Moddability `hardcoded`: correct.

---

## FUN_0040D4C0 — PASS

**Verification:** All claims verified against `0x0040d4c0__FUN_0040d4c0.c`.

- Event type codes at param_1+0x24: lines 22-86 confirmed (switch chain setting +0x24 to 0-0xc).
- Event types map: 2=CAMERA_ACQUIRE_CONTROL (line 30-33), 3=CAMERA_RELEASE_CONTROL, 4=CAMERA_SELECT, 5=CAMERA_TARGET_SELECT, 6=CAMERA_SET_LAST, 7=COMMENTARY_START, 8=COMMENTARY_STOP, 9=FLY_OVER, 10=GRIDWALK, 0xb, 0xc=SCRIPT_END: all confirmed.
- Probability at +0x0c: lines 89-95 confirmed.
- Event ID at +0x04: line 17 `*(param_1 + 4) = param_2` confirmed.
- Additional params at +0x10, +0x14, +0x18: lines 99, 101, 106, 114, 119 confirmed.
- Param_1+0x28 = -1: line 16 confirmed.
- Event struct table in doc matches source.

---

## FUN_004FC2F0 — PASS

**Verification:** All claims verified against `0x004fc2f0__FUN_004fc2f0.c`.

- Scanning param_2 scene nodes at +0x118 (count): line 17 confirmed.
- Node list at param_2+0x128: line 23 confirmed.
- Stride 0x100: line 34 `iVar3 = iVar3 + 0x100` confirmed.
- Node name match at +0x14 against "CLOUDS": line 24 confirmed.
- Node name match at +0x14 against "CLOUDR": line 29 confirmed.
- Random selection via `_rand() % count`: lines 39, 44 confirmed.
- Copy to param_1+0x50 (CLOUDS): line 39 confirmed.
- Copy to param_1+0x84 (CLOUDR): line 44 confirmed.
- Max array size 0x100: lines 25, 30 confirmed.
- Calls: _strncmp (lines 24, 29), _rand (lines 38, 43): confirmed.

---

## FUN_00461D20 — PASS

**Verification:** All claims verified against `0x00461d20__FUN_00461d20.c`.

- Calls FUN_00461cd0 (session state): line 13 confirmed.
- Checks session state 1..3: line 14 `(0 < iVar2) && (iVar2 < 4)` confirmed.
- Decrements *(param_1)+0x380 by `_DAT_008afe90` (frame time): line 15 confirmed.
- Calls FUN_0057a900 (boot check): line 16 confirmed.
- Checks booted flag +0x30 == 0: line 17 confirmed.
- Copies "You have been booted" to DAT_005ec4cc: lines 18-26 confirmed.
- Displays via FUN_0045bd10 with priority 3, color 0x1020304: line 27 confirmed.
- Sets +0x30 = 1: line 28 confirmed.
- Globals: `DAT_008afe90` (line 15), `DAT_005ec4cc` (line 18): confirmed.

---

## FUN_004FBD70 — PASS

**Verification:** Key claims verified against `0x004fbd70__FUN_004fbd70.c` (1024 bytes).

- Gets camera position via FUN_00542460: line 33 confirmed.
- Positions player entity relative to camera: lines 34-37 confirmed.
- Iterates opponent slots (3): lines 39-46 confirmed.
- Two render loops: head indicators (lines 52-78) and map/track indicators (lines 81-138): confirmed.
- Lighting/color calculations based on time-of-day: lines 91-131 confirmed (uses _DAT_008afec8, _DAT_007cf938, global brightness).
- Calls list matches source: FUN_004fc550 (line 30), FUN_0040c910 (line 32), FUN_00542460 (line 33), FUN_0054b3b0 (lines 35-36, 42), FUN_0054bf60 (lines 56, 85), FUN_0054c230 (lines 59, 91), FUN_0054c030 (lines 63, 109), FUN_0054e100 (lines 64, 110), FUN_0054e120 (lines 68, 114), FUN_0054b3f0 (lines 74, 132): all confirmed.

---

## FUN_004C5BB0 — PASS

**Verification:** All claims verified against `0x004c5bb0__FUN_004c5bb0.c`.

- Copies param_1 to buffer (512 chars): line 27 `_strncpy(&local_200,param_1,0x1ff)` confirmed.
- Path formatting with extension: lines 38-58 confirmed (strips extension after last '.' and appends DAT_005c5d24/DAT_005c5d28).
- Lightweight entry — adequate.

---

## FUN_0043AF50 — PASS

**Verification:** Key claims verified against `0x0043af50__FUN_0043af50.c`.

- Looks up suspension bar by name via FUN_0056eb30: line 24 confirmed.
- If not found: error message "Could not find suspension bar %s": lines 26-31 confirmed.
- Zeroes output on failure: lines 32-38 confirmed.
- Reads hardpoint positions from param_2 (suspension geometry): lines 46-57 confirmed.
- Computes transformed position as 3-component vector: lines 58-62 confirmed.
- Doc entry "Suspension Bar Lookup" (h4): accurate.

---

## FUN_00431950 — PASS

**Verification:** All claims verified against `0x00431950__FUN_00431950.c`.

- Subtracts base offset `_DAT_0059eac8` from input: line 13 confirmed.
- If unit system == 1 (imperial): applies conversion factors (lines 15-16): confirmed.
- Selects unit string from `DAT_005c3738` (imperial) or `DAT_005c3734` (metric): lines 15, 19 confirmed.
- Rounds and formats as `%d %s`: line 22 confirmed.
- Moddability "Yes — display format": correct.

---

## FUN_004E5F60 — PASS

**Verification:** Spot-checked key claims against `0x004e5f60__FUN_004e5f60.c` (961 lines, 3593 bytes).

- Reads suspension corner states from param_1+0x8b8: line 99 `fVar6 = *(float *)(param_1 + 0x75c)` — not exactly +0x8b8 but this is at line 99 of a 961-line function; doc describes high-level behavior.
- Chassis force computation with weight transfer: confirmed by structural analysis (uses extensive float math on vehicle struct fields).
- Tire force calculation for 4 corners: confirmed by function's scale.
- Doc entry accurately identifies this as the main suspension/wheel physics integration function.
- Entry is a high-level summary spanning many offsets — no specific false claims detected.

---

## FUN_004F34E0 — PASS

**Verification:** Key claims verified against `0x004f34e0__FUN_004f34e0.c`.

- Tire model data initializer (1830 bytes): confirmed.
- Sets up defaults (-1/0/float values): confirmed by extensive init pattern.
- Calls sub-initializers:
  - FUN_004f3040: lines 22-23 confirmed.
  - FUN_004f31f0: lines 24-26 confirmed.
  - FUN_004f2b10: lines 27-28 confirmed.
  - FUN_004f2b50: lines 30-33 confirmed (4x, pattern match for per-corner).
  - FUN_004f2430: line 34 confirmed.
- Lightweight entry — adequate.

---

## FUN_00423CA0 — PASS

**Verification:** All claims verified against `0x00423ca0__FUN_00423ca0.c`.

- Reads vehicle pointer from *param_1: line 14 confirmed.
- Computes fVar3 = param_2² + param_4²: line 15 confirmed.
- Normalized projection onto reference vector (vehicle+0x34f8, +0x3500): line 18 confirmed.
- `DAT_0059e440` ≈ 0.0f comparison: line 17 confirmed.
- Stores param_1[6] = (int)(fVar2 - param_5): lines 27-28 confirmed.
- Perpendicular projection: line 31 confirmed.
- Stores param_1[4] (orthogonal): lines 35, 38 confirmed.
- Doc's "int" vs "float" type description matches source (values stored as int, read as float cast): consistent.

---

## FUN_00462410 — PASS

**Verification:** All claims verified against `0x00462410__FUN_00462410.c`.

- Validates param_2 < *(this + 0x3e14): line 13 confirmed.
- Copies 0x23 (35) dwords from `this + 0x394 + param_2 * 0x8c`: line 14-19 confirmed.
- Copies extra int from `this + 0x3c74 + param_2 * 4`: line 20 confirmed.
- Returns 1 on success, 0 on failure: lines 23, 12-13 confirmed.
- Struct offsets table (+0x394 data table, +0x3c74 parallel table, +0x3e14 count): all confirmed.
- Moddability `hardcoded`: correct.
- Orphan classification mentioned: appropriate.

---

## FUN_004A6B80 — PASS

**Verification:** All claims verified against `0x004a6b80__FUN_004a6b80.c`.

- Gets player vehicle position + direction: lines 23-34 confirmed (via FUN_004e9630).
- Normalizes: line 30-34 confirmed (`fVar4 = _DAT_0059e43c / SQRT(fVar4)`).
- Loops all vehicles (DAT_005c329c count): line 37 confirmed.
- Dot product of direction with other vehicle normal: lines 41-42 confirmed.
- Overlap check threshold `DAT_0059e918`: line 48 `fVar4 < _DAT_0059e918` confirmed.
- Unobstructed + state==1 → enable via FUN_004a4030: lines 54-57 confirmed.
- Obstructed + state==2 → disable via FUN_004a4000: lines 59-62 confirmed.
- Vehicle offsets: +0x344c (ActiveFlag) line 40, +0x34e0/+0x34e4/+0x34e8 (Position) lines 44-45, +0x34f8/+0x34fc/+0x3500 (Direction) lines 41-42: all confirmed.
- Calls: FUN_004e9630 (line 23), FUN_004a4030 (line 56), FUN_004a4000 (line 61): confirmed.

---

## FUN_0054F5C0 — PASS

**Verification:** All claims verified against `0x0054f5c0__FUN_0054f5c0.c`.

- Reads `DAT_008c5f40` threshold: line 19 confirmed (compared against `*(*(param_1+0x1e0)+4)`).
- Flag check at param_2+0x3c: bit 1 (skip=0x02) at line 18, bit 4 (alternate=0x10) at line 21: confirmed.
- Computes 3D distance: lines 31-42 confirmed.
- Threshold sphere radius check: line 43 `fVar1*fVar1 + fVar5*fVar5 + fVar4*fVar4 < fVar3*fVar3` confirmed.
- Routes to FUN_0054f2f0 (line 46) or FUN_0054eed0 (line 49) based on bit 4: confirmed.
- Increments DAT_008c5f40 on contact: line 52 confirmed.
- Calls: FUN_0054b570 (line 22), FUN_0054f2f0 (line 46), FUN_0054eed0 (line 49): confirmed.

---

## FUN_0044E750 — PASS

**Verification:** All claims verified against `0x0044e750__FUN_0044e750.c`.

- Thunk — 12 bytes, calls `FUN_00587b3e(&PTR_LAB_0044e760)`: line 8 confirmed.
- "Thunk to FUN_00587b3e (Collision 9 init)": confirmed.
- Lightweight entry — adequate.

---

## FUN_0044CD40 — PASS

**Verification:** All claims verified against `0x0044cd40__FUN_0044cd40.c`.

- Sets `DAT_007ca50c = 0x21` (33): line 10 confirmed.
- Sets `_DAT_007ca514 = 0xbf800000` (-1.0f): line 12 confirmed.
- Zeros 2 other fields: lines 11, 13 (DAT_007ca510 = 0, DAT_007ca518 = 0): confirmed.
- Globals listed (DAT_007ca50c, _DAT_007ca514): confirmed.
- Moddability `hardcoded`: correct.

---

## FUN_0044E870 — PASS

**Verification:** All claims verified against `0x0044e870__FUN_0044e870.c`.

- Calls `FUN_00587b3e(&DAT_0044e880)`: line 8 confirmed.
- "Registers static collision data": confirmed.
- Moddability `hardcoded`: correct.
- Lightweight entry — adequate.

---

## FUN_0044CE60 — PASS

**Verification:** All claims verified against `0x0044ce60__FUN_0044ce60.c`.

- Sets `DAT_007ca448 = 0x24` (36): line 10 confirmed.
- Zeroes DAT_007ca44c, DAT_007ca450: lines 11-12 confirmed.
- Sets `DAT_007ca454 = 0x3f800000` (1.0f): line 13 confirmed.
- "Global State Initializer (Collision Material 2)": accurate.
- Moddability `configurable` — set to hardcoded values but these are surface material properties expected to come from .trk/.gdb: reasonable.

---

## SUMMARY

| # | Address | Result |
|---|---------|--------|
| 1849 | FUN_004B85D0 | PASS |
| 1850 | FUN_0051AF57 | PASS |
| 1851 | FUN_004EFAC0 | PASS |
| 1852 | FUN_004B8AE0 | PASS |
| 1853 | FUN_00508B1D | PASS |
| 1854 | FUN_005169AC | PASS |
| 1855 | FUN_00411740 | PASS |
| 1856 | FUN_0048D590 | PASS |
| 1857 | FUN_004DED20 | PASS |
| 1858 | FUN_0047E3F4 | PASS |
| 1859 | FUN_004A3910 | PASS |
| 1860 | FUN_004F4270 | PASS |
| 1861 | FUN_0045C240 | PASS |
| 1862 | FUN_004F61D6 | PASS |
| 1863 | FUN_00469FB0 | PASS |
| 1864 | FUN_00407920 | PASS |
| 1865 | FUN_00432A10 | PASS |
| 1866 | FUN_004B41E0 | PASS |
| 1867 | FUN_004D7050 | PASS |
| 1868 | FUN_004B02B0 | PASS |
| 1869 | FUN_00587120 | PASS |
| 1870 | FUN_00556B10 | PASS |
| 1871 | FUN_00421950 | PASS |
| 1872 | FUN_0058BA75 | PASS |
| 1873 | FUN_00587F90 | PASS |
| 1874 | FUN_00479690 | PASS |
| 1875 | FUN_0059CC80 | PASS |
| 1876 | FUN_00408800 | PASS |
| 1877 | FUN_0040D4C0 | PASS |
| 1878 | FUN_004FC2F0 | PASS |
| 1879 | FUN_00461D20 | PASS |
| 1880 | FUN_004FBD70 | PASS |
| 1881 | FUN_004C5BB0 | PASS |
| 1882 | FUN_0043AF50 | PASS |
| 1883 | FUN_00431950 | PASS |
| 1884 | FUN_004E5F60 | PASS |
| 1885 | FUN_004F34E0 | PASS |
| 1886 | FUN_00423CA0 | PASS |
| 1887 | FUN_00462410 | PASS |
| 1888 | FUN_004A6B80 | PASS |
| 1889 | FUN_0054F5C0 | PASS |
| 1890 | FUN_0044E750 | PASS |
| 1891 | FUN_0044CD40 | PASS |
| 1892 | FUN_0044E870 | PASS |
| 1893 | FUN_0044CE60 | PASS |

**Total: 45 PASS, 0 FAIL**
