# Cross-Validation Results — worker_L_batch2

## 40 functions validated against source (docs/06-session-race-logic.md)

---

### FUN_0047E400 — Race Laps Getter

**Current doc:** docs/06-session-race-logic.md (line 989)
**Issues found:** none
**Details:**
- Source calls FUN_004c5840(0) → gate check, FUN_005679c0("RaceLaps") → INI key lookup, FUN_00567970() → get value, FUN_00488b40(value) → process
- Doc lists all calls and logic correctly
- All claims verified

---

### FUN_00463EF0 — Season/Championship State Init

**Current doc:** docs/06-session-race-logic.md (line 1335)
**Issues found:** 2
**Details:**
- Doc says "Sets DAT_007d0990 from positive bias" but source also handles negative case: if DAT_007d099c < 0 → DAT_007d0990 = DAT_007d099c (negative)
- Doc omits that this code only runs when DAT_007d0410 == 5 (RaceMode 5). Not noted as a condition in doc.
- Doc omits first conditional: if *param_1+0x1d0 != 1 → zero *(param_1+0x3fc4). This is the "replay guard" path — doc says "If no replay" but doesn't detail the +0x3fc4 zeroing.
- Globals DAT_007ce260, DAT_007d0410, DAT_007d0a44, DAT_007d0990 — all verified present in source

---

### FUN_004A0590 — Session Type Dispatch

**Current doc:** docs/06-session-race-logic.md (line 1620)
**Issues found:** none
**Details:**
- Switch mapping 1→2,2→3,3→4,4→5,5→6,6→7 confirmed in source
- RaceMode 4 check (DAT_007d0410==4) and championship condition (FUN_004c2850() != 0) confirmed
- SessionType 7 → FUN_004a09a0(), else → FUN_004c15a0() confirmed
- Default case returns 1, handled cases return 0 after FUN_0042cf10() call
- All calls verified

---

### FUN_004C29F0 — UpdateRaceStateScoring

**Current doc:** docs/06-session-race-logic.md (line 1906)
**Issues found:** 2
**Details:**
- Doc says "Reads player position" but source reads *(DAT_007c54e8 + 0x4058) stored as iVar1. This is a vehicle struct field at +0x4058, not necessarily a position value.
- Doc says "AI adjustment via AIDifficultySlider" but source shows FUN_004c2dc0((float)DAT_007d01a0) only called when DAT_007d0990 > 0 — conditional, not unconditional
- Doc says iVar1 == 1 → "first" but +0x4058 could be any vehicle state field (driver index, position, state flag)
- Calls list matches source exactly

---

### FUN_004D88D0 — Structure Init

**Current doc:** docs/06-session-race-logic.md (line 2189)
**Issues found:** none
**Details:**
- Source: 25 iterations (0..24) at +0x10 via FUN_004d9290/FUN_004daea0 — confirmed
- 3 iterations at +0x74 via FUN_004db420 — confirmed
- +0xc set from FUN_004dc220 (conditional on FUN_004d93e0 check) — confirmed
- +0xd8 set from FUN_004dc290 — confirmed
- All calls verified

---

### FUN_00418E50 — HUD/Display Data Reset

**Current doc:** docs/06-session-race-logic.md (line 2516)
**Issues found:** none (minor terminology)
**Details:**
- Source confirms: 0x68 iterations, gate on DAT_007d0308 != 0 and DAT_007cf3c8 != DAT_0059e440
- Values set: -1 (0xffffffff), 0x7fffffff, 0, -1.0f (0xbf800000), 0, 0 — matches doc
- Byte flag array at +0x9dc cleared — confirmed
- Calls FUN_00418ee0 after loop — confirmed
- Zeroes at +0x4f0/+0x4f4/+0x4f8 — confirmed
- Doc says "stride 0x30?" — this is uncertain in doc, source shows stride 4 (int-by-int), so the entry stride interpretation remains ambiguous

---

### FUN_004A0630 — Session/Scene Init Chain

**Current doc:** docs/06-session-race-logic.md (line 2768)
**Issues found:** 1
**Details:**
- Doc lists calls: FUN_0042cf10, FUN_004c2780, FUN_004c2810, FUN_004c55b0 — but source also calls FUN_004186a0 and FUN_004a09f0 at end
- Doc missing FUN_004186a0 and FUN_004a09f0 from Calls section
- Globals DAT_007ce5ec, DAT_005eb10c verified
- Track path default &DAT_005ea438 verified

---

### FUN_0058CF35 — Buffered byte write

**Current doc:** docs/06-session-race-logic.md (line 2952, triage entry)
**Issues found:** none
**Details:**
- Triage entry correctly describes: buffered byte write, overflow handling, global/local buffer contexts, error state management
- Source shows flag manipulation (0x82, 0x40, 0x10), buffer expansion fallback, callback invocation — matches triage description
- No detailed claims to verify in triage entry

---

### FUN_00594624 — Base-N decode (claimed)

**Current doc:** docs/06-session-race-logic.md (line 3115, triage entry)
**Issues found:** 1
**Details:**
- Triage claims "Base-N decode from string buffer with byte extraction" / "Data decoding for asset loading"
- Source shows linked-list manipulation with prev/next pointers (+0x4/+0x8), free-list management, bit flag operations, size header manipulation with sentinel values (0xf1), and memory offset calculations — this is a custom heap allocator / memory manager, not a decoder
- **Misclassification:** Should be "Memory — Allocator" or "Heap — Custom Allocator", not encoding/decoding

---

### FUN_00587730 — Linked-list node find by field match (claimed)

**Current doc:** docs/06-session-race-logic.md (line 3315, triage entry)
**Issues found:** 1
**Details:**
- Triage claims "Linked-list node find by field match" / "List search"
- Source shows: reads count from FUN_00586a80(), checks buffer capacity at param_1+0x414+0x80, copies header byte with encoded size, copies data blocks from two sources (param_2+0x14 data and FUN_00586a90() sorted data), updates buffer position counter at param_1+0x400
- This is a serialization/buffer packing function, not a list search
- **Misclassification:** Should be "Data — Serialization" or "Buffer — Packed write"

---

### FUN_00596773 — WideChar string processing

**Current doc:** docs/06-session-race-logic.md (line 3515, triage entry)
**Issues found:** none
**Details:**
- Source confirms MultiByteToWideChar conversion with codepage, PTR_DAT_005e69c8 character table lookup, DAT_008d3f38 flag check, DAT_008d3f48 codepage
- Triage: "WideChar string processing with fallback" — matches

---

### FUN_0057AA50 — Global state flags clear

**Current doc:** docs/06-session-race-logic.md (line 3715, triage entry)
**Issues found:** none
**Details:**
- Source: zeros DAT_008d3bfc, DAT_008d3c00, DAT_008d3c04, DAT_008d3c08
- Triage: "Global state flags clear (zero 4 fields)" — matches

---

### FUN_004B5E50 — Hash Bucket List Manager

**Current doc:** docs/06-session-race-logic.md (line 4301)
**Issues found:** 1
**Details:**
- Doc says "Processes 64 hash buckets" but source shows local_4 = 0x68 = **104** iterations
- Doc also says "piVar6 walks 104 iterations (0x68)" which is correct, but the summary says 64 buckets — contradictory
- The stride is 4 ints (0x10) per iteration, covering 104 × 0x10 = 0x680 bytes
- Doc says "64 entries × 4 pointers × 4 bytes = 0x400 bytes" — wrong. 104 × 4 ints = 416 ints = 0x680 bytes
- Rest of logic description (key matching, node removal, reallocation, freeing) verified against source

---

### FUN_004B6940 — Pitstop Action Set

**Current doc:** docs/06-session-race-logic.md (line 4771)
**Issues found:** none
**Details:**
- Source: FUN_004b7860(0), FUN_004b69f0() → inactive branch (FUN_004b69a0) or active branch (zero +0x9bc/+0x9b8, FUN_004b4e10)
- Write: *(*(param_1+0x9b8)*0xb0 + 0x6c + *(param_1+0x9b0)) = param_2
- Offsets +0x9b0, +0x9b8, +0x9bc verified against source
- All calls verified

---

### FUN_004E87E0 — Brake Thermal Model (Temperature Clamp)

**Current doc:** docs/06-session-race-logic.md (line 5177)
**Issues found:** none
**Details:**
- Source formula: fVar1 = *(param_1+0x3500) - (*(param_1+0x34b8)**(param_1+0x3a58) + *(param_1+0x3a5c)**(param_1+0x34c4) + *(param_1+0x3a60)**(param_1+0x34d0))
- Zero-guard on +0x39c8 and +0x39ac verified
- fVar2 = (((fVar1² × +0x3d44 × +0x3d40) / +0x39c8) - +0x39a8) / +0x39ac
- Clamp to ≥0 and ≤1.0 (_DAT_0059e43c) confirmed
- All offsets (+0x3500, +0x34b8, +0x3a58/5c/60, +0x39c8, +0x39ac, +0x3d40/44, +0x39a8) verified

---

### FUN_00545340 — LinkedListNodeFinder

**Current doc:** docs/06-session-race-logic.md (line 5611)
**Issues found:** none
**Details:**
- Source: starts at param_1+0x100, if null tries param_1+0x108
- Children via +0xec link, siblings via +0x4c link — verified
- Falls through to next sibling at +0x104 — verified
- Iterates until param_2 matches — verified
- Depth-first traversal confirmed

---

### FUN_0042ED30 — AI Path Node Delegate

**Current doc:** docs/06-session-race-logic.md (line 6109)
**Issues found:** none
**Details:**
- Source: 12 bytes, calls FUN_0042dd80(*(param_1+0x1644))
- Offset +0x1644 verified
- All doc claims verified

---

### FUN_0054BDC0 — UI Element Bitfield State Setter

**Current doc:** docs/06-session-race-logic.md (line 6661)
**Issues found:** none
**Details:**
- Linked list at param_1+0x204, following +0x10 next — verified
- Sub-elements at stride 0x10, count at +0x118 — verified
- param_2 & 0x20 check and branches verified
- Color encoding with DAT_008b8f28 + 0x1b0 counter verified
- State callback dispatch (FUN_0055d900/5e320/5da50/5eb30) verified
- All calls verified

---

### FUN_0042A740 — Track Parameter Minimum Clamp

**Current doc:** docs/06-session-race-logic.md (line 7075)
**Issues found:** 1
**Details:**
- Source: `if (*(float*)(param_1+0x4484) < _DAT_0059e7ec) { *(param_1+0x4484) = 0x40a00000; }`. The threshold for floor clamp is _DAT_0059e7ec (a global), not 5.0f directly.
- Doc says "If *(param_1+0x4484) < 5.0f (0x40a00000): sets to 5.0f" — the _value set_ is 5.0f (0x40a00000), but the _threshold_ is _DAT_0059e7ec, not 5.0f
- Doc globals: `_DAT_0059e7ec — compared constant (5.0f encoded indirectly)` — this implies _DAT_0059e7ec equals 5.0f, which is unverified. The source compares against _DAT_0059e7ec and sets to 0x40a00000. _DAT_0059e7ec could be any value and the floor is hardcoded 5.0f.
- **Issue: doc mislabels _DAT_0059e7ec as "5.0f encoded indirectly" — it's a separate threshold, not 5.0f**

---

### FUN_004ED420 — VehicleGeometryProximityTest

**Current doc:** docs/06-session-race-logic.md (line 7438)
**Issues found:** none
**Details:**
- Rotation matrix at +0x34b0/0x34bc/0x34c8 verified
- 4 bounding elements at +0x828 (int flags stride 0x128) and +0x3594 (float position stride 0xf8) verified
- Sphere hit test logic verified
- Closest-point-on-ray fallback verified
- param_6 contact normal computation verified
- All calls (FUN_004ea930, 004ed750, 004ed710, 004ed380, 004ed7b0) verified
- Offsets table complete and correct

---

### FUN_00537F30 — BitstreamWriteBits

**Current doc:** docs/06-session-race-logic.md (line 8036)
**Issues found:** none
**Details:**
- Bit accumulator at +0x16ab (ushort), bits-left at +0x16ad (int) — verified
- >13 branch: packs into buffer at (param_1+8)[param_1+0x14], writes 2 bytes, decrements by 13, stores remaining bits — verified
- Else branch: accumulates, increments bits-left by 3 — verified
- Calls FUN_005397a0(param_2, 1) in both paths — verified
- Offsets +0x008, +0x014, +0x16ab, +0x16ad verified

---

### FUN_004A8B80 — StaticInitBulk

**Current doc:** docs/06-session-race-logic.md (line 8498)
**Issues found:** none
**Details:**
- Source (557 lines) confirms: FUN_004c1700() → 4×16 calls to FUN_004aa1b0() → multiple FUN_00414370() calls → 0x2c loop → 0x30 loop → FUN_004aa170() loops → FUN_004b2100()
- Doc description matches source pattern accurately

---

### FUN_004F1890 — Speed/Value Setter with Global Mirror

**Current doc:** docs/06-session-race-logic.md (line 8915)
**Issues found:** none
**Details:**
- Source: *(param_1+0x3978)=param_2; if *(param_1+0x32bc)==0 → _DAT_007c75c4=(double)param_2
- Offsets +0x3978, +0x32bc verified
- Global DAT_007c75c4 verified

---

### FUN_0042E290 — PositionIndexClamp

**Current doc:** docs/06-session-race-logic.md (line 9384)
**Issues found:** 1
**Details:**
- Doc claims struct offset +0x18 = MinIndex (int)
- Source uses only: *(int*)(param_1+0x14) for CurrentIndex, *(int*)(param_1+0x10) as MaxIndex bound, *(int*)(param_1+2) = *(int*)((char*)param_1+0x10) as bounds check `if (*(int*)(param_1+2) + -1 <= iVar2)` — this is a MaxIndex-1 check, not a MinIndex field
- **Offset +0x18 is never read in this function.** The doc's claim of +0x18 MinIndex is unsupported by source.
- Note: source reads double* param_1, so param_1+1 = +0x8 (ScaleFactor), param_1+2 = +0x10 (MaxIndex)
- _DAT_0059e880 and _DAT_0059e420 globals verified

---

### FUN_0042E4A0 — Weighted-sum comparator with binary adjustment

**Current doc:** docs/06-session-race-logic.md (line 9742)
**Issues found:** none
**Details:**
- Source: (iVar2 * param_1[1] + *param_1) * _DAT_0059e9f0 < (iVar1 * param_2[1] + *param_2)
- param_3 controls: 0→increment param_1 index; nonzero→decrement param_2 index
- Guard: if param_3 == 0 or param_2 index < 1 → increment param_1 index
- Stops when param_1 sum >= param_2 sum
- All verified against source

---

### FUN_004D1100 — Conditional delegate dispatch

**Current doc:** docs/06-session-race-logic.md (line 10186)
**Issues found:** none
**Details:**
- Source: if *(param_1+0x48a4) < 0 → FUN_004c6f10(); FUN_00403f70(*(param_1+0x48a4), param_2, param_3)
- Offset +0x48a4 verified
- Calls FUN_004c6f10, FUN_00403f70 verified

---

### FUN_004EF6C0 — Coordinate Transform with Offset

**Current doc:** docs/06-session-race-logic.md (line 10591)
**Issues found:** none
**Details:**
- Source: FUN_00566e40(), FUN_004ef680(&local_3c)
- Reads position from +0x34d4(px), +0x34d8(py), +0x34dc(pz) — verified
- Adds param_2 offset components — verified
- Computes: output = (position + offset) - (matrix * vector + position) — verified
- Writes result to param_4[0..2] — verified

---

### FUN_0054FB70 — Linked List Flag Bit Extraction

**Current doc:** docs/06-session-race-logic.md (line 10951)
**Issues found:** none
**Details:**
- Source: `return ((int)*(char *)(*(int *)(param_1 + 0x204) + 0x14) & 0x40U) >> 6;`
- Linked list head at param_1+0x204, byte at head+0x14, bit 6 test — all verified

---

### FUN_00421380 — CountActiveEntitiesByState

**Current doc:** docs/06-session-race-logic.md (line 11439)
**Issues found:** none
**Details:**
- Outer loop: iVar3 < FUN_004c1370() — verified
- Inner loop: checks state == 10 at *(int*)(base + 0xd8 + i*4) — verified (iVar1 starts at 0xd8, increments by 4)
- Returns 0 if param_1 is null — verified
- All calls (FUN_004c2850, FUN_004c1370, FUN_004c13a0, FUN_004c0a20, FUN_00566810, FUN_004c11d0) verified

---

### FUN_00447E00 — Position/Lap State Update

**Current doc:** docs/06-session-race-logic.md (line 11888)
**Issues found:** 1
**Details:**
- Doc says "param_2 > 0: sets +0x1ef8 to 2*(prev < new) - 1" but:
  - The else branch handles all values except -1 and 0 (both positive and negative), not just "param_2 > 0"
  - The expression uses *(param_1+0x1ef0) (Counter field, just set to 0), not "prev" 
- Branch for param_2 == -1 correctly documented
- Branch for param_2 == 0 correctly documented
- All offsets and logic flow verified against source
- Minor: the comparison is `0 < param_2` using +0x1ef0 which is always 0 at this point, making it effectively a sign test

---

### FUN_004674E0 — Menu Command Dispatcher

**Current doc:** docs/06-session-race-logic.md (line 12251)
**Issues found:** none
**Details:**
- Switch on command ID at param_1+0x174 verified
- Cases 0x1be, 0x1bf-0x1c2, 0x1c3-0x1c6, 0x1c7-0x1ca all verified
- DAT_007c737c used in case 0x1be (not listed in doc globals but minor omission)
- DAT_007c7378, DAT_007c7380/7384, DAT_007d048c verified
- All calls verified

---

### FUN_00508867 — TextureEncode16BitMatrix

**Current doc:** docs/06-session-race-logic.md (line 12650)
**Issues found:** none
**Details:**
- param_1+0x1048 conditional → FUN_00506ce2 verified
- Color multiplier at param_1+0x2c verified
- DAT_005adb18/1c/20 color matrix coefficients verified
- DAT_0059fec8 scale factor verified
- 16-bit packing (low byte weighted sum, high byte A*coeff) verified
- Loop count at param_1+0x1058 verified

---

### FUN_00507EE4 — Texture Encoder RGBA 4-4-4-4

**Current doc:** docs/06-session-race-logic.md (line 13103)
**Issues found:** none
**Details:**
- param_1+0x1048 → FUN_00506ce2 verified
- FUN_00507473 (dither init) called verified
- Loop count at param_1+0x1058 verified
- Dither matrix at param_1+0x2c, indexed by (param_3&3) + (param_2&3)*8 + (uVar9&3) — verified
- _DAT_0059e8d8 (15.0f) quantization scale verified
- 4-4-4-4 packing: ((((A<<4|R)<<4|G)<<4|B) verified

---

### FUN_0051BF23 — PlaybackBufferAlloc

**Current doc:** docs/06-session-race-logic.md (line 13501)
**Issues found:** none
**Details:**
- 0x1c-byte allocation via vtabled allocator, stored at param_1+0x188 — verified
- Vtable set to FUN_0051be7d — verified
- Zeroes fields at indices 2 and 3 — verified
- Flag at param_1+0x4a condition — verified
- param_2==0: alloc via vtable+8 of size *(param_1+100)**(param_1+0x5c) — verified
- param_2!=0: FUN_00515927 then alloc via vtable+0x10 — verified
- puVar2[4] from param_1+0x110 — verified

---

### FUN_0042BD60 — SeasonScoringReset

**Current doc:** docs/06-session-race-logic.md (line 13866)
**Issues found:** none
**Details:**
- DAT_007c5690 = 0 verified
- Loop: DAT_005ec6e4 base, stride 0x48c0, until address >= 0x7c54e4 — verified
- For each: FUN_004c6960(iVar2), FUN_004ef5a0(0xffffffff,0) — verified
- All claims verified

---

### FUN_005001D0 — FieldCompareConstant

**Current doc:** docs/06-session-race-logic.md (line 14304)
**Issues found:** none
**Details:**
- Source: returns 1 if *(float*)(param_1+0x1bc) != _DAT_005ad348
- Offset +0x1bc verified
- Global DAT_005ad348 verified
- All claims verified

---

### FUN_004A5E60 — State/Phase Setter

**Current doc:** docs/06-session-race-logic.md (line 14749)
**Issues found:** none
**Details:**
- *(param_1+0x184)=4, *(param_1+0x180)=1 — verified
- If *(param_1+0x14) != 0 → FUN_004a3fe0() — verified
- Offsets +0x180, +0x184, +0x14 verified

---

### FUN_004B86E0 — AngleClampWrap

**Current doc:** docs/06-session-race-logic.md (line 15230)
**Issues found:** none
**Details:**
- Stores prev at +0xf3c, sets new at +0xf38 — verified
- +0xf81 != 0 (clamp mode): clamps between +0xf30 (min) and +0xf34 (max) — verified
- +0xf81 == 0 (wrap mode): infinite loop reflecting value when exceeding bounds — verified
- All offsets (+0xf30, +0xf34, +0xf38, +0xf3c, +0xf81) verified

---

### FUN_00472CC0 — UI String Format + Display

**Current doc:** docs/06-session-race-logic.md (line 15641)
**Issues found:** none
**Details:**
- Source: FUN_00487010(**(param_1+0x31c)), FUN_0058815f(local_20,uVar1), FUN_0048b810(local_20)
- All three calls verified

---

### FUN_00499580 — Linked List Destroy (vtable destructor variant)

**Current doc:** docs/06-session-race-logic.md (line 15765)
**Issues found:** none
**Details:**
- Walks linked list at *param_1 — verified
- For each node: piVar2 = node, piVar1 = piVar2[1] (next pointer) — verified
- If node[3] flag != 0 and *node != null: calls vtable destructor on data — verified
- Frees node via FUN_00587bcf — verified
- Zeros param_1[0..3] (4 list fields) — verified

---

## Summary

| Status | Count |
|--------|-------|
| No issues | 28 |
| Issues found | 8 |
| Misclassified (triage) | 2 |

**Key issues to correct:**
1. `FUN_00594624` — triage misclassified as "Base-N decode", actually a custom heap allocator
2. `FUN_00587730` — triage misclassified as "linked-list find", actually serialization/buffer pack
3. `FUN_004B5E50` — doc says 64 buckets, source shows 104 (0x68)
4. `FUN_0042E290` — doc claims +0x18 MinIndex not used in source
5. `FUN_00463EF0` — incomplete about RaceMode 5 condition and negative bias handling
6. `FUN_004A0630` — missing FUN_004186a0 and FUN_004a09f0 from Calls section
7. `FUN_0042A740` — _DAT_0059e7ec is threshold, not "5.0f encoded indirectly"
8. `FUN_00447E00` — else branch handles all non-{-1,0} values, not just positive
