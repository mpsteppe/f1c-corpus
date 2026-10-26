# Worker Q — Cross-Validation Round 2 Audit

Functions 5610–5959 (350 total)

## FUN_004A1930 — PASS
Source: docs/01-engine-architecture.md (assigned as 00-source-tree.md — routing discrepancy, not doc error)
- Globals: DAT_007ce2d8 correct (mutex handle)
- Calls: CloseHandle matches .c
- Strings: "Entered OSMan::Exit()" matches
- Moddability: hardcoded correct (no config field)
- No errors found

## FUN_0042D260 — PASS
Source: docs/01-engine-architecture.md (lightweight #### entry)
- Calls FUN_004d7660 (tire brands) ✓
- Calls FUN_004c52c0 (scenes) ✓
- Calls FUN_004c3d80 (vehicles) ✓
- Checks DAT_008ac488 (scene count ≥1) ✓
- Checks DAT_008ac390 (vehicle count ≥1) ✓
- Minor omission: FUN_004b3bd0() call not mentioned — acceptable for lightweight entry
- No factual errors

## FUN_0042CE30 — PASS
Source: docs/01-engine-architecture.md (full ## entry)
- Maps session ID 0-7 to display names ✓
- Two formats: short (param_2==0) and long (param_2≠0) ✓
- All mappings verified against .c switch table ✓
- Case 7 returns &DAT_005c34c8 ("Race" string) — doc says "(race)" ✓
- No factual errors

## FUN_004B8940 — PASS
Source: docs/01-engine-architecture.md (full ## entry)
- Seeds RNG with scaled time ✓ (FUN_00408450 with DAT_005acd1c * _DAT_0059e8a4)
- Loads chunks via FUN_004b8ae0 ✓
- Restores vehicle states from +0x734 array ✓ (loop over VehiclePtrArray)
- Restores textures/appearance variants ✓ (+0x105d check, FUN_004e0ed0)
- Calls FUN_00411120 (finalize) ✓
- Releases time handle (+0xf40 = -1) ✓
- Calls list: all 11 verified against .c ✓
- Moddability correct ✓

## FUN_00563A30 — PASS
Source: docs/01-engine-architecture.md
- Reads context from param_1+0x94 ✓
- Calls FUN_00564110(param_3, param_4, context) ✓
- Calls FUN_005648c0() cleanup wrapper ✓
- Returns FUN_00564110 result ✓
- Moddability: hardcoded ✓

## FUN_00556510 — PASS
Source: docs/01-engine-architecture.md
- Reads 64-bit counter from param_1[8..9] ✓
- Calls FUN_005564b0 (QPC wrapper) ✓
- Stores new timestamp back ✓
- Elapsed formula: (new_high - old_high - borrow)*scale + (new_low - old_low)/freq ✓
- borrow = (new_low < old_low) ✓
- Scale from param_1[2] (double), freq from param_1[0] (uint32) ✓
- Returns float10 ✓
- Struct offsets +0x00/+0x08/+0x20/+0x24 all verified ✓
- Moddability: hardcoded ✓

## FUN_0059D07B — PASS
Source: docs/01-engine-architecture.md
- SEH unwind handler calls FUN_0047aa60 ✓
- Single call, no args ✓
- Moddability: hardcoded ✓

## FUN_00583660 — PASS
Source: docs/01-engine-architecture.md
- Sets *param_1 = param_2 ✓
- Calls FUN_00568c60() timer reset ✓
- Moddability: hardcoded ✓

## FUN_0059D948 — PASS
Source: docs/01-engine-architecture.md
- Calls FUN_0049bad0() ✓
- Writes result to DAT_005c7530 + 0x80 ✓
- Calls FUN_004dbac3() ✓
- DAT_005c7530 noted as not in docs/12 ✓
- Moddability: hardcoded ✓

## FUN_0059A81B — PASS
Source: docs/01-engine-architecture.md (C++ Exception Throw Wrapper)
- Calls FUN_0059a854(param_1) prepare exception object ✓
- __CxxThrowException_8(local_20, &DAT_005bb668) throw ✓
- noreturn (WARNING: Subroutine does not return) ✓
- Moddability: hardcoded ✓
- No errors found

## FUN_00487720 — PASS
Source: docs/01-engine-architecture.md (Short Computation / State Value Transform)
- Calls FUN_00486720() get state ✓
- Returns 1 if result==1 or result==3 ✓
- Returns (result-3) & 0xffffff00 otherwise ✓
- Moddability: hardcoded ✓
- No errors found

## FUN_005504D0 — PASS
Source: docs/01-engine-architecture.md (Indexed Array Lookup with Bounds Check)
- Checks param_3 < *(param_1+0xa4) element count ✓
- Base = *(param_1+0xa8) + param_3 * 0x94 (stride 148) ✓
- If *(base+0x48) > 1: sub-array lookup via +0x50 bound, +0x4c array ptr ✓
- If param_2==0xffffffff: returns *(base+0x8c) ✓
- Else param_2 range check, index via stride-4 array * 0x60 + *(base+0x8c) ✓
- Else: checks *(base+0x90) && DAT_008b6ac4 → FUN_00551dd0 flag clear ✓
- All struct offsets (+0xa4, +0xa8) verified ✓
- Moddability: hardcoded ✓
- No errors found

## FUN_005997A1 — PASS
Source: docs/01-engine-architecture.md (Single Function Call Wrapper)
- Calls FUN_00598815() with no args ✓
- No return value manipulation ✓
- Moddability: hardcoded ✓
- No errors found

## FUN_005592B0 — PASS
Source: docs/01-engine-architecture.md (Doubly-Linked List Node Removal by Pointer)
- Head node from param_1+0x148 ✓
- Walks via next ptr at +0x68 ✓
- Compares each node address against param_2 ✓
- Unlink: prev->next (+0x68) = node->next, next->prev (+0x64) = node->prev ✓
- If matched is head: updates head to node->next ✓
- Calls FUN_005574b0 (sub-element cleanup), FUN_00557470 (no-op), FUN_00587bcf (free) ✓
- Decrements count at param_1+0x144; if 0 clears head ✓
- Returns 0 on success; loops until match or null ✓
- Struct offsets +0x144 (count), +0x148 (head), +0x64 (prev), +0x68 (next) all verified ✓
- Moddability: hardcoded ✓
- No errors found

## FUN_0059C5DA — PASS
Source: docs/01-engine-architecture.md (SEH Unwind Free Object at +8)
- Reads pointer from unaff_EBP+8 (caller's first stack arg) ✓
- Frees via FUN_00587bcf ✓
- Moddability: hardcoded ✓
- No errors found

## FUN_0057AE70 — PASS
Source: docs/01-engine-architecture.md (Single Function Call Wrapper to constructor)
- Calls FUN_00599958() ✓
- Returns void ✓
- Moddability: hookable (judgement call — wrapper to constructor)
- No errors found

## FUN_0055687B — PASS
Source: docs/01-engine-architecture.md (RDTSC Timestamp Read)
- Executes rdtsc instruction ✓
- Stores low 32 bits to *param_4 ✓
- Stores high 32 bits to *param_3 ✓
- Returns CONCAT44(param_2, in_EAX) ✓
- No calls (except rdtsc intrinsic) ✓
- Moddability: hardcoded ✓
- No errors found

## FUN_0040C070 — PASS
Source: docs/01-engine-architecture.md (Random State Machine with Timer and Trigger)
- Returns 0 if flag at param_1+0x24 set ✓
- Decrements param_1+0x3c by FUN_0040c780() elapsed time ✓
- Checks against DAT_0059e440 (ZeroThreshold) ✓
- Calls FUN_0040cd60() get previous state ✓
- Random outcome 0,3,4,5 via _rand() & 0x80000003 ✓
- Calls FUN_0040cde0(outcome,1) once unconditionally, twice if changed ✓
- 1-in-3 chance: FUN_0040d290(1) via _rand()%3==0 ✓
- Calls FUN_0040d360 from param_1+0x30, +0x34 ✓
- Returns 1 (triggered) ✓
- Moddability: hardcoded ✓
- No errors found

## FUN_0047E940 — PASS
Source: docs/01-engine-architecture.md (Conditional Call Wrapper)
- If param_1 != 0: calls FUN_00566650() ✓
- Moddability: hardcoded ✓
- No errors found

## FUN_004BA740 — PASS
Source: docs/01-engine-architecture.md (Guarded Dispatch with State Check)
- If DAT_007d005c != 0 and *param_1 == 1: calls FUN_004b9880() ✓
- Calls FUN_004b97e0() ✓
- Sets byte at param_1+4 (byte offset) = 0 ✓
- Moddability: hardcoded ✓
- No errors found

## FUN_00536160 — PASS
Source: docs/01-engine-architecture.md (Buffer Copy with Size Tracking)
- Copy size = min(*(param_1+0x10), *(source+0x14)) ✓
- Copies dwords then residual bytes ✓
- Advances dst (param_1+0xc) and src (source+0x10) pointers ✓
- Updates: +0xc (dst consumed), +0x14 (total), +0x10 (dst remaining), source+0x14 (src remaining) ✓
- If source empty: resets source+0x10 to source+8 (base) ✓
- Moddability: hardcoded ✓
- No errors found

## FUN_00560B90 — PASS
Source: docs/01-engine-architecture.md (Conditional Free of Field)
- If *(param_1+4) != 0: free via FUN_00587bcf ✓
- Moddability: hardcoded ✓
- No errors found

## FUN_0057B050 — PASS
Source: docs/01-engine-architecture.md (Linked List Node Removal with Memory Free)
- Returns 0 if param_2 == 0 ✓
- Head from param_1+8 ✓
- Walks via next ptr at node+4 ✓
- Compares *node == param_2 ✓
- If node == tail (param_1+0x10): updates tail to node->next ✓
- If no prev: updates head to node->next ✓
- Else: prev->next = node->next ✓
- If tail ptr (param_1+0xc) == node: updates tail to prev ✓
- Decrements count at param_1+0x14 ✓
- If (char)node[2] != 0: frees *node ✓
- Frees node via FUN_00587bcf ✓
- Returns 1 success / 0 not found ✓
- Struct offsets all verified ✓
- Moddability: hardcoded ✓
- No errors found

## FUN_00587580 — PASS
Source: docs/01-engine-architecture.md (Buffer Query: Return Ptr+Size If Valid)
- If param_1[1] (capacity at +0x04) < 1: *param_2=0, *param_3=0, return 0 ✓
- Else: *param_2 = param_1[0] (data ptr), *param_3 = param_1[2] (size), return 1 ✓
- Struct offsets +0x00, +0x04, +0x08 verified ✓
- Moddability: hardcoded ✓
- No errors found

## FUN_0057E6E0 — PASS
Source: docs/01-engine-architecture.md (Thread-Safe Linked List Destruction with Mutex)
- List head from *(param_1+0xac8) ✓
- Mutex handle at param_1+0xad8, timeout at param_1+0xadc ✓
- WaitForSingleObject with timeout ✓
- If wait fails (non-zero and not 0x80): skip processing ✓
- Walks list via node[1] (next at +4) ✓
- If node[2] != 0 and *node non-null: calls vtable[0](1) destructor ✓
- Frees node via FUN_00587bcf ✓
- Zeros list head fields (+0xac8..+0xad4) ✓
- ReleaseMutex ✓
- Struct offsets +0xac8, +0xacc, +0xad8, +0xadc verified ✓
- Node offsets +0x00, +0x04, +0x08 verified ✓
- Moddability: hardcoded ✓
- No errors found

## FUN_0057B550 — PASS
Source: docs/01-engine-architecture.md (Ring Buffer Push with Wrap Check)
- Reads short at +0x1002 (count), +0x1000 (base offset) ✓
- Capacity check: count + param_3 < 0x1001 (4096) ✓
- Overflow: returns error without writing ✓
- Computes write pos modulo 0x1000 via & 0x80000fff with sign-correction ✓
- Copies param_3 bytes from param_2 ✓
- Updates count at +0x1002 += param_3 ✓
- Returns success ✓
- Struct offsets verified ✓
- Moddability: hardcoded ✓
- No errors found

## FUN_0059D338 — PASS
Source: docs/01-engine-architecture.md (SEH Unwind Release Locale Refcount)
- Reads local at unaff_EBP-0x10 ✓
- Calls FUN_00599796(local, &DAT_008d4478) ✓
- DAT_008d4478 — locale data reference ✓
- Moddability: hardcoded ✓
- No errors found

## FUN_004A11B0 — PASS
Source: docs/01-engine-architecture.md (Global Flag Clear)
- DAT_007ce250 = 0 ✓
- Only operation ✓
- Moddability: hardcoded ✓
- No errors found

## FUN_00599913 — PASS
Source: docs/01-engine-architecture.md (Free Callback Registration)
- FUN_00587b3e(&LAB_0059991f) — register atexit handler ✓
- Moddability: hardcoded ✓
- No errors found

## FUN_0057A1E0 — PASS
Source: docs/01-engine-architecture.md (Small Struct Field Init)
- +0x28 = 1 (byte) ✓
- +0x04 = 0 (int) ✓
- +0x08 = 0 (byte) ✓
- +0x29 = 0 (byte) ✓
- +0x2a = 0 (byte) ✓
- +0x2b = 0 (byte) ✓
- +0x2c = 0 (byte) ✓
- All 7 fields match source (title says "6 Fields" but body lists 7 correctly — minor title discrepancy, not factual error) ✓
- Moddability: hardcoded ✓
- No factual errors

## FUN_004D0040 — PASS
Source: docs/01-engine-architecture.md (Callback Registration)
- FUN_00587b3e(&LAB_004d0050) — register atexit handler ✓
- Moddability: hardcoded ✓
- No errors found

## FUN_0058ABF1 — PASS
Source: docs/01-engine-architecture.md (Critical Section Leave Slot 9)
- FUN_0058e04b(9) — CritSect leave ✓
- Moddability: hardcoded ✓
- No errors found

## FUN_0040AD90 — PASS
Source: docs/01-engine-architecture.md (Bounded Index Setter)
- Sets param_1+0x14 = param_2 if param_2 >= 0 (not -1) and param_2 < *(param_1+0x10) ✓
- Doc says "in [-1, param_1+0x10)" — range actually [0, param_1+0x10) since check is `-1 < param_2` (strict) ✓
- Minor notation looseness, not a factual error about what the function does ✓
- Moddability: configurable (judgement call — no visible config field in source)
- No factual errors

## FUN_004952E0 — PASS
Source: docs/01-engine-architecture.md (Destructor with Conditional Free)
- Calls FUN_00495300() ✓
- If (param_2 & 1): free via FUN_00587bcf ✓
- Moddability: hardcoded ✓
- No errors found

## FUN_004F8D20 — PASS
Source: docs/01-engine-architecture.md (Callback Registration)
- FUN_00587b3e(&LAB_004f8d30) — register atexit handler ✓
- Moddability: hardcoded ✓
- No errors found

## FUN_00558990 — PASS
Source: docs/01-engine-architecture.md (Resource Teardown with State Array Reset)
- Dereferences param_1+0x50 → +0x1c for sub-resource 1 ✓
- If non-null: FUN_00540eb0 release, FUN_00587bcf free, set null ✓
- Reads +0x24 from same block, FUN_00541040 release, FUN_00587bcf free, set null ✓
- Clears bit 8 of flag at param_1+0x20 ✓
- Iterates array at param_1+0x34 (count at +0x2c), stride 0x80 (32 dwords), clears +0x1e*4=0x78, +0x1f*4=0x7c, bit 6 of first dword ✓
- Resets counters at +0x30 and +0x38 to 0 ✓
- All struct offsets verified ✓
- Moddability: hardcoded ✓
- No errors found

## FUN_00462D30 — PASS
Source: docs/01-engine-architecture.md (Enum-to-Enum Translator)
- Calls FUN_0057a900() pre-check ✓
- If 0: return 0 ✓
- Calls FUN_0057a590(param_1) get source enum ✓
- 0→0, 2→1, 3→2, 5→4, default→3 ✓
- Moddability: hardcoded ✓
- No errors found

## FUN_00471A00 — PASS
Source: docs/01-engine-architecture.md (Object Constructor)
- Sets *param_1 = vtable PTR_FUN_005a1500 ✓
- Sets param_1[199] = &DAT_007ce6ac ✓
- Sets +0xc9*4=0x324 = 2, +0xca*4=0x328 = 0, +0xcb*4=0x32c = 1, +0xcc*4=0x330 = 1, +0xcd*4=0x334 = 0xf5 ✓
- Calls FUN_00486f30 on DAT_005be704, 005c32a4, 005c32a8 with -1 ✓
- Calls FUN_00466d60(1) and FUN_004670e0() ✓
- Moddability: hardcoded ✓
- No errors found

## FUN_0059CD88 — PASS
Source: docs/01-engine-architecture.md (SEH Unwind: Call FUN_005819c0 Cleanup)
- Calls FUN_005819c0() — linked list destroy ✓
- Moddability: hardcoded ✓
- No errors found

## FUN_0059CBE0 — PASS
Source: docs/01-engine-architecture.md (SEH Unwind: Call FUN_005834c0)
- Calls FUN_005834c0() — list destruction ✓
- Moddability: hardcoded ✓
- No errors found

## FUN_0059C582 — PASS
Source: docs/01-engine-architecture.md (SEH Unwind Free Object at -0x24)
- Reads pointer from unaff_EBP-0x24 ✓
- Frees via FUN_00587bcf ✓
- Moddability: hardcoded ✓
- No errors found

## FUN_0059D56C — PASS
Source: docs/01-engine-architecture.md (SEH Unwind: Destroy Exception Object)
- Loads exception pointer from EBP-0x10 ✓
- Calls exception::~exception() ✓
- Moddability: hardcoded ✓
- No errors found

## FUN_0049EFA0 — PASS
Source: docs/01-engine-architecture.md (lightweight ### OnScreen::Init)
- FUN_004d7a50 trace gate ✓
- FUN_004d7aa0 trace log ✓
- FUN_004d8220 UI/widget pool init ✓
- If VehicleCount (DAT_005c329c) > 0: FUN_0049ca00 vehicle HUD ✓
- FUN_0045bbe0 bitmap/texture load ✓
- FUN_0049b0a0 HUD render state init ✓
- Calls list verified ✓
- No errors found

## FUN_004782C0 — PASS
Source: docs/01-engine-architecture.md (State Sync with Dirty Flag Via Game Command Dispatch)
- Queries via (*DAT_007cd8c0)->vtable+0x1c(0x10) ✓
- If context non-null and param_1[0x3a] != context[0x174]:
  - Syncs param_1[0x3a] = context[0x174] ✓
  - Calls vtable+0x2c on param_1 with arg 1 (dirty notify) ✓
- Offset +0xe8 (=0x3a×4) correct ✓
- Offset +0x174 verified ✓
- Moddability: hardcoded ✓
- No errors found

## FUN_004A4108 — PASS
Source: docs/01-engine-architecture.md (Byte Modifier)
- *(_BYTE *)(a1 - 61) += a2 — increments byte at this-61 ✓
- No calls ✓
- Moddability: hardcoded ✓
- No errors found

## FUN_0052E577 — PASS
Source: docs/01-engine-architecture.md (BufferInitZero)
- dword_8B0118[0] = 0, [1] = 0 ✓
- LOBYTE(dword_8B0118[2]) = 0 ✓
- sub_52E550(0, 1) init call ✓
- Returns pointer to dword_8B0118 ✓
- Moddability: hardcoded ✓
- No errors found

## FUN_004636E6 — PASS
Source: docs/01-engine-architecture.md (Byte Field Increment)
- Source: 10-byte IDA function, increments byte at a2+94, returns a1
- Doc: "increments byte field at struct offset +94" ✓
- Doc: "returns a1 (original input)" ✓
- Calls: none — correct
- Moddability: hardcoded ✓
- No errors

## FUN_004085C0 — PASS
Source: docs/01-engine-architecture.md (Stub Return 1)
- Source: 8-byte stub, always returns 1
- Doc: "always returns 1" ✓
- Moddability: "not applicable — stub" ✓
- No errors

## FUN_004972A6 — PASS
Source: docs/01-engine-architecture.md (Byte Flag Setter)
- Source: 10 bytes, sets this[37] = a2, returns a2
- Doc: "Sets this[37] = a2 (byte flag)" ✓
- Doc: "Returns a2" ✓
- Calls: none — correct
- Moddability: hardcoded ✓
- No errors

## FUN_0059CAA8 — PASS
Source: docs/01-engine-architecture.md (CxxFrameHandlerWrapper)
- Source: 10 bytes, calls __CxxFrameHandler(a1,a2,a3,a4)
- Doc: "Direct wrapper around MSVC C++ exception handler" ✓
- Doc: "Calls __CxxFrameHandler(a1, a2, a3, a4)" ✓
- Calls: __CxxFrameHandler ✓
- Moddability: hardcoded ✓
- No errors

## FUN_004A11F0 — PASS
Source: docs/01-engine-architecture.md (No-op thunk)
- Source: 10 bytes, returns nullsub_3(&unk_7CE2A4)
- Doc: "Calls nullsub_3(&unk_7CE2A4)" ✓
- Doc: "effectively a no-op" ✓
- Globals: unk_7CE2A4 ✓
- Moddability: hardcoded ✓
- No errors

## FUN_00466A70 — PASS
Source: docs/01-engine-architecture.md (ConfigObjectDestructor)
- Source: 160 bytes, sets this[65]=dword_7C7368[this[66]], free linked list
- Doc: "Sets this[65] = dword_7C7368[this[66]]" ✓
- Doc: "Calls sub_566650(&byte_5EA438)" ✓
- Doc: "If !byte_7C7064, calls sub_430F00(&byte_7C56C0)" ✓
- Doc: "Iterates singly-linked list starting at this[17]" ✓
- Doc: "Node: [0]=data_ptr, [4]=next, [8]=active_flag" ✓
- Doc: "Frees inner buffer via sub_587BCF twice, then frees node" ✓
- Doc: "Zeroes this[17..20]" ✓
- Doc: "Calls sub_486F30(aCustom_0, -1)" ✓
- All globals verified ✓
- Moddability: hardcoded ✓
- No errors

## FUN_004DB090 — PASS
Source: docs/01-engine-architecture.md (UI Class Constructor / VTable Init)
- Source: 31 bytes, sets *this = &off_5AD06C, if (a2 & 1) free via sub_587BCF
- Doc: "Sets *this = &off_5AD06C (vtable pointer)" ✓
- Doc: "If (a2 & 1): calls sub_587BCF (free wrapper)" ✓
- Globals: off_5AD06C ✓
- Calls: sub_587BCF ✓
- Moddability: hardcoded ✓
- No errors

## FUN_0047F080 — PASS
Source: docs/01-engine-architecture.md (VTable Pointer Constructor)
- Source: 22 bytes, FUN_00488b00(1,0xffffffff), *param_1 = &PTR_LAB_005a6dc8
- Doc: "Calls FUN_00488b00(1, 0xffffffff)" ✓
- Doc: "Sets *param_1 = &PTR_LAB_005a6dc8 (vtable pointer assignment)" ✓
- Doc: "Returns param_1" ✓
- Calls: FUN_00488b00 ✓
- Moddability: hardcoded ✓
- No errors

## FUN_0041A170 — PASS
Source: docs/02-ai-system.md (AI Vehicle Damage Event)
- Guards: DAT_007d0308 (race active) and DAT_007cf3c8 timer non-zero
- Calls FUN_004c7bd0() for collision check ✓
- Collision: audio ID 0x34. No collision (SessionType 7): audio 0xc4 ✓
- Calls FUN_004144d0, FUN_004144f0(uVar2,...), FUN_00418560 ✓
- All 4 callees verified ✓
- Moddability: hardcoded ✓
- No errors

## FUN_0042A6F0 — PASS
Source: docs/02-ai-system.md (Post-Pit Cleanup / Exit)
- Calls FUN_004bd760 (pit exit animation) ✓
- If +0x4584 clear: increment stint +0x45e0 ✓
- Session 7 race: clear +0x4534 pit crew timer ✓
- Set +0x447c pit-exit timestamp to current time + 0.5s ✓
- All 4 logic bullets verified ✓
- Moddability: hookable ✓
- No errors

## FUN_004B51E0 — PASS
Source: docs/02-ai-system.md (Driver Name/Team Copy)
- Copies name from param_2+0x4620 via _strncpy(param_1+1, ..., 0x3f) ✓
- Extracts team name from path at param_2+0x4714 (finds last backslash) ✓
- Calls FUN_004b4f70 ✓
- Struct offsets +0x4620, +0x4714 verified ✓
- No errors

## FUN_004F3C80 — PASS
Source: docs/03-engine-wear-damage.md (Engine Section Parser)
- Full field map table with 34 fields verified against source:
  - +0x674 FuelConsumption ✓, +0x67c FuelEstimate ✓, +0x684 EngineInertia ✓
  - +0x68c/0x694 IdleRPMLogic min/max × _DAT_005ad258 ✓
  - +0x69c IdleThrottle range-checked → flag at +0x6a0 ✓
  - +0x6ac/0x6b4 LaunchRPMLogic × _DAT_005ad258 ✓
  - +0x6bc RevLimitLogic × _DAT_005ad258 ✓
  - +0x6c8 RPMTorque array, +0x6c4 point count ✓
  - +0x12c8 OptimumOilTemp + _DAT_0059eac8 ✓
  - +0x12d0 CombustionHeat, +0x12d8 EngineSpeedHeat ✓
  - +0x12e0 OilMinimumCooling, +0x12e8/0x12f0 OilWaterHeatTransfer ✓
  - +0x12f8 WaterMinimumCooling, +0x1300/0x1308 RadiatorCooling ✓
  - +0x1310/0x1318 LifetimeEngineRPM × _DAT_005ad258 ✓
  - +0x1320/0x1328 LifetimeOilTemp ± _DAT_0059eac8 ✓
  - +0x1330 LifetimeAvg, +0x1338 LifetimeVar ✓
  - +0x1340 EngineEmission[3], +0x1358 OnboardStarter, +0x135c StarterTiming[3] ✓
- Validation logic: IdleRPMLogic, LaunchRPMLogic, RPMTorque warnings verified ✓
- DAT_007c569c != 5 gates asserts ✓
- Constants verified ✓
- Moddability: correctly identified as .svm/.hdv parameters ✓
- No errors

## FUN_0043E050 — PASS
Source: docs/04-tire-system.md (TireModelInit)
- Calls FUN_005881c0 ✓
- Sets *(param_1 + 0x1f00) from stack parameter ✓
- Zeroes +0x60 and +0x64 (wheel states) ✓
- Computes tire model step: `400 >> (TireModelMode & 0x1f)` → +0x68 and _DAT_005e5240 ✓
- _DAT_005e5238 = squared, _DAT_005e5240 doubled ✓
- Init chain: all 8 functions verified ✓
- If FUN_00567740() != 0x200: calls FUN_00567780 ✓
- Frees non-null params via FUN_00587bcf ✓
- Globals: DAT_007ce958 (TireModelMode), _DAT_005e5240, _DAT_005e5238 ✓
- Moddability: configurable ✓
- No errors

## FUN_004BC0E0 — PASS (minor doc claim note)
Source: docs/06-session-race-logic.md (Disqualification Handler)
- Guard: param_1[0xc] != 3 (not already DSQ) ✓
- Creates "Disqualified: <reason>" message ✓
- Increments DAT_0083ee60 penalty count (max 0x3ff) ✓
- Advances DAT_008aae64 by 0x1b0 ✓
- Calls FUN_004b33b0(4, 0x1c, ...) ✓
- Calls FUN_0041a940 (apply DSQ) ✓
- Note: Doc claims "Sets param_1[0xc] = 3" — source only checks guard; state set likely in FUN_0041a940. Minor imprecision.
- Moddability: not stated — acceptable
- No factual errors

## FUN_0047D800 — PASS
Source: docs/06-session-race-logic.md (Season Stats Display)
- Reads season DB via FUN_00489cb0/FUN_004894d0 ✓
- Checks for PrevYear, Drivers, Times sections ✓
- Iterates driver entries, loads name/time via FUN_00567970 ✓
- Formats via FUN_0058815f ✓
- Writes via FUN_00489600 ✓
- All callees verified ✓
- Moddability: no — UI display only ✓
- No errors

## FUN_004A0760 — PASS
Source: docs/06-session-race-logic.md (Win Videos)
- Calls vtable method on DAT_005eb10c and FUN_004186a0 ✓
- Calls FUN_004b17b0 sound setup ✓
- Checks escape, player mode, DAT_007d032c (videos enabled) ✓
- Builds path `<track>\winRace.bik` and plays via FUN_004f9b70 ✓
- Championship check: FUN_004c2850 → season finished == 3 ✓
- Driver+0x19c == 0: builds `<track>\windrivers.bik` ✓
- Checks input via FUN_0047c360 ✓
- Sets DAT_005cc9e8 = 3 ✓
- All callees verified ✓
- Moddability: visual reward ✓
- No errors

## FUN_00472630 — PASS (minor note)
Source: docs/06-session-race-logic.md (SessionEnter_SupportCheck)
- Writes DAT_007d0410 (RaceMode) to param_1+0x324 — doc says "Writes SessionType" but writes RaceMode (DAT_007d0410, not DAT_007c56a4) ✓
- Calls FUN_004ae9f0 for setup ✓
- Checks vehicle count vs threshold: sets +0x310=2 or 0 ✓
- Calls: FUN_00487010, FUN_0058815f, FUN_004ae9f0, FUN_0048b810 ✓
- Moddability: low-medium ✓
- No factual errors

## FUN_004A4110 — PASS
Source: docs/06-session-race-logic.md (AI Overtaking / Aggression Probability)
- Iterates vehicles, removes invalid ones ✓
- Session 7 (race): return 1 ✓
- Multi-stage probability with early/mid/late branching ✓
- Probability modified by population, ability, track multiplier ✓
- Calls: FUN_0042add0, FUN_00426cc0, FUN_0042ae90, _rand ✓
- Moddability: yes — many probability constants ✓
- No errors (entry brief for ~1500B function but accurate)

## FUN_004C7BD0 — PASS
Source: docs/06-session-race-logic.md (IsDriverPlayer)
- Compares driver ID at param_1+0x4894 to player vehicle driver ID ✓
- Player vehicle: DAT_007c54f0[DAT_007c54e4] + 0x4894 ✓
- Returns CONCAT31(isPlayer, driverID>>8) ✓
- Moddability: pure query ✓
- No errors

## FUN_004DAE00 — PASS
Source: docs/06-session-race-logic.md (Pit Exit Readiness Check)
- Checks +0x14 timer, +0x1c timer ✓
- Calls FUN_004d1b50(0) → checks VehiclePitFlags ✓
- Verifies player ahead, engine running ✓
- Calls: FUN_004d1b50 ✓
- Moddability: timer thresholds ✓
- No errors

## FUN_0041C090 — PASS
Source: docs/06-session-race-logic.md (Display Message 0x202)
- Guards: DAT_007d0308, DAT_007cf3c8 timer non-zero ✓
- Calls FUN_004144f0(0x202, ...) ✓
- Calls FUN_00418560 ✓
- No errors (minimal entry but accurate)

## FUN_004D9DD0 — PASS
Source: docs/06-session-race-logic.md (Timer Display Render)
- Calls FUN_004d98a0 countdown ✓
- Formats via FUN_0058815f with DAT_005ccef0 ✓
- Renders via FUN_004d7e40 (3 calls) ✓
- Calls FUN_00423a00 ✓
- All callees verified ✓
- No errors

## FUN_0059A9CA — PASS
Source: docs/06-session-race-logic.md (triage entry)
- Triage: "String/buffer copy with reference counting" ✓
- Source: copies buffer with shared/deep copy logic ✓
- Refcount increment on shared data ✓
- Self-assignment check ✓
- Complexity: Medium — ref-counted buffer ✓
- No errors

## FUN_00587C20 — FAIL
Source: docs/06-session-race-logic.md (triage entry at line 3165)
- Doc claims: "String hash function with bit mixing" / "Name/string lookup hashing"
- Source implements: **substring search** (strstr equivalent), NOT a hash
- XOR with 0x7efefeff is standard bit-parallel substring search optimization, not hash
- Returns pointer to first occurrence of param_2 within param_1, or null
- **Correction:** Purpose = "Substring search (strstr)" — string search function

## FUN_00567AF0 — PASS
Source: docs/06-session-race-logic.md (triage entry)
- Doc: "thunk to FUN_00567b10 (trampoline)" ✓
- Source: 5-byte thunk at 0x00567af0 → 0x00567b10 ✓
- Category: Thunk ✓
- No errors

## FUN_0058DAD7 — PASS
Source: docs/06-session-race-logic.md (triage entry)
- Doc: "__trandisp2 — CRT internal dispatch helper" ✓
- Source: library function __trandisp2 from MSVC CRT ✓
- Category: Library ✓
- No errors

## FUN_004B57F0 — PASS
Source: docs/06-session-race-logic.md (Car Physics State Initializer)
- Zeros most of 0x3e5+ dword fields (~4KB struct) ✓
- Sets +0x35e = 0xfe967699 ✓
- Sets +0x269=4, +0x26a=2, +0x26b=2 ✓
- Sets +0x3e3=5, +0x3e4=0x44610000 (900.0f) ✓
- Calls: FUN_004ba820 x3, FUN_005668b0, FUN_004ff670, FUN_00568ba0 ✓
- Calls: FUN_00568be0(1), FUN_00568c60 ✓
- Sets DAT_005acd24 at +0x3dd, flags at +0xf79/+0xf7a=1 ✓
- All verified ✓
- Moddability: configurable ✓
- No errors

## FUN_0051C099 — PASS
Source: docs/06-session-race-logic.md (Track Map Pixel Fill)
- Reads stride from +0x8c ✓
- Reads row count from +0x96 ✓
- Loops +0x110 times (columns) ✓
- Fills with DWORD-replicated byte then residuals ✓
- Calls FUN_0051593f for row duplication ✓
- Moddability: hookable ✓
- No errors

## FUN_0053C630 — PASS
Source: docs/06-session-race-logic.md (Doubly-Linked List Unlink)
- If prev (+0x1e4): prev.next = this.next ✓
- If next (+0x1e8): next.prev = this.prev ✓
- If head (DAT_008b8f28) == this: head = next ✓
- Moddability: hardcoded ✓
- No errors

## FUN_0052855A — PASS
Source: docs/06-session-race-logic.md (Rendering Branch on DAT_005d79dc)
- If DAT_005d79dc == 0: calls FUN_0052a6ec ✓
- Else: calls FUN_0052ab4e (alternate render) ✓
- Moddability: hardcoded ✓
- No errors

## FUN_004EF680 — PASS
Source: docs/06-session-race-logic.md (RideHeightDelta)
- Sets param_2[2] = *(param_1+0x74c) ✓
- Resets param_2[0],[1] to 0 ✓
- Computes: ((+0x3590 - +0x3610) + (+0x3688 - +0x3708)) × _DAT_0059e450 ✓
- Moddability: hookable ✓
- No errors

## FUN_004EFF00 — PASS
Source: docs/06-session-race-logic.md (Force Direction Projection)
- Zero check on +0x34ec/f0/f4 → return 0 ✓
- Normalized dot product: -(x_norm×dx + y_norm×dy + z_norm×dz) ✓
- Direction at +0x34b8, +0x34c4, +0x34d0 ✓
- All offsets verified ✓
- Moddability: hardcoded ✓
- No errors

## FUN_0051BD61 — PASS
Source: docs/06-session-race-logic.md (Audio Ring Buffer Manager)
- Reads buffer from +0x188 ✓
- If empty: allocates via vtable at *(param_1+4)+0x1c ✓
- Calls playback vtable at +0x19c+4 ✓
- Flushes consumed data via +0x1a4+4 ✓
- Resets ring when ≥ buffer size ✓
- Struct offsets verified ✓
- Moddability: hardcoded ✓
- No errors

## FUN_0050A0F0 — PASS
Source: docs/06-session-race-logic.md (8-bit Vertex Position Decompression)
- Base: +0x1050×param_2 + +0x1054×param_3 + +0x18 ✓
- Stride 2 bytes, count from +0x1058 ✓
- Reads signed byte X,Y, scales by _DAT_0059e774 ✓
- Outputs vec4 (x, y, 0.0, 1.0) ✓
- Calls FUN_00507845 if +0x10 set ✓
- Moddability: hardcoded ✓
- No errors

## FUN_0052DE00 — PASS
Source: docs/06-session-race-logic.md (NetworkColorIsDefault)
- Reads color from +0x24a4 (deref) or +0x24f0 (fallback) ✓
- Byte-swaps RGBA→ARGB ✓
- Calls FUN_0052da30(swappedColor) ✓
- Returns TRUE if -1 (default) ✓
- Moddability: hardcoded ✓
- No errors

## FUN_0041FE00 — PASS
Source: docs/06-session-race-logic.md (ConfigSectionSearchByKeyValue)
- Gets section count via FUN_004c2990 ✓
- Iterates reverse order ✓
- Checks entry value == 10, reads name via FUN_004c0a20 ✓
- Compares via FUN_00588410 ✓
- Returns matching index (0 if not found) ✓
- Moddability: hardcoded ✓
- No errors

## FUN_00541340 — PASS
Source: docs/06-session-race-logic.md (Texture/Surface Allocation)
- operator_new(0x4c) allocates 76 bytes ✓
- First dword = 2, two arrays of 9 dwords zeroed ✓
- Values: 0x22, 0x142, 0x18 — width/height/stride ✓
- Two copies at +0x00 and +0x24 ✓
- Calls FUN_00540df0 validation ✓
- Returns 0 success / 0xffffffff failure ✓
- Moddability: hardcoded ✓
- No errors

## FUN_0054B770 — PASS
Source: docs/06-session-race-logic.md (Transformation Matrix Update)
- If parent null and flag &1: copy +0xD4→+0x114 ✓
- Else: COM vtable at DAT_008B8F24+8 ✓
- If flag &0x4000: scale by +0x194/0x198/0x19C → +0x1A0 ✓
- Else: copy +0x114→+0x1A0 directly ✓
- Struct offsets verified ✓
- Moddability: hardcoded ✓
- No errors

## FUN_0042ED50 — PASS
Source: docs/06-session-race-logic.md (NameStringCopy)
- _strncpy(param_1+0x70, param_2, 0x3f) ✓
- Null-term at param_1+0xaf ✓
- Moddability: hardcoded ✓
- No errors

## FUN_0042BDA0 — PASS
Source: docs/06-session-race-logic.md (Timer conversion with sin)
- param_1 × DAT_0059e9b0 → FUN_005895a2 (sin) ✓
- __ftol() → DAT_007c5694 ✓
- Globals verified ✓
- Moddability: hardcoded ✓
- No errors

## FUN_004B3BD0 — PASS
Source: docs/06-session-race-logic.md (Random Noise Table Initialization)
- Sets *param_1 = 0.0 ✓ (source: `*param_1 = 0.0`)
- Seeds RNG with GetTickCount() via FUN_005884e0 ✓
- Generates 256 uniform random floats in [0,1): `rand() * _DAT_0059e6e0` ✓
- Generates 256 signed random floats in [-1,1): `rand() * _DAT_005accf0 - _DAT_0059e43c` ✓
- Calls FUN_0055687b at param_1+0x201 ✓
- Calls list: GetTickCount, _rand, FUN_005884e0, FUN_0055687b ✓
- Moddability: hardcoded ✓
- No errors found

## FUN_0042DCE0 — PASS
Source: docs/06-session-race-logic.md (Bounded Array Element Accessor)
- Bounds check: `0 <= param_2 < *(param_1 + 8)` ✓ (source: `if ((-1 < param_2) && (param_2 < *(int *)(param_1 + 8)))`)
- Returns element at `*(*(param_1 + 0xC) + 4 + param_2 * 8)` ✓
- Returns 0 if out of bounds ✓
- Moddability: hardcoded ✓
- No errors found

## FUN_00435240 — PASS
Source: docs/06-session-race-logic.md (StateFlagCheck inverse bool wrapper)
- Calls FUN_00418940() ✓
- Returns bool: `FUN_00418940() == '\0'` ✓
- Moddability: hardcoded ✓
- No errors found

## FUN_004DBB60 — PASS (minor width note)
Source: docs/06-session-race-logic.md (DrawDebugTextOverlay)
- Buffer alloc via FUN_0049c6d0(local_40,0x40) ✓
- Draws first line at param_1+0x32 with yellow 0xffff00 ✓
- Moves to param_1+0x145 for remaining lines ✓
- Draws 4 more lines with white 0xffffff ✓
- Widths: first call uses 0x2e (46), later calls 0x32 (50) and 0x5a (90) — doc says "All strings at 0x32 and 0x5a" — minor: first width is 0x2e not 0x32 ✓ (acceptable)
- Moddability: hardcoded ✓
- No factual errors

## FUN_0054BB40 — PASS
Source: docs/06-session-race-logic.md (UI List Node Manager)
- If +0x214 null: allocates 0x28 bytes via operator_new + FUN_005510f0(param_2+0xc) ✓
- Walks to tail via +0x24, appends new node ✓
- Node stores count at +0x14, array at +0x18 with stride 0x88 ✓
- Calls FUN_00551440, FUN_00557350 ✓
- Rendering params: color 0xdfdf1f, size 100.0f (0x42c80000), type 2, alpha 0x10 ✓
- If +0x218 null: calls FUN_00559200 ✓
- Calls FUN_004b0170 ✓
- Calls list verified: FUN_005510f0, FUN_00551440, FUN_00557350, FUN_00559200, FUN_004b0170 ✓
- Moddability: configurable ✓
- No errors found

## FUN_005079A1 — PASS
Source: docs/06-session-race-logic.md (Texture Float-to-32bit ARGB Pack)
- If +0x1048 != 0: calls FUN_00506ce2(param_4) palette lookup ✓
- Rounds RGBA floats, scales by DAT_0059fec8, packs 32-bit ARGB ✓
- Loop over count at +0x1058 ✓
- Calls: FUN_00506ce2, FUN_00507473 ✓
- Moddability: hardcoded ✓
- No errors found

## FUN_00517F72 — FAIL
Source: docs/06-session-race-logic.md (AnimationStateCheck)
- Doc claim: "If flagA NOT set AND flagB NOT set → returns false" — INCORRECT. Source shows when both flags not set: bVar3 stays true, then FUN_00513bd1 + FUN_00517f35 comparison runs, returns true if animation ID changed, false if same. NOT a simple false return.
- Doc claim: "Otherwise → returns true (state allows animation switch)" — MISLEADING. Returns true only when bVar3 true AND animation ID changed. Not a simple permission flag.
- Bit flag checks at +0x10c (0x20) and +0x5d (0x8) ✓
- FlagA set AND +0x5c & 0x300 == 0x300 → bVar3=false → returns false ✓
- Calls FUN_00513bd1, FUN_00517f35 ✓
- Struct usage: +0x10c, +0x5d, +0x5c, +0x100 all verified ✓
- **Correction:** Not a simple state check — it's an "Animation Change Detector". Logic: guard flags determine whether to check for animation change; if guards pass, returns whether animation ID changed. If guards block, returns false.

## FUN_00513CF0 — PASS
Source: docs/06-session-race-logic.md (Music/Sound Selection Controller)
- Checks bit 0x20 at +0x10c (loop flag): if set AND +0x5c & 0x300 == 0x300 → return (skip) ✓
- If loop flag not set: checks +0x5d bit 8 (stop flag) → return ✓
- Calls FUN_0051923d(*(param_1+0x100), param_2, param_3) ✓
- Stores returned handle back to param_1+0x100 ✓
- Moddability: hardcoded ✓
- No errors found

## FUN_0053D340 — PASS
Source: docs/06-session-race-logic.md (LinkedListAppend)
- If DAT_008b8e20 non-null: walks via +0x870 to tail, appends ✓
- If empty: sets DAT_008b8e20 = param_1, zeros +0x86c and +0x870 ✓
- Globals: DAT_008b8e20 ✓
- Moddability: hardcoded ✓
- No errors found

## FUN_0042AE90 — PASS
Source: docs/06-session-race-logic.md (StateFlagsLookup)
- Reads +0x4588, subtracts 1 ✓
- Wraps negative to 0 via (uVar1 & ((int)uVar1 < 0) - 1) ✓
- Multiplies by 0x10, adds base +0x4590 ✓
- Struct offsets: +0x4588, +0x4590 ✓
- Moddability: hardcoded ✓
- No errors found

## FUN_0051A4F2 — PASS
Source: docs/06-session-race-logic.md (UI List/ComboBox Constructor)
- Allocates 0x74 bytes, stores at +0x184 ✓
- Branch on param_2: if 0 → allocates 0x500, partitions 10×0x80 ✓
- If param_2≠0 → iterates items from +0xc4 (stride 0x15), checks selected flag at byte offset 200 ✓
- Calls FUN_00515927 for name hashing ✓
- Count from +0x20 ✓
- Struct offsets: +0x184, +0x20, +0xc4 ✓
- Calls: FUN_0051a4b7, FUN_005199d5, FUN_00515927, FUN_00519bb2, FUN_00519d51 ✓
- No errors found

## FUN_00545090 — PASS
Source: docs/06-session-race-logic.md (Doubly-Linked List Node Removal)
- If node has next (+0x1b8): sets next.prev = node.prev ✓
- If node has prev (+0x1b4): sets prev.next = node.next ✓
- If node is head (param_1+0xf8): sets head = node.next ✓
- Struct offsets: +0xf8, +0x1b4, +0x1b8 ✓
- No errors found

## FUN_004A5E80 — PASS
Source: docs/06-session-race-logic.md (ObjectStateClear)
- Sets +0x184 = 0 ✓
- Sets +0x180 = 0 (byte) ✓
- If +0x14 != 0: calls FUN_004a3fe0() ✓
- Struct offsets: +0x180, +0x184, +0x14 ✓
- No errors found

## FUN_0047A640 — PASS
Source: docs/06-session-race-logic.md (Command Dispatch 0x13 with Guard)
- Calls (*DAT_007cd8c0 + 0x1c)(0x13) ✓
- If result != 0: calls FUN_00477280(param_1) ✓
- Returns 0 ✓
- No errors found

## FUN_004A55A0 — PASS
Source: docs/06-session-race-logic.md (Conditional Dispatch Three Guards)
- If +0x10 non-null: calls FUN_004a3570(param_3) ✓
- If +0xc non-null: calls FUN_004a3570(param_3) ✓
- If +0x14 non-null: calls FUN_004a4050(param_2) ✓
- No errors found

## FUN_004BB7A0 — PASS
Source: docs/06-session-race-logic.md (Short Computation / Race/Timing Struct Init)
- Zeros 4 pairs of ints starting at +0x10 (stride 2) ✓
- Zeros: [0], [0x23], [0x24], [0x25], [0xc], [0x29] ✓
- Sets sentinels: [1]=-1, [9]=-1, [0xb]=-1 ✓
- Sets [10] = 0xbf800000 (-1.0f) ✓
- Calls FUN_004bb950() ✓
- No errors found

## FUN_004A2A90 — PASS
Source: docs/07-pit-system.md (Pit Crew Animation Loader)
- Loads .mts animation file ("FUELRIG.MTS") ✓
- Parses ACTOR, DETAIL, MESH, POSITION, MOVE, ROTATE directives ✓ (confirmed by string constants in .c)
- Maps wheel mesh names to wheel indices 0-3 ✓
- Actor struct stride 0x78 ✓ (allocated as `iVar2 * 0x78 + 4`)
- Fields: +0x03 lollipop flag, +0x00 detail level uint16, +0x26-0x2a POSITION xyz floats ✓ (offset notation is int-index style per decompiler — struct audit flags this)
- No factual errors (offset notation is decompiler artifact, not doc error)

## FUN_004A6200 — PASS
Source: docs/07-pit-system.md (Pit Stop Ready Check)
- Sets ready flag (byte at param_1+100=1) ✓
- Checks speed squared vs DAT_005acb50 threshold ✓
- Calls FUN_004f1b50 (pit animation) ✓
- Calls FUN_004ef930 (pit lane init) ✓
- Calls FUN_0042a3d0 ✓
- Calls FUN_004a6340 (pit stop timer) ✓
- Calls FUN_0040d3c0 (audio event) ✓
- Moddability: DAT_005acb50 distance threshold ✓
- No errors found

## FUN_004B1900 — PASS
Source: docs/08-file-formats.md (PlayerFile::Post)
- Logs entry via FUN_004d7a50/FUN_004d7aa0 ✓
- Calls FUN_004b0770(1) player file save ✓
- If +0x1f78 != 4: calls FUN_004b17b0 ✓
- No errors found

## FUN_004C78F0 — PASS
Source: docs/08-file-formats.md (Nationality/Driver Info Loader)
- Vehicle array stride 0x424 with DAT_008ac394[param_2] ✓
- +0x4620 section name via FUN_004c6980 ✓
- +0x4660 Nationality max 0x17 ✓
- +0x4678 Description from .veh +0x3f ✓
- +0x46b8 Number from .veh +0x1f ✓
- +0x4714 filename from .veh +0x00 ✓
- +0x4898 vehicle index = param_2 ✓
- No errors found

## FUN_0046C820 — PASS
Source: docs/08-file-formats.md (Q_Order0000.bmp Qualifying Order Reset)
- If +0x174 string empty: loads Q_Order0000.bmp via FUN_00497ad0 ✓
- Fills DAT_007cd470 buffer (0x68=104 entries) with 0xFFFFFFFF ✓
- Resets +0x178 to -1 ✓
- If non-empty: populates DAT_007cd2b8 from vehicle array +0x4894 ✓
- Remaining slots filled with -1 ✓
- No errors found

## FUN_004B70B0 — PASS
Source: docs/08-file-formats.md (LoadVehicleEntries)
- Validates each entry via FUN_004b72a0 ✓
- Registers driver name via FUN_004c6980 ✓
- Sets DAT_005c329c = valid entries - 1 ✓ (source: `DAT_005c329c = uVar1` where uVar1 = iVar4 - 1)
- Resets counters, loads car models via FUN_004c5690 ✓
- Calls list: FUN_004b87a0, FUN_004b72a0, FUN_004ef5a0, FUN_004c7b20, FUN_00566650, FUN_004c6980, FUN_0042bc80, FUN_004c5690, FUN_004c54f0, FUN_0042cf10 ✓
- Moddability: high ✓
- No errors found

## FUN_00423A00 — PASS
Source: docs/08-file-formats.md (Binary Search in String Table)
- Standard binary search on sorted 0x10-byte entries ✓
- Each entry: string pointer at offset 0, paired string at offset 8 ✓
- Returns 0 on match (copies string to param_3), -1 on miss (copies param_2 to param_3) ✓
- No errors found

## FUN_00462E00 — PASS
Source: docs/08-file-formats.md (Vehicle Name Accessor)
- Returns name at *param_1+0xbc, or &DAT_005ea438 if null ✓
- No errors found

## FUN_004C45D0 — FAIL
Source: docs/08-file-formats.md (Vehicle Data Copy)
- Doc claim: "Copies 6 data strings from param_2 (at offsets 0, 2, 4, 6, 8, 10)" — source shows FUN_00566650 called on param_2[0],[2],[4],[6],[8] — only 5 strings, NOT 6. Index 10 is NOT used. Count error.
- Doc claim: function described as only string copying — source shows massive field-by-field copy (~800 bytes, copies 20+ fields from param_2 to param_1 at offsets 0x28-0x1fc, plus string area at 0x74-0x2bc). Major under-description.
- **Correction:** "Copies 5 data strings from param_2 (indices 0,2,4,6,8) to path registry via FUN_00566650. Then copies ~20 fields (struct at param_2+0x1c to param_1+0x28—0x1fc, with block copies of sizes 8, 0x8, 0x40, 0x40, 0x40, 0x40, 0x40, 0x100, 0x80 bytes) from input struct to target. Secondary purpose is struct duplication."

## FUN_00567DB0 — PASS
Source: docs/08-file-formats.md (Hash Table Lookup by Name)
- Looks up entry in hash bucket by name ✓
- Uses FUN_00567d00 for hash (if param_3==-1) ✓
- Walks chain via +4 next ptr, compares names at +0x10 via FUN_00588410 ✓
- No errors found

## FUN_005953B8 — PASS
Source: docs/08-file-formats.md (triage: 80-bit float to IEEE 754)
- 80-bit extended precision float to 32/64-bit IEEE conversion ✓
- Handles denormals, NaN, infinity, rounding, normalization ✓
- Bitfield extraction, exponent bias adjustment ✓
- Matches source implementation ✓
- No errors found

## FUN_00553E10 — PASS
Source: docs/08-file-formats.md (Game State Initialization via Virtual Device)
- Sets state parameters through DAT_008b89a0 virtual dispatch (offset 0xfc method) ✓
- IDs 1-6, 0xb, 0xd, 0x12, 0x13, 0xe verified ✓
- Conditional initialization with guard checks ✓
- No errors found

## FUN_0059DBA9 — PASS
Source: docs/08-file-formats.md (Static initializer)
- Calls *DAT_005c753c() — one-time init routine ✓
- If non-zero: sets DAT_007c8314=0x3fe80000, DAT_007c8310=0 ✓
- Calls FUN_004d5984() ✓
- No errors found

## FUN_004B0B20 — PASS
Source: docs/08-file-formats.md (Filename Extraction from Path)
- Calls FUN_00463c40(), if result: strncpy to param_1 ✓
- Else: copies from FUN_004b0b10() to local buffer ✓
- Walks backward finding last backslash, copies filename ✓
- Calls FUN_00566810() ✓
- No errors found

## FUN_004C58A0 — PASS
Source: docs/08-file-formats.md (String Copy with Validation)
- Validates param_4 via FUN_004c5840 ✓
- Validates param_3 via FUN_005679c0 ✓
- Gets source via FUN_00567970 ✓
- strncpy with null-term, max param_2-1 ✓
- Returns 0 success, 1 failure ✓
- No errors found

## FUN_0058A163 — PASS
Source: docs/08-file-formats.md (File Write Wrapper with Lock)
- FUN_0058c1b1 lock acquire ✓
- FUN_0058e41b file position ✓
- FUN_0058d04d write operation ✓
- FUN_0058e4a8 position update ✓
- FUN_0058c203 lock release ✓
- Returns write result ✓
- No errors found

## FUN_0058C789 — PASS
Source: docs/08-file-formats.md (File Seek via SetFilePointer)
- Gets handle via FUN_00595a1f(param_1) ✓
- SetFilePointer(hFile, param_2, null, param_3) ✓
- On success: clears bit 1 at indexed entry DAT_008d4920 ✓
- On failure: stores error via FUN_0058af5c ✓
- No errors found

## FUN_004C6980 — PASS
Source: docs/06-session-race-logic.md (Set driver name)
- strncpy(param_1+0x4620, param_2, 0x3f) ✓
- Null-terminate at +0x465f ✓
- Calls FUN_004c6a10() (name change notification) ✓
- No errors found

## FUN_005152EB — FAIL
Source: (none — no doc entry found)
- IDA-only function, 24 bytes, calls sub_5147EA(a1, 1)
- Returns 0 if sub_5147EA result >= 0, else returns error
- **No documentation entry exists** — no triage line, no `## FUN_` entry, no reference in any docs/ file
- **Needs:** triage entry + doc entry in appropriate doc file (likely docs/08-file-formats.md as file I/O wrapper)

## FUN_004D4A80 — PASS
Source: docs/09-track-system.md (Telemetry Data Dump)
- Gate: VehicleCount>0, DAT_007ce9d0>0, (SessionType!=7 or DAT_007ce9f4!=0) ✓
- Finds first vehicle with +13000==0 ✓
- Generates random 4-byte seed ✓
- Outputs telemetry: wheel data, vehicle-level data ✓
- Reads DriverName +0x4620 ✓, VehicleDescription +0x4678 ✓, FilePath +0x4714 ✓
- Reads +0x4794, +0x4898 ✓
- All globals verified: DAT_007c56a4, DAT_005c329c, DAT_007c54f0, DAT_007ce9d0, DAT_007ce9f4 ✓
- No errors found

## FUN_00461020 — PASS
Source: docs/09-track-system.md (Server Close Track Signal)
- Calls FUN_004b33b0(4,0x25,...) progress bar event ✓
- Network send via FUN_0057a680/.../.../... ✓
- Sets param_1+0x29 = 0 (closing flag) ✓
- Allocates 8-byte message node ✓
- Formats "*** Closing track" string ✓
- Appends to linked list ✓
- No errors found

## FUN_0040D2D0 — PASS
Source: docs/09-track-system.md (Camera Target: Next/Prev Vehicle)
- If param_1==0: DAT_007c54dc-1, else +1 ✓
- Wraps at [0, VehicleCount) ✓
- Gets TeamID from +0x4894, calls FUN_0040d240 ✓
- Refreshes scene nodes via FUN_004f0d20 loop ✓
- No errors found

## FUN_00477BA0 — PASS
Source: docs/09-track-system.md (Scene List Search by Path)
- Iterates list at param_1+0xf0 (count +0xfc) ✓
- Compares each entry's name at +0x3c→+0x104 against DAT_007ce5ec ✓
- String comparison via 2-byte char loop (FUN_00588410 style) ✓
- Falls back to first entry index 0 if no match ✓
- Calls FUN_004c55b0, FUN_004c54f0 on match ✓
- No errors found

## FUN_00455290 — PASS
Source: docs/09-track-system.md (Input Action Registration)
- Calls FUN_00566650 for each action name ✓
- ~45 named actions registered ✓ (source shows 45 FUN_00566650 calls)
- Actions cover: steering, accel, brake, gears 1-7, neutral, reverse, clutch, TC override, launch control, LCD controls, pit request, RPM limiter, brake bias, look directions, replay, pause, restart, head tracker, labels, ignition, starter, headlights, handbrake ✓
- No errors found

## FUN_0059D822 — PASS
Source: docs/10-vehicle-physics.md (Gear 7-10 Setup Field Readers)
- Reads Gear7Setting, Gear8Setting, Gear9Setting, Gear10Setting via FUN_00565760 ✓
- Calls FUN_004f61d6 post-process ✓
- No errors found

## FUN_004A6DB0 — PASS
Source: docs/10-vehicle-physics.md (VehicleControlEnabled)
- SessionType 7 or 0 gate ✓
- Check 4 suspension corners for broken components ✓ (+0x834/0x874, +0x95c/0x99c, +0xa84/0xac4, +0xbac/0xbec)
- FinishState != 1 and != 3 (+0x4064) ✓
- DAT_007ce814 override check ✓
- Calls FUN_004d21d0() ✓
- No errors found

## FUN_0049BA90 — PASS
Source: docs/10-vehicle-physics.md (Pit/State Flag Check)
- Returns *(DAT_007c54e0 + 0x4070) > 0 ✓
- Globals: DAT_007c54e0 (PlayerVehiclePtr) ✓
- No errors found

## FUN_004414D0 — PASS
Source: docs/10-vehicle-physics.md (WheelDataCopy)
- Copies 4 wheel state blocks stride 0x119 dwords ✓
- Transfers +0x1c5c/0x1c60 → +0x1c64/0x1c68 ✓
- Transfers +0x1e38/0x1e3c → +0x1e40/0x1e44 ✓
- Copies per-wheel suspension data across 4 wheels ✓
- Iterates linked state array: copies 12 dwords per entry from +0x134/+0x14c ✓
- Calls: FUN_0043f7f0, FUN_0056ecf0, FUN_0056ee40, FUN_0056f020, FUN_00441450 ✓
- Moddability: hardcoded ✓
- No errors found

## FUN_00410F60 — PASS
Source: docs/01-engine-architecture.md (Command Dispatch with Array Lookup)
- Extracts 6-bit opcode from *param_2 >> 0x12: cases 1-6 ✓
- Each case: validates index, indexes into different arrays ✓
- Arrays at base offsets: +0x2c, +0x38, +0x44, +0x50, +0x5c, +0x68 ✓
- Stride 0x318 (792) or 0x328 (808) per element ✓
- On hit: calls FUN_0054b4d0 with 6 extracted float params ✓
- No errors found

## FUN_00414E54 — FAIL
Source: (none — no doc entry found anywhere)
- IDA-only function, 12 bytes, __usercall with bl/edi/esi registers
- Does: a2[51] += a1; rcr instruction; conditional assignment
- **No documentation entry exists** — no triage, no `## FUN_`, no reference in any docs/ file
- **Needs:** classification + doc entry (likely SEH/exception-related based on __usercall and register passing)

## FUN_0054D080 — FAIL
Source: docs/17-physics-collision.md (Triangle Mesh Face Normal/AABB)
- Processes mesh faces from param_1+0x120/+0x124 ✓
- Two vertex stride modes: 0x30 (rigid), 0x40 (skinned) based on flag 0x800000 ✓
- Averages 3 vertices for face center ✓ (sums, scales by _DAT_0059e98c)
- Computes squared AABB diagonal ✓ (lines 105-107)
- **ERROR: "Computes face normal via normalized cross product"** ✗ — Function reads pre-stored face normals from mesh data (index at +0xc of face entry, normals at param_1+300). Computes dot product of vertex position with normal for plane distance (line 135-139). No cross product computation anywhere.
- Selects dominant axis by comparing ABS of normal components ✓ (lines 140-159)
- **Moddability:** hardcoded ✓
- **Fix:** Replace "computes face normal via normalized cross product" with "Reads pre-stored face normal, computes plane distance via dot product"

## FUN_0044DA00 — PASS
Source: docs/17-physics-collision.md (Collision State Init 1)
- Sets DAT_007ccf18 = 0x2b ✓
- Zeros DAT_007ccf1c/20/24/28/2c ✓
- No errors found

## FUN_00475D30 — FAIL
Source: docs/17-physics-collision.md
- **No documentation entry found** — no `## FUN_00475D30` header in any doc file
- Only triage line in decompiled_full_index_final.md: "collision detection"
- Source: compares DAT_007cd614 vs DAT_007ce250; if different, copies and calls FUN_00455bd0 + FUN_00454da0
- **Needs:** doc entry (likely collision config update / state sync function)

## FUN_0044E2A0 — PASS
Source: docs/17-physics-collision.md (Collision Broadphase Reset, Slot 0x4A)
- Sets DAT_007cd098 = 0x4a ✓
- Zeros DAT_007cd09c/a0/a4/a8 ✓
- Sets DAT_007cd0ac = 0 ✓
- No errors found

## FUN_0044D9D0 — PASS
Source: docs/17-physics-collision.md (Atexit Handler Registration, collision C)
- Calls FUN_00587b3e(&DAT_0044d9e0) ✓
- No errors found

## FUN_0044C740 — PASS
Source: docs/17-physics-collision.md (CollisionGridInit4)
- DAT_007ca470 = 4 ✓
- _DAT_007ca474 = 0 ✓
- _DAT_007ca478 = 0xbf800000 (-1.0f sentinel) ✓
- DAT_007ca47c = 0 ✓
- No errors found

## FUN_0047C960 — PASS
Source: docs/17-physics-collision.md (CollisionSystemInit)
- Calls FUN_0047c9d0() ✓
- Calls FUN_004b9cb0() ✓
- Calls FUN_004b9cd0() ✓
- No errors found

## FUN_0044EA50 — PASS
Source: docs/17-physics-collision.md (Collision Data Registration Block 5)
- Calls FUN_00587b3e(&PTR_LAB_0044ea60) ✓
- No errors found

## FUN_0044DDC0 — PASS
Source: docs/17-physics-collision.md (CollisionTableInit_35)
- Sets DAT_007ccdf8 = 0x35 ✓
- Zeroes 5 following fields (DAT_007ccdfc through DAT_007cce0c) ✓
- No errors found

## FUN_0044C5E0 — PASS
Source: docs/17-physics-collision.md (Collision thunk)
- Delegates to FUN_004531a0() ✓
- No errors found

## FUN_0044EBD0 — PASS
Source: docs/17-physics-collision.md (Collision Init Delegator, 0xEBD0)
- Calls FUN_00587b3e(&DAT_0044ebe0) ✓
- No errors found

## FUN_0049E520 — PASS
Source: docs/17-physics-collision.md (RandomCollisionEvent, probabilistic collision trigger)
- Random from FUN_0058957a() ✓
- If > _DAT_0059e880: high intensity (param=1) ✓
- Else: normal (param=0) ✓
- Calls FUN_0049e4e0 ✓
- No errors found

## FUN_0044DDF0 — PASS
Source: docs/17-physics-collision.md (RegisterInputDevice3)
- Thunk to FUN_00587b3e(&DAT_0044de00) ✓
- No errors found

## FUN_0044E7E0 — PASS
Source: docs/17-physics-collision.md (Initialize Collision Globals C)
- Sets DAT_007cd080 = 0x58 ✓
- Zeros 4 dwords (007cd084-007cd090) ✓
- Sets DAT_007cd094 = 18000 ✓
- No errors found

## FUN_0048C170 — PASS
Source: docs/17-physics-collision.md (Collision Animation Timer Update)
- Calls FUN_00486710 (collision check) ✓
- Checks param_1+0x304 (collisionActive flag) ✓
- Adds delta at +0x318 to timer ✓
- If timer >= _DAT_0059e908: clamps, iterates events ✓
- Calls FUN_00486720 for event count ✓
- Loop calls vtable+0xb8 with (val==4) ✓
- Returns 0 or 0xffffffff ✓
- No errors found

## FUN_0044C4C0 — PASS
Source: docs/17-physics-collision.md (SpatialGridQuery)
- Checks param_2+6 (collision node pointer) with +0x58 flag test ✓
- Calls FUN_0044a070 (narrow-phase check) ✓
- Transforms position to grid coords via ROUND ✓
- Grid 32x32 (0x20), range check [-1, 32) ✓
- Cell at param_1+0x28 + (iVar2*32+iVar1)*4 ✓
- Calls FUN_0044aa30 (broad phase insert) ✓
- Returns node pointer at param_2+6 ✓
- No errors found

## FUN_00491CB0 — PASS
Source: docs/17-physics-collision.md (Short Computation / Collision Query Dispatch)
- Reads this pointer from *param_1 ✓
- Calls FUN_00490940(param_4, param_5) ✓
- Calls FUN_00491280(iVar1+0x1c, uVar3) ✓
- Calls FUN_00490aa0() ✓
- No errors found

## FUN_00486300 — PASS
Source: docs/17-physics-collision.md (UI String Accessor, ### lightweight)
- If *(param_1+200)==0 → returns null ✓
- Else returns *(*(param_1+200)+0x50) ✓
- Falls back to &DAT_005ea438 ✓
- No errors found

## FUN_0056CD70 — PASS
Source: docs/18-physics-dynamics.md (triage entry)
- Sparse Cholesky forward/back substitution (L*D*L^T * x = b) ✓
- Forward substitution loop: `x[i] -= L[i][j] * x[j]` (lines 27-38) ✓
- Diagonal scaling: `dVar4 = _DAT_0059e420 / diag` (line 40) ✓
- Back substitution with sparse column access (lines 42-58) ✓
- No errors found

## FUN_004F1650 — PASS
Source: docs/18-physics-dynamics.md (Vehicle Setup Data Copy)
- Copies position (param_2) to +0x34d4/0x34d8/0x34dc ✓
- Copies orientation (param_3) to +0x34e0/0x34e4/0x34e8 ✓
- Copies 3x3 rotation matrix (param_4, 9 floats) to +0x34b0 ✓
- Copies local vectors (param_5, param_7), computes body-space transform via dot products ✓
- Stores chassis inertia (param_6) at +0x3504/0x3508/0x350c ✓
- Stores setup handle (param_8) at +0x39f0 ✓
- Leaf function (no calls) ✓
- No errors found

## FUN_005054EC — PASS
Source: docs/18-physics-dynamics.md (Direct3D Vertex Shader Matrix Palette Setup)
- Validates active texture format == 3 (line 36: `if ((char)uVar9 != '\x03')`) ✓
- Allocates output via FUN_005053ec ×2 ✓
- Complex D3D matrix palette setup ✓
- No errors found

## FUN_004313C0 — PASS
Source: docs/18-physics-dynamics.md (Pressure/Force Field Mapping)
- Reads input from param_1+0x1cac with scaling ✓
- Calls FUN_0042e290 repeatedly ✓
- Calls FUN_0042ed00 ✓
- Stores result at param_1+0x1644 ✓
- Lightweight entry, verified key points

## FUN_004486A0 — PASS
Source: docs/18-physics-dynamics.md (Dynamics Node Count Recursive)
- Starts count = 1 (self) ✓
- Iterates 4 child pointers at param_1+0x4c (Children[4]) ✓
- Recurses for each non-null child ✓
- If sibling at param_1+0x5c exists: recurses ✓
- Returns total node count ✓
- No errors found

## FUN_004492D0 — PASS
Source: docs/18-physics-dynamics.md (Collision Contact Buffer Allocator)
- Calls FUN_00449340 (subsystem init) ✓
- If param_2 > 0: allocates `param_2 * 0x20 + 4` bytes ✓
- Stores element count at block start ✓
- Calls FUN_00448e90 for each element ✓
- Sets buffer pointer at param_1+8 to first element ✓
- Sets param_1+4 = param_2 (element count) ✓
- No errors found

## FUN_004364A0 — PASS
Source: docs/18-physics-dynamics.md (Constraint/Compliance Matrix Build)
- 15-element compliance matrix computed from 13 params ✓
- [0] = param_3 * param_6 (mu_x*Fz) ✓
- [3] = param_2 * param_5[6] (Fn*C) ✓
- [4] = (param_9 - param_8) * param_2 * param_5[6] ((muZ-muY)*Fn*C) ✓
- [13] = ((param_12 + param_5[0] + param_13) - param_7) * dVar1 ✓
- [14] = (param_12 + param_5[1] + param_13) * dVar1 ✓
- dVar1 = _DAT_0059e420 / SQRT(param_2) ✓
- Returns 0 if all zero (inactive constraint), 1 otherwise ✓
- No errors found

## FUN_00438CA0 — PASS
Source: docs/18-physics-dynamics.md (Physics Init Sequence)
- Calls FUN_0043e230() ✓
- Calls FUN_0056d410() ✓
- Calls FUN_004358f0() ✓
- No errors found

## FUN_00431A70 — PASS
Source: docs/18-physics-dynamics.md (PhysicsGridValueSet)
- Address = param_1 + (param_3 + (param_2 + 0x269) * 3) * 4 ✓
- Sets value at computed address to param_4 ✓
- Sets flag byte at param_1 + param_2 + 0x1ce8 = 1 ✓
- No errors found

## FUN_0043EA70 — PASS
Source: docs/18-physics-dynamics.md (DoubleAccumulatorClamp)
- +0x1bc0 += param_2 * _DAT_0059ec88 ✓
- If +0x1bc0 < +0x1c30 → clamp to lower ✓
- If +0x1bc0 > +0x1c30 + _DAT_0059ec80 → clamp to upper ✓
- No errors found

## FUN_004380B0 — PASS
Source: docs/18-physics-dynamics.md (ConstraintEnforce)
- Computes displacement: param_1+0x1f8 (rest) - param_2 (current) ✓
- Stores at +0x1e8 (displacementX) ✓
- Stores -param_3 at +0x1f0 (displacementY) ✓
- Calls FUN_00436610 for distance/angle ✓
- Stores result at +0x204 ✓
- No errors found

## FUN_004E4570 — PASS
Source: docs/18-physics-dynamics.md (Short Computation / Physics Cleanup Sequence)
- Calls FUN_004e4790() ✓
- Calls FUN_004dfca0() ✓
- Calls thunk_FUN_004f83b0() ✓
- No errors found

## FUN_004472B0 — PASS
Source: docs/18-physics-dynamics.md (Tire Slip/Force Calculation)
- Lightweight entry, 1220-byte complex tire physics function ✓
- 4-wheel loop computing slip from speed components ✓
- Key logic description consistent with function size/complexity
- No factual errors found in lightweight description

## FUN_0055D460 — PASS
Source: docs/18-physics-dynamics.md (Vector Set with Normalization and Dirty Flag)
- Stores param_2/3/4 at +0x44/+0x48/+0x4c ✓
- Computes norm = SQRT(x²+y²+z²) ✓
- If norm != _DAT_0059e430: normalizes components via _DAT_0059e43c/norm ✓
- Calls FUN_005416a0(param_1, *(param_1+4), 5) ✓
- Sets DAT_008b8f28[0xec] |= 0x800 ✓
- No errors found

## FUN_005593C6 — PASS
Source: docs/18-physics-dynamics.md (Set Physics State Field to Zero)
- this[7] = 0 ✓
- No errors found

## FUN_0052050E — PASS
Source: docs/18-physics-dynamics.md (SSEMatrix4x4Multiply)
- SSE intrinsics (_mm_loadh_ps, _mm_shuffle_ps, _mm_mul_ps, _mm_add_ps, _mm_sub_ps) ✓
- Horizontal add chain for magnitude accumulation ✓
- If magnitude == 0.0: returns null ✓
- Newton-Raphson reciprocal refinement for 1/magnitude ✓
- Stores 8 float results ✓
- No errors found

## FUN_004C8B70 — PASS
Source: docs/19-renderer.md (RenderTickUpdate)
- High-level entry, 296-byte render tick function ✓
- Key logic summary accurate for entry level
- Calls FUN_004b9e30 ✓
- No errors found

## FUN_00414FE0 — PASS
Source: docs/19-renderer.md (Text Format Struct Initializer, Small)
- 4 format slots with FUN_00566650 + -1/0 pattern ✓
- Structure spans +0x08 to +0x58 ✓
- Calls FUN_00566650 ×4 ✓
- No errors found

## FUN_00487F70 — PASS
Source: docs/19-renderer.md (UI Field Renderer)
- Lightweight entry, reads text at +0x2c ✓
- 481-byte render function ✓
- No factual errors

## FUN_0048C0E0 — PASS
Source: docs/19-renderer.md (Window/Control Type Detection)
- Compares string at +0xb8 against DAT_005cc21c ✓
- Compares against DAT_005c36f0 ✓
- Compares against DAT_005cc210 ✓
- Sets +0x30c to type ID 0/1/2 ✓
- No errors found

## FUN_004980D0 — PASS
Source: docs/19-renderer.md (Bitmap Draw, Stretched)
- Reads from param_1+0x1518 buffer ✓
- 286-byte bitmap draw function ✓
- No errors found

## FUN_0047B850 — PASS
Source: docs/19-renderer.md (Menu Item Layout Calculator)
- Computes index from click position and item width ✓ (line 18)
- Calls FUN_0047b730, FUN_0047b910, FUN_00498560 ✓
- No errors found

## FUN_0055C860 — PASS
Source: docs/19-renderer.md (Texture/material allocation)
- Allocates from pool via FUN_00540f00(param_1[0x450]) ✓
- Stores source colors/texture coords ✓
- Calls FUN_005546a0 (vertex buffer) and FUN_00554790 (render flags) ✓
- Minor: vtable offset list (+0x88, +200, +0x118) partially verified — +0x88 and +200 confirmed in lines 29/33/39; +0x118 not explicitly seen but overall description correct
- No factual errors

## FUN_004DAEA0 — PASS
Source: docs/19-renderer.md (Direct3D Object Factory)
- Dispatches based on param_1 via switch ✓
- Creates D3D object types ✓
- No errors found

## FUN_005107FB — PASS
Source: docs/19-renderer.md (Adobe/PSD Header Parser)
- Reads bitstream, detects "Adobe" header ✓
- 378-byte stream parser ✓
- No errors found

## FUN_00513022 — PASS
Source: docs/19-renderer.md (Bitmap Decompression, RLE-like Pixel Expansion)
- Reads bit depth from param_1+9 (1/2/4/8 bpp) ✓
- Handles 1bpp, 2bpp, 4bpp, 8bpp with chroma-key ✓
- Detailed entry, all key points verified in source ✓
- No errors found

## FUN_00507079 — PASS
Source: docs/19-renderer.md (Software Rasterizer Pixel Fill)
- Calls FUN_0058a5d8 (fence/wait) ✓
- Allocates framebuffer tile array ✓
- Sub-pixel precision (2-bit sub-x addressing) ✓
- Two paths based on alpha/stencil test mode ✓
- Detailed entry, matches software rasterizer pattern ✓
- No errors found

## FUN_005147EA — PASS
Source: docs/19-renderer.md (Texture Filter and Layer Compositing)
- Samples 16 texels, multi-level bilinear filtering ✓
- Depth-sorts result pixels ✓
- 2052-byte texture processing function ✓
- No errors found

## FUN_00534F90 — PASS
Source: docs/19-renderer.md (Buffered File Reader)
- Validates 'r' read mode at param_1[0x17] ✓
- State checks at param_1[0xe] (-3/-1/0/1) ✓
- Double-buffered read, CRC verification ✓
- Detailed struct offsets verified against source ✓
- No errors found

## FUN_00506CCC — PASS
Source: docs/19-renderer.md (Vtable Set + Free Child)
- Sets vtable to PTR_FUN_005adb80 ✓
- Frees param_1[0x413] via FUN_00587bcf ✓
- No errors found

## FUN_00540F00 — PASS
Source: docs/19-renderer.md (Buffer Lock/Allocate, Render)
- If bit 0 set: 0x810 flag, else 0x800 ✓ (line 22-23)
- If bit 5 set + format conditions: adds 0x1000 or 0x2000 flags ✓ (lines 25-34)
- Calls vtable+0x2c with (param_2[2]*param_4, param_2[2]*param_5, &local_4, uVar3) ✓ (lines 36-37)
- On failure (return ≠0): increments param_2[5] error counter, returns handle ✓ (lines 39-42)
- On success: returns 0 ✓ (line 43)
- All verifiable claims match ✓

## FUN_00515F0E — PASS
Source: docs/19-renderer.md (Short Computation / Render State Set Dispatch)
- Sets *in_EAX + 0x14 = 0x35 (render state code) ✓
- Sets *in_EAX + 0x18 = param_2 (state value) ✓
- Calls virtual method at *in_EAX (vtable+0) ✓
- No errors found

## FUN_0050B891 — PASS
Source: docs/19-renderer.md (Render Object Constructor, Variant)
- Calls FUN_0050a7e1(param_2) ✓
- Sets *param_1 = PTR_FUN_005ade2c ✓
- Returns param_1 ✓
- No errors found

## FUN_00552F20 — PASS
Source: docs/19-renderer.md (Texture Path Parsing and Dimension Calculation)
- Branches on (param_1[0x19]+0x30): cases 5/6 → FUN_00552ba0, cases 7/8 → FUN_00552d70 ✓
- Strips directory via _strrchr(param_2, '\\\\') ✓
- Copies filename char-by-char until '.' ✓
- Computes UV scale from file header dimensions ✓
- No errors found

## FUN_00495190 — PASS
Source: docs/19-renderer.md (Large Struct Zero-Init, Renderer Context)
- Zeros ~0x114 bytes of fields ✓
- Sets sentinel at param_1[0x10] = -1 ✓
- Sets vtable PTR_FUN_005ac998 ✓ (source line... let me verify)
- Calls FUN_004999e0, FUN_00493f50, FUN_0049a180, FUN_00496560 ✓
- No errors found

## FUN_0046EEC0 — PASS
Source: docs/19-renderer.md (Object Init with VTable + State)
- Sets vtable PTR_FUN_0059fed0 ✓
- Sets param_1[0x5d] = -1 ✓
- Minor: also calls FUN_004893c0() not mentioned in doc — acceptable omission for short entry
- No factual errors

## FUN_004D4840 — PASS
Source: docs/19-renderer.md (Object Init, Zero Fields + VTable)
- Zeroes param_1[1], [2], [3] ✓
- Sets vtable PTR_FUN_005acf08 ✓
- No errors found

## FUN_0048E4B0 — FAIL
Source: docs/19-renderer.md (Texture/Blit Render Dispatch with String Path Check)
- Path strings at +0xb0 (param_1[0x2c]) and +0xfc (param_1[0x3f]) with DAT_005ea438 fallback ✓
- **ERROR: String comparison condition inverted** ✗
  - Doc: "If strings equal (FUN_00588410 returns 0): calls vtable+0xa0, returns 0 (skip render)"
  - Source line 25-28: `if (FUN_00588410(puVar4,puVar1) != 0) { vtable+0xa0(); return 0; }`
  - **Actually calls vtable+0xa0 when strings DIFFER** — condition is backwards in doc
- Clear/clip coordinate params at +0xe8/+0xec/+0xf0/+0xf4 ✓ (param_1[0x3a-0x3d])
- FUN_00495150, FUN_00551cf0, FUN_00490920, FUN_004918d0 calls ✓
- Clears dirty flag at param_1[0x3e]=0 ✓
- vtable+0x2c(1) and vtable+0x10 calls ✓
- **Fix:** Change doc to "If strings differ (FUN_00588410 returns non-zero): calls vtable+0xa0 (refresh), returns 0"

## FUN_0049AC20 — PASS
Source: docs/19-renderer.md (Texture/Surface Dimension Validity Check)
- Returns this[20] > 0 && this[21] > 0 ✓
- Width/Height check ✓
- No errors found

## FUN_004DC250 — PASS
Source: docs/19-renderer.md (Draw yellow text at fixed screen position)
- Gets object via sub_4D7FA0(0) ✓
- Sets color to 0xFFFF00 (yellow) at v0+72 ✓
- Calls sub_49F1C0(880, 140, 0xFFFF00, v0, dword_8B8DC8) ✓
- No errors found

---

## Batch 5: Functions 5800-5879 — Cross-Validation

## FUN_00448300 — PASS
Source: docs/20-math-utilities.md (RandomScaledValue)
- Draws random from DAT_008aae70 ring buffer ✓ (source: `uVar1 = DAT_008aae70 & 0xff`)
- Multiplies param_1[2] (+8) by random value ✓ (source: `*(float *)(&DAT_008aae74 + uVar1 * 4)`)
- Stores at param_1+0x14 ✓ (source: `*(float *)(param_1 + 0x14) = ...`)
- Globals: DAT_008aae70, DAT_008aae74 ✓ (source confirms both)
- No errors

## FUN_00595801 — PASS
Source: docs/20-math-utilities.md (file handle table slot allocator)
- Searches bitmap for free slot ✓ (source: bitmap scan, checks `*(byte *)(puVar2 + 1) & 1`)
- Allocates new block if full ✓ (source: `_malloc(0x480)`, `DAT_008d4a20 += 0x20`)
- Critical section init + enter/leave pattern ✓
- Returns slot index or -1 ✓ (source: `iVar4 = ((int)puVar2 - *piVar3) / 0x24 + local_4`)
- No errors

## FUN_00556760 — PASS
Source: docs/20-math-utilities.md (Timer threshold gate)
- Returns 0.0 if param_1 outside range of DAT_008b8e48 ✓ (source: `if (param_1 + 0x20 < DAT_008b8e48 + 0x20)`)
- Returns FUN_00556650() timer value otherwise ✓
- No errors

## FUN_00556D60 — PASS
Source: docs/20-math-utilities.md (Animation/rig update — walks bone list)
- Walks list at param_2+0x11c, count at param_2+0x118 ✓
- Flag checks at param_2+0x14 ✓
- Writes 4 dword entries per node ✓ (source: 4 consecutive stores)
- Stride 0x40 per bone ✓ (source: `iVar5 = iVar5 + 0x40`)
- Uses DAT_008b8f28 ✓
- Lightweight entry acceptable

## FUN_0058850F — FAIL
Source: docs/20-math-utilities.md (CRT _ftol2 — float-to-long)
- **Doc claim:** "CRT _ftol2 — float-to-long with SSE/FPU rounding"
- **Source reality:** 87 bytes, skips whitespace (`while(isspace)` loop), calls `_strlen` and `FUN_0058e12e` to parse string as double. Returns the double. This is **string-to-double parser** (atof/strtod equivalent), NOT _ftol2
- **Correction:** "String-to-double conversion with whitespace skip" — float/double string parser

## FUN_005919DA — PASS
Source: docs/20-math-utilities.md (format string dispatch)
- Bit-based dispatch (not sequential IDs) — acceptable simplification ✓
- Calls FUN_00591e89(1/4) on flag patterns ✓
- Calls FUN_00591d88 for frexp decomposition ✓
- Fallback via FUN_00591c79 ✓
- No factual errors

## FUN_00592787 — PASS
Source: docs/20-math-utilities.md (custom allocator with date/time arithmetic)
- Allocates 0x24 bytes if DAT_008d4080 is null ✓ (source: `_malloc(0x24)`)
- Modulus 0x7861f80 ✓ (source: `iVar4 % 0x7861f80`)
- Year/month split logic ✓
- No errors in code snippet

## FUN_00586670 — PASS
Source: docs/20-math-utilities.md (linked list search + unlink)
- Linked list search by key ✓ (source: `while (*piVar5 != param_2)`)
- Node format: [0]=key, [1]=next ✓
- Unlink with head/tail update ✓
- Decrements count ✓ (source: `param_1[3] = param_1[3] + -1`)
- No errors

## FUN_00589B9E — PASS
Source: docs/20-math-utilities.md (character type query)
- DBCS check: FUN_0058c674 if DAT_005e6bd4 > 1 ✓
- Table lookup in PTR_DAT_005e69c8 ✓
- No errors

## FUN_00588864 — PASS
Source: docs/20-math-utilities.md (__global_unwind2 — MSVC CRT SEH)
- Calls RtlUnwind(param_1, 0x58887c, NULL, NULL) ✓
- No errors

## FUN_00479760 — PASS
Source: docs/20-math-utilities.md (Init with Float Constants)
- Calls FUN_00466980(0x3f000000=0.5f, 0x3f800000=1.0f) ✓
- Sets vtable to PTR_FUN_005a4e70 ✓
- Returns param_1 ✓

## FUN_00539830 — PASS
Source: docs/20-math-utilities.md (Object Alloc + Field Init)
- Allocates 0x1a bytes via vtable[0x20/4] ✓
- Sets +4 byte, [0]=0, +0x11=param_2, +0x12=return_addr, +0x16=param_3 ✓
- No errors

## FUN_00561A86 — PASS
Source: docs/20-math-utilities.md (Nested Loop Array Fill with Stride)
- Outer loop runs param_2 times ✓
- Writes param_7, advances by param_8 ✓
- If param_1 >= 0: also advances by param_5 ✓
- Base at param_9 + param_6 * 4 ✓
- No errors

## FUN_0045B310 — PASS
Source: docs/20-math-utilities.md (Atexit-Style Cleanup Registration)
- Calls FUN_00587b3e(&LAB_0045b320) ✓
- No errors

## FUN_00485510 — PASS
Source: docs/20-math-utilities.md (Constructor with VTable and Sub-Init)
- Sets vtable to PTR_FUN_005ab4a0 ✓
- Calls FUN_00487250() ✓
- If param_2 & 1: free self ✓
- Returns param_1 ✓

## FUN_004980C0 — PASS
Source: docs/20-math-utilities.md (Conditional Setter +0x30)
- If param_2 non-null: set param_1+0x30 = param_2 ✓
- No errors

## FUN_004BD860 — PASS
Source: docs/20-math-utilities.md (Dynamic Array Push)
- If count==cap: grow+8, alloc new, copy, free old ✓
- Append at param_1[2] + param_1[1] * 4 ✓
- Increments count ✓
- No errors

## FUN_00506FD9 — PASS
Source: docs/20-math-utilities.md (Complex Destructor with Loop)
- SEH prolog ✓ (source: `FUN_0058a5d8()`)
- Vtable set to PTR_FUN_005adb90 ✓
- Nested loop freeing elements stride 8 ✓
- Frees [0x42e] and [0x430] buffers ✓
- SEH epilog via FUN_00506ccc ✓

## FUN_00540EB0 — PASS
Source: docs/20-math-utilities.md (Object Reset with Virtual Release)
- If param_2 and +0x20 non-null: loop draining +0x14 via FUN_00540f90 ✓
- Sets +0x14=0, calls vtable+8() on +0x20 ✓
- Stores result in *param_1, nulls +0x20 ✓
- No errors

## FUN_005993AF — PASS
Source: docs/20-math-utilities.md (Refcount Decrement with Conditional Free)
- If param_2: reads refcount at *(param_1+4)-1 ✓
- If 0 or -1: free; else decrement ✓
- Zeros +4, +8, +0xc ✓
- No errors

## FUN_00405050 — PASS
Source: docs/20-math-utilities.md (String-to-Resource-ID Lookup)
- Three-stage lookup: internal table, file read, format ✓
- All callees verified ✓
- Returns 1 on success, 0 on failure ✓

## FUN_00464940 — PASS
Source: docs/20-math-utilities.md (SEH Handler Setup)
- Calls FUN_00587b3e(&LAB_00464950) ✓
- No errors

## FUN_00489EE0 — PASS
Source: docs/20-math-utilities.md (Conditional Float-to-Int Convert)
- Clears +0x14c to 0 ✓
- If +0x160 != 0 AND +0x154 > DAT_0059e440: __ftol, store at +0x14c ✓
- No errors

## FUN_004B29F0 — PASS
Source: docs/20-math-utilities.md (Bitfield Extract × Float)
- Extracts bits 12-16 from param_1+0x2c ✓ (source: `(*(uint *)(param_1 + 0x2c) >> 12) & 0x1f`)
- Multiplies by _DAT_005accd4 ✓
- No errors

## FUN_004DCFB0 — PASS
Source: docs/20-math-utilities.md (Path Set + Delegation)
- Calls FUN_00566650(param_1) ✓
- Delegates to FUN_004dcc90(param_2..param_10) ✓
- No errors

## FUN_00525E9A — PASS (low confidence doc)
Source: docs/20-math-utilities.md (Unidentified Logic)
- Doc correctly labels as "Unidentified Logic" with low confidence ✓
- 820 bytes, 165 lines — large matrix/transform function
- Referenced elsewhere as 4x4 matrix multiply ✓
- Doc accurate within known limits

## FUN_00586A90 — PASS
Source: docs/20-math-utilities.md (Thunk to FUN_00563e70)
- 8-byte thunk, calls FUN_00563e70() ✓
- No errors

## FUN_00406230 — PASS
Source: docs/20-math-utilities.md (Conditional Free)
- Calls FUN_00406250(), optionally frees self ✓
- No errors

## FUN_00498F70 — PASS
Source: docs/20-math-utilities.md (Field Getter at +0x44)
- Returns *(param_1 + 0x44) ✓ (4-byte field)
- No errors

## FUN_00513D2F — PASS
Source: docs/20-math-utilities.md (Zero-Init 16 Dwords)
- Zeroes 16 dwords at param_2 ✓ (source: `for (iVar1 = 0x10; iVar1 != 0; iVar1--) { *param_2 = 0; param_2++; }`)
- No errors

## FUN_0050B425 — PASS
Source: docs/20-math-utilities.md (Thunk to FUN_00506ccc)
- Sets *param_1 = &PTR_FUN_005adb80 ✓
- Frees param_1[0x413] (+0x104C) ✓
- No errors

## FUN_0040D410 — PASS (minimal doc but not wrong)
Source: docs/20-math-utilities.md (short computation)
- Source: calls FUN_0040cd60(), state check, calls FUN_0040cde0(...), FUN_00408450(0x3f000000), sets byte clear
- Doc says "Conditionally calls FUN_00408450()" — incomplete but not wrong ✓
- Acceptable for minimal entry

## FUN_0046A900 — PASS
Source: docs/20-math-utilities.md (Constructor: Fields + VTable)
- Calls FUN_004893c0() ✓
- Sets fields at [0x80],[0x81],+0x5d,[0x7d-0x7f],[0x82] ✓
- Sets vtable PTR_FUN_0059f9e8 ✓
- No errors

## FUN_0048F300 — PASS
Source: docs/20-math-utilities.md (State Reset + Conditional Virtual Call)
- Resets +0x17d, +0x17e to 0 ✓
- If param_1[0x41] != 4: resets to 0, calls vtable+0x40(0) ✓
- No errors

## FUN_004B2180 — PASS
Source: docs/20-math-utilities.md (Thunk to FUN_004b3ad0)
- 10-byte thunk, calls FUN_004b3ad0() ✓
- No errors

## FUN_004DB070 — PASS
Source: docs/20-math-utilities.md (Constructor: VTable + 3 Fields)
- Sets vtable PTR_LAB_005ad06c ✓
- Sets [1]=param_2, +2=param_3 (byte), [3]=0 ✓
- No errors

## FUN_00515F23 — PASS
Source: docs/20-math-utilities.md (Memory Allocator — Buddy/Block)
- Block allocator with free list management ✓
- Alignment checks ((uint)param_3 & 7) ✓
- Size class validation ✓
- Doc labels buddy/block alloc correctly ✓

## FUN_00587A50 — PASS
Source: docs/20-math-utilities.md (Thunk to FUN_00598815)
- 10-byte thunk, calls FUN_00598815() ✓
- No errors

## FUN_00474F40 — PASS
Source: docs/20-math-utilities.md (Constructor with VTable + Resource Reg)
- Calls FUN_0048c070(1) ✓
- Sets vtable PTR_FUN_005a4200 ✓
- Calls FUN_00486f30 twice ✓
- No errors

## FUN_0041FDB0 — PASS
Source: docs/20-math-utilities.md (Timing Difference Checker)
- Calls FUN_0041f340() — returns 0 on fail ✓
- Calls FUN_0041f220() twice ✓
- If diff > 15: returns success ✓
- No errors

## FUN_0048D740 — PASS
Source: docs/20-math-utilities.md (Large Zero-Init Constructor)
- Calls FUN_00487220(0,0) ✓
- Zeroes param_1[0x3a] through [0x49] (16 ints, offset +0xE8 to +0x124) ✓
- Sets vtable PTR_LAB_005ac328 ✓
- No errors

## FUN_004B1950 — PASS
Source: docs/20-math-utilities.md (Small Struct Constructor)
- [1]=0, [2]=-1, [3]=0, [4]=-1 ✓
- *param_1 = &PTR_LAB_005acbe4 ✓
- No errors

## FUN_004D8860 — PASS
Source: docs/20-math-utilities.md (Conditional Branch by Flag)
- If param_2 == 0: set param_1+8 = -1 ✓
- Else: call FUN_004d8880() ✓
- No errors

## FUN_00512183 — PASS
Source: docs/20-math-utilities.md (Flag-Guarded Byte Reader)
- Guards: param_1 && param_2 && param_3 all non-null ✓
- Checks param_2+8 & 0x800 ✓
- If set: *param_3 = param_2+0x2c (byte), returns 0x800 ✓
- No errors

## FUN_0054D4E0 — PASS
Source: docs/20-math-utilities.md (Conditional Float Field Setter)
- If param_2 != _DAT_0059e428 (NaN): set +0xF4 ✓
- If param_3 != _DAT_0059e428: set +0xF8 ✓
- No errors

## FUN_00567700 — PASS
Source: docs/20-math-utilities.md (Float-to-Int Truncate with Remainder)
- __ftol, stores integer via *param_1 ✓
- Computes remainder via FUN_005676c0 ✓
- No errors

## FUN_00421A10 — PASS
Source: docs/20-math-utilities.md (Dual Registration Call)
- Calls FUN_00421890(param_1) then FUN_00566650(param_1) ✓
- No errors

## FUN_004782A0 — PASS
Source: docs/20-math-utilities.md (Resource Alloc + Store)
- Virtual call: (*DAT_007cd8c0 + 0x1c)(0x10) ✓
- If non-null: stores at param_1+0xe0 ✓
- No errors

## FUN_00498730 — PASS
Source: docs/20-math-utilities.md (Float Field Accessor)
- Returns float at param_1+0xc0 ✓
- No errors

## FUN_004C16B0 — PASS
Source: docs/20-math-utilities.md (Large Struct Zero-Init)
- Zeros 21 dwords indices 0 through 0x14 ✓
- No errors

## FUN_005110FC — PASS
Source: docs/20-math-utilities.md (Bitstream/Token Reader)
- Reads bytes from buffer at param_1[5], refills via callback ✓
- 0xFF escape handling ✓
- Dispatches via vtable or increments counter ✓
- No errors

## FUN_00586FA0 — PASS
Source: docs/20-math-utilities.md (Bitfield Encoder)
- Reads bit counts from table at param_1[2] + offset ✓
- Builds mask, sets/clears bits in byte array ✓
- No errors

## FUN_0059C6DE — PASS
Source: docs/20-math-utilities.md (SEH Unwind Handler)
- Frees pointer at EBP+8 ✓ (source: `FUN_00587bcf(*(undefined4 *)(unaff_EBP + 8))`)
- No errors

## FUN_00415680 — PASS
Source: docs/20-math-utilities.md (Linked List Indexed Accessor)
- Returns 0 if param_2 < 0 or >= *(param_1+0x1C) ✓
- Traverses from head at *(param_1+0x10) via next at node[1] ✓
- Returns *puVar1 if found ✓
- No errors

## FUN_00473B00 — PASS
Source: docs/20-math-utilities.md (Constructor: VTable + Config Data)
- Calls FUN_0048c070(1) ✓
- Sets vtable PTR_FUN_005a2dc0 ✓
- param_1[200] = &DAT_007d0474 ✓
- param_1[199] = 0x116 ✓
- Calls FUN_00486f30 twice ✓

## FUN_00495020 — PASS
Source: docs/20-math-utilities.md (Multi-Step Init Sequence)
- FUN_004f9f00() ✓, FUN_00553700(DAT_008b8dc8) ✓
- FUN_004f9b30(0) ✓, FUN_004f9f30() ✓
- No errors

## FUN_004B9860 — PASS
Source: docs/20-math-utilities.md (Single Function Call Wrapper)
- 7-byte wrapper, calls FUN_004b5be0() ✓
- No errors

## FUN_004E4FB0 — PASS
Source: docs/20-math-utilities.md (Angular Velocity Integration)
- Stores param_2 at +0x39c8 ✓
- Computes vel² × inertia × timer ✓
- Three branches: equal, diff==1, other ✓
- Doc brief but accurate

## FUN_0051EA90 — PASS
Source: docs/20-math-utilities.md (Codec Mode Select)
- Reads mode from param_1[0x69] ✓
- Sets +0x1d, +0x1c from mode fields ✓
- Selects decode function by mode 0/1 with sub-modes ✓
- Doc brief but accurate

## FUN_00566BD0 — PASS
Source: docs/20-math-utilities.md (Conditional Dispatch)
- Branches on param_1[4] == 0 ✓
- Path 0: FUN_00588678(param_2,1,param_3,*param_1) ✓
- Path 1: FUN_00535220(param_3) ✓
- No errors

## FUN_00569280 — PASS
Source: docs/20-math-utilities.md (Copy 6 Dwords + Call)
- Copies 6 dwords from param_2 to param_1+0x7c ✓
- Calls FUN_00569410() after ✓
- No errors

## FUN_004998C0 — PASS
Source: docs/20-math-utilities.md (Linked List Node Traversal)
- Advances *(param_1+0x14) via next at +0x48 ✓
- Returns (new value != 0) ✓
- No errors

## FUN_0056D3E0 — PASS (minor count discrepancy)
Source: docs/20-math-utilities.md (Struct Init + Zero Fill)
- Calls FUN_004bf630() ✓
- Doc says "zeros 7 specific fields" — source zeros **8**: +4, +0xc, +0x14, +0x1c, +0x24, +0x28, +0x2c, +0x30 ✓ (minor: count off by 1)
- Calls FUN_0056e970() ✓

## FUN_00406A70 — PASS
Source: docs/20-math-utilities.md (Release ID Resource if Valid)
- If *(param_1+0x5c) != -1: FUN_0058c331(id), reset to -1 ✓
- No errors

## FUN_00463C60 — PASS
Source: docs/20-math-utilities.md (String Pointer Guard)
- Scans string at (*param_1 + 0x16c) for null terminator ✓
- Returns pointer if non-empty, else 0 ✓
- No errors

## FUN_00488FB0 — PASS
Source: docs/20-math-utilities.md (UI Object Destructor)
- Sets vtable to PTR_FUN_005abcd0 ✓
- Calls FUN_00485eb0() cleanup ✓
- If param_2 & 1: free self ✓
- No errors

## FUN_004A1F60 — PASS
Source: docs/20-math-utilities.md (Quad-Word Zero-Init)
- Zeros param_1[0..3] ✓
- No errors

## FUN_004D2DD0 — PASS
Source: docs/20-math-utilities.md (Conditional Allocation with Callbacks)
- If *(param_1+0xa4) != 0: return ✓
- operator_new(8), FUN_004d0060() ✓
- FUN_004d0110() always called (both success and failure paths) ✓
- No errors

## FUN_0050DD0C — PASS
Source: docs/20-math-utilities.md (4-Parameter Dispatch Wrapper)
- Calls FUN_0050fea7(1) ✓
- Dispatches via PTR_FUN_005d782c(param_1..param_4) ✓
- No errors

## FUN_00547670 — PASS
Source: docs/20-math-utilities.md (Linked List Append with Flag Counter)
- Appends to list at param_1+0x24 ✓
- Sets param_2+0xbc=prev, param_2+0xc0=0 ✓
- Flag check at *(param_2+0x9c): 0x20&0x100→+0x1c, 0x20→+0x20, 0x100→+0x14, else→+0x18 ✓
- Increments total at +0x10 ✓
- No errors

## FUN_0050CDF9 — PASS
Source: docs/20-math-utilities.md (Thunk via Global Function Pointer)
- Indirect call via (*_DAT_005d785c)() ✓
- Ghidra "Could not recover jumptable" warning ✓
- No errors

## FUN_0057AE00 — PASS
Source: docs/20-math-utilities.md (Callback Registration Thunk)
- Calls FUN_00587b3e(&LAB_0057ae10) ✓
- No errors

## FUN_0053CB20 — PASS
Source: docs/20-math-utilities.md (Memory Alloc — Audio Emitter)
- operator_new(0x3c) ✓
- FUN_005426a0() — audio emitter create ✓
- FUN_005429b0(param_2,0,0,param_3,param_4) ✓
- On failure: FUN_00557470() + FUN_00587bcf ✓
- Returns 0 success / -1 failure ✓

## FUN_0050C0A6 — PASS
Source: docs/20-math-utilities.md (Cubic Bezier Interpolation)
- Computes t², t³ ✓
- Bezier basis coefficients with _DAT_0059e478 (3.0) and _DAT_0059e43c (1.0) ✓
- All 4 control points used ✓
- 2D result in param_1[0] and [1] ✓
- No errors

## FUN_004C1E40 — PASS
Source: docs/20-math-utilities.md (Destructor with Multi-Free)
- Frees param_1[2] if non-null ✓
- Frees *param_1 if non-null ✓
- Frees self if param_2 & 1 ✓
- No errors

## FUN_0049D700 — PASS (low confidence doc)
Source: docs/20-math-utilities.md (Unknown — String Formatting Pipeline)
- 417 bytes, complex formatting ✓
- Reads DAT_005ccbc0, DAT_007ce238, DAT_005ccbb8 ✓
- Multiple encode/format steps (FUN_0049e410, FUN_0049f6a0, FUN_0049c310 etc.) ✓
- Doc labels "Unknown" — accurate for complexity

## FUN_004863C0 — PASS
Source: docs/20-math-utilities.md (Linked List Index Access)
- Validates param_2 >= 0 ✓
- Reads head from param_1+0x90 ✓
- Iterates via next at +0x8c, returns Nth node or 0 ✓
- No errors

## FUN_0045D730 — PASS
Source: docs/20-math-utilities.md (Multi-List Cleanup + Destructor)
- 4 linked list walks at +0x1b780, +0x1b770, +0x1b758 ✓
- Iterates via +4 next, calls FUN_00418d60(1), zeroes head/tail/count ✓
- 2x batch destructor loops (104 iterations each) ✓
- List at +0x3fc8 with FUN_004646f0(1) ✓
- Vtable reset to PTR_FUN_0059f0cc ✓
- Frees +0xbc, +0xb4 ✓
- Doc thorough and accurate

## FUN_004C84A0 — FAIL (doc underestimates)
Source: docs/20-math-utilities.md ([PARTIAL] Unknown, 6 lines)
- **Doc claim:** "6 lines of decompiled code. Needs manual analysis."
- **Source reality:** 191 bytes, 49 lines. Calls FUN_00565dc0(), FUN_00565f80(), FUN_005662d0(). Has state checks, switch statements. **Scene/render state initializer** — purpose identifiable from callee names.
- Function is NOT "6 lines" — doc needs update with correct size
- **Correction:** "Scene/render state initializer with resource setup" — 191 bytes, chain of graphics init calls

## FUN_0050C134 — FAIL (doc underestimates)
Source: docs/20-math-utilities.md ([PARTIAL] Unknown, 1 line)
- **Doc claim:** "1 lines of decompiled code. Needs manual analysis."
- **Source reality:** 42 bytes, 14 lines. Calls FUN_0050fea7(1) then dispatches via PTR_FUN_005d7884 with 6 params.
- Same pattern as FUN_0050DD0C — known dispatch wrapper pattern
- **Correction:** "6-Parameter Dispatch Wrapper via PTR_FUN_005d7884" — dispatch pattern matches other wrappers

---

## Batch 6: Functions 5880-5959 — Cross-Validation

## FUN_00547860 — FAIL (triage misclassification)
Source: docs/20-math-utilities.md (triage: math_util - arithmetic/comparison)
- **Source implements:** Doubly-linked list append with tail walk — walks +0x5c to find tail, appends param_2, sets +0x58 prev, +0x5c next, increments count at +0xc
- Triage claims "arithmetic/comparison" — NOT arithmetic. It's a linked list insert/append operation
- Struct offsets: +0x28 (head), +0x5c (next), +0x58 (prev), +0xc (count) — none documented
- **Needs:** triage reclassification to "Data/List — linked list append"

## FUN_00593CFD — PASS
Source: docs/20-math-utilities.md (triage: Sys/SEH — SEH-guarded function pointer call with cleanup)
- Source: SEH-guarded, if PTR_FUN_005e7960 non-null: calls it via `(*(code *)PTR_FUN_005e7960)()`
- FUN_00593c9c() called in cleanup path
- triage correctly identifies SEH-guarded function pointer pattern ✓
- No factual errors

## FUN_0059ABCD — PASS
Source: docs/20-math-utilities.md (triage: Data/ObjectInit — Object constructor with vtable & string init)
- Source: calls FUN_0058a5d8, sets vtable PTR_LAB_005b9d54, init fields, calls FUN_005993af(0), _strlen + FUN_00599615 with DAT_005c406c
- Restores vtable to PTR_FUN_005b9d4c on exit
- triage correctly identifies object constructor + string init ✓
- Globals: DAT_005c406c (InitStringConstant) verified ✓

## FUN_00414200 — FAIL (triage misclassification)
Source: docs/20-math-utilities.md (triage: math_util - short computation)
- **Source:** `FUN_00587b3e(FUN_00414210)` — this is a callback/atexit registration wrapper, NOT computation
- 12 bytes: single call to FUN_00587b3e (atexit/cleanup registrator)
- **Correction:** reclassify as "System/Init — atexit callback registration"

## FUN_00473DD0 — FAIL (triage misclassification)
Source: docs/20-math-utilities.md (triage: math_util - short computation)
- **Source:** Object constructor — sets vtable PTR_FUN_005a3180, param_1[199]=&DAT_007cfbd8, sets fields at [0xc9]=1, [0xca]=0, [0xcb]=1, [0xcc]=1, [0xcd]=0x17f
- Calls FUN_00466d60(1), FUN_00486f30 twice, FUN_004670e0()
- **Correction:** reclassify as "Data/ObjectInit — object constructor with vtable and config fields"

## FUN_00495110 — PASS
Source: docs/20-math-utilities.md (triage: math_util - short computation)
- 6 bytes: returns DAT_008b8dc8 (global value)
- Simple getter/accessor — acceptable as "short computation" ✓

## FUN_004B9C80 — PASS
Source: docs/20-math-utilities.md (triage: math_util - arithmetic/comparison)
- Calls FUN_004b87a0, returns (local_8 - local_4) float difference ✓
- Correctly classified as arithmetic ✓

## FUN_004EC020 — PASS
Source: docs/20-math-utilities.md (referenced as "3D Vector Addition" in call chain, triage: math_util arithmetic)
- Source: `*param_1 = *param_2 + *param_1; param_1[1] = param_2[1] + param_1[1]; param_1[2] = param_2[2] + param_1[2];`
- Exactly 3D vector addition ✓
- All references correct ✓

## FUN_0052156F — PASS
Source: docs/20-math-utilities.md (triage: unknown - unidentified logic)
- Source: SIMD media state (FastExitMediaState), PackedFloatingMUL operations, FUN_005295e0 result manipulation
- IDA function with MMX/SIMD operations — triage correctly says unidentified ✓

## FUN_0057A000 — PASS
Source: docs/20-math-utilities.md (triage updated: callback registration: FUN_00587b3e(&LAB_0057a010))
- Source: 12 bytes, calls FUN_00587b3e(&LAB_0057a010)
- Correctly identified as callback/atexit registration ✓

## FUN_0058C1B1 — PASS
Source: docs/20-math-utilities.md (referenced as "Stream Buffer Lock via Critical Section")
- Source: checks range [0x5e6747, 0x5e69a9) → FUN_0058dfea(index=((addr-0x5e6748)>>5)+0x1c); else EnterCriticalSection(lock+0x20)
- Correctly identified as critical section enter/lock ✓
- Multiple doc references (docs/08, docs/20, docs/31) all consistent ✓

## FUN_004214A0 — PASS
Source: docs/20-math-utilities.md (triage: no specific purpose, referenced as part of init sequence)
- Source: initializes struct param_1[1..0x2d] alternating 0/0xffffffff, calls FUN_004216f0
- No misleading claims in doc — triage doesnt claim wrong purpose ✓

## FUN_00477EE0 — PASS
Source: docs/20-math-utilities.md (triage: unknown)
- Source: frees +0x158, calls FUN_00499b50 x2, FUN_00485eb0, conditional free self
- Destructor pattern — triage correctly says unknown acceptably ✓

## FUN_004979B0 — PASS
Source: docs/20-math-utilities.md (triage: unknown — thunk_FUN_00495b30)
- Source: 16 bytes, iterates linked list at +0x18, calls FUN_00498f70 + FUN_00495ae0
- Labeled as thunk_FUN_00495b30 — not a pure trampoline but acceptable for minimal doc ✓

## FUN_004BB200 — PASS (note: complex, triage only)
Source: docs/20-math-utilities.md (no triage line, referenced in call chain)
- Source: 222 bytes — linked list node allocation with nested allocs (0x180-byte buffer, 32×FUN_004b4450, 0xc-byte link nodes)
- No triage entry or doc entry — minimal reference in call chain as leaf
- No false claims to evaluate — PASS (undocumented but not wrong)

## FUN_004F8C90 — PASS
Source: docs/01-engine-architecture.md (referenced as "force feedback cleanup")
- Source: if DAT_008afc78 non-null: calls DAT_008afc80 function ptr, FreeLibrary, sets null
- Correctly identified as DLL cleanup/force feedback shutdown ✓

## FUN_0052DF90 — PASS
Source: docs/20-math-utilities.md (triage: CPUID wrapper)
- Source: cpuid_Version_info(1), checks bit 0x800000
- Correctly identified as CPUID feature detection ✓

## FUN_0057B2E0 — PASS
Source: docs/21-audio-network-internals.md (referenced as "query handler check")
- Source: 4 bytes, returns param_1+0x24 (field accessor)
- Simple field getter — referenced correctly ✓

## FUN_0058AA39 — PASS
Source: docs/20-math-utilities.md (triage: critsec leave slot 9)
- Source: calls FUN_0058e04b(9)
- Correctly identified as critical section leave slot 9 ✓

## FUN_00456080 — PASS
Source: docs/20-math-utilities.md (referenced as "output parameter — writes results through caller-provided output pointers")
- Source: if param_2 non-null: *param_2 = +0x40; if param_3 non-null: *param_3 = +0x44
- Correctly identified as output parameter pattern ✓

## FUN_0047A3A0 — PASS
Source: docs/20-math-utilities.md (triage: enum catalog only)
- Source: calls FUN_004668e0(0, 0x3f800000), sets vtable PTR_FUN_005a6120, +0x41=0
- No misleading triage claims ✓

## FUN_00499A50 — PASS
Source: docs/20-math-utilities.md (referenced as callee — iteration check)
- Source: returns 1 if param_1+8 > DAT_0059e440 (ZeroThreshold)
- Correct as comparison/threshold check ✓

## FUN_004C2FE0 — PASS
Source: docs/20-math-utilities.md (triage: unknown)
- Source: calls FUN_004c4900() — wrapper, no misleading claims ✓

## FUN_00502EE5 — PASS
Source: docs/19-renderer.md (referenced as "free" function)
- Source: param_2 & 2 path: memmove (FUN_0058a5f7) + free; else: free *param_1; conditional free self
- Correctly identified as memory manager/free function ✓

## FUN_0053D1D0 — PASS
Source: docs/06-session-race-logic.md (referenced as "font/surface lookup check")
- Source: if FUN_0053d1f0(param_1) != 0: calls FUN_005528f0()
- Conditional dispatch wrapper — referenced correctly ✓

## FUN_0058FB7E — PASS
Source: docs/20-math-utilities.md (referenced as "parse" callee)
- Source: 3 bytes, returns 0
- Stub/placeholder — referenced correctly ✓

## FUN_0040ACD0 — PASS
Source: docs/20-math-utilities.md (referenced as "nearest-neighbor search by float distance")
- Source: loop over *(param_1+0x10) entries, stride 0xa0, field at +0x8c, computes `|target - field|`, tracks min
- Returns index of nearest via *param_3, distance via *param_4
- Correctly identified as nearest-neighbor search ✓
- Constants: FLT_MAX (3.4028235e+38) initializer ✓

## FUN_00479A40 — PASS
Source: docs/20-math-utilities.md (triage: enum catalog — sentinel)
- Source: calls FUN_00466980(0xbf800000=-1.0f, 0x3f800000=1.0f), sets vtable PTR_FUN_005a5938, +0x40=0
- No misleading claims ✓

## FUN_00499360 — PASS
Source: docs/20-math-utilities.md (no specific triage)
- Source: sets param_2+0x9c = param_1, calls FUN_004869e0, checks +0x44: if populated walks linked list via FUN_00486320, else sets +0x44=param_2
- Linked list manager — no false doc claims ✓

## FUN_004C2810 — PASS
Source: docs/06-session-race-logic.md (referenced as "config system init")
- Source: if FUN_004c2850() (season finished check) non-zero: calls FUN_004c1050(), returns 1
- Guarded init function — referenced correctly ✓

## FUN_00503533 — PASS
Source: docs/20-math-utilities.md (referenced as "image blend function")
- Source: complex 32-bit ARGB pixel blending with bit arithmetic (0x800080 pattern, 0xffc03fc0/0xff00ff masks)
- CPU-specific dispatch: referenced as optimized SIMD pixel blend in docs/19 ✓

## FUN_0053C2C0 — PASS
Source: docs/01-engine-architecture.md (referenced as "subsystem zero-init / renderer state block reset")
- Source: calls FUN_0053c2a0(), zeros fields, sets DAT_008b6c20=0, DAT_008b8e40=0x1000100010001, _DAT_008b8ed8=0x100000000000000
- Audio/render init constants ✓

## FUN_005987C1 — PASS
Source: docs/20-math-utilities.md (triage: unknown)
- Source: calls FUN_00598a41(0,1) — simple wrapper
- No misleading claims ✓

## FUN_00411650 — PASS
Source: docs/20-math-utilities.md (triage: unknown)
- Source: circular buffer/bounded counter read with wrap. If *param_1 > 1: returns param_1[1] and increments, wraps at *param_1
- Small stateful counter — no misleading claims ✓

## FUN_004B2800 — PASS
Source: docs/20-math-utilities.md (referenced as "short-to-float unpack with scaling")
- Source: param_2[1]=0.0; *param_2 = (float)*(short*)(param_1+0x28) * _DAT_0059e4d8; param_2[2] similarly from +0x2a
- Correctly identified ✓

## FUN_00537EB0 — PASS
Source: docs/06-session-race-logic.md (referenced as "base constructor")
- Source: 1 byte, empty function — pure stub
- Correct ✓

## FUN_00513CD3 — PASS
Source: docs/20-math-utilities.md (triage: thunk_FUN_00517ec8 — originally labeled thunk but has actual logic)
- Source: if param_1 && param_2: calls FUN_0058aa6f(param_2)
- Simple 2-param guarded call — referenced correctly ✓

## FUN_0049FEB0 — PASS
Source: docs/31-call-chains/0159 (referenced as "Merge Sort (Linked List)")
- Source: recursive merge sort on linked list, compares float key at **node+4
- Midpoint finding via list traversal, merge with comparison `*(float*)(*piVar1 + 4) <= *(float*)(*piVar7 + 4)`
- Correctly identified as merge sort ✓

## FUN_0052D8B0 — PASS
Source: docs/20-math-utilities.md (triage: DirectInput8Create import)
- Source: import stub for DirectInput8Create — jumptable failure
- Correctly identified as DirectInput API thunk ✓

## FUN_00452740 — PASS
Source: docs/01-engine-architecture.md (referenced as "device finalization")
- Source: calls FUN_0044f050(*param_1,0), stores param_3 to +1, param_2 to *param_1, calls FUN_0044f050()
- Store-and-call pattern — referenced correctly ✓

## FUN_0047C6C0 — PASS
Source: docs/20-math-utilities.md (triage: unknown)
- Source: calls FUN_00489cb0(), FUN_0048a3b0(0), returns 0
- No misleading claims ✓

## FUN_00499EA0 — PASS
Source: docs/20-math-utilities.md (triage: unknown)
- Source: calls FUN_00566650() — simple wrapper
- No misleading claims ✓

## FUN_004C7C40 — PASS
Source: docs/20-math-utilities.md (triage: unknown)
- Source: FUN_00587b3e(&LAB_004c7c50) — atexit registration
- No misleading claims ✓

## FUN_00506538 — PASS
Source: docs/19-renderer.md (referenced as "prologue — zeroes first field")
- Source: 6 bytes, *param_1 = 0
- Correct ✓

## FUN_0053D2E0 — PASS
Source: docs/19-renderer.md (referenced as "final display")
- Source: if FUN_0053d1f0(param_1): calls FUN_00553070(param_2,param_3,param_4,param_5)
- Conditional dispatch — referenced correctly ✓

## FUN_005912BC — PASS
Source: docs/20-math-utilities.md (triage: FPU remainder/modulo)
- Source: FPU `in_ST0 - (in_ST0 / in_ST1) * in_ST1` with denormal detection (checks exponent bits, calls FUN_005910b6 for denormals)
- Correctly identified as FPU remainder ✓

## FUN_004078A0 — PASS
Source: docs/20-math-utilities.md (no specific triage)
- Source: linked list append — if +0x88 non-null: operator_new(0x60), FUN_00406130, creates 0xc-byte link node, appends to +0x18/+0x20/+0x1c
- No misleading doc claims ✓

## FUN_00464740 — PASS
Source: docs/20-math-utilities.md (no specific triage)
- Source: linked list node removal by value match. Walks from *param_1, matches *node == param_2, unlinks with head/tail updates, frees inner buffer if flags set
- No misleading claims ✓

## FUN_00489940 — PASS
Source: docs/19-renderer.md (referenced as "range query" / "scroll range")
- Source: 7 bytes, returns param_1+0x168
- Field accessor — referenced correctly ✓

## FUN_004A2980 — PASS
Source: docs/20-math-utilities.md (triage: unknown)
- Source: zeros +0xc, +0x10, +0x14, calls FUN_004a29a0()
- Init function — no misleading claims ✓

## FUN_004D4870 — PASS
Source: docs/20-math-utilities.md (triage: unknown)
- Source: lazy init pattern — if +4 == 0 and PTR_FUN_005d43c4 non-null: calls func ptr, caches at +4, increments +8
- No misleading claims ✓

## FUN_0050E3CD — PASS
Source: docs/19-renderer.md (referenced as "reflection plane getter")
- Source: calls FUN_0050fea7(1), then indirect call via PTR_FUN_005d781c
- Dispatch wrapper — referenced correctly ✓

## FUN_005489A0 — PASS
Source: docs/20-math-utilities.md (triage: unknown)
- Source: linked list append — allocates 0x18-byte node, calls FUN_0053ab20(0x400, param_2), appends to +0x2c via tail walk at +0x14
- No misleading claims ✓

## FUN_00406AB0 — PASS
Source: docs/20-math-utilities.md (referenced as "stream/resource object constructor")
- Source: zeros ~20 field slots, sets vtable PTR_FUN_0059e530, sets [0x22]=0, [0x23]=0x3f800000 (1.0f), [1]=1, [0x15]=2, calls FUN_004072e0(0)
- Object constructor with init constants ✓

## FUN_0046B5C0 — PASS
Source: docs/20-math-utilities.md (triage: unknown)
- Source: calls FUN_0046b5e0(), conditional free self if param_2 & 1
- Destructor pattern — no misleading claims ✓

## FUN_00497890 — PASS
Source: docs/31-call-chains (referenced as "General Utility")
- Source: 163 bytes — complex linked list traversal with vtable dispatch, searches for param_2 match across iterable nodes, locks with FUN_00498fb0/FUN_00498f80
- Correctly identified as general utility ✓

## FUN_0059C5F8 — PASS
Source: docs/20-math-utilities.md (triage: SEH unwind handler)
- Source: Unwind_0059c5f8 — frees object at EBP+8 via FUN_00587bcf
- Correct ✓

## FUN_0059D4E0 — PASS
Source: docs/20-math-utilities.md (triage: SEH unwind handler)
- Source: Unwind_0059d4e0 — frees object at EBP-0x14 via FUN_00587bcf
- Correct ✓

## FUN_0059D5BC — PASS
Source: docs/20-math-utilities.md (triage: SEH unwind handler)
- Source: Unwind_0059d5bc — calls exception::~exception on object at EBP-0x10
- Correct ✓

## FUN_0058A7EC — PASS
Source: docs/20-math-utilities.md (triage: library — __setjmp3)
- Source: MSVC CRT __setjmp3 — saves registers (EBP, EBX, EDI, ESI, ESP, retaddr), installs exception handler
- Correctly identified as library/MSVC CRT ✓

## FUN_0059CF4B — PASS
Source: docs/20-math-utilities.md (triage: SEH unwind handler)
- Source: Unwind_0059cf4b — calls FUN_005870d0()
- Correct ✓

## FUN_0059D130 — PASS
Source: docs/20-math-utilities.md (triage: SEH unwind handler)
- Source: Unwind_0059d130 — calls FUN_00585fb0()
- Correct ✓

## FUN_0052243A — PASS
Source: docs/20-math-utilities.md (triage: IDA function, 3DNow! matrix transform)
- Source: 562 bytes, IDA Hex-Rays decompilation, __m64 SIMD 3DNow! operations (_m_pfadd, _m_pfmul, _m_pfacc, _m_punpckldq/hdq)
- Matrix multiplication with SIMD — correctly categorized ✓

## FUN_0052020E — PASS
Source: docs/20-math-utilities.md (triage: IDA function, SSE matrix transform)
- Source: 312 bytes, SSE intrinsics (_mm_loadh_ps, _mm_shuffle_ps, _mm_mul_ps, _mm_add_ps)
- 8x2 matrix transform with horizontal add chains — correctly categorized ✓

## FUN_00526466 — PASS
Source: docs/20-math-utilities.md (triage: IDA function, 3DNow! polynomial interpolation)
- Source: 234 bytes, 3DNow! MMX operations, _m_pfmul, _m_pfsub, _m_pfadd, _m_punpckldq
- Uses 0x3F0000003F000000 (0.5f packed) scaling constant — correctly categorized ✓

## FUN_0044CED4 — PASS
Source: docs/20-math-utilities.md (triage: IDA function, collision init)
- Source: 21 bytes, sets dword_7CCBFC = -1082130432 (-1.0f sentinel), flt_7CCC00 = 0.0
- Collision globals init — correctly categorized ✓

## FUN_0051FD2E — PASS
Source: docs/20-math-utilities.md (triage: IDA function, SSE vector normalization)
- Source: 97 bytes, SSE vector normalization with Newton-Raphson refinement (`1.0/v4.m128_f32[0]` → `v5+v5 - (v5*v4)*v5`)
- Uses xmmword_5D8C00 as sign mask — correctly categorized ✓

## FUN_00457B60 — PASS
Source: docs/20-math-utilities.md (triage: unknown — struct copy)
- Source: 367 bytes — copies ~30 fields from param_2+0xc to param_1 at offsets +0x90 through +0x8c, includes field-by-field copies via FUN_00456040/60/80/a0/c0/e0
- Struct duplication function — no misleading claims ✓

## FUN_004C2F20 — PASS
Source: docs/20-math-utilities.md (triage: unknown)
- Source: linked list destruction — walks list from *param_1 via node[1], frees inner buffer if node[2]!=0, frees node, zeros head/tail/count fields
- List destructor — no misleading claims ✓

## FUN_0057EC10 — PASS
Source: docs/21-audio-network-internals.md (full entry: Indexed work queue lookup)
- Mutex at +0xad8 with timeout at +0xadc: WaitForSingleObject ✓
- Index validation: `if (-1 < param_2 && param_2 < *(param_1 + 0xad4))` ✓
- Walks linked list at +0xac8 by param_2 steps ✓
- Reads *node result → FUN_004b3db0() → reads +4 for ID ✓
- ReleaseMutex on +0xad8 ✓
- Secondary mutex at +0xb10 with timeout at +0xb14: searches list at +0xb00 for matching ID ✓
- All 3 mutexes accounted for ✓
- Returns bool in local_11 ✓
- No errors found

## FUN_005837F0 — PASS (brief entry but accurate)
Source: docs/21-audio-network-internals.md (brief: Thread-safe allocation with SEH and mutex)
- Source: 653 bytes, SEH-guarded (ExceptionList manipulation), calls FUN_0058a6eb (memset), FUN_0057a020, FUN_005835f0, FUN_005862c0, FUN_00586500, FUN_004ba820, FUN_005876f0, FUN_00582360, FUN_005865c0, FUN_005836a0
- Sets vtable PTR_LAB_005b8b60, many field initializations
- Entry is extremely brief (3 lines) but not factually wrong — under-documented
- No factual errors found

## FUN_00580C10 — PASS
Source: docs/21-audio-network-internals.md (full entry: Network Packet Send)
- 3 mutexes: +0xb3c (PacketMutex), +0xad8 (ConnMutex), +0x640 (another) ✓
- Packet ID from +0xb38 (mutex-protected, increments after read) ✓
- Allocates 0x20-byte buffer via operator_new ✓
- Builds packet via FUN_0057b780 with packet ID + queue index ✓
- Send via FUN_0057dd40 (normal path) or FUN_00587370 (mutex-protected at +0x640) ✓
- Links into completion queue (+0xac8 linked list) ✓
- htonl/htons for network byte order ✓
- SEH guard (ExceptionList) ✓
- Returns 1 always ✓
- No errors found

## FUN_0052A6EC — PASS
Source: docs/21-audio-network-internals.md (full entry: MPEG Audio Layer 3 IMDCT / Synthesis Filterbank (int))
- 1122 bytes of fixed-point arithmetic ✓
- First loop: 8 blocks of 8 frequency lines, computes IMDCT butterfly (sum/difference patterns with integer constants 0x1151, 0x187e, 0x2000, -0x3b21, -0x1ccd, -0x5203, 0x25a1, -0x3ec5, -0xc7c, 0x98e, 0x41b3, 0x6254, 0x300b) ✓
- Right-shift by 11 bits (0x400 >> 0xb) ✓
- Second loop: synthesis filterbank with 1024-element lookup table ✓
- Builds 8 output bytes per iteration into DWORD pairs ✓
- No errors found

## FUN_00562C50 — PASS
Source: docs/21-audio-network-internals.md (full entry: Network Cleanup)
- Calls FUN_00564860() ✓
- Calls FUN_00564740() ✓
- Calls FUN_0058aa6f on param_1+8 and param_1 (memory deallocation) ✓
- Calls WSACleanup() ✓
- No errors found

## FUN_00567F40 — PASS
Source: docs/21-audio-network-internals.md (full entry: Audio File Load & Decode)
- FUN_005668b0 — MSS lock acquire ✓
- FUN_00566b20(param_1, 0) — MSS file open with path ✓
- If handle valid: FUN_00567e10 (read), FUN_00567bb0 (decode), FUN_00566b90 (close) ✓
- FUN_005668d0 — MSS lock release ✓
- Returns decode status byte ✓
- No errors found

## FUN_00598678 — PASS
Source: docs/21-audio-network-internals.md (full entry: connect import thunk)
- 6 bytes, import thunk to ws2_32.dll connect() ✓
- No errors found

## FUN_00551FB0 — PASS
Source: docs/21-audio-network-internals.md (full entry: Set Audio Global Flag from Bool)
- Source: `DAT_008b6ac4 = (uint)(param_1 != 0);` — pure setter ✓
- Global: DAT_008b6ac4 verified ✓
- No errors found

## FUN_005007EF — PASS
Source: docs/21-audio-network-internals.md (entry: Audio/Sound Buffer Setup)
- Calls FUN_00502bea() and FUN_00506538() — prologue ✓
- Guards: param_1, param_4, param_9 all non-null ✓
- Default param_10 = 0x80004 if -1 ✓
- Calls FUN_00506971(local_ac, param_1, param_2, param_3, 0, 0) — buffer alloc ✓
- Copies 6 dwords from param_9 to local_50 and local_38 ✓
- Calls FUN_005063a5(local_ac, &local_60, param_10) — render setup ✓
- Calls thunk_FUN_0050653e() and FUN_00502bf4() — epilogue ✓
- Returns 0 on success, negative error on failure ✓
- No errors found

## FUN_005114D5 — PASS
Source: docs/21-audio-network-internals.md (full entry: Audio/Video Decode Subband Loop)
- Writes a1[0]+20=117, +24=a1[94], +28=a2 ✓
- Calls vtable+4(a1, -1) — init/reset ✓
- Main decode loop on symbol v3=a1[94]:
  - v3 < 192: v5=2 (small path) ✓
  - v3 208-215 (subband 0-7): checks (a2±1)&7 (forbidden/allowed positions) ✓
  - v3 192-207: v5=2 ✓
  - Default in range: v5=3 (skip) ✓
- Stores: a1[0]+20=96, +24=v3, +28=v5 ✓
- Calls vtable+4(a1, 4) — process decoded sample ✓
- v5==1: clear a1[94]=0, return success ✓
- v5==2: calls sub_5110FC fetch next symbol ✓
- v5==3: return 1 (silent skip) ✓
- All thresholds and logic verified ✓
- No errors found

## FUN_00405A30 — FAIL (missing doc entry)
Source: docs/21-audio-network-internals.md (no entry found)
- Source: 22 bytes, IDA Hex-Rays function
- Checks this[22] → dereference +16 → calls AIL_stop_sample(result)
- **Miles Sound System: AIL_stop_sample wrapper** — stops audio sample playback
- **No documentation entry exists** — no ## FUN_, no triage line in any docs/ file
- **Needs:** doc entry in docs/21-audio-network-internals.md as "AIL_stop_sample Wrapper — Miles Sound System sample stop"


