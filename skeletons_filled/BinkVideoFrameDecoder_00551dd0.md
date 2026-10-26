## BinkVideoFrameDecoder_00551dd0 — BinkVideoFrameDecoder

**Summary:** Decodes a Bink video frame to a surface (variant of render, uses different surface lock method). Waits for next frame, decompresses, advances frame index, then copies decoded frame to buffer via BinkCopyToBuffer with additional flag bits from a5. Returns result from surface unlock call.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** IndexedArrayLookupWithBoundsCheck (005504d0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x8 | R | — | Total frame count from Bink header (obj = this[0], Bink handle struct) |
| this | 0x0 | R | — | Bink handle (HBINK) for BinkWait/BinkDoFrame/BinkNextFrame/BinkCopyToBuffer |
| this | 0x4 | RW | — | Current frame index, incremented modulo total frame count |

**Written-by note (persistence):**
- this 0x4: updated each frame, wraps by total frames count; does external poke survive? yes

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 00551e94 | jpt_551E11 | R | Jump table for switch on a2[12] (render path flags) |
| 0059e340 | _BinkWait@4 | R | Bink API: returns 0 when next frame is ready |
| 0059e344 | _BinkDoFrame@4 | R | Bink API: decompresses/render current frame |
| 0059e348 | _BinkNextFrame@4 | R | Bink API: advances to next frame in file |
| 0059e34c | _BinkCopyToBuffer@28 | R | Bink API: copies rendered frame to output buffer with dest pitch, rect, and flags |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00543210 | ThunkWithArgReorder | Gets surface/buffer address from render target (variant: lock type 4) |
| 00543230 | ArgumentReorderWrapper_3230 | Releases/returns surface after copy (pair with ThunkWithArgReorder) |

**Guard conditions:** No early-return guards. Frame decode always attempts BinkWait; if ready, processes frame and increments counter. Surface lock/copy only succeeds if ThunkWithArgReorder returns non-null.
