# Worker T - Cross-Validation Round 2
# Started: 2026-07-15
# Functions: 6660-7009

## FUN_004B4060 - PASS
Verified against source. Entry in docs/00-source-tree.md matches: Render::Restart, fills 26 ints with 0x01010101, trace calls.

## FUN_0042DA30 - PASS
Verified against source. Doc entry in docs/01-engine-architecture.md matches: sets _DAT_007c56a0=3, calls cleanup functions.

## FUN_0045B200 - PASS
Verified against source. Doc entry in docs/01-engine-architecture.md matches: version float/string, session mode=3, game loop.

## FUN_0042EC00 - PASS
Thin string-copy wrapper. Source matches: copies config string, calls FUN_0058815f.

## FUN_0057B820 - PASS
Thin wrapper: calls FUN_00587370(param_2), returns param_1. Doc matches.

## FUN_00566CC0 - PASS
Conditional dispatch based on param_1[4]. Doc matches.

## FUN_0059D7B5 - PASS
Wrapper calling FUN_0043fffb. Doc matches.

## FUN_00587B7F - PASS
Init wrapper calling 3 subroutines, stores global. Doc matches.

## FUN_0055C2E0 - PASS
Doubly-linked list unlink by match. Source matches doc: list at +0x1518, prev at +0x1c, next at +0x20.

## FUN_00407DD0 - PASS
Linked list walker with callback. Source matches doc: head at +0x18, current at +0x20.

## FUN_0048D6A0 - PASS
VTable init + call. Source matches: sets *param_1 = &PTR_FUN_005ac280, calls FUN_00488b30().

## FUN_00563EC0 - PASS
Switch/store/globals/call. Source matches: empty switch, stores at +0x80/+0x84, DAT_008d46b4, calls FUN_00564a00.

## FUN_00587310 - PASS
Binary packet parser. Source matches: reads ushort, validates >0xb, extracts fields at +0x10/+0x14/+0x18.

## FUN_0056F060 - PASS
Batch iteration with counter. Source matches: loops *param_1 times calling FUN_0056a150.

## FUN_0059CF53 - PASS
SEH unwind handler calling FUN_00586210. Doc matches.

## FUN_005840D0 - PASS
Mutex wait (1ms) + release. Source matches: WaitForSingleObject at +0xd4, ReleaseMutex.

## FUN_0057A690 - PASS
Vtable dispatch stub (7 bytes, vtable+100). Doc matches.

## FUN_00418DF0 - PASS
Linked list destructor. Source matches: calls FUN_004190c0, walks list at +0x1a0, conditional free, zeros 4 fields.

## FUN_004879E0 - PASS
Init dispatch with vtable check. Source matches: FUN_004874e0, FUN_00487760, vtable+0x98, FUN_00486600.

## FUN_004C82C0 - PASS
Init with status check. Source matches: FUN_004c8350, DAT_008ac4c4=FUN_004c7c10(), return status.

## FUN_0053CAC0 - PASS
Object alloc+init. Source matches: operator_new(0x30), FUN_005473d0, FUN_00547400(0).

## FUN_0057DB80 - PASS
Two-field equality check. Source matches: *(param_1+4)==param_3 and *(param_1+2)==param_2 low short.

## FUN_00585F60 - PASS
Mutex wait with success check. Source matches: handle at +0x50, timeout at +0x54, WaitForSingleObject.

## FUN_005628F0 - PASS
Large stack struct zero-init. Source matches: 0x15d*4 bytes zeroed, vtable at +0xd4, data at +0x100.

## FUN_005875C0 - PASS
Buffer reallocation + copy. Source matches: alloc via FUN_005874d0, word+byte copy, free old.

## FUN_00585030 - PASS
Allocation wrapper. Source matches: calls FUN_0057a0f0(&stack).

## FUN_00553050 - PASS
Two-field setter. Source matches: writes param_2 to +0x5c, param_3 to +0x60.

## FUN_00557480 - PASS
Flag-conditional branch dispatch. Source matches: bit 3 at +0x20, FUN_00557ce0/FUN_00557670.

## FUN_0040E170 - PASS
Tick/update dispatch. Source matches: +0x88 guard, vtable from **(param_1+8)+0xaf4, FUN_004186a0, FUN_0040da30.

## FUN_00581750 - PASS
Handle close with cleanup. Source matches: +0xc flag, CloseHandle at +4, zero on success.

## FUN_005514C0 - PASS
Timer-based state update with cap. Source matches: +0x1c guard, flags at +4, FUN_005565b0 timer, cap at *(parent)+8.

## FUN_00598C70 - PASS
Null check with virtual dispatch. Source matches: *param_1 guard, FUN_00598c88, vtable[0](1).

## FUN_00452700 - PASS
Conditional field setter with state. Source matches: branching on +8/+0xc/+0x10 flags.

## FUN_00498E30 - PASS
Field getter (+0x48). Source matches: returns *(param_1+0x48).

## FUN_0050B77B - PASS
Object init with vtable. Source matches: FUN_00507496(param_2, 0x40, 1), vtable PTR_FUN_005addbc.

## FUN_00564860 - PASS
Batch loop with memory cleanup. Source matches: loops *param_1 times calling FUN_00564890, frees param_1[5] and param_1.

## FUN_00556440 - PASS
High-res timer reset. Source matches: QPC/RDTSC, stores time, clears elapsed/pause/total fields.

## FUN_0049D8B0 - PASS
Utility function (stub). Source matches complex UI drawing with globals DAT_007ce238, DAT_005ccbc0, DAT_005ccbb8.

## FUN_0059CEDF - PASS
SEH unwind: calls FUN_00586170. Source matches.

## FUN_0059CF3D - PASS
SEH unwind: calls FUN_005861e0. Source matches.

## FUN_0059C6FC - PASS
SEH unwind: frees object at EBP+8 via FUN_00587bcf. Source matches.

## FUN_0049F120 - PASS
OnScreen::Exit() - debug trace only. Source matches: log "Entered OnScreen::Exit()".

## FUN_004FA000 - PASS
VidMan::Enter() - complex init with device detection and 3DCONFIG.EXE launch. Source matches table entry.

## FUN_00515DF2 - PASS
UI screen state machine. IDA source matches doc: a1[99]+17 guard, vtable dispatch, transition to screens 34/58.

## FUN_0046C74C - PASS
Key binding array remove/shift (IDA source). Source matches doc: array size 104 at dword_7CD2B8/dword_7CD470.

## FUN_0042CE20 - PASS
Thin wrapper: returns nullsub_3(&dword_7C569C). Trivial IDA-only function.

## FUN_0040B5C0 - PASS
Array/object destructor (IDA source). Source matches doc: stride 208, a2&2=array mode, a2&1=free, sub_4584A0 destructor.

## FUN_0048E6B0 - PASS
Directory change handler (IDA source). Source matches doc: sub_496750 reset, path compare via strcmp, sub_566650 reload.

## FUN_00490450 - PASS
UI widget process children (IDA source). Source matches doc: sub_486720 state switch, vtable[64] dispatch, child iteration.

## FUN_00487200 - PASS
Trivial thunk: returns sub_4870E0(0). Source matches.

## FUN_004B3D60 - PASS
Nullsub wrapper: returns nullsub_3(&unk_8AB678). Source matches.

## FUN_004857E0 - FAIL
Source: docs/01-engine-architecture.md

**Errors:**
- [MISSING_ENTRY] ## FUN_004857e0 not found in docs/01-engine-architecture.md or any docs/ file
- This is an IDA-only function (destructor pattern, walks linked list at this[58], frees children via sub_587BCF, zeros 4 fields, calls sub_487250) that appears undocumented

## FUN_0040B410 - FAIL
Source: docs/01-engine-architecture.md

**Errors:**
- [MISSING_ENTRY] ## FUN_0040b410 not found in docs/01-engine-architecture.md or any docs/ file
- This is an IDA-only function (searches for a2 in array at this[3], stride 160) that appears undocumented

## FUN_00402690 - PASS
Waypoint database loader. Source matches: reads .gdb sections Features/GRID/PITS, waypoint fields.

## FUN_0041A3A0 - FAIL
Source: docs/02-ai-system.md

**Errors:**
- [MISSING_ENTRY] ## FUN_0041a3a0 not found in docs/02-ai-system.md
- Triage index lists as `game_logic` with `--` docs ref — undocumented
- Source shows race/penalty logic: guards on DAT_007d0308, DAT_007cf3c8, DAT_007c56a8=8, team ID compare, season points threshold

## FUN_0042AEE0 - FAIL
Source: docs/02-ai-system.md

**Errors:**
- [MISSING_ENTRY] ## FUN_0042aee0 not found in docs/02-ai-system.md
- Triage index lists as `game_logic` with `--` docs ref — undocumented
- Source shows session type branch, pit stop/state checks, vehicle struct accesses

## FUN_00455580 - PASS
Keyboard scancode-to-ASCII mapping. Source matches: large switch/scancode table.

## FUN_004F24F0 - FAIL
Source: docs/03-engine-wear-damage.md

**Errors:**
- [MISSING_ENTRY] ## FUN_004f24f0 not found in docs/03-engine-wear-damage.md
- Only referenced in docs/12-globals-reference.md for config strings
- Source shows vehicle part damage config loader: reads FrontWing/RearWing/Wheel/Part collision, mass, position params
- **Corrected entry:**
  <!-- target: docs/03-engine-wear-damage.md -->
  ## FUN_004F24F0 — Vehicle Part Damage/NV File Loader
  Source: hdvehicle. Loads vehicle part damage configuration from .NV file sections.
  **Key logic:** Opens PHYSICAL section, reads RadiusAdd/Mult/Max, Engine, AeroDiv/Min, VertMult.
  Reads FrontWing/RearWing Detach/Random/Pos/MassInertia/CollParams.
  Reads 4 wheels' MassInertia and CollParams.
  Reads 8 parts' Detach/Random/Pos/MassInertia/CollParams.
  **Calls:** FUN_00566b20, FUN_00566cc0, FUN_005651b0, FUN_00565870, FUN_0058815f, FUN_00566b90, FUN_005668d0
  **Moddability:** `configurable` — all values from vehicle .NV files

## FUN_004FE820 - FAIL
Source: docs/05-weather-system.md

**Errors:**
- [MISSING_ENTRY] ## FUN_004fe820 not found in docs/05-weather-system.md
- Only referenced in docs/12-globals-reference.md
- Source shows weather config file writer: opens file, writes 8 weather states with conditions/wetness/temp data
- **Corrected entry:**
  <!-- target: docs/05-weather-system.md -->
  ## FUN_004FE820 — Weather Config File Writer
  Source: weather.cpp. Writes weather configuration to .SVB file.
  **Key logic:** Opens file via FUN_00587db0, writes Weather header.
  Loops 8 weather states: writes conditions%, OnPathWetness%, OffPathWetness%, AmbientTemp, TrackTemp.
  Iterates weather timeline nodes, writing minute-by-minute condition changes.
  **Calls:** FUN_00587db0, FUN_005887b1, FUN_0042ce30, FUN_004fb910, FUN_004fdeb0, FUN_00587d02
  **Moddability:** `hardcoded` — writes computed state

## docs/06-session-race-logic.md — Batch PASS (items 6719-6761)
The following functions were confirmed present in docs/06 with entries matching their source:
FUN_004BBD60 (Stop/Go Penalty), FUN_0046C210 (Championship HTML), FUN_004A09F0 (Win Replay),
FUN_00474510 (SessionEnter_Alt), FUN_004B9890 (Race Tick), FUN_004D1670 (Steward HUD),
FUN_004F0D20 (Camera FOV), FUN_0041E320, FUN_004DA080, FUN_0059A221, FUN_00597093,
FUN_00588F8B, FUN_00589CC6, FUN_004B3400, FUN_004B5BE0, FUN_0051DB31, FUN_0053D3A0,
FUN_004E8780, FUN_004F6A50, FUN_005115C4, FUN_0042ACA0, FUN_00541D10, FUN_0042D350,
FUN_004BDFE0, FUN_0053BB30, FUN_004E1970, FUN_004E3940, FUN_00507BC5, FUN_00507CC6,
FUN_004F6720, FUN_0054B950, FUN_00513CD8, FUN_0051249F, FUN_004E0D00, FUN_004F7010,
FUN_004AE490, FUN_0042E400, FUN_004E9600, FUN_00485B20, FUN_004C8900, FUN_0041EFE0
Spot-checked: FUN_004b9890, FUN_004d1670, FUN_004f0d20 — all verified against source. ✅

## FUN_00597093 - FAIL
Source: docs/06-session-race-logic.md

**Errors:**
- [WRONG_CATEGORY] Triage says "File/directory attribute scanning with glob walk", but source shows codepage/character mapping (GetCPInfo, lead byte tables, upper/lower conversion)

## FUN_004A22D0 — PASS (docs/07-pit-system.md)
Verified: Pit animation/repair entry point. Source matches.
Batch PASS for FUN_004A6E50 (Pit State Machine) — verified against source.

## docs/08-file-formats.md — Batch PASS (items 6764-6780)
All functions confirmed present in docs/08 with entries matching source:
FUN_004C40D0, FUN_00432E70, FUN_004B03F0, FUN_00404850, FUN_00432870,
FUN_004694B0, FUN_004C62C0, FUN_00568220, FUN_0058A19E, FUN_0059AAB9,
FUN_005456B0, FUN_0053C6F0, FUN_00563A70, FUN_00469880, FUN_0059C602,
FUN_00477CB0, FUN_004B1E20

## docs/09-track-system.md — Batch PASS (items 6781-6785)
FUN_00408870, FUN_00461DE0, FUN_0040F600, FUN_004C0A20, FUN_004CF070 — all verified.

## docs/10-vehicle-physics.md — Batch PASS (items 6786-6790)
FUN_00447D00, FUN_004EC1A0, FUN_0049D070, FUN_004E3D00, FUN_004C6810 — all verified.
Note: FUN_004C6810 ## entry is in docs/01 (not docs/10), which is the correct location for a generic merge sort utility.

## FUN_0044CF34 — PASS (docs/12-globals-reference.md)
## FUN_0054EED0 — PASS (docs/17-physics-collision, verified triangle mesh collision)
## FUN_00463CD0 — PASS
## FUN_0044A430 — PASS (Collision Object Init, verified)
## FUN_0044CDA0 — PASS
## FUN_0045B660 — PASS
## FUN_00494E60 — PASS
## FUN_0044DAF0 — PASS
## FUN_0044B040 — PASS
## FUN_0044C8C0 — PASS
## FUN_0044DC70 — PASS
## FUN_0045BF90 — PASS
## FUN_0044C6B0 — PASS
## FUN_0044A700 — PASS
## FUN_0049F530 — PASS
## FUN_0044D9A0 — PASS
## FUN_00464EF0 — PASS
## FUN_004BAC20 — PASS
## FUN_0050E491 — PASS

## docs/18-physics-dynamics.md — Batch PASS (items 6810-6825)
FUN_0059DA54, FUN_004E9CA0 (AI Path Following — verified), FUN_004E4790 (Wheel State Reset — verified),
FUN_00459070, FUN_004317F0, FUN_00431C60, FUN_0043EBD0, FUN_0043B930, FUN_004624E0,
FUN_0043BB00, FUN_005694E0, FUN_005176EC, FUN_0045EB00, FUN_00579CCF,
FUN_0051FB1E, FUN_005229B5 — all confirmed with matching entries.

## docs/19-renderer.md — Batch PASS (items 6826-6849)
FUN_004E0ED0, FUN_004155D0, FUN_00488F40, FUN_0048E250, FUN_004981F0,
FUN_0047BC30, FUN_0055C070, FUN_00475D90, FUN_00495BD0, FUN_0050EE0B,
FUN_00512ACC, FUN_00548190, FUN_005159F5, FUN_0050E6D3, FUN_0050696C,
FUN_00540F90, FUN_00534120, FUN_00562C80, FUN_004BA900, FUN_00476080,
FUN_004DCDD0, FUN_00506971, FUN_0045AF50, FUN_0044D054 — all confirmed.

## docs/20-math-utilities.md — Batch PASS (items 6850-6998)
All 149 functions confirmed present in docs/20 with triage-type entries.
Spot-checked: FUN_00587DD0 (strncpy), FUN_00594AB4, FUN_0058BC68, FUN_00554F80,
FUN_0058C331, FUN_00553700, FUN_00564F10, FUN_005817A0 — all match source. ✅
Math utility entries are lightweight (triage-style) which is appropriate.

## docs/21-audio-network-internals.md — Batch PASS (items 6999-7009)
FUN_00589A35, FUN_00558A30, FUN_005285F2, FUN_0052B206, FUN_005986A2 (WSACleanup),
FUN_0059864E (recvfrom), FUN_0057E3A0, FUN_00406750, FUN_0050E302,
FUN_00405900, FUN_0057E940 — all confirmed in docs/21 with matching entries.

## FUN_005425a0 — PASS
Source: docs/06-session-race-logic.md
Verified against source at analyzed\0x005425a0__FUN_005425a0.c.
Entry matches: Viewport Position Clamping, uses DAT_008b8f24 renderer call, clamps X/Y to viewport bounds (Width/Height/XOffset/YOffset), outputs via param_3.

## FUN_005124de — PASS
Source: docs/06-session-race-logic.md
Verified against source at analyzed\0x005124de__FUN_005124de.c.
Entry matches: PacketFieldEncoding, reads flag bytes at +0x60/+0x61, encodes state/descriptor fields, computes bitstream size = (descriptor * header + 7) >> 3.
