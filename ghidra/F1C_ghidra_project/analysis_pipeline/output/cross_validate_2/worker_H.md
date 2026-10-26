# WORKER H — Cross-Validation Round 2 Results

Items 2458–2808 (351 functions)

---

## FUN_00439210 — PASS
docs/10-vehicle-physics.md + docs/00-source-tree.md — all claims verified against .c source.
- Inertia tensor, mass distribution, wheel positions, ARB, toe-in, chassis forces, constraint solver all confirmed
- All 21 Call targets verified in .c
- All globals (DAT_007ce958, DAT_007c569c, _DAT_0059e880, _DAT_0059ea58, _DAT_0059e420) verified
- All struct offsets (+0x1f00, +0x1d4, +0x15f0, +0x141c, +0x3ec, etc.) verified

## FUN_004D75D0 — PASS
docs/00-source-tree.md + docs/04-tire-system.md + docs/10-vehicle-physics.md — all claims verified.
- Curve name lookup, stride 0x18, param_2 name search, DAT_005ea438 fallback
- Calls: FUN_00588410, FUN_004d7a50, FUN_004d7aa0 all confirmed
- Error string "Tire brand doesn't have curve name %s" confirmed

## FUN_00455BF0 — PASS
docs/01-engine-architecture.md — all claims verified.
- HWInput::Enter() confirmed from hwinput.cpp assert string
- ShowCursor(0) loop, FUN_0044f4e0, FUN_00455290, conditional FUN_004f8ae0 all confirmed
- DAT_007d13a0 flag check confirmed

## FUN_004049D0 — PASS
docs/01-engine-architecture.md — all claims verified.
- Guard: +0x14 != 0 AND +0x20 == 1 confirmed
- Restores DAT_007d2e44/DAT_007d0410 from backups confirmed
- Clamping, DAT_005ea53e=0, FUN_00408450(0.1f) all confirmed
- FUN_004c8630 conditional confirmed

## FUN_004C6810 — FAIL
docs/01-engine-architecture.md

**Errors:**
- [WRONG_NAME] "Float Comparator" — actually linked-list merge sort
- [WRONG_TYPE] claimed float comparison, actual struct pointer comparison
- [WRONG_CALL] missing recursive self-calls FUN_004c6810(self)
- [WRONG_TARGET] routing target wrong (not audio/network)

**Corrected entry:**
<!-- target: docs/09-track-system.md -->
## FUN_004c6810 — Recursive Linked List Merge Sort (Scene Filter Comparator)

Source: Unknown. Sorts singly-linked list by scene entry priority using recursive merge sort with FUN_004c5d30 as comparator.

**Key logic:**
- Walks list to count nodes (linked via offset +4 as next pointer)
- Splits at midpoint (count/2 - 1) by breaking the link
- Recursively sorts left half via tail call
- Recursively sorts right half via tail call
- Merges sorted halves using FUN_004c5d30 as comparator
- Returns sorted list head

**Struct (linked list node):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0x00 | ObjectPtr | Pointer to scene entry object (passed to comparator) |
| +0x04 | NextPtr | Next node pointer, NULL = end |

**Calls:** FUN_004c6810 (self, recursive), FUN_004c5d30 (scene sort comparator)

**Moddability:** hardcoded

## FUN_0059964A — PASS
docs/01-engine-architecture.md — all claims verified.
- Calls FUN_0058a5d8 (stack probe/SEH init)
- Bucket allocation: (size | 0x1f) + 2 = bucket rounding + 2 bytes
- operator_new allocation, overflow guard confirmed
- Minor: size formula description slightly imprecise (says "next multiple of 32 + 2" vs actual "(size|0x1f)+2")

## FUN_005865C0 — PASS
docs/01-engine-architecture.md — all claims verified.
- CreateMutex with SECURITY_ATTRIBUTES confirmed
- CloseHandle existing, CreateMutexA, +0x1c handle store, +0x24 flag all confirmed
- Struct offsets +0x1c (MutexHandle), +0x24 (MutexActive) verified

## FUN_00551830 — PASS
docs/01-engine-architecture.md — all claims verified.
- Linked list walk via +0x24 next pointer, head from +0x13c
- Wide-character (2-byte) string comparison confirmed
- Returns matching node or 0

## FUN_0059AFFF — PASS
docs/01-engine-architecture.md — all claims verified.
- Thin C++ exception throw wrapper
- Calls FUN_0059b038 (object init) and __CxxThrowException_8
- NORETURN confirmed

## FUN_00585CD0 — PASS
docs/01-engine-architecture.md — all claims verified.
- Thread-safe write with mutex confirmed
- +0x5b8 (MutexHandle), +0x5bc (Timeout), +0x5b4 (WriteTarget) verified
- WaitForSingleObject + ReleaseMutex pattern confirmed

## FUN_00466D60 — PASS
docs/01-engine-architecture.md — all claims verified.
- Calls FUN_0048c070(param_2) confirmed
- Zeros fields param_1[199], [0xcb], [0xcc], [0xca], [0xc9]
- Sets vtable PTR_FUN_0059f438 confirmed

## FUN_004DD000 — PASS
docs/01-engine-architecture.md — all claims verified.
- Two-call sequence: FUN_004dcd10() + FUN_004dcf80()
- Init sequence wrapper confirmed

## FUN_0058B903 — PASS
docs/01-engine-architecture.md — all claims verified.
- Semaphore guard: FUN_0058dfea(0xc) acquire, FUN_0058e04b(0xc) release
- Calls FUN_0058b92a(query) between

## FUN_00558E10 — PASS
docs/01-engine-architecture.md — guard +0x4c==1 & +0x20<0, address computation param_2*0x80+4, writes at offsets 0/4/8/0x18

## FUN_00587C03 — PASS
docs/01-engine-architecture.md — operator_new wrapper, calls __nh_malloc(param_1, 1)

## FUN_00548EB0 — PASS
docs/01-engine-architecture.md — 5-list cleanup, first 4 via FUN_004b0170+FUN_00587bcf, 5th via FUN_00549110

## FUN_0059A336 — PASS
docs/01-engine-architecture.md — calls FUN_00599be5(), conditional FUN_00587bcf, returns param_1

## FUN_00593C24 — PASS
docs/01-engine-architecture.md — address arithmetic only, no calls, offset computation verified

## FUN_0046FE50 — PASS
docs/01-engine-architecture.md — calls FUN_0048fec0+FUN_00490160(1), DAT_007cd8c0 vtable check, FUN_00477280

## FUN_00495060 — PASS
docs/01-engine-architecture.md — if DAT_007cde1c != 0: calls FUN_00554d70, single globals check

## FUN_004F9240 — PASS
docs/01-engine-architecture.md — iterates DAT_008afe6c tables, 4-value comparison, returns index/-1

## FUN_0057AA20 — PASS
docs/01-engine-architecture.md — registers LAB_0057aa30 via FUN_00587b3e

## FUN_00599822 — PASS
docs/01-engine-architecture.md — calls FUN_00599e66(0)

## FUN_00586D00 — FAIL
docs/01-engine-architecture.md
**Errors:** [WRONG_CONST] — field labels for +0/+2 swapped. Doc says "+0=range length, +2=range start bit index" — actual reversed.

## FUN_0059988B — PASS
docs/01-engine-architecture.md — calls FUN_00587b3e(&LAB_00599897)

## FUN_00551390 — PASS
docs/01-engine-architecture.md — max index clamp, type byte check, 3-dword copy, flag set verified

## FUN_005998CF — PASS
docs/01-engine-architecture.md — calls FUN_00587b3e(&LAB_005998db)

## FUN_00585220 — PASS
docs/01-engine-architecture.md — status query via vtable+0xa4, threshold check at +0x60, return logic verified

## FUN_0057A8B0 — PASS
docs/01-engine-architecture.md — vtable dispatch at *param_1+0x7c

## FUN_00585810 — PASS
docs/01-engine-architecture.md — WaitForSingleObject+FUN_00587210+ReleaseMutex, +0x640/+0x644 offsets

## FUN_0059A473 — PASS
docs/01-engine-architecture.md — flag set at +0x48, conditional cleanup, DAT_008d5a60 globals

## FUN_0057A200 — PASS
docs/01-engine-architecture.md — buffer copy at +0x2d, dword+byte copy, size at +0x2c

## FUN_0059C91E — PASS
docs/01-engine-architecture.md — calls FUN_00581ad0() SEH unwind

## FUN_00472720 — PASS
docs/01-engine-architecture.md — strlen>27 truncation at space, FUN_00486f30 with path

## FUN_004BA950 — PASS
docs/01-engine-architecture.md — conditional allocation (param_2?0x18:0)+8*0x1b0 bytes

## FUN_0054C0B0 — PASS
docs/01-engine-architecture.md — bit flag reader at +0x3c, bits 1 and 2

## FUN_00587070 — PASS
docs/01-engine-architecture.md — calls FUN_005870d0 then conditional free

## FUN_00586500 — PASS
docs/01-engine-architecture.md — CloseHandle+CreateMutexA, +0x04/+0x0c offsets

## FUN_0059C6CA — PASS
docs/01-engine-architecture.md — reads pointer from EBP+8, calls FUN_00587bcf

## FUN_0059AE24 — PASS
docs/01-engine-architecture.md — SEH prolog, vtable set, FUN_005993af(1), exception destructor

## FUN_0059C980 — PASS
docs/01-engine-architecture.md — calls FUN_00581880 (linked list destruction)

## FUN_0059CCC8 — PASS
docs/01-engine-architecture.md — calls FUN_00581880 (linked list destruction)

## FUN_0042C130 — PASS
docs/01-engine-architecture.md — DynMan::Enter() trace, delegates to FUN_0042bd60

## FUN_004062B0 — PASS
docs/01-engine-architecture.md — mode 0/1 dispatch, DAT_005ea438 sentinel, string compare, sort callback

## FUN_00477440 — FAIL
docs/01-engine-architecture.md
**Errors:** [WRONG_CONST] — flag offset is +0x0C (not +8) in IDA Hex-Rays source

## FUN_0052E6E7 — PASS
docs/01-engine-architecture.md — vtable set, dword_8B0118

## FUN_0049A102 — PASS
docs/01-engine-architecture.md — field read at offset 100, store through pointer

## FUN_00404EE8 — PASS
docs/01-engine-architecture.md — byte accumulator at +94

## FUN_0059CA3B — PASS
docs/01-engine-architecture.md — __CxxFrameHandler trampoline

## FUN_0059CA8B — PASS
docs/01-engine-architecture.md — __CxxFrameHandler trampoline

## FUN_0050AF57 — PASS
docs/01-engine-architecture.md — buffer offset reads, 16-byte block copy, conditional post-process

## FUN_004A7000 — PASS
docs/01-engine-architecture.md — calls FUN_004A8B80(&DAT_007CE498)

## FUN_0049E8E8 — PASS
docs/01-engine-architecture.md — returns MEMORY[0x5E000A4C] as char

## FUN_004A0DE8 — PASS
docs/01-engine-architecture.md — sets byte_7CE25E = 1

## FUN_004122C0 — PASS
docs/02-ai-system.md — target struct resolve, vehicle array stride 0x424, 8 string offsets

## FUN_00424E70 — PASS
docs/02-ai-system.md — behavior state machine at +0x1144 (states 0-7), race phase transition, all 15 calls verified

## FUN_004BF0A0 — PASS
docs/02-ai-system.md — EngineWearMode gate, 0x68-float zeroing, per-vehicle gap computation, FUN_004bf390 sort

## FUN_004A5D10 — PASS
docs/02-ai-system.md — mode compare at +0x61, game mode dispatch, all 9 calls verified

## FUN_004D7660 — PASS
docs/04-tire-system.md — *.tbc scan from DAT_005ec3d8/DAT_005ec428, loads via FUN_004d7150

## FUN_004B9FD0 — FAIL
docs/06-session-race-logic.md — **Errors:** [MISSING_ENTRY] — no ## FUN_ entry in docs/06 or any doc

## FUN_0046A560 — FAIL
docs/06-session-race-logic.md — **Errors:** [MISSING_ENTRY] — no ## FUN_ entry (career stats HTML writer)

## FUN_004A0030 — FAIL
docs/06-session-race-logic.md — **Errors:** [MISSING_ENTRY] — no ## FUN_ entry (switch on RaceMode)

## FUN_0041B190 — FAIL
docs/06-session-race-logic.md — **Errors:** [MISSING_ENTRY] — team ID compare, audio play

## FUN_0049E670 — FAIL
docs/06-session-race-logic.md — **Errors:** [MISSING_ENTRY] — DriverNumber compare, color call

## FUN_004BFFA4 — FAIL
docs/06-session-race-logic.md — **Errors:** [MISSING_ENTRY] — driver sorting, grid position setup

## FUN_004D24A0 — FAIL
docs/06-session-race-logic.md — **Errors:** [MISSING_ENTRY] — VehiclePtrArray +0x4064 check

## FUN_00461900 — PASS
docs/06-session-race-logic.md — bitfield to globals, pit open/close timers, all 8 calls verified

## FUN_00477280 — FAIL
docs/06-session-race-logic.md
**Errors:** [WRONG_RETURN] — doc says "returns comparison result" but function is void
[OMITS_LOGIC] — omits entire child-list creation/linking code (lines 43-75)

## FUN_00594C12 — PASS
docs/06-session-race-logic.md — custom heap allocator, VirtualAlloc, free list sentinels 0xff/0xf0/0xf1

## FUN_00589BC6 — PASS (partial)
docs/06-session-race-logic.md — hex-digit test via lookup table bit 0x80, minimal entry, no contradictions

## FUN_0059BCFC — PASS
docs/06-session-race-logic.md — bitmap allocator, sentinel checks, flag bits 0x80/0x40/0x2/0x1

## FUN_0058C5AC — FAIL
docs/06-session-race-logic.md
**Errors:** [SIZE_MISMATCH] — doc says 62 bytes, actual 200 bytes
[PURPOSE_INCOMPLETE] — not just semaphore P, also allocates + critical section init

## FUN_005901F0 — FAIL
docs/06-session-race-logic.md
**Errors:** [PURPOSE_MISMATCH] — triage says "stub/no-op" but function does locale detection with EnumSystemLocalesA

## FUN_00466650 — PASS
docs/06-session-race-logic.md — elapsed time query, 3.0f clamp, interpolation mode switch, all 9 globals and 5 calls verified

## FUN_00509047 — PASS
docs/06-session-race-logic.md — dither pixel quantizer, 4-channel 10-bit, DAT_005accb4 scale

## FUN_005081AE — FAIL
docs/06-session-race-logic.md — **Errors:** [MISSING_ENTRY] — triage only (12 lines)

## FUN_00509A09 — FAIL
docs/06-session-race-logic.md — **Errors:** [MISSING_ENTRY] — triage only (14 lines)

## FUN_0054BF60 — FAIL
docs/06-session-race-logic.md — **Errors:** [MISSING_ENTRY] — triage only (20 lines)

## FUN_0051E7D7 — FAIL
docs/06-session-race-logic.md — **Errors:** [MISSING_ENTRY] — triage only (41 lines)

## FUN_004B9CC0 — FAIL
docs/06-session-race-logic.md — **Errors:** [MISSING_ENTRY] — triage only

## FUN_004ED1F0 — FAIL
docs/06-session-race-logic.md — **Errors:** [MISSING_ENTRY] — triage only

## FUN_004A0BA0 — FAIL
docs/06-session-race-logic.md — **Errors:** [MISSING_ENTRY] — triage only

## FUN_0054F7A0 — FAIL
docs/06-session-race-logic.md — **Errors:** [MISSING_ENTRY] — triage only

## FUN_004E0C90 — FAIL
docs/06-session-race-logic.md — **Errors:** [MISSING_ENTRY] — triage only

## FUN_00542560 — PASS
docs/06-session-race-logic.md — store at +0x19c, call FUN_00542200 with 5 floats

## FUN_004F1B50 — FAIL
docs/06-session-race-logic.md — **Errors:** [MISSING_ENTRY] — triage only

## FUN_004F6880 — FAIL
docs/06-session-race-logic.md — **Errors:** [MISSING_ENTRY] — triage only, referenced in docs/30 as TireForceQuadraticModel

## FUN_00512334 — PASS
docs/06-session-race-logic.md — if +0x117<8: set bit 2 at +0x60, set +0x118=8

## FUN_004F1B10 — FAIL
docs/06-session-race-logic.md — **Errors:** [MISSING_ENTRY] — triage only

## FUN_004FF040 — FAIL
docs/06-session-race-logic.md — **Errors:** [MISSING_ENTRY] — triage only

## FUN_0050AEAE — FAIL
docs/06-session-race-logic.md — **Errors:** [MISSING_ENTRY] — triage only

## FUN_0050B27C — FAIL
docs/06-session-race-logic.md — **Errors:** [MISSING_ENTRY] — present in docs/24 only as DXT FourCC checker

## FUN_0050A067 — FAIL
docs/06-session-race-logic.md — **Errors:** [MISSING_ENTRY] — triage only

## FUN_004B0E30 — FAIL
docs/06-session-race-logic.md — **Errors:** [MISSING_ENTRY] — triage only

## FUN_0051BA70 — FAIL
docs/06-session-race-logic.md — **Errors:** [MISSING_ENTRY] — triage only

## FUN_005459D0 — FAIL
docs/06-session-race-logic.md — **Errors:** [MISSING_ENTRY] — triage only

## FUN_004E2C70 — FAIL
docs/06-session-race-logic.md — **Errors:** [MISSING_ENTRY] — triage only

## FUN_004ED250 — FAIL
docs/06-session-race-logic.md — **Errors:** [MISSING_ENTRY] — triage only

## FUN_004E24A0 — FAIL
docs/06-session-race-logic.md — **Errors:** [MISSING_ENTRY] — triage only

## FUN_0046A480 — FAIL
docs/06-session-race-logic.md — **Errors:** [MISSING_ENTRY] — triage only

## FUN_0048FE90 — FAIL
docs/06-session-race-logic.md — **Errors:** [MISSING_ENTRY] — triage only

## FUN_00545F50 — FAIL
docs/06-session-race-logic.md — **Errors:** [MISSING_ENTRY] — triage only

## FUN_0047DD10 — PASS
docs/06-session-race-logic.md — HTML builder, 7 field labels, Nationality copy, DAT_007cd8c0 vtable dispatch

## FUN_004A58B0 — FAIL
docs/07-pit-system.md — **Errors:** [MISSING_ENTRY] — NOT found in docs/07. Formats pit status strings "Repair"/"Do Not Repair"/%d(+%d)/%d(-%d)

## FUN_004C18B0 — FAIL
docs/08-file-formats.md — **Errors:** [MISSING_ENTRY] — NOT found in docs/08. Career stats reader, keys: CAREERSEASON/TOTALLAPS/TOTALRACES/BestLapTime

## FUN_004C2700 — FAIL
docs/08-file-formats.md — **Errors:** [MISSING_ENTRY] — NOT found. 26 bytes, opens [CAREER] section

## FUN_0047F440 — FAIL
docs/08-file-formats.md — **Errors:** [MISSING_ENTRY] — NOT found. Scene object factory, types 0x00-0x2b, "F1_2002.gdb" string

## FUN_004C54F0 — FAIL
docs/08-file-formats.md — **Errors:** [MISSING_ENTRY] — NOT found in docs/08. Builds .AIW/.SCN filenames

## FUN_00407F10 — FAIL
docs/08-file-formats.md — **Errors:** [MISSING_ENTRY] — NOT found. String comparison + linked list traversal

## FUN_004331A0 — FAIL
docs/08-file-formats.md — **Errors:** [MISSING_ENTRY] — NOT found. Two linked list cleanup

## FUN_004B8010 — FAIL
docs/08-file-formats.md — **Errors:** [MISSING_ENTRY] — NOT found. File format detection, 0x180-byte buffer

## FUN_004F7440 — FAIL
docs/08-file-formats.md — **Errors:** [MISSING_ENTRY] — NOT found. 15 bytes, init +8/+0xc to 0xffffffff

## FUN_00469630 — PASS
docs/08-file-formats.md — linked list name get, extension strip, compare with DAT_007d0434, UI update

## FUN_00594478 — PASS
docs/08-file-formats.md — custom heap arena, 0x41c4 struct + 0x100000 VirtualAlloc

## FUN_00598815 — PASS
docs/08-file-formats.md — SEH prolog, DAT_005e9ef4 counter, vtable init

## FUN_0045BC50 — FAIL
docs/08-file-formats.md — **Errors:** [MISSING_ENTRY] — NOT found. String concat, _strncpy

## FUN_00599081 — PASS
docs/08-file-formats.md — buffered stream read, +0x1c buffer ptr, +0x2c buffer end, vtable fallback

## FUN_0058801D — FAIL
docs/08-file-formats.md — **Errors:** [MISSING_ENTRY] — NOT found. 20 bytes, flag bitwise check

## FUN_004B9D00 — FAIL
docs/08-file-formats.md — **Errors:** [MISSING_ENTRY] — NOT found. 15 bytes, audio volume fade

## FUN_0059CFB0 — FAIL
docs/08-file-formats.md — **Errors:** [MISSING_ENTRY] — NOT found. 12 bytes, thunk to FUN_00585fb0

## FUN_00536A70 — FAIL
docs/08-file-formats.md — **Errors:** [MISSING_ENTRY] — NOT found. zlib inflate core, Huffman trees

## FUN_0049CA00 — FAIL
docs/09-track-system.md — **Errors:** [MISSING_ENTRY] — NOT found in docs/09. Cockpit HUD init, LED bitmaps, fonts

## FUN_0045FC50 — FAIL
docs/09-track-system.md — **Errors:** [MISSING_ENTRY] — NOT found in docs/09. NetComm player slot sync, NetComm.cpp

## FUN_00460380 — PASS
docs/09-track-system.md — client grid display timer, 0x3fc4==3 check, scene load + grid setup

## FUN_0040AA20 — FAIL
docs/09-track-system.md — **Errors:** [MISSING_ENTRY] — NOT found. Camera transform init, 4 transforms at 360.0f

## FUN_0040C240 — FAIL
docs/09-track-system.md — **Errors:** [MISSING_ENTRY] — NOT found. Track path resolver, scene index globals

## FUN_0043DA10 — FAIL
docs/10-vehicle-physics.md — **Errors:** [MISSING_ENTRY] — NOT found. Tire setup, camber angle, slip curves

## FUN_0042F2F0 — FAIL
docs/10-vehicle-physics.md — **Errors:** [MISSING_ENTRY] — NOT found. Setup value formatter, switch modes 0-10

## FUN_004EFAE0 — FAIL
docs/10-vehicle-physics.md — **Errors:** [MISSING_ENTRY] — NOT found. Engine wear check, DAT_007cea5c

## FUN_0049E570 — FAIL
docs/10-vehicle-physics.md — **Errors:** [MISSING_ENTRY] — NOT found. Result display selector

## FUN_004780B0 — FAIL
docs/10-vehicle-physics.md — **Errors:** [MISSING_ENTRY] — NOT found. Virtual dispatch via DAT_007cd8c0+0x1c

## FUN_00435406 — PASS
docs/10-vehicle-physics.md — sets array elements 22/23/24 to same value

## FUN_004CE3E0 — FAIL
docs/17-physics-collision.md — **Errors:** [MISSING_ENTRY] — NOT found. Collision particle/trail effect

## FUN_00436870 — PASS
docs/17-physics-collision.md — collision contact generation, triangle data at +0x15c, orthonormal basis, Bezier eval, all calls verified

## FUN_0049B670 — FAIL
docs/17-physics-collision.md — **Errors:** [MISSING_ENTRY] — NOT found. Time-to-frame converter

## FUN_0044C9B0 — FAIL
docs/17-physics-collision.md — **Errors:** [MISSING_ENTRY] — NOT found. 12 bytes, thunk to FUN_00587b3e

## FUN_0044D400 — FAIL
docs/17-physics-collision.md — **Errors:** [MISSING_ENTRY] — NOT found. 19 bytes, init collision globals

## FUN_0044CAD0 — FAIL
docs/17-physics-collision.md — **Errors:** [MISSING_ENTRY] — NOT found. 12 bytes, thunk

## FUN_0044F7F0 — FAIL
docs/17-physics-collision.md — **Errors:** [MISSING_ENTRY] — NOT found. Friction velocity interpolation

## FUN_0044E480 — FAIL
docs/17-physics-collision.md — **Errors:** [MISSING_ENTRY] — NOT found. 19 bytes, init collision globals

## FUN_0044CC50 — FAIL
docs/17-physics-collision.md — **Errors:** [MISSING_ENTRY] — NOT found. 12 bytes, thunk

## FUN_0044AF60 — FAIL
docs/17-physics-collision.md — **Errors:** [MISSING_ENTRY] — NOT found. Matrix permutation 3×2

## FUN_0044E600 — FAIL
docs/17-physics-collision.md — **Errors:** [MISSING_ENTRY] — NOT found. 19 bytes, init collision globals

## FUN_0044DD30 — FAIL
docs/17-physics-collision.md — **Errors:** [MISSING_ENTRY] — NOT found. 12 bytes, thunk

## FUN_00455B30 — FAIL
docs/17-physics-collision.md — **Errors:** [MISSING_ENTRY] — NOT found. Keyboard input handler, GetKeyboardState/MapVirtualKey

## FUN_0044D280 — FAIL
docs/17-physics-collision.md — **Errors:** [MISSING_ENTRY] — NOT found. 17 bytes, init globals

## FUN_0044CBC0 — FAIL
docs/17-physics-collision.md — **Errors:** [MISSING_ENTRY] — NOT found. 17 bytes, init globals

## FUN_0044D7F0 — FAIL
docs/17-physics-collision.md — **Errors:** [MISSING_ENTRY] — NOT found. 12 bytes, thunk

## FUN_004527C0 — FAIL
docs/17-physics-collision.md — **Errors:** [MISSING_ENTRY] — NOT found. 14 bytes, conditional call

## FUN_00405E60 — FAIL
docs/17-physics-collision.md — **Errors:** [MISSING_ENTRY] — NOT found. Steering response, speed threshold

## FUN_0054F2F0 — FAIL
docs/17-physics-collision.md — **Errors:** [MISSING_ENTRY] — NOT found. Ray-triangle intersection batch

## FUN_0056D8F0 — FAIL
docs/18-physics-dynamics.md — **Errors:** [MISSING_ENTRY] — NOT found. Physics error log to pmodel_error.txt

## FUN_004CE110 — FAIL
docs/18-physics-dynamics.md — **Errors:** [MISSING_ENTRY] — NOT found. Wheel surface contact friction

## FUN_00447780 — PASS
docs/18-physics-dynamics.md — suspension force computation, 6 doubles per entry, stride 0x244, dot product, all calls verified

## FUN_00524553 — PASS
docs/18-physics-dynamics.md — SIMD quaternion arithmetic, 3DNow! packed float ops

## FUN_00448E90 — PASS (partial)
docs/17-physics-collision.md — referenced as collision pipeline init callee, accurate

## FUN_00438930 — PASS
docs/18-physics-dynamics.md — Gram-Schmidt projection, momentum onto YZ constraint plane

## FUN_004492B0 — FAIL
docs/18-physics-dynamics.md — **Errors:** [MISSING_ENTRY] — NOT found. 15 bytes, zeroes +8/+0xc/+0x10

## FUN_00447B10 — FAIL
docs/18-physics-dynamics.md — **Errors:** [MISSING_ENTRY] — NOT found. Temperature damage interpolation

## FUN_00441450 — PASS
docs/18-physics-dynamics.md — PhysicsSubObjectFree, FUN_004389b0 on multiple offsets

## FUN_0043BB80 — FAIL
docs/18-physics-dynamics.md — **Errors:** [MISSING_ENTRY] — NOT found. Quadratic aerodynamic force computation

## FUN_004BB5A0 — FAIL
docs/18-physics-dynamics.md — **Errors:** [MISSING_ENTRY] — NOT found. Linked list data free

## FUN_004A3820 — FAIL
docs/18-physics-dynamics.md — **Errors:** [MISSING_ENTRY] — NOT found. Audio/display channel processing

## FUN_004A2800 — FAIL
docs/18-physics-dynamics.md — **Errors:** [MISSING_CALL] doesn't mention FUN_004a27d0

## FUN_0059983B — PASS
docs/18-physics-dynamics.md — calls sub_599E71(&DAT_008D44B8), matches

## FUN_00598727 — PASS
docs/18-physics-dynamics.md — sub_598731 wrapper, matches

## FUN_004D68A0 — PASS
docs/18-physics-dynamics.md — physics struct init with sentinel values, matches

## FUN_00411840 — PASS
docs/19-renderer.md — font rendering prep, all globals and calls verified

## FUN_00486280 — PASS
docs/19-renderer.md — UI string accessor at +200→+0x28, matches

## FUN_00489AB0 — FAIL
docs/19-renderer.md — **Errors:** [MISSING_CALL] missing FUN_00489d00, FUN_00489e90; [OMITS_LOGIC] linked list walk at +0x24 + vtable dispatch

## FUN_00495580 — FAIL
docs/19-renderer.md — **Errors:** [INCOMPLETE] doc is ~3 lines, source is 527 bytes with 6+ unlisted calls

## FUN_0049A2B0 — PASS
docs/19-renderer.md — string pointer dereference, null→DAT_005ea438, matches

## FUN_0059B0F5 — PASS
docs/19-renderer.md — MultiByteToWideChar wrapper, matches

## FUN_00543BF0 — PASS
docs/19-renderer.md — DirectX resource cleanup, all callees verified

## FUN_00513F7A — PASS
docs/19-renderer.md — color quantization, Newton method, 6/8 palette, matches

## FUN_00502F31 — PASS
docs/19-renderer.md — D3D vertex buffer builder, matches

## FUN_00506003 — PASS
docs/19-renderer.md — D3D vertex buffer creation, COM interfaces, matches

## FUN_0054CA00 — PASS
docs/19-renderer.md — D3D vertex buffer + software T&L, struct offsets verified

## FUN_0053AEB0 — PASS
docs/19-renderer.md — vertex batch transform, dual 4x4 matrix, matches

## FUN_00556CD0 — PASS
docs/19-renderer.md — D3DMarkDirty, recursion check at +0x44/+0x4c, matches

## FUN_00553D70 — PASS
docs/19-renderer.md — draw rectangle with sorted coords, matches

## FUN_004C9A50 — PASS
docs/19-renderer.md — memory alloc / particle factory types 1-7, matches

## FUN_0057A5A0 — PASS
docs/19-renderer.md — animation timing update, matches

## FUN_0055CEE0 — PASS
docs/19-renderer.md — RGB→16-bit color compaction, 565/555 formulas verified

## FUN_00488180 — PASS
docs/19-renderer.md — UI text display constructor, calls confirmed

## FUN_0052E170 — PASS
docs/19-renderer.md — render object constructor, vtable + properties, matches

## FUN_00489560 — PASS
docs/19-renderer.md — state update with decrement, verified

## FUN_0054FC50 — PASS
docs/19-renderer.md — float-to-int multiply 0x1010101, matches

## FUN_0046C8B0 — PASS
docs/19-renderer.md — UI mouse click handler, all 4 calls confirmed

## FUN_0050C762 — PASS
docs/19-renderer.md — D3D wrapper hook, sub_50FEA7(1), matches

## FUN_004950E0 — PASS
docs/19-renderer.md — render frame wrapper, 3 calls confirmed

## FUN_00589E6C — PASS
docs/20-math-utilities.md — date/time conversion, mod 0x3c/0x18, leap years, matches

## FUN_005832E0 — PASS
docs/20-math-utilities.md — linked list node removal by key, doubly-linked, matches

## FUN_005664A0 — PASS
docs/20-math-utilities.md — recursive merge-sort on singly-linked list, overview matches

## FUN_0058E41B — NOT_FOUND — no ## entry, callee mention only

## FUN_0058F939 — NOT_FOUND — globals ref only

## FUN_00582BA0 — NOT_FOUND — SEH frame, globals only

## FUN_0055EE20 — FAIL
docs/20-math-utilities.md — **Errors:** [TRIAGE_ONLY] — no ## entry, overview "reflection vector" plausible but unverifiable

## FUN_00565400 — NOT_FOUND — triage only "unknown no"

## FUN_0056A150 — NOT_FOUND — callee mention "copy struct + 3x3 matrix×vector"

## FUN_0040B560 — NOT_FOUND — callee mention only

## FUN_004DAC30 — NOT_FOUND — triage only

## FUN_00567F10 — NOT_FOUND — callee mention only

## FUN_0040B5A0 — NOT_FOUND — globals only

## FUN_004713C0 — NOT_FOUND — no matches

## FUN_0048C9A0 — NOT_FOUND — globals only (vtable)

## FUN_004B0720 — NOT_FOUND — callee mention only

## FUN_004DC2E0 — NOT_FOUND — no matches

## FUN_0051DF18 — NOT_FOUND — callee mention only

## FUN_005681F0 — NOT_FOUND — callee mention only

## FUN_005871F0 — NOT_FOUND — callee mention only

## FUN_00421990 — NOT_FOUND — callee mention only

## FUN_004797C0 — NOT_FOUND — enum catalog only

## FUN_0049A110 — NOT_FOUND — enum catalog only

## FUN_004C7DE0 — NOT_FOUND — callee mention only

## FUN_0050D857 — NOT_FOUND — no matches (thunk)

## FUN_0054A5B0 — NOT_FOUND — no matches

## FUN_00550300 — NOT_FOUND — no matches

## FUN_0046D610 — NOT_FOUND — no matches

## FUN_004C2C00 — NOT_FOUND — callee mention

## FUN_00556260 — NOT_FOUND — callee mention

## FUN_00595F82 — NOT_FOUND — triage only

## FUN_0045B400 — NOT_FOUND — no matches

## FUN_0047C9D0 — NOT_FOUND — callee mention

## FUN_0049A180 — NOT_FOUND — callee mention

## FUN_004C4BB0 — NOT_FOUND — callee mention

## FUN_00503B94 — NOT_FOUND — enum only

## FUN_0054C2F0 — NOT_FOUND — no matches

## FUN_00598FD4 — NOT_FOUND — no matches

## FUN_00407EF0 — NOT_FOUND — callee mention

## FUN_00464A10 — NOT_FOUND — callee mention

## FUN_00499CC0 — NOT_FOUND — no matches

## FUN_004C2C20 — NOT_FOUND — callee mention

## FUN_005016E0 — NOT_FOUND — no matches

## FUN_0053B6F0 — NOT_FOUND — callee mention

## FUN_0058A32A — NOT_FOUND — overview mention only

## FUN_00408520 — NOT_FOUND — struct offsets only

## FUN_00465FF0 — NOT_FOUND — no matches

## FUN_0048CA30 — NOT_FOUND — no matches

## FUN_004A5BD0 — NOT_FOUND — callee mention

## FUN_004DB4E0 — NOT_FOUND — no matches

## FUN_0053BCE0 — PASS
docs/20-math-utilities.md — force/scale calc, reads +0x18/+0x1c/+0x20+0x44/+0x48/+0x4c, verified

## FUN_00550760 — NOT_FOUND — triage only

## FUN_00408740 — PASS (triage-only) — float switch → int offset

## FUN_00462330 — PASS (triage-only) — ID lookup in array

## FUN_00487900 — PASS (triage-only) — vtable dispatch, list walk

## FUN_004A0D90 — PASS (triage-only) — sets DAT_007ce25c=1

## FUN_004CE860 — PASS (triage-only) — string copy + search

## FUN_0050C9A9 — PASS (overview) — 4-component bilinear interpolation

## FUN_00546430 — FAIL (MINOR) — call chain says "accumulates" but function ZEROS +0x94/+0x98

## FUN_0059AF50 — PASS (triage-only) — constructor, vtable set

## FUN_00425660 — PASS (triage-only) — zeroes int at +0x4510

## FUN_004F3190 — PASS (triage-only) — TireForceChannel, quadratic polynomial

## FUN_0058BD8F — PASS (triage-only) — MSVC __fassign

## FUN_00421A70 — PASS (triage-only) — short computation

## FUN_00478350 — PASS (triage-only) — conditional update + virtual call

## FUN_004988C0 — PASS (triage-only) — sets byte at +0x18f5

## FUN_004BC270 — PASS (triage-only) — bounds-checked table lookup

## FUN_004F9420 — PASS (triage-only) — calls FUN_004f9240, stores 5 globals

## FUN_00534B00 — PASS (triage-only) — calls FUN_00534b10(0xffffffff)

## FUN_00584110 — PASS (triage-only) — accumulator at +0xe0

## FUN_00406A90 — PASS (triage-only) — returns +0x18/+0x1c values

## FUN_0054B4A0 — PASS (triage-only) — returns +0x2c/+0x30/+0x34 values

## FUN_00534D50 — PASS (triage-only) — bit/byte parsing

## FUN_004D2E20 — PASS (triage-only) — conditional free at +0xa4

## FUN_004A1F80 — PASS (triage-only) — linked list free 4 buckets

## FUN_004893C0 — PASS (triage-only) — constructor

## FUN_0046B580 — PASS (triage-only) — constructor

## FUN_0057B0D0 — PASS (triage-only) — linked list node getter by index

## FUN_004EA930 — PASS (overview) — 3-component vector subtraction

## FUN_0052DF10 — PASS (triage-only) — codec type dispatch

## FUN_00587220 — PASS (triage-only) — returns field at +0x10

## FUN_0057B530 — PASS (triage-only) — ring buffer head/tail reset

## FUN_0059D52F — PASS (triage-only) — unwind thunk

## FUN_00462410 — PASS (triage-only) — data table row at stride 0x8C

## FUN_00487E70 — PASS (triage-only) — virtual dispatch

## FUN_004A0DF0 — PASS (triage-only) — branching on FUN_00461cd0

## FUN_004CEFE0 — PASS (triage-only) — search loop stride 0x6c

## FUN_0050D4D9 — PASS (triage-only) — dispatch through PTR_FUN_005d7830

## FUN_00547040 — PASS (triage-only) — conditional audio functions

## FUN_0059C86A — PASS (triage-only) — unwind thunk

## FUN_00408220 — PASS (triage-only) — calls FUN_00587b3e

## FUN_00464C10 — PASS (triage-only) — constructor, 0x68×0x230 array

## FUN_0048B8F0 — PASS (triage-only) — stores at +0x2f8

## FUN_004A4050 — PASS (triage-only) — branches on +0x78

## FUN_004D5EA0 — PASS (triage-only) — float computation

## FUN_0050F904 — PASS (triage-only) — state machine

## FUN_005492F0 — PASS (triage-only) — linked list allocator

## FUN_0059CF94 — PASS (triage-only) — unwind thunk

## FUN_0040C910 — PASS (triage-only) — return field accessor

## FUN_0046C6F0 — PASS (triage-only) — constructor

## FUN_0048FD60 — PASS (triage-only) — constructor

## FUN_004B2B80 — PASS (overview) — bitfield extract at +0x30>>0xf&0x7f

## FUN_004DCD60 — PASS (triage-only) — conditional FUN_00553700

## FUN_00517EC8 — PASS (triage-only) — conditional FUN_0058aa6f

## FUN_0055C9C0 — PASS (triage-only) — float array setter stride 0x44

## FUN_00595207 — FAIL (MINOR) — overview says "96-bit bitmap" but source is arbitrary-size bit array

## FUN_0045C750 — PASS (triage-only) — calls FUN_0045c8b0(1)

## FUN_0048E6A0 — PASS (triage-only) — calls FUN_004966e0

## FUN_004B1A90 — PASS (triage-only) — constructor

## FUN_004DBF90 — PASS (triage-only) — render/display

## FUN_00516853 — PASS (triage-only) — loop + free

## FUN_00559350 — PASS (triage-only) — string copy

## FUN_00591E66 — PASS (overview) — FPU control word query

## FUN_00498DF0 — PASS (triage-only) — zero-init 22 fields

## FUN_004F8D10 — PASS (triage-only) — calls FUN_004f8d40

## FUN_00567A30 — PASS (triage-only) — linked list destructor

## FUN_00411680 — PASS (triage-only) — loop 0x219 times, {1,0} pairs

## FUN_00540240 — PASS (triage-only) — return 0

## FUN_00407810 — PASS (triage-only) — linked list insert

## FUN_0046EFE0 — PASS (triage-only) — conditional FUN_0046f170

## FUN_00490B00 — PASS (triage-only) — array allocator

## FUN_004B44A0 — PASS (triage-only) — vector math

## FUN_004DE5D0 — PASS (triage-only) — table lookup

## FUN_00517F58 — PASS (triage-only) — calls FUN_00513bd1

## FUN_0055EEAF — PASS (triage-only) — 4x3 matrix × vector transform

## FUN_005879F0 — PASS (triage-only) — writes {500,0,0,0} to offsets

## FUN_004234C0 — PASS (triage-only) — zeroes 3 fields + 1 byte

## FUN_00479730 — PASS (triage-only) — constructor

## FUN_00498E50 — PASS (triage-only) — linked list insertion

## FUN_004BD7D0 — PASS (triage-only) — constructor

## FUN_004FAD80 — FAIL (MINOR) — triage "unknown/unidentified" but is actually constructor init

## FUN_00535550 — PASS (triage-only) — calls FUN_00535390(1)

## FUN_00585E60 — PASS (triage-only) — calls FUN_00587b3e

## FUN_004263EB — PASS (triage-only) — conditional float reads

## FUN_00489440 — PASS (triage-only) — vtable set

## FUN_004B1A10 — PASS (triage-only) — constructor

## FUN_0059CD13 — PASS (triage-only) — unwind helper

## FUN_0059CB68 — PASS (triage-only) — unwind thunk

## FUN_0059CCEB — PASS (triage-only) — unwind free

## FUN_0059C83E — PASS (triage-only) — calls FUN_00581a80

## FUN_0058DC57 — PASS (triage-only) — MSVC CRT __startOneArgErrorHandling

## FUN_0050DF9B — PASS (triage-only) — quaternion inverse/normalize

## FUN_0053BE60 — PASS (triage-only) — 3D squared distance

## FUN_0052014E — PASS (triage-only) — SSE 4x4 matrix×vector

## FUN_005207CE — PASS (triage-only) — SSE 3D cross product

## FUN_00522952 — PASS (triage-only) — 3DNow! matrix construct

## FUN_00564620 — PASS (triage-only) — integer subtraction

## FUN_00502BEA — PASS (triage-only) — zeros param_1[0] and [1]

## FUN_00560FE0 — PASS (triage-only) — shadow frustum calc, fpatan

## FUN_0057BCE0 — PASS (triage-only) — SEH destructor cleanup

## FUN_004FF8F0 — PASS (triage-only) — audio cross-fade/interpolation

## FUN_0051BAD1 — FAIL (MINOR) — overview says "FIR/crossfeed" but dispatches to IMDCT filter bank

## FUN_00551CE0 — PASS (triage-only) — BinkClose wrapper

## FUN_00561F80 — PASS (triage-only) — socket cleanup + WSACleanup

## FUN_0057FBE0 — PASS (triage-only) — network thread cleanup

## FUN_004117B0 — PASS (triage-only) — audio commentary strings

## FUN_00405B50 — FAIL (MINOR) — triage "math_util" but is audio status polling (AIL_sample_status)

## FUN_0051BD61 — PASS (triage-only) — audio decode pipeline

## FUN_00581600 — PASS
docs/21-audio-network-internals.md — mutex-protected linked list search, all struct offsets and calls verified

## FUN_0052AB4E — PASS (triage-only) — packed-SIMD audio mixing

---

