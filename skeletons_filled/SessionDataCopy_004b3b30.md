## SessionDataCopy_004b3b30 — RingBufferResetToStart

**Summary:** Resets ring buffer read pointer (0x6C00C) to start address (0x6C008). Companion to AdvanceRingBuffer — rewinds buffer to beginning for replay or re-initialization.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** InputCommandDispatchToEntities (0045f4a0), TeamRadioNetworkMessageProcessing (0045f710), PitTimingUpdate (004b7a90)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x6C008 | R | — | Ring buffer start address (source) |
| this | 0x6C00C | RW | — | Current read pointer (written with start value) |

**Written-by note (persistence):**
- this 0x6C00C: written every call — set to value of 0x6C008 (start address)

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** No guard conditions — always executes fully (single read + single write, no branches).
