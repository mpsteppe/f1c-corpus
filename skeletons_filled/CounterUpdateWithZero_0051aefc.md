## CounterUpdateWithZero_0051aefc — CounterUpdateWithZero

**Summary:** Resets decode counter state by accumulating byte count into total, zeroing per-channel counters, setting a reference value, and clearing the ready flag.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** BitstreamDecoder (0051af57), sub_51B154 (0051b154), PlaneVisibilityTestWithBitfieldOutput (0051b37d), sub_51B45F (0051b45f)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0xFC | R | — | reference value copied to state field +52 |
| this | 0x120 | R | — | channel count, defines number of DWORDs to zero in array at +36 |
| this | 0x190 | R | — | pointer to output/total buffer (offset +88 accumulates byte count) |
| this | 0x194 | R | — | pointer to internal decode state |
| this | 0x198 | R | — | not directly referenced in this function |
| this | 0x1A8 | RW | 0 | state field +20, byte counter zeroed |
| this | 0x1AC | RW | 0 | state field +24, ready flag byte zeroed |
| this | 0x1B4 | RW | 0 | state field +32, zeroed unconditionally |
| this | 0x1B8 | RW | 0 | state field +36, first element of per-channel counter array zeroed |
| this | 0x1C8 | RW | — | state field +52, written with reference value from this->0xFC |
| this | 0x1E8 | RW | — | output total at *(this->0x190 + 88), accumulated byte count |

**Written-by note (persistence):**
- this 0x1A8: once, unconditional (zeroed); survives external poke
- this 0x1AC: once, conditional on callback success (byte zeroed); survives external poke
- this 0x1B4: once, conditional (zeroed); survives external poke
- this 0x1B8: once, conditional (zeroed for this->0x120 elements); survives external poke
- this 0x1C8: once, conditional (written with reference value); survives external poke
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

**Guard interpretation:** Vtable callback at *(this->0x190 + 8) must return nonzero to PASS (proceed with zeroing and field writes). this->0x120 > 0 controls channel counter array zeroing loop (BLOCKED: skip zeroing if <= 0).
