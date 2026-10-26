## MPEGBuffer_0052e350 — MpegBufferFill

**Summary:** Fills output buffer with decoded MPEG audio data. Decodes frames via sub_52DF10 codec dispatch, handles partial frame data via residual tracking and qmemcpy, accumulates total decoded bytes. Core buffer-fill for audio playback.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** GuardedFunctionCall (0052d970)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x248C | R | — | buffer size (frame_size × channel multiplier) |
| this | 0x249C | R | — | frame size in bytes |
| this | 0x24B4 | RW | — | accumulated total byte position (updated per fill) |
| this | 0x24E4 | RW | — | frame count (incremented per decoded frame) |
| this | 0x24E8 | RW | 0 | residual bytes available in current internal frame buffer |

**Written-by note (persistence):**
- this 0x24B4: written each fill; external poke overwritten next fill
- this 0x24E4: incremented per frame; external poke overwritten each frame decode
- this 0x24E8: updated per copy; external poke overwritten each operation

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005da6f0 | aMpegFail2D | R | format string "mpeg fail 2 %d\n" |
| 005da700 | aMpegFail1D | R | format string "mpeg fail 1 %d\n" |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0052df10 | sub_52DF10 | codec type decoder dispatch (audio/texture) |
| 00588821 | FileOpWithGlobalBuffer | display error message via global buffer |

**Guard conditions:** if residual at 0x24E8 < frame_size at 0x249C, copies data from internal frame buffer (skips decode); if residual equals frame_size, decodes new frame via sub_52DF10; if decode fails, zeros the frame and reports error; loops until requested byte count filled
