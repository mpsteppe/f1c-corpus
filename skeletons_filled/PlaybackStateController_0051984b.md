## PlaybackStateController_0051984b — PlaybackStateRouter

**Summary:** Dispatches playback state transitions by selecting stream buffer callbacks (AudioStreamBufferFill, BufferedDataStreamWrite, or RendererVtableDispatchWrapper) and zeroing state fields based on command parameter a2.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x0 | R | — | vtable/type pointer of stream buffer object |
| obj | 0x14 | RW | 4 | vtable entry written to 4 (function dispatch index) |
| this | 0x0 | R | — | vtable pointer for state controller dispatch |
| this | 0x180 | R | — | pointer to stream buffer state object (obj) |
| this | 0x184 | RW | — | stream buffer object field (at obj+0x4) written with callback pointer |
| this | 0x19C | R | — | pointer to audio buffer status struct with byte at +8 |
| this | 0x1A4 | R | — | not directly referenced in this function |
| this | 0x1B0 | RW | 0 | stream buffer field obj+0x30 zeroed on init |
| this | 0x1B4 | RW | 0 | stream buffer field obj+0x34 zeroed on init |
| this | 0x1C0 | RW | 0 | stream buffer field obj+0x40 zeroed on audio stream path |
| this | 0x1C4 | RW | 0 | stream buffer field obj+0x44 zeroed on audio stream path |
| this | 0x1CC | RW | 0 | stream buffer field obj+0x4C zeroed on audio stream path |

**Written-by note (persistence):**
- obj 0x14: once, conditional (a2 != 0 and a2 != 2); does external poke survive — yes, raw write
- this 0x184: once, conditional on a2 value; survives external poke
- this 0x1B0: once, conditional (a2 == 0 path); survives external poke
- this 0x1B4: once, conditional (a2 == 0 path); survives external poke
- this 0x1C0: once, conditional (a2 == 0 and status byte nonzero); survives external poke
- this 0x1C4: once, conditional (a2 == 0 and status byte nonzero); survives external poke
- this 0x1CC: once, conditional (a2 == 0 and status byte nonzero); survives external poke

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005196b8 | BufferedDataStreamWrite | R | callback for buffered data stream when audio buffer not ready |
| 00519720 | AudioStreamBufferFill | R | callback for filling audio stream buffer when ready |
| 00519828 | RendererVtableDispatchWrapper | R | callback for renderer vtable dispatch (a2 == 2 path) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0051941d | TextureRowCopy | copies texture row data during audio stream init path |

**Guard conditions:** a2 == 0 → early branch for init/stop path; a2 == 2 → renderer dispatch path; a2 != 0 && a2 != 2 → vtable write + dispatch via *a1. When a2 == 0: checks byte at *(this->0x19C + 8) — if nonzero PASSES to audio stream path (sets AudioStreamBufferFill, calls TextureRowCopy, zeros 0x40/0x44/0x4C), else BLOCKED to buffered path (sets BufferedDataStreamWrite). Always zeros obj+0x30 and obj+0x34 on a2 == 0 path.
