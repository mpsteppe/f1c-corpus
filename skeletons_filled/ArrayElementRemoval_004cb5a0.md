## ArrayElementRemoval_004cb5a0 — ArraySwapRemoveByIndex

**Summary:** Removes an element from a flat pointer array by swapping with the last element (swap-remove pattern). Decrements count, copies last element into the removed slot, updates the moved element's index, and marks removed element as invalid (-1).

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** WheelRenderObjectPerFrameUpdate (004cb860), ParticleInstanceUpdate (004cc1d0), ParticleEffectPhysics (004ccb30), ParticleSystemUpdateWithWindAndDamping (004cd220), TelemetryBarIndicatorRenderer (004cd980), ScoringGateTimeoutCheck (004cdad0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x64 | RW | — | Element count in the flat array; decremented by 1 on removal |
| this | 0x68 | R | — | Pointer to flat array base; last element read and written into removed slot |

**Written-by note (persistence):**
- this 0x64: Decremented every removal. External poke survives until next decrement.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** None. Assumes element index (a2[1]) is valid within array bounds. No explicit bounds check on count.
