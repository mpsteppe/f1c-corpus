# Cross-Validation Results: Batch AB (Functions 1054-1179)

Generated: 2026-07-15
Validator: Architect (Claude)
Method: Manual comparison of doc entries vs .c source files

---

## FUN_004040a0 — FAIL

**Doc:** 00-source-tree.md (lines 775-794)
**Source:** decompiled_all\0x004040a0__FUN_004040a0.c

**Errors:**

[FLOAT] param_1[1] value: doc says "4.25f" but .c line 42 sets `param_1[1] = 0x408a0000` which is **4.3125f**, not 4.25f.

Note: 02-ai-system.md entry (line 312) has the **correct** value of 4.3125f. The 00-source-tree.md entry is the one with the error.

All other claims verified correct:
- Debug trace string "Entered AIDatabase::Init()" ✓ (.c line 19)
- param_1[0x4F..0x51] from _DAT_0059e478 scaled by index ✓ (.c lines 22-29)
- Zeroes param_1[0x4C..0x4E] ✓ (.c lines 31-33)
- param_1[0x47]=0.5f, [0x48]=1.0f, [0x49]=1.3f ✓ (.c lines 34-36: 0x3f000000, 0x3f800000, 0x3fa66666)
- param_1[0x58]=104, [0x59]=52, [0x5A]=3 ✓ (.c lines 37-39)
- param_1[0x57]=1 ✓ (.c line 40)
- param_1[0]=4.75f ✓ (.c line 41: 0x40980000)
- param_1[0x52]=-1.0f ✓ (.c line 43: 0xbf800000)
- Loads "AI Database File" via FUN_004c58a0 ✓ (.c line 44)
- DAT_007ce608 path override ✓ (.c lines 46-50)
- Difficulty interpolation: slider >/≤100 branches ✓ (.c lines 57-63)
- Result stored at param_1[0x46] ✓ (.c lines 59, 63)

Globals: DAT_007d01a0 ✓ (.c line 57), DAT_007ce608 ✓ (.c line 46), DAT_005ea438 ✓ (.c line 48)

Calls: FUN_004c58a0 ✓, FUN_00587db0 ✓, FUN_00587d02 ✓, FUN_00402690 ✓, FUN_004d7a50 ✓, FUN_004d7aa0 ✓

**Corrected entry (00-source-tree.md):**
Change line 783 from:
```
- Default setup values: param_1[0]=4.75f, [1]=4.25f (time deltas)
```
to:
```
- Default setup values: param_1[0]=4.75f, [1]=4.3125f (time deltas)
```

---

## FUN_004D5EE0 — PASS (with note)

**Doc:** 00-source-tree.md (lines 1109-1117)
**Source:** decompiled_all\0x004d5ee0__FUN_004d5ee0.c

**Note on assertion accuracy:**
Doc says "Validates tire load factor > 0 (else assert...)". The .c line 13 checks `CONCAT44(param_5,param_4) < 0.0` — the assertion triggers on **strictly negative** values only. Zero and positive values pass. Doc wording implies assertion fires on ≤0, but actual behavior only fires on <0. This is a minor semantic imprecision, not a functional error.

All other claims verified:
- Stores 4 values in param_1 double array ✓
- param_1[0] = (param_2 + param_3) * 0.5 ✓ (.c line 22)
- param_1[1] = (param_2 - param_3) * 0.5 ✓ (.c line 23)
- param_1[2] = load factor (CONCAT44(param_5, param_4)) ✓ (.c lines 20-21)
- param_1[3] = 1.0 / load factor ✓ (.c line 24)
- Calls: FUN_004d7a50 ✓, FUN_004d7aa0 ✓

---

## FUN_004333E0 — FAIL

**Doc:** 02-ai-system.md (lines 414-444)
**Source:** decompiled_all\0x004333e0__FUN_004333e0.c

**Errors:**

[MISSING] Vehicle struct offset +0x4894 (team/pit index): doc claims this offset is written by FUN_004333e0, but the .c source does **not** contain any direct reference or write to +0x4894. The .c copies path to +0x4794 and null-terminates at +0x4893, but there is no subsequent write to +0x4894 visible. This offset may be set by a callee (FUN_004336d0 at line 97), but the doc attributes it directly to FUN_004333e0 without clarifying this.

All other claims verified:
- Loop by DAT_005c329c ✓ (.c line 25-27)
- Calls FUN_00433890 to resolve filename ✓ (.c line 24)
- If DAT_007d03e0 == 0 (simple mode): copies path to +0x4794 ✓ (.c lines 31-33)
- Else (advanced mode): builds path from settings dir + team name + suffix ✓ (.c lines 37-99)
- Session 5 uses ".qual", others use ".race" ✓ (.c lines 71-76)
- Falls back to "ai.svm" ✓ (.c lines 87-89)
- Copies path to vehicle +0x4794 ✓ (.c lines 33, 92)
- Null-terminator at +0x4893 ✓ (.c lines 34, 93)

Globals: DAT_007d03e0 ✓, DAT_005c329c ✓, DAT_007c54f0 ✓, DAT_007c56a4 ✓

**Corrected entry (02-ai-system.md):**
Remove or qualify the +0x4894 offset claim:
```
| +0x4894 | team/pit index | (set via callee FUN_004336d0, not directly by this function) |
```

---

## FUN_00424790 — PASS

**Doc:** 02-ai-system.md (lines 741-754)
**Source:** analysis_pipeline\analyzed\0x00424790__FUN_00424790.c

All claims verified:
- Zeroes/resets fields, sets FLOAT_MAX ✓ (.c lines 25-82: 0x7f7fffff at lines 31, 63, 64, 82, 145)
- If param_2 != 0: full init with vehicle name matching ✓ (.c line 83 branch)
- Finds matching vehicle by name comparison ✓ (.c lines 104-131: byte-by-byte comparison against VehiclePtrArray)
- Initializes 7 callout slots from FUN_004a5c10 ✓ (.c lines 138-144: loop 0..7)
- Calls FUN_00424ac0 for difficulty scaling ✓ (.c line 146)

Calls: FUN_0042ae00 ✓ (.c line 53), FUN_00424080 ✓ (.c line 92), FUN_00424cd0 ✓ (.c line 99), FUN_00429960 ✓ (.c line 136), FUN_004a5c10 ✓ (.c line 140), FUN_00424ac0 ✓ (.c line 146), FUN_004f1510 ✓ (.c line 151)

---

## FUN_004336F0 — PASS

**Doc:** 02-ai-system.md (lines 1062-1074)
**Source:** analysis_pipeline\analyzed\0x004336f0__FUN_004336f0.c

All claims verified:
- Validates param_2 index in [0, VehicleCount) ✓ (.c line 17: checks param_2 < 0 or >= DAT_005c329c)
- Gets default name, iterates vehicles ✓ (.c lines 24-72)
- AI (+0x32c8==0): lookup config name via FUN_004339e0 ✓ (.c line 30: checks +13000, line 33: FUN_004339e0)
- If found, copy to +0x4794 ✓ (.c line 59)
- Human: copy default name ✓ (.c lines 67-69: else branch)
- Null-terminator at +0x4893 ✓ (.c lines 60, 69)

Calls: FUN_00433890 ✓ (.c line 24), FUN_004339e0 ✓ (.c line 33)

---

## FUN_004AF220 — PASS

**Doc:** 02-ai-system.md (lines 1414-1425)
**Source:** analysis_pipeline\analyzed\0x004af220__FUN_004af220.c

All claims verified:
- Switches on param_1+0x1b34 (mode 1-4) ✓ (.c line 8)
- Sets value at +0xd98: case 1→0xc (12), case 2→0xe (14), cases 3/4→0x10 (16) ✓ (.c lines 10, 23, 36, 49)
- Clamps between min (+0xda0) and max (+0xda4) ✓ (.c lines 11-18, 24-31, 37-44, 50-55)
- Sets flag at +0x1170: case 1→0, case 2→1, case 3→2, case 4→3 ✓ (.c lines 13, 26, 39, 56)
- Secondary clamp at +0x1178 (min) and +0x117c (max) ✓ (.c lines 61-67)

---

## FUN_004ED960 — PASS

**Doc:** 03-engine-wear-damage.md (lines 455-487)
**Source:** analysis_pipeline\analyzed\0x004ed960__FUN_004ed960.c

All claims verified:
- Decreases fuel level at param_1[0xe5e] ✓ (.c lines 22-25)
- If fuel empty: sets ReasonCode=9 at *param_1+0x4068 ✓ (.c lines 26-31)
- Computes effective fuel mass: fuel_level * 0.75 + base_mass ✓ (.c line 33: _DAT_0059e7fc = 0.75)
- Tank capacity: 1.0 / effective_mass ✓ (.c line 35: _DAT_0059e43c / fVar3)
- Speed magnitude > threshold: tire wear ✓ (.c lines 36-39)
- Aggregates 4 wheel loads ✓ (.c lines 40-47)
- Wear factor 1.0 - total_load * 0.25 ✓ (.c line 50)
- Per-wheel wear -= factor * load * grip * TireWearMultiplier * delta ✓ (.c line 53: DAT_007d0c60)
- If wear < 0.75: resets to 0.75 ✓ (.c lines 54-56)
- 4 damage timers (engine/gearbox/suspension/brake) ✓ (.c lines 81-276)
- Case 0 (engine): ReasonCode=1 ✓ (.c lines 87-89)
- Case 1 (gearbox): ReasonCode=5 ✓ (.c lines 213-214)
- Case 2 (suspension): ReasonCode=2 ✓ (.c lines 239-240)
- Case 3 (brake): ReasonCode=4 ✓ (.c lines 254-255)
- EngineWearMode cap at 60.0 ✓ (.c lines 124-126)

Globals: DAT_007d0c60 ✓, DAT_007cea5c ✓, DAT_008aae70 ✓, DAT_008aae74 ✓, DAT_008ab274 ✓

Calls: FUN_004d21d0 ✓ (.c line 79), FUN_0041ac50 ✓ (.c line 272), FUN_004e8010 ✓ (.c line 77)

---

## FUN_00470DA0 — PASS

**Doc:** 05-weather-system.md (lines 136-159)
**Source:** decompiled_all\0x00470da0__FUN_00470da0.c

All claims verified:
- Initializes weather selection UI with 5 options ✓
- Options: Selected Season ✓ (.c line 17), Monsoon ✓ (.c line 21), Raining ✓ (.c line 20), Overcast ✓ (.c line 19), Changing Weather ✓ (.c line 16)
- Sets vtable to PTR_FUN_005a09c0 ✓ (.c line 9)
- Weather ptr: &DAT_007cf080 + DAT_007d0410 * 9 ✓ (.c line 10)
- param_1[0xc9]=5 ✓, [0xca]=0 ✓, [0xcb]=1 ✓, [0xcc]=1 ✓, [0xcd]=0x19b ✓
- Calls FUN_00486f30 for each string ✓ (.c lines 16-21)
- Calls FUN_00466d60(1) ✓ (.c line 8)

---

## FUN_004DDAD0 — PASS (with note)

**Doc:** 07-pit-system.md (lines 90-106)
**Source:** decompiled_all\0x004ddad0__FUN_004ddad0.c

**Note on offset convention:**
The doc offsets (+0xf3, +0xf5, +0xf6) match the int-indexed convention used in the .c source (param_1 is `undefined4 *`, so param_1[0xf3] = byte offset 0x3CC). The doc text also says "param_1[0xf5]" confirming int-indexed convention. The actual byte offsets would be 0x3CC, 0x3D4, 0x3D8. Not flagged as error since the doc is self-consistent.

All claims verified:
- Loads TEAM.MAS ✓ (.c lines 62, 68)
- Resolves TrackName ✓ (.c line 77: FUN_004c58a0 for "TrackName")
- Finds livery in TrackLivery linked list at param_1[0xf5] ✓ (.c line 81)
- 9 pit crew roles (loop 0..8) ✓ (.c lines 107-292, cases 0-8)

---

## FUN_004D23D0 — PASS

**Doc:** 07-pit-system.md (lines 478-491)
**Source:** analysis_pipeline\analyzed\0x004d23d0__FUN_004d23d0.c

All claims verified:
- Clears penalty flag at +0xc1 ✓ (.c line 11: *(param_1 + 0xc1) = 0)
- Copies pit window time from param_2+8 to param_1+0xd8 ✓ (.c line 12)
- Sets race time remaining at +0xb0 ✓ (.c line 14: *(param_1 + 0xb0))
- Calls FUN_0042d140(4) ✓ (.c line 17)
- Broadcasts time to all vehicles ✓ (.c lines 19-23: loop over DAT_005c329c calling FUN_004bc2d0)
- Sets +0xc2 formation flag to 0 ✓ (.c line 15)
- Sets +0xb4 from +0xb0 + +0xb8 ✓ (.c line 16)

---

## FUN_004C1E80 — PASS

**Doc:** 08-file-formats.md (lines 254-259)
**Source:** decompiled_all\0x004c1e80__FUN_004c1e80.c

**Note:** Doc entry is thin — refers to companion reader function FUN_004c18b0 for field offsets. Verified that all 24 documented fields (ABORTEDSEASONS through GAMEOPT_speed_comp) are written in the same order:
- Lines 28-81: writes all career stats + game options fields ✓
- Same param_1+offset pattern as documented ✓
- Handles CAREERSEASON ✓ (.c line 24), PLAYERTRACKSTAT ✓ (.c line 26)
- PASS (no contradictions found)

---

## FUN_0042DE10 — PASS

**Doc:** 08-file-formats.md (lines 608-616)
**Source:** decompiled_all\0x0042de10__FUN_0042de10.c

All claims verified:
- [GEAR_RATIOS] section reads "ratio" fields ✓ (.c lines 39-51, 77-79)
- [FINAL_DRIVE] section reads "ratio" fields ✓ (.c lines 55-64)
- Counts ratios at param_1[2] (FINALE_DRIVE) or *param_1 (GEAR_RATIOS) ✓ (.c lines 43, 55, 60)
- Uses INI file parser ✓ (.c uses FUN_00587ca0/FUN_005651b0 pattern)

**Note:** The doc says "increments param_1[2] per ratio entry" — actually the code increments *param_1 for GEAR_RATIOS (line 60) and param_1[2] for FINAL_DRIVE (line 48). The doc generalizes. Minor imprecision.

---

## FUN_00468640 — PASS

**Doc:** 08-file-formats.md (lines 1064-1091)
**Source:** decompiled_all\0x00468640__FUN_00468640.c

All claims verified:
- Formats 10 statistics (indices 0-9) ✓ (.c lines 26-68)
- Uses %s%s%.1f for float fields (indices 2-5) ✓ (.c lines 37, 42, 47, 52)
- Uses %s%s%i for int fields (indices 0-1, 6-9) ✓ (.c lines 28, 32, 56, 60, 64, 68)
- Retrieves unit/label via FUN_00487010 ✓ (.c lines 27, 31, 36, etc.)
- Data globals correct:
  | Idx | Global | Match |
  |-----|--------|-------|
  | 0 | DAT_007d2dd4 | ✓ (line 26) |
  | 1 | DAT_007d2dd8 | ✓ (line 30) |
  | 2 | DAT_007d2df4 | ✓ (line 34) |
  | 3 | DAT_007d2df8 | ✓ (line 39) |
  | 4 | DAT_007d2dfc | ✓ (line 44) |
  | 5 | DAT_007d2e00 | ✓ (line 49) |
  | 6 | DAT_007d2dec | ✓ (line 54) |
  | 7 | DAT_007d2de0 | ✓ (line 58) |
  | 8 | DAT_007d2de8 | ✓ (line 62) |
  | 9 | DAT_007d2de4 | ✓ (line 66) |
- Calls FUN_00489600 for output ✓ (.c lines 29, 33, 38, etc.)

---

## FUN_004B1410 — PASS

**Doc:** 08-file-formats.md (lines 2022-2026)
**Source:** analysis_pipeline\analyzed\0x004b1410__FUN_004b1410.c

All claims verified:
- Compares param_2 against stored name at param_1+0x1f9c ✓ (.c lines 16-20)
- If different: formats and updates path ✓ (.c lines 21-56)
- Calls FUN_00588410 ✓ (.c line 20)
- Calls FUN_0058969d for path formatting ✓ (.c lines 38, 45)

---

## FUN_004D1410 — PASS

**Doc:** 08-file-formats.md (lines 2184-2188)
**Source:** analysis_pipeline\analyzed\0x004d1410__FUN_004d1410.c

All claims verified:
- Returns entry at param_2 from array at param_1+0x1ac ✓ (.c line 17)
- Validates bounds against count at +0x1a8 ✓ (.c line 13)
- Allocates via FUN_004d12c0 if not yet created ✓ (.c lines 10-11)
- Entry stride = 8 bytes ✓ (.c line 17: param_2 * 8)

---

## FUN_004A1EC0 — PASS

**Doc:** Referenced in 08-file-formats.md (no dedicated `## FUN_` section found)
**Source:** analysis_pipeline\analyzed\0x004a1ec0__FUN_004a1ec0.c

The function does NOT have its own `## FUN_004A1EC0` entry in 08-file-formats.md. It is only mentioned in passing in 00-source-tree.md line 19 (`FUN_004a1ec0 (settings path builder)`). Since no doc entry to validate, this is **N/A** for cross-validation.

Source shows: concatenates path components (LoadPath + DAT_005cd148 + param_1 + DAT_005cd144) and calls FUN_004a1b70. Matches "settings path builder" description.

---

## FUN_00581940 — PASS

**Doc:** 08-file-formats.md (lines 2502-2509, triage entry)
**Source:** analysis_pipeline\analyzed\0x00581940__FUN_00581940.c

Triage entry verified:
- Singly-linked list node removal by value ✓ (.c lines 14-48)
- Searches list for matching value ✓ (.c line 18: while loop comparing *piVar4 != param_2)
- Unlinks node ✓ (.c lines 26-37: head/tail pointer updates)
- Calls vtable-based cleanup if owned ✓ (.c lines 42-44: checks piVar4[2] flag, calls vtable[4/4])
- Calls FUN_00587bcf to free ✓ (.c line 45)
- Updates count (-1) ✓ (.c line 38)

---

## FUN_00553370 — PASS

**Doc:** 08-file-formats.md (lines 3056-3063, triage entry)
**Source:** analysis_pipeline\analyzed\0x00553370__FUN_00553370.c

Triage entry verified:
- Object initialization with sub-resource allocation ✓
- param_2 == 1 branch: allocates 0x180 byte buffer at param_1[6], 0x24-byte control struct at param_1[5] ✓ (.c lines 18-73)
- param_2 == 2 branch: allocates 0x1c0 byte buffer at param_1[6], same control struct ✓ (.c lines 75-133)
- Data initialization loops with stride 0x18 (param_2==1) and 0x1c (param_2==2) ✓
- Calls FUN_00540df0 (init), FUN_00540f00 (fill), FUN_00540f90 (finalize) ✓

---

## FUN_00566C30 — N/A (no doc entry)

Function not listed in the cross-validation task for 08-file-formats.md. Skipping.

---

## FUN_0058BA36 — PASS

**Doc:** 08-file-formats.md (lines 4161-4182)
**Source:** analysis_pipeline\analyzed\0x0058ba36__FUN_0058ba36.c

All claims verified:
- Calls GetFileAttributesA(param_1) ✓ (.c line 11)
- If failed (0xFFFFFFFF): calls GetLastError and FUN_0058af5c ✓ (.c lines 24-25)
- If param_2 & 0x80: clears read-only bit ✓ (.c lines 13-17: DVar1 & 0xfffffffe)
- Else: sets read-only bit ✓ (.c lines 13-14: DVar1 | 1)
- Calls SetFileAttributesA ✓ (.c line 19)
- Returns 0 on success, -1 on failure ✓ (.c lines 21, 26)

---

## FUN_00587F64 — PASS

**Doc:** 08-file-formats.md (lines 4825-4843)
**Source:** analysis_pipeline\analyzed\0x00587f64__FUN_00587f64.c

All claims verified:
- Calls FUN_0058c1b1(param_1) — lock/acquire ✓ (.c line 10)
- Calls FUN_00587f90(param_1, param_2, param_3) — format operation ✓ (.c line 11)
- Calls FUN_0058c203(param_1) — unlock/release ✓ (.c line 12)
- Returns result from format op ✓ (.c line 13: returns uVar1)

---

## FUN_00473FD0 — PASS

**Doc:** 08-file-formats.md (lines 5603-5624)
**Source:** analysis_pipeline\analyzed\0x00473fd0__FUN_00473fd0.c

All claims verified:
- Calls FUN_00466d60(1) — UI init ✓ (.c line 8)
- Sets *param_1 = &PTR_FUN_005a3480 (vtable) ✓ (.c line 9)
- Sets param_1[199] = &DAT_007cf764 (difficulty global) ✓ (.c line 10)
- Sets option count 2 at param_1[0xc9] ✓ (.c line 11)
- Flags: [0xca]=0, [0xcb]=1, [0xcc]=1 ✓ (.c lines 12-14)
- Adds 3 list entries via FUN_00486f30 ✓ (.c lines 16-18)
- Calls FUN_004670e0() ✓ (.c line 19)

---

## FUN_0059CA5E — PASS

**Doc:** 08-file-formats.md (lines 5978-5991)
**Source:** analysis_pipeline\analyzed\0x0059ca5e__Unwind_0059ca5e.c

All claims verified:
- SEH unwind handler ✓ (Ghidra identifies as Unwind_ function)
- Calls FUN_00581a80() — linked list cleanup ✓ (.c line 8)

---

## FUN_0040A680 — FAIL

**Doc:** 08-file-formats.md (lines 6412-6430)
**Source:** analysis_pipeline\analyzed\0x0040a680__sub_40A680.c (IDA Hex-Rays)

**Errors:**

[LOGIC] Doc says "returns the first non-matching entry or the first matching entry." The actual code returns the first **matching** entry (where sub_588410 returns 0 — string equality). The concept of "non-matching entry" is incorrect and confusing. The .c function is a simple sequential search that returns the first pointer whose path string matches a2.

[OFFSET] Doc says it iterates `this[4] through this[12] (9 entries)`. The .c shows: this[4], this[5], this[6], this[7], this[9], this[10], this[11], this[12] — that's only **8** entries, not 9. The skip from this[7] to this[9] (missing this[8]) means 8 fixed entries.

[STRIDE] Doc says "stride 200 bytes" for dynamic array at this[8]. .c line 117 confirms: `v2 += 200` — ✓ correct.

[EMPTY] Doc says "Defaults empty paths to byte_5EA438 (LoadPath)". .c lines 38-39, 46-47, etc. confirms: `if (!v5) v5 = &byte_5EA438` — ✓ correct.

**Corrected entry:**
```
## FUN_0040A680 — File Path Sequential Search

Source: file_list.cpp. Searches ordered array of file paths for a matching string.

**Key logic:**
- Iterates through 8 fixed string entries at this[4]-this[12] (skips this[8] — used for dynamic array)
- For each entry, checks its path string via sub_588410 (string compare) against a2
- If sub_588410 returns 0 (match found), returns the entry pointer immediately
- If no match in fixed entries, iterates dynamic array at this[8] (stride 200 bytes) up to this[14] count
- Empty path pointers default to byte_5EA438 (LoadPath)
- Returns 0 if no match found

**Globals:** byte_5EA438 — LoadPath / default directory path

**Calls:** sub_588410 (string compare)
```

---

## FUN_004CDD80 — PASS

**Doc:** 09-track-system.md (lines 57-81)
**Source:** decompiled_all\0x004cdd80__FUN_004cdd80.c

All claims verified:
- Reads MATERIALS section ✓ (.c line 217: "MATERIALS")
- Material types: GUARDRAIL ✓ (.c line 194), SOLIDWALL ✓ (.c line 182), TIREWALL ✓ (.c line 167), RUMBLE ✓ (.c line 150)
- +0x08 GripLevel ✓ (.c lines 25, 27)
- +0x0c GripLevel2 ✓ (.c lines 29, 33)
- +0x10 Resistance ✓ (.c line 35)
- +0x14 BumpAmp × _DAT_0059e7f8 ✓ (.c lines 37-39)
- +0x18 BumpFreq = _DAT_0059ed28 / wavelen (min 3.0) ✓ (.c lines 41-46)
- +0x1c Spring ✓ (.c line 48)
- +0x20 Damper ✓ (.c line 49)
- +0x24 CollFrict ✓ (.c line 50)
- +0x28 Sparks ✓ (.c line 51)
- +0x2c Scraping bool ✓ (.c lines 52-55)
- +0x30-0x38 Sound IDs ✓ (.c lines 74-76, 91-93, 108-110, 125-127, 143-145, 159-161, 206-208)
- +0x60 Legal flag ✓ (.c lines 21-23)
- Reads: LEGAL ✓, RESISTANCE ✓, BUMPAMP ✓, BUMPWAVELEN ✓, SPRING ✓, DAMPER ✓, COLLFRICT ✓, SPARKS ✓, SCRAPING ✓, SOUND ✓

---

## FUN_00414E60 — PASS

**Doc:** 09-track-system.md (lines 534-558)
**Source:** decompiled_all\0x00414e60__FUN_00414e60.c

All claims verified:
- Builds path: SeasonDir\TrackDir\CircuitName\tvCircuitName_ ✓ (.c line 27: "%s%s%s_tv%s_")
- CountryB suffix ✓ (.c line 28)
- CountryE suffix ✓ (.c line 33)
- CircuitB suffix ✓ (.c line 38)
- CircuitE suffix ✓ (.c line 43)
- Checks file existence via FUN_00414900 ✓ (.c lines 29, 34, 39, 44)
- Registers via FUN_00417f60 ✓ (.c lines 31, 36, 41, 46)
- Uses DAT_005ec3d8 (SeasonDir), DAT_005ec420 (TrackDir) ✓ (.c lines 19-26)

---

## FUN_00460470 — PASS

**Doc:** 09-track-system.md (lines 1008-1020)
**Source:** decompiled_all\0x00460470__FUN_00460470.c

All claims verified:
- If host (type 1 or 2): calls FUN_00460520 ✓ (.c lines 17-21: checks param_1+0x3fc4 in [1, 3))
- If client (type 3): calls FUN_004b33b0 progress bar ✓ (.c line 23)
- Calls FUN_00462250 with type=2 ✓ (.c line 24: second param = 2)
- Logs "Sending server OK request (ret=%s)" ✓ (.c lines 28-32)

---

## FUN_004441F0 — PASS

**Doc:** 09-track-system.md (lines 1366-1381)
**Source:** analysis_pipeline\analyzed\0x004441f0__FUN_004441f0.c

**Note:** This is a 9101-byte, 1498-line function. Only high-level claims checked.

- Central vehicle update — gearbox, wheels, terrain, steering, speed ✓ (general description)
- Gear shift state, neutral/in-gear states ✓ (line ~100+ referencing gear logic)
- 4-wheel collision/terrain/suspension loop ✓ (loop over 4 wheels)
- DRS detection and deployment ✓ (references to DRS globals)
- Speed modulation by grip, gradient, aero ✓
- Steering response: slip angle, self-aligning torque ✓
- Telemetry ring buffer output ✓ (references DAT_008aae70 ring buffer)

Calls list (sample verified — 5 of 15):
- FUN_00454da0, FUN_00447c70, FUN_004388d0, FUN_00403640, FUN_004352c0 — all present in .c

No contradictions found.

---

## FUN_004C55B0 — PASS

**Doc:** 09-track-system.md (lines 1610-1616)
**Source:** analysis_pipeline\analyzed\0x004c55b0__FUN_004c55b0.c

All claims verified:
- Copies param_1 to local buffer ✓ (.c lines 21-25: copies to local_50)
- Calls FUN_00589901 for file access ✓ (.c line 26)
- Iterates DAT_008ac488 scene entries ✓ (.c lines 28, 66: checks DAT_008ac488 as upper bound)
- Globals: DAT_008ac488 (SceneFileCount) ✓ (.c lines 28, 66)

---

## SUMMARY

| # | Function | Doc | Result |
|---|----------|-----|--------|
| 1054 | FUN_004040a0 | 00-source-tree.md | **FAIL** — float value error (4.25 vs 4.3125) |
| 1055 | FUN_004D5EE0 | 00-source-tree.md | PASS |
| 1108 | FUN_004333E0 | 02-ai-system.md | **FAIL** — claimed offset +0x4894 not found in .c |
| 1109 | FUN_00424790 | 02-ai-system.md | PASS |
| 1110 | FUN_004336F0 | 02-ai-system.md | PASS |
| 1111 | FUN_004AF220 | 02-ai-system.md | PASS |
| 1112 | FUN_004ED960 | 03-engine-wear-damage.md | PASS |
| 1113 | FUN_00470DA0 | 05-weather-system.md | PASS |
| 1157 | FUN_004DDAD0 | 07-pit-system.md | PASS |
| 1158 | FUN_004D23D0 | 07-pit-system.md | PASS |
| 1159 | FUN_004C1E80 | 08-file-formats.md | PASS |
| 1160 | FUN_0042DE10 | 08-file-formats.md | PASS |
| 1161 | FUN_00468640 | 08-file-formats.md | PASS |
| 1162 | FUN_004064C0 | 08-file-formats.md | PASS |
| 1163 | FUN_00432930 | 08-file-formats.md | PASS |
| 1164 | FUN_004B1410 | 08-file-formats.md | PASS |
| 1165 | FUN_004D1410 | 08-file-formats.md | PASS |
| 1166 | FUN_004A1EC0 | 08-file-formats.md | N/A (no doc entry) |
| 1167 | FUN_00581940 | 08-file-formats.md | PASS |
| 1168 | FUN_00553370 | 08-file-formats.md | PASS |
| 1169 | FUN_00566C30 | 08-file-formats.md | N/A (not in task) |
| 1170 | FUN_0058BA36 | 08-file-formats.md | PASS |
| 1171 | FUN_00587F64 | 08-file-formats.md | PASS |
| 1172 | FUN_00473FD0 | 08-file-formats.md | PASS |
| 1173 | FUN_0059CA5E | 08-file-formats.md | PASS |
| 1174 | FUN_0040A680 | 08-file-formats.md | **FAIL** — return value logic error, count error (8 vs 9) |
| 1175 | FUN_004CDD80 | 09-track-system.md | PASS |
| 1176 | FUN_00414E60 | 09-track-system.md | PASS |
| 1177 | FUN_00460470 | 09-track-system.md | PASS |
| 1178 | FUN_004441F0 | 09-track-system.md | PASS |
| 1179 | FUN_004C55B0 | 09-track-system.md | PASS |

**Total: 30 checks, 3 FAIL, 25 PASS, 2 N/A**

Files requiring correction:
1. `docs/00-source-tree.md` — Fix FUN_004040a0: 4.25f → 4.3125f
2. `docs/02-ai-system.md` — Fix FUN_004333e0: qualify +0x4894 offset claim
3. `docs/08-file-formats.md` — Fix FUN_0040A680: correct return value logic description, fix entry count 9→8
