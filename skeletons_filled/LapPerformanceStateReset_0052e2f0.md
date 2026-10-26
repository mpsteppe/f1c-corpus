## LapPerformanceStateReset_0052e2f0 — MpegLapPerformanceReset

**Summary:** Resets MPEG audio lap/performance tracking state: zeroes frame counter, bit position, and residual counters; copies current buffer level to tracking field. Called during decoder open.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** CMpegBase_Open (0052e090), CMpegFilePlayer_Open (0052e1d0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x249C | R | — | frame size (copied to tracking field) |
| this | 0x24A8 | RW | 0 | bit position in current frame (reset to 0) |
| this | 0x24AC | RW | 0 | current bit position in bitstream (reset to 0) |
| this | 0x24B4 | RW | 0 | accumulated byte position (reset to 0) |
| this | 0x24E4 | RW | 0 | frame count (reset to 0) |
| this | 0x24E8 | RW | — | residual bytes in current frame (set from frame size) |

**Written-by note (persistence):**
- this 0x24A8: written to 0 each reset; external poke overwritten each reset
- this 0x24AC: written to 0 each reset; external poke overwritten each reset
- this 0x24B4: written to 0 each reset; external poke overwritten each reset
- this 0x24E4: written to 0 each reset; external poke overwritten each reset
- this 0x24E8: written with frame size each reset; external poke overwritten each reset

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** none — always executes all field writes
