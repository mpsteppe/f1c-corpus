## BitExpandDecompress_00512850 — BitExpandDecompressByTwo

**Summary:** Decompression step: if state==16, deinterleave input buffer by factor 2 (take every other byte), pack contiguously, then update state to 8 and compute output stride/count.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_51389E (0051389e)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | R | — | total element count (width × height) |
| this | 0x4 | RW | — | output element count after expansion |
| this | 0x9 | RW | 8 | state/step — must be 16 to run, reset to 8 on completion |
| this | 0xA | R | — | source stride (bytes between samples before deinterleave) |
| this | 0xB | RW | — | output stride computed as 8 × source stride |

**Written-by note (persistence):**
- this 0x4: unconditionally on pass — set to element count; survives until overwritten
- this 0x9: unconditionally on pass — set from 16 to 8; survives until overwritten
- this 0xB: unconditionally on pass — set to 8 × source stride; survives until overwritten

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x9 | == | 16 | state field — must equal 16 for processing |

**Guard interpretation:** PASSES when state at 0x9 == 16 → full body executes (deinterleave + update state/count/stride). BLOCKED (early return) when state ≠ 16.
