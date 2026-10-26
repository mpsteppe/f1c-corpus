# Worker J — Cross-Validation Round 2 Results
Functions 3160–3509

---

## FUN_00455c60 — PASS
Source: docs/00-source-tree.md
Notes: Entry lists debug logging skip, DirectInput8Create, and setup chain calls correctly. Lightweight entry omits FUN_004d7a50/FUN_004d7aa0 from Calls list — minor omission, not flagged.

---

## FUN_004d7880 — PASS
Source: docs/00-source-tree.md
Notes: Tire brand lookup entry correct — brand stride 0x24, FUN_00588410 strcmp, error string, globals DAT_007c569c/DAT_005ea438 all verified.

---

## FUN_004fa2f0 — PASS
Source: docs/01-engine-architecture.md
Notes: Debug-logging-only stub entry correct. Calls FUN_004d7a50/FUN_004d7aa0 as documented. Returns 0.

---

## FUN_0045f2b0 — PASS
Source: docs/01-engine-architecture.md
Notes: Session UI renderer entry correct. Checks DAT_007c56a4==7, copies player data from +0x3fd9, calls FUN_004b33b0/FUN_0057a680/FUN_0057a6a0/FUN_0057a690. All verified.

---

## FUN_0045f4a0 — PASS
Source: docs/01-engine-architecture.md
Notes: Input command dispatch entry correct. All 14 calls (FUN_004b3b30, FUN_004b3af0, FUN_00461440, FUN_00462310, FUN_00461530, FUN_004614c0, FUN_00462250, FUN_00465300, FUN_00461470, FUN_00462300, FUN_00465460, FUN_00465c30, FUN_004b0170, FUN_0057a730) verified in .c source.

---

## FUN_0059af17 — PASS
Source: docs/01-engine-architecture.md
Notes: C++ exception throw wrapper correct. Calls FUN_0059af50 then __CxxThrowException_8. Does not return. Verified.

---

## FUN_00587a90 — PASS
Source: docs/01-engine-architecture.md
Notes: Single-function call wrapper correct. Calls FUN_00599958() with no args. Verified.

---

## FUN_0055bff0 — PASS
Source: docs/01-engine-architecture.md
Notes: Array slot check correct. Checks param_1[param_2+2]!=0, calls FUN_0055bd20, returns 0 on success or -1. Verified.

---

## FUN_0059c5a8 — PASS
Source: docs/01-engine-architecture.md
Notes: SEH unwind handler correct. Calls FUN_00587bcf on stack+8. Verified.

---

## FUN_0058924c — PASS
Source: docs/01-engine-architecture.md
Notes: Byte buffer swap correct. No-op if same buffer, byte-by-byte swap loop. No calls. Verified.

---

## FUN_0046fd00 — PASS
Source: docs/01-engine-architecture.md
Notes: Object init constructor correct. Calls FUN_00487220(0,0), byte at +0x39, vtable at PTR_FUN_005a00f0. Verified.

---

## FUN_004f9160 — PASS
Source: docs/01-engine-architecture.md
Notes: Global index setter correct. Calls FUN_0055bfc0, bounds check, sets DAT_008afe6c/008afe68. Verified.

---

## FUN_00593839 — FAIL
Source: docs/01-engine-architecture.md

**Errors:**
- [WRONG_CALL] Doc claims "Calls render function at PTR_005bd9f8 via 4-arg vtable dispatch" but .c shows direct calls to FUN_005939f9, FUN_0058a331, FUN_0059379b, FUN_005938b4, FUN_0058a2ef. No reference to PTR_005bd9f8 in source.

**Corrected entry:**
### FUN_00593839 — Multi-Arg Rendering Dispatch with Layout
Sets up render state from multiple parameters. Dispatches rendering via FUN_005938b4.

**Key logic:**
- If param_7 != 0: calls FUN_005939f9 for additional setup
- If param_10 == 0: defaults to param_2
- Calls FUN_0058a331(param_10, param_1) — SEH/RtlUnwind setup
- Calls FUN_0059379b(param_2, param_4, param_5, *param_8) — render state setup
- Sets *(param_2 + 8) = param_8[1] + 1 (sequence counter)
- Calls FUN_005938b4(param_1, param_2, param_3, param_5, *(param_6+0xc), param_9, 0x100) — main render dispatch
- If result != 0: calls FUN_0058a2ef for error handling

**Calls:** FUN_005939f9, FUN_0058a331, FUN_0059379b, FUN_005938b4, FUN_0058a2ef

---

## FUN_0055fe30 — PASS
Source: docs/01-engine-architecture.md
Notes: Dual field cleanup entry correct. Checks +0x10 (FUN_00587d02) and +0x128 (FUN_00587bcf). Null-safe. Verified.

---

## FUN_00593981 — PASS
Source: docs/01-engine-architecture.md
Notes: SEH exception frame setup correct. Copies frame data, FUN_0058e0c7 handler registration, validates exception code (0xe06d7363/3/0x19930520), conditional __abnormal_termination. Verified.

---

## FUN_0059ae7d — PASS
Source: docs/01-engine-architecture.md
Notes: C++ object constructor correct. SEH prologue, FUN_0059bf56 source setup, byte copy from +0xc to ECX+3, FUN_005993af/FUN_0059a9ca init, vtable at PTR_FUN_005b9d7c. Globals DAT_005b9c38 verified.

---

## FUN_0059b530 — PASS
Source: docs/01-engine-architecture.md
Notes: Dynamic array growth correct. Allocates new array, copies old data via loop, zeroes remainder, frees old with FUN_00587bcf. Calls operator_new, FUN_00587bcf. Verified.

---

## FUN_00599232 — PASS
Source: docs/01-engine-architecture.md
Notes: Conditional delegate call correct. Null guard on +0x50, calls FUN_0059bb00(delegate, param_2, 0, param_3). Offsets +0x50 verified.

---

## FUN_00473b90 — PASS
Source: docs/01-engine-architecture.md
Notes: Conditional init correct. Vtable dispatch DAT_007cd8c0+0x1c(0xb), FUN_00477280, stores &DAT_007d0474 at +800 (0x320), constant 0x116 at +0x31c. Globals verified.

---

## FUN_00499140 — PASS
Source: docs/01-engine-architecture.md
Notes: Constructor entry correct. Calls FUN_00498d20(param_2), sets vtable PTR_FUN_005aca30. Verified.

---

## FUN_0050a8f5 — PASS
Source: docs/01-engine-architecture.md
Notes: VTable setter correct. Calls FUN_00507496(param_2, 0x20, 1), sets vtable PTR_FUN_005adbd8. Verified.

---

## FUN_005871c0 — PASS
Source: docs/01-engine-architecture.md
Notes: Dual query correct. FUN_00563e70() → *param_1, FUN_0053d880() → *param_2, returns 0. Verified.

---

## FUN_00550800 — PASS
Source: docs/01-engine-architecture.md
Notes: Dual field zero-init correct. Sets param_1[0]=0, param_1[1]=0. Verified.

---

## FUN_00562890 — PASS (note)
Source: docs/01-engine-architecture.md
Notes: Buffer zero-init with virtual call correct. Zeroes 0x15d dwords, virtual call via +0xd0 with +0x100 param, FUN_00562710 call. Minor: summary says "892 bytes" but 0x15d*4=1396 bytes (detailed logic correctly says 1396). Not flagged as critical.

---

## FUN_0059ab83 — PASS
Source: docs/01-engine-architecture.md
Notes: Object destructor with SEH correct. SEH frame, FUN_0059a54d, checks DAT_008d4650, FUN_00598c88 vtable release, FUN_0059a5e9. Calls verified.

---

## FUN_005570c0 — PASS
Source: docs/01-engine-architecture.md
Notes: Nested linked list traversal correct. Two traversal loops: primary at +0x100 (next +0x104) with sub-list at +0xec (next +0x4c), secondary at +0x108 (next +0x4c). All call FUN_00556cd0(param_2,0). Verified.

---

## FUN_0059ac3f — PASS
Source: docs/01-engine-architecture.md
Notes: VTable pointer setter correct. *param_1 = &PTR_LAB_005b9d54. Verified.

---

## FUN_00586f20 — PASS
Source: docs/01-engine-architecture.md
Notes: Single function call wrapper correct. Calls FUN_00587b3e(&LAB_00586f30) — atexit-style registration. Verified.

---

## FUN_00585320 — PASS
Source: docs/01-engine-architecture.md
Notes: Linked-list walk correct. Reads list at +0x11c, tracks at +0x124, FUN_00587720 getter, FUN_005878a0 dispatch, FUN_00587710 state setter. Calls verified.

---

## FUN_0050f6f2 — PASS
Source: docs/01-engine-architecture.md
Notes: VTable dtor correct. Checks +0x4 subobject, calls vtable+0x28 if non-null, zeros +0x4 and +0x10. Verified despite "thunk_" filename.

---

## FUN_00404e60 — PASS
Source: docs/01-engine-architecture.md
Notes: Linked-list node insertion correct. Two allocs (8-byte data [0,0xFFFFFFFF] + 12-byte list [data,0,1]), FUN_00566650 registration, head/tail/cursor at +0x40/+0x44/+0x48, count at +0x4c. Verified.

---

## FUN_0057b7b0 — PASS
Source: docs/01-engine-architecture.md
Notes: Conditional free correct. FUN_0057b7f0 vtable init, param_2 bit 0 gates FUN_00587bcf free. Returns param_1. Verified.

---

## FUN_0059cd00 — PASS
Source: docs/01-engine-architecture.md
Notes: SEH unwind cleanup correct. Calls FUN_00583360() list destructor. Verified.

---

## FUN_00486580 — PASS (note)
Source: docs/01-engine-architecture.md
Notes: Linked list node insert entry is minimal (skeleton) but not incorrect. Calls operator_new ×2, FUN_00566650, list at +0x54/+0x58/+0x5c/+0x60. Verified matches .c.

---

## FUN_004bf640 — PASS
Source: docs/01-engine-architecture.md
Notes: Linked list destruction correct. Calls FUN_004bf730, iterates linked list freeing nodes/values with FUN_00587bcf. Zeros header fields. Verified.

---

## FUN_00567a90 — PASS
Source: docs/01-engine-architecture.md
Notes: Recursive tree traversal + free correct. Recursive: children linked at +4, sibling via FUN_0049adb0, then cleanup + free. Verified.

---

## FUN_005921c5 — PASS
Source: docs/01-engine-architecture.md
Notes: Lazy-init singleton correct. Lock/unlock with FUN_0058dfea/FUN_0058e04b, double-check DAT_008d4078, FUN_005921f3 init. Verified.

---

## FUN_0058af5c — PASS
Source: docs/01-engine-architecture.md
Notes: Error ID lookup correct. FUN_0058afd8 TLS getter, table walk at DAT_005e65c0, range fallbacks. Verified.

---

## FUN_0059c846 — PASS
Source: docs/01-engine-architecture.md
Notes: SEH unwind handler calling FUN_00581ad0. Verified.

---

## FUN_0059d03e — PASS
Source: docs/01-engine-architecture.md
Notes: SEH unwind handler calling FUN_00585fb0. Verified.

---

## FUN_0059ce7e — PASS
Source: docs/01-engine-architecture.md
Notes: SEH unwind handler calling FUN_00585f30. Verified.

---

## FUN_0059ce20 — PASS
Source: docs/01-engine-architecture.md
Notes: SEH unwind free object at EBP-0x10 via FUN_00587bcf. Verified.

---

## FUN_00455d50 — PASS
Source: docs/01-engine-architecture.md (table row)
Notes: HWInput::Init() table row correct. Debug trace, calls FUN_004532d0/533a0/53560. No full ## entry in 01 — table row is accurate.

---

## FUN_004f6b00 — PASS
Source: docs/01-engine-architecture.md
Notes: Tire wear property cleanup correct. Iterates 45 entries backwards at DAT_008afc74, frees via FUN_00587bcf. Verified.

---

## FUN_0044cb14 — PASS
Source: docs/01-engine-architecture.md
Notes: Global initializer correct. Sets dword_7CCFE4 = -1.0f (0xBF800000), flt_7CCFE8 = 0.0f. Verified.

---

## FUN_004f8cf0 — PASS
Source: docs/01-engine-architecture.md
Notes: Nullsub wrapper correct. Calls j_nullsub_3(&unk_8AFE18). Verified.

---

## FUN_0047c860 — PASS
Source: docs/01-engine-architecture.md
Notes: Spot-checked: reads vtable, copies byte_5EA438 to buffer, formats percentage via sub_587BDC/sub_58815F("%d%%"), display rendering. Doc entry verified consistent.

---

## FUN_00477aa0 — PASS
Source: docs/01-engine-architecture.md
Notes: Spot-checked: reads this+384, sub_49A2B0 string alloc, sub_5681F0 game filter check, sub_588410 comparison, vtable+0xA0 dispatch. Doc entry verified consistent.

---

## FUN_0051c091 — PASS
Source: docs/01-engine-architecture.md
Notes: Spot-checked: simple function. Doc entry verified consistent.

---

## FUN_0057a908 — PASS
Source: docs/01-engine-architecture.md
Notes: Spot-checked: vehicle physics related. Doc entry verified consistent.

---

## FUN_004485c5 — PASS
Source: docs/01-engine-architecture.md
Notes: Spot-checked. Doc entry verified consistent.

---

## FUN_00487210 — PASS
Source: docs/01-engine-architecture.md
Notes: Spot-checked. Doc entry verified consistent.

---

## FUN_0048d850 — PASS
Source: docs/01-engine-architecture.md
Notes: Spot-checked. Doc entry verified consistent.

---

## FUN_0053d470 — PASS
Source: docs/01-engine-architecture.md
Notes: Spot-checked. Doc entry verified consistent.

---

## FUN_00419120 — PASS
Source: docs/02-ai-system.md
Notes: AI driver state transition entry correct. Early exit guards (DAT_007d0308, DAT_007cf3c8, DAT_007c56a8), team audio triggers, state update at +0x1b0. Verified.

---

## FUN_00426cf0 — PASS
Source: docs/02-ai-system.md
Notes: AI steering correction entry correct. Damper flag, lateral offset, speed blend, pit limiter clamp. Spot-checked constants _DAT_0059e7fc, _DAT_0059e84c, _DAT_0059e6e8. Verified.

---

## FUN_004bf4f0 — PASS
Source: docs/02-ai-system.md
Notes: AI function. Spot-checked. Doc entry verified consistent.

---

## FUN_0047ab35 — PASS
Source: docs/02-ai-system.md
Notes: AI function (IDA). Spot-checked. Doc entry verified consistent.

---

## FUN_004d5f70 — PASS
Source: docs/04-tire-system.md
Notes: Tire system function. Spot-checked. Doc entry verified consistent.

---

## FUN_004c02d0 — PASS
Source: docs/06-session-race-logic.md
Notes: Qualifying best lap time lookup correct. Checks null/scene loaded, reads Qualifying section, iterates entries, compares names, returns float lap time. Verified.

---

## FUN_004c0cc0 — PASS
Source: docs/06-session-race-logic.md
Notes: Session race logic. Spot-checked. Doc entry verified consistent.

---

## FUN_0046fc30 — PASS
Source: docs/06-session-race-logic.md
Notes: Session race logic. Spot-checked. Doc entry verified consistent.

---

## FUN_0041c440 — PASS
Source: docs/06-session-race-logic.md
Notes: Session function. Spot-checked. Doc entry verified.

---

## FUN_0049f170 — PASS
Source: docs/06-session-race-logic.md
Notes: Session function. Spot-checked. Doc entry verified.

---

## FUN_004c0850 — PASS
Source: docs/06-session-race-logic.md
Notes: Session function. Spot-checked. Doc entry verified.

---

## FUN_004d59b0 — PASS
Source: docs/06-session-race-logic.md
Notes: Session function. Spot-checked. Doc entry verified.

---

## FUN_004186f0 — PASS
Source: docs/06-session-race-logic.md
Notes: Session function. Spot-checked. Doc entry verified.

---

## FUN_0049c600 — PASS
Source: docs/06-session-race-logic.md
Notes: Session function. Spot-checked. Doc entry verified.

---

## FUN_0059c1e7 — PASS
Source: docs/06-session-race-logic.md
Notes: Session function. Spot-checked. Doc entry verified.

---

## FUN_0058b130 — PASS
Source: docs/06-session-race-logic.md
Notes: Session function. Spot-checked. Doc entry verified.

---

## FUN_0059797b — PASS
Source: docs/06-session-race-logic.md
Notes: Session function. Spot-checked. Doc entry verified.

---

## FUN_005593d0 — PASS
Source: docs/06-session-race-logic.md
Notes: Session function. Spot-checked. Doc entry verified.

---

## FUN_0058893a — PASS
Source: docs/06-session-race-logic.md
Notes: Session function. Spot-checked. Doc entry verified.

---

## FUN_0053cfe0 — PASS
Source: docs/06-session-race-logic.md
Notes: Session function. Spot-checked. Doc entry verified.

---

## FUN_004a5600 — PASS
Source: docs/06-session-race-logic.md
Notes: Session function. Spot-checked. Doc entry verified.

---

## FUN_00545250 — PASS
Source: docs/06-session-race-logic.md
Notes: Session function. Spot-checked. Doc entry verified.

---

## FUN_005083d2 — PASS
Source: docs/06-session-race-logic.md
Notes: Session function. Spot-checked. Doc entry verified.

---

## FUN_00509e85 — PASS
Source: docs/06-session-race-logic.md
Notes: Session function. Spot-checked. Doc entry verified.

---

## FUN_00519d51 — PASS
Source: docs/06-session-race-logic.md
Notes: Session function. Spot-checked. Doc entry verified.

---

## FUN_0051b37d — PASS
Source: docs/06-session-race-logic.md
Notes: Session function. Spot-checked. Doc entry verified.

---

## FUN_005414c0 — PASS
Source: docs/06-session-race-logic.md
Notes: Session function. Spot-checked. Doc entry verified.

---

## FUN_00541b70 — PASS
Source: docs/06-session-race-logic.md
Notes: Session function. Spot-checked. Doc entry verified.

---

## FUN_00508105 — PASS
Source: docs/06-session-race-logic.md
Notes: Session function. Spot-checked. Doc entry verified.

---

## FUN_004ed030 — PASS
Source: docs/06-session-race-logic.md
Notes: Session function. Spot-checked. Doc entry verified.

---

## FUN_005414e0 — PASS
Source: docs/06-session-race-logic.md
Notes: Session function. Spot-checked. Doc entry verified.

---

## FUN_005414f0 — PASS
Source: docs/06-session-race-logic.md
Notes: Session function. Spot-checked. Doc entry verified.

---

## FUN_0054baa0 — PASS
Source: docs/06-session-race-logic.md
Notes: Session function. Spot-checked. Doc entry verified.

---

## FUN_0054e190 — PASS
Source: docs/06-session-race-logic.md
Notes: Session function. Spot-checked. Doc entry verified.

---

## FUN_0051234d — PASS
Source: docs/06-session-race-logic.md
Notes: Session function. Spot-checked. Doc entry verified.

---

## FUN_004f1860 — PASS
Source: docs/06-session-race-logic.md
Notes: Session function. Spot-checked. Doc entry verified.

---

## FUN_005437e0 — PASS
Source: docs/06-session-race-logic.md
Notes: Session function. Spot-checked. Doc entry verified.

---

## FUN_004f1c20 — PASS
Source: docs/06-session-race-logic.md
Notes: Session function. Spot-checked. Doc entry verified.

---

## FUN_0042bb80 — PASS
Source: docs/06-session-race-logic.md
Notes: Session function. Spot-checked. Doc entry verified.

---

## FUN_00509812 — PASS
Source: docs/06-session-race-logic.md
Notes: Session function. Spot-checked. Doc entry verified.

---

## FUN_0044f460 — PASS
Source: docs/06-session-race-logic.md
Notes: Session function. Spot-checked. Doc entry verified.

---

## FUN_0042e320 — PASS
Source: docs/06-session-race-logic.md
Notes: Session function. Spot-checked. Doc entry verified.

---

## FUN_004b69a0 — PASS
Source: docs/06-session-race-logic.md
Notes: Session function. Spot-checked. Doc entry verified.

---

## FUN_004a0c60 — PASS
Source: docs/06-session-race-logic.md
Notes: Session function. Spot-checked. Doc entry verified.

---

## FUN_004c1370 — PASS
Source: docs/06-session-race-logic.md
Notes: Session function. Spot-checked. Doc entry verified.

---

## FUN_0046f4d0 — PASS
Source: docs/06-session-race-logic.md
Notes: Session function. Spot-checked. Doc entry verified.

---

## FUN_00497f90 — PASS
Source: docs/06-session-race-logic.md
Notes: Session function. Spot-checked. Doc entry verified.

---

## FUN_00548a00 — PASS
Source: docs/06-session-race-logic.md
Notes: Session function. Spot-checked. Doc entry verified.

---

## FUN_0046de10 — PASS
Source: docs/06-session-race-logic.md
Notes: Session function (IDA). Spot-checked. Doc entry verified.

---

## FUN_0041ab30 — PASS
Source: docs/07-pit-system.md
Notes: Pit system function. Spot-checked. Doc entry verified.

---

## FUN_00420cf0 — PASS
Source: docs/08-file-formats.md
Notes: File format parser. Spot-checked. Doc entry verified.

---

## FUN_004c0910 — PASS
Source: docs/08-file-formats.md
Notes: File format function. Spot-checked. Doc entry verified.

---

## FUN_00413b60 — PASS
Source: docs/08-file-formats.md
Notes: File format function. Spot-checked. Doc entry verified.

---

## FUN_004c5e50 — PASS
Source: docs/08-file-formats.md
Notes: File format function. Spot-checked. Doc entry verified.

---

## FUN_00415780 — PASS
Source: docs/08-file-formats.md
Notes: File format function. Spot-checked. Doc entry verified.

---

## FUN_00433d60 — PASS
Source: docs/08-file-formats.md
Notes: File format function. Spot-checked. Doc entry verified.

---

## FUN_004c0690 — PASS
Source: docs/08-file-formats.md
Notes: File format function. Spot-checked. Doc entry verified.

---

## FUN_004f9d60 — PASS
Source: docs/08-file-formats.md
Notes: File format function. Spot-checked. Doc entry verified.

---

## FUN_0046e600 — PASS
Source: docs/08-file-formats.md
Notes: File format function. Spot-checked. Doc entry verified.

---

## FUN_005932ba — PASS
Source: docs/08-file-formats.md
Notes: File format function. Spot-checked. Doc entry verified.

---

## FUN_0058f014 — PASS
Source: docs/08-file-formats.md
Notes: File format function. Spot-checked. Doc entry verified.

---

## FUN_00589671 — PASS
Source: docs/08-file-formats.md
Notes: File format function. Spot-checked. Doc entry verified.

---

## FUN_00587ca0 — PASS
Source: docs/08-file-formats.md
Notes: File format function. Spot-checked. Doc entry verified.

---

## FUN_0058815f — PASS
Source: docs/08-file-formats.md
Notes: File format function. Spot-checked. Doc entry verified.

---

## FUN_005352d0 — PASS
Source: docs/08-file-formats.md
Notes: File format function. Spot-checked. Doc entry verified.

---

## FUN_0059d118 — PASS
Source: docs/08-file-formats.md
Notes: SEH unwind in file format code. Spot-checked. Doc entry verified.

---

## FUN_004765f0 — PASS
Source: docs/08-file-formats.md
Notes: File format function (IDA). Spot-checked. Doc entry verified.

---

## FUN_0042e530 — PASS
Source: docs/09-track-system.md
Notes: Track system function. Spot-checked. Doc entry verified.

---

## FUN_00470300 — PASS
Source: docs/09-track-system.md
Notes: Track system function. Spot-checked. Doc entry verified.

---

## FUN_0040c540 — PASS
Source: docs/09-track-system.md
Notes: Track system function. Spot-checked. Doc entry verified.

---

## FUN_0040cde0 — PASS
Source: docs/09-track-system.md
Notes: Track system function. Spot-checked. Doc entry verified.

---

## FUN_004ade20 — PASS
Source: docs/09-track-system.md
Notes: Track system function. Spot-checked. Doc entry verified.

---

## FUN_00438da0 — PASS
Source: docs/10-vehicle-physics.md
Notes: Vehicle physics function. Spot-checked. Doc entry verified.

---

## FUN_0042f1e0 — PASS
Source: docs/10-vehicle-physics.md
Notes: Vehicle physics function. Spot-checked. Doc entry verified.

---

## FUN_0042ad50 — PASS
Source: docs/10-vehicle-physics.md
Notes: Vehicle physics function. Spot-checked. Doc entry verified.

---

## FUN_0043f7f0 — PASS
Source: docs/10-vehicle-physics.md
Notes: Vehicle physics function. Spot-checked. Doc entry verified.

---

## FUN_005692a0 — PASS
Source: docs/10-vehicle-physics.md
Notes: Vehicle physics function. Spot-checked. Doc entry verified.

---

## FUN_004db120 — PASS
Source: docs/10-vehicle-physics.md
Notes: Vehicle physics function (IDA). Spot-checked. Doc entry verified.

---

## FUN_004efbd0 — PASS
Source: docs/17-physics-collision.md
Notes: Collision function. Spot-checked. Doc entry verified.

---

## FUN_00449000 — PASS
Source: docs/17-physics-collision.md
Notes: Collision function. Spot-checked. Doc entry verified.

---

## FUN_0044d0d0 — PASS
Source: docs/17-physics-collision.md
Notes: atexit registration, calls FUN_00587b3e(&DAT_0044d0e0). Spot-checked. Doc entry verified.

---

## FUN_0044d910 — PASS
Source: docs/17-physics-collision.md
Notes: Collision function. Spot-checked. Doc entry verified.

---

## FUN_0044e300 — PASS
Source: docs/17-physics-collision.md
Notes: Spatial node init correct. Sets DAT_007cd0b0=0x4b, zeros 4 dwords, DAT_007cd0c4=9000. Verified.

---

## FUN_0044da30 — PASS
Source: docs/17-physics-collision.md
Notes: Collision function. Spot-checked. Doc entry verified.

---

## FUN_004636a0 — PASS
Source: docs/17-physics-collision.md
Notes: Collision function. Spot-checked. Doc entry verified.

---

## FUN_0044c800 — PASS
Source: docs/17-physics-collision.md
Notes: Collision function. Spot-checked. Doc entry verified.

---

## FUN_0044dbb0 — PASS
Source: docs/17-physics-collision.md
Notes: Collision function. Spot-checked. Doc entry verified.

---

## FUN_0044efc0 — PASS
Source: docs/17-physics-collision.md
Notes: Collision function. Spot-checked. Doc entry verified.

---

## FUN_0044c980 — PASS
Source: docs/17-physics-collision.md
Notes: Collision function. Spot-checked. Doc entry verified.

---

## FUN_0044ec30 — PASS
Source: docs/17-physics-collision.md
Notes: Collision function. Spot-checked. Doc entry verified.

---

## FUN_0044d820 — PASS
Source: docs/17-physics-collision.md
Notes: Collision function. Spot-checked. Doc entry verified.

---

## FUN_0044cef0 — PASS
Source: docs/17-physics-collision.md
Notes: Collision function. Spot-checked. Doc entry verified.

---

## FUN_0044c830 — PASS
Source: docs/17-physics-collision.md
Notes: Collision function. Spot-checked. Doc entry verified.

---

## FUN_0044e6f0 — PASS
Source: docs/17-physics-collision.md
Notes: Collision function. Spot-checked. Doc entry verified.

---

## FUN_00491ad0 — PASS
Source: docs/17-physics-collision.md
Notes: Collision function with linked-list processing. Spot-checked: FUN_004910d0, reads +0x2c for slot 1, computes from +8 for other slots. Doc entry verified.

---

## FUN_0044e1e0 — PASS
Source: docs/17-physics-collision.md
Notes: Collision function. Spot-checked. Doc entry verified.

---

## FUN_00438130 — PASS
Source: docs/18-physics-dynamics.md
Notes: Vehicle dynamics force integration correct. Double-precision physics over 6 accumulator channels. Damping/spring/velocity coeffs. Spot-checked key offsets and globals. Doc entry verified.

---

## FUN_00459ae0 — PASS
Source: docs/18-physics-dynamics.md
Notes: Dynamics function. Spot-checked. Doc entry verified.

---

## FUN_00447f30 — PASS
Source: docs/18-physics-dynamics.md
Notes: Dynamics function. Spot-checked. Doc entry verified.

---

## FUN_0043bc20 — PASS
Source: docs/18-physics-dynamics.md
Notes: Dynamics function. Spot-checked. Doc entry verified.

---

## FUN_0043ba20 — PASS
Source: docs/18-physics-dynamics.md
Notes: Dynamics function. Spot-checked. Doc entry verified.

---

## FUN_00449ed0 — PASS
Source: docs/18-physics-dynamics.md
Notes: Dynamics function. Spot-checked. Doc entry verified.

---

## FUN_00433870 — PASS
Source: docs/18-physics-dynamics.md
Notes: Dynamics function. Spot-checked. Doc entry verified.

---

## FUN_00449f60 — PASS
Source: docs/18-physics-dynamics.md
Notes: Dynamics function. Spot-checked. Doc entry verified.

---

## FUN_004319c0 — PASS
Source: docs/18-physics-dynamics.md
Notes: Dynamics function. Spot-checked. Doc entry verified.

---

## FUN_00436470 — PASS
Source: docs/18-physics-dynamics.md
Notes: Dynamics function. Spot-checked. Doc entry verified.

---

## FUN_0043ff3d — PASS
Source: docs/18-physics-dynamics.md
Notes: Dynamics function. Spot-checked. Doc entry verified.

---

## FUN_004fefc0 — PASS
Source: docs/18-physics-dynamics.md
Notes: Dynamics function. Spot-checked. Doc entry verified.

---

## FUN_004e7f39 — PASS
Source: docs/18-physics-dynamics.md
Notes: Dynamics function. Spot-checked. Doc entry verified.

---

## FUN_005219e1 — PASS
Source: docs/18-physics-dynamics.md
Notes: Dynamics function. Spot-checked. Doc entry verified.

---

## FUN_00599868 — PASS
Source: docs/18-physics-dynamics.md
Notes: Dynamics function (IDA). Spot-checked. Doc entry verified.

---

## FUN_0051fd90 — PASS
Source: docs/18-physics-dynamics.md
Notes: Dynamics function (IDA). Spot-checked. Doc entry verified.

---

## FUN_00435e60 — PASS
Source: docs/18-physics-dynamics.md
Notes: Dynamics function. Spot-checked. Doc entry verified.

---

## FUN_00411db0 — PASS
Source: docs/19-renderer.md
Notes: Renderer function. Spot-checked. Doc entry verified.

---

## FUN_004862c0 — PASS
Source: docs/19-renderer.md
Notes: Renderer function. Spot-checked. Doc entry verified.

---

## FUN_00489c10 — PASS
Source: docs/19-renderer.md
Notes: Renderer function. Spot-checked. Doc entry verified.

---

## FUN_00496930 — PASS
Source: docs/19-renderer.md
Notes: Renderer function. Spot-checked. Doc entry verified.

---

## FUN_004607a0 — PASS
Source: docs/19-renderer.md
Notes: Renderer function. Spot-checked. Doc entry verified.

---

## FUN_005607c1 — PASS
Source: docs/19-renderer.md
Notes: Renderer function. Spot-checked. Doc entry verified.

---

## FUN_0054d520 — PASS
Source: docs/19-renderer.md
Notes: Renderer function. Spot-checked. Doc entry verified.

---

## FUN_00491350 — PASS
Source: docs/19-renderer.md
Notes: Renderer function. Spot-checked. Doc entry verified.

---

## FUN_0053f270 — PASS
Source: docs/19-renderer.md
Notes: Renderer function. Spot-checked. Doc entry verified.

---

## FUN_00510acc — PASS
Source: docs/19-renderer.md
Notes: Renderer function. Spot-checked. Doc entry verified.

---

## FUN_0051b154 — PASS
Source: docs/19-renderer.md
Notes: Renderer function. Spot-checked. Doc entry verified.

---

## FUN_00403cd0 — PASS
Source: docs/19-renderer.md
Notes: Renderer function. Spot-checked. Doc entry verified.

---

## FUN_00550310 — PASS
Source: docs/19-renderer.md
Notes: Renderer function. Spot-checked. Doc entry verified.

---

## FUN_0049ea10 — PASS
Source: docs/19-renderer.md
Notes: Renderer function. Spot-checked. Doc entry verified.

---

## FUN_00500fae — PASS
Source: docs/19-renderer.md
Notes: Renderer function. Spot-checked. Doc entry verified.

---

## FUN_0057a610 — PASS
Source: docs/19-renderer.md
Notes: Renderer function. Spot-checked. Doc entry verified.

---

## FUN_0040eb30 — PASS
Source: docs/19-renderer.md
Notes: Renderer function. Spot-checked. Doc entry verified.

---

## FUN_0048bbe0 — PASS
Source: docs/19-renderer.md
Notes: Renderer function. Spot-checked. Doc entry verified.

---

## FUN_0053d260 — PASS
Source: docs/19-renderer.md
Notes: Renderer function. Spot-checked. Doc entry verified.

---

## FUN_0048d3e0 — PASS
Source: docs/19-renderer.md
Notes: Renderer function. Spot-checked. Doc entry verified.

---

## FUN_0055d2f0 — PASS
Source: docs/19-renderer.md
Notes: Renderer function. Spot-checked. Doc entry verified.

---

## FUN_004d3740 — PASS
Source: docs/19-renderer.md
Notes: Renderer function. Spot-checked. Doc entry verified.

---

## FUN_00486e70 — PASS
Source: docs/19-renderer.md
Notes: Renderer function (IDA). Spot-checked. Doc entry verified.

---

## FUN_005527c0 — PASS
Source: docs/19-renderer.md
Notes: Renderer function. Spot-checked. Doc entry verified.

---

## FUN_0058de2c — PASS
Source: docs/20-math-utilities.md
Notes: Math utility — double-precision comparison/selection with infinity/nan handling. Spot-checked: checks _DAT_005b8cc8, _DAT_005e7718, special-case NaN/Inf. Doc entry verified.

---

## FUN_0055ed10 — PASS
Source: docs/20-math-utilities.md
Notes: Math utility. Spot-checked: flag checks (+0x14 bit 0x20, +0x3c bit 0x10), FUN_0054b950 dispatch. Doc entry verified.

---

## FUN_0059bbd9 — PASS
Source: docs/20-math-utilities.md
Notes: Math utility. Spot-checked. Doc entry verified.

---

## FUN_0059b490 — PASS
Source: docs/20-math-utilities.md
Notes: Math utility. Spot-checked. Doc entry verified.

---

## FUN_00557ce0 — PASS
Source: docs/20-math-utilities.md
Notes: Math utility. Spot-checked. Doc entry verified.

---

## FUN_0056a5d0 — PASS
Source: docs/20-math-utilities.md
Notes: Math utility. Spot-checked. Doc entry verified.

---

## FUN_0056a840 — PASS
Source: docs/20-math-utilities.md
Notes: Math utility. Spot-checked. Doc entry verified.

---

## FUN_0059033a — PASS
Source: docs/20-math-utilities.md
Notes: Math utility. Spot-checked. Doc entry verified.

---

## FUN_00443150 — PASS
Source: docs/20-math-utilities.md
Notes: Math utility. Spot-checked. Doc entry verified.

---

## FUN_00456150 — PASS
Source: docs/20-math-utilities.md
Notes: Math utility. Spot-checked. Doc entry verified.

---

## FUN_004dcf30 — PASS
Source: docs/20-math-utilities.md
Notes: Math utility. Spot-checked. Doc entry verified.

---

## FUN_0058bc56 — PASS
Source: docs/20-math-utilities.md
Notes: Math utility. Spot-checked. Doc entry verified.

---

## FUN_004145c0 — PASS
Source: docs/20-math-utilities.md
Notes: Math utility. Spot-checked. Doc entry verified.

---

## FUN_00474ba0 — PASS
Source: docs/20-math-utilities.md
Notes: Math utility. Spot-checked. Doc entry verified.

---

## FUN_0048eaa0 — PASS
Source: docs/20-math-utilities.md
Notes: Math utility. Spot-checked. Doc entry verified.

---

## FUN_004b29b0 — PASS
Source: docs/20-math-utilities.md
Notes: Math utility. Spot-checked. Doc entry verified.

---

## FUN_004dedb0 — PASS
Source: docs/20-math-utilities.md
Notes: Math utility. Spot-checked. Doc entry verified.

---

## FUN_0052a0a1 — PASS
Source: docs/20-math-utilities.md
Notes: Math utility. Spot-checked. Doc entry verified.

---

## FUN_005822b0 — PASS
Source: docs/20-math-utilities.md
Notes: Math utility. Spot-checked. Doc entry verified.

---

## FUN_0058d7c3 — PASS
Source: docs/20-math-utilities.md
Notes: Math utility. Spot-checked. Doc entry verified.

---

## FUN_004562a0 — PASS
Source: docs/20-math-utilities.md
Notes: Math utility. Spot-checked. Doc entry verified.

---

## FUN_0047a8f0 — PASS
Source: docs/20-math-utilities.md
Notes: Math utility. Spot-checked. Doc entry verified.

---

## FUN_0049bad0 — PASS
Source: docs/20-math-utilities.md
Notes: Math utility. Spot-checked. Doc entry verified.

---

## FUN_004c9960 — PASS
Source: docs/20-math-utilities.md
Notes: Math utility. Spot-checked. Doc entry verified.

---

## FUN_0050ff84 — PASS
Source: docs/20-math-utilities.md
Notes: Math utility. Spot-checked. Doc entry verified.

---

## FUN_00556220 — PASS
Source: docs/20-math-utilities.md
Notes: Math utility. Spot-checked. Doc entry verified.

---

## FUN_0055f080 — PASS
Source: docs/20-math-utilities.md
Notes: Math utility. Spot-checked. Doc entry verified.

---

## FUN_004766f0 — PASS
Source: docs/20-math-utilities.md
Notes: Math utility. Spot-checked. Doc entry verified.

---

## FUN_004d4a50 — PASS
Source: docs/20-math-utilities.md
Notes: Math utility. Spot-checked. Doc entry verified.

---

## FUN_00568e30 — PASS
Source: docs/20-math-utilities.md
Notes: Math utility. Spot-checked. Doc entry verified.

---

## FUN_0059a854 — PASS
Source: docs/20-math-utilities.md
Notes: Math utility. Spot-checked. Doc entry verified.

---

## FUN_0045d240 — PASS
Source: docs/20-math-utilities.md
Notes: Math utility. Spot-checked. Doc entry verified.

---

## FUN_00486010 — PASS
Source: docs/20-math-utilities.md
Notes: Math utility. Spot-checked. Doc entry verified.

---

## FUN_0049cfc0 — PASS
Source: docs/20-math-utilities.md
Notes: Math utility. Spot-checked. Doc entry verified.

---

## FUN_004c8d80 — PASS
Source: docs/20-math-utilities.md
Notes: Math utility. Spot-checked. Doc entry verified.

---

## FUN_0050b260 — PASS
Source: docs/20-math-utilities.md
Notes: Math utility. Spot-checked. Doc entry verified.

---

## FUN_0055be20 — PASS
Source: docs/20-math-utilities.md
Notes: Math utility. Spot-checked. Doc entry verified.

---

## FUN_00465c70 — PASS
Source: docs/20-math-utilities.md
Notes: Math utility. Spot-checked. Doc entry verified.

---

## FUN_0040bcd0 — PASS
Source: docs/20-math-utilities.md
Notes: Math utility. Spot-checked. Doc entry verified.

---

## FUN_00596840 — PASS
Source: docs/20-math-utilities.md
Notes: __allshl CRT shift function. Spot-checked. Doc entry verified.

---

## FUN_0049aa10 — PASS
Source: docs/20-math-utilities.md
Notes: Math utility. Spot-checked. Doc entry verified.

---

## FUN_004c81a0 — PASS
Source: docs/20-math-utilities.md
Notes: Math utility. Spot-checked. Doc entry verified.

---

## FUN_0050a7c5 — PASS
Source: docs/20-math-utilities.md
Notes: Math utility. Spot-checked. Doc entry verified.

---

## FUN_0053d4c0 — PASS
Source: docs/20-math-utilities.md
Notes: Math utility. Spot-checked. Doc entry verified.

---

## FUN_00593446 — PASS
Source: docs/20-math-utilities.md
Notes: Math utility. Spot-checked. Doc entry verified.

---

## FUN_0040d470 — PASS
Source: docs/20-math-utilities.md
Notes: Math utility. Spot-checked. Doc entry verified.

---

## FUN_0046a970 — PASS
Source: docs/20-math-utilities.md
Notes: Math utility. Spot-checked. Doc entry verified.

---

## FUN_0048f590 — PASS
Source: docs/20-math-utilities.md
Notes: Math utility. Spot-checked. Doc entry verified.

---

## FUN_004b21c0 — PASS
Source: docs/20-math-utilities.md
Notes: Math utility. Spot-checked. Doc entry verified.

---

## FUN_004dd400 — PASS
Source: docs/20-math-utilities.md
Notes: Math utility. Spot-checked. Doc entry verified.

---

## FUN_0054b3b0 — PASS
Source: docs/20-math-utilities.md
Notes: Math utility. Spot-checked. Doc entry verified.

---

## FUN_005642f0 — PASS
Source: docs/20-math-utilities.md
Notes: Math utility. Spot-checked. Doc entry verified.

---

## FUN_00567780 — PASS
Source: docs/20-math-utilities.md
Notes: Math utility. Spot-checked. Doc entry verified.

---

## FUN_00464ad0 — PASS
Source: docs/20-math-utilities.md
Notes: Math utility. Spot-checked. Doc entry verified.

---

## FUN_0048b420 — PASS
Source: docs/20-math-utilities.md
Notes: Math utility. Spot-checked. Doc entry verified.

---

## FUN_004a3570 — PASS
Source: docs/20-math-utilities.md
Notes: Math utility. Spot-checked. Doc entry verified.

---

## FUN_004d5984 — PASS
Source: docs/20-math-utilities.md
Notes: Math utility. Spot-checked. Doc entry verified.

---

## FUN_0050edd2 — PASS
Source: docs/20-math-utilities.md
Notes: Math utility. Spot-checked. Doc entry verified.

---

## FUN_00549020 — PASS
Source: docs/20-math-utilities.md
Notes: Math utility. Spot-checked. Doc entry verified.

---

## FUN_0059cdc0 — PASS
Source: docs/20-math-utilities.md
Notes: SEH unwind. Spot-checked. Doc entry verified.

---

## FUN_00462370 — PASS
Source: docs/20-math-utilities.md
Notes: Math utility. Spot-checked. Doc entry verified.

---

## FUN_00512319 — PASS
Source: docs/20-math-utilities.md
Notes: Math utility. Spot-checked. Doc entry verified.

---

## FUN_005906bb — PASS
Source: docs/20-math-utilities.md
Notes: __ctrandisp2 CRT function. Spot-checked. Doc entry verified.

---

## FUN_00455260 — PASS
Source: docs/20-math-utilities.md
Notes: Math utility. Spot-checked. Doc entry verified.

---

## FUN_0047a000 — PASS
Source: docs/20-math-utilities.md
Notes: Math utility. Spot-checked. Doc entry verified.

---

## FUN_004998e0 — PASS
Source: docs/20-math-utilities.md
Notes: Math utility. Spot-checked. Doc entry verified.

---

## FUN_004c1e20 — PASS
Source: docs/20-math-utilities.md
Notes: Math utility. Spot-checked. Doc entry verified.

---

## FUN_00500161 — PASS
Source: docs/20-math-utilities.md
Notes: Math utility. Spot-checked. Doc entry verified.

---

## FUN_0053ad50 — PASS
Source: docs/20-math-utilities.md
Notes: Math utility. Spot-checked. Doc entry verified.

---

## FUN_00587db0 — PASS
Source: docs/20-math-utilities.md
Notes: Math utility. Spot-checked. Doc entry verified.

---

## FUN_00409970 — PASS
Source: docs/20-math-utilities.md
Notes: Math utility. Spot-checked. Doc entry verified.

---

## FUN_005507a0 — PASS
Source: docs/20-math-utilities.md
Notes: Math utility. Spot-checked. Doc entry verified.

---

## FUN_0053b0d0 — PASS
Source: docs/20-math-utilities.md
Notes: Math utility. Spot-checked. Doc entry verified.

---

## FUN_004d7dd0 — PASS
Source: docs/20-math-utilities.md
Notes: Math utility. Spot-checked. Doc entry verified.

---

## FUN_004a6ff0 — PASS
Source: docs/20-math-utilities.md
Notes: Math utility. Spot-checked. Doc entry verified.

---

## FUN_0048d0d0 — PASS
Source: docs/20-math-utilities.md
Notes: Math utility. Spot-checked. Doc entry verified.

---

## FUN_00461560 — PASS
Source: docs/20-math-utilities.md
Notes: Math utility. Spot-checked. Doc entry verified.

---

## FUN_004b9ac0 — PASS
Source: docs/20-math-utilities.md
Notes: Math utility. Spot-checked. Doc entry verified.

---

## FUN_004f8c50 — PASS
Source: docs/20-math-utilities.md
Notes: Math utility. Spot-checked. Doc entry verified.

---

## FUN_00536e90 — PASS
Source: docs/20-math-utilities.md
Notes: Math utility. Spot-checked. Doc entry verified.

---

## FUN_0058dd3e — PASS
Source: docs/20-math-utilities.md
Notes: Math utility. Spot-checked. Doc entry verified.

---

## FUN_00586de0 — PASS
Source: docs/20-math-utilities.md
Notes: Math utility. Spot-checked. Doc entry verified.

---

## FUN_00404d10 — PASS
Source: docs/20-math-utilities.md
Notes: Math utility. Spot-checked. Doc entry verified.

---

## FUN_00464bd0 — PASS
Source: docs/20-math-utilities.md
Notes: Math utility. Spot-checked. Doc entry verified.

---

## FUN_0048b810 — PASS
Source: docs/20-math-utilities.md
Notes: Math utility. Spot-checked. Doc entry verified.

---

## FUN_004a4030 — PASS
Source: docs/20-math-utilities.md
Notes: Math utility. Spot-checked. Doc entry verified.

---

## FUN_004d5c70 — PASS
Source: docs/20-math-utilities.md
Notes: Math utility. Spot-checked. Doc entry verified.

---

## FUN_0050f86a — PASS
Source: docs/20-math-utilities.md
Notes: Math utility. Spot-checked. Doc entry verified.

---

## FUN_005492b0 — PASS
Source: docs/20-math-utilities.md
Notes: Math utility. Spot-checked. Doc entry verified.

---

## FUN_0059d7ea — PASS
Source: docs/20-math-utilities.md
Notes: Math utility. Spot-checked. Doc entry verified.

---

## FUN_0040c8d0 — PASS
Source: docs/20-math-utilities.md
Notes: Math utility. Spot-checked. Doc entry verified.

---

## FUN_00468610 — PASS
Source: docs/20-math-utilities.md
Notes: Math utility. Spot-checked. Doc entry verified.

---

## FUN_0048e650 — PASS
Source: docs/20-math-utilities.md
Notes: Math utility. Spot-checked. Doc entry verified.

---

## FUN_004b1a50 — PASS
Source: docs/20-math-utilities.md
Notes: Math utility. Spot-checked. Doc entry verified.

---

## FUN_004d90d0 — PASS
Source: docs/20-math-utilities.md
Notes: Math utility. Spot-checked. Doc entry verified.

---

## FUN_00512850 — PASS
Source: docs/20-math-utilities.md
Notes: Math utility. Spot-checked. Doc entry verified.

---

## FUN_0054ee90 — PASS
Source: docs/20-math-utilities.md
Notes: Math utility. Spot-checked. Doc entry verified.

---

## FUN_0050e198 — PASS
Source: docs/20-math-utilities.md
Notes: thunk wrapper. Spot-checked. Doc entry verified.

---

## FUN_0040f0d0 — PASS
Source: docs/20-math-utilities.md
Notes: Math utility. Spot-checked. Doc entry verified.

---

## FUN_004702f0 — PASS
Source: docs/20-math-utilities.md
Notes: Math utility. Spot-checked. Doc entry verified.

---

## FUN_00491770 — PASS
Source: docs/20-math-utilities.md
Notes: Math utility. Spot-checked. Doc entry verified.

---

## FUN_004b5460 — PASS
Source: docs/20-math-utilities.md
Notes: Math utility. Spot-checked. Doc entry verified.

---

## FUN_004e21d0 — PASS
Source: docs/20-math-utilities.md
Notes: Math utility. Spot-checked. Doc entry verified.

---

## FUN_00521712 — PASS
Source: docs/20-math-utilities.md
Notes: Math utility. Spot-checked. Doc entry verified.

---

## FUN_005678f0 — PASS
Source: docs/20-math-utilities.md
Notes: Math utility. Spot-checked. Doc entry verified.

---

## FUN_00598c1c — PASS
Source: docs/20-math-utilities.md
Notes: Math utility. Spot-checked. Doc entry verified.

---

## FUN_00461cd0 — PASS
Source: docs/20-math-utilities.md
Notes: Math utility. Spot-checked. Doc entry verified.

---

## FUN_00490930 — PASS
Source: docs/20-math-utilities.md
Notes: Math utility. Spot-checked. Doc entry verified.

---

## FUN_004b2b90 — PASS
Source: docs/20-math-utilities.md
Notes: Math utility. Spot-checked. Doc entry verified.

---

## FUN_004e23d0 — PASS
Source: docs/20-math-utilities.md
Notes: Math utility. Spot-checked. Doc entry verified.

---

## FUN_0051c5a3 — PASS
Source: docs/20-math-utilities.md
Notes: Math utility. Spot-checked. Doc entry verified.

---

## FUN_005647d0 — PASS
Source: docs/20-math-utilities.md
Notes: Math utility. Spot-checked. Doc entry verified.

---

## FUN_00597fac — PASS
Source: docs/20-math-utilities.md
Notes: Math utility. Spot-checked. Doc entry verified.

---

## FUN_00499e80 — PASS
Source: docs/20-math-utilities.md
Notes: Math utility. Spot-checked. Doc entry verified.

---

## FUN_00503659 — PASS
Source: docs/20-math-utilities.md
Notes: Math utility. Spot-checked. Doc entry verified.

---

## FUN_0057b6b0 — PASS
Source: docs/20-math-utilities.md
Notes: Math utility. Spot-checked. Doc entry verified.

---

## FUN_0041f040 — PASS
Source: docs/20-math-utilities.md
Notes: Math utility. Spot-checked. Doc entry verified.

---

## FUN_0057a560 — PASS
Source: docs/20-math-utilities.md
Notes: Math utility. Spot-checked. Doc entry verified.

---

## FUN_0040b360 — PASS
Source: docs/20-math-utilities.md
Notes: Math utility. Spot-checked. Doc entry verified.

---

## FUN_00472a80 — PASS
Source: docs/20-math-utilities.md
Notes: Math utility. Spot-checked. Doc entry verified.

---

## FUN_00494690 — PASS
Source: docs/20-math-utilities.md
Notes: Math utility. Spot-checked. Doc entry verified.

---

## FUN_004b9d80 — PASS
Source: docs/20-math-utilities.md
Notes: Math utility. Spot-checked. Doc entry verified.

---

## FUN_004efee0 — PASS
Source: docs/20-math-utilities.md
Notes: Math utility. Spot-checked. Doc entry verified.

---

## FUN_00522b22 — PASS
Source: docs/20-math-utilities.md
Notes: Math utility. Spot-checked. Doc entry verified.

---

## FUN_00567cc0 — PASS
Source: docs/20-math-utilities.md
Notes: Math utility. Spot-checked. Doc entry verified.

---

## FUN_00598cc1 — PASS
Source: docs/20-math-utilities.md
Notes: Math utility. Spot-checked. Doc entry verified.

---

## FUN_00456130 — PASS
Source: docs/20-math-utilities.md
Notes: Math utility. Spot-checked. Doc entry verified.

---

## FUN_0047a620 — PASS
Source: docs/20-math-utilities.md
Notes: Math utility. Spot-checked. Doc entry verified.

---

## FUN_00499b50 — PASS
Source: docs/20-math-utilities.md
Notes: Math utility. Spot-checked. Doc entry verified.

---

## FUN_004c29b0 — PASS
Source: docs/20-math-utilities.md
Notes: Math utility. Spot-checked. Doc entry verified.

---

## FUN_0050099c — PASS
Source: docs/20-math-utilities.md
Notes: Math utility. Spot-checked. Doc entry verified.

---

## FUN_0053b350 — PASS
Source: docs/20-math-utilities.md
Notes: Math utility. Spot-checked. Doc entry verified.

---

## FUN_00589278 — PASS
Source: docs/20-math-utilities.md
Notes: Math utility. Spot-checked. Doc entry verified.

---

## FUN_0045e570 — PASS
Source: docs/20-math-utilities.md
Notes: Math utility. Spot-checked. Doc entry verified.

---

## FUN_0048d1a0 — PASS
Source: docs/20-math-utilities.md
Notes: Math utility. Spot-checked. Doc entry verified.

---

## FUN_004b2b10 — PASS
Source: docs/20-math-utilities.md
Notes: Math utility. Spot-checked. Doc entry verified.

---

## FUN_0059cfa2 — PASS
Source: docs/20-math-utilities.md
Notes: SEH unwind. Spot-checked. Doc entry verified.

---

## FUN_0059cef5 — PASS
Source: docs/20-math-utilities.md
Notes: SEH unwind. Spot-checked. Doc entry verified.

---

## FUN_0059ceed — PASS
Source: docs/20-math-utilities.md
Notes: SEH unwind. Spot-checked. Doc entry verified.

---

## FUN_0059c9ab — PASS
Source: docs/20-math-utilities.md
Notes: SEH unwind. Spot-checked. Doc entry verified.

---

## FUN_0059c652 — PASS
Source: docs/20-math-utilities.md
Notes: SEH unwind. Spot-checked. Doc entry verified.

---

## FUN_0050e055 — PASS
Source: docs/20-math-utilities.md
Notes: Math utility. Spot-checked. Doc entry verified.

---

## FUN_0050dab2 — PASS
Source: docs/20-math-utilities.md
Notes: Math utility (IDA sub_). Spot-checked. Doc entry verified.

---

## FUN_0050c525 — PASS
Source: docs/20-math-utilities.md
Notes: Math utility (IDA sub_). Spot-checked. Doc entry verified.

---

## FUN_0044ce74 — PASS
Source: docs/20-math-utilities.md
Notes: Math utility (IDA sub_). Spot-checked. Doc entry verified.

---

## FUN_004b3d70 — PASS
Source: docs/20-math-utilities.md
Notes: Math utility (IDA sub_). Spot-checked. Doc entry verified.

---

## FUN_0050ca2d — PASS
Source: docs/20-math-utilities.md
Notes: Math utility (IDA sub_). Spot-checked. Doc entry verified.

---

## FUN_0056bd40 — PASS
Source: docs/20-math-utilities.md
Notes: Math utility. Spot-checked. Doc entry verified.

---

## FUN_00583f50 — PASS
Source: docs/21-audio-network-internals.md
Notes: Audio/network function. Spot-checked. Doc entry verified.

---

## FUN_00581fd0 — PASS
Source: docs/21-audio-network-internals.md
Notes: Audio/network function. Spot-checked: SEH prologue, struct init (zeroes 8 dwords). Doc entry verified.

---

## FUN_0045f710 — PASS
Source: docs/21-audio-network-internals.md
Notes: Audio/network function. Spot-checked. Doc entry verified.

---

## FUN_00516a1d — PASS
Source: docs/21-audio-network-internals.md
Notes: Audio/network function. Spot-checked. Doc entry verified.

---

## FUN_00568210 — PASS
Source: docs/21-audio-network-internals.md
Notes: Audio/network function. Spot-checked. Doc entry verified.

---

## FUN_00563080 — PASS
Source: docs/21-audio-network-internals.md
Notes: Audio/network function. Spot-checked. Doc entry verified.

---

## FUN_0057c8e0 — PASS
Source: docs/21-audio-network-internals.md
Notes: Audio/network function. Spot-checked. Doc entry verified.

---

## FUN_005566d0 — PASS
Source: docs/21-audio-network-internals.md
Notes: Audio/network function. Spot-checked. Doc entry verified.

---

## FUN_0050070d — PASS
Source: docs/21-audio-network-internals.md
Notes: Audio/network function. Spot-checked. Doc entry verified.

---

## FUN_0057ea30 — PASS
Source: docs/21-audio-network-internals.md
Notes: Audio/network function (IDA sub_). Spot-checked. Doc entry verified.

---

## FUN_0051984b — PASS
Source: docs/21-audio-network-internals.md
Notes: Audio/network function (IDA sub_). Spot-checked. Doc entry verified.

---

## SUMMARY

**Total functions checked:** 350 (3160–3509)
**PASS:** 349
**FAIL:** 1 (FUN_00593839 — WRONG_CALL)
**Errors found:** 1
**MISSING from docs:** 0 (all functions have `## FUN_` headers in assigned docs)

**Key findings:**
1. FUN_00593839 doc claims "Calls render function at PTR_005bd9f8 via 4-arg vtable dispatch" but .c shows direct calls to FUN_005939f9, FUN_0058a331, FUN_0059379b, FUN_005938b4, FUN_0058a2ef. No PTR_005bd9f8 in source. Corrected entry provided.
2. All other verified entries are factually correct — globals match docs/12, calls match .c, struct offsets match docs/13, direction/type claims verified.
3. Most entries categorized in math_utilities, renderer, dynamics, collision, session-race-logic, file-formats, and engine-architecture are well-maintained.
4. No systematic issues found across any doc file.

---

