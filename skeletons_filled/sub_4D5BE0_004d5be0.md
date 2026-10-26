## sub_4D5BE0_004d5be0 — FeedbackShiftRegisterDataProcessor

**Summary:** Processes each byte of input buffer through a 4-word feedback shift register (FSR) state machine using multiplication and addition, updating state fields at this[3..6]. After processing all bytes, calls FileReadWrapperWithLock to write processed data to the file descriptor at *this.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** TelemetryDataDump (004d4a80), EncodedDataWriterWithXOR (004d5900), DebugLogInit (004d5960), sub_4D59B0 (004d59b0), FileReadWithXORDecode (004d5af0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | R | — | file descriptor handle for output |
| this | 0xC | RW | — | FSR state word 0 (this[3]) — cycled through state |
| this | 0x10 | RW | — | FSR state word 1 (this[4]) — shifted from word 0 |
| this | 0x14 | RW | — | FSR state word 2 (this[5]) — shifted from word 1 |
| this | 0x18 | RW | — | FSR state word 3 (this[6]) — accumulates byte * state[0] |

**Written-by note (persistence):**
- this 0xC: recalc every frame — external poke does NOT persist
- this 0x10: recalc every frame — external poke does NOT persist
- this 0x14: recalc every frame — external poke does NOT persist
- this 0x18: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00588678 | FileReadWrapperWithLock | writes processed data buffer to file descriptor |

**Guard conditions:** None; always processes entire buffer. Loop runs a3 iterations (byte count).
