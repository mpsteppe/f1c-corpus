## ArrayProcessingWithValidation_0051ad93 — ArrayProcessingWithValidation

**Summary:** Validates per-object channel indices (0-3 with non-null buffers), copies channel data via sub_51A5EA, then resets decode state fields and counters.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x124) | 0x14 | R | — | sprite object channel index A (v3) |
| *(this+0x124) | 0x18 | R | — | sprite object channel index B (v4) |
| obj | 0x0 | R | — | vtable pointer (this->0x0), read for dispatch |
| obj | 0x4 | R | — | vtable entry 1 (error handler) |
| obj | 0x14 | RW | 49 | vtable entry 5, written with error code 49 on validation failure |
| obj | 0x18 | RW | — | vtable entry 6, written with offending channel index on validation failure |
| this | 0x0 | R | — | main vtable pointer |
| this | 0xFC | R | — | reference value copied to state->0x1C4 at end |
| this | 0x120 | R | — | number of objects to process |
| this | 0x124 | R | — | pointer to sprite object array |
| this | 0x168 | R | — | validation field 0 (must be zero) |
| this | 0x16C | R | — | validation field 1 (must equal 63) |
| this | 0x170 | R | — | validation field 2 (must be zero) |
| this | 0x174 | R | — | validation field 3 (must be zero) |
| this | 0x194 | R | — | pointer to decode state struct |
| this | 0x19C | RW | 0 | state field +8 zeroed at end |
| this | 0x1A0 | RW | 0 | state field +12 zeroed at end |
| this | 0x1A4 | RW | 0 | state field +16 zeroed at end |
| this | 0x1A8 | RW | 0 | state field +20 zeroed at end |
| this | 0x1AC | RW | 0 | state field +24 byte zeroed at end |
| this | 0x1B4 | RW | 0 | state field +32 per-object array element zeroed |
| this | 0x1C4 | RW | — | state field +48 written with this->0xFC |

**Written-by note (persistence):**
- obj 0x14: once, conditional (validation failure); set to 49; survives external poke
- obj 0x18: once, conditional (validation failure); set to channel index; survives external poke
- this 0x19C: once, unconditional; zeroed; survives external poke
- this 0x1A0: once, unconditional; zeroed; survives external poke
- this 0x1A4: once, unconditional; zeroed; survives external poke
- this 0x1A8: once, unconditional; zeroed; survives external poke
- this 0x1AC: once, unconditional; zeroed; survives external poke
- this 0x1B4: once, conditional per object; zeroed; survives external poke
- this 0x1C4: once, unconditional; written with reference value; survives external poke

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0051a5ea | sub_51A5EA | copies channel data from source buffer to decode state array |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x120 | > | 0 | object count |
| this | 0x16C | != | 63 | validation constant |

**Guard interpretation:** If this->0x168 nonzero OR this->0x16C != 63 OR this->0x170 nonzero OR this->0x174 nonzero: BLOCKED by error (writes 118 to vtable, calls handler). Per-object: channel index >= 4 OR channel pointer null BLOCKS that object (writes 49 to vtable, dispatches error). this->0x120 <= 0 skips all object processing.
