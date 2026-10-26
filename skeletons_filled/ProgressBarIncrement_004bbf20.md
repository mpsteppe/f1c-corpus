## ProgressBarIncrement_004bbf20 — ProgressBarLapStageWriter

**Summary:** Writes a progress bar stage event (type 4, ID 24) with current session time to the ring buffer for the given driver, returning the current lap/stage value at offset 0x44.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** PitStopOperationTimer (004a6340)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x4 | R | — | driver/vehicle identifier |
| this | 0x44 | R | — | current lap or stage value (returned) |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0083ee60 | dword_83EE60 | RW | RingBufferCount [DERIVED] (also: ` -- ring buffer counter) |
| 008aae64 | dword_8AAE64 | RW | RingBufferWritePtr [DERIVED] (also: ` -- ring buffer offset) |
| 008afea0 | dbl_8AFEA0 | R | SessionTime [DERIVED] (also: ` — current session time (passed to FUN_0040f300) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004b33b0 | ProgressBarEventEncode | encode progress bar event to ring buffer |

**Guard conditions:** none — always writes to ring buffer (may clamp ring buffer count at 1023).
