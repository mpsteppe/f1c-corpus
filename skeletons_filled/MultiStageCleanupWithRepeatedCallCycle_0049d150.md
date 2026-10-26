## MultiStageCleanupWithRepeatedCallCycle_0049d150 — Multi-Stage Resource Cleanup & Struct Zeroing

**Summary:** Iterates over pointer fields (indices 1-7), calls release/cleanup on non-null linked-list and resource pointers, then runs 5 cycles of 4-phase cleanup (ShortComputation, SoundResourceCleanup, SingleFieldFree, ConditionalFree) on sub-blocks at offsets +24, +43, +62, +81, +100. Finally zeroes all 24 DWORD fields (0x00-0x5C).

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** OnScreen_Post (0049f0d0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | 0 | field[0] — zeroed at exit (struct flag/state byte) |
| this | 0x4 | RW | 0 | field[1] — pointer, freed via StringCompareLinkedListSearch if non-null |
| this | 0x8 | RW | 0 | field[2] — pointer, freed via StringCompareLinkedListSearch if non-null |
| this | 0xC | RW | 0 | field[3] — pointer, freed via StringCompareLinkedListSearch if non-null |
| this | 0x10 | RW | 0 | field[4] — zeroed at exit |
| this | 0x14 | RW | 0 | field[5] — zeroed at exit |
| this | 0x18 | RW | 0 | field[6] — pointer, freed via sub_53CB90 if non-null |
| this | 0x1C | RW | 0 | field[7] — pointer, freed via sub_53CB90 if non-null |
| this | 0x20 | RW | 0 | field[8] — zeroed at exit |
| this | 0x24 | RW | 0 | field[9] — zeroed at exit |
| this | 0x28 | RW | 0 | field[10] — zeroed at exit |
| this | 0x2C | RW | 0 | field[11] — zeroed at exit |
| this | 0x30 | RW | 0 | field[12] — zeroed at exit |
| this | 0x34 | RW | 0 | field[13] — zeroed at exit |
| this | 0x38 | RW | 0 | field[14] — zeroed at exit |
| this | 0x3C | RW | 0 | field[15] — zeroed at exit |
| this | 0x40 | RW | 0 | field[16] — zeroed at exit |
| this | 0x44 | RW | 0 | field[17] — zeroed at exit |
| this | 0x48 | RW | 0 | field[18] — zeroed at exit |
| this | 0x4C | RW | 0 | field[19] — zeroed at exit |
| this | 0x50 | RW | 0 | field[20] — zeroed at exit |
| this | 0x54 | RW | 0 | field[21] — zeroed at exit |
| this | 0x58 | RW | 0 | field[22] — zeroed at exit |
| this | 0x5C | RW | 0 | field[23] — zeroed at exit |

**Written-by note (persistence):**
- this 0x0: set to 0 at exit — external poke does NOT survive this call (not called per-frame; single cleanup pass)
- this 0x4: set to 0 at exit — external poke does NOT survive this call
- this 0x8: set to 0 at exit — external poke does NOT survive this call
- this 0xC: set to 0 at exit — external poke does NOT survive this call
- this 0x10: set to 0 at exit — external poke does NOT survive this call
- this 0x14: set to 0 at exit — external poke does NOT survive this call
- this 0x18: set to 0 at exit — external poke does NOT survive this call
- this 0x1C: set to 0 at exit — external poke does NOT survive this call
- this 0x20: set to 0 at exit — external poke does NOT survive this call
- this 0x24: set to 0 at exit — external poke does NOT survive this call
- this 0x28: set to 0 at exit — external poke does NOT survive this call
- this 0x2C: set to 0 at exit — external poke does NOT survive this call
- this 0x30: set to 0 at exit — external poke does NOT survive this call
- this 0x34: set to 0 at exit — external poke does NOT survive this call
- this 0x38: set to 0 at exit — external poke does NOT survive this call
- this 0x3C: set to 0 at exit — external poke does NOT survive this call
- this 0x40: set to 0 at exit — external poke does NOT survive this call
- this 0x44: set to 0 at exit — external poke does NOT survive this call
- this 0x48: set to 0 at exit — external poke does NOT survive this call
- this 0x4C: set to 0 at exit — external poke does NOT survive this call
- this 0x50: set to 0 at exit — external poke does NOT survive this call
- this 0x54: set to 0 at exit — external poke does NOT survive this call
- this 0x58: set to 0 at exit — external poke does NOT survive this call
- this 0x5C: set to 0 at exit — external poke does NOT survive this call

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 008afe64 | dword_8AFE64 | R | RaceTimeDelta [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0049ec40 | ShortComputation_ec40 | phase-1 compute on sub-block (called 5x at offsets +24,+43,+62,+81,+100) |
| 0049ec60 | SoundResourceCleanup | phase-2: release sound resources in sub-block |
| 0049eca0 | SingleFieldFreeWrapper | phase-3: free single pointer field in sub-block |
| 0049ecc0 | ConditionalFreeSubCall | phase-4: conditional free call on sub-block |
| 0053cb90 | sub_53CB90 | release/free for pointer fields [6] and [7] |
| 0053d130 | StringCompareLinkedListSearch | release/free for linked-list pointer fields [1],[2],[3] |

**Guard conditions:** Each pointer field is guarded individually: if non-null, the corresponding release function is called and the pointer is zeroed. Fields [6] and [7] use sub_53CB90; fields [1],[2],[3] use StringCompareLinkedListSearch. The 5 sub-block cleanup cycles (indices 24, 43, 62, 81, 100) and final zeroing of fields [0]-[23] are unconditional — always executed.
