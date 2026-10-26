# Cross-Validation Results: worker_F_B

## FUN_004866AD — PASS
UI Widget Property Propagator. All claims verified against source:
- Sets *(BYTE*)(a2+101) = a1 ✓
- Walks child linked list from a2+144 ✓
- Vtable dispatch at offset 44 (alloc) and 60 (propagate) ✓
- Calls sub_486320 for linked list traversal ✓

## FUN_0054FD46 — PASS
Object State Setter (this[24]). All claims verified:
- this[24] = a2 ✓
- Returns a2 ✓
- 10-byte trivial setter ✓

## FUN_00502102 — PASS
AssertFailHandler. All claims verified:
- Calls sub_58A770(a1, 1) ✓
- Triggers __debugbreak() ✓
- Moddability: hardcoded ✓

## FUN_0049E663 — PASS
SetFourDwords. All claims verified:
- a2[20] = result (+0x50) ✓
- a2[21] = result (+0x54) ✓
- a2[22] = result (+0x58) ✓
- a2[23] = result (+0x5C) ✓

## FUN_005816B0 — PASS
Thread Pool Job Dequeue by Type. All claims verified against source:
- this[694] as mutex handle ✓
- this[695] as timeout, WaitForSingleObject ✓
- Linked list from this[690], traversal at this[692] ✓
- Job data at [0], next node at [1] ✓
- sub_5871F0 for type check against a2 ✓
- sub_57B800 to process matched job ✓
- ReleaseMutex on v4[4] ✓
- Returns 1 if job found, 0 otherwise ✓

## FUN_0059A6FE — PASS
GetterOrFallback. All claims verified:
- Returns this[4] if non-null ✓
- Returns &unk_5B9D34 if null ✓

## FUN_0059880B — PASS
PhysicsThunk. All claims verified:
- Passes 4 args to sub_598775 ✓
- Returns result of sub_598775 ✓

## FUN_00406B60 — PASS
MenuSelectSetter. All claims verified:
- this[21] = a2 ✓
- Returns a2 ✓

## FUN_0042B8D0 — FAIL
**ERROR: Struct claim invalid** — param_1 is `int` enum selector (0-3), NOT struct pointer. Confirmed by docs/13-audit-report.md: "MAJOR CONFLICT — param_1 in FUN_0042b8d0 is used as an integer selector... NOT a struct pointer". Source shows param_1 compared to 3, used as switch selector. String constants "Upshifts"/"Downshifts"/"Disallowed" are **string constants for display**, not struct field reads.

**Corrected entry:**
Source: ai_db.cpp. Selects shift pattern string ("Upshifts", "Downshifts", "Disallowed") based on param_1 (enum 0-3) and ring buffer index from *param_2. Displays result.

**Key logic:**
- param_1 is integer selector (0-3) for shift pattern type
- Calls FUN_004b15d0(param_1) for shift validation
- Uses global string arrays (DAT_005c32b0, DAT_005c32bc, DAT_005c32cc) for "Upshifts"/"Downshifts"/"Disallowed"
- Copies selected string to DAT_005ec4cc message buffer via FUN_00423a00
- Displays via FUN_0045bd10(local_80, 3, 0x1020304) — priority 3
- Also calls FUN_0045bdf0() and FUN_00438cc0() for post-display cleanup

**Globals:** DAT_005ec4cc (display buffer), DAT_005c32d8 (string suffix terminator), s_Upshifts_005c32b0, s_Downshifts_005c32bc, s_Disallowed_005c32cc

**Calls:** FUN_004b15d0 (shift validation), FUN_00423a00 (string compare/copy), FUN_0045bd10 (display, priority 3), FUN_0045bdf0, FUN_00438cc0

**Moddability:** hardcoded

## FUN_00424C80 — PASS
AI Ring Buffer Field Init. All claims verified:
- Reads DAT_008aae70 (ring buffer counter), increments ✓
- Formula: (ringBufferTable[counter & 0xff] * _DAT_0059e868 + _DAT_0059e868) - (float)DAT_007d01a0 * _DAT_0059e444 * _DAT_0059e84c ✓
- Stores result at param_1 + 0x4448 ✓
- Globals: DAT_008aae70, DAT_008aae74, DAT_007d01a0 ✓

## FUN_004BEB10 — PASS
AI Overtake / Collision Detection Loop. All claims verified:
- param_1[0xd5] += param_1[0xd4] (accumulator) ✓
- Main vehicle loop: position delta, distance via FUN_004bea10 ✓
- Collision type 0: clean overtake, increments +0x403c, calls FUN_004bf390 ✓
- Collision type 1/2: contact via FUN_004b33b0 audio dispatch ✓
- Calls FUN_004bf4f0 when no collisions ✓
- Callees: FUN_004bf0a0, FUN_004bea10, FUN_004bef60, FUN_004bf390, FUN_004b33b0, FUN_004bf4f0 ✓

## FUN_004144F0 — PASS
Driver Data Table Lookup and Time Conversion. All claims verified:
- param_1[4]=param_3, param_1[6]=param_5, *param_1=param_2, param_1[5]=param_4, param_1[7]=param_6 ✓
- If param_6==-1: param_1[7] from DAT_005bf9a0 + param_2*0x14 ✓
- If param_8==_DAT_0059e7f0: param_8 from DAT_005bf9a4 + param_2*0x14 ✓
- __ftol + _DAT_0059e7e8 scaling ✓
- If param_8==_DAT_0059e670: param_1[3] = -0x40800000 ✓
- Else: param_1[3] = (int)(scaled + param_8 + _DAT_0059e7e8) ✓
- Globals: DAT_005bf9a0, DAT_005bf9a4, _DAT_0059e7f0, _DAT_0059e7e8, _DAT_0059e670 ✓

## FUN_004537B0 — PASS
Tire Compound Struct Layout (brief entry). Verifies brief description:
- Reads tire state from vehicle struct (param_1) at offsets +0x1140..0x115c (front, 8 floats) and +0x153c..0x1558 (rear, 8 floats) ✓
- Broadcasts to global HUD/timing state variables (40+ DAT_ globals written) ✓
- Reads compound selection ints at +0x1170..0x117c (front) and rear via +0x1170..0x117c (rear flags path) ✓
- Reads pit stop flag bitmask at +0x1180 (front) and +0x157c (rear) ✓
- Compares compound ints against comparison globals for HUD display ✓
- Note: +0x1140 and +0x153c are `float[8]` not `double[8]` as stated in docs/13 (known audit finding, not in this brief doc entry)

## FUN_004BA1F0 — PASS
Replay Playback Loader (Prepping Replay). All claims verified:
- State machine: *param_1 == 0/1 (condition checks on DAT_007d0038/DAT_007d005c) ✓
- State 2: active loading phase with assert, file open, message display ✓
- "Prepping Replay", "Loading VCR File for playback" strings confirmed ✓
- FUN_004d7a50 assert, FUN_00566b20 file open, FUN_00423a00 string copy ✓
- FUN_004a0e70 message display, Sleep(250ms) ✓
- operator_new(0x80), FUN_004b9830 buffer init ✓
- Loop: FUN_00566c00/FUN_00566bd0 packet streaming ✓
- Post-load: FUN_004b9820, FUN_0042bbd0, FUN_0042bc40 ✓
- FUN_004b87a0/FUN_004b86e0 replay data init ✓
- All callees verified ✓

## FUN_00469D30 — PASS
Player Stats Display Cleanup. All claims verified:
- Frees linked list at param_1+0x44 (walks +0x4/0x8/0xc nodes) ✓
- Clears +0x44 through +0x50 ✓
- Labels: "Circuit:", "Experience (Laps):", "Best Lap:" via FUN_00486f30 ✓
- Calls FUN_00489cb0, FUN_00469900, FUN_0048a3b0(0) ✓

## FUN_0046B9B0 — PASS
Loading Grid Screen. All claims verified:
- FUN_00489cb0 reset HTML buffer ✓
- param_1+0x178 = -1 ✓
- If DAT_007d0410 == 5: copies "Loading Grid..." to DAT_005ec4cc via FUN_00423a00 ✓
- FUN_00489600 output HTML ✓

## FUN_0041AD80 — PASS
Overtake / Position Swap. All claims verified:
- Guards on DAT_007d0308, DAT_007cf3c8, DAT_007c56a8 ✓
- Reads team IDs via +0x4894 ✓
- Lap time delta at +0x4fc ✓
- Overtake gap at +0x69c, target at +0x83c ✓
- FUN_004f0050 random calls (x2) ✓
- Commentary ID 0x72 (passed), 0x73 (was passed), 0xe1/0xe2 (general overtake) ✓
- Calls: FUN_004f0050, FUN_004144d0, FUN_004144f0 (line 85), FUN_00418560 (line 86) ✓

## FUN_0049D5D0 — PASS
HUD_TachoRenderDispatch. All claims verified:
- Switch on DAT_007ce048 display mode ✓
- Cases 0-4 route to sub-renderers: case 0 sub-router by SessionType, case 1->FUN_0049e3e0, case 3->FUN_0049e170, case 4->FUN_0049db80 ✓
- Case 2: full tacho via FUN_0049de40 ✓
- Guard checks on param_1+0x14, +0x18, +0x8 (data pointers) ✓
- Sub-dispatch by SessionType (DAT_007c56a4) for case 0 ✓

## FUN_004BC340 — PASS
Session Type Condition Check. All claims verified:
- Complex condition on DAT_007c569c, DAT_007c56a4, DAT_007c56a8, DAT_007cef84 ✓
- Returns 1 or masked (uVar1 & 0xffffff00) ✓

## FUN_004D21D0 — PASS
Race Phase Check. All claims verified:
- switch(DAT_007c56a8): cases 0-4 return 0, default return 1 ✓

## FUN_004FF1D0 — PASS
Audio Filter Parameter Calculation. All claims verified:
- Reads linked list head from param_1+0x38 ✓
- Session type threshold: _DAT_005ad338 (default), _DAT_005ad33c (if DAT_007c56a4==7) ✓
- Iterates list tracking min/max of pfVar2[2] ✓
- Computes average * _DAT_0059e450 + param_1+0x104 (stored offset) ✓
- If <0: calls FUN_004feaa0(0) (mute) ✓
- If >1.0: clamps to 1.0 ✓
- Calls FUN_004feaa0(computed) ✓
- Calls FUN_004ff0e0 if list is null ✓

## FUN_0046FE80 — PASS
Session Flag Pointer Selector. All claims verified:
- FUN_0048fe60() init call ✓
- Sets param_1[0x3b]=0, param_1[0x3c]=0xffffffff, *param_1=&PTR_FUN_005a01a0 ✓
- Switch map: 1->&DAT_007ceb64, 2->&DAT_007ceb7c, 3->&DAT_007ceb94, 4->&DAT_007cebac, 5->&DAT_007cebc4, 6->&DAT_007cebdc, default->0 ✓

## FUN_00420490 — PASS
Position Change Detector. All claims verified:
- Gets current leader via FUN_004c2850/FUN_004c1390 ✓
- Compares puVar11[0x66] (stored position) against other drivers' +0x198 (position) ✓
- Uses FUN_004c1370, FUN_004c13a0 for driver iteration ✓
- Calls FUN_004144d0, FUN_004144f0, FUN_00418560 for commentary ✓

## FUN_0058C9B4 — PASS
File handle read wrapper. All claims verified:
- Validates param_1 < DAT_008d4a20 (handle table size) ✓
- Checks flag bit at (&DAT_008d4920)[index>>5] + 4 + (index&0x1f)*0x24 ✓
- Lock: FUN_00595a61, Read: FUN_0058ca19, Unlock: FUN_00595ac0 ✓
- Error: errno=9 (EBADF) on invalid handle ✓

## FUN_0055CA90 — PASS (triage entry)
State sync with vtable callbacks. Triage-level entry verified:
- Size 386 bytes, 87 lines ✓
- Uses param_1[0x440] vtable dispatch at +0x7c ✓
- Flag checks on param_2+0x18 (0x40000, 0x200000) ✓

## FUN_00588640 — PASS
strncmp — CRT library function. Verified:
- Standard strncmp implementation ✓
- Library function, single match ✓

## FUN_0059045F — PASS (triage entry)
Character classification / symbol lookup. Verified:
- Calls via DAT_008d3fb8 function pointer ✓
- Uses FUN_005905dd for lookup verification ✓
- Compares locale data via DAT_008d3fa8 ✓

## FUN_0044B110 — PASS
ConstraintValidator3Way. All claims verified:
- Initializes via FUN_00448ee0, FUN_0044af20, FUN_0044b040 ✓
- Iterates 3 slots (0-2), tests each with FUN_0044b090 ✓
- Cross-check when <2 slots valid (forced swap) ✓
- Returns local_88 (valid slot index) or 0 on failure ✓
- Struct offset: base+0x10+idx*0x5c per-slot data block ✓
- Callees: FUN_00448ee0, FUN_0044af20, FUN_0044af60, FUN_0044b040, FUN_0044b090 ✓

## FUN_00509CC2 — PASS
Texture Decode: 8-bit Alpha-Only Format. All claims verified:
- Row-major pixel offset computation ✓
- Each byte: R=0, G=0, B=0, A=byte * _DAT_0059e460 ✓
- Calls FUN_00507845 if param_1+0x10 != 0 ✓
- Global _DAT_0059e460 ✓

## FUN_00509C20 — PASS
RGB 3-3-2 to Float Texture Decompress. All claims verified:
- R = (*pbVar2 >> 5) * _DAT_005ad210 ✓
- G = (*pbVar2 >> 2 & 7) * _DAT_005ad210 ✓
- B = (*pbVar2 & 3) * _DAT_0059e98c ✓
- A = 1.0 ✓
- Calls FUN_00507845 if param_1+0x10 != 0 ✓
- Globals: _DAT_005ad210, _DAT_0059e98c ✓

## FUN_004E2130 — PASS
ChassisWorldTransform. All claims verified:
- Rotation matrix at +0x20 to +0x40 (3x3 float, column-major) ✓
- Local vector at +0x918 to +0x920 (3 floats) ✓
- World position: rotation * local + chassis_position (+0x8, +0xc, +0x10) ✓
- Orientation quaternion from +0x14 to +0x1c copied to param_3 ✓

## FUN_004ED810 — PASS
Wheel/Tire Force Update (4-Wheel Loop). All claims verified:
- Reference delta from _DAT_008afef0 + _DAT_005acafc ✓
- Loop count = 4 ✓
- pfVar4 starts at +0x35dc, advances by 0x3e floats (0xF8 bytes/wheel) ✓
- Duplicate storage at +0x36d4 (front) and +0x38c4 (rear) ✓
- Clamp: (value - _DAT_0059eec8) * _DAT_0059eec0 ✓
- Range: [DAT_0059e440, _DAT_0059e43c] ✓
- Uses ABS(*(param_1+0x3500)) for steering influence ✓
- Globals: _DAT_008afef0, _DAT_005acafc, _DAT_0059e450, _DAT_0059eec8, _DAT_0059eec0, DAT_0059e440, _DAT_0059e43c ✓

## FUN_004B9CB0 — PASS
Vehicle Lifetime Average Accessor. All claims verified:
- Dereferences *param_1 (vehicle pointer) ✓
- Reads float at +0xf30 ✓
- Returns float10 ✓

## FUN_004A5E40 — PASS
State-Conditional Action. All claims verified:
- Checks param_1+0x184 for 0 or 4 ✓
- If match: calls FUN_004a5c80(1) ✓

## FUN_0054C210 — PASS
Scene Graph Child Count. All claims verified:
- Traverses list from param_1+0x204 via next at +0x10 ✓
- Returns count ✓

## FUN_0054E100 — PASS
PackedArrayTotalSize. All claims verified:
- Count at param_1+0x118 ✓
- Records at param_1+0x11c, stride 0x10 ✓
- Sums int at offset +8 per record ✓

## FUN_0054C410 — PASS
QueueResourceCleanup. All claims verified:
- FUN_00545f40() global pre-cleanup ✓
- Array at param_1+0x11c, count at +0x118, stride 0x40 ✓
- Calls FUN_00547710 (release), zeros ptr, FUN_00540cb0 (free) per entry ✓
- Linked list at param_1+0x13c: FUN_005511a0 + FUN_00587bcf per node ✓
- Refcounted block at param_1+0x110: loops FUN_004b0170 ✓
- Block at param_1+0x144: FUN_004b0170 ✓

## FUN_004B6130 — PASS
Sprite/Overlay List Cleanup. All claims verified:
- Reads *(param_1+0x9b0) as list pointer ✓
- Count at *(iVar1-4) (embedded before allocation) ✓
- Loops calling FUN_004b46f0 ✓
- Frees via FUN_00587bcf ✓
- Zeros +0x9b0 and +0x9b4 ✓

## FUN_0052E2F0 — PASS
Lap/Performance State Reset. All claims verified:
- +0x249c -> +0x24e8 (lap reference copy) ✓
- Zero +0x24ac, +0x24a8 (accumulators) ✓
- Zero +0x24e4, +0x24b4 (delta/adjustment) ✓

## FUN_004F6850 — PASS
RandomOffsetCalculator. All claims verified:
- If param_1+0x56c == 0: FUN_005881f0() * *(double*)(param_1+0x578) ✓
- Always adds *(double*)(param_1+0x570) (base offset) ✓

## FUN_004E4930 — PASS
Vehicle physics mode dispatcher. All claims verified:
- Read mode at param_1+0x32bc ✓
- 0 (wet): FUN_004a6e50 + FUN_00441650, stores param_2 at +0x34ac, FUN_004e49b0 ✓
- 1 (dry): FUN_004a6e50 + FUN_004e4e60 ✓
- 2 (setup): stores param_2 at +0x34ac, FUN_004f03e0 ✓

## FUN_004F17A0 — PASS
Effect Parameter Setter. All claims verified:
- param_1+0x3994 = param_2 ✓
- param_1+0x3570 = param_4 ✓
- param_1+0x3978 = param_3 * param_1+0x397c ✓

## FUN_00545030 — PASS
Doubly-Linked List Tail Insertion. All claims verified:
- Walks list from param_1+0xf8 via +0x1b8 (next) pointers ✓
- If list empty: param_1+0xf8 = param_2 ✓
- If non-empty: appends at tail, sets +0x1b4 (prev) and +0x1b8 (next) ✓
- New node: next=0, prev=old tail ✓

## FUN_00545850 — PASS
ClearBuffersLoop (resource buffer flush). All claims verified:
- First loop: walks param_1+0x100 (next at +0x104), sub-list at +0xec (next at +0x4c) ✓
- Second loop: walks param_1+0x108 (next at +0x4c) ✓
- Calls FUN_0054b330(0,0x20,0) and FUN_0054b2c0(0,0x10000000,0) ✓

## FUN_004D1A50 — PASS
ParseMidiBitstream. All claims verified:
- Checks (*param_2 & 0xfc0000) == 0x280000 header pattern ✓
- Loops FUN_004d0f00(0) for param_1+0x10c iterations ✓
- Extracts 9-bit count from param_2>>9 & 0x1ff ✓
- Loops reading 6-bit values (ushort & 0x3f), calls FUN_004d0f00 ✓

## FUN_004D1CF0 — PASS
Ring Buffer Access with Wrap. All claims verified:
- __ftol(param), subtracts 1 ✓
- Modulo wrap by +0x10c (buffer size) ✓
- Clamps to [0, size-1] ✓
- Returns element from +0x110 (stride 8) ✓

## FUN_0042ED00 — PASS
SessionStateIndexedLookup. All claims verified:
- Reads value at param_1[param_2*0x40 + 0xbc4] ✓
- Passes through FUN_0042dd00 with param_1+0x1644 ✓
- If param_2 == 0x2b (43): negates result ✓
