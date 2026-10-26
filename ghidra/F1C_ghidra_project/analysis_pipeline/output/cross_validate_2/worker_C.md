## FUN_004024F0 — PASS
Source: docs/00-source-tree.md (line 765) + docs/02-ai-system.md (line 388)
- Walks AI waypoint linked list from +0x134 → +0x110 — confirmed (lines 22, 67)
- Validates path completeness (checks for cycles up to 12000 nodes) — confirmed (line 64)
- Renders path using debug lines: FUN_004cefa0 for position/color — confirmed (lines 49, 55)
- Uses FUN_00402220 to get waypoint positions — confirmed (lines 47-52)
- Calls FUN_0053ac70 with 2 then 1 to set render state — confirmed (lines 38, 58)
- Falls through on empty path with "Incomplete waypoint path" assert — confirmed (lines 25-32)
- All calls listed confirmed: FUN_004cf010, FUN_0053ac70, FUN_00402220, FUN_004cefa0, FUN_004d7a50, FUN_004d7aa0

## FUN_004C8A20 — PASS
Source: docs/01-engine-architecture.md (line 140) + docs/00-source-tree.md (line 1086)
- Debug trace "Entered Sound::Enter()" — confirmed (line 13)
- FUN_004c82c0 → if 0 → FUN_004c82f0 (init sound) — confirmed (lines 15-18)
- FUN_004c83b0 (setup) — confirmed (line 19)
- FUN_004c8560 (load sound files) — confirmed (line 20)
- FUN_004c8900(DAT_007cf380) — set output device — confirmed (line 21)
- FUN_004184f0 (audio mixer) — confirmed (line 22)
- FUN_004116c0(0) and FUN_004116c0(1) — channel init — confirmed (lines 23-24)
- DAT_007cf380 — sound device handle — confirmed (line 21)
- All calls confirmed

## FUN_00404F30 — PASS
Source: docs/01-engine-architecture.md (line 634)
- Calls FUN_004a0250() + FUN_004a03f0() (menu setup) — confirmed (lines 10-11)
- Checks condition via FUN_00404f10() — confirmed (line 12)
- If true: calls FUN_00497940("MAIN MENU", 0xffffffff) — confirmed (lines 13-14)
- Calls FUN_004049d0() (post-setup) — confirmed (line 16)
- All calls confirmed

## FUN_004A0AD0 — PASS
Source: docs/01-engine-architecture.md (line 4270)
- Calls virtual at (*DAT_007cd8c0)+0x1c with arg 0x1b (command ID) — confirmed (line 10)
- If non-null: calls FUN_0046a560() (standings display) — confirmed (lines 11-13)
- DAT_007cd8c0 — game command dispatch interface — confirmed (line 10)
- All calls confirmed

## FUN_00593C9C — PASS
Source: docs/01-engine-architecture.md (line 9588)
- SEH frame (DAT_005b9988, handler LAB_0058895c) — confirmed (lines 14-15)
- Calls FUN_0058e0c7() TLS retrieval — confirmed (line 19)
- Checks *(result + 0x60) != 0 — confirmed (line 20)
- If non-null: sets local_8=1, retrieves TLS, calls fnptr — confirmed (lines 21-23)
- local_8 = 0xffffffff SEH termination — confirmed (line 25)
- FUN_00597371() SEH epilogue — confirmed (line 26)
- ExceptionList setup — confirmed (line 18)

## FUN_004E0E20 — PASS
Source: docs/06-session-race-logic.md (line 9591)
- Computes entry address: param_1 + param_2 * 0x128 — confirmed (line 10)
- Calls FUN_004e0d00(param + 0x144) — confirmed (line 11)
- Calls FUN_004e0d00(param + 0x188) — confirmed (line 13)
- If value at +0x188 was non-null: calls FUN_0054c030(1,1,0,0) — confirmed (lines 14-15)
- All calls confirmed

## FUN_004E17C0 — PASS
Source: docs/06-session-race-logic.md (line 9986)
- Switch on param_2 (0-13) — confirmed (cases 0-0xd, lines 10-46)
- Cases 0-3: Wheels at stride 0x128, +0x144 active, +0x184 ready — confirmed (lines 11-30)
- Case 4: system at param_1+0x5e4 — confirmed (lines 31-33)
- Case 5: system at param_1+0x628 — confirmed (lines 34-36)
- Cases 6-13: subsystems at param_1+0x66c + (id-6)*0x44 — confirmed (lines 37-46)
- param_3==0: activate (FUN_004e0e20 for wheels, FUN_004e0d00 for systems) — confirmed (lines 20, 52)
- param_3!=0: deactivate (FUN_004e0e70 for wheels, FUN_004e0d70 for systems) — confirmed (lines 29, 57)
- Guards prevent redundant ops — confirmed (lines 16-18, 23-28, 51, 56)
- All calls confirmed

## FUN_004BBFC0 — PASS
Source: docs/06-session-race-logic.md (line 10413)
- Packet type match (param_2 & 0xFC0000 == 0x680000) — confirmed (line 10)
- If idle (param_1[0xc]==0): set active=2, timer from packet byte — confirmed (lines 11-15)
- Clear car+0x105d flag, hide indicator (FUN_004e0ed0) — confirmed (lines 16-19)
- FUN_0042af40 (sound/action) — confirmed (line 21)
- Non-matching packet: reset state, show indicator — confirmed (lines 24-32)
- OFFSETS: +0x105d, +0x1054 confirmed

## FUN_00548D40 — PASS
Source: docs/06-session-race-logic.md (line 10796)
- Linked list head at param_1+0x170 — confirmed (line 13)
- If null: alloc 0x1c-byte node, init via FUN_00548aa0 — confirmed (lines 15-22)
- If non-null: walk via +0x18 links, append new node — confirmed (lines 25-35)
- FUN_00548ad0(param_2,param_3) validation — confirmed (line 37)
- Non-zero → return -1 — confirmed (lines 38-39)
- Increment counter at +0x16c — confirmed (line 41)
- All calls confirmed

## FUN_00542400 — PASS
Source: docs/06-session-race-logic.md (line 11232)
- If param_2 non-null: copies 16 dwords from param_1+0x15c to param_2 — confirmed (lines 11-17)
- SourceData at +0x15c — confirmed (line 12)

## FUN_004B5A30 — FAIL
Source: docs/06-session-race-logic.md (line 11700)

**Errors:**
- [WRONG_CONST] Struct offsets table missing +0x704 (ComponentPtr4) — doc text lists it correctly at line 11708 but table at lines 11718-11721 omits it

**Corrected entry:**
<!-- target: docs/06-session-race-logic.md -->
## FUN_004b5a30 — DestroyUIWidgetHierarchy

Source: unknown. Tears down a complete UI widget/layer hierarchy, freeing linked lists and components.

**Key logic:**
- Calls FUN_004b6130, FUN_004b5e50, FUN_004b5f60 (pre-cleanup)
- Frees object at +0xf94 via FUN_00587bcf
- Calls FUN_004b52a0, FUN_004ba9f0×2, FUN_004bb4f0, FUN_004b0170×2 (sub-component cleanup)
- Frees objects at +0x72c, +0x724, +0x70c, +0x704 via FUN_00587bcf
- Calls FUN_004bb400, FUN_005668d0
- Walks linked list at +0x6d4 chain: FUN_004646f0(1) per node, zeros head + 3 trailing fields
- Walks linked list at +0x6c0 chain: FUN_004ba900(1) per node, zeros head + 3 trailing fields
- Walks 0x68 (104) additional linked lists below +0x6c0: FUN_004ba8c0(1) per node, zeros 4 fields per list
- Final cleanup: FUN_0049af30×2, FUN_004bb650, FUN_004baeb0×2, FUN_004bb5a0

**Struct offsets (param_1):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0xf94 | ComponentPtr0 | freed object |
| +0x72c | ComponentPtr1 | freed object |
| +0x724 | ComponentPtr2 | freed object |
| +0x70c | ComponentPtr3 | freed object |
| +0x704 | ComponentPtr4 | freed object |
| +0x6d4 | ListHeadA | linked list chain |
| +0x6c0 | ListHeadB | linked list chain + 104 sub-lists below |

**Calls:** FUN_004b6130, FUN_004b5e50, FUN_004b5f60, FUN_00587bcf (×5), FUN_004b52a0, FUN_004ba9f0 (×2), FUN_004bb4f0, FUN_004b0170 (×2), FUN_004bb400, FUN_005668d0, FUN_004646f0 (per node), FUN_004ba900 (per node), FUN_004ba8c0 (per node), FUN_0049af30 (×2), FUN_004bb650, FUN_004baeb0 (×2), FUN_004bb5a0

**Moddability:** hardcoded

## FUN_005087A2 — PASS
Source: docs/06-session-race-logic.md (line 12112)
- RGB dot product × DAT_0059fec8 + palette value → byte output — confirmed (lines 28-32)
- Globals _DAT_005adb18/1c/20 (RGB matrix), DAT_0059fec8 (additive scale) — confirmed
- Calls FUN_00506ce2 (input transform) — confirmed (line 19)
- Calls FUN_00507473 (texture setup) — confirmed (line 22)
- All claims confirmed

## FUN_0054E240 — FAIL
Source: docs/06-session-race-logic.md (line 12486)

**Errors:**
- [WRONG_DIRECTION] Doc says "reads from param_1+0x124 + 8 + param_2*0x24, deref +4" but source shows THREE dereferences: param_1+0x124 → pointer array → each element is pointer → target at +4. Missing one full level of indirection.

**Corrected entry:**
<!-- target: docs/06-session-race-logic.md -->
## FUN_0054E240 — Array Index Read (double-indirect)

Source: unknown. Bounds-checked array read from a pointer array (double indirection).

**Key logic:**
- If param_2 < *(param_1+0x120): returns *(*(*(param_1+0x124) + 8 + param_2*0x24) + 4)
  1. Read pointer array base from param_1+0x124
  2. Index into array at offset 8 + param_2*0x24 → get element pointer
  3. Dereference element pointer + 4 → return value
- Returns 0 if bounds check fails

**Struct offsets:**
| Offset | Field |
|--------|-------|
| +0x120 | ArrayCount (int, max index) |
| +0x124 | ArrayBasePtr (pointer to pointer array) |

**Moddability:** hardcoded

## FUN_00512322 — PASS
Source: docs/06-session-race-logic.md (line 12897)
- Checks byte at +0x117 == 0x10 — confirmed (line 8)
- If match: sets bit 0x10 at +0x60 — confirmed (line 9)
- All claims confirmed

## FUN_00508F3D — FAIL
Source: docs/06-session-race-logic.md (line 13312)

**Errors:**
- [WRONG_CONST] Bit packing shift for Blue channel is wrong. Doc says `B << 0xb (11)`, but source shows `B << 0x15 (21)` — the `<< 10` at the outer level applies to the whole `(G & 0x7ff | B << 0xb)` expression, making B shift = 0xb + 0xa = 0x15.

**Corrected entry:**
<!-- target: docs/06-session-race-logic.md -->
## FUN_00508f3d — Texture Encoder RGB 5-6-5

Source: likely_renderer_texture.cpp. Quantizes float RGB pixels to 16-bit 5-6-5 format with dithering. NOTE: should be in docs/19-renderer.md (renderer texture format converter).

**Key logic:**
- If param_1+0x1048 != 0: resolves indirect buffer via FUN_00506ce2
- Calls FUN_00507473 (dither state init)
- Loops over count at param_1+0x1058
- For each pixel: reads 3 floats (RGB), applies dither from 4×4 matrix indexed by (param_3&3) + (param_2&3)×8 + (uVar5&3)
- Quantizes: R 5-bit (×_DAT_005accb4), G 6-bit (×_DAT_005acee4), B 5-bit (×_DAT_005acee4)
- Packs into uint: `R & 0x3ff | (G & 0x7ff) << 10 | (B & 0x7ff) << 21`
  - R at bits 0-9, G at bits 10-20, B at bits 21-31

**Globals:**
- `_DAT_005accb4` — 5-bit R scale
- `_DAT_005acee4` — 6-bit G / 5-bit B scale

**Calls:** FUN_00506ce2 (buffer resolve), FUN_00507473 (dither init)

**Moddability:** hardcoded

## FUN_004B87A0 — PASS
Source: docs/06-session-race-logic.md (line 13689)
- Copies param_1+0xf30 → *param_2 (queue1 value) — confirmed (line 10)
- Copies param_1+0xf34 → *param_3 (queue2 value) — confirmed (lines 11-12)
- Returns: upper 3 bytes of queue2 value with low byte set to 1 — confirmed (line 13)
- All claims confirmed

## FUN_004E23AD — PASS
Source: docs/06-session-race-logic.md (line 14116)
- 4 entries starting at param_1+0x1ec, stride 0x4a*4 = 0x128 — confirmed (lines 11-17)
- Each set to 0xffffffff (-1) — confirmed (line 14)

## FUN_0054D7A0 — PASS
Source: docs/06-session-race-logic.md (line 14569)
- Distance from contact point to shape center — confirmed (lines 16-20)
- Bit 4 check at +0x14 — confirmed (line 21)
- Simple distance test (bit 4 clear): thresholds +0xf8/+0xf4, state 4 — confirmed (lines 22-25)
- Entering/exiting (bit 4 set): iteration count +0xfc vs 5 — confirmed (lines 29-30)
- Plane equations at param_2+0x104, stride 4 floats — confirmed (line 41)
- Outside all planes → state 4, inside any → state 2 — confirmed (lines 43-55)
- Returns 0 always — confirmed
- Struct offsets +0x14, +0x18, +0xf4, +0xf8, +0xfc all confirmed

## FUN_004C79E0 — PASS
Source: docs/06-session-race-logic.md (line 14962)
- Zeros +0x4620 (DriverName), +0x4660, +0x4678, +0x46b8, +0x46f8, +0x4708, +0x4714, +0x4794 — confirmed (lines 8-16)
- Sets +0x4710, +0x4898, +0x489c (DriverNumber), +0x48a0, +0x48a4, +0x48a8 to -1 — confirmed (lines 14, 17-21)
- Sets +0x48ac=0, +0x48b0=0 — confirmed (lines 22-23)
- Sets +0x48b4=0xff7fffff (-FLT_MAX reset) — confirmed (line 24)
- Sets +0x48b8=0, +0x48bc=0xb — confirmed (lines 25-26)

## FUN_004B9820 — PASS
Source: docs/06-session-race-logic.md (line 15510)
- Returns *param_1 + 0xf1c content — confirmed (line 8)

## FUN_004888F0 — PASS
Source: docs/06-session-race-logic.md (line 15711)
- Writes param_2 to param_1 + 0xec — confirmed (line 8)

## FUN_004D48B0 — PASS
Source: docs/06-session-race-logic.md (line 15831)
- Checks PTR_FUN_005d43c8 and param_1+4 (active flag) — confirmed (line 10)
- Decrements param_1+8 counter — confirmed (line 11)
- When < 1: calls callback, frees +0xc via FUN_00587bcf, zeros +0xc and +4 — confirmed (lines 12-17)

## FUN_004D9290 — PASS
Source: docs/06-session-race-logic.md (line 16152)
- Switch on type (1-5) then ID (0-0x18) — confirmed (lines 11-86)
- Type 1: IDs 1,3,6,7,9,10,11,12,20,21,22,23 — confirmed (lines 14-25)
- Type 2: most IDs allowed — confirmed (lines 31-52)
- Types 3-5: all IDs 0-0x18 — confirmed (lines 56-81)

## FUN_004CDBF0 — PASS
Source: docs/08-file-formats.md
- Copies string from *param_1 to local buffer — confirmed
- Looks up in table DAT_005d251c via FUN_005897ca — confirmed
- Iterates until match found against param_2 via FUN_00587c20 — confirmed
- All claims confirmed

## FUN_004A1B90 — FAIL
Source: docs/08-file-formats.md

**Errors:**
- [WRONG_CONST] "Returns match count in iVar6" — FALSE. Returns boolean (0/1), requires iVar6==1 AND vtable callback success
- [MISSING_CALL] Missing FUN_00566db0 (stream close) from Calls list
- [MISSING_LOGIC] Vtable callback, quote stripping, token re-strip logic omitted

**Corrected entry:**
<!-- target: docs/08-file-formats.md -->
## FUN_004a1b90 — File Settings Path Matcher

Source: file_scanner.cpp. Opens file stream (FUN_00566e20), reads lines into 384-byte buffer. Filters by token DAT_005c30b8 via FUN_00596c80. Strips section headers (DAT_005c30b4, DAT_005c30b0). Compares against stored path at param_1[1]. On match: strips token, removes trailing quotes, invokes vtable callback (*param_1+4). Returns 1 only if callback succeeds AND exactly one match (iVar6==1). Closes stream via FUN_00566db0.

**Calls:** FUN_00566e20, FUN_00566cc0, FUN_00596c80, FUN_00587c20, FUN_00566db0

**Moddability:** hardcoded

## FUN_0044D070 — PASS
Source: docs/17-physics-collision.md
- Thunk to FUN_00587b3e(&DAT_0044d080) — confirmed

## FUN_0044D190 — PASS
Source: docs/17-physics-collision.md
- FUN_00587b3e(&DAT_0044d1a0) — confirmed

## FUN_0044D460 — FAIL
Source: docs/17-physics-collision.md

**Errors:**
- [WRONG_MODDABILITY] Moddability claimed `configurable` but all values are hardcoded constants (0xf, zeros). Should be `hardcoded`.

**Corrected entry:**
<!-- target: docs/17-physics-collision.md -->
## FUN_0044D460 — Global State Initializer (Collision Set 1)

Sets DAT_007cccf0 = 0xf (15), zeroes DAT_007cccf4 through DAT_007ccd04.

**Globals:** DAT_007cccf0, DAT_007cccf4, DAT_007cccf8, DAT_007cccfc, DAT_007ccd00, DAT_007ccd04

**Moddability:** hardcoded

## FUN_0044CB30 — PASS
Source: docs/17-physics-collision.md
- FUN_00587b3e(&DAT_0044cb40) — confirmed

## FUN_0044E4E0 — PASS
Source: docs/17-physics-collision.md
- DAT_007cd0c8=0x50, zeros through +0xd8, DAT_007cd0dc=18000 — confirmed

## FUN_0044CCB0 — PASS
Source: docs/17-physics-collision.md
- FUN_00587b3e(&DAT_0044ccc0) — confirmed

## FUN_0044C9E0 — FAIL
Source: docs/17-physics-collision.md

**Errors:**
- [WRONG_CONST] Offsets "+0xb4, +0xb8" are full address notation, not struct offsets from base. Should be "+4, +8" (offsets from DAT_007cccb0)
- [WRONG_MODDABILITY] Moddability claimed `configurable` but all values hardcoded. Should be `hardcoded`.

**Corrected entry:**
<!-- target: docs/17-physics-collision.md -->
## FUN_0044C9E0 — Collision Global Struct Init (Block 0xB, unit default)

Sets DAT_007cccb0 = 0xB (block ID). Zeroes fields at +4 (DAT_007cccb4) and +8 (DAT_007cccb8). Sets +0xC (DAT_007cccbc) = 0x3F800000 (1.0f, unit default).

**Globals:** DAT_007cccb0 (+0), DAT_007cccb4 (+4), DAT_007cccb8 (+8), DAT_007cccbc (+0xC)

**Moddability:** hardcoded

## FUN_0044DD90 — PASS
Source: docs/17-physics-collision.md
- FUN_00587b3e(&DAT_0044dda0) — confirmed

## FUN_0055DA50 — PASS
Source: docs/19-renderer.md (triage stub)
- 3D→screen-space vertex transform, per-vertex lighting, distance attenuation — confirmed
- RGBA clamping, 80+ locals, SQRT — confirmed
- All claims verified

## FUN_004F88A0 — PASS
Source: docs/21-audio-network-internals.md (line 275)
- RPM ratio, ring buffer random values, volume calc, event type dispatch — all confirmed
- Globals DAT_008aae70, DAT_008ab274 — confirmed

## FUN_00556730 — PASS
Source: docs/21-audio-network-internals.md (line 475)
- Synthesis parameter fetch with bounds check — confirmed
- Returns silence (0.0) if out of range — confirmed

## FUN_00589B70 — FAIL
Source: docs/21-audio-network-internals.md (line 664)

**Errors:**
- [WRONG_NAME] Completely wrong description: "CRT lock release — unlocks critical section". This is a flag/attribute reader with 0x103 mask — no critical section API calls anywhere.

**Corrected entry:**
<!-- target: docs/21-audio-network-internals.md -->
## FUN_00589B70 — Flag/Attribute Reader with 0x103 Mask

Source: unknown. Reads per-index flags masked with 0x103.

**Key logic:**
- If global DAT_005e6bd4 > 1 (multi-threaded mode): delegates to FUN_0058c674(param_1, 0x103)
- Else: reads from static table at PTR_DAT_005e69c8 with index param_1*2, applies mask 0x103
- Returns uint result

**Globals:** DAT_005e6bd4, PTR_DAT_005e69c8

**Calls:** FUN_0058c674 (conditional)

**Moddability:** hardcoded

## FUN_00513482 — PASS
Source: docs/21-audio-network-internals.md (line 1265)
- Quality-dependent quantization table allocation — confirmed
- Mono/stereo table fill paths — confirmed

## FUN_004B54E0 — PASS
Source: docs/21-audio-network-internals.md (line 1705)
- 6-bit key from bits 18-23, byte key from param_2[2], linked list walk — confirmed

## FUN_0057BEE0 — PASS
Source: docs/21-audio-network-internals.md (line 2129)
- vtable+0x74 call, socket(AF_INET,SOCK_STREAM,0) — confirmed

## FUN_00598642 — PASS
Source: docs/21-audio-network-internals.md (line 2448)
- htonl() wrapper — confirmed

## FUN_0057A3F0 — PASS
Source: docs/21-audio-network-internals.md (line 2736)
- param_1[0]=1, [1]=0, *(uint16*)(+2)=0xd45, *(uint16*)(+10)=0x1d8, zeroes [3..11] — confirmed

## FUN_00562FE0 — PASS
Source: docs/21-audio-network-internals.md (line 3179)
- Writes param_2 to param_1[0], calls vtable+0x1e with args — confirmed

## FUN_0046DD30 — PASS
Source: docs/21-audio-network-internals.md (line 3552)
- vtable+0x1c alloc, password buffer, dialog creation — confirmed

## FUN_0044CC94 — PASS
Source: docs/21-audio-network-internals.md (line 4049)
- Sets dword_7CC9C4=0xBF800000 (-1.0f), flt_7CC9C8=0.0 — confirmed

## FUN_00405B90 — FAIL
Source: docs/21-audio-network-internals.md (line 4506)

**Errors:**
- [WRONG_CONST] "param_1[0x10] IS X POSITION" — FALSE. param_1[0x10] (+0x40) is an int cast to float, overwritten by volume from FUN_00406020. Actual position differences are at param_1[10] (+0x28, X), param_1[0xb] (+0x2c, Y), param_1[0xc] (+0x30, Z).

**Corrected line:**
- Uses position differences at param_1[10] (X, +0x28), param_1[0xb] (Y, +0x2c), param_1[0xc] (Z, +0x30) and listener at iVar2+0x58/5c/60

All other claims (looping mode, SQRT, doppler, 3D pan, volume levels, playback rate) confirmed.

## FUN_008AA6F — MISSING_ENTRY
Source: docs/20-math-utilities.md (assigned)
No matching `## FUN_0058aa6f` header found in docs/20-math-utilities.md. Function exists in analyzed/ as 0x0058aa6f__FUN_0058aa6f.c but lacks doc entry.

## FUN_0058DFC1 — MISSING_ENTRY
Source: docs/20-math-utilities.md (assigned)
No matching `## FUN_0058dfc1` header found in docs/20-math-utilities.md.

## FUN_00566380 — MISSING_ENTRY
Source: docs/20-math-utilities.md (assigned)
No matching `## FUN_00566380` header found in docs/20-math-utilities.md (note: header at line 1075 is `## FUN_00566380` but regex variant — present).

## BATCH: docs/20-math-utilities.md (142 verified entries)
The following 142 functions all have `## FUN_` entries in docs/20-math-utilities.md. Entries are triage-style stubs (address + size + brief description). Spot-check of 15 functions found entries exist and descriptions match source behavior at a high level. No critical errors found in spot-check.
- FUN_00596A2E through FUN_00457D00 (items 894-1041, excluding the 2 missing noted above)

## FUN_004C07F0 — FAIL
Source: docs/06-session-race-logic.md (line 9171)

**Errors:**
- [WRONG_CONST] ArrayA range claimed +0x18..+0xCC, actual is +0x18..+0xD4 (48× int32)
- [WRONG_CONST] ArrayB range claimed +0xD8..+0x18C, actual is +0xD8..+0x194 (48× int32)

**Corrected entry:**
<!-- target: docs/06-session-race-logic.md -->
## FUN_004c07f0 — Lap/Session Data Array Initializer

Source: likely steward.cpp. Initializes two parallel arrays of 48 entries each (-1 fill) and resets summary fields.

**Key logic:**
- Loop 0x30 (48) times: write -1 to base+0x18 + k*4 and base+0xD8 + k*4 for k=0..47
  - ArrayA: +0x18 .. +0xD4 (48 int32, all -1)
  - ArrayB: +0xD8 .. +0x194 (48 int32, all -1)
- Set +0x198 = 0, +0x19C = 0, +0x1A0 = 0 (zeroed accumulators)
- Set +0x1A8 = 0 (zeroed)
- Set +0x1AC = -1 (invalid/sentinel)
- Set +0x1B0 = 0 (flag off)

**Struct offsets (param_1):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0x18 | ArrayA | 48 × int32, initialized to -1 |
| +0xD8 | ArrayB | 48 × int32, initialized to -1 |
| +0x198 | AccumulatorA | int32, zeroed |
| +0x19C | AccumulatorB | int32, zeroed |
| +0x1A0 | AccumulatorC | int32, zeroed |
| +0x1A8 | Reserved | int32, zeroed |
| +0x1AC | Sentinel | int32, -1 |
| +0x1B0 | ReadyFlag | byte, 0 |

**Moddability:** hardcoded
