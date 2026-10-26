## sub_518FCF_00518fcf — UnknownCriticalChunkHandler

**Summary:** Handles an unknown critical PNG chunk by checking control flags, potentially dispatching an error message, setting done flag bits, and running CRC error check. Part of PNG decoder.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_5119E9 (005119e9)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x58 | RW | — | flags register: bit 3 (0x8) set to mark processing done |
| this | 0x10C | R | — | control flags (bit 5: if set, skip error dispatch) |

**Written-by note (persistence):**
- this 0x58: bit 3 set when IDAT was active; external poke may skip done state

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005aff58 | aUnknownCritica | R | UnknownCriticaString [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0051189c | DoubleBufferInit | reinitialize double-buffer for error/unknown chunk |
| 00517fd0 | sub_517FD0 | check chunk type flags against control flags |
| 00518828 | sub_518828 | run CRC error check on remaining data |

**Guard conditions:** Calls sub_517FD0 first to evaluate chunk type. If this->0x10C bit 5 SET (PASSES), skips DoubleBufferInit error dispatch and directly sets done flag + CRC check. If bit 5 NOT SET (BLOCKED), calls DoubleBufferInit("unknown critical chunk") then if a2 is non-null, proceeds to set done flag and CRC check.
