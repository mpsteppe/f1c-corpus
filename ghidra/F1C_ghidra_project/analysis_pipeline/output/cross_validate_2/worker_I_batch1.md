# Cross-Validation Results — worker_I_batch1

## FUN_00455BF0 — PASS

Source: docs/01-engine-architecture.md (line 215)
- Profile trace via FUN_004d7a50/7aa0 ✓
- FUN_0044f4e0 (cursor init) ✓
- ShowCursor(0) loop ✓
- FUN_00455290 (control binding) ✓
- DAT_007d13a0 == 1 → FUN_004f8ae0 ✓
- Returns 0 ✓

## FUN_004D7660 — PASS

Source: docs/00-source-tree.md (line 1159)
- Scans season directory for *.tbc ✓
- Builds path from DAT_005ec428/DAT_005ec3d8 with DAT_005ea438 fallback ✓
- Uses FUN_00565f80 to enumerate *.tbc files ✓
- Allocates brand array stride 0x24 ✓
- Iterates calling FUN_004d7150 to parse each ✓
- Globals: DAT_005ec428, DAT_005ec3d8, DAT_005ea438 — all confirmed in source ✓
- Calls list verified against source: FUN_004d7800, FUN_00567740, FUN_0058815f, FUN_00565f80, FUN_00565f70, FUN_004d7020, FUN_004d7150, FUN_00565f50, FUN_005662d0, FUN_00565f20, FUN_00565eb0, FUN_00567780, FUN_004d7a50, FUN_004d7aa0 ✓

## FUN_00455F00 — PASS

Source: docs/01-engine-architecture.md (line 233)
- Logs entry via FUN_004d7a50/7aa0 ✓
- FUN_0044fbe0 ×2 ✓
- FUN_0044f5f0 ✓
- FUN_0044efe0 ✓
- Releases DirectInput via vtable+8, zeroes param_1 ✓
- DAT_007d13a0 == 1 → FUN_004f8c90, sets param_1[0x6c4] = -1 ✓
- Calls: FUN_0044fbe0, FUN_0044f5f0, FUN_0044efe0, FUN_004f8c90 ✓
- Note: "New globals" section lists DAT_007d1ffc, DAT_007ce2a0, DAT_007ce2dc, DAT_005ec4a4 which are NOT referenced in this function's source; likely class-level globals listed here. Function-specific usage of DAT_007d13a0 confirmed.

## FUN_0042C690 — FAIL

Source: docs/01-engine-architecture.md
**Errors:** [WRONG_NAME] [WRONG_CALLS] [WRONG_GLOBALS]

Doc entry not found in 01-engine-architecture.md as `## FUN_0042C690` header. Function is documented as "Main Game Tick" in impl spec (docs/30-impl-specs/03-session-state-machine-module-lifecycle-system-part-2-spec.md line 335) but not as a full `## FUN_0042C690` entry in docs/01. The user-assigned doc is docs/01-engine-architecture.md but no entry exists there.

Source analysis (0x0042c690__FUN_0042c690.c):
- 863 bytes, void FUN_0042c690(void)
- Guard: if DAT_008ab6e4 != 2
- Calls FUN_0042c440()
- Calls FUN_005895a2(_DAT_008afea0 * _DAT_0059e9b0)
- Timed loop using DAT_007c5694 (counter) and DAT_007c5698 (tick counter)
- Every 10 ticks: per-vehicle loops (FUN_00424e70, FUN_004eb430, FUN_004ee2d0), zeros 12 _DAT_007c932c-007c9358 flags
- Every 400 ticks: calls FUN_004ed960 for player vehicles
- Every 50 ticks: calls FUN_0042caa0, per-vehicle FUN_004f1c40, FUN_004ed810 for player vehicles
- If player vehicle state == 0: calls FUN_004bccc0
- Periodic: checks DAT_008ad23c modulus, calls FUN_004d5960/FUN_004d59b0
- If player vehicle state == 0 and conditions: calls FUN_004e4930
- Loops until counter catches up
- Final: FUN_004109d0()

**Globals used:** DAT_008ab6e4, _DAT_008afea0, _DAT_0059e9b0, DAT_007c5694, DAT_007c5698, DAT_005c329c, _DAT_007c932c-_007c9358 (12), DAT_007c54f0, DAT_007c54e8, DAT_008ad23c, DAT_008ad238, DAT_007ce958, DAT_007cbf24

**Calls:** FUN_0042c440, FUN_005895a2, __ftol, FUN_00424e70, FUN_00410980, FUN_004eb430, FUN_004ee2d0, FUN_004ed960, FUN_0042caa0, FUN_004f1c40, FUN_004ed810, FUN_004bccc0, FUN_004d5960, FUN_004d59b0, FUN_004e4930, FUN_00451720, FUN_004109d0

**Corrected entry:**
<!-- target: docs/01-engine-architecture.md -->
## FUN_0042C690 — Main Game Tick / Time-Sliced Update Loop

Source: Game.cpp (game loop tick). Core game loop tick — runs AI/physics updates on a time-sliced schedule tied to DAT_007c5698 tick counter.

**Key logic:**
- Guard: skip if DAT_008ab6e4 == 2
- Calls FUN_0042c440 (pre-update)
- Computes target tick count from _DAT_008afea0 * _DAT_0059e9b0
- Loops DAT_007c5694 (current tick) up to target with max catch-up of 0xC9 (201) ticks
- Every 10 ticks: AI update (FUN_00424e70 per vehicle), zeroes 12 scoring/lap flags (DAT_007c932c-007c9358), physics step (FUN_004eb430 per vehicle), vehicle integration (FUN_004ee2d0 per vehicle)
- Every 400 ticks: AI driving decisions for player vehicles (FUN_004ed960)
- Every 50 ticks: safety car check (FUN_0042caa0), vehicle control updates (FUN_004f1c40), tire/brake updates for player vehicles (FUN_004ed810)
- If player vehicle in race mode (state 0): calls FUN_004bccc0 (race logic)
- Periodic checkpoint saving based on DAT_008ad23c modulus
- Alternative path when player vehicle state 0: calls FUN_004e4930 (input/control processing)
- Rolls tick counter at 400
- Final: FUN_004109d0 (post-update)

**Globals:**
- DAT_008ab6e4 — mode guard
- _DAT_008afea0, _DAT_0059e9b0 — target tick computation
- DAT_007c5694 — current tick counter
- DAT_007c5698 — frame/tick counter (0-399)
- DAT_005c329c — VehicleCount
- DAT_007c54f0 — VehiclePtrArray
- DAT_007c54e8 — PlayerVehiclePtr
- DAT_007c932c-007c9358 — 12 scoring/lap flag variables
- DAT_008ad23c, DAT_008ad238 — checkpoint timing
- DAT_007ce958 — playback/replay flag
- DAT_007cbf24 — pending action flag

**Calls:** FUN_0042c440, FUN_005895a2, FUN_00424e70, FUN_00410980, FUN_004eb430, FUN_004ee2d0, FUN_004ed960, FUN_0042caa0, FUN_004f1c40, FUN_004ed810, FUN_004bccc0, FUN_004d5960, FUN_004d59b0, FUN_004e4930, FUN_00451720, FUN_004109d0

**Moddability:** hardcoded

## FUN_004C2E20 — FAIL

Source: docs/10-vehicle-physics.md (line 2184)

**Errors:** [WRONG_DOC] — User assigned docs/01-engine-architecture.md but entry is in docs/10-vehicle-physics.md.

Entry content verified against source (0x004c2e20__FUN_004c2e20.c):
- Merge sort for linked list ✓
- Counts nodes via offset +4 (next pointer) ✓
- Splits at midpoint ✓
- Recursively sorts halves ✓
- Merges comparing *(float*)(*node_ptr + 4) ascending ✓ (line 38: `*(float *)(*piVar4 + 4) <= *(float *)(*piVar3 + 4)`)
- Returns sorted list head ✓
- Struct: +0x00 DataPtr, +0x04 NextPtr ✓
- Data element +0x04 SortKey ✓
- Calls: FUN_004c2e20 (self, recursive) ✓

All claims verified. Doc entry is correct but in wrong doc file per user assignment.

**Corrected entry:**
<!-- target: docs/01-engine-architecture.md -->
### FUN_004C2E20 — MergeSortLinkedListByFloat

Generic merge sort for linked list. Sorts by comparing float value at element+4.

**Key logic:**
- Walks list to count nodes (linked via offset +4)
- Splits at midpoint
- Recursively sorts both halves
- Merges comparing *(float*)(*node_ptr + 4) — ascending order (<= places first)
- Returns sorted list head

**Struct (linked list node):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0x00 | DataPtr | Pointer to data element |
| +0x04 | NextPtr | Next node pointer |

**Data element:**
| Offset | Field | Notes |
|--------|-------|-------|
| +0x04 | SortKey | float comparison value |

**Calls:** FUN_004c2e20 (self, recursive)

## FUN_0059A728 — PASS

Source: docs/01-engine-architecture.md (line 1470)
- Calls FUN_0058a5d8 (stack probe/SEH init) ✓
- Sets vtable to PTR_FUN_005b9d28 ✓
- Calls FUN_005993af(1) ✓
- Calls exception::~exception(this) ✓
- Restores ExceptionList ✓
- Globals: PTR_FUN_005b9d28 ✓

## FUN_005870E0 — PASS

Source: docs/01-engine-architecture.md (line 2069)
- Calls FUN_00587500 first ✓
- Sets +0x14 = -1 (0xffffffff) ✓
- Sets +0x10 = 0 ✓
- Sets +0x18 = 0 (byte) ✓
- Sets +0x19 = 0 (byte) ✓
- Struct offsets all match source exactly ✓

## FUN_00553DB0 — PASS

Source: docs/01-engine-architecture.md (line 2489)
- Sets *(param_1+0x20) = 7 ✓
- Zeros fields at +0x24, +0x30, +0x28, +0x2c, +0x34, +0x38, +0x3c ✓
- Struct offsets all confirmed in source ✓

## FUN_0059C43C — PASS

Source: docs/01-engine-architecture.md (line 2955)
- Calls FUN_00587bcf(*(unaff_EBP + -0x14)) ✓
- SEH unwind freeing object at stack offset -0x14 ✓

## FUN_00587230 — PASS

Source: docs/01-engine-architecture.md (line 3393)
- Reads byte counter at param_1+0x19 ✓
- If param_2 != 0: increments by 1 ✓
- If param_2 == 0 AND counter != 0: decrements by 1 ✓
- Clamped to byte range ✓

## FUN_0046A530 — PASS

Source: docs/01-engine-architecture.md (line 3965)
- Sets *param_1 = &PTR_FUN_0059f938 (vtable reset) ✓
- If param_1[0x5d] (offset +0x174) non-null: frees via FUN_00587bcf ✓
- Calls FUN_00489440() ✓
- Struct offset +0x174 confirmed ✓

## FUN_004F23B0 — PASS

Source: docs/01-engine-architecture.md (line 4402)
- Calls FUN_00587b3e(&LAB_004f23c0) ✓
- Callback registration (_atexit-like) ✓

## FUN_0058D82C — FAIL

Source: docs/01-engine-architecture.md (line 4858)

**Errors:** [WRONG_DESCRIPTION]

Doc says: "Returns *(int*)((char*)&param_1 + 4)" — Incorrect. Actual behavior:
```
*param_1 = *param_1 + 4;          // advances pointer by 4 bytes
return *(undefined4 *)(*param_1 + -4);  // reads value at old position
```
Function is a sequential buffer read primitive: advances a pointer int by 4, returns previous 4-byte value at that position. NOT a stack peek.

**Corrected entry:**
<!-- target: docs/01-engine-architecture.md -->
## FUN_0058D82C — Sequential Int Read + Advance

Source: unknown. Reads int from pointer, advances pointer by 4 bytes.

**Key logic:**
- *param_1 += 4 — advance pointer offset by 4
- Returns *(int*)(*param_1 - 4) — read int at previous position
- Pattern: sequential deserialization from buffer

**Moddability:** hardcoded

## FUN_0055C7D0 — PASS

Source: docs/01-engine-architecture.md (line 5453)
- Calls FUN_0055c450(*(param_1+0x13ec), 0, &local_4) — passes VALUE at +0x13ec ✓
- Returns local_4 (queried value) ✓
- Offset 0x13ec confirmed as input device handle/ptr field ✓

## FUN_005905DD — PASS

Source: docs/01-engine-architecture.md (line 6001)
- Iterates input string char by char ✓
- 'a'-'f': subtract 0x27 ✓
- 'A'-'F': subtract 7 ✓
- Accumulates: (result - 3) * 16 + charValue ✓
- No calls (pure logic) ✓

## FUN_0056CF10 — PASS

Source: docs/01-engine-architecture.md (line 6412)
- Frees param_1[0], [1], [2], [3] via FUN_00587bcf ✓
- Null checks before each free ✓
- Zeros each after freeing ✓

## FUN_0059A8D8 — PASS

Source: docs/01-engine-architecture.md (line 6839)
- Walks linked list at param_1+0x1c ✓
- For each node: calls callback with 3 args (param_2, param_1, puVar1[1]) ✓

## FUN_00597218 — PASS

Source: docs/01-engine-architecture.md (line 7157)
- Checks DAT_008d5a4c flag ✓
- If 0: calls FUN_00596e40(0xfffffffd), sets flag to 1 ✓
- If already 1: no-op ✓

## FUN_00471860 — PASS

Source: docs/01-engine-architecture.md (line 7565)
- Calls FUN_00466d60(1) ✓
- Vtable: PTR_FUN_005a12c0 ✓
- param_1[199] = &DAT_007ce7cc ✓
- Fields [0xc9..0xcc] = 1, 0, 1, 1 ✓
- Field [0xcd] = 0xf2 (242) ✓
- FUN_00486f30 twice ✓
- FUN_004670e0 ✓

## FUN_004975B0 — PASS

Source: docs/01-engine-architecture.md (line 7935)
- Sets *(param_2+0x40) = param_1 ✓
- Calls FUN_00498eb0(param_2) ✓

## FUN_004FC650 — PASS

Source: docs/01-engine-architecture.md (line 8249)
- If DAT_0083ee60 < 0x3ff: increments counter and offset (+0x1b0) ✓
- String lengths at +0x50 and +0x84 ✓
- Calls FUN_004b33b0 ✓
- Copies strings to ring buffer ✓
- Globals: DAT_008aae64, DAT_0083ee60 ✓

## FUN_00583AA0 — PASS

Source: docs/01-engine-architecture.md (line 8539)
- If flag at +0x24 set: CloseHandle(+0x1c), zero ✓
- If flag at +0x14 set: CloseHandle(+0xc), zero ✓

## FUN_0059A980 — PASS

Source: docs/01-engine-architecture.md (line 9020)
- Calls FUN_0059a8d8(0) ✓
- Frees linked list at +0x18 ✓
- Frees linked list at +0x1c ✓
- "Double linked list free" confirmed

## FUN_005874D0 — PASS

Source: docs/01-engine-architecture.md (line 9741)
- operator_new(param_1), stores to *param_2 ✓
- Returns success (result != null) ✓

## FUN_0059A407 — PASS

Source: docs/01-engine-architecture.md (line 10247)
- Increments **(param_1+0x2c) by 1 ✓
- Decrements **(param_1+0x1c) by 2 ✓

## FUN_00554C30 — PASS

Source: docs/01-engine-architecture.md (line 10842)
- Linked list at +0x24, next at +0xc0 ✓
- +0xa4 entries, stride 0x25 dwords, base +0xa8+0x8c ✓
- Bit 2 check, nested null check ✓
- Bit 0/3/1 manipulation at +0x54->+0x18 ✓
- FUN_0053f720(entry->+0x54, 0) ✓

## FUN_0059A428 — PASS

Source: docs/01-engine-architecture.md (line 11329)
- **(param_1+0x30) -= param_2 ✓
- **(param_1+0x20) += param_2 * 2 ✓

## FUN_005861E0 — PASS

Source: docs/01-engine-architecture.md (line 11783)
- If flag at +0x5c: CloseHandle(+0x54), zero ✓
- Offsets +0x54 (handle), +0x5c (validFlag) confirmed ✓

## FUN_0057EE80 — PASS

Source: docs/01-engine-architecture.md (line 12146)
- WaitForSingleObject on mutex at +0xad8 ✓
- Walk list at +0xac8, FUN_0057b840 compare ✓
- FUN_005871f0, store to *param_3, ReleaseMutex ✓

## FUN_00599C58 — PASS

Source: docs/01-engine-architecture.md (line 12442)
- SEH frame via FUN_0058a5d8 ✓
- Vtable setup, FUN_0059a8fa finalize ✓

## FUN_0059AD3D — PASS

Source: docs/01-engine-architecture.md (line 12980)
- FUN_00587b3e(FUN_00599796) — registers cleanup callback ✓

## FUN_0057A910 — PASS

Source: docs/01-engine-architecture.md (line 13516)
- Calls FUN_005855e0() ✓

## FUN_0059CB48 — PASS

Source: docs/01-engine-architecture.md (line 13824)
- Calls FUN_00581880() ✓

## FUN_004780D0 — PASS

Source: docs/01-engine-architecture.md (line 14049)
- FUN_00461cd0(), if ==3: vtable+0x1c(0x17), else: vtable+0x1c(0x15) ✓
- Stores result at param_1+0xe0 ✓

## FUN_004BB460 — PASS

Source: docs/01-engine-architecture.md (line 14269)
- Frees param_1+4 if non-null ✓
- If bit 0 set: frees self ✓

## FUN_00559A30 — PASS

Source: docs/01-engine-architecture.md (line 14491)
- Calls FUN_005596e0() ✓

## FUN_00587930 — PASS

Source: docs/01-engine-architecture.md (line 14951)
- Virtual type resolution, byte read + size calc ✓
- Dword-aligned copy, children via FUN_00587510 ✓
- FUN_00585400 finalize ✓

## FUN_00587090 — PASS

Source: docs/01-engine-architecture.md (line 15401)
- FUN_00587490(param_2+4), field copies ✓
- Vtable: PTR_FUN_005b8c30 ✓

## FUN_0059C706 — PASS

Source: docs/01-engine-architecture.md (line 15768)
- Reads *(unaff_EBP+8), FUN_00587bcf() ✓

## FUN_0059C670 — PASS

Source: docs/01-engine-architecture.md (line 16174)
- Reads *(unaff_EBP+8), FUN_00587bcf() ✓

## FUN_0059CC88 — PASS

Source: docs/01-engine-architecture.md (line 16519)
- Calls FUN_00582f60() ✓

## FUN_0059CD80 — PASS

Source: docs/01-engine-architecture.md (line 16866)
- Calls FUN_005834c0() ✓

## FUN_004C8CA0 — PASS

Source: docs/01-engine-architecture.md (line 163) / docs/00-source-tree.md
- Profile trace, FUN_004c8180, FUN_004c7e80, FUN_004c8a10, FUN_00418a60 ✓
- Sound::Post() confirmed

## FUN_0057E410 — PASS

Source: docs/01-engine-architecture.md (line 17581)
- PeekMessageA loop, GetMessageA → TranslateMessage → DispatchMessageA ✓

## FUN_0040D2CA — PASS

Source: docs/01-engine-architecture.md (line 17966)
- Direction flag 0/1, wrap modulo VehicleCount ✓
- sub_40D240(vehicle+0x4894), sub_4F0D20(vehicle+12) ✓

## FUN_004BC2E8 — PASS

Source: docs/01-engine-architecture.md (line 18326)
- this[24] = 1 (offset +0x60) ✓

## FUN_0048B024 — PASS

Source: docs/01-engine-architecture.md (line 18651)
- Returns 0 unconditionally ✓

## FUN_0051126A — PASS

Source: docs/01-engine-architecture.md (line 18956)
- Full command dispatch table (1-254) verified against source ✓

## FUN_00408868 — PASS

Source: docs/01-engine-architecture.md (line 19310)
- Returns 1 unconditionally ✓

## FUN_004472A8 — PASS

Source: docs/01-engine-architecture.md (line 19681)
- this[7257] = 0 (byte at +0x1C59) ✓

## FUN_004D4A58 — PASS

Source: docs/01-engine-architecture.md (line 20070)
- Sets result[1] (+4) = 4 ✓
- Sets result[2] (+8) = 0 ✓
- Returns result ✓

## FUN_004D1027 — FAIL

Source: docs/01-engine-architecture.md

**Errors:** [NO_DOC_ENTRY]

No `## FUN_004D1027` entry found in docs/01-engine-architecture.md. Source shows: *this = a2, returns a2.

**Corrected entry:**
<!-- target: docs/01-engine-architecture.md -->
## FUN_004D1027 — Field Setter Wrapper

Source: IDA Hex-Rays. Stores param a2 into *this, returns a2.

**Key logic:**
- *this = a2
- Returns a2

**Calls:** none
**Moddability:** hardcoded

## FUN_0048A650 — PASS

Source: docs/01-engine-architecture.md (line 20699)
- sub_498880, vtable bounds (+24/+28/+32/+36) ✓
- Flags at +324/+325/+326 ✓
- Above/below/within thumb zone logic ✓
- sub_489500, sub_489530, sub_489560, sub_4895B0 ✓
- sub_489E90, sub_489F40, sub_49A490 ✓
- vtable+64 dispatch, vtable+152 refresh ✓

## FUN_0053C1B0 — PASS

Source: docs/01-engine-architecture.md (line 21050)
- FUN_00587b3e(&LAB_0053c1c0) ✓
