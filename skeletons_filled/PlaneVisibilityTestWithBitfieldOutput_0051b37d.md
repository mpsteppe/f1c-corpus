## PlaneVisibilityTestWithBitfieldOutput_0051b37d — PlaneVisibilityTestWithBitfieldOutput

**Summary:** Reads one bit per plane-sub-block from bitstream and ORs a mask into visibility bitfield output words, indicating which planes/layers are visible.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x14 | RW | — | saved read pointer state |
| this | 0x18 | RW | — | saved write pointer state |
| this | 0xFC | R | — | block count flag |
| this | 0x13C | R | — | number of plane bits to test |
| this | 0x174 | R | — | bit position shift value (produces mask 1 << shift) |
| this | 0x178 | RW | — | written during processing |
| this | 0x194 | R | — | pointer to internal decode state |
| this | 0x1A4 | RW | — | decode state v3[4] bit accumulator |
| this | 0x1A8 | RW | — | decode state v3[5] bit count |
| this | 0x1C8 | R | — | decode state v3[13] block counter (decremented) |

**Written-by note (persistence):**
- this 0x14: on exit, saved read pointer; survives external poke
- this 0x18: on exit, saved write pointer; survives external poke
- this 0x178: conditional, per sub-block; survives external poke
- this 0x1A4: on exit, saved bit accumulator; survives external poke
- this 0x1A8: on exit, saved bit count; survives external poke

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0051a794 | sub_51A794 | bitstream reader with escape sequence handling |
| 0051aefc | CounterUpdateWithZero | resets counter state before processing |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0xFC | == | 0 | block count flag |
| this | 0x13C | <= | 0 | plane count |

**Guard interpretation:** this->0xFC == 0 OR block counter v3[13] nonzero BLOCKS CounterUpdateWithZero. this->0x13C <= 0 BLOCKS entire bit-testing loop. On insufficient bits (bit count < 1), sub_51A794 is called; failure returns 0.
