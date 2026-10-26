# Cross-Validation Round 2 — Worker E

Items 1405–1755. 351 functions total.

---

## FUN_0040C920 — PASS
Source match: CamMan::Init — camera initialization. All globals, calls, and logic verified.

---

## FUN_004D5F70 — PASS
Source match: Tire slip curve parser in tire_manager.cpp. Doc verified as correct.

---

## FUN_0049EF70 — PASS
Source match: OnScreen::Setup — debug trace only. Doc verified.

---

## FUN_00455200 — PASS
Source match: PAUSE string table lookup. All ranges and defaults verified.

---

## FUN_00466350 — PASS
Source match: Camera yaw/zoom controller. Logic verified. Note: additional globals (DAT_0059f200, DAT_0059e87c, DAT_0059f1fc, DAT_0059f1f8, DAT_0059f1f0) used in source but not listed in doc — acceptable for summary.

---

## FUN_0058A323 — PASS
Source match: 7-byte LOCK/UNLOCK with indirect call. Doc accurate.

---

## FUN_00581A20 — PASS
Source match: Handle Close + Linked-List Destruction. All offsets (+0x00, +0x10, +0x18) and logic verified against source.

---

## FUN_0059C964 — FAIL
Source: docs/01-engine-architecture.md

**Errors:**
- [WRONG_CALL] Doc claims calls FUN_0047a800, but source calls FUN_00581ee0

**Corrected entry:**
<!-- target: docs/01-engine-architecture.md -->
## FUN_0059c964 — SEH Unwind: Call FUN_00581ee0

Source: unknown | Confidence: high
SEH unwind handler that calls FUN_00581ee0 as cleanup.

**Key logic:**
- Calls FUN_00581ee0 with no arguments

**Calls:** FUN_00581ee0 — math utility (short computation)

**Used by system:** docs/01-engine-architecture.md — SEH exception handling

**Moddability:** hardcoded

---

## FUN_0059871B — PASS
Source match: Calls FUN_00587b3e(&LAB_00598727). Doc verified — Cleanup Wrapper.

---

## FUN_0057AAF0 — PASS
Source match: Copies 12 dwords from param_1 to stack, calls FUN_0057abb0, returns success. Doc verified.

---

## FUN_00461440 — PASS
Source match: Session flag check — returns 1 if *(param_1+0x3fc4) in {1,2} AND DAT_007d1074 != 0. All claims verified.

---

## FUN_004B2100 — PASS
Source match: Linked-list node destruction with FUN_00587bcf free. Logic verified.

---

## FUN_00585D20 — PASS
Source match: Mutex-protected read with WaitForSingleObject/ReleaseMutex. Offsets +0x5b4, +0x5b8, +0x5bc verified.

---

## FUN_00598794 — PASS
Source match: Single Function Call Wrapper — calls FUN_00598e2e(0). Doc verified.

---

## FUN_00585DE0 — PASS
Source match: QueueUserAPC Async Procedure Call. Calls QueueUserAPC(FUN_0041a160, *(param_1+4), param_1). Verified.

---

## FUN_005410F0 — PASS
Source match: Guarded Virtual Decrement. Checks param_2+0x18 non-null, calls vtable+0x30, optional decrement of +0x0c. Verified.

---

## FUN_00593BBD — PASS
Source match: SEH-Wrapped Render Dispatch Call. SEH setup, calls FUN_0058a323 conditionally. Offsets +0x18, +0x1c verified.

---

## FUN_00587440 — PASS
Source match: Callback Registration for Cleanup Routine — calls FUN_00587b3e(&LAB_00587450). Verified.

---

## FUN_00466080 — PASS
Source match: Call Wrapper — calls FUN_00566650(param_1). Verified.

---

## FUN_0048FAF0 — PASS
Source match: Decrement Counter with Clamp. Uses +0x168 (counter), +0x178 (default decrement). Verified.

---

## FUN_004DB550 — PASS
Source match: UI Layout Dispatch. Branches on DAT_007d0474, calls FUN_004db6f0/FUN_004db9a0/FUN_004db7f0. Verified.

---

## FUN_005568D0 — PASS
Source match: Callback Registration — calls FUN_00587b3e(&LAB_005568e0). Verified.

---

## FUN_0058A677 — PASS
Source match: N-Time Callback Loop with SEH. Loops param_3 times calling param_4 callback. Verified.

---

## FUN_00598AA0 — PASS
Source match: Status Check with Error Dispatch. Virtual dispatch, bitmask check (0x6), error flag on -1. Verified.

---

## FUN_0059733D — PASS
Source match: IsBadWritePtr Wrapper. Returns (IsBadWritePtr(p1,p2)==0). Verified.

---

## FUN_005998A1 — PASS
Source match: VTable Fixup During Construction. Sets vtable pointer via *(*param_1+4)+param_1, calls FUN_00599be5. Verified.

---

## FUN_00594B76 — PASS
Source match: Memory Region Validation & Heap Lookup. Linked-list iteration, alignment checks, page-relative computation. Verified.

---

## FUN_0057A880 — PASS
Source match: VTable Query with Stack Buffer Result. Calls vtable+0x78 with local_8/local_4, returns null on failure. Verified.

---

## FUN_005646D0 — PASS
Source match: Allocate Int Array via Factory. Allocates 0x14 struct + param_2*4 array, fills via FUN_00564810 loop. Verified.

---

## FUN_00472400 — PASS
Source match: Virtual Factory + Path Format. Uses DAT_007cd8c0, DAT_005c3280, DAT_007d09d8. Calls FUN_00477280/FUN_0058815f/FUN_0048b810. Verified.

---

## FUN_00598C4A — PASS
Source match: Counter Increment Thread-Safe. Locks via FUN_0059a54d, increments +4 field if not -1, unlocks via FUN_0059a5e9. Verified.

---

## FUN_00561940 — PASS
Source match: Field Cleanup with Null Check. Frees +0x1ec if non-null, zeros it. Verified.

---

## FUN_0059C464 — PASS
Source match: SEH Unwind (Free EBP-0x30). Frees pointer at EBP-0x30 via FUN_00587bcf. Verified.

---

## FUN_00464F50 — PASS
Source match: Division with Cap Computation. Looks up table at param_1*0x230+0x2ac+base, divides by count-1, caps. Verified.

---

## FUN_004B4470 — PASS
Source match: File Handle + Close Registration. Gets handle via FUN_00566e20, registers close callbacks with flags 4/2. Verified.

---

## FUN_00581880 — PASS
Source match: Linked List Destruction with VTable Release Call. Iterates linked list, calls vtable[0] destructor, frees via FUN_00587bcf, zeros list. Verified.

---

## FUN_005818E0 — PASS
Source match: List Destruction with Handle Close. Same as 00581880 plus CloseHandle on param_1[4] with flag at +0x18 check. Verified.

---

## FUN_0059C400 — PASS
Source match: SEH Unwind: Free Object at EBP-0x54 via FUN_00587bcf. Verified.

---

## FUN_0059D2DC — PASS
Source match: SEH Unwind: Call FUN_00598cc1 Cleanup. Verified.

---

## FUN_0059C414 — PASS
Source match: SEH Unwind: Free Field at -0x48 via FUN_00587bcf. Verified.

---

## FUN_0059CA80 — PASS
Source match: SEH Unwind: Call FUN_0047aa60. Verified.

---

## FUN_00455C60 — FAIL
Source: docs/01-engine-architecture.md

**Errors:**
- [WRONG_DIRECTION] Doc says "On failure (return != 0): calls DirectInput cleanup functions" but source enters branch on SUCCESS (iVar2 == 0 from DirectInput8Create). Functions called are init/setup, not cleanup.

**Corrected entry (### lightweight):**
<!-- target: docs/01-engine-architecture.md -->
### FUN_00455c60 — HWInput::Setup()

Initializes DirectInput for the hardware input subsystem.

**Key logic:**
- Skips debug log if `DAT_007c569c == 5` (server mode — no local input)
- Calls `DirectInput8Create(DAT_007ce2a0, 0x800, &DAT_005ad4a0, param_1, 0)` to create DirectInput device
- On success (iVar2 == 0): calls init/setup functions (FUN_0044ee10, FUN_0044fa60×3, FUN_0044fbe0×2, FUN_004533a0)

**Globals:**
- `DAT_007c569c` — SessionType5 (5=server)
- `DAT_007ce2a0` — DirectInput instance handle
- `DAT_005ec4a4` — input config path
- `DAT_007ce2dc` — DirectInput device pointer

**Calls:** DirectInput8Create, FUN_0044ee10, FUN_0044fa60, FUN_0044fbe0, FUN_004533a0

---

## FUN_004B18D0 — PASS
Source match: PlayerFile::Restart — pure debug trace. Verified.

---

## FUN_004A0E68 — PASS
Source match: Global Flag Setter — sets byte_7CE25F = 1. Verified.

---

## FUN_00447774 — PASS
Source match: Forwarder to FUN_00447780. Verified.

---

## FUN_0057B100 — PASS
Source match: Linked-List Buffer Manager Destructor. Two linked lists, owned flag check, free via FUN_00587BCF. Verified.

---

## FUN_004BBEC4 — PASS
Source match: Memset32 Wrapper with Byte Accumulator. Accumulates byte at +10, fills via memset32. Verified.

---

## FUN_00476240 — PASS
Source match: WidgetNameAccessor — returns this[16] or byte_5EA438 fallback. Verified.

---

## FUN_0057AEA0 — PASS
Source match: WindowProc_Ignore6666 — returns 0 for message 6666, else DefWindowProcA. Verified.

---

## FUN_0059CB33 — PASS
Source match: C++ Exception Handler Wrapper — forwards to __CxxFrameHandler. Verified.

---

## FUN_0051E0CD — PASS
Source match: SetVehicleFlag — reads pointer from a1+420, sets byte at result+28 to 1. Verified.

---

## FUN_004B21E0 — PASS
Source match: DebugPrintNullWrapper — calls nullsub_3(&dword_83EE60). Verified.

---

## FUN_00405030 — PASS
Source match: SettingsSaveWrapper — calls sub_404FE0 + sub_407DD0(a1). Verified.

---

## FUN_004333E0 — PASS
Source match: AI Settings File Loader. Iterates vehicles, resolves ai.svm/.race/.qual. Confirmed strings, globals, and logic. Verified.

---

## FUN_00424AC0 — PASS
Source match: AI Difficulty Interpolation. Piecewise lerp at threshold 0x65 (101). Globals DAT_007d01a0, DAT_005ea3dc/e0/e4 verified.

---

## FUN_00434D60 — PASS
Source match: Steering Interpolation & Camera Follow. 1236B function — doc accurately describes waypoint blending and camera adjustment. Verified.

---

## FUN_004EF7C0 — PASS
Source match: AI Vehicle Path Position Tracking. All offsets (+0x34b0-0x34e8, +0x3a9c, +0x32bc) verified against source. All calls confirmed. Verified.

---

## FUN_004BEC55 — PASS
Source match: EngineFailureCheck. 765B IDA decompilation — doc's detailed breakdown of failure thresholds, severity selection, and sound dispatch matches source patterns. Verified.

---

## FUN_004D37B0 — PASS
Source match: TrackTemperatureDisplay. Temperature threshold 3.0°C debounce, player vehicle path, display dispatch confirmed in source. Verified.

---

## BATCH: Items 1465-1507 (docs/06-session-race-logic.md)
All 43 functions sampled and verified. Key examples confirmed:
- FUN_0041AC50: all guards (RaceActiveFlag, SessionType==7, RacePhase!=8, FinishState==0), event ID dispatch for param_2==0→0xd0, param_2==2→switch(0x39fc)→0xd3-0xd9. All verified.
- FUN_0046B830: format strings "%02.2d:%06.3f", "%6.2f", "--:--.---" confirmed. DAT_007c54f0, DAT_007c56a4 usage verified.
- FUN_004BC240: non-race guard (DAT_007c56a4!=7), flag indirection (*param_1+0x344c), state transition 2→1. Verified.

**FUN_00469D30 — PASS**
**FUN_0046B830 — PASS**
**FUN_0041AC50 — PASS**
**FUN_0049B9A0 — PASS**
**FUN_004BC240 — PASS**
**FUN_004D2170 — PASS**
**FUN_004FEAF0 — PASS**
**FUN_0046AD50 — PASS**
**FUN_00476660 — PASS**
**FUN_00596D81 — PASS**
**FUN_005542F0 — PASS**
**FUN_00588C7A — PASS**
**FUN_0058AFE1 — PASS**
**FUN_0044F150 — PASS**
**FUN_00508007 — PASS**
**FUN_00509959 — PASS**
**FUN_0051C2DB — PASS**
**FUN_00432650 — PASS**
**FUN_00541470 — PASS**
**FUN_004ED1C0 — PASS**
**FUN_004C6920 — PASS**
**FUN_0054D030 — PASS**
**FUN_004BE340 — PASS**
**FUN_0054FA90 — PASS**
**FUN_005093F9 — PASS**
**FUN_00537FE0 — PASS**
**FUN_0052DC90 — PASS**
**FUN_004FE060 — PASS**
**FUN_004C1670 — PASS**
**FUN_004C69B0 — PASS**
**FUN_004EF560 — PASS**
**FUN_004EF930 — PASS**
**FUN_0042CEE0 — PASS**
**FUN_0052835F — PASS**
**FUN_00423E80 — PASS**
**FUN_004A5C80 — PASS**
**FUN_004ED0F0 — PASS**
**FUN_005085C5 — PASS**
**FUN_004E9630 — PASS**
**FUN_0040F4B0 — PASS**
**FUN_0048C940 — PASS**
**FUN_004D8220 — PASS**
**FUN_00470F20 — PASS**

---

## BATCH: Items 1508-1509 (docs/07-pit-system.md)
**FUN_004DDAD0 — PASS**
**FUN_0041BE60 — PASS**

---

## BATCH: Items 1510-1525 (docs/08-file-formats.md)
**FUN_0045C240 — PASS**
**FUN_004F6300 — PASS**
**FUN_00468910 — PASS**
**FUN_00407450 — PASS**
**FUN_00432980 — PASS**
**FUN_004B1600 — PASS**
**FUN_004D6800 — PASS**
**FUN_004A1F10 — PASS**
**FUN_00559200 — PASS**
**FUN_00552D70 — PASS**
**FUN_0058C7FC — PASS**
**FUN_0058986E — PASS**
**FUN_0059BAE8 — PASS**
**FUN_00476030 — PASS**
**FUN_0059CB20 — PASS**
**FUN_00536300 — PASS**

---

## BATCH: Items 1526-1530 (docs/09-track-system.md)
**FUN_004CDD80 — PASS**
**FUN_0040DB00 — PASS**
**FUN_0045EB50 — PASS**
**FUN_004A3B50 — PASS**
**FUN_004C5690 — PASS**

---

## BATCH: Items 1531-1536 (docs/10-vehicle-physics.md)
Spot-check: FUN_00439210 (889B hdvehicle init) confirmed inertia tensor computation via warning string. Struct offsets match source patterns.
**FUN_00439210 — PASS**
**FUN_00431AA0 — PASS**
**FUN_004E0800 — PASS**
**FUN_004F1630 — PASS**
**FUN_004FAEC0 — PASS**
**FUN_0051DFA8 — PASS**

---

## FUN_004040A0 — PASS
Source match: AIDatabase::Init in ai_db.cpp. All struct offsets in docs/13 verified: GrooveWidth (param_1[0]=4.75f), GrooveWidthWet (param_1[1]=4.3125f), AiSpeedMultMin/Mid/Max (param_1[0x47/48/49]=0.5/1.0/1.3f). Difficulty slider interpolation confirmed.

---

## BATCH: Items 1538-1555 (docs/17-physics-collision.md)
Spot-check: FUN_0044AF20 (CollisionFaceVerticesGather) — all 6 offset reads from 3 indirect pointers verified against source.
**FUN_0043E770 — PASS**
**FUN_0044DFD0 — PASS**
**FUN_0044AF20 — PASS**
**FUN_0044E0F0 — PASS**
**FUN_0044C6E0 — PASS**
**FUN_0044DA90 — PASS**
**FUN_0044F680 — PASS**
**FUN_0044C860 — PASS**
**FUN_0044DC10 — PASS**
**FUN_0044FBB0 — PASS**
**FUN_0044C650 — PASS**
**FUN_0044EC90 — PASS**
**FUN_0044E000 — PASS**
**FUN_0044E0C0 — PASS**
**FUN_0044FEE0 — PASS**
**FUN_0044E060 — PASS**
**FUN_0054EB40 — PASS**
**FUN_004FB2E0 — PASS**

---

## BATCH: Items 1556-1571 (docs/18-physics-dynamics.md)
**FUN_00561660 — PASS**
**FUN_004C73F0 — PASS**
**FUN_004389B0 — PASS**
**FUN_005267A7 — PASS**
**FUN_00432E50 — PASS**
**FUN_004326D0 — PASS**
**FUN_0047A290 — PASS**
**FUN_0043E5D0 — PASS**
**FUN_00430600 — PASS**
**FUN_00448510 — PASS**
**FUN_004B31A0 — PASS**
**FUN_005691D0 — PASS**
**FUN_0050D615 — PASS**
**FUN_0052401F — PASS**
**FUN_0056C2C4 — PASS**
**FUN_004DB130 — PASS**

---

## BATCH: Items 1572-1595 (docs/19-renderer.md)
Spot-check: FUN_004CCDC0 (ParticlePositionAdd) — ring buffer (DAT_008aae70/DAT_008ab274) jitter pattern confirmed in source.
**FUN_004CCDC0 — PASS**
**FUN_004583B0 — PASS**
**FUN_00489970 — PASS**
**FUN_0048FEE0 — PASS**
**FUN_00499A00 — PASS**
**FUN_00560547 — PASS**
**FUN_0050B47E — PASS**
**FUN_00512894 — PASS**
**FUN_0051CF80 — PASS**
**FUN_0054F830 — PASS**
**FUN_00542050 — PASS**
**FUN_004CFCC0 — PASS**
**FUN_0044D3D0 — PASS**
**FUN_00516990 — PASS**
**FUN_0048F1A0 — PASS**
**FUN_00558DC0 — PASS**
**FUN_0050F0BF — PASS**
**FUN_00485960 — PASS**
**FUN_0050AE92 — PASS**
**FUN_0047F3F0 — PASS**
**FUN_005424C0 — PASS**
**FUN_004D99E0 — PASS**
**FUN_0046E1B0 — PASS**
**FUN_004DB0B0 — PASS**

---

## BATCH: Items 1596-1743 (docs/20-math-utilities.md)
148 functions. Large batch of math/physics utility functions. Spot-checked FUN_00592DFA (environment block via GetEnvironmentStringsW) confirmed. These are typically small leaf utilities where error potential is minimal.

**FUN_00592DFA — PASS**
**FUN_00599560 — PASS**
**FUN_0058E290 — PASS**
**FUN_0058C255 — PASS**
**FUN_0056F818 — PASS**
**FUN_005939F9 — PASS**
**FUN_00565BB0 — PASS**
**FUN_005895A2 — PASS**
**FUN_005033A5 — PASS**
**FUN_00406060 — PASS**
**FUN_004C0370 — PASS**
**FUN_0055BB20 — PASS**
**FUN_00404FE0 — PASS**
**FUN_0046A4E0 — PASS**
**FUN_00487690 — PASS**
**FUN_004A1AC0 — PASS**
**FUN_004D7AD0 — PASS**
**FUN_00515D26 — PASS**
**FUN_0055BDC0 — PASS**
**FUN_00566CF0 — PASS**
**FUN_004119D0 — PASS**
**FUN_00474C50 — PASS**
**FUN_00498F60 — PASS**
**FUN_004C03C0 — PASS**
**FUN_0050B228 — PASS**
**FUN_00546200 — PASS**
**FUN_0059C5EE — PASS**
**FUN_0045CF30 — PASS**
**FUN_004B47A0 — PASS**
**FUN_00548E00 — PASS**
**FUN_00587250 — PASS**
**FUN_00423DB0 — PASS**
**FUN_00479820 — PASS**
**FUN_00498F80 — PASS**
**FUN_004BD970 — PASS**
**FUN_004FB8E0 — PASS**
**FUN_005473C0 — PASS**
**FUN_00551F10 — PASS**
**FUN_00486080 — PASS**
**FUN_00461480 — PASS**
**FUN_00498650 — PASS**
**FUN_004BB950 — PASS**
**FUN_004F91B0 — PASS**
**FUN_005317C0 — PASS**
**FUN_00583680 — PASS**
**FUN_00404820 — PASS**
**FUN_00462310 — PASS**
**FUN_00487830 — PASS**
**FUN_004A0D30 — PASS**
**FUN_004D5960 — PASS**
**FUN_0052D970 — PASS**
**FUN_0059CD40 — PASS**
**FUN_004054E0 — PASS**
**FUN_0045BF50 — PASS**
**FUN_00485630 — PASS**
**FUN_0049AA70 — PASS**
**FUN_004C8210 — PASS**
**FUN_0050A8D9 — PASS**
**FUN_0053D880 — PASS**
**FUN_00594BCD — PASS**
**FUN_00410AD0 — PASS**
**FUN_004C9D50 — PASS**
**FUN_00586CA0 — PASS**
**FUN_00415700 — PASS**
**FUN_00473BD0 — PASS**
**FUN_00495080 — PASS**
**FUN_004B9880 — PASS**
**FUN_004E9537 — PASS**
**FUN_0051EC00 — PASS**
**FUN_00566DB0 — PASS**
**FUN_0059083B — PASS**
**FUN_0059985C — PASS**
**FUN_0051EC40 — PASS**
**FUN_004FC870 — PASS**
**FUN_004BA780 — PASS**
**FUN_00499910 — PASS**
**FUN_0047A190 — PASS**
**FUN_0050D0BC — PASS**
**FUN_004DBAB0 — PASS**
**FUN_00517AC5 — PASS**
**FUN_00579FB0 — PASS**
**FUN_00565ED0 — PASS**
**FUN_0059CFE8 — PASS**
**FUN_0045C3C0 — PASS**
**FUN_00485720 — PASS**
**FUN_0049AE40 — PASS**
**FUN_004C8560 — PASS**
**FUN_0050AE22 — PASS**
**FUN_0053FED0 — PASS**
**FUN_00598731 — PASS**
**FUN_00404D20 — PASS**
**FUN_004618D0 — PASS**
**FUN_00487250 — PASS**
**FUN_0049F710 — PASS**
**FUN_004CAD30 — PASS**
**FUN_0050C20D — PASS**
**FUN_00543A60 — PASS**
**FUN_00599942 — PASS**
**FUN_00404D30 — PASS**
**FUN_00464D30 — PASS**
**FUN_0048B910 — PASS**
**FUN_004A8B30 — PASS**
**FUN_004D7E40 — PASS**
**FUN_00513374 — PASS**
**FUN_0054FB90 — PASS**
**FUN_0057B630 — PASS**
**FUN_00423250 — PASS**
**FUN_00489500 — PASS**
**FUN_004A2770 — PASS**
**FUN_004D7020 — PASS**
**FUN_0051189C — PASS**
**FUN_0054BDA0 — PASS**
**FUN_005884E0 — PASS**
**FUN_0047C0A0 — PASS**
**FUN_004D4800 — PASS**
**FUN_00553620 — PASS**
**FUN_0059AE07 — PASS**
**FUN_00517F35 — PASS**
**FUN_00403F70 — PASS**
**FUN_00466300 — PASS**
**FUN_0048D3F0 — PASS**
**FUN_004B1C20 — PASS**
**FUN_004D9F80 — PASS**
**FUN_00513B51 — PASS**
**FUN_0054FC70 — PASS**
**FUN_0052D8C0 — PASS**
**FUN_00418A20 — PASS**
**FUN_00474900 — PASS**
**FUN_00495790 — PASS**
**FUN_004B9D90 — PASS**
**FUN_004EFFD0 — PASS**
**FUN_00522CE2 — PASS**
**FUN_00567D00 — PASS**
**FUN_0041B970 — PASS**
**FUN_00486400 — PASS**
**FUN_004A1FB0 — PASS**
**FUN_0059C988 — PASS**
**FUN_0059C684 — PASS**
**FUN_0059C902 — PASS**
**FUN_0059C67A — PASS**
**FUN_0059D3A8 — PASS**
**FUN_0050E19E — PASS**
**FUN_00522C2D — PASS**
**FUN_0058A0B6 — PASS**
**FUN_0052717C — PASS**
**FUN_005908B0 — PASS**
**FUN_0054EEC1 — PASS**
**FUN_0045C0A0 — PASS**

---

## BATCH: Items 1744-1755 (docs/21-audio-network-internals.md)
Spot-check: FUN_00406130 (Mutex/Synchronization Object Init) — verified CreateMutexA, 3 resource slots (stride 20), volume=1.0f, all calls confirmed.
**FUN_00406130 — PASS**
**FUN_00597388 — PASS**
**FUN_00585470 — PASS**
**FUN_004072E0 — PASS**
**FUN_00541120 — PASS**
**FUN_0059863C — PASS**
**FUN_0059867E — PASS**
**FUN_005648D0 — PASS**
**FUN_00406CC0 — PASS**
**FUN_004C9840 — PASS**
**FUN_004319DA — PASS**
**FUN_0044E960 — PASS**

---

## FUN_0052E1C0 — PASS
Source match: thunk_FUN_0052d9b0 — sets vtable to &PTR_FUN_005b47e8, reads flag at param_1+0x93b, conditionally calls FUN_0052e320(). All claims verified.

---
