## AdvanceRingBuffer_004b3af0 — AdvanceRingBuffer

**Summary:** Advances ring buffer read pointer by one entry (432 bytes). If pointer reaches end, wraps to start and returns 0; otherwise calls ArithmeticComparison_3a90 on current entry and returns 1. Used by input, radio, and timing subsystems.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** InputCommandDispatchToEntities (0045f4a0), TeamRadioNetworkMessageProcessing (0045f710), PitTimingUpdate (004b7a90)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x6C004 | R | — | Ring buffer end address (limit) |
| this | 0x6C008 | R | — | Ring buffer start address (reset target) |
| this | 0x6C00C | RW | — | Current read pointer; advanced by 432 per entry |

**Written-by note (persistence):**
- this 0x6C00C: written each call — current read pointer advances; wraps to start on overflow

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004b3a90 | ArithmeticComparison_3a90 | Compare/process current ring buffer entry |

**Guard conditions:** Compares current pointer (0x6C00C) against end pointer (0x6C004). If equal: pointer resets to start (0x6C008), returns 0 (buffer empty/wrapped). If not equal: processes entry, advances pointer by 432, returns 1 (entry consumed).
