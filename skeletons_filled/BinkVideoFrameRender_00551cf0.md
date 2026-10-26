## BinkVideoFrameRender_00551cf0 — BinkVideoFrameRender

**Summary:** Renders a Bink video frame onto a render surface. Waits for frame readiness, decompresses current frame via BinkDoFrame, advances to next frame, updates frame counter, then copies rendered frame to target buffer via BinkCopyToBuffer. Returns true when frame counter wraps to 0 (indicating loop completion).

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** UIStringComparison_e250 (0048e250), sub_48E4B0 (0048e4b0), FileLoadWithRetryLoop (004f9b70)

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
| 00551db4 | jpt_551D31 | R | Jump table for switch on a2[12] (render path flags) |
| 0059e340 | _BinkWait@4 | R | Bink API: returns 0 when next frame is ready |
| 0059e344 | _BinkDoFrame@4 | R | Bink API: decompresses/render current frame |
| 0059e348 | _BinkNextFrame@4 | R | Bink API: advances to next frame in file |
| 0059e34c | _BinkCopyToBuffer@28 | R | Bink API: copies rendered frame to output buffer with dest pitch, rect, and flags |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00543210 | ThunkWithArgReorder | Gets surface/buffer address from render target for BinkCopyToBuffer |
| 00543230 | ArgumentReorderWrapper_3230 | Releases/returns surface after copy (pair with ThunkWithArgReorder) |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x4 | == | 0 | Current frame index; returns true (BOOL) when frame counter wraps to 0 |

**Guard interpretation:** Blocked (early return): none. Frame processing always runs if BinkWait returns 0. Return value this[1]==0 signals to caller whether a full loop cycle completed (frame counter wrapped).
