## ArithmeticComparison_5620_00535620 — Context state reset/init

**Summary:** Resets internal state counters to zero and calls StateResetWithCallback. Sets referenced object's first field to 7 or 0 based on a flag. File I/O / stream context management system.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** BufferedFileReader (00534f90), sub_5354E0 (005354e0), sub_5356A0 (005356a0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x8 | RW | 0 | Context field this[2]; reset to 0 |
| this | 0x14 | RW | 0 | Context field this[5]; reset to 0 |
| this | 0x18 | RW | 0 | Context field this[6]; reset to 0 |
| this | 0x1C | RW | — | Pointer this[7]; after reset, writes 7 or 0 to its first field based on this[7][3] |
| this | 0x28 | R | — | Flag this[10]; if non-zero, first field written as 7; otherwise 0 |

**Written-by note (persistence):**
- this 0x8: recalc every frame — external poke does NOT persist
- this 0x14: recalc every frame — external poke does NOT persist
- this 0x18: recalc every frame — external poke does NOT persist
- this 0x1C: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00537000 | StateResetWithCallback | Reset state and invoke optional callback |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x28 | != | 0 | Flag this[10]: non-zero → init value 7; zero → init value 0 |

**Guard interpretation:** If `this` is NULL → return -2. If `this[7]` (pointer) is NULL → return -2. Always resets counters and calls StateResetWithCallback. The flag test determines what value to write to the referenced object.
