## StreamBufferReadStateMachine_0050fab7 — Stream buffer read state dispatcher

**Summary:** State machine for reading from a stream buffer. Dispatches data chunks to a callback and advances read position until buffer exhausted, then signals completion with state 119.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** ImageTextureDecompressor (00501722)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x0 | R | — | vtable base pointer for state dispatcher object |
| obj | 0x4 | R | — | second vtable entry (completion handler) |
| obj | 0x14 | RW | 119 | state code — 18 for active processing, 119 for done |
| obj | 0x18 | RW | — | copy of source state/type field (this+0x10) for tracking |
| this | 0x0 | R | — | pointer to state dispatcher object (obj base) |
| this | 0x8 | R | — | secondary callback object pointer for data dispatch |
| this | 0xC | RW | — | unknown (not directly accessed by this function) |
| this | 0x10 | RW | — | state/type discriminator checked against 205 |
| this | 0x60 | R | — | buffer end offset / data size limit |
| this | 0x78 | RW | — | current read position within buffer |
| this | 0x180 | R | — | dispatch object for chunked data read operation |
| this | 0x184 | R | — | unknown (not directly accessed by this function) |

**Written-by note (persistence):**
- obj 0x14: written conditionally — 18 on guard pass, 119 on buffer exhausted
- obj 0x18: written once conditionally from this+0x10 value
- this 0xC: not written by this function — external state
- this 0x10: not written by this function — external initial state
- this 0x78: incremented by data read return value — tracks consumed bytes

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x10 | != | 205 | state/type discriminator — determines init path |

**Guard interpretation:** If this+0x10 != 205: initialize state to 18, copy discriminator to obj+0x18, call vfunc 0 (init path). If this+0x10 == 205: skip initialization block (state already configured).
