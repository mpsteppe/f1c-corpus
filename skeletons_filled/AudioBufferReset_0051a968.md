## AudioBufferReset_0051a968 — AudioBufferReset

**Summary:** Resets audio decode buffer state by accumulating byte count into total, zeroing per-channel arrays, setting a reference value, and clearing the ready flag.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** TextureDecompression (0051a9c6)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0xFC | R | — | reference value copied to buffer state (channels/format) |
| this | 0x120 | R | — | channel count, defines number of DWORDs to zero in array |
| this | 0x190 | R | — | pointer to output/total buffer (offset +88 written with accumulated byte count) |
| this | 0x194 | R | — | pointer to internal decode buffer state |
| this | 0x198 | R | — | not directly referenced here |
| this | 0x1A8 | RW | 0 | decode state field +20, byte counter zeroed |
| this | 0x1AC | RW | 0 | decode state field +24, ready flag byte zeroed |
| this | 0x1B4 | RW | 0 | decode state field +32, first element of per-channel array zeroed |
| this | 0x1C4 | RW | — | decode state field +48, written with reference value from this->0xFC |
| this | 0x1E8 | RW | — | output total at *(this->0x190 + 88), accumulated byte count |

**Written-by note (persistence):**
- this 0x1A8: once, unconditional (zeroed); survives external poke
- this 0x1AC: once, conditional on callback success (byte zeroed); survives external poke
- this 0x1B4: once, conditional (zeroed for this->0x120 elements); survives external poke
- this 0x1C4: once, conditional (written with reference value); survives external poke
- this 0x1E8: once, unconditional (accumulated); survives external poke

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x120 | > | 0 | channel count |

**Guard interpretation:** Vtable callback at *(this->0x190 + 8) must return nonzero to PASS (proceed with zeroing array and setting fields). this->0x120 > 0 controls the array zeroing loop (BLOCKED: skip zeroing if channel count <= 0).
