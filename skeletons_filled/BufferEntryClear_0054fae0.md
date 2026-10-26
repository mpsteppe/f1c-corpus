## BufferEntryClear_0054fae0 — RenderBufferEntryClear

**Summary:** Clears the active/dirty flag (bit 0) and resets a status field to zero on one or all render buffer entries, resetting them for the next frame.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** FloatDoubleCoordinateTransform (00459830), VehiclePhysicsVelocityAngularVelocityIntegrator (00459ae0), TimerFrameRateThrottle (004d3740), TrackTemperatureDisplay (004d37b0), AIRacingLinePathFollowing (004e9ca0), CollisionDetectionSystem (004ea970)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x1E8) | 0x0 | RW | — | entry flags (bit 0 cleared to mark inactive) |
| *(this+0x1E8) | 0x40 | RW | 0 | entry status/result field (reset to 0) |
| this | 0x1E0 | R | — | pointer to buffer descriptor |
| this | 0x1E4 | R | — | element count from descriptor |
| this | 0x1E8 | R | — | pointer to buffer data array from descriptor |

**Written-by note (persistence):**
- *(this+0x1E8) 0x0: recalc every frame — external poke does NOT persist
- *(this+0x1E8) 0x40: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x1E4 | > | 0 | element count from buffer descriptor |

**Guard interpretation:** If this[120] (this+0x1E0) is null → skip entirely (BLOCKED). If a2 == 0x8000000 and count > 0 → clear ALL entries (PASS: bulk clear). Otherwise → clear only entry at index a2 (PASS: single clear). If count == 0 with 0x8000000 → skip loop (BLOCKED: empty buffer).
