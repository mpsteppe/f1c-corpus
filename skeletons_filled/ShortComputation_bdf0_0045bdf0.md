## ShortComputation_bdf0_0045bdf0 — CircularBufferFullReset

**Summary:** Resets the entire 8-entry circular buffer: initializes write cursor (obj[0x31C]) to 0, then resets all eight entries via PerIndexStructFieldResetter. Called for buffer initialization or full flush.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** AIShiftPattern (0042b8d0), BrakeBiasAdjustmentControl (00447d00), OnScreen_Restart (0049f000), sub_4A00A0 (004a00a0), PitTimer (004d2e50)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x31C | RW | 0 | Circular buffer write cursor (reset to 0) |
| this | 0x0 | R | — | Pointer to target object (dereferenced to get buffer context) |

**Written-by note (persistence):**
- obj 0x31C: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** No guard conditions — unconditionally resets all 8 entries and write cursor.
