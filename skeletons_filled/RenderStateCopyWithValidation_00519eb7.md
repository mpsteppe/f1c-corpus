## RenderStateCopyWithValidation_00519eb7 — RenderStateCopyWithValidation

**Summary:** Copies validated render state data from source buffer to destination, checking that all sprite object pointer fields are non-null and the source state values are non-negative.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** ProtocolStateHandler (0051a4b7)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(*(this+0xC4)+0x4C) | 0x0 | R | — | sprite object first word (checked non-zero) |
| *(*(this+0xC4)+0x4C) | 0x2 | R | — | sprite object word at offset 2 (checked non-zero) |
| *(*(this+0xC4)+0x4C) | 0x4 | R | — | sprite object word at offset 4 (checked non-zero) |
| *(*(this+0xC4)+0x4C) | 0x10 | R | — | sprite object word at offset 16 (checked non-zero) |
| *(*(this+0xC4)+0x4C) | 0x12 | R | — | sprite object word at offset 18 (checked non-zero) |
| *(*(this+0xC4)+0x4C) | 0x20 | R | — | sprite object word at offset 32 (checked non-zero) |
| *(this+0x184) | 0x70 | RW | — | destination buffer pointer, allocated once if null |
| *(this+0x4) | 0x0 | R | — | sub-allocator vtable entry 0 (allocation function) |
| *(this+0xC4) | 0x4C | R | — | offset to word array within each sprite object struct |
| this | 0x4 | R | — | sub-allocator vtable pointer |
| this | 0x20 | R | — | number of objects to process |
| this | 0x8C | R | — | source render state data pointer |
| this | 0xC4 | R | — | pointer to array of sprite object descriptors |
| this | 0xC8 | R | — | enable flag for render state copy |
| this | 0x184 | R | — | pointer to frame info struct |

**Written-by note (persistence):**
- *(this+0x184) 0x70: once, conditional (null check + enable flag); survives external poke

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x20 | <= | 0 | object count (return early) |

**Guard interpretation:** this->0xC8 (enable flag) must be nonzero AND this->0x8C (source ptr) must be nonzero to PASS initial guard. Then this->0x20 <= 0 BLOCKS (returns 0 with no copy). Per-object validation: all 6 word checks at *(object+0x4C) must PASS (non-null/non-zero), and source data at [source + index*256] must have non-negative first DWORD; any failure BREAKS the loop.
