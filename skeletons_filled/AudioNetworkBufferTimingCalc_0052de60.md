## AudioNetworkBufferTimingCalc_0052de60 — MpegAudioTimingCalc

**Summary:** Computes MPEG audio buffer timing parameters: buffer size (768 or 2304 × multiplier based on mode), timing quotient/remainder (28800 × 5×mode / sample_rate), and sets ready flag. Called during audio decoder open.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** CMpegBase_Open (0052e090), CMpegFilePlayer_Open (0052e1d0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x2484 | R | — | audio sample rate / timing divisor |
| this | 0x248C | RW | — | buffer size (768×v4 or 2304×v4) |
| this | 0x2490 | R | — | mode flag: 1 = mono (768×), else stereo (2304×) |
| this | 0x2494 | R | — | mode multiplier (5× used in timing calc) |
| this | 0x249C | RW | — | copy of buffer size from 0x248C |
| this | 0x24BC | RW | 1 | ready flag (set to 1) |
| this | 0x24CC | R | — | channel/frame multiplier for buffer size calc |
| this | 0x24D4 | RW | 1 | initial timing field (set to 1) |
| this | 0x24D8 | RW | — | timing quotient (28800 × 5×mode / sample_rate) |
| this | 0x24DC | RW | — | timing remainder (fractional part / 100) |
| this | 0x24E0 | RW | — | sample_rate / 100 |

**Written-by note (persistence):**
- this 0x248C: written once per open; external poke overwritten next open
- this 0x249C: written once per open; external poke overwritten next open
- this 0x24BC: written once to 1; external poke survives until next open
- this 0x24D4: written once to 1; external poke survives until next open
- this 0x24D8: written once per open; external poke overwritten next open
- this 0x24DC: written once per open; external poke overwritten next open
- this 0x24E0: written once per open; external poke overwritten next open

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x2490 | == | 1 | mode flag: 1 = mono channel config |

**Guard interpretation:** mode==1 uses 768× multiplier for buffer size; otherwise uses 2304× (stereo). Both paths execute normally (no early return).
