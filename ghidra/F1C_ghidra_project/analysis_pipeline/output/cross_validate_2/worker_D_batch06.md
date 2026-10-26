# Cross-Validation Results: Batch 06 (43 functions)
# Target: docs/06-session-race-logic.md
# Generated: 2026-07-15

---

## FUN_004BC4E0 — PASS

**Summary:** All claims verified against .c source. Globals correct (DAT_008acf8c, DAT_008acf90, DAT_008acf94, DAT_008acfa0, DAT_007c56a4, DAT_007c56a8, DAT_007ce814 all present in source with correct usage). Key logic matches: param_4 != 0 → sector timing, param_4 == 0 → lap completion. Switch on DAT_007c56a4 with cases 0/1-6/7. Formation lap via FUN_0042d140 confirmed. Penalty countdown array at param_1+0x10 with stride 2 (8 bytes). DAT_008acfa0 set at half-distance. FUN_004bc240 called at end.

**Minor note:** Doc says "Qualifying (5)" but per doc's own session table, 5=Practice5, 6=Qualifying. Code checks `DAT_007c56a4 == 5` which is Practice5 per table, not Qualifying. DSQ-for-time-limit logic inside case 1-6 block with inner check for `== 5`. Type labeling discrepancy; behavior description functionally correct.

---

## FUN_00468BF0 — PASS

**Summary:** All claims verified. Source confirms: initializes buffers to DAT_005c694c, compares DAT_007ce668 against param_1+0x17c, calls FUN_00566650 on mismatch. Sets DAT_007d2dc8 = DAT_007d2dc0. Iterates linked list, calls FUN_004c5840, FUN_005679c0, FUN_00567970 for name lookup. Formats via FUN_0058815f with "%i:%06.3f". Writes 4 HTML sections via FUN_00487010(10/0xb/0xc) and FUN_00489600. Globals DAT_007d2dc0, DAT_007d2dc8, DAT_007ce668 confirmed. Calls list matches.

---

## FUN_00463BC0 — PASS

**Summary:** 35-line function fully verified. Checks `*(*param_1 + 0xc5)`, sets DAT_007d0410=5 with min/max clamping from DAT_007d0418/DAT_007d041c, sets DAT_007d0f94=1, calls FUN_0057a920, checks game existence via FUN_00463c60, routes to "SELECTCIRCUITPAGE" or "MULTIPLAYER_CREATEGAME". All 4 doc claims verified.

---

## FUN_0049B7A0 — PASS

**Summary:** 55-line source verified. Calls FUN_004f1aa0 for controller check. Controller active → binary gear mask. Non-controller: compares speed ratio against DAT_0059e824, DAT_005acaf0, DAT_005acaec, DAT_005acae8 thresholds. Returns 0/1/3/7/0xF matching doc's threshold values. All globals confirmed in source.

---

## FUN_004BC060 — PASS

**Summary:** 28-line function verified. Guards on DAT_007c56a4 == 7. Ring buffer check DAT_0083ee60 < 0x3ff. If param_2 != 0: event 0x1a via FUN_004b33b0(4, 0x1a, ...). Else: event 0x1b. All doc claims match.

---

## FUN_004D1D80 — PASS

**Summary:** 166-line source verified. Phase-based processing: reads time from param_1+0x120 minus _DAT_008afe98. Phase 1: gap computation via FUN_004e9630, stores distance at +0x4044. Phase 2: overtake detection. Phase 3: ring buffer write via FUN_004b33b0. Calls list matches: FUN_004e9630, FUN_004b33b0. DAT_005c329c (VehicleCount) and DAT_007c54f0 confirmed.

---

## FUN_0042BC80 — PASS

**Summary:** 67-line source verified. Scans season database at &DAT_005ec6d8 with stride 0x48c0 for entries with +13000 != -1. Stores valid pointers in DAT_007c54f0. Fills remaining slots via re-scan. Resets DAT_007c54dc and DAT_007c54e4 to 0. Finds indices matching DAT_007c54e0 and DAT_007c54e8. Returns active count. All 6 doc claims verified.

---

## FUN_004643C0 — FAIL

**Error tags:**
- [GLOBALS_INCOMPLETE] Doc globals: only lists `_DAT_008afe98`. Source also reads DAT_0059e440 (zero threshold) and writes to *param_1+0x37c, *param_1+900.
- [CALLS_INCOMPLETE] Doc lists: FUN_00462370, FUN_0057a900, FUN_004a0d30, FUN_004a0db0, FUN_004a0490, FUN_00460cb0. Source also calls: FUN_0045fc50, FUN_00460380, FUN_0045c7e0, FUN_00460dd0, FUN_004612e0, FUN_00460470, FUN_00460e90, FUN_0045d4e0, FUN_0045f030, FUN_004a0df0, FUN_00464740, FUN_00587bcf — 12 undocumented calls.

**Corrected entry:**
```
## FUN_004643C0 — Session Scoring Update

Source: scoring.cpp. Updates session scoring/standings. Reads time from _DAT_008afe98.
Checks +0x3fc4 flag for session type. Calls FUN_00462370 for lap counting (sessions 1-2).
Manages timer at +0x37c; triggers multi-function cleanup on expiry.

**Key logic:**
- Returns if +0x3fc4 == 0
- Accumulates delta time from _DAT_008afe98
- Sessions 1-2: checks lap count via FUN_00462370
- If session not active (FUN_0057a900 == 0): decrements timer at +0x37c, calls cleanup sequence
- If active: calls sequence of 6+ update functions
- Accumulates time at +900
- Iterates linked list at *param_1+0x1b770, processes entries

**Globals:** _DAT_008afe98, DAT_0059e440 (zero threshold)

**Calls:** FUN_00462370, FUN_0057a900, FUN_004a0d30, FUN_004a0db0, FUN_004a0490,
FUN_00460cb0, FUN_0045fc50, FUN_00460380, FUN_0045c7e0, FUN_00460dd0, FUN_004612e0,
FUN_00460470, FUN_00460e90, FUN_0045d4e0, FUN_0045f030, FUN_004a0df0, FUN_00464740,
FUN_00587bcf

**Moddability:** partially configurable via DAT_0059e440 threshold
```

---

## FUN_0047F010 — PASS

**Summary:** 41-line source verified. Calls FUN_00462e00. Copies to DAT_005ec4cc via FUN_00423a00. Falls back to DAT_005ea438 if null. Calls FUN_00488b40. All doc claims match. Globals correct: DAT_005ec4cc.

---

## FUN_00596089 — PASS

**Summary:** Triage entry. 35-line source. WideCharToMultiByte conversion with ASCII fast-path and errno on failure. Category "Strings/Encoding" correct. Size 105 bytes confirmed.

---

## FUN_005823C0 — PASS

**Summary:** Triage entry. 90-line source. Sorted linked-list node insertion with SEH wrapping. Category "Data — List" correct. Size 299 bytes confirmed.

---

## FUN_0058FC20 — PASS

**Summary:** Triage entry. 62-line source. Character bitmap filter — builds charset bitmap from param_2, scans param_1 for first non-matching char. Category "Utility — Compare" is slightly off (should be "search/filter" not "compare") but acceptable for triage.

---

## FUN_00596FED — FAIL

**Error tags:**
- [CATEGORY_WRONG] Category "Entity — State" is wrong. Function checks param_1 for -2/-3/-4 sentinel values, sets DAT_008d41d4 flag, returns GetOEMCP/GetACP. Should be "System — CodePage" or "System — Encoding".
- [PURPOSE_INACCURATE] Purpose "State/flag read from entity struct" does not match. Function is a code page/encoding locale query utility, not an entity struct operation.

**Corrected triage:**
```
## FUN_00596FED
- Address: 0x00596fed
- Size: 74 bytes
- Lines: 33
- Category: System — Encoding
- Algorithm/Purpose: Code page / locale query — returns GetOEMCP or GetACP based on sentinel
  param_1 (-2/-3/-4). Sets DAT_008d41d4 locale flag.
- Game Logic: System locale/code page detection
- Complexity: Low
```

---

## FUN_00412E50 — PASS

**Summary:** 190-line source fully verified. Maps param_3 (1-26) to DIK_* scancodes 0xF0-0x10A with shift modifier (param_4). Source shows: param_2 == 0 → primary table. Shift modifier: `(-(uint)(param_4 != '\0') & 0xffffffe6) + base` which is base or base-0x1A, matching doc's "-0x1A for table 0". Writes scancode to param_1+8 (line 181). Calls FUN_00414180 (line 182) to resolve key binding, stores at param_1+0xC (line 183). Returns 1 on success (line 184), 0xFFFFFFFF on invalid (line 12, default). All doc claims confirmed.

---

## FUN_0042CE10 — PASS

**Summary:** Thunk. 12-byte function. Delegates to FUN_00587b3e with LAB_0042ce20. Doc entry correct.

---

## FUN_0050A5CB — PASS

**Summary:** 34-line source verified. Decodes 16-bit RGB (5-6-5) texture data to float RGBA using _DAT_005ad290 multiplier. Sets RGB from low word, A from upper word of 32-bit pixel. Calls FUN_00507845 if param_1+0x10 != 0. All doc claims match.

---

## FUN_0042ECC0 — PASS

**Summary:** 23-line source verified. Calls FUN_0042de10(param_2). Copies +0x1978 to +0x1640. Copies 8 entries from +0x1970 to +0x1680 with stride 0x10. All doc claims match.

---

## FUN_00411BF0 — PASS

**Summary:** 80-line source verified. Switch on *(param_2 + 0xc). All 23 case values documented match source exactly. Random via `_rand() & 1`. Each dispatched function receives param_4, param_1, and text from *(param_3 + 0x10). All dispatched functions confirmed. Doc claims all verified.

---

## FUN_00424010 — PASS

**Summary:** 16-line source verified. Frees buffer at param_1+0x44a8 via FUN_00587bcf. Calls FUN_004b0170, FUN_004e4570. Name "Vehicle Subsystem Cleanup" from doc entry at line 6478 is consistent with source behavior.

---

## FUN_0054BA00 — PASS

**Summary:** 44-line source verified. Doubly-linked list node mover. Unlinks node from current list (adjusts +0x48/+0x4c pointers). If node is global head at DAT_008b8f28+0x108, updates head to node->next (line 18-19). If param_3 != 0: calls FUN_00544c50 (line 22). Appends to param_1's list: walks to tail via +0x4c, inserts at end, sets +0x48/+0x4c/+0x40 (lines 24-37). If +0x230 buffers present: calls FUN_00560eb0 (lines 38-40). Global DAT_008b8f28+0x108 confirmed. All doc claims match.

---

## FUN_00500190 — PASS

**Summary:** 22-line source verified. Zeroes 0x6c dwords (lines 13-17) starting at param_1+0x1b8. Sets *(param_1+0x1bc) = _DAT_005ad348 (line 18). Doc says "Zeroes 0x1b0-byte buffer" but source zeroes 0x6c dwords = 0x1b0 bytes — CORRECT. All claims verified.

---

## FUN_00519720 — PASS

**Summary:** 63-line source verified. State-machine driven audio streaming fill. All struct offsets confirmed:
- +0x030 ReadyFlag: checked at line 13
- +0x034 Position: read at line 30, reset at line 39
- +0x040 BufferIndex: toggled XOR 1 at line 54
- +0x044 FillState: read at line 22, set at lines 34, 44, 58
- +0x048 BufferSize: read at line 30
- +0x04c BufferCounter: incremented at line 19, checked at line 41
- +0x114 BufferSizeBase: read at lines 40, 56-57
- +0x118 TotalBuffers: read at line 41
- +0x180 StreamPtr: read at line 12
- +0x184 VtableDecoder: vtable call at line 14
- +0x188 VtableFiller: vtable call at lines 28-30, 47-49

Calls FUN_00519622 (line 42), FUN_0051954e (line 52) confirmed. All doc claims match.

---

## FUN_0050A2B4 — PASS

**Summary:** 31-line source verified. Decompresses byte-encoded vertex data to float array with _DAT_0059e774 scale. Reads strides from +0x1050/0x1054/0x1058. Each vertex: 4 bytes → 4 floats (byte * scale). Output to param_4 (4 floats per vertex). Calls FUN_00507845 if +0x10 != 0. All claims match.

---

## FUN_0054FA00 — PASS

**Summary:** 25-line source verified. Network packet data writer. Checks buffer at param_1+0x1e0 → +8 (line 11). Validates param_3 < count at +4 (line 12). At packet index param_3 * 0x74 + data_start: writes param_2[0..2] to +0x4/+0x8/+0xc (lines 14-16), param_2[3..5] to +0x1c/+0x20/+0x24 (lines 17-19). Sets flag bit 8 (line 20). All claims verified. Doc says 6 dwords — confirmed (lines 14-19, 6 writes).

---

## FUN_0053CE40 — PASS

**Summary:** 37-line source verified. Unlinks physics body from global collision list at DAT_008b8f14. Walks list via +0x130 (next) and +300 (prev) pointers. If head (field +300 == 0): updates DAT_008b8f14 to next (lines 26-28). Calls FUN_0055fe30 (line 29), FUN_00557470 (line 30), FUN_00587bcf (line 31). Decrements DAT_008b6ac0 (line 32). All globals and calls confirmed.

---

## FUN_004B8150 — PASS

**Summary:** 26-line source verified. Bounds-checks param_2 against *(param_1 + 0x6cc) (line 12). Walks linked list from param_1 + 0x6c0 via [1] as next pointer (lines 13-16). Returns float at node's data pointer (line 19). Returns _DAT_0059e670 default if invalid (line 23). All claims match.

---

## FUN_004E18C0 — PASS

**Summary:** 50-line source verified. Switch on param_2 (0-13):
- Cases 0-3: wheel at param_2*0x128 + 0x144 (line 15), checks active and +0x10 byte (line 43)
- Cases 4-5: dedicated at +0x5e4 (line 21) / +0x628 (line 26), checks +0x40 byte (lines 21, 26)
- Cases 6-13: subsystems at param_2*0x44 + 0x4d4 (line 38), checks active and ready byte (line 43)
- Returns 1 (ready) or 0 (busy/inactive)

All claims match. Called by FUN_004d0030 per doc. Moddability: hardcoded.

---

## FUN_00543800 — PASS

**Summary:** 18-line source verified. Sets param_1+0x17c/0x180/0x184 to param_2/3/4 * _DAT_0059e460 (lines 10-12). Calls FUN_00541670 with packed color (param_2*0x100+param_3)*0x100+param_4 (line 13). Sets DAT_008b8f28+0xec bit 0x800 (line 14). All claims match. Globals: DAT_008b8f28 confirmed.

---

## FUN_00538940 — PASS

**Summary:** 22-line source verified. Calls FUN_005389b0 twice with values at +0xb12 and +0xb1e (lines 10-11). Calls FUN_005383d0 (line 12). Backward-searches table indexed by UNK_005b7dec into array at +0xa74 (short array, stride 4) (lines 13-17). Cumulative addition: +0x169b += iVar1 * 3 + 0x11 (line 18). All claims match. Calls: FUN_005389b0, FUN_005383d0 confirmed.

---

## FUN_004EE230 — PASS

**Summary:** 33-line source verified. Computes ratio: +0x3994 / +0x3998 (line 13). Cubic-scaled force: ratio * +0x3570 * ratio^3 * _DAT_0059e450 (line 15). For each output (+0x77c, +0x790, +0x7a4): copies default from +0x3d48/+0x3d4c/+0x3d50 (lines 14, 20, 25). If default == _DAT_005ad1f8 sentinel: overrides with computed value (lines 16-18, 21-23, 26-28). All struct offsets confirmed. Globals _DAT_005ad1f8 and _DAT_0059e450 confirmed.

---

## FUN_005453A0 — PASS

**Summary:** 42-line source verified. If param_3 != 0: directly evaluates via FUN_0054bc60 (line 15), returns result (line 16). Otherwise walks linked list at param_1+0x100 (lines 18-29). For each node: if +0xec flag set, evaluates param_2 via FUN_0054bc60 (line 25). Falls back to param_1+0x108 default node (lines 34-38). All struct offsets confirmed: +0x100 (chain head), +0x108 (default node). Moddability: hardcoded.

---

## FUN_0054ABE0 — PASS

**Summary:** 27-line source verified. If param_1+0x204 (head) null: sets head = param_2, zeroes +0x140 and +0x10 links (lines 12-16). Else walks to tail via +0x10 next (lines 18-20), appends param_2, sets +0x140 back-pointer (lines 21-22). All struct offsets confirmed: +0x204 head, +0x10 next, +0x140 back-pointer. Moddability: hardcoded.

---

## FUN_0051C237 — PASS

**Summary:** 45-line source verified. Reads width from param_1+0x110 (line 18), height-2 from param_2+0x28 (line 27). First pixel: copies source byte, second = (src*3 + next*2 + 2) >> 2 (lines 22-26). Middle pixels (width-2 loop): (prev*1 + cur*3 + next*2) >> 2 (lines 27-34). Last pixel: (prev*1 + cur*3 + 1) >> 2 (line 37), copies final byte directly (line 38). All arithmetic integer bit-shift, no floating point. Doc claims fully verified.

---

## FUN_004D0F10 — PASS

**Summary:** 62-line source verified. Calls FUN_0040d980 (memset/base init) (line 11). Zeroes fields at 0xe0, 0xe4, 0xec, 0xf0, 0xf8, 0xfc, 0xa4, 0xa8 (lines 12-19). Sets +0xac = 0x7fffffff (line 20). Zeroes +0xb0, +0xb4 (lines 21-22). Sets +0xb8 = 0x45e10000 (7200.0f) (line 23). Sets +0xbc = 0x3f800000 (1.0f) (line 24). Zeroes +0xc0, +0xc3, +0xd4, +0xd0 (lines 25-28). Initializes array at +0x128 (26 ints) to 0xffffffff (lines 37-41). Sets +400 = 0xffff (short) and +0x192 = 0xff (lines 42-43). Zeroes remaining fields through +0x1ac (lines 44-50). Clears 52 ints at +0x280 (lines 51-58). All struct offsets confirmed. Moddability: hardcoded.

---

## FUN_00509AB8 — PASS

**Summary:** 35-line source verified. Unpacks RGBA 10-10-10-2 texels from uint32. R: bits 0-9 * _DAT_005adba4 (line 23). G: bits 10-19 * _DAT_005adba4 (line 24). B: bits 20-29 * _DAT_005adba4 (line 25). A: bits 30-31 * _DAT_0059e98c (line 26). Calls FUN_00507845 if +0x10 != 0 (lines 29-30). All globals and logic confirmed.

---

## FUN_00541420 — PASS

**Summary:** 19-line source verified. If param_1+0x114c non-null: calls FUN_00540eb0 on pointer (line 9) and pointer+0x24 (line 10). Frees via FUN_00587bcf(pointer - 4) (line 12). Zeroes param_1+0x114c (line 14). All claims match.

---

## FUN_0054B330 — PASS

**Summary:** 28-line source verified. Clears ~param_2 bits from param_1+0x3c (line 11). If param_3 != 0: clears ~param_3 from first child (+0x204) at +0x14 (line 13) and all siblings (+0x10 chain) at +0x14 (lines 14-17). Recurses into child at +0x44 (line 20, calls self with param_4=1). Continues to sibling at +0x4c (line 22, calls self). Recursive self-call confirmed. All claims match.

---

## FUN_00507845 — PASS

**Summary:** 32-line source verified. Computes entry count from +0x1058 × 16 (0x10-byte) (line 12). Iterates 4-float entries at param_2 (lines 14-28). If all 4 floats match reference at +0x1c/+0x20/+0x24/+0x28 (lines 17-19), zeros all 4 (lines 20-23). Used to remove stale/resolved contacts. All struct offsets confirmed: +0x1058, +0x1c/0x20/0x24/0x28.

---

## FUN_0042E470 — PASS

**Summary:** 17-line source verified. Compares +0x10 of param_2 and param_3 (line 8). If equal AND +0x14 differ (line 9): copies +0x14 from param_2 to param_3 (line 10). Sets param_1[0x19a4] = 1 (line 11). Sets *param_1 = 1 (line 12). All struct offsets confirmed: param_2/3+0x10 (StateType), param_2/3+0x14 (StateValue), param_1+0x19a4 (EventFlag), param_1[0] (TriggerFlag). Moddability: hardcoded.

---

## FUN_0040D1B0 — PASS

**Summary:** 47-line source verified. Three-level cascade: FUN_0040a910 (line 16), FUN_0040b450 (line 18), FUN_0040bcd0 (line 20). On match: reads value from param_1+0x18/0x1c/0x20 (lines 22, 25, 29). Calls FUN_0040cdd0 (line 31). Sets param_1+0x2c = 1 (line 33). Calls FUN_0040cd60(0) (line 34) and FUN_0040cde0 (line 35). If param_3 != 0 AND param_1[8] != 0: calls vtable[0x10] (lines 37-39). Returns combined status byte. All claims match.

---

## FUN_00489CB0 — PASS

**Summary:** 24-line source verified. Iterates linked list at param_1[0x24] (lines 11-16). Calls vtable destructor on each node (line 15). Zeros [0x24]=0 (line 17), [0x5a]=-1 (line 18), [0x25]=0 (line 19). Calls vtable[0x2c](1) (line 20). All doc claims match.

---

## FUN_004D7AA0 — PASS

**Summary:** 13-line source verified. Calls FUN_0058a163 with string from param_1+4 and param_2 (line 8). Calls FUN_00589ffd (thread-safe file write) (line 9). Debug/log output. Doc entry correct.

---

## FUN_004862E0 — PASS

**Summary:** 22-line source verified. Checks *(param_1 + 200) non-null (line 10). Dereferences *(*(param_1+200) + 0x48) for string pointer (line 14). If null: returns DAT_005ea438 (line 16). Returns string pointer (line 19). Global DAT_005ea438 confirmed. Doc claims match. Moddability: "configurable" is acceptable since it returns LoadPath pointer.

---

## End of Cross-Validation Report
