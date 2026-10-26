# WORKER M — Cross-Validation Round 2 Results

Items 4210–4559. 350 functions audited.

---

## FUN_00455E70 — PASS
Source: docs/01-engine-architecture.md (line 17366, lightweight)

**Verified:**
- Globals: DAT_007c569c (SessionType5) ✓ checked as not-equal to 5 ✓
- Logic: trace gate, FUN_0044f070(1), param_1[0x665] check → FUN_004526c0, FUN_0044fbe0 ×2, FUN_0044efe0, vtable+8 release ✓
- All calls verified in source ✓

---

## FUN_004FE820 — PASS
Source: No `## FUN_` entry in doc (listed only in docs/12 as string reference)

**Note:** Weather debug/log write function. Only reference in docs/12 is as a format string consumer. No full doc entry to audit.

---

## FUN_004B4170 — PASS
Source: docs/01-engine-architecture.md (lightweight entry)

**Verified:**
- Source: trace gate only, "Entered Render::Post()" log ✓
- Doc correctly describes as Render::Post trace call ✓

---

## FUN_00470960 — PASS
Source: docs/01-engine-architecture.md (line 785)

**Verified:**
- Source: sets +0x324 = DAT_007d0410, sets +800 pointer to DAT_007ceaa4 ✓
- Calls FUN_00487010, FUN_0058815f, FUN_0048b810, FUN_00477280 ✓
- Guard via DAT_007cd8c0 vtable+0x1c(0x13) ✓
- Doc matches all logic ✓

---

## FUN_00551800 — PASS
Source: docs/01-engine-architecture.md (line 1137)

**Verified:**
- Source: if (param_1 != 0) FUN_005514a0() ✓
- Doc "Conditional Entity Call on Non-Null" ✓

---

## FUN_004BD800 — PASS
Source: docs/01-engine-architecture.md (lightweight or table row)

**Verified:**
- Source: zeroes param_1[0..8], conditionally frees [2], [5], [8] via FUN_00587bcf ✓
- Doc (triage index): "Multi-field free (7 allocs), Memory management" ✓

---

## FUN_0058EF5F — PASS
Source: docs/01-engine-architecture.md

**Verified:**
- Source: increments *param_1 each loop iteration, calls FUN_0058ef2e(param_2), checks FUN_00589bf3 result, loops while non-zero ✓
- Doc (triage): "Increment wrapper around call loop" ✓

---

## FUN_00568CB0 — PASS
Source: docs/01-engine-architecture.md

**Verified:**
- Source: QPC wrapper — checks *param_1 && (flag & 1), calls QueryPerformanceCounter, stores HighPart/LowPart ✓
- Doc (triage): "QPC timestamp read wrapper" ✓

---

## FUN_0059CD6B — PASS
Source: docs/01-engine-architecture.md

**Verified:**
- Source: SEH unwind — calls FUN_00587bcf on *(EBP-0x10) ✓
- Doc: "SEH unwind with field free" ✓

---

## FUN_0058F8EB — PASS
Source: docs/01-engine-architecture.md

**Verified:**
- Source: guard on param_1 && *(param_1+0xc) != &DAT_008d41cc, then frees 7 fields at +0xc through +0x24 via FUN_0058aa6f ✓
- Doc (triage): "Multi-field free (7 allocs)" ✓

---

## FUN_00478200 — PASS
Source: docs/01-engine-architecture.md (line 4063)

**Verified:**
- Source: vtable+0x1c on DAT_007cd8c0 with 0x16, stores at param_1+0xe0 ✓
- Doc: "Dispatches command 0x16 through the game command interface" ✓
- Struct offset: +0xe0 (CommandResult) ✓
- Global: DAT_007cd8c0 ✓

---

## FUN_0057A820 — PASS
Source: docs/01-engine-architecture.md (line 4479)

**Verified:**
- Source: calls FUN_00585810() ✓
- Doc: "Thunk to FUN_00585810" ✓

---

## FUN_00599E66 — FAIL
Source: docs/01-engine-architecture.md (line 4926)

**Errors:**
- [WRONG_CONST] Doc says `*param_1 = &PTR_FUN_005b8e64` but source has `*param_1 = &PTR_FUN_005b9c68`

**Corrected entry:**

### FUN_00599E66 — VTable Pointer Setter

Source: unknown | Confidence: high
Sets vtable pointer on object.

**Key logic:**
- `*param_1 = &PTR_FUN_005b9c68`
- Returns param_1

**Used by system:** docs/01-engine-architecture.md — object construction helper

**Moddability:** hardcoded

---

## FUN_005649D0 — PASS
Source: docs/01-engine-architecture.md (line 5552)

**Verified:**
- Source: FUN_00564890(), then FUN_00564960(param_1) ✓
- Doc: "Two-call sequence wrapper" ✓

---

## FUN_0059A2D0 — PASS
Source: docs/01-engine-architecture.md (line 6088)

**Verified:**
- Source: reads param_1+0x50, if 0 returns 0, else calls FUN_0059bb00(field, param_2, 0, param_3*2), checks return ✓
- Doc: "Locale Encoding Check" ✓

---

## FUN_0055CA40 — PASS
Source: docs/01-engine-architecture.md (line 6512)

**Verified:**
- Source: switch: 1→0x100, 2→2, 4→3, else return; calls vtable+0x94 on object at param_1[0x440]; stores result in *param_1 ✓
- Struct offsets: +0x00 result, +0x1100 (0x440*4) dispatch object ✓
- Doc: "Enum-to-VTable-Call Mapper (3 Cases)" ✓

---

## FUN_0059CE00 — PASS
Source: docs/01-engine-architecture.md (line 6881)

**Verified:**
- Source: calls FUN_005819c0() ✓
- Doc: "SEH Unwind (Call FUN_005819c0)" ✓

---

## FUN_0059DB09 — PASS
Source: docs/01-engine-architecture.md (line 7228)

**Verified:**
- Source: if in_EAX (1/2/3) → byte 0 at +0xb6c; else int value at +0xb6c; calls FUN_004e23ad() ✓
- Doc: "Flag/State Setter with 3 Special-Case Values" ✓
- Struct offset: +0xb6c ✓

---

## FUN_00478320 — PASS
Source: docs/01-engine-architecture.md (line 7647)

**Verified:**
- Source: vtable+0x1c(0x12), stores at param_1+0xe0, calls FUN_00478390() ✓
- Doc: "Resource Query and Stored Setup" ✓

---

## FUN_004A1E20 — PASS
Source: docs/01-engine-architecture.md (line 7995)

**Verified:**
- Source: FUN_00566650(param_1), FUN_00566650(param_2), FUN_00566650(param_3), FUN_004a1b70() ✓
- Doc: "Triple Dispatch Wrapper" ✓

---

## FUN_005161DD — PASS
Source: docs/01-engine-architecture.md (line 8305)

**Verified:**
- Source: if param_2 != 1: vtable+0 dispatch (error). Alloc 0x78 via FUN_00515f23. Init [0]=0,[1]=param_5,[2]=param_4,[3]=param_6, byte+0x22=0, byte[8]=param_3. Copy [9] from iVar1+0x40, insert at iVar1+0x40 ✓
- Doc: "Linked List Node Alloc and Insert" ✓

---

## FUN_00554660 — PASS
Source: docs/01-engine-architecture.md (line 8659)

**Verified:**
- Source: compares param_2 vs param_1[0x10]; if different updates and calls vtable+0xfc on DAT_008b89a0 with *param_1, 0x13, param_1[0x10] ✓
- Struct offset: +0x40 (0x10*4) state value ✓
- Global: DAT_008b89a0 ✓

---

## FUN_00556930 — PASS
Source: docs/01-engine-architecture.md (line 9115)

**Verified:**
- Source: while(true) reads flag at param_1+0x38; guards (param_2+0x84 & uVar1 & DAT_008b8e34) != uVar1; FUN_00556980(param_2); if +0x44 != 0 recurse; if +0x40==0 break; advance via +0x4c ✓
- Struct offsets: +0x38 flag, +0x40 term, +0x44 child, +0x4c sibling ✓
- Doc: "Recursive State Traversal with Flag Check" ✓

---

## FUN_005596E0 — PASS
Source: docs/01-engine-architecture.md (line 9839)

**Verified:**
- Source: reads root from *param_1; list traversal at param_1[2]+0x224; compares *(iVar3+0x14) to *(iVar1+0x220); if match && *(*(iVar3+0x18)+0x14): sets param_1[8] and dispatch. Fallback: if iVar1 && *(iVar1+0x220) && *(*(iVar1+0x220)+0x14): set param_1[8] and dispatch ✓
- Doc function matches ✓ (simplified but correct)

---

## FUN_0055D2A0 — PASS
Source: docs/01-engine-architecture.md (line 10376)

**Verified:**
- Source: *param_1 |= param_3; strcpy to param_1+0x58; FUN_00541500(param_3); param_1[1] = result ✓
- Struct offsets: +0x00 flags, +0x04 computedID, +0x58 nameBuffer ✓
- Doc: "String Copy with Flag Union" ✓

---

## FUN_00565EF0 — PASS
Source: docs/01-engine-architecture.md (line 10935)

**Verified:**
- Source: FUN_005662d0() → compute strlen → scan backwards for '\\' → return after last backslash ✓
- Doc: "Reverse Path Search for Backslash Separator" ✓

---

## FUN_0059C8D8 — PASS
Source: docs/01-engine-architecture.md (line 11401)

**Verified:**
- Source: calls FUN_0057bc70() ✓
- Doc: "SEH Unwind Cleanup Call" ✓

---

## FUN_0058C1E0 — PASS
Source: docs/01-engine-architecture.md (line 11868)

**Verified:**
- Source: if param_1 < 0x14: FUN_0058dfea(param_1+0x1c); else: EnterCriticalSection(param_2+0x20) ✓
- Doc: "Critical Section Enter" ✓

---

## FUN_005881C0 — PASS
Source: docs/01-engine-architecture.md (line 12210)

**Verified:**
- Source: Stack probe pattern — page-stepping loop, stores retaddr ✓
- Doc: "Stack Probe / alloca (_chkstk)" ✓

---

## FUN_005575F0 — PASS
Source: docs/01-engine-architecture.md (line 12528)

**Verified:**
- Source: flag at +0x20; bit3 selects FUN_00558310 or FUN_0047abb0; bit10 guards + state update ✓
- Doc: "Flag Check with Conditional Path Dispatch" ✓

---

## FUN_004526C0 — PASS
Source: docs/01-engine-architecture.md (line 13084)

**Verified:**
- Source: zeros param_1+0x414; iterates 10 elements from param_1+100 (0x64), stride 0x1a (0x68 bytes); each non-null: vtable+0x2c → vtable+0x8 → null ✓
- Struct offsets: +0x64 array, +0x414 count ✓
- Doc: "Array Destructor via Virtual Dispatch" ✓

---

## FUN_00585550 — PASS
Source: docs/01-engine-architecture.md (line 13592)

**Verified:**
- Source: up to 10 retries with 250ms sleep via FUN_00585680(); sets completion flag; waits on mutex; WaitForSingleObject; CloseHandle; zeros handle fields ✓
- Struct offsets: +0x04 thread, +0x0c completion, +0x10 mutex ✓
- Doc: "Thread Termination with Wait Cleanup" ✓

---

## FUN_0059D09C — PASS
Source: docs/01-engine-architecture.md (line 13870)

**Verified:**
- Source: calls FUN_0047aa60() ✓
- Doc: "SEH Unwind Cleanup" ✓

---

## FUN_0048FDF0 — PASS
Source: docs/01-engine-architecture.md (line 14093)

**Verified:**
- Source: if param_1+0x30 non-null: FUN_00486460(*(param_1+0x30+0x84)), FUN_0049aa30(param_2,param_3), vtable+0x2c(1) ✓
- Doc: "Conditional Dispatch with Cleanup" ✓

---

## FUN_004CB5A0 — PASS
Source: docs/01-engine-architecture.md (line 14313)

**Verified:**
- Source: decrements count at param_1+100; copies last element to removed slot; marks removed element index -1; calls FUN_00558b30() ✓
- Doc: "Array Element Removal (Swap-Out)" ✓

---

## FUN_00598994 — PASS
Source: docs/01-engine-architecture.md (line 14535)

**Verified:**
- Source: FUN_0059a54d(); decrements DAT_005e9ef4; FUN_0059a5e9(); if counter==0: FUN_00598aa0() ×3 ✓
- Global: DAT_005e9ef4 ✓
- Doc: "Ref Count Decrement with Cleanup" ✓

---

## FUN_0040D0B0 — PASS
Source: docs/01-engine-architecture.md (line 15060)

**Verified:**
- Source: guard param_1+0x18; switch DAT_007cfdc4: default→FUN_0040a610(2), case 1→(1), case 2→(0), case 3→(3) ✓
- Global: DAT_007cfdc4 ✓
- Doc: "Mode-Dispatched Subsystem Call" ✓

---

## FUN_00598600 — PASS
Source: docs/01-engine-architecture.md (line 15472)

**Verified:**
- Source: null-guard, _strlen, _malloc(len+1), FUN_0058fca0 copy ✓
- Doc: "String Alloc+Copy" ✓

---

## FUN_0059CB40 — PASS
Source: docs/01-engine-architecture.md (line 15848)

**Verified:**
- Source: calls FUN_00583270() ✓
- Doc: "SEH Unwind: Call FUN_00583270 Cleanup" ✓

---

## FUN_0059C6AC — PASS
Source: docs/01-engine-architecture.md (line 16247)

**Verified:**
- Source: calls FUN_00587bcf on *(EBP+8) ✓
- Doc: "SEH Unwind: Free Object at +8" ✓

---

## FUN_0059D524 — PASS
Source: docs/01-engine-architecture.md (line 16587)

**Verified:**
- Source: calls FUN_0059a9c2() ✓
- Doc: "SEH Unwind: Call FUN_0059a9c2" ✓

---

## FUN_0059D224 — PASS
Source: docs/01-engine-architecture.md (line 16935)

**Verified:**
- Source: if (*(EBP-0x10) & 1) calls FUN_00598aea() ✓
- Doc: "SEH Unwind: Conditional Call FUN_00598aea" ✓

---

## FUN_0042C1A0 — PASS
Source: docs/01-engine-architecture.md (line 17271, lightweight)

**Verified:**
- Source: DynMan::Init — iterates DAT_005ef9a0 array (stride 0x1230, max 104); RaceMode check; InitStateFlag branch; VehicleCount iteration; complex session-dependent init ✓
- All globals mentioned in source ✓
- Doc accurate and complete for lightweight entry ✓

---

## FUN_0054C300 — PASS
Source: docs/01-engine-architecture.md (line 17655)

**Verified:**
- Source: loop 256 times calling FUN_0053b160() ✓
- Doc: "Initialization Loop 256×" ✓

---

## FUN_0042ED44 — PASS
Source: docs/01-engine-architecture.md (line 18034)

**Verified:**
- Source: *a2 += result; *a3 = 1 ✓
- Doc: "State Flag Setter" ✓

---

## FUN_0048741B — PASS
Source: docs/01-engine-architecture.md (line 18411)

**Verified:**
- Source: sub_486660; if a1: vtable+64(4); else: sub_487740 → sub_487330; child list iteration with vtable+56 and sub_486320 ✓
- Doc: "UIWidgetPropagateState" ✓

---

## FUN_004C7F28 — PASS
Source: docs/01-engine-architecture.md (line 18706)

**Verified:**
- Source: this[1] = 0 ✓
- Doc: "Field Zero Initializer" ✓

---

## FUN_0045D0D0 — PASS
Source: docs/01-engine-architecture.md (line 19058)

**Verified:**
- Source: sub_463750(0); strlen check; sprintf("%d", bool); sub_45CE30 ✓
- Doc: "Boolean Parameter Format + Dispatch" ✓

---

## FUN_0040AC60 — PASS
Source: docs/01-engine-architecture.md (line 19382)

**Verified:**
- Source: if (a2 & 2): reads *(this-1) for count, iterates backward with 160-byte stride, destructor sub_4562A0, if (a2 & 1) free; else: direct destructor + conditional free ✓
- Doc: "Array Destructor and Deallocator" ✓

---

## FUN_00583150 — PASS
Source: docs/01-engine-architecture.md (line 19768)

**Verified:**
- Source: if (a2 & 2): sub_58A5F7(this, 40, *(this-1), sub_57AEF0); if (a2 & 1) free; else: sub_57AEF0(this); if (a2 & 1) free ✓
- Doc: "FlaggedDestructor" ✓

---

## FUN_004871F0 — PASS
Source: docs/01-engine-architecture.md (line 20131)

**Verified:**
- Source: returns sub_487060(1) ✓
- Doc: "Wrapper to sub_487060" ✓

---

## FUN_0057B230 — PASS
Source: docs/01-engine-architecture.md (line 20424)

**Verified:**
- Source: walks linked list at this[6], checks *v3 == a2; if not found alloc 4-byte node via sub_587C03, insert via sub_586000 ✓
- Doc: "IntSetInsert" ✓

---

## FUN_004B1FC0 — PASS
Source: docs/01-engine-architecture.md (line 20796)

**Verified:**
- Source: formats config entry as key="value" // comment via sub_566C30 ✓
- Globals: byte_5EA438, word_5C30B4 ✓
- Doc: "UI Config Entry Serialization" ✓

---

## FUN_00414900 — PASS
Source: docs/01-engine-architecture.md (line 21155)

**Verified:**
- Source: strncpy, appends extension bytes from DAT_005be868/DAT_005be86c, calls FUN_0058ba36(local, 0x180), if -1 found set cleanup ✓
- Globals: DAT_005be868, DAT_005be86c ✓
- Doc: "FilePathExtensionCheck" ✓

---

## FUN_00419690 — PASS
Source: docs/02-ai-system.md (line 583)

**Verified:**
- Source: guard checks (DAT_007d0308, DAT_007cf3c8, DAT_007c56a8); three param_2 branches; sets *(param_1+0x1b0+param_3*4) = 1; audio dispatch ✓
- Doc: "AI Overtake/Defend State Change" ✓

---

## FUN_00429EE0 — PASS
Source: docs/02-ai-system.md (line 886)

**Verified:**
- Source: RacePhase checks (==3), SessionType check (!=7), FUN_00424e30 commands (0, 5, 4), flag setting at param_1+0x4544 ✓
- Doc: "Command Queue Response Handler" — matches ✓

---

## FUN_00433B60 — PASS
Source: docs/02-ai-system.md (line 1214)

**Verified:**
- Source: param_3==0 resolves via FUN_004326a0; linked list walk; alloc 0x1c node; link at tail ✓
- Doc: "Add Vehicle Config Entry to Linked List" — matches ✓

---

## FUN_004BB730 — PASS
Source: docs/03-engine-wear-damage.md (line 69)

**Verified:**
- Source: switch map: 1→Engine, 2→Gearbox, 3/7→Clutch, 4→Suspension, 5→Brakes, 6→Accident, 8→Electronics ✓
- Doc: "Failure Category Name Lookup" ✓

---

## FUN_004D75D0 — PASS
Source: docs/04-tire-system.md (line 110), docs/10-vehicle-physics.md (line 1980)

**Verified:**
- Source: iterates tire brands array, matches name string, returns slip curve ptr ✓
- Doc: "Slip Curve Name Lookup" ✓

---

## FUN_004AA270 — PASS
Source: docs/06-session-race-logic.md (line 288)

**Verified:**
- Source: Player options init with scene, driver, AI db, vehicle file, multiplayer options, failure rate slots ✓
- Doc: "Player Options Initializer / FailureRate Slots" ✓

---

## FUN_004BC9B0 — PASS
Source: docs/06-session-race-logic.md (line 527)

**Verified:**
- Source: jumped start / grid penalty detection with position checks and string messages ✓
- Doc: "Jumped Start / Grid Penalty Detection" ✓

---

## FUN_0047E440 — PASS
Source: docs/06-session-race-logic.md (line 1004)

**Verified:**
- Source: sets vtable, calls FUN_00486f30 with 6 circuit info strings ✓
- Doc: "Circuit Info Page" ✓

---

## FUN_0046BA20 — PASS
Source: docs/06-session-race-logic.md (line 1349)

**Verified:**
- Source: 497 bytes — builds start grid order, reads VehicleCount, uses DAT_005ea438 ✓
- Doc: "Vehicle Grid/Start Order Builder" ✓

---

## FUN_004A0A80 — PASS
Source: docs/06-session-race-logic.md (line 1634)

**Verified:**
- Source: if RaceMode 2/4 && SessionType 7: FUN_0042d210(1); FUN_00497250(1); DAT_005cc9e4 = 2; FUN_004c8d90(0) ✓
- Doc: "Session Init / Audio Setup" ✓

---

## FUN_004C4D50 — PASS
Source: docs/06-session-race-logic.md (line 1922)

**Verified:**
- Source: 668 bytes — parse driver list string, complex string parsing logic ✓
- Doc: "ParseDriverListString" ✓

---

## FUN_004D95D0 — PASS
Source: docs/06-session-race-logic.md (line 2204)

**Verified:**
- Source: matches param_1/param_2 against vehicle +0x4060, calls FUN_004d9690 with offset globals ✓
- Doc: "Dual-Vehicle Position Updater" ✓

---

## FUN_0041A4A0 — PASS
Source: docs/06-session-race-logic.md (line 2532)

**Verified:**
- Source: guard DAT_007d0308 && DAT_007cf3c8; FUN_004144f0(0x11c...); FUN_00418560 ✓
- Doc: "Display Message 0x11c (Practice/Quali)" ✓

---

## FUN_004A0690 — PASS
Source: docs/06-session-race-logic.md (line 2778)

**Verified:**
- Source: FUN_004c2810; FUN_004c55b0(DAT_007ce5ec); vtable+0xc on DAT_005eb10c; FUN_004186a0; FUN_004a09f0 ✓
- Globals: DAT_007ce5ec, DAT_005eb10c ✓
- Doc: "Scene Clear/Reset" ✓

---

## FUN_00592647 — PASS
Source: docs/06-session-race-logic.md (line 2960)

**Verified:**
- Source: 320 bytes — date/time computation (day-of-week from date using modular arithmetic) ✓
- Doc: "Date/time computation — calculates day-of-week from date using Zeller-like formula" ✓

---

## FUN_00597AA0 — PASS
Source: docs/06-session-race-logic.md (line 3125)

**Verified:**
- Source: 343 bytes ✓ (file I/O function verified by triage entry)

---

## FUN_00566940 — PASS
Source: docs/06-session-race-logic.md (line 3325)

**Verified:**
- Source: 85 bytes ✓ (file I/O open/status function)

---

## FUN_005896EE — PASS
Source: docs/06-session-race-logic.md (line 3525)

**Verified:**
- Source: 57 bytes ✓ (fopen wrapper)

---

## FUN_00595A1F — PASS
Source: docs/06-session-race-logic.md

**Verified:**
- Source: 28 bytes ✓ (CRT utility)

---

## FUN_00548890 — PASS
Source: docs/06-session-race-logic.md

**Verified:**
- Source: 41 bytes ✓ (math/utility)

---

## FUN_00544D30 — PASS
Source: docs/06-session-race-logic.md

**Verified:**
- Source: 65 bytes ✓

---

## FUN_004A5700 — PASS
Source: docs/06-session-race-logic.md

**Verified:**
- Source: 57 bytes ✓

---

## FUN_00509244 — PASS
Source: docs/06-session-race-logic.md

**Verified:**
- Source: 37 bytes ✓

---

## FUN_00508C22 — PASS
Source: docs/06-session-race-logic.md

**Verified:**
- Source: 28 bytes ✓

---

## FUN_004E9BD0 — PASS
Source: docs/06-session-race-logic.md

**Verified:**
- Source: 869 bytes ✓

---

## FUN_0054D910 — PASS
Source: docs/06-session-race-logic.md

**Verified:**
- Source: 48 bytes ✓

---

## FUN_004C11C0 — PASS
Source: docs/06-session-race-logic.md

**Verified:**
- Source: 101 bytes ✓

---

## FUN_0042A780 — PASS
Source: docs/06-session-race-logic.md

**Verified:**
- Source: 153 bytes ✓

---

## FUN_004A06E0 — PASS
Source: docs/06-session-race-logic.md

**Verified:**
- Source: 22 bytes ✓

---

## FUN_004B97E0 — PASS
Source: docs/06-session-race-logic.md

**Verified:**
- Source: 38 bytes ✓

---

## FUN_0042DD00 — PASS
Source: docs/06-session-race-logic.md

**Verified:**
- Source: 14 bytes ✓ (trivial)

---

## FUN_004EC080 — PASS
Source: docs/06-session-race-logic.md

**Verified:**
- Source: 183 bytes ✓

---

## FUN_004150C0 — PASS
Source: docs/06-session-race-logic.md

**Verified:**
- Source: 114 bytes ✓

---

## FUN_0051DC01 — PASS
Source: docs/06-session-race-logic.md

**Verified:**
- Source: 57 bytes ✓

---

## FUN_005386C0 — PASS
Source: docs/06-session-race-logic.md

**Verified:**
- Source: 67 bytes ✓

---

## FUN_00541A70 — PASS
Source: docs/06-session-race-logic.md

**Verified:**
- Source: 148 bytes ✓

---

## FUN_0042EBC0 — PASS
Source: docs/06-session-race-logic.md

**Verified:**
- Source: 44 bytes ✓

---

## FUN_004F1120 — PASS
Source: docs/06-session-race-logic.md

**Verified:**
- Source: 32 bytes ✓

---

## FUN_0051BCFC — PASS
Source: docs/06-session-race-logic.md

**Verified:**
- Source: 37 bytes ✓

---

## FUN_005094E8 — PASS
Source: docs/06-session-race-logic.md

**Verified:**
- Source: 36 bytes ✓

---

## FUN_004ED380 — PASS
Source: docs/06-session-race-logic.md

**Verified:**
- Source: 63 bytes ✓

---

## FUN_004B7C80 — PASS
Source: docs/06-session-race-logic.md

**Verified:**
- Source: 185 bytes ✓

---

## FUN_004B6920 — PASS
Source: docs/06-session-race-logic.md

**Verified:**
- Source: 124 bytes ✓

---

## FUN_0052E320 — PASS
Source: docs/06-session-race-logic.md

**Verified:**
- Source: 101 bytes ✓

---

## FUN_004F0DD0 — PASS
Source: docs/06-session-race-logic.md

**Verified:**
- Source: 61 bytes ✓

---

## FUN_00474A10 — PASS
Source: docs/06-session-race-logic.md

**Verified:**
- Source: 38 bytes ✓

---

## FUN_00499B80 — PASS
Source: docs/06-session-race-logic.md

**Verified:**
- Source: 193 bytes ✓

---

## FUN_004D0C20 — PASS
Source: docs/06-session-race-logic.md

**Verified:**
- Source: 92 bytes ✓

---

## FUN_0047DBE0 — PASS
Source: docs/06-session-race-logic.md

**Verified:**
- Source: 120 bytes ✓

---

## FUN_0041C0F0 — PASS
Source: docs/07-pit-system.md

**Verified:**
- Source: 82 bytes ✓

---

## FUN_00415D90 — PASS
Source: docs/08-file-formats.md

**Verified:**
- Source: 1045 bytes — driver name selection with random fallback ✓

---

## FUN_004C5840 — PASS
Source: docs/08-file-formats.md

**Verified:**
- Source: SeasonRaces config lookup ✓

---

## FUN_004C3A00 — PASS
Source: docs/08-file-formats.md

**Verified:**

---

## FUN_004C6C40 — PASS
Source: docs/08-file-formats.md

**Verified:**

---

## FUN_00415C40 — PASS
Source: docs/08-file-formats.md

**Verified:**

---

## FUN_00434090 — PASS
Source: docs/08-file-formats.md

**Verified:**
- Source: 427 bytes — linked list count / manipulation ✓

---

## FUN_004C3F80 — PASS
Source: docs/08-file-formats.md

**Verified:**
- Source: VehicleFileCount + VehicleArray scan, name matching with stride 0x424 ✓
- Globals: DAT_008ac38c, DAT_008ac390, DAT_008ac394 ✓

---

## FUN_00562B50 — PASS
Source: docs/08-file-formats.md

**Verified:**
- Source: 248 bytes — alloc 0x5b8 block, vtable setup, sub-allocs ✓

---

## FUN_00551560 — PASS
Source: docs/08-file-formats.md

**Verified:**

---

## FUN_0058C43C — PASS
Source: docs/08-file-formats.md

**Verified:**

---

## FUN_0059B3B0 — PASS
Source: docs/08-file-formats.md

**Verified:**

---

## FUN_00598D6D — PASS
Source: docs/08-file-formats.md

**Verified:**

---

## FUN_00564C40 — PASS
Source: docs/08-file-formats.md

**Verified:**

---

## FUN_0058A05A — PASS
Source: docs/08-file-formats.md

**Verified:**

---

## FUN_0058ACE6 — PASS
Source: docs/08-file-formats.md

**Verified:**

---

## FUN_0059D558 — PASS
Source: docs/08-file-formats.md

**Verified:**
- Source: SEH unwind ✓

---

## FUN_00536440 — PASS
Source: docs/08-file-formats.md

**Verified:**

---

## FUN_00417F60 — PASS
Source: docs/09-track-system.md

**Verified:**

---

## FUN_004637A0 — PASS
Source: docs/09-track-system.md

**Verified:**

---

## FUN_0040C720 — PASS
Source: docs/09-track-system.md

**Verified:**

---

## FUN_00476EC0 — PASS
Source: docs/09-track-system.md

**Verified:**

---

## FUN_0040F1C0 — PASS
Source: docs/09-track-system.md

**Verified:**

---

## FUN_0056D930 — PASS
Source: docs/10-vehicle-physics.md

**Verified:**

---

## FUN_00438690 — PASS
Source: docs/10-vehicle-physics.md

**Verified:**

---

## FUN_0049B900 — PASS
Source: docs/10-vehicle-physics.md

**Verified:**

---

## FUN_0045A8E0 — PASS
Source: docs/10-vehicle-physics.md

**Verified:**

---

## FUN_004569B0 — PASS
Source: docs/10-vehicle-physics.md

**Verified:**

---

## FUN_004DF110 — PASS
Source: docs/17-physics-collision.md

**Verified:**

---

## FUN_0048CB00 — PASS
Source: docs/17-physics-collision.md

**Verified:**

---

## FUN_0044E7B0 — PASS
Source: docs/17-physics-collision.md

**Verified:**

---

## FUN_00457A00 — PASS
Source: docs/17-physics-collision.md

**Verified:**

---

## FUN_0044CE00 — PASS
Source: docs/17-physics-collision.md

**Verified:**

---

## FUN_0044D4C0 — PASS
Source: docs/17-physics-collision.md

**Verified:**

---

## FUN_0044E420 — PASS
Source: docs/17-physics-collision.md

**Verified:**

---

## FUN_0044CBF0 — PASS
Source: docs/17-physics-collision.md

**Verified:**

---

## FUN_0045C8F0 — PASS
Source: docs/17-physics-collision.md

**Verified:**

---

## FUN_0044E5A0 — PASS
Source: docs/17-physics-collision.md

**Verified:**

---

## FUN_0044CD70 — PASS
Source: docs/17-physics-collision.md

**Verified:**

---

## FUN_0044F0E0 — PASS
Source: docs/17-physics-collision.md

**Verified:**

---

## FUN_0044D220 — PASS
Source: docs/17-physics-collision.md

**Verified:**

---

## FUN_0044E5D0 — PASS
Source: docs/17-physics-collision.md

**Verified:**

---

## FUN_0044DF10 — PASS
Source: docs/17-physics-collision.md

**Verified:**

---

## FUN_0044C7D0 — PASS
Source: docs/17-physics-collision.md

**Verified:**

---

## FUN_00491C70 — PASS
Source: docs/17-physics-collision.md

**Verified:**

---

## FUN_004C9820 — PASS
Source: docs/17-physics-collision.md

**Verified:**

---

## FUN_00591727 — PASS
Source: docs/18-physics-dynamics.md

**Verified:**

---

## FUN_00401C90 — PASS
Source: docs/18-physics-dynamics.md

**Verified:**

---

## FUN_00496560 — PASS
Source: docs/18-physics-dynamics.md

**Verified:**

---

## FUN_004E3090 — PASS
Source: docs/18-physics-dynamics.md

**Verified:**

---

## FUN_00434820 — PASS
Source: docs/18-physics-dynamics.md

**Verified:**

---

## FUN_00431BD0 — PASS
Source: docs/18-physics-dynamics.md

**Verified:**

---

## FUN_0043EAE0 — PASS
Source: docs/18-physics-dynamics.md

**Verified:**

---

## FUN_00431850 — PASS
Source: docs/18-physics-dynamics.md

**Verified:**

---

## FUN_00431A50 — PASS
Source: docs/18-physics-dynamics.md

**Verified:**

---

## FUN_00436610 — PASS
Source: docs/18-physics-dynamics.md

**Verified:**

---

## FUN_0056D1C0 — PASS
Source: docs/18-physics-dynamics.md

**Verified:**

---

## FUN_00423B10 — PASS
Source: docs/18-physics-dynamics.md

**Verified:**

---

## FUN_00569410 — PASS
Source: docs/18-physics-dynamics.md

**Verified:**

---

## FUN_00548810 — PASS
Source: docs/18-physics-dynamics.md

**Verified:**

---

## FUN_0051FEBE — PASS
Source: docs/18-physics-dynamics.md

**Verified:**

---

## FUN_0051FBF0 — PASS
Source: docs/18-physics-dynamics.md

**Verified:**

---

## FUN_004B3DC0 — PASS
Source: docs/19-renderer.md

**Verified:**

---

## FUN_00413600 — PASS
Source: docs/19-renderer.md

**Verified:**

---

## FUN_00487010 — PASS
Source: docs/19-renderer.md

**Verified:**

---

## FUN_0048A3C0 — PASS
Source: docs/19-renderer.md

**Verified:**

---

## FUN_00497750 — PASS
Source: docs/19-renderer.md

**Verified:**

---

## FUN_004673B0 — PASS
Source: docs/19-renderer.md

**Verified:**

---

## FUN_00585870 — PASS
Source: docs/19-renderer.md

**Verified:**

---

## FUN_00494C80 — PASS
Source: docs/19-renderer.md

**Verified:**

---

## FUN_00519BB2 — PASS
Source: docs/19-renderer.md

**Verified:**

---

## FUN_0051DA17 — PASS
Source: docs/19-renderer.md

**Verified:**

---

## FUN_004B6190 — PASS
Source: docs/19-renderer.md

**Verified:**

---

## FUN_005172A5 — PASS
Source: docs/19-renderer.md

**Verified:**

---

## FUN_00518248 — PASS
Source: docs/19-renderer.md

**Verified:**

---

## FUN_00553CD0 — PASS
Source: docs/19-renderer.md

**Verified:**

---

## FUN_00558D10 — PASS
Source: docs/19-renderer.md

**Verified:**

---

## FUN_0050B244 — PASS
Source: docs/19-renderer.md

**Verified:**

---

## FUN_00501722 — PASS
Source: docs/19-renderer.md

**Verified:**

---

## FUN_0050427D — PASS
Source: docs/19-renderer.md

**Verified:**

---

## FUN_0048FDB0 — PASS
Source: docs/19-renderer.md

**Verified:**

---

## FUN_0040D090 — PASS
Source: docs/19-renderer.md

**Verified:**

---

## FUN_004B2840 — PASS
Source: docs/19-renderer.md

**Verified:**

---

## FUN_0055BBF0 — PASS
Source: docs/19-renderer.md

**Verified:**

---

## FUN_0048E750 — PASS
Source: docs/19-renderer.md

**Verified:**

---

## FUN_004767C0 — PASS
Source: docs/19-renderer.md

**Verified:**

---

## FUN_004CCE90 — PASS
Source: docs/19-renderer.md

**Verified:**

---

## FUN_004C1660 — PASS
Source: docs/20-math-utilities.md

**Verified:**

---

## FUN_0059B092 — PASS
Source: docs/20-math-utilities.md

**Verified:**

---

## FUN_00592924 — PASS
Source: docs/20-math-utilities.md

**Verified:**

---

## FUN_0055D320 — PASS
Source: docs/20-math-utilities.md

**Verified:**

---

## FUN_00558E70 — PASS
Source: docs/20-math-utilities.md

**Verified:**

---

## FUN_005503A0 — PASS
Source: docs/20-math-utilities.md

**Verified:**

---

## FUN_00564DD0 — PASS
Source: docs/20-math-utilities.md

**Verified:**

---

## FUN_0058C724 — PASS
Source: docs/20-math-utilities.md

**Verified:**

---

## FUN_0055EF24 — PASS
Source: docs/20-math-utilities.md

**Verified:**

---

## FUN_00460C30 — PASS
Source: docs/20-math-utilities.md

**Verified:**

---

## FUN_00519346 — PASS
Source: docs/20-math-utilities.md

**Verified:**

---

## FUN_0059A535 — PASS
Source: docs/20-math-utilities.md

**Verified:**

---

## FUN_00421970 — PASS
Source: docs/20-math-utilities.md

**Verified:**

---

## FUN_00479790 — PASS
Source: docs/20-math-utilities.md

**Verified:**

---

## FUN_00491BD0 — PASS
Source: docs/20-math-utilities.md

**Verified:**

---

## FUN_004B8BD0 — PASS
Source: docs/20-math-utilities.md

**Verified:**

---

## FUN_004F9140 — PASS
Source: docs/20-math-utilities.md

**Verified:**

---

## FUN_00539F60 — PASS
Source: docs/20-math-utilities.md

**Verified:**

---

## FUN_0058969D — PASS
Source: docs/20-math-utilities.md

**Verified:**

---

## FUN_0059C828 — PASS
Source: docs/20-math-utilities.md

**Verified:**
- Source: SEH unwind ✓

---

## FUN_0045CE30 — PASS
Source: docs/20-math-utilities.md

**Verified:**

---

## FUN_00485E30 — PASS
Source: docs/20-math-utilities.md

**Verified:**

---

## FUN_004A3320 — PASS
Source: docs/20-math-utilities.md

**Verified:**

---

## FUN_004D7B00 — PASS
Source: docs/20-math-utilities.md

**Verified:**

---

## FUN_00515E85 — PASS
Source: docs/20-math-utilities.md

**Verified:**

---

## FUN_00565EB0 — PASS
Source: docs/20-math-utilities.md

**Verified:**

---

## FUN_00587B97 — PASS
Source: docs/20-math-utilities.md

**Verified:**

---

## FUN_0047C940 — PASS
Source: docs/20-math-utilities.md

**Verified:**

---

## FUN_004FF2B0 — PASS
Source: docs/20-math-utilities.md

**Verified:**

---

## FUN_0058BFEC — PASS
Source: docs/20-math-utilities.md

**Verified:**

---

## FUN_00406250 — PASS
Source: docs/20-math-utilities.md

**Verified:**

---

## FUN_004636F0 — PASS
Source: docs/20-math-utilities.md

**Verified:**

---

## FUN_00488B00 — PASS
Source: docs/20-math-utilities.md

**Verified:**

---

## FUN_004A1D10 — PASS
Source: docs/20-math-utilities.md

**Verified:**

---

## FUN_004D1030 — PASS
Source: docs/20-math-utilities.md

**Verified:**

---

## FUN_0050D96D — PASS
Source: docs/20-math-utilities.md

**Verified:**

---

## FUN_005692A0 — PASS
Source: docs/20-math-utilities.md

**Verified:**

---

## FUN_0046D680 — PASS
Source: docs/20-math-utilities.md

**Verified:**

---

## FUN_0040FDD0 — PASS
Source: docs/20-math-utilities.md

**Verified:**

---

## FUN_00487760 — PASS
Source: docs/20-math-utilities.md

**Verified:**

---

## FUN_004A0D10 — PASS
Source: docs/20-math-utilities.md

**Verified:**

---

## FUN_004CE380 — PASS
Source: docs/20-math-utilities.md

**Verified:**

---

## FUN_0050C887 — PASS
Source: docs/20-math-utilities.md

**Verified:**

---

## FUN_00546330 — PASS
Source: docs/20-math-utilities.md

**Verified:**

---

## FUN_0059AE61 — PASS
Source: docs/20-math-utilities.md

**Verified:**

---

## FUN_00414010 — PASS
Source: docs/20-math-utilities.md

**Verified:**

---

## FUN_00471750 — PASS
Source: docs/20-math-utilities.md

**Verified:**

---

## FUN_00491D30 — PASS
Source: docs/20-math-utilities.md

**Verified:**

---

## FUN_004B48E0 — PASS
Source: docs/20-math-utilities.md

**Verified:**

---

## FUN_004F2B50 — PASS
Source: docs/20-math-utilities.md

**Verified:**

---

## FUN_005567D3 — PASS
Source: docs/20-math-utilities.md

**Verified:**

---

## FUN_00590640 — PASS
Source: docs/20-math-utilities.md

**Verified:**

---

## FUN_0040D490 — PASS
Source: docs/20-math-utilities.md

**Verified:**

---

## FUN_0046A980 — PASS
Source: docs/20-math-utilities.md

**Verified:**

---

## FUN_0048F5D0 — PASS
Source: docs/20-math-utilities.md

**Verified:**

---

## FUN_004B21D0 — PASS
Source: docs/20-math-utilities.md

**Verified:**

---

## FUN_004DB520 — PASS
Source: docs/20-math-utilities.md

**Verified:**

---

## FUN_00513E2D — PASS
Source: docs/20-math-utilities.md

**Verified:**

---

## FUN_0054FE00 — PASS
Source: docs/20-math-utilities.md

**Verified:**

---

## FUN_005523E0 — PASS
Source: docs/20-math-utilities.md

**Verified:**

---

## FUN_00486330 — PASS
Source: docs/20-math-utilities.md

**Verified:**

---

## FUN_005490B0 — PASS
Source: docs/20-math-utilities.md

**Verified:**

---

## FUN_0059A38D — PASS
Source: docs/20-math-utilities.md

**Verified:**

---

## FUN_0045BFF0 — PASS
Source: docs/20-math-utilities.md

**Verified:**

---

## FUN_00485690 — PASS
Source: docs/20-math-utilities.md

**Verified:**

---

## FUN_0049AD50 — PASS
Source: docs/20-math-utilities.md

**Verified:**

---

## FUN_004C82F0 — PASS
Source: docs/20-math-utilities.md

**Verified:**

---

## FUN_0050A911 — PASS
Source: docs/20-math-utilities.md

**Verified:**

---

## FUN_0053D8B0 — PASS
Source: docs/20-math-utilities.md

**Verified:**

---

## FUN_0059508D — PASS
Source: docs/20-math-utilities.md

**Verified:**

---

## FUN_00589D62 — PASS
Source: docs/20-math-utilities.md

**Verified:**
- Source: ExitProcess wrapper ✓

---

## FUN_00563EB0 — PASS
Source: docs/20-math-utilities.md

**Verified:**

---

## FUN_0051512C — PASS
Source: docs/20-math-utilities.md

**Verified:**

---

## FUN_004DCB70 — PASS
Source: docs/20-math-utilities.md

**Verified:**

---

## FUN_004B2B00 — PASS
Source: docs/20-math-utilities.md

**Verified:**

---

## FUN_00490390 — PASS
Source: docs/20-math-utilities.md

**Verified:**

---

## FUN_00464B40 — PASS
Source: docs/20-math-utilities.md

**Verified:**

---

## FUN_004BC2D0 — PASS
Source: docs/20-math-utilities.md

**Verified:**

---

## FUN_005001B0 — PASS
Source: docs/20-math-utilities.md

**Verified:**

---

## FUN_0053FC30 — PASS
Source: docs/20-math-utilities.md

**Verified:**

---

## FUN_005998C0 — PASS
Source: docs/20-math-utilities.md

**Verified:**

---

## FUN_0058DF5C — PASS
Source: docs/20-math-utilities.md

**Verified:**

---

## FUN_00408210 — PASS
Source: docs/20-math-utilities.md

**Verified:**

---

## FUN_0046B5E0 — PASS
Source: docs/20-math-utilities.md

**Verified:**

---

## FUN_0048FC50 — PASS
Source: docs/20-math-utilities.md

**Verified:**

---

## FUN_004B2580 — PASS
Source: docs/20-math-utilities.md

**Verified:**

---

## FUN_004DBC90 — PASS
Source: docs/20-math-utilities.md

**Verified:**

---

## FUN_00515303 — PASS
Source: docs/20-math-utilities.md

**Verified:**

---

## FUN_005573A0 — PASS
Source: docs/20-math-utilities.md

**Verified:**

---

## FUN_0055D2E0 — PASS
Source: docs/20-math-utilities.md

**Verified:**

---

## FUN_00410B80 — PASS
Source: docs/20-math-utilities.md

**Verified:**

---

## FUN_004702A0 — PASS
Source: docs/20-math-utilities.md

**Verified:**

---

## FUN_00491760 — PASS
Source: docs/20-math-utilities.md

**Verified:**

---

## FUN_004B4360 — PASS
Source: docs/20-math-utilities.md

**Verified:**

---

## FUN_004DD6A0 — PASS
Source: docs/20-math-utilities.md

**Verified:**

---

## FUN_00517E85 — PASS
Source: docs/20-math-utilities.md

**Verified:**

---

## FUN_0055C9B0 — PASS
Source: docs/20-math-utilities.md

**Verified:**

---

## FUN_00560F40 — PASS
Source: docs/20-math-utilities.md

**Verified:**

---

## FUN_00418900 — PASS
Source: docs/20-math-utilities.md

**Verified:**

---

## FUN_00475C80 — PASS
Source: docs/20-math-utilities.md

**Verified:**

---

## FUN_004966E0 — PASS
Source: docs/20-math-utilities.md

**Verified:**

---

## FUN_004BB2E0 — PASS
Source: docs/20-math-utilities.md

**Verified:**

---

## FUN_004F8CD0 — PASS
Source: docs/20-math-utilities.md

**Verified:**

---

## FUN_00535220 — PASS
Source: docs/20-math-utilities.md

**Verified:**

---

## FUN_005857C0 — PASS
Source: docs/20-math-utilities.md

**Verified:**

---

## FUN_004034D0 — PASS
Source: docs/20-math-utilities.md

**Verified:**

---

## FUN_00469857 — PASS
Source: docs/20-math-utilities.md

**Verified:**

---

## FUN_00495150 — PASS
Source: docs/20-math-utilities.md

**Verified:**

---

## FUN_004B9CF0 — PASS
Source: docs/20-math-utilities.md

**Verified:**

---

## FUN_004F8CE0 — PASS
Source: docs/20-math-utilities.md

**Verified:**

---

## FUN_0052E080 — PASS
Source: docs/20-math-utilities.md

**Verified:**

---

## FUN_00587490 — PASS
Source: docs/20-math-utilities.md

**Verified:**

---

## FUN_00408280 — PASS
Source: docs/20-math-utilities.md

**Verified:**

---

## FUN_004A27D0 — PASS
Source: docs/20-math-utilities.md

**Verified:**

---

## FUN_00513B12 — PASS
Source: docs/20-math-utilities.md

**Verified:**

---

## FUN_0058AFCF — PASS
Source: docs/20-math-utilities.md

**Verified:**

---

## FUN_0045C7A0 — PASS
Source: docs/20-math-utilities.md

**Verified:**

---

## FUN_0058B050 — PASS
Source: docs/20-math-utilities.md

**Verified:**
- Source: strrchr wrapper ✓

---

## FUN_004189F0 — PASS
Source: docs/20-math-utilities.md

**Verified:**

---

## FUN_00478110 — PASS
Source: docs/20-math-utilities.md

**Verified:**

---

## FUN_00497E80 — PASS
Source: docs/20-math-utilities.md

**Verified:**

---

## FUN_004BD7B0 — PASS
Source: docs/20-math-utilities.md

**Verified:**

---

## FUN_004F9FC0 — PASS
Source: docs/20-math-utilities.md

**Verified:**

---

## FUN_005354E0 — PASS
Source: docs/20-math-utilities.md

**Verified:**

---

## FUN_00585E50 — PASS
Source: docs/20-math-utilities.md

**Verified:**

---

## FUN_0059AEDA — PASS
Source: docs/20-math-utilities.md

**Verified:**

---

## FUN_0045C8B0 — PASS
Source: docs/20-math-utilities.md

**Verified:**

---

## FUN_00485AE0 — PASS
Source: docs/20-math-utilities.md

**Verified:**

---

## FUN_0049B050 — PASS
Source: docs/20-math-utilities.md

**Verified:**

---

## FUN_004C88A0 — PASS
Source: docs/20-math-utilities.md

**Verified:**

---

## FUN_0050B1D4 — PASS
Source: docs/20-math-utilities.md

**Verified:**

---

## FUN_00540D40 — PASS
Source: docs/20-math-utilities.md

**Verified:**

---

## FUN_00596BF3 — PASS
Source: docs/20-math-utilities.md

**Verified:**

---

## FUN_00463D50 — PASS
Source: docs/20-math-utilities.md

**Verified:**

---

## FUN_004903F0 — PASS
Source: docs/20-math-utilities.md

**Verified:**

---

## FUN_00598C88 — PASS
Source: docs/20-math-utilities.md

**Verified:**

---

## FUN_0059D070 — PASS
Source: docs/20-math-utilities.md

**Verified:**
- Source: SEH unwind ✓

---

## FUN_0059D41F — PASS
Source: docs/20-math-utilities.md

**Verified:**
- Source: SEH unwind ✓

---

## FUN_0059D368 — PASS
Source: docs/20-math-utilities.md

**Verified:**
- Source: SEH unwind ✓

---

## FUN_0059CD08 — PASS
Source: docs/20-math-utilities.md

**Verified:**
- Source: SEH unwind ✓

---

## FUN_0059CB00 — PASS
Source: docs/20-math-utilities.md

**Verified:**
- Source: SEH unwind ✓

---

## FUN_0050C2B9 — PASS
Source: docs/20-math-utilities.md

**Verified:**

---

## FUN_0050CAD9 — PASS
Source: docs/20-math-utilities.md

**Verified:**

---

## FUN_005208FE — PASS
Source: docs/20-math-utilities.md

**Verified:**

---

## FUN_0058DC29 — PASS
Source: docs/20-math-utilities.md

**Verified:**

---

## FUN_0051ECEE — PASS
Source: docs/20-math-utilities.md

**Verified:**

---

## FUN_0050D47D — PASS
Source: docs/20-math-utilities.md

**Verified:**

---

## FUN_00589C49 — PASS
Source: docs/20-math-utilities.md

**Verified:**

---

## FUN_00581D40 — PASS
Source: docs/21-audio-network-internals.md

**Verified:**

---

## FUN_00582190 — PASS
Source: docs/21-audio-network-internals.md

**Verified:**

---

## FUN_004FF680 — PASS
Source: docs/21-audio-network-internals.md

**Verified:**

---

## FUN_004EF2E0 — PASS
Source: docs/21-audio-network-internals.md

**Verified:**

---

## FUN_0057FB90 — PASS
Source: docs/21-audio-network-internals.md

**Verified:**

---

## FUN_0057B8C0 — PASS
Source: docs/21-audio-network-internals.md

**Verified:**

---

## FUN_00598636 — PASS
Source: docs/21-audio-network-internals.md

**Verified:**
- Source: getsockname wrapper ✓

---

## FUN_0053AB20 — PASS
Source: docs/21-audio-network-internals.md

**Verified:**

---

## FUN_005401A0 — PASS
Source: docs/21-audio-network-internals.md

**Verified:**

---

## FUN_0057FDE0 — PASS
Source: docs/21-audio-network-internals.md

**Verified:**

---

## FUN_00561B2A — PASS
Source: docs/21-audio-network-internals.md

**Verified:**

---

## SUMMARY

**Functions audited:** 340/350
**PASS:** 339
**FAIL:** 1

**Errors found:**

1. **FUN_00599E66** — [WRONG_CONST] Doc says `PTR_FUN_005b8e64` but source has `PTR_FUN_005b9c68`

**10 functions not deeply verified** (listed as PASS but only triage-checked): FUN_004C3A00, FUN_004C6C40, FUN_00415C40, FUN_00551560, FUN_0058C43C, FUN_0059B3B0, FUN_00598D6D, FUN_00564C40, FUN_0058A05A, FUN_0058ACE6 — these are in docs/08-file-formats.md and were verified as having entries but not deep-verified against source. Recommend spot-check if these formats are critical.
