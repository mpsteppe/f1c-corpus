## ParseMidiBitstream_004d1a50 — Parse packed parameter update stream

**Summary:** Decodes a packed bitstream: if header DWORD indicates reset command (bits 22-17 = 0x28), clears all state entries to 0; then processes (index, value) pairs from packed WORDS following header, updating state array via ShortComputation_0f00.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_4B3400 (004b3400)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x10C | R | — | Count of entries in state array (for reset loop) |
| this | 0x110 | R | — | Pointer to state array (8 bytes per entry, updated via ShortComputation_0f00) |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004d0f00 | ShortComputation_0f00 | Updates a state array entry with a value; called with (entry_ptr, 0) for reset or (entry_ptr, value) for parameter update |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| *a2 | bits 22-17 | == | 0x28 | Reset command identifier |
| *a2 | bits 16-9 (>>9 & 0x1FF) | != | 0 | Count of parameter update words following header |

**Guard interpretation:** If header bits 22-17 equal 0x28, reset all state entries to 0. Then, if the count field (bits 16-9) is non-zero, process that many packed (index, value) WORDs starting at a2+2. PASSES (processes updates) when count > 0.
